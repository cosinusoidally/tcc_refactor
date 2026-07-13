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

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define STATIC_DATA_WANTED (nocode_wanted & 0xC0000000) /* only static data output */
CType func_vt; /* current function return type (used by return instruction) */

/* ------------------------------------------------------------------------- */

void gen_cast(CType *type);
void gen_cast_s(int t);
int parse_btype(CType *type, AttributeDef *ad);
CType *type_decl(CType *type, AttributeDef *ad, int *v, int td);
void parse_expr_type(CType *type);
void parse_init_elem(int expr_type);
void init_putz(Section *sec, unsigned long c, int size);
void block_return(void);
void block_break(int *break_symbol);
void block_continue(int *continue_symbol);
void block_if(int *break_symbol, int *continue_symbol);
void block_while(void);
void block_do(void);
void block_for(void);
void block_case(void);
void block_default(void);
void block_goto(void);
void block_expression(int is_expression);
void block_switch(int *continue_symbol);
void block_after_label(int *break_symbol, int *continue_symbol,
                       int is_expression);
void block_label(int label, int *break_symbol, int *continue_symbol,
                 int is_expression);
void block_compound(int *break_symbol, int *continue_symbol,
                    int is_expression);
void unary_identifier(int token);
void unary_postfix_field(int operator);
void unary_postfix_index(void);
void unary_postfix_call(void);
void unary_prefix(int operator);
void unary_literal(int token);
void unary_postfix_increment(int operator);
void unary_builtin_expression(int token);
void unary_builtin_frame(int token);
void unary_label_address(int token);
void unary_sizeof(int token);
void unary_minus(void);
void unary_ieee_constant(int token);
int unary_parenthesized(int sizeof_caller);
void unary_string(int token);
void unary_function_name(int token);
void unary_generic(void);
void parse_type(CType *type);
void parse_builtin_params(int nc, const char *args);
void parse_attribute(AttributeDef *ad);
void init_putv(CType *type, Section *sec, unsigned long c);
void decl_initializer(CType *type, Section *sec, unsigned long c, int first, int size_only);
void block(int *bsym, int *csym, int is_expr);
void decl_initializer_alloc(CType *type, AttributeDef *ad, int r, int has_init, int v, int scope);
void decl(int l);
int decl0(int l, int is_for_loop_init, Sym *);
void expr_eq(void);
static inline int64_t expr_const64(void);
static void vpush64(int ty, unsigned long long v);
int gvtst(int inv, int t);
void gen_inline_functions(TCCState *s);
void skip_or_save_block(TokenString **str);

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */

/* ------------------------------------------------------------------------- */
/* vstack debugging aid */

#if 0
void pv (const char *lbl, int a, int b)
{
    int i;
    for (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (int)p->c.i);
    }
}
#endif

/* ------------------------------------------------------------------------- */
/* start of translation unit info */
void tcc_debug_start(TCCState *s1)
{
    if (s1->do_debug) {
        char buf[512];

        /* file info: full path + filename */
        section_sym = put_elf_sym(symtab_section, 0, 0,
                                  ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                  text_section->sh_num, NULL);
        getcwd(buf, sizeof(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif
        pstrcat(buf, sizeof(buf), "/");
        put_stabs_r(buf, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
        put_stabs_r(file->filename, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
        last_ind = 0;
        last_line_num = 0;
    }

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, file->filename);
}

/* put end of translation unit info */
void tcc_debug_end(TCCState *s1)
{
    if (!s1->do_debug)
        return;
    put_stabs_r(NULL, N_SO, 0, 0,
        text_section->data_offset, text_section, section_sym);

}

/* generate line number info */
void tcc_debug_line(TCCState *s1)
{
    if (!s1->do_debug)
        return;
    if ((last_line_num != file->line_num || last_ind != ind)) {
        put_stabn(N_SLINE, 0, file->line_num, ind - func_ind);
        last_ind = ind;
        last_line_num = file->line_num;
    }
}

/* put function symbol */
void tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    char buf[512];

    if (!s1->do_debug)
        return;

    /* stabs info */
    /* XXX: we put here a dummy type */
    snprintf(buf, sizeof(buf), "%s:%c1",
             funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
    put_stabs_r(buf, N_FUN, 0, file->line_num, 0,
                cur_text_section, sym->c);
    /* //gr gdb wants a line at the function */
    put_stabn(N_SLINE, 0, file->line_num, 0);

    last_ind = 0;
    last_line_num = 0;
}

/* put function size */
void tcc_debug_funcend(TCCState *s1, int size)
{
    if (!s1->do_debug)
        return;
    put_stabn(N_FUN, 0, 0, size);
}

/* ------------------------------------------------------------------------- */
ElfSym *elfsym(Sym *s)
{
  if (!s || !s->c)
    return NULL;
  return &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

/* add a new relocation entry to symbol 'sym' in section 's' */

/* push arbitrary 64bit constant */


/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */

/* single-byte load mode for packed or otherwise unaligned bitfields */

/* single-byte store mode for packed or otherwise unaligned bitfields */


/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */


#if PTR_SIZE == 4
/* expand 64bit on stack in two ints */
#endif

#if PTR_SIZE == 4
/* build a long long from two ints */
#endif

/* convert stack entry to register and duplicate its value in another
   register */

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */



/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
void type_to_str(char *buf, int buf_size,
                 CType *type, const char *varstr)
{
    int bt, v, t;
    Sym *s, *sa;
    char buf1[256];
    const char *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    if (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    if (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    if (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    if (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    if (t & VT_VOLATILE)
        pstrcat(buf, buf_size, "volatile ");
    if (t & VT_CONSTANT)
        pstrcat(buf, buf_size, "const ");

    if (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    switch(bt) {
    case VT_VOID:
        tstr = "void";
        goto add_tstr;
    case VT_BOOL:
        tstr = "_Bool";
        goto add_tstr;
    case VT_BYTE:
        tstr = "char";
        goto add_tstr;
    case VT_SHORT:
        tstr = "short";
        goto add_tstr;
    case VT_INT:
        tstr = "int";
        goto maybe_long;
    case VT_LLONG:
        tstr = "long long";
    maybe_long:
        if (t & VT_LONG)
            tstr = "long";
        if (!IS_ENUM(t))
            goto add_tstr;
        tstr = "enum ";
        goto tstruct;
    case VT_FLOAT:
        tstr = "float";
        goto add_tstr;
    case VT_DOUBLE:
        tstr = "double";
        goto add_tstr;
    case VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        break;
    case VT_STRUCT:
        tstr = "struct ";
        if (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        if (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        else
            pstrcat(buf, buf_size, get_tok_str(v, NULL));
        break;
    case VT_FUNC:
        s = type->ref;
        type_to_str(buf, buf_size, &s->type, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        while (sa != NULL) {
            type_to_str(buf1, sizeof(buf1), &sa->type, NULL);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            if (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        goto no_var;
    case VT_PTR:
        s = type->ref;
        if (t & VT_ARRAY) {
            snprintf(buf1, sizeof(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            goto no_var;
        }
        pstrcpy(buf1, sizeof(buf1), "*");
        if (t & VT_CONSTANT)
            pstrcat(buf1, buf_size, "const ");
        if (t & VT_VOLATILE)
            pstrcat(buf1, buf_size, "volatile ");
        if (varstr)
            pstrcat(buf1, sizeof(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        goto no_var;
    }
    if (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}


/* Parse __attribute__((...)) GNUC extension. */
/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
/* indirection with full error checking and bound check */

/* pass a parameter to a function and do type checking and casting */
/* parse an expression and return its type without any side effect. */

/* parse an integer constant and return its value. */

/* return the label token if current token is a label, otherwise
   return zero */


/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
#define EXPR_CONST 1
#define EXPR_ANY   2

/* Replicate already encoded target bytes for a GNU range designator. */

/* store a value or an expression directly in global data or in local array */
/* Allocate TCC's variable-sized inline record and capture its body. */

/* 'l' is VT_LOCAL or VT_CONST to define default storage type, or VT_CMP
   if parsing old style parameter decl list (and FUNC_SYM is set then) */
