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
var CC0_ASCII_SLASH;
var CC0_ASCII_STAR;
var CC0_ASCII_BACKSLASH;
var CC0_ASCII_QUOTE;

/* Standalone compiler lexer state and its deliberately small token set. */
var CC0_SOURCE;
var CC0_SOURCE_LENGTH;
var CC0_SOURCE_POSITION;
var CC0_TOKEN;
var CC0_TOKEN_START;
var CC0_TOKEN_LENGTH;
var CC0_TOKEN_NUMBER;
var CC0_TOKEN_EOF;
var CC0_TOKEN_ERROR;
var CC0_TOKEN_IDENTIFIER;
var CC0_TOKEN_NUMBER_LITERAL;
var CC0_TOKEN_STRING_LITERAL;
var CC0_TOKEN_FUNCTION;
var CC0_TOKEN_VAR;
var CC0_TOKEN_RETURN;
var CC0_TOKEN_IF;
var CC0_TOKEN_ELSE;
var CC0_TOKEN_WHILE;
var CC0_TOKEN_BREAK;

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
    CC0_ASCII_SLASH = 47;
    CC0_ASCII_STAR = 42;
    CC0_ASCII_BACKSLASH = 92;
    CC0_ASCII_QUOTE = 34;
    CC0_TOKEN_EOF = 0;
    CC0_TOKEN_ERROR = 1;
    CC0_TOKEN_IDENTIFIER = 2;
    CC0_TOKEN_NUMBER_LITERAL = 3;
    CC0_TOKEN_STRING_LITERAL = 4;
    CC0_TOKEN_FUNCTION = 5;
    CC0_TOKEN_VAR = 6;
    CC0_TOKEN_RETURN = 7;
    CC0_TOKEN_IF = 8;
    CC0_TOKEN_ELSE = 9;
    CC0_TOKEN_WHILE = 10;
    CC0_TOKEN_BREAK = 11;
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

/* Scan a TCC identifier and retain the hash used by its symbol table. */
function cc0_scan_identifier_(table, text, continuation_mask, hash_pointer, position, hash, character, flags, left_part, right_part)
{
    position = text;
    hash = CC0_TOKEN_HASH_INITIAL;
    character = ri8(position);
    flags = ri8(add(table, sub(character, CC0_CHARACTER_EOF)));
    while (and(flags, continuation_mask)) {
        left_part = shl(hash, CC0_TOKEN_HASH_LEFT_SHIFT);
        right_part = ushr(hash, CC0_TOKEN_HASH_RIGHT_SHIFT);
        hash = add(hash, left_part);
        hash = add(hash, right_part);
        hash = add(hash, character);
        position = add(position, 1);
        character = ri8(position);
        flags = ri8(add(table, sub(character, CC0_CHARACTER_EOF)));
    }
    wi32(hash_pointer, and(hash, CC0_TOKEN_HASH_BUCKET_MASK));
    return position;
}

function cc0_scan_identifier(table, text, continuation_mask, hash_pointer)
{
    return cc0_scan_identifier_(table, text, continuation_mask, hash_pointer,
        0, 0, 0, 0, 0, 0);
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

function cc0_text_equal_(source, length, text, index, left, right)
{
    index = 0;
    while (lt(index, length)) {
        left = ri8(add(source, index));
        right = ri8(add(text, index));
        if (not(eq(left, right))) {
            return CC0_FALSE;
        }
        index = add(index, 1);
    }
    return eq(ri8(add(text, length)), 0);
}

function cc0_text_equal(source, length, text)
{
    return cc0_text_equal_(source, length, text, 0, 0, 0);
}

function cc0_compiler_set_source(source, length)
{
    CC0_SOURCE = source;
    CC0_SOURCE_LENGTH = length;
    CC0_SOURCE_POSITION = 0;
    CC0_TOKEN = CC0_TOKEN_EOF;
    CC0_TOKEN_START = source;
    CC0_TOKEN_LENGTH = 0;
    CC0_TOKEN_NUMBER = 0;
    return CC0_FALSE;
}

function cc0_compiler_skip_layout_(character, next_character, closed)
{
    while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        if (cc0_is_horizontal_space(character)) {
            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
        } else if (cc0_is_line_space(character)) {
            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
        } else if (eq(character, CC0_ASCII_VERTICAL_TAB)) {
            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
        } else if (eq(character, CC0_ASCII_SLASH)) {
            if (not(lt(add(CC0_SOURCE_POSITION, 1), CC0_SOURCE_LENGTH))) {
                return CC0_TRUE;
            }
            next_character = ri8(add(CC0_SOURCE, add(CC0_SOURCE_POSITION, 1)));
            if (eq(next_character, CC0_ASCII_SLASH)) {
                CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 2);
                while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
                    character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
                    if (eq(character, CC0_ASCII_LINE_FEED)) {
                        break;
                    }
                    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
                }
            } else if (eq(next_character, CC0_ASCII_STAR)) {
                CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 2);
                closed = CC0_FALSE;
                while (lt(add(CC0_SOURCE_POSITION, 1), CC0_SOURCE_LENGTH)) {
                    character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
                    next_character = ri8(add(CC0_SOURCE, add(CC0_SOURCE_POSITION, 1)));
                    if (eq(character, CC0_ASCII_STAR)) {
                        if (eq(next_character, CC0_ASCII_SLASH)) {
                            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 2);
                            closed = CC0_TRUE;
                            break;
                        }
                    }
                    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
                }
                if (not(closed)) {
                    CC0_TOKEN = CC0_TOKEN_ERROR;
                    return CC0_FALSE;
                }
            } else {
                return CC0_TRUE;
            }
        } else {
            return CC0_TRUE;
        }
    }
    return CC0_TRUE;
}

function cc0_compiler_skip_layout()
{
    return cc0_compiler_skip_layout_(0, 0, 0);
}

function cc0_compiler_keyword_(text, length)
{
    if (cc0_text_equal(text, length, mks("function"))) {
        return CC0_TOKEN_FUNCTION;
    }
    if (cc0_text_equal(text, length, mks("var"))) {
        return CC0_TOKEN_VAR;
    }
    if (cc0_text_equal(text, length, mks("return"))) {
        return CC0_TOKEN_RETURN;
    }
    if (cc0_text_equal(text, length, mks("if"))) {
        return CC0_TOKEN_IF;
    }
    if (cc0_text_equal(text, length, mks("else"))) {
        return CC0_TOKEN_ELSE;
    }
    if (cc0_text_equal(text, length, mks("while"))) {
        return CC0_TOKEN_WHILE;
    }
    if (cc0_text_equal(text, length, mks("break"))) {
        return CC0_TOKEN_BREAK;
    }
    return CC0_TOKEN_IDENTIFIER;
}

function cc0_compiler_scan_name_(character)
{
    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        if (not(cc0_is_name_continue(character))) {
            break;
        }
        CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    }
    CC0_TOKEN_LENGTH = sub(add(CC0_SOURCE, CC0_SOURCE_POSITION), CC0_TOKEN_START);
    CC0_TOKEN = cc0_compiler_keyword_(CC0_TOKEN_START, CC0_TOKEN_LENGTH);
    return CC0_TOKEN;
}

function cc0_compiler_scan_number_(character, digit)
{
    CC0_TOKEN_NUMBER = 0;
    while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        if (not(cc0_is_decimal_digit(character))) {
            break;
        }
        digit = sub(character, CC0_ASCII_ZERO);
        CC0_TOKEN_NUMBER = add(shl(CC0_TOKEN_NUMBER, 3),
            add(shl(CC0_TOKEN_NUMBER, 1), digit));
        CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    }
    CC0_TOKEN_LENGTH = sub(add(CC0_SOURCE, CC0_SOURCE_POSITION), CC0_TOKEN_START);
    CC0_TOKEN = CC0_TOKEN_NUMBER_LITERAL;
    return CC0_TOKEN;
}

function cc0_compiler_scan_string_(character, escaped)
{
    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    CC0_TOKEN_START = add(CC0_SOURCE, CC0_SOURCE_POSITION);
    escaped = CC0_FALSE;
    while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        if (escaped) {
            escaped = CC0_FALSE;
        } else if (eq(character, CC0_ASCII_BACKSLASH)) {
            escaped = CC0_TRUE;
        } else if (eq(character, CC0_ASCII_QUOTE)) {
            CC0_TOKEN_LENGTH = sub(add(CC0_SOURCE, CC0_SOURCE_POSITION), CC0_TOKEN_START);
            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
            CC0_TOKEN = CC0_TOKEN_STRING_LITERAL;
            return CC0_TOKEN;
        }
        CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    }
    CC0_TOKEN = CC0_TOKEN_ERROR;
    return CC0_TOKEN;
}

function cc0_compiler_next_token_(character)
{
    cc0_compiler_skip_layout();
    if (eq(CC0_TOKEN, CC0_TOKEN_ERROR)) {
        return CC0_TOKEN;
    }
    CC0_TOKEN_START = add(CC0_SOURCE, CC0_SOURCE_POSITION);
    CC0_TOKEN_LENGTH = 1;
    if (not(lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH))) {
        CC0_TOKEN_LENGTH = 0;
        CC0_TOKEN = CC0_TOKEN_EOF;
        return CC0_TOKEN;
    }
    character = ri8(CC0_TOKEN_START);
    if (cc0_is_name_start(character)) {
        return cc0_compiler_scan_name_(0);
    }
    if (cc0_is_decimal_digit(character)) {
        return cc0_compiler_scan_number_(0, 0);
    }
    if (eq(character, CC0_ASCII_QUOTE)) {
        return cc0_compiler_scan_string_(0, 0);
    }
    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    CC0_TOKEN = character;
    return CC0_TOKEN;
}

function cc0_compiler_next_token()
{
    return cc0_compiler_next_token_(0);
}
