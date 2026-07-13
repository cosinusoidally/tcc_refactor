/*
 * cc0 uses K&R-shaped functions so the same text is readable by C and JS.
 * C maps the two declaration words to int; JavaScript uses them directly.
 */
var CC0_FALSE = 0;
var CC0_TRUE = 1;

/* Named ASCII values keep character classification independent of literals. */
var CC0_ASCII_TAB = 9;
var CC0_ASCII_LINE_FEED = 10;
var CC0_ASCII_FORM_FEED = 12;
var CC0_ASCII_CARRIAGE_RETURN = 13;
var CC0_ASCII_SPACE = 32;
var CC0_ASCII_ZERO = 48;
var CC0_ASCII_NINE = 57;
var CC0_ASCII_UPPER_A = 65;
var CC0_ASCII_UPPER_Z = 90;
var CC0_ASCII_UNDERSCORE = 95;
var CC0_ASCII_LOWER_A = 97;
var CC0_ASCII_LOWER_Z = 122;

/* These primitives are the small host-semantic boundary for later cc0 code. */
function CC0_ADD(left, right)
{
    return left + right;
}

function CC0_SUB(left, right)
{
    return left - right;
}

function CC0_EQ(left, right)
{
    if (left == right)
        return CC0_TRUE;
    return CC0_FALSE;
}

function CC0_LT(left, right)
{
    if (left < right)
        return CC0_TRUE;
    return CC0_FALSE;
}

function CC0_LE(left, right)
{
    if (left <= right)
        return CC0_TRUE;
    return CC0_FALSE;
}

function CC0_NOT(value)
{
    if (value == CC0_FALSE)
        return CC0_TRUE;
    return CC0_FALSE;
}

function cc0_is_decimal_digit(value)
{
    if (CC0_LT(value, CC0_ASCII_ZERO))
        return CC0_FALSE;
    return CC0_LE(value, CC0_ASCII_NINE);
}

function cc0_is_uppercase(value)
{
    if (CC0_LT(value, CC0_ASCII_UPPER_A))
        return CC0_FALSE;
    return CC0_LE(value, CC0_ASCII_UPPER_Z);
}

function cc0_is_lowercase(value)
{
    if (CC0_LT(value, CC0_ASCII_LOWER_A))
        return CC0_FALSE;
    return CC0_LE(value, CC0_ASCII_LOWER_Z);
}

function cc0_is_name_start(value)
{
    if (cc0_is_uppercase(value))
        return CC0_TRUE;
    if (cc0_is_lowercase(value))
        return CC0_TRUE;
    return CC0_EQ(value, CC0_ASCII_UNDERSCORE);
}

function cc0_is_name_continue(value)
{
    if (cc0_is_name_start(value))
        return CC0_TRUE;
    return cc0_is_decimal_digit(value);
}

function cc0_is_horizontal_space(value)
{
    if (CC0_EQ(value, CC0_ASCII_SPACE))
        return CC0_TRUE;
    return CC0_EQ(value, CC0_ASCII_TAB);
}

function cc0_is_line_space(value)
{
    if (CC0_EQ(value, CC0_ASCII_LINE_FEED))
        return CC0_TRUE;
    if (CC0_EQ(value, CC0_ASCII_CARRIAGE_RETURN))
        return CC0_TRUE;
    return CC0_EQ(value, CC0_ASCII_FORM_FEED);
}

function cc0_is_space(value)
{
    if (cc0_is_horizontal_space(value))
        return CC0_TRUE;
    return cc0_is_line_space(value);
}
