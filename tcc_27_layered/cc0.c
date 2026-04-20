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
var cc0_src_0;
var cc0_src_1;
var cc0_src_2;
var cc0_src_3;
var cc0_src_4;
var cc0_src_5;
var cc0_src_6;
var cc0_src_7;
var cc0_scan_pos;
var cc0_tok_class;
var cc0_tok_start;
var cc0_tok_len;

cc0_dialect_version = 1;
CC0_TOK_EOF = 0;
CC0_TOK_NAME = 1;
CC0_TOK_NUMBER = 2;
CC0_TOK_SPACE = 3;
CC0_TOK_PUNCT = 4;
cc0_src_0 = -1;
cc0_src_1 = -1;
cc0_src_2 = -1;
cc0_src_3 = -1;
cc0_src_4 = -1;
cc0_src_5 = -1;
cc0_src_6 = -1;
cc0_src_7 = -1;
cc0_scan_pos = 0;
cc0_tok_class = 0;
cc0_tok_start = 0;
cc0_tok_len = 0;

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

function cc0_is_digit(c)
{
    if (c >= 48)
        if (c <= 57)
            return 1;
    return 0;
}

function cc0_is_upper(c)
{
    if (c >= 65)
        if (c <= 90)
            return 1;
    return 0;
}

function cc0_is_lower(c)
{
    if (c >= 97)
        if (c <= 122)
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

function cc0_is_name_start(c)
{
    if (cc0_is_alpha(c))
        return 1;
    if (c == 95)
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
    if (c == 32)
        return 1;
    if (c == 9)
        return 1;
    if (c == 10)
        return 1;
    if (c == 13)
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
    cc0_src_0 = c0;
    cc0_src_1 = c1;
    cc0_src_2 = c2;
    cc0_src_3 = c3;
    cc0_src_4 = c4;
    cc0_src_5 = c5;
    cc0_src_6 = c6;
    cc0_src_7 = c7;
    cc0_scan_pos = 0;
    cc0_tok_class = CC0_TOK_EOF;
    cc0_tok_start = 0;
    cc0_tok_len = 0;
    return 0;
}

function cc0_source_at(pos)
{
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
