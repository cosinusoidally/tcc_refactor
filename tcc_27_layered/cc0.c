/*
 * cc0 dialect seed.
 *
 * This file is intentionally valid as both ECMAScript 3/5.1-style JavaScript
 * and old-style C when C is compiled with:
 *
 *   -Dfunction=int -Dvar=int
 *
 * Keep declarations in the intersection accepted by both parsers.
 */

var cc0_dialect_version;
var CC0_TOK_EOF;
var CC0_TOK_NAME;
var CC0_TOK_NUMBER;
var CC0_TOK_SPACE;
var CC0_TOK_PUNCT;
var CC0_SOURCE_NONE;
var CC0_SOURCE_CELLS;
var CC0_SOURCE_STRING;
var CC0_CH_NUL;
var CC0_CH_TAB;
var CC0_CH_LF;
var CC0_CH_VT;
var CC0_CH_FF;
var CC0_CH_CR;
var CC0_CH_SPACE;
var CC0_CH_BANG;
var CC0_CH_LPAREN;
var CC0_CH_RPAREN;
var CC0_CH_STAR;
var CC0_CH_PLUS;
var CC0_CH_COMMA;
var CC0_CH_MINUS;
var CC0_CH_0;
var CC0_CH_7;
var CC0_CH_9;
var CC0_CH_SEMI;
var CC0_CH_LT;
var CC0_CH_EQUAL;
var CC0_CH_GT;
var CC0_CH_A;
var CC0_CH_C;
var CC0_CH_H;
var CC0_CH_Z;
var CC0_CH_UNDERSCORE;
var CC0_CH_LBRACE;
var CC0_CH_RBRACE;
var CC0_CH_a;
var CC0_CH_c;
var CC0_CH_e;
var CC0_CH_f;
var CC0_CH_i;
var CC0_CH_m;
var CC0_CH_n;
var CC0_CH_o;
var CC0_CH_r;
var CC0_CH_t;
var CC0_CH_u;
var CC0_CH_v;
var CC0_CH_z;
var CC0_LOWER_TO_UPPER_DELTA;
var cc0_src_0;
var cc0_src_1;
var cc0_src_2;
var cc0_src_3;
var cc0_src_4;
var cc0_src_5;
var cc0_src_6;
var cc0_src_7;
var cc0_src_8;
var cc0_src_9;
var cc0_src_10;
var cc0_src_11;
var cc0_src_12;
var cc0_src_13;
var cc0_src_14;
var cc0_src_15;
var cc0_source_kind;
var cc0_source_ptr;
var cc0_scan_pos;
var cc0_tok_class;
var cc0_tok_start;
var cc0_tok_len;
var cc0_tok_value;

cc0_dialect_version = 1;
CC0_TOK_EOF = 0;
CC0_TOK_NAME = 1;
CC0_TOK_NUMBER = 2;
CC0_TOK_SPACE = 3;
CC0_TOK_PUNCT = 4;
CC0_SOURCE_NONE = 0;
CC0_SOURCE_CELLS = 1;
CC0_SOURCE_STRING = 2;
CC0_CH_NUL = 0;
CC0_CH_TAB = 9;
CC0_CH_LF = 10;
CC0_CH_VT = 11;
CC0_CH_FF = 12;
CC0_CH_CR = 13;
CC0_CH_SPACE = 32;
CC0_CH_BANG = 33;
CC0_CH_LPAREN = 40;
CC0_CH_RPAREN = 41;
CC0_CH_STAR = 42;
CC0_CH_PLUS = 43;
CC0_CH_COMMA = 44;
CC0_CH_MINUS = 45;
CC0_CH_0 = 48;
CC0_CH_7 = 55;
CC0_CH_9 = 57;
CC0_CH_SEMI = 59;
CC0_CH_LT = 60;
CC0_CH_EQUAL = 61;
CC0_CH_GT = 62;
CC0_CH_A = 65;
CC0_CH_C = 67;
CC0_CH_H = 72;
CC0_CH_Z = 90;
CC0_CH_UNDERSCORE = 95;
CC0_CH_LBRACE = 123;
CC0_CH_RBRACE = 125;
CC0_CH_a = 97;
CC0_CH_c = 99;
CC0_CH_e = 101;
CC0_CH_f = 102;
CC0_CH_i = 105;
CC0_CH_m = 109;
CC0_CH_n = 110;
CC0_CH_o = 111;
CC0_CH_r = 114;
CC0_CH_t = 116;
CC0_CH_u = 117;
CC0_CH_v = 118;
CC0_CH_z = 122;
CC0_LOWER_TO_UPPER_DELTA = 32;
cc0_src_0 = -1;
cc0_src_1 = -1;
cc0_src_2 = -1;
cc0_src_3 = -1;
cc0_src_4 = -1;
cc0_src_5 = -1;
cc0_src_6 = -1;
cc0_src_7 = -1;
cc0_src_8 = -1;
cc0_src_9 = -1;
cc0_src_10 = -1;
cc0_src_11 = -1;
cc0_src_12 = -1;
cc0_src_13 = -1;
cc0_src_14 = -1;
cc0_src_15 = -1;
cc0_source_kind = 0;
cc0_source_ptr = 0;
cc0_scan_pos = 0;
cc0_tok_class = 0;
cc0_tok_start = 0;
cc0_tok_len = 0;
cc0_tok_value = 0;

function cc0_add(a, b)
{
    return a + b;
}

function cc0_select(cond, when_true, when_false)
{
    if (cond)
        return when_true;
    return when_false;
}

function cc0_not(value)
{
    if (value)
        return 0;
    return 1;
}

function cc0_is_word_function_chars(c0, c1, c2, c3, c4, c5, c6, c7, c8)
{
    if (c0 != CC0_CH_f)
        return 0;
    if (c1 != CC0_CH_u)
        return 0;
    if (c2 != CC0_CH_n)
        return 0;
    if (c3 != CC0_CH_c)
        return 0;
    if (c4 != CC0_CH_t)
        return 0;
    if (c5 != CC0_CH_i)
        return 0;
    if (c6 != CC0_CH_o)
        return 0;
    if (c7 != CC0_CH_n)
        return 0;
    if (c8 != CC0_CH_NUL)
        return 0;
    return 1;
}

function cc0_is_word_var_chars(c0, c1, c2, c3)
{
    if (c0 != CC0_CH_v)
        return 0;
    if (c1 != CC0_CH_a)
        return 0;
    if (c2 != CC0_CH_r)
        return 0;
    if (c3 != CC0_CH_NUL)
        return 0;
    return 1;
}

function cc0_is_dialect_type_chars(c0, c1, c2, c3, c4, c5, c6, c7, c8)
{
    if (cc0_is_word_function_chars(c0, c1, c2, c3, c4, c5, c6, c7, c8))
        return 1;
    if (cc0_is_word_var_chars(c0, c1, c2, c3))
        return 1;
    return 0;
}

function cc0_is_word_return_chars(c0, c1, c2, c3, c4, c5, c6)
{
    if (c0 != CC0_CH_r)
        return 0;
    if (c1 != CC0_CH_e)
        return 0;
    if (c2 != CC0_CH_t)
        return 0;
    if (c3 != CC0_CH_u)
        return 0;
    if (c4 != CC0_CH_r)
        return 0;
    if (c5 != CC0_CH_n)
        return 0;
    if (c6 != CC0_CH_NUL)
        return 0;
    return 1;
}

function cc0_is_word_if_chars(c0, c1, c2)
{
    if (c0 != CC0_CH_i)
        return 0;
    if (c1 != CC0_CH_f)
        return 0;
    if (c2 != CC0_CH_NUL)
        return 0;
    return 1;
}

function cc0_is_digit(c)
{
    if (c >= CC0_CH_0)
        if (c <= CC0_CH_9)
            return 1;
    return 0;
}

function cc0_is_oct_digit(c)
{
    if (c >= CC0_CH_0)
        if (c <= CC0_CH_7)
            return 1;
    return 0;
}

function cc0_is_upper(c)
{
    if (c >= CC0_CH_A)
        if (c <= CC0_CH_Z)
            return 1;
    return 0;
}

function cc0_is_lower(c)
{
    if (c >= CC0_CH_a)
        if (c <= CC0_CH_z)
            return 1;
    return 0;
}

function cc0_is_alpha(c)
{
    if (cc0_is_upper(c))
        return 1;
    if (cc0_is_lower(c))
        return 1;
    return 0;
}

function cc0_to_upper(c)
{
    if (cc0_is_lower(c))
        return c - CC0_LOWER_TO_UPPER_DELTA;
    return c;
}

function cc0_is_name_start(c)
{
    if (cc0_is_alpha(c))
        return 1;
    if (c == CC0_CH_UNDERSCORE)
        return 1;
    return 0;
}

function cc0_is_name_continue(c)
{
    if (cc0_is_name_start(c))
        return 1;
    if (cc0_is_digit(c))
        return 1;
    return 0;
}

function cc0_is_space(c)
{
    if (c == CC0_CH_SPACE)
        return 1;
    if (c == CC0_CH_TAB)
        return 1;
    if (c == CC0_CH_LF)
        return 1;
    if (c == CC0_CH_VT)
        return 1;
    if (c == CC0_CH_FF)
        return 1;
    if (c == CC0_CH_CR)
        return 1;
    return 0;
}

function cc0_tccpp_char_flags(c)
{
    if (cc0_is_space(c))
        if (c != CC0_CH_LF)
            return 1;
    if (cc0_is_name_start(c))
        return 2;
    if (cc0_is_digit(c))
        return 4;
    return 0;
}

function cc0_tccpp_is_space(c)
{
    if (cc0_tccpp_char_flags(c) == 1)
        return 1;
    return 0;
}

function cc0_token_class(c)
{
    if (c < 0)
        return CC0_TOK_EOF;
    if (cc0_is_space(c))
        return CC0_TOK_SPACE;
    if (cc0_is_name_start(c))
        return CC0_TOK_NAME;
    if (cc0_is_digit(c))
        return CC0_TOK_NUMBER;
    return CC0_TOK_PUNCT;
}

function cc0_source_set8(c0, c1, c2, c3, c4, c5, c6, c7)
{
    cc0_source_kind = CC0_SOURCE_CELLS;
    cc0_source_ptr = 0;
    cc0_src_0 = c0;
    cc0_src_1 = c1;
    cc0_src_2 = c2;
    cc0_src_3 = c3;
    cc0_src_4 = c4;
    cc0_src_5 = c5;
    cc0_src_6 = c6;
    cc0_src_7 = c7;
    cc0_src_8 = -1;
    cc0_src_9 = -1;
    cc0_src_10 = -1;
    cc0_src_11 = -1;
    cc0_src_12 = -1;
    cc0_src_13 = -1;
    cc0_src_14 = -1;
    cc0_src_15 = -1;
    cc0_scan_pos = 0;
    cc0_tok_class = CC0_TOK_EOF;
    cc0_tok_start = 0;
    cc0_tok_len = 0;
    cc0_tok_value = 0;
    return 0;
}

function cc0_source_set16(c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15)
{
    cc0_source_kind = CC0_SOURCE_CELLS;
    cc0_source_ptr = 0;
    cc0_src_0 = c0;
    cc0_src_1 = c1;
    cc0_src_2 = c2;
    cc0_src_3 = c3;
    cc0_src_4 = c4;
    cc0_src_5 = c5;
    cc0_src_6 = c6;
    cc0_src_7 = c7;
    cc0_src_8 = c8;
    cc0_src_9 = c9;
    cc0_src_10 = c10;
    cc0_src_11 = c11;
    cc0_src_12 = c12;
    cc0_src_13 = c13;
    cc0_src_14 = c14;
    cc0_src_15 = c15;
    cc0_scan_pos = 0;
    cc0_tok_class = CC0_TOK_EOF;
    cc0_tok_start = 0;
    cc0_tok_len = 0;
    cc0_tok_value = 0;
    return 0;
}

function cc0_source_set_string(ptr)
{
    cc0_source_kind = CC0_SOURCE_STRING;
    cc0_source_ptr = ptr;
    cc0_scan_pos = 0;
    cc0_tok_class = CC0_TOK_EOF;
    cc0_tok_start = 0;
    cc0_tok_len = 0;
    cc0_tok_value = 0;
    return 0;
}

function cc0_source_at(pos)
{
    var c;
    if (cc0_source_kind == CC0_SOURCE_STRING) {
        c = cc0_heap_get(cc0_source_ptr, pos);
        if (c == CC0_CH_NUL)
            return -1;
        return c;
    }
    if (pos == 0)
        return cc0_src_0;
    if (pos == 1)
        return cc0_src_1;
    if (pos == 2)
        return cc0_src_2;
    if (pos == 3)
        return cc0_src_3;
    if (pos == 4)
        return cc0_src_4;
    if (pos == 5)
        return cc0_src_5;
    if (pos == 6)
        return cc0_src_6;
    if (pos == 7)
        return cc0_src_7;
    if (pos == 8)
        return cc0_src_8;
    if (pos == 9)
        return cc0_src_9;
    if (pos == 10)
        return cc0_src_10;
    if (pos == 11)
        return cc0_src_11;
    if (pos == 12)
        return cc0_src_12;
    if (pos == 13)
        return cc0_src_13;
    if (pos == 14)
        return cc0_src_14;
    if (pos == 15)
        return cc0_src_15;
    return -1;
}

function cc0_scan_skip_space()
{
    var c;
    c = cc0_source_at(cc0_scan_pos);
    while (cc0_is_space(c)) {
        cc0_scan_pos = cc0_scan_pos + 1;
        c = cc0_source_at(cc0_scan_pos);
    }
    return c;
}

function cc0_scan_next()
{
    var c;
    c = cc0_scan_skip_space();
    cc0_tok_start = cc0_scan_pos;
    cc0_tok_len = 0;
    cc0_tok_value = 0;
    cc0_tok_class = cc0_token_class(c);
    if (cc0_tok_class == CC0_TOK_EOF)
        return cc0_tok_class;
    if (cc0_tok_class == CC0_TOK_NAME) {
        while (cc0_is_name_continue(c)) {
            cc0_scan_pos = cc0_scan_pos + 1;
            cc0_tok_len = cc0_tok_len + 1;
            c = cc0_source_at(cc0_scan_pos);
        }
        return cc0_tok_class;
    }
    if (cc0_tok_class == CC0_TOK_NUMBER) {
        while (cc0_is_digit(c)) {
            cc0_tok_value = cc0_tok_value * 10 + c - CC0_CH_0;
            cc0_scan_pos = cc0_scan_pos + 1;
            cc0_tok_len = cc0_tok_len + 1;
            c = cc0_source_at(cc0_scan_pos);
        }
        return cc0_tok_class;
    }
    cc0_scan_pos = cc0_scan_pos + 1;
    cc0_tok_len = 1;
    return cc0_tok_class;
}

function cc0_get_tok_class()
{
    return cc0_tok_class;
}

function cc0_get_tok_start()
{
    return cc0_tok_start;
}

function cc0_get_tok_len()
{
    return cc0_tok_len;
}

function cc0_get_tok_value()
{
    return cc0_tok_value;
}

function cc0_get_tok_first()
{
    return cc0_source_at(cc0_tok_start);
}

function cc0_tok_is_word_function()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 8)
        return 0;
    return cc0_is_word_function_chars(
        cc0_source_at(cc0_tok_start),
        cc0_source_at(cc0_tok_start + 1),
        cc0_source_at(cc0_tok_start + 2),
        cc0_source_at(cc0_tok_start + 3),
        cc0_source_at(cc0_tok_start + 4),
        cc0_source_at(cc0_tok_start + 5),
        cc0_source_at(cc0_tok_start + 6),
        cc0_source_at(cc0_tok_start + 7),
        CC0_CH_NUL);
}

function cc0_tok_is_word_var()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 3)
        return 0;
    return cc0_is_word_var_chars(
        cc0_source_at(cc0_tok_start),
        cc0_source_at(cc0_tok_start + 1),
        cc0_source_at(cc0_tok_start + 2),
        CC0_CH_NUL);
}

function cc0_tok_is_word_return()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 6)
        return 0;
    return cc0_is_word_return_chars(
        cc0_source_at(cc0_tok_start),
        cc0_source_at(cc0_tok_start + 1),
        cc0_source_at(cc0_tok_start + 2),
        cc0_source_at(cc0_tok_start + 3),
        cc0_source_at(cc0_tok_start + 4),
        cc0_source_at(cc0_tok_start + 5),
        CC0_CH_NUL);
}

function cc0_tok_is_word_if()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 2)
        return 0;
    return cc0_is_word_if_chars(
        cc0_source_at(cc0_tok_start),
        cc0_source_at(cc0_tok_start + 1),
        CC0_CH_NUL);
}
