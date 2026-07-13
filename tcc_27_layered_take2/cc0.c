/*
 * cc0 uses K&R-shaped functions so the same text is readable by C and JS.
 * C maps the two declaration words to int; JavaScript uses them directly.
 * Operators are primitive calls supplied by the current host. The cc0
 * compiler will also recognize these calls and emit their i386 operations,
 * which removes the host support from the eventual self-hosted path.
 */
var CC0_FALSE;
var CC0_TRUE;
var CC0_CHARACTER_EOF;
var CC0_BYTE_VALUE_COUNT;
var CC0_CHARACTER_SPACE_FLAG;
var CC0_TOKEN_HASH_INITIAL;
var CC0_TOKEN_HASH_LEFT_SHIFT;
var CC0_TOKEN_HASH_RIGHT_SHIFT;
var CC0_TOKEN_HASH_BUCKET_MASK;
var CC0_WORD_ADDRESS_SHIFT;
var CC0_WORD_BITS;
var CC0_NUMBER_WORD_COUNT;

/* Named ASCII values keep character classification independent of literals. */
var CC0_ASCII_TAB;
var CC0_ASCII_VERTICAL_TAB;
var CC0_ASCII_LINE_FEED;
var CC0_ASCII_FORM_FEED;
var CC0_ASCII_CARRIAGE_RETURN;
var CC0_ASCII_SPACE;
var CC0_ASCII_ZERO;
var CC0_ASCII_SEVEN;
var CC0_ASCII_NINE;
var CC0_ASCII_UPPER_A;
var CC0_ASCII_UPPER_Z;
var CC0_ASCII_UNDERSCORE;
var CC0_ASCII_LOWER_A;
var CC0_ASCII_LOWER_Z;

function cc0_init()
{
    CC0_FALSE = 0;
    CC0_TRUE = 1;
    CC0_CHARACTER_EOF = sub(0, 1);
    CC0_BYTE_VALUE_COUNT = 256;
    CC0_CHARACTER_SPACE_FLAG = 1;
    CC0_TOKEN_HASH_INITIAL = 1;
    CC0_TOKEN_HASH_LEFT_SHIFT = 5;
    CC0_TOKEN_HASH_RIGHT_SHIFT = 27;
    CC0_TOKEN_HASH_BUCKET_MASK = 16383;
    CC0_WORD_ADDRESS_SHIFT = 2;
    CC0_WORD_BITS = 32;
    CC0_NUMBER_WORD_COUNT = 2;
    CC0_ASCII_TAB = 9;
    CC0_ASCII_LINE_FEED = 10;
    CC0_ASCII_VERTICAL_TAB = 11;
    CC0_ASCII_FORM_FEED = 12;
    CC0_ASCII_CARRIAGE_RETURN = 13;
    CC0_ASCII_SPACE = 32;
    CC0_ASCII_ZERO = 48;
    CC0_ASCII_SEVEN = 55;
    CC0_ASCII_NINE = 57;
    CC0_ASCII_UPPER_A = 65;
    CC0_ASCII_UPPER_Z = 90;
    CC0_ASCII_UNDERSCORE = 95;
    CC0_ASCII_LOWER_A = 97;
    CC0_ASCII_LOWER_Z = 122;
    return CC0_FALSE;
}

function cc0_is_decimal_digit(value)
{
    if (lt(value, CC0_ASCII_ZERO)) {
        return CC0_FALSE;
    }
    return le(value, CC0_ASCII_NINE);
}

function cc0_is_octal_digit(value)
{
    if (lt(value, CC0_ASCII_ZERO)) {
        return CC0_FALSE;
    }
    return le(value, CC0_ASCII_SEVEN);
}

function cc0_is_uppercase(value)
{
    if (lt(value, CC0_ASCII_UPPER_A)) {
        return CC0_FALSE;
    }
    return le(value, CC0_ASCII_UPPER_Z);
}

function cc0_is_lowercase(value)
{
    if (lt(value, CC0_ASCII_LOWER_A)) {
        return CC0_FALSE;
    }
    return le(value, CC0_ASCII_LOWER_Z);
}

function cc0_is_name_start(value)
{
    if (cc0_is_uppercase(value)) {
        return CC0_TRUE;
    }
    if (cc0_is_lowercase(value)) {
        return CC0_TRUE;
    }
    return eq(value, CC0_ASCII_UNDERSCORE);
}

function cc0_is_name_continue(value)
{
    if (cc0_is_name_start(value)) {
        return CC0_TRUE;
    }
    return cc0_is_decimal_digit(value);
}

function cc0_is_horizontal_space(value)
{
    if (eq(value, CC0_ASCII_SPACE)) {
        return CC0_TRUE;
    }
    return eq(value, CC0_ASCII_TAB);
}

function cc0_is_line_space(value)
{
    if (eq(value, CC0_ASCII_LINE_FEED)) {
        return CC0_TRUE;
    }
    if (eq(value, CC0_ASCII_CARRIAGE_RETURN)) {
        return CC0_TRUE;
    }
    return eq(value, CC0_ASCII_FORM_FEED);
}

/* Match TCC's preprocessing-space class, which deliberately excludes LF. */
function cc0_is_space(value)
{
    if (cc0_is_horizontal_space(value)) {
        return CC0_TRUE;
    }
    if (eq(value, CC0_ASCII_VERTICAL_TAB)) {
        return CC0_TRUE;
    }
    if (eq(value, CC0_ASCII_FORM_FEED)) {
        return CC0_TRUE;
    }
    return eq(value, CC0_ASCII_CARRIAGE_RETURN);
}

function cc0_to_upper(value)
{
    if (cc0_is_lowercase(value)) {
        return add(sub(value, CC0_ASCII_LOWER_A), CC0_ASCII_UPPER_A);
    }
    return value;
}

/* The table starts at the EOF entry, followed by all byte values. */
function cc0_set_idnum_(table, character, flags, address, previous)
{
    address = add(table, sub(character, CC0_CHARACTER_EOF));
    previous = ri8(address);
    wi8(address, flags);
    return previous;
}

function cc0_set_idnum(table, character, flags)
{
    return cc0_set_idnum_(table, character, flags, 0, 0);
}

/* Preserve TCC's rule that a second adjacent space reports one token. */
function cc0_check_space_(table, token, space_pointer, address, flags)
{
    if (lt(token, CC0_BYTE_VALUE_COUNT)) {
        address = add(table, sub(token, CC0_CHARACTER_EOF));
        flags = ri8(address);
        if (and(flags, CC0_CHARACTER_SPACE_FLAG)) {
            if (ri32(space_pointer)) {
                return CC0_TRUE;
            }
            wi32(space_pointer, CC0_TRUE);
            return CC0_FALSE;
        }
    }
    wi32(space_pointer, CC0_FALSE);
    return CC0_FALSE;
}

function cc0_check_space(table, token, space_pointer)
{
    return cc0_check_space_(table, token, space_pointer, 0, 0);
}

/* This is TCC's identifier hash with explicit 32-bit wrapping primitives. */
function cc0_token_hash_(text, length, index, hash, character, left_part, right_part)
{
    index = 0;
    hash = CC0_TOKEN_HASH_INITIAL;
    while (lt(index, length)) {
        character = ri8(add(text, index));
        left_part = shl(hash, CC0_TOKEN_HASH_LEFT_SHIFT);
        right_part = ushr(hash, CC0_TOKEN_HASH_RIGHT_SHIFT);
        hash = add(hash, left_part);
        hash = add(hash, right_part);
        hash = add(hash, character);
        index = add(index, 1);
    }
    return and(hash, CC0_TOKEN_HASH_BUCKET_MASK);
}

function cc0_token_hash(text, length)
{
    return cc0_token_hash_(text, length, 0, 0, 0, 0, 0);
}

/* TCC accumulates hexadecimal and binary floating literals in two words. */
function cc0_number_zero_(number, index, address)
{
    index = 0;
    while (lt(index, CC0_NUMBER_WORD_COUNT)) {
        address = add(number, shl(index, CC0_WORD_ADDRESS_SHIFT));
        wi32(address, 0);
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_number_zero(number)
{
    return cc0_number_zero_(number, 0, 0);
}

function cc0_number_lshift_(number, shift, low_bits, index, address, value)
{
    index = 0;
    while (lt(index, CC0_NUMBER_WORD_COUNT)) {
        address = add(number, shl(index, CC0_WORD_ADDRESS_SHIFT));
        value = ri32(address);
        /* low_bits occupies positions cleared by the shift, so add acts as OR. */
        wi32(address, add(shl(value, shift), low_bits));
        low_bits = ushr(value, sub(CC0_WORD_BITS, shift));
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_number_lshift(number, shift, low_bits)
{
    return cc0_number_lshift_(number, shift, low_bits, 0, 0, 0);
}
