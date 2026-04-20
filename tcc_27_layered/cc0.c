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
