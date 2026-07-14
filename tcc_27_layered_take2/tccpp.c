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
