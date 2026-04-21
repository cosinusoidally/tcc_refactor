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
var CC0_TOK_CHAR;
var CC0_TOK_STRING;
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
var CC0_CH_DQUOTE;
var CC0_CH_HASH;
var CC0_CH_SQUOTE;
var CC0_CH_LPAREN;
var CC0_CH_RPAREN;
var CC0_CH_STAR;
var CC0_CH_PLUS;
var CC0_CH_COMMA;
var CC0_CH_MINUS;
var CC0_CH_DOT;
var CC0_CH_SLASH;
var CC0_CH_0;
var CC0_CH_7;
var CC0_CH_9;
var CC0_CH_SEMI;
var CC0_CH_LT;
var CC0_CH_EQUAL;
var CC0_CH_GT;
var CC0_CH_AMP;
var CC0_CH_PERCENT;
var CC0_CH_CARET;
var CC0_CH_BAR;
var CC0_CH_A;
var CC0_CH_C;
var CC0_CH_F;
var CC0_CH_H;
var CC0_CH_U;
var CC0_CH_Z;
var CC0_CH_BACKSLASH;
var CC0_CH_UNDERSCORE;
var CC0_CH_QUESTION;
var CC0_CH_LBRACE;
var CC0_CH_RBRACE;
var CC0_CH_a;
var CC0_CH_b;
var CC0_CH_c;
var CC0_CH_d;
var CC0_CH_e;
var CC0_CH_f;
var CC0_CH_g;
var CC0_CH_h;
var CC0_CH_i;
var CC0_CH_k;
var CC0_CH_l;
var CC0_CH_m;
var CC0_CH_n;
var CC0_CH_o;
var CC0_CH_p;
var CC0_CH_r;
var CC0_CH_s;
var CC0_CH_t;
var CC0_CH_u;
var CC0_CH_v;
var CC0_CH_w;
var CC0_CH_x;
var CC0_CH_z;
var CC0_LOWER_TO_UPPER_DELTA;
var CC0_ESCAPE_BEL;
var CC0_ESCAPE_BS;
var CC0_ESCAPE_ESC;
var CC0_TCC_TOK_SHL;
var CC0_TCC_TOK_SAR;
var CC0_TCC_TOK_EQ;
var CC0_TCC_TOK_NE;
var CC0_TCC_TOK_GE;
var CC0_TCC_TOK_LE;
var CC0_TCC_TOK_LAND;
var CC0_TCC_TOK_LOR;
var CC0_TCC_TOK_DEC;
var CC0_TCC_TOK_INC;
var CC0_TCC_TOK_TWODOTS;
var CC0_TCC_TOK_ARROW;
var CC0_TCC_TOK_DOTS;
var CC0_TCC_TOK_TWOSHARPS;
var CC0_TCC_TOK_A_MOD;
var CC0_TCC_TOK_A_AND;
var CC0_TCC_TOK_A_MUL;
var CC0_TCC_TOK_A_ADD;
var CC0_TCC_TOK_A_SUB;
var CC0_TCC_TOK_A_DIV;
var CC0_TCC_TOK_A_XOR;
var CC0_TCC_TOK_A_OR;
var CC0_TCC_TOK_A_SHL;
var CC0_TCC_TOK_A_SAR;
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
CC0_TOK_CHAR = 5;
CC0_TOK_STRING = 6;
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
CC0_CH_DQUOTE = 34;
CC0_CH_HASH = 35;
CC0_CH_SQUOTE = 39;
CC0_CH_LPAREN = 40;
CC0_CH_RPAREN = 41;
CC0_CH_STAR = 42;
CC0_CH_PLUS = 43;
CC0_CH_COMMA = 44;
CC0_CH_MINUS = 45;
CC0_CH_DOT = 46;
CC0_CH_SLASH = 47;
CC0_CH_0 = 48;
CC0_CH_7 = 55;
CC0_CH_9 = 57;
CC0_CH_SEMI = 59;
CC0_CH_LT = 60;
CC0_CH_EQUAL = 61;
CC0_CH_GT = 62;
CC0_CH_AMP = 38;
CC0_CH_PERCENT = 37;
CC0_CH_CARET = 94;
CC0_CH_BAR = 124;
CC0_CH_A = 65;
CC0_CH_C = 67;
CC0_CH_F = 70;
CC0_CH_H = 72;
CC0_CH_U = 85;
CC0_CH_Z = 90;
CC0_CH_BACKSLASH = 92;
CC0_CH_UNDERSCORE = 95;
CC0_CH_QUESTION = 63;
CC0_CH_LBRACE = 123;
CC0_CH_RBRACE = 125;
CC0_CH_a = 97;
CC0_CH_b = 98;
CC0_CH_c = 99;
CC0_CH_d = 100;
CC0_CH_e = 101;
CC0_CH_f = 102;
CC0_CH_g = 103;
CC0_CH_h = 104;
CC0_CH_i = 105;
CC0_CH_k = 107;
CC0_CH_l = 108;
CC0_CH_m = 109;
CC0_CH_n = 110;
CC0_CH_o = 111;
CC0_CH_p = 112;
CC0_CH_r = 114;
CC0_CH_s = 115;
CC0_CH_t = 116;
CC0_CH_u = 117;
CC0_CH_v = 118;
CC0_CH_w = 119;
CC0_CH_x = 120;
CC0_CH_z = 122;
CC0_LOWER_TO_UPPER_DELTA = 32;
CC0_ESCAPE_BEL = 7;
CC0_ESCAPE_BS = 8;
CC0_ESCAPE_ESC = 27;
CC0_TCC_TOK_SHL = 1;
CC0_TCC_TOK_SAR = 2;
CC0_TCC_TOK_EQ = 148;
CC0_TCC_TOK_NE = 149;
CC0_TCC_TOK_GE = 157;
CC0_TCC_TOK_LE = 158;
CC0_TCC_TOK_LAND = 160;
CC0_TCC_TOK_LOR = 161;
CC0_TCC_TOK_DEC = 162;
CC0_TCC_TOK_INC = 164;
CC0_TCC_TOK_TWODOTS = 168;
CC0_TCC_TOK_ARROW = 199;
CC0_TCC_TOK_DOTS = 200;
CC0_TCC_TOK_TWOSHARPS = 202;
CC0_TCC_TOK_A_MOD = 165;
CC0_TCC_TOK_A_AND = 166;
CC0_TCC_TOK_A_MUL = 170;
CC0_TCC_TOK_A_ADD = 171;
CC0_TCC_TOK_A_SUB = 173;
CC0_TCC_TOK_A_DIV = 175;
CC0_TCC_TOK_A_XOR = 222;
CC0_TCC_TOK_A_OR = 252;
CC0_TCC_TOK_A_SHL = 129;
CC0_TCC_TOK_A_SAR = 130;
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

function cc0_is_word_mkc_chars(c0, c1, c2, c3)
{
    if (c0 != CC0_CH_m)
        return 0;
    if (c1 != CC0_CH_k)
        return 0;
    if (c2 != CC0_CH_c)
        return 0;
    if (c3 != CC0_CH_NUL)
        return 0;
    return 1;
}

function cc0_is_word_mks_chars(c0, c1, c2, c3)
{
    if (c0 != CC0_CH_m)
        return 0;
    if (c1 != CC0_CH_k)
        return 0;
    if (c2 != CC0_CH_s)
        return 0;
    if (c3 != CC0_CH_NUL)
        return 0;
    return 1;
}

function cc0_is_word_while_chars(c0, c1, c2, c3, c4, c5)
{
    if (c0 != CC0_CH_w)
        return 0;
    if (c1 != CC0_CH_h)
        return 0;
    if (c2 != CC0_CH_i)
        return 0;
    if (c3 != CC0_CH_l)
        return 0;
    if (c4 != CC0_CH_e)
        return 0;
    if (c5 != CC0_CH_NUL)
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

function cc0_hex_digit_value(c)
{
    if (cc0_is_digit(c))
        return c - CC0_CH_0;
    if (c >= CC0_CH_a)
        if (c <= CC0_CH_f)
            return c - CC0_CH_a + 10;
    if (c >= CC0_CH_A)
        if (c <= CC0_CH_F)
            return c - CC0_CH_A + 10;
    return -1;
}

function cc0_c_escape_value(c, allow_gnu)
{
    if (c == CC0_CH_a)
        return CC0_ESCAPE_BEL;
    if (c == CC0_CH_b)
        return CC0_ESCAPE_BS;
    if (c == CC0_CH_f)
        return CC0_CH_FF;
    if (c == CC0_CH_n)
        return CC0_CH_LF;
    if (c == CC0_CH_r)
        return CC0_CH_CR;
    if (c == CC0_CH_t)
        return CC0_CH_TAB;
    if (c == CC0_CH_v)
        return CC0_CH_VT;
    if (c == CC0_CH_e)
        if (allow_gnu)
            return CC0_ESCAPE_ESC;
    if (c == CC0_CH_SQUOTE)
        return c;
    if (c == CC0_CH_DQUOTE)
        return c;
    if (c == CC0_CH_BACKSLASH)
        return c;
    if (c == CC0_CH_QUESTION)
        return c;
    return -1;
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
    if (c == CC0_CH_SQUOTE)
        return CC0_TOK_CHAR;
    if (c == CC0_CH_DQUOTE)
        return CC0_TOK_STRING;
    return CC0_TOK_PUNCT;
}

function cc0_tccpp_pair_token(c0, c1)
{
    if (c0 == CC0_CH_LT)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_LE;
    if (c0 == CC0_CH_GT)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_GE;
    if (c0 == CC0_CH_BANG)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_NE;
    if (c0 == CC0_CH_AMP)
        if (c1 == CC0_CH_AMP)
            return CC0_TCC_TOK_LAND;
    if (c0 == CC0_CH_AMP)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_A_AND;
    if (c0 == CC0_CH_PLUS)
        if (c1 == CC0_CH_PLUS)
            return CC0_TCC_TOK_INC;
    if (c0 == CC0_CH_PLUS)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_A_ADD;
    if (c0 == CC0_CH_MINUS)
        if (c1 == CC0_CH_MINUS)
            return CC0_TCC_TOK_DEC;
    if (c0 == CC0_CH_MINUS)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_A_SUB;
    if (c0 == CC0_CH_MINUS)
        if (c1 == CC0_CH_GT)
            return CC0_TCC_TOK_ARROW;
    if (c0 == CC0_CH_EQUAL)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_EQ;
    if (c0 == CC0_CH_LT)
        if (c1 == CC0_CH_LT)
            return CC0_TCC_TOK_SHL;
    if (c0 == CC0_CH_GT)
        if (c1 == CC0_CH_GT)
            return CC0_TCC_TOK_SAR;
    if (c0 == CC0_CH_STAR)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_A_MUL;
    if (c0 == CC0_CH_SLASH)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_A_DIV;
    if (c0 == CC0_CH_PERCENT)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_A_MOD;
    if (c0 == CC0_CH_CARET)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_A_XOR;
    if (c0 == CC0_CH_BAR)
        if (c1 == CC0_CH_BAR)
            return CC0_TCC_TOK_LOR;
    if (c0 == CC0_CH_BAR)
        if (c1 == CC0_CH_EQUAL)
            return CC0_TCC_TOK_A_OR;
    if (c0 == CC0_CH_DOT)
        if (c1 == CC0_CH_DOT)
            return CC0_TCC_TOK_TWODOTS;
    if (c0 == CC0_CH_HASH)
        if (c1 == CC0_CH_HASH)
            return CC0_TCC_TOK_TWOSHARPS;
    return 0;
}

function cc0_tccpp_three_token(c0, c1, c2)
{
    if (c0 == CC0_CH_LT)
        if (c1 == CC0_CH_LT)
            if (c2 == CC0_CH_EQUAL)
                return CC0_TCC_TOK_A_SHL;
    if (c0 == CC0_CH_GT)
        if (c1 == CC0_CH_GT)
            if (c2 == CC0_CH_EQUAL)
                return CC0_TCC_TOK_A_SAR;
    if (c0 == CC0_CH_DOT)
        if (c1 == CC0_CH_DOT)
            if (c2 == CC0_CH_DOT)
                return CC0_TCC_TOK_DOTS;
    return 0;
}

function cc0_tccpp_pair_first(tok)
{
    if (tok == CC0_TCC_TOK_LE)
        return CC0_CH_LT;
    if (tok == CC0_TCC_TOK_GE)
        return CC0_CH_GT;
    if (tok == CC0_TCC_TOK_NE)
        return CC0_CH_BANG;
    if (tok == CC0_TCC_TOK_LAND)
        return CC0_CH_AMP;
    if (tok == CC0_TCC_TOK_LOR)
        return CC0_CH_BAR;
    if (tok == CC0_TCC_TOK_INC)
        return CC0_CH_PLUS;
    if (tok == CC0_TCC_TOK_DEC)
        return CC0_CH_MINUS;
    if (tok == CC0_TCC_TOK_EQ)
        return CC0_CH_EQUAL;
    if (tok == CC0_TCC_TOK_SHL)
        return CC0_CH_LT;
    if (tok == CC0_TCC_TOK_SAR)
        return CC0_CH_GT;
    if (tok == CC0_TCC_TOK_A_ADD)
        return CC0_CH_PLUS;
    if (tok == CC0_TCC_TOK_A_SUB)
        return CC0_CH_MINUS;
    if (tok == CC0_TCC_TOK_A_MUL)
        return CC0_CH_STAR;
    if (tok == CC0_TCC_TOK_A_DIV)
        return CC0_CH_SLASH;
    if (tok == CC0_TCC_TOK_A_MOD)
        return CC0_CH_PERCENT;
    if (tok == CC0_TCC_TOK_A_AND)
        return CC0_CH_AMP;
    if (tok == CC0_TCC_TOK_A_XOR)
        return CC0_CH_CARET;
    if (tok == CC0_TCC_TOK_A_OR)
        return CC0_CH_BAR;
    if (tok == CC0_TCC_TOK_ARROW)
        return CC0_CH_MINUS;
    if (tok == CC0_TCC_TOK_TWODOTS)
        return CC0_CH_DOT;
    if (tok == CC0_TCC_TOK_TWOSHARPS)
        return CC0_CH_HASH;
    return -1;
}

function cc0_tccpp_three_first(tok)
{
    if (tok == CC0_TCC_TOK_A_SHL)
        return CC0_CH_LT;
    if (tok == CC0_TCC_TOK_A_SAR)
        return CC0_CH_GT;
    if (tok == CC0_TCC_TOK_DOTS)
        return CC0_CH_DOT;
    return -1;
}

function cc0_tccpp_three_second(tok)
{
    if (tok == CC0_TCC_TOK_A_SHL)
        return CC0_CH_LT;
    if (tok == CC0_TCC_TOK_A_SAR)
        return CC0_CH_GT;
    if (tok == CC0_TCC_TOK_DOTS)
        return CC0_CH_DOT;
    return -1;
}

function cc0_tccpp_three_third(tok)
{
    if (tok == CC0_TCC_TOK_A_SHL)
        return CC0_CH_EQUAL;
    if (tok == CC0_TCC_TOK_A_SAR)
        return CC0_CH_EQUAL;
    if (tok == CC0_TCC_TOK_DOTS)
        return CC0_CH_DOT;
    return -1;
}

function cc0_tccpp_pair_second(tok)
{
    if (tok == CC0_TCC_TOK_LAND)
        return CC0_CH_AMP;
    if (tok == CC0_TCC_TOK_LOR)
        return CC0_CH_BAR;
    if (tok == CC0_TCC_TOK_INC)
        return CC0_CH_PLUS;
    if (tok == CC0_TCC_TOK_DEC)
        return CC0_CH_MINUS;
    if (tok == CC0_TCC_TOK_SHL)
        return CC0_CH_LT;
    if (tok == CC0_TCC_TOK_SAR)
        return CC0_CH_GT;
    if (tok == CC0_TCC_TOK_ARROW)
        return CC0_CH_GT;
    if (tok == CC0_TCC_TOK_TWODOTS)
        return CC0_CH_DOT;
    if (tok == CC0_TCC_TOK_TWOSHARPS)
        return CC0_CH_HASH;
    if (cc0_tccpp_pair_first(tok) >= 0)
        return CC0_CH_EQUAL;
    return -1;
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

function cc0_source_seek(pos)
{
    cc0_scan_pos = pos;
    cc0_tok_class = CC0_TOK_EOF;
    cc0_tok_start = pos;
    cc0_tok_len = 0;
    cc0_tok_value = 0;
    return 1;
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
    var next;
    c = cc0_source_at(cc0_scan_pos);
    while (cc0_is_space(c)) {
        cc0_scan_pos = cc0_scan_pos + 1;
        c = cc0_source_at(cc0_scan_pos);
    }
    while (c == CC0_CH_SLASH) {
        next = cc0_source_at(cc0_scan_pos + 1);
        if (next != CC0_CH_STAR)
            return c;
        cc0_scan_pos = cc0_scan_pos + 2;
        c = cc0_source_at(cc0_scan_pos);
        while (c >= 0) {
            if (c == CC0_CH_STAR)
                if (cc0_source_at(cc0_scan_pos + 1) == CC0_CH_SLASH) {
                    cc0_scan_pos = cc0_scan_pos + 2;
                    c = cc0_source_at(cc0_scan_pos);
                    while (cc0_is_space(c)) {
                        cc0_scan_pos = cc0_scan_pos + 1;
                        c = cc0_source_at(cc0_scan_pos);
                    }
                    break;
                }
            cc0_scan_pos = cc0_scan_pos + 1;
            c = cc0_source_at(cc0_scan_pos);
        }
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
    if (cc0_tok_class == CC0_TOK_CHAR) {
        cc0_scan_pos = cc0_scan_pos + 1;
        cc0_tok_value = cc0_source_at(cc0_scan_pos);
        cc0_scan_pos = cc0_scan_pos + 1;
        if (cc0_source_at(cc0_scan_pos) == CC0_CH_SQUOTE)
            cc0_scan_pos = cc0_scan_pos + 1;
        cc0_tok_len = 1;
        return cc0_tok_class;
    }
    if (cc0_tok_class == CC0_TOK_STRING) {
        cc0_scan_pos = cc0_scan_pos + 1;
        cc0_tok_start = cc0_scan_pos;
        c = cc0_source_at(cc0_scan_pos);
        while (c >= 0) {
            if (c == CC0_CH_DQUOTE) {
                cc0_tok_value = cc0_heap_slice(cc0_source_ptr, cc0_tok_start, cc0_tok_len);
                cc0_scan_pos = cc0_scan_pos + 1;
                return cc0_tok_class;
            }
            cc0_scan_pos = cc0_scan_pos + 1;
            cc0_tok_len = cc0_tok_len + 1;
            c = cc0_source_at(cc0_scan_pos);
        }
        cc0_tok_value = 0;
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

function cc0_tok_is_word_mkc()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 3)
        return 0;
    return cc0_is_word_mkc_chars(
        cc0_source_at(cc0_tok_start),
        cc0_source_at(cc0_tok_start + 1),
        cc0_source_at(cc0_tok_start + 2),
        CC0_CH_NUL);
}

function cc0_tok_is_word_mks()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 3)
        return 0;
    return cc0_is_word_mks_chars(
        cc0_source_at(cc0_tok_start),
        cc0_source_at(cc0_tok_start + 1),
        cc0_source_at(cc0_tok_start + 2),
        CC0_CH_NUL);
}

function cc0_tok_is_word_while()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 5)
        return 0;
    return cc0_is_word_while_chars(
        cc0_source_at(cc0_tok_start),
        cc0_source_at(cc0_tok_start + 1),
        cc0_source_at(cc0_tok_start + 2),
        cc0_source_at(cc0_tok_start + 3),
        cc0_source_at(cc0_tok_start + 4),
        CC0_CH_NUL);
}
