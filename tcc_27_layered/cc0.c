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

cc0_dialect_version = 1;
CC0_TOK_EOF = 0;
CC0_TOK_NAME = 1;
CC0_TOK_NUMBER = 2;
CC0_TOK_SPACE = 3;
CC0_TOK_PUNCT = 4;

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
