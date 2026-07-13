/*
 *  TCC - Tiny C Compiler
 * 
 *  Copyright (c) 2001-2004 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "tcc.h"

/********************************************************/
/* global variables */

ST_DATA int tok_flags;
ST_DATA int parse_flags;

ST_DATA struct BufferedFile *file;
int tok;
CValue tokc;
ST_DATA CString tokcstr; /* current parsed string, if any */

/* display benchmark infos */
ST_DATA int total_lines;

/* ------------------------------------------------------------------------- */

static TokenSym *hash_ident[TOK_HASH_SIZE];
static char token_buf[STRING_MAX_SIZE + 1];
static CString cstr_buf;
static TokenString tokstr_buf;
static unsigned char isidnum_table[256 - CH_EOF];
static int pp_debug_tok, pp_debug_symv;
static int pp_once;
static void tok_print(const char *msg, const int *str);

static const char tcc_keywords[] = 
#define DEF(id, str) str "\0"
#include "tcctok.h"
#undef DEF
;

/* WARNING: the content of this string encodes token numbers */
static const unsigned char tok_two_chars[] =
/* outdated -- gr
    "<=\236>=\235!=\225&&\240||\241++\244--\242==\224<<\1>>\2+=\253"
    "-=\255*=\252/=\257%=\245&=\246^=\336|=\374->\313..\250##\266";
*/{
    '<','=', TOK_LE,
    '>','=', TOK_GE,
    '!','=', TOK_NE,
    '&','&', TOK_LAND,
    '|','|', TOK_LOR,
    '+','+', TOK_INC,
    '-','-', TOK_DEC,
    '=','=', TOK_EQ,
    '<','<', TOK_SHL,
    '>','>', TOK_SAR,
    '+','=', TOK_A_ADD,
    '-','=', TOK_A_SUB,
    '*','=', TOK_A_MUL,
    '/','=', TOK_A_DIV,
    '%','=', TOK_A_MOD,
    '&','=', TOK_A_AND,
    '^','=', TOK_A_XOR,
    '|','=', TOK_A_OR,
    '-','>', TOK_ARROW,
    '.','.', TOK_TWODOTS,
    '#','#', TOK_TWOSHARPS,
    0
};

void next_nomacro_spc(void);

/* ------------------------------------------------------------------------- */

/* we use 64 bit numbers */
#define BN_SIZE 2

/* bn = (bn << shift) | or_val */
/* parse number in null terminated string 'p' and return it in the
   current token */
static void parse_number(const char *p)
{
    int b, t, shift, frac_bits, s, exp_val, ch;
    char *q;
    unsigned int bn[BN_SIZE];
    double d;

    /* number */
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    if (t == '.') {
        goto float_frac_parse;
    } else if (t == '0') {
        if (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        } else if (tcc_ext && (ch == 'b' || ch == 'B')) {
            q--;
            ch = *p++;
            b = 2;
        }
    }
    /* parse all digits. cannot check octal numbers at this stage
       because of floating point constants */
    while (1) {
        if (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        else if (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        else if (isnum(ch))
            t = ch - '0';
        else
            break;
        if (t >= b)
            break;
        if (q >= token_buf + STRING_MAX_SIZE) {
        num_too_long:
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    if (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        if (b != 10) {
            /* NOTE: strtox should support that for hexa numbers, but
               non ISOC99 libcs do not support it, so we prefer to do
               it by hand */
            /* hexadecimal or binary floats */
            /* XXX: handle overflows */
            *q = '\0';
            if (b == 16)
                shift = 4;
            else 
                shift = 1;
            cc0_number_zero((int)bn);
            q = token_buf;
            while (1) {
                t = *q++;
                if (t == '\0') {
                    break;
                } else if (t >= 'a') {
                    t = t - 'a' + 10;
                } else if (t >= 'A') {
                    t = t - 'A' + 10;
                } else {
                    t = t - '0';
                }
                cc0_number_lshift((int)bn, shift, t);
            }
            frac_bits = 0;
            if (ch == '.') {
                ch = *p++;
                while (1) {
                    t = ch;
                    if (t >= 'a' && t <= 'f') {
                        t = t - 'a' + 10;
                    } else if (t >= 'A' && t <= 'F') {
                        t = t - 'A' + 10;
                    } else if (t >= '0' && t <= '9') {
                        t = t - '0';
                    } else {
                        break;
                    }
                    if (t >= b)
                        tcc_error("invalid digit");
                    cc0_number_lshift((int)bn, shift, t);
                    frac_bits += shift;
                    ch = *p++;
                }
            }
            if (ch != 'p' && ch != 'P')
                expect("exponent");
            ch = *p++;
            s = 1;
            exp_val = 0;
            if (ch == '+') {
                ch = *p++;
            } else if (ch == '-') {
                s = -1;
                ch = *p++;
            }
            if (ch < '0' || ch > '9')
                expect("exponent digits");
            while (ch >= '0' && ch <= '9') {
                exp_val = exp_val * 10 + ch - '0';
                ch = *p++;
            }
            exp_val = exp_val * s;
            
            /* now we can generate the number */
            /* XXX: should patch directly float number */
            d = (double)bn[1] * 4294967296.0 + (double)bn[0];
            d = ldexp(d, exp_val - frac_bits);
            t = toup(ch);
            if (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                /* float : should handle overflow */
                tokc.f = (float)d;
            } else if (t == 'L') {
                ch = *p++;
#ifdef TCC_TARGET_PE
                tok = TOK_CDOUBLE;
                tokc.d = d;
#else
                tok = TOK_CLDOUBLE;
                /* XXX: not large enough */
                tokc.ld = (long double)d;
#endif
            } else {
                tok = TOK_CDOUBLE;
                tokc.d = d;
            }
        } else {
            /* decimal floats */
            if (ch == '.') {
                if (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
            float_frac_parse:
                while (ch >= '0' && ch <= '9') {
                    if (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            if (ch == 'e' || ch == 'E') {
                if (q >= token_buf + STRING_MAX_SIZE)
                    goto num_too_long;
                *q++ = ch;
                ch = *p++;
                if (ch == '-' || ch == '+') {
                    if (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
                if (ch < '0' || ch > '9')
                    expect("exponent digits");
                while (ch >= '0' && ch <= '9') {
                    if (q >= token_buf + STRING_MAX_SIZE)
                        goto num_too_long;
                    *q++ = ch;
                    ch = *p++;
                }
            }
            *q = '\0';
            t = toup(ch);
/* LJW HACK remove errno use
            errno = 0;
*/
            if (t == 'F') {
                ch = *p++;
                tok = TOK_CFLOAT;
                tokc.f = strtof(token_buf, NULL);
            } else if (t == 'L') {
                ch = *p++;
#ifdef TCC_TARGET_PE
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, NULL);
#else
                tok = TOK_CLDOUBLE;
                tokc.ld = strtold(token_buf, NULL);
#endif
            } else {
                tok = TOK_CDOUBLE;
                tokc.d = strtod(token_buf, NULL);
            }
        }
    } else {
        unsigned long long n, n1;
        int lcount, ucount, ov = 0;
        const char *p1;

        /* integer number */
        *q = '\0';
        q = token_buf;
        if (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        while(1) {
            t = *q++;
            /* no need for checks except for base 10 / 8 errors */
            if (t == '\0')
                break;
            else if (t >= 'a')
                t = t - 'a' + 10;
            else if (t >= 'A')
                t = t - 'A' + 10;
            else
                t = t - '0';
            if (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            /* detect overflow */
            if (n1 >= 0x1000000000000000ULL && n / b != n1)
                ov = 1;
        }

        /* Determine the characteristics (unsigned and/or 64bit) the type of
           the constant must have according to the constant suffix(es) */
        lcount = ucount = 0;
        p1 = p;
        for(;;) {
            t = toup(ch);
            if (t == 'L') {
                if (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                if (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } else if (t == 'U') {
                if (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } else {
                break;
            }
        }

        /* Determine if it needs 64 bits and/or unsigned in order to fit */
        if (ucount == 0 && b == 10) {
            if (lcount <= (LONG_SIZE == 4)) {
                if (n >= 0x80000000U)
                    lcount = (LONG_SIZE == 4) + 1;
            }
            if (n >= 0x8000000000000000ULL)
                ov = 1, ucount = 1;
        } else {
            if (lcount <= (LONG_SIZE == 4)) {
                if (n >= 0x100000000ULL)
                    lcount = (LONG_SIZE == 4) + 1;
                else if (n >= 0x80000000U)
                    ucount = 1;
            }
            if (n >= 0x8000000000000000ULL)
                ucount = 1;
        }

        if (ov)
            tcc_warning("integer constant overflow");

        tok = TOK_CINT;
	if (lcount) {
            tok = TOK_CLONG;
            if (lcount == 2)
                tok = TOK_CLLONG;
	}
	if (ucount)
	    ++tok; /* TOK_CU... */
        tokc.i = n;
    }
    if (ch)
        tcc_error("invalid number\n");
}


/* return next token with macro substitution */
void next(void)
{
 redo:
    if (parse_flags & PARSE_FLAG_SPACES)
        next_nomacro_spc();
    else
        next_nomacro();

    if (macro_ptr) {
        if (tok == TOK_NOSUBST || tok == TOK_PLCHLDR) {
        /* discard preprocessor markers */
            goto redo;
        } else if (tok == 0) {
            /* end of macro or unget token string */
            end_macro();
            goto redo;
        }
    } else if (tok >= TOK_IDENT && (parse_flags & PARSE_FLAG_PREPROCESS)) {
        Sym *s;
        /* if reading from file, try to substitute macros */
        s = define_find(tok);
        if (s) {
            Sym *nested_list = NULL;
            tokstr_buf.len = 0;
            macro_subst_tok(&tokstr_buf, &nested_list, s);
            tok_str_add(&tokstr_buf, 0);
            begin_macro(&tokstr_buf, 2);
            goto redo;
        }
    }
    /* convert preprocessor tokens into C tokens */
    if (tok == TOK_PPNUM) {
        if  (parse_flags & PARSE_FLAG_TOK_NUM)
            parse_number((char *)tokc.str.data);
    } else if (tok == TOK_PPSTR) {
        if (parse_flags & PARSE_FLAG_TOK_STR)
            parse_string((char *)tokc.str.data, tokc.str.size - 1);
    }
}

ST_FUNC void preprocess_start(TCCState *s1, int is_asm)
{
    cc2_bind_preprocess_types(s1);
    cc2_preprocess_start((int)s1, is_asm);
}

ST_FUNC void tccpp_new(TCCState *s)
{
    cc2_bind_preprocessor_state();
    cc2_preprocessor_set_stdout(s);
    cc2_tccpp_new((int)s, (int)tcc_keywords);
}

/* ------------------------------------------------------------------------- */
/* tcc -E [-P[1]] [-dD} support */

/* Preprocess the current file */
ST_FUNC int tcc_preprocess(TCCState *s1)
{
    return cc2_tcc_preprocess((int)s1);
}

/* ------------------------------------------------------------------------- */
