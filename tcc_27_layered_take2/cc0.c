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
var CC0_WORD_BYTES;
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
var CC0_COMPILER_ERROR;
var CC0_PUNCTUATION_LEFT_PARENTHESIS;
var CC0_PUNCTUATION_RIGHT_PARENTHESIS;
var CC0_PUNCTUATION_LEFT_BRACE;
var CC0_PUNCTUATION_RIGHT_BRACE;
var CC0_PUNCTUATION_SEMICOLON;
var CC0_PUNCTUATION_COMMA;
var CC0_PUNCTUATION_ASSIGN;
var CC0_SYMBOL_ENTRY_ADDRESS_SHIFT;
var CC0_SYMBOL_CAPACITY;
var CC0_SYMBOL_TABLE_BYTES;
var CC0_SYMBOL_NAME_OFFSET;
var CC0_SYMBOL_LENGTH_OFFSET;
var CC0_SYMBOL_VALUE_OFFSET;
var CC0_SYMBOL_CODE_OFFSET;
var CC0_GLOBAL_SYMBOLS;
var CC0_GLOBAL_COUNT;
var CC0_FUNCTION_SYMBOLS;
var CC0_FUNCTION_COUNT;
var CC0_PARAMETER_SYMBOLS;
var CC0_PARAMETER_COUNT;
var CC0_CURRENT_NAME_START;
var CC0_CURRENT_NAME_LENGTH;
var CC0_COMPILER_PHASE;
var CC0_COMPILER_PHASE_COLLECT;
var CC0_COMPILER_PHASE_RESOLVE;
var CC0_CODE_CAPACITY;
var CC0_CODE;
var CC0_CODE_LENGTH;
var CC0_X86_PUSH_EBP;
var CC0_X86_MOV_REGISTER_OPCODE;
var CC0_X86_MOV_EBP_ESP;
var CC0_X86_PUSH_EBX;
var CC0_X86_LOAD_REGISTER_OPCODE;
var CC0_X86_LOAD_EBX_FROM_FRAME;
var CC0_X86_SAVED_EBX_DISPLACEMENT;
var CC0_X86_MOV_ESP_EBP;
var CC0_X86_POP_EBP;
var CC0_X86_RETURN;
var CC0_X86_MOV_EAX_IMMEDIATE;
var CC0_X86_PUSH_EAX;
var CC0_X86_POP_EBX;
var CC0_X86_LOAD_EAX_FROM_FRAME;
var CC0_X86_STORE_REGISTER_OPCODE;
var CC0_X86_STORE_EAX_TO_FRAME;
var CC0_X86_TEST_OPCODE;
var CC0_X86_TEST_EAX_EAX;
var CC0_X86_TWO_BYTE_OPCODE;
var CC0_X86_JUMP_IF_ZERO;
var CC0_X86_JUMP_RELATIVE;
var CC0_X86_CALL_RELATIVE;
var CC0_X86_ADD_IMMEDIATE_OPCODE;
var CC0_X86_ADD_ESP_IMMEDIATE;
var CC0_X86_MOV_ECX_EAX;
var CC0_X86_MOV_EAX_EBX;
var CC0_X86_ADD_REGISTER_OPCODE;
var CC0_X86_ADD_EAX_EBX;
var CC0_X86_SUB_REGISTER_OPCODE;
var CC0_X86_SUB_EAX_ECX;
var CC0_X86_AND_REGISTER_OPCODE;
var CC0_X86_AND_EAX_EBX;
var CC0_X86_SHIFT_BY_CL_OPCODE;
var CC0_X86_SHIFT_LEFT_EBX;
var CC0_X86_SHIFT_RIGHT_EBX;
var CC0_X86_COMPARE_OPCODE;
var CC0_X86_COMPARE_EBX_EAX;
var CC0_X86_SET_EQUAL;
var CC0_X86_SET_LESS;
var CC0_X86_SET_LESS_EQUAL;
var CC0_X86_SET_EAX_BYTE;
var CC0_X86_ZERO_EXTEND_OPCODE;
var CC0_X86_ZERO_EXTEND_EAX_BYTE;
var CC0_X86_LOAD_EAX_ADDRESS;
var CC0_X86_LOAD_EAX_BYTE_ADDRESS;
var CC0_X86_STORE_EAX_ADDRESS;
var CC0_X86_STORE_EAX_BYTE_ADDRESS_OPCODE;
var CC0_X86_STORE_EAX_BYTE_ADDRESS;

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
    CC0_WORD_BYTES = 4;
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
    CC0_COMPILER_ERROR = CC0_FALSE;
    CC0_PUNCTUATION_LEFT_PARENTHESIS = 40;
    CC0_PUNCTUATION_RIGHT_PARENTHESIS = 41;
    CC0_PUNCTUATION_LEFT_BRACE = 123;
    CC0_PUNCTUATION_RIGHT_BRACE = 125;
    CC0_PUNCTUATION_SEMICOLON = 59;
    CC0_PUNCTUATION_COMMA = 44;
    CC0_PUNCTUATION_ASSIGN = 61;
    CC0_SYMBOL_ENTRY_ADDRESS_SHIFT = 4;
    CC0_SYMBOL_CAPACITY = 1024;
    CC0_SYMBOL_TABLE_BYTES = 16384;
    CC0_SYMBOL_NAME_OFFSET = 0;
    CC0_SYMBOL_LENGTH_OFFSET = 4;
    CC0_SYMBOL_VALUE_OFFSET = 8;
    CC0_SYMBOL_CODE_OFFSET = 12;
    CC0_GLOBAL_SYMBOLS = 0;
    CC0_GLOBAL_COUNT = 0;
    CC0_FUNCTION_SYMBOLS = 0;
    CC0_FUNCTION_COUNT = 0;
    CC0_PARAMETER_SYMBOLS = 0;
    CC0_PARAMETER_COUNT = 0;
    CC0_CURRENT_NAME_START = 0;
    CC0_CURRENT_NAME_LENGTH = 0;
    CC0_COMPILER_PHASE_COLLECT = 0;
    CC0_COMPILER_PHASE_RESOLVE = 1;
    CC0_COMPILER_PHASE = CC0_COMPILER_PHASE_COLLECT;
    CC0_CODE_CAPACITY = 262144;
    CC0_CODE = 0;
    CC0_CODE_LENGTH = 0;
    CC0_X86_PUSH_EBP = 85;
    CC0_X86_MOV_REGISTER_OPCODE = 137;
    CC0_X86_MOV_EBP_ESP = 229;
    CC0_X86_PUSH_EBX = 83;
    CC0_X86_LOAD_REGISTER_OPCODE = 139;
    CC0_X86_LOAD_EBX_FROM_FRAME = 93;
    CC0_X86_SAVED_EBX_DISPLACEMENT = 252;
    CC0_X86_MOV_ESP_EBP = 236;
    CC0_X86_POP_EBP = 93;
    CC0_X86_RETURN = 195;
    CC0_X86_MOV_EAX_IMMEDIATE = 184;
    CC0_X86_PUSH_EAX = 80;
    CC0_X86_POP_EBX = 91;
    CC0_X86_LOAD_EAX_FROM_FRAME = 69;
    CC0_X86_STORE_REGISTER_OPCODE = 137;
    CC0_X86_STORE_EAX_TO_FRAME = 69;
    CC0_X86_TEST_OPCODE = 133;
    CC0_X86_TEST_EAX_EAX = 192;
    CC0_X86_TWO_BYTE_OPCODE = 15;
    CC0_X86_JUMP_IF_ZERO = 132;
    CC0_X86_JUMP_RELATIVE = 233;
    CC0_X86_CALL_RELATIVE = 232;
    CC0_X86_ADD_IMMEDIATE_OPCODE = 129;
    CC0_X86_ADD_ESP_IMMEDIATE = 196;
    CC0_X86_MOV_ECX_EAX = 193;
    CC0_X86_MOV_EAX_EBX = 216;
    CC0_X86_ADD_REGISTER_OPCODE = 1;
    CC0_X86_ADD_EAX_EBX = 216;
    CC0_X86_SUB_REGISTER_OPCODE = 41;
    CC0_X86_SUB_EAX_ECX = 200;
    CC0_X86_AND_REGISTER_OPCODE = 33;
    CC0_X86_AND_EAX_EBX = 216;
    CC0_X86_SHIFT_BY_CL_OPCODE = 211;
    CC0_X86_SHIFT_LEFT_EBX = 227;
    CC0_X86_SHIFT_RIGHT_EBX = 235;
    CC0_X86_COMPARE_OPCODE = 57;
    CC0_X86_COMPARE_EBX_EAX = 195;
    CC0_X86_SET_EQUAL = 148;
    CC0_X86_SET_LESS = 156;
    CC0_X86_SET_LESS_EQUAL = 158;
    CC0_X86_SET_EAX_BYTE = 192;
    CC0_X86_ZERO_EXTEND_OPCODE = 182;
    CC0_X86_ZERO_EXTEND_EAX_BYTE = 192;
    CC0_X86_LOAD_EAX_ADDRESS = 0;
    CC0_X86_LOAD_EAX_BYTE_ADDRESS = 0;
    CC0_X86_STORE_EAX_ADDRESS = 3;
    CC0_X86_STORE_EAX_BYTE_ADDRESS_OPCODE = 136;
    CC0_X86_STORE_EAX_BYTE_ADDRESS = 3;
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

function cc0_compiler_fail()
{
    CC0_COMPILER_ERROR = CC0_TRUE;
    return CC0_TRUE;
}

function cc0_compiler_symbol_entry(table, index)
{
    return add(table, shl(index, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT));
}

function cc0_compiler_slice_equal_(left, left_length, right, right_length, index)
{
    if (not(eq(left_length, right_length))) {
        return CC0_FALSE;
    }
    index = 0;
    while (lt(index, left_length)) {
        if (not(eq(ri8(add(left, index)), ri8(add(right, index))))) {
            return CC0_FALSE;
        }
        index = add(index, 1);
    }
    return CC0_TRUE;
}

function cc0_compiler_slice_equal(left, left_length, right, right_length)
{
    return cc0_compiler_slice_equal_(left, left_length, right, right_length, 0);
}

function cc0_compiler_find_symbol_(table, count, name, length, index, entry)
{
    index = 0;
    while (lt(index, count)) {
        entry = cc0_compiler_symbol_entry(table, index);
        if (cc0_compiler_slice_equal(
            ri32(add(entry, CC0_SYMBOL_NAME_OFFSET)),
            ri32(add(entry, CC0_SYMBOL_LENGTH_OFFSET)), name, length)) {
            return index;
        }
        index = add(index, 1);
    }
    return sub(0, 1);
}

function cc0_compiler_find_symbol(table, count, name, length)
{
    return cc0_compiler_find_symbol_(table, count, name, length, 0, 0);
}

function cc0_compiler_add_symbol_(table, count, name, length, value, entry)
{
    if (not(lt(count, CC0_SYMBOL_CAPACITY))) {
        return cc0_compiler_fail();
    }
    entry = cc0_compiler_symbol_entry(table, count);
    wi32(add(entry, CC0_SYMBOL_NAME_OFFSET), name);
    wi32(add(entry, CC0_SYMBOL_LENGTH_OFFSET), length);
    wi32(add(entry, CC0_SYMBOL_VALUE_OFFSET), value);
    wi32(add(entry, CC0_SYMBOL_CODE_OFFSET), 0);
    return CC0_FALSE;
}

function cc0_compiler_add_symbol(table, count, name, length, value)
{
    return cc0_compiler_add_symbol_(table, count, name, length, value, 0);
}

function cc0_compiler_prepare_symbols()
{
    if (eq(CC0_GLOBAL_SYMBOLS, 0)) {
        CC0_GLOBAL_SYMBOLS = alloc(CC0_SYMBOL_TABLE_BYTES);
        CC0_FUNCTION_SYMBOLS = alloc(CC0_SYMBOL_TABLE_BYTES);
        CC0_PARAMETER_SYMBOLS = alloc(CC0_SYMBOL_TABLE_BYTES);
    }
    CC0_GLOBAL_COUNT = 0;
    CC0_FUNCTION_COUNT = 0;
    CC0_PARAMETER_COUNT = 0;
    return CC0_FALSE;
}

function cc0_compiler_prepare_code()
{
    if (eq(CC0_CODE, 0)) {
        CC0_CODE = alloc(CC0_CODE_CAPACITY);
    }
    CC0_CODE_LENGTH = 0;
    if (eq(CC0_CODE, 0)) {
        return cc0_compiler_fail();
    }
    return CC0_FALSE;
}

function cc0_compiler_emit_byte(value)
{
    if (not(lt(CC0_CODE_LENGTH, CC0_CODE_CAPACITY))) {
        return cc0_compiler_fail();
    }
    wi8(add(CC0_CODE, CC0_CODE_LENGTH), value);
    CC0_CODE_LENGTH = add(CC0_CODE_LENGTH, 1);
    return CC0_FALSE;
}

function cc0_compiler_emit_word(value)
{
    if (not(le(add(CC0_CODE_LENGTH, CC0_WORD_BYTES),
        CC0_CODE_CAPACITY))) {
        return cc0_compiler_fail();
    }
    wi32(add(CC0_CODE, CC0_CODE_LENGTH), value);
    CC0_CODE_LENGTH = add(CC0_CODE_LENGTH, CC0_WORD_BYTES);
    return CC0_FALSE;
}

function cc0_compiler_patch_word(position, value)
{
    if (not(le(add(position, CC0_WORD_BYTES), CC0_CODE_LENGTH))) {
        return cc0_compiler_fail();
    }
    wi32(add(CC0_CODE, position), value);
    return CC0_FALSE;
}

function cc0_compiler_emit_prologue()
{
    cc0_compiler_emit_byte(CC0_X86_PUSH_EBP);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_EBP_ESP);
    cc0_compiler_emit_byte(CC0_X86_PUSH_EBX);
    return CC0_FALSE;
}

function cc0_compiler_emit_epilogue()
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_LOAD_EBX_FROM_FRAME);
    cc0_compiler_emit_byte(CC0_X86_SAVED_EBX_DISPLACEMENT);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ESP_EBP);
    cc0_compiler_emit_byte(CC0_X86_POP_EBP);
    cc0_compiler_emit_byte(CC0_X86_RETURN);
    return CC0_FALSE;
}

function cc0_compiler_emit_immediate(value)
{
    cc0_compiler_emit_byte(CC0_X86_MOV_EAX_IMMEDIATE);
    return cc0_compiler_emit_word(value);
}

function cc0_compiler_emit_push_result()
{
    return cc0_compiler_emit_byte(CC0_X86_PUSH_EAX);
}

function cc0_compiler_emit_pop_left_operand()
{
    return cc0_compiler_emit_byte(CC0_X86_POP_EBX);
}

function cc0_compiler_emit_load_parameter(offset)
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_LOAD_EAX_FROM_FRAME);
    return cc0_compiler_emit_byte(offset);
}

function cc0_compiler_emit_store_parameter(offset)
{
    cc0_compiler_emit_byte(CC0_X86_STORE_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_STORE_EAX_TO_FRAME);
    return cc0_compiler_emit_byte(offset);
}

function cc0_compiler_emit_test_result()
{
    cc0_compiler_emit_byte(CC0_X86_TEST_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_TEST_EAX_EAX);
}

function cc0_compiler_emit_zero_jump_(position)
{
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_JUMP_IF_ZERO);
    position = CC0_CODE_LENGTH;
    cc0_compiler_emit_word(0);
    return position;
}

function cc0_compiler_emit_zero_jump()
{
    return cc0_compiler_emit_zero_jump_(0);
}

function cc0_compiler_emit_jump_(position)
{
    cc0_compiler_emit_byte(CC0_X86_JUMP_RELATIVE);
    position = CC0_CODE_LENGTH;
    cc0_compiler_emit_word(0);
    return position;
}

function cc0_compiler_emit_jump()
{
    return cc0_compiler_emit_jump_(0);
}

function cc0_compiler_patch_relative(position, target)
{
    return cc0_compiler_patch_word(position,
        sub(target, add(position, CC0_WORD_BYTES)));
}

function cc0_compiler_emit_jump_to_(target, position)
{
    position = cc0_compiler_emit_jump();
    return cc0_compiler_patch_relative(position, target);
}

function cc0_compiler_emit_jump_to(target)
{
    return cc0_compiler_emit_jump_to_(target, 0);
}

function cc0_compiler_emit_call_placeholder_(position)
{
    cc0_compiler_emit_byte(CC0_X86_CALL_RELATIVE);
    position = CC0_CODE_LENGTH;
    cc0_compiler_emit_word(0);
    return position;
}

function cc0_compiler_emit_call_placeholder()
{
    return cc0_compiler_emit_call_placeholder_(0);
}

function cc0_compiler_emit_drop_arguments(argument_bytes)
{
    if (eq(argument_bytes, 0)) {
        return CC0_FALSE;
    }
    cc0_compiler_emit_byte(CC0_X86_ADD_IMMEDIATE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ADD_ESP_IMMEDIATE);
    return cc0_compiler_emit_word(argument_bytes);
}

function cc0_compiler_emit_compare(condition)
{
    cc0_compiler_emit_byte(CC0_X86_COMPARE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_COMPARE_EBX_EAX);
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(condition);
    cc0_compiler_emit_byte(CC0_X86_SET_EAX_BYTE);
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_EAX_BYTE);
}

function cc0_compiler_emit_not()
{
    cc0_compiler_emit_test_result();
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_SET_EQUAL);
    cc0_compiler_emit_byte(CC0_X86_SET_EAX_BYTE);
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_EAX_BYTE);
}

function cc0_compiler_emit_add()
{
    cc0_compiler_emit_byte(CC0_X86_ADD_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_ADD_EAX_EBX);
}

function cc0_compiler_emit_subtract()
{
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ECX_EAX);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_EAX_EBX);
    cc0_compiler_emit_byte(CC0_X86_SUB_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_SUB_EAX_ECX);
}

function cc0_compiler_emit_and()
{
    cc0_compiler_emit_byte(CC0_X86_AND_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_AND_EAX_EBX);
}

function cc0_compiler_emit_shift_left()
{
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ECX_EAX);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_BY_CL_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_LEFT_EBX);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_MOV_EAX_EBX);
}

function cc0_compiler_emit_shift_right()
{
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ECX_EAX);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_BY_CL_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_RIGHT_EBX);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_MOV_EAX_EBX);
}

function cc0_compiler_emit_read_word()
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_LOAD_EAX_ADDRESS);
}

function cc0_compiler_emit_read_byte()
{
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_LOAD_EAX_BYTE_ADDRESS);
}

function cc0_compiler_emit_write_word()
{
    cc0_compiler_emit_byte(CC0_X86_STORE_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_STORE_EAX_ADDRESS);
}

function cc0_compiler_emit_write_byte()
{
    cc0_compiler_emit_byte(CC0_X86_STORE_EAX_BYTE_ADDRESS_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_STORE_EAX_BYTE_ADDRESS);
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_EAX_BYTE);
}

function cc0_compiler_emit_builtin(name, length)
{
    if (cc0_text_equal(name, length, mks("not"))) {
        return cc0_compiler_emit_not();
    }
    if (cc0_text_equal(name, length, mks("ri8"))) {
        return cc0_compiler_emit_read_byte();
    }
    if (cc0_text_equal(name, length, mks("ri32"))) {
        return cc0_compiler_emit_read_word();
    }
    if (cc0_text_equal(name, length, mks("add"))) {
        return cc0_compiler_emit_add();
    }
    if (cc0_text_equal(name, length, mks("sub"))) {
        return cc0_compiler_emit_subtract();
    }
    if (cc0_text_equal(name, length, mks("eq"))) {
        return cc0_compiler_emit_compare(CC0_X86_SET_EQUAL);
    }
    if (cc0_text_equal(name, length, mks("lt"))) {
        return cc0_compiler_emit_compare(CC0_X86_SET_LESS);
    }
    if (cc0_text_equal(name, length, mks("le"))) {
        return cc0_compiler_emit_compare(CC0_X86_SET_LESS_EQUAL);
    }
    if (cc0_text_equal(name, length, mks("and"))) {
        return cc0_compiler_emit_and();
    }
    if (cc0_text_equal(name, length, mks("shl"))) {
        return cc0_compiler_emit_shift_left();
    }
    if (cc0_text_equal(name, length, mks("ushr"))) {
        return cc0_compiler_emit_shift_right();
    }
    if (cc0_text_equal(name, length, mks("wi8"))) {
        return cc0_compiler_emit_write_byte();
    }
    if (cc0_text_equal(name, length, mks("wi32"))) {
        return cc0_compiler_emit_write_word();
    }
    return cc0_compiler_fail();
}

function cc0_compiler_name_exists(name, length)
{
    if (not(lt(cc0_compiler_find_symbol(CC0_GLOBAL_SYMBOLS,
        CC0_GLOBAL_COUNT, name, length), 0))) {
        return CC0_TRUE;
    }
    return not(lt(cc0_compiler_find_symbol(CC0_FUNCTION_SYMBOLS,
        CC0_FUNCTION_COUNT, name, length), 0));
}

function cc0_compiler_variable_exists(name, length)
{
    if (not(lt(cc0_compiler_find_symbol(CC0_PARAMETER_SYMBOLS,
        CC0_PARAMETER_COUNT, name, length), 0))) {
        return CC0_TRUE;
    }
    return not(lt(cc0_compiler_find_symbol(CC0_GLOBAL_SYMBOLS,
        CC0_GLOBAL_COUNT, name, length), 0));
}

function cc0_compiler_builtin_arity(name, length)
{
    if (cc0_text_equal(name, length, mks("not"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("mks"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("alloc"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("ri8"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("ri32"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("add"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("sub"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("eq"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("lt"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("le"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("and"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("shl"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("ushr"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("wi8"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("wi32"))) {
        return 2;
    }
    return sub(0, 1);
}

function cc0_compiler_function_arity_(name, length, index, entry)
{
    index = cc0_compiler_find_symbol(CC0_FUNCTION_SYMBOLS,
        CC0_FUNCTION_COUNT, name, length);
    if (lt(index, 0)) {
        return cc0_compiler_builtin_arity(name, length);
    }
    entry = cc0_compiler_symbol_entry(CC0_FUNCTION_SYMBOLS, index);
    return ri32(add(entry, CC0_SYMBOL_VALUE_OFFSET));
}

function cc0_compiler_function_arity(name, length)
{
    return cc0_compiler_function_arity_(name, length, 0, 0);
}

function cc0_compiler_expect(token)
{
    if (not(eq(CC0_TOKEN, token))) {
        return cc0_compiler_fail();
    }
    cc0_compiler_next_token();
    return CC0_FALSE;
}

function cc0_compiler_parse_call_(name, length, argument_count, arity)
{
    cc0_compiler_next_token();
    argument_count = 0;
    if (not(eq(CC0_TOKEN, CC0_PUNCTUATION_RIGHT_PARENTHESIS))) {
        while (CC0_TRUE) {
            if (cc0_compiler_parse_expression()) {
                return CC0_TRUE;
            }
            argument_count = add(argument_count, 1);
            if (not(eq(CC0_TOKEN, CC0_PUNCTUATION_COMMA))) {
                break;
            }
            cc0_compiler_next_token();
        }
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_RESOLVE)) {
        arity = cc0_compiler_function_arity(name, length);
        if (lt(arity, 0)) {
            return cc0_compiler_fail();
        }
        if (not(eq(arity, argument_count))) {
            return cc0_compiler_fail();
        }
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_expression_(name, length)
{
    if (eq(CC0_TOKEN, CC0_TOKEN_NUMBER_LITERAL)) {
        cc0_compiler_next_token();
        return CC0_FALSE;
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_STRING_LITERAL)) {
        cc0_compiler_next_token();
        return CC0_FALSE;
    }
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        cc0_compiler_next_token();
        cc0_compiler_parse_expression_(0, 0);
        return cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS);
    }
    if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
        return cc0_compiler_fail();
    }
    name = CC0_TOKEN_START;
    length = CC0_TOKEN_LENGTH;
    cc0_compiler_next_token();
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_ASSIGN)) {
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_RESOLVE)) {
            if (not(cc0_compiler_variable_exists(name, length))) {
                return cc0_compiler_fail();
            }
        }
        cc0_compiler_next_token();
        return cc0_compiler_parse_expression_(0, 0);
    }
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        return cc0_compiler_parse_call_(name, length, 0, 0);
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_RESOLVE)) {
        if (not(cc0_compiler_variable_exists(name, length))) {
            return cc0_compiler_fail();
        }
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_expression()
{
    if (CC0_COMPILER_ERROR) {
        return CC0_TRUE;
    }
    return cc0_compiler_parse_expression_(0, 0);
}

function cc0_compiler_parse_block_()
{
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_BRACE)) {
        return CC0_TRUE;
    }
    while (not(eq(CC0_TOKEN, CC0_PUNCTUATION_RIGHT_BRACE))) {
        if (eq(CC0_TOKEN, CC0_TOKEN_EOF)) {
            return cc0_compiler_fail();
        }
        if (cc0_compiler_parse_statement()) {
            return CC0_TRUE;
        }
    }
    return cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_BRACE);
}

function cc0_compiler_parse_if_()
{
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_parse_statement()) {
        return CC0_TRUE;
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_ELSE)) {
        cc0_compiler_next_token();
        return cc0_compiler_parse_statement();
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_while_()
{
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    return cc0_compiler_parse_statement();
}

function cc0_compiler_parse_statement()
{
    if (CC0_COMPILER_ERROR) {
        return CC0_TRUE;
    }
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_LEFT_BRACE)) {
        return cc0_compiler_parse_block_();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_RETURN)) {
        cc0_compiler_next_token();
        if (cc0_compiler_parse_expression()) {
            return CC0_TRUE;
        }
        return cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON);
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_IF)) {
        return cc0_compiler_parse_if_();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_WHILE)) {
        return cc0_compiler_parse_while_();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_BREAK)) {
        cc0_compiler_next_token();
        return cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON);
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    return cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON);
}

function cc0_compiler_parse_parameters_()
{
    CC0_PARAMETER_COUNT = 0;
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_FALSE;
    }
    while (CC0_TRUE) {
        if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
            return cc0_compiler_fail();
        }
        if (not(lt(cc0_compiler_find_symbol(CC0_PARAMETER_SYMBOLS,
            CC0_PARAMETER_COUNT, CC0_TOKEN_START, CC0_TOKEN_LENGTH), 0))) {
            return cc0_compiler_fail();
        }
        cc0_compiler_add_symbol(CC0_PARAMETER_SYMBOLS, CC0_PARAMETER_COUNT,
            CC0_TOKEN_START, CC0_TOKEN_LENGTH, CC0_PARAMETER_COUNT);
        CC0_PARAMETER_COUNT = add(CC0_PARAMETER_COUNT, 1);
        cc0_compiler_next_token();
        if (not(eq(CC0_TOKEN, CC0_PUNCTUATION_COMMA))) {
            return CC0_FALSE;
        }
        cc0_compiler_next_token();
    }
}

function cc0_compiler_parse_function_()
{
    cc0_compiler_next_token();
    if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
        return cc0_compiler_fail();
    }
    CC0_CURRENT_NAME_START = CC0_TOKEN_START;
    CC0_CURRENT_NAME_LENGTH = CC0_TOKEN_LENGTH;
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT)) {
        if (cc0_compiler_name_exists(CC0_CURRENT_NAME_START,
            CC0_CURRENT_NAME_LENGTH)) {
            return cc0_compiler_fail();
        }
    }
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_parse_parameters_()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT)) {
        if (cc0_compiler_add_symbol(CC0_FUNCTION_SYMBOLS, CC0_FUNCTION_COUNT,
            CC0_CURRENT_NAME_START, CC0_CURRENT_NAME_LENGTH,
            CC0_PARAMETER_COUNT)) {
            return CC0_TRUE;
        }
        CC0_FUNCTION_COUNT = add(CC0_FUNCTION_COUNT, 1);
    } else if (not(eq(cc0_compiler_function_arity(CC0_CURRENT_NAME_START,
        CC0_CURRENT_NAME_LENGTH), CC0_PARAMETER_COUNT))) {
        return cc0_compiler_fail();
    }
    return cc0_compiler_parse_block_();
}

function cc0_compiler_parse_global_()
{
    cc0_compiler_next_token();
    if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
        return cc0_compiler_fail();
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT)) {
        if (cc0_compiler_name_exists(CC0_TOKEN_START, CC0_TOKEN_LENGTH)) {
            return cc0_compiler_fail();
        }
        cc0_compiler_add_symbol(CC0_GLOBAL_SYMBOLS, CC0_GLOBAL_COUNT,
            CC0_TOKEN_START, CC0_TOKEN_LENGTH, CC0_GLOBAL_COUNT);
        CC0_GLOBAL_COUNT = add(CC0_GLOBAL_COUNT, 1);
    }
    cc0_compiler_next_token();
    return cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON);
}

function cc0_compiler_parse_program_(source, length, phase)
{
    CC0_COMPILER_ERROR = CC0_FALSE;
    CC0_COMPILER_PHASE = phase;
    cc0_compiler_set_source(source, length);
    cc0_compiler_next_token();
    while (not(eq(CC0_TOKEN, CC0_TOKEN_EOF))) {
        if (eq(CC0_TOKEN, CC0_TOKEN_VAR)) {
            cc0_compiler_parse_global_();
        } else if (eq(CC0_TOKEN, CC0_TOKEN_FUNCTION)) {
            cc0_compiler_parse_function_();
        } else {
            return cc0_compiler_fail();
        }
        if (CC0_COMPILER_ERROR) {
            return CC0_TRUE;
        }
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_program(source, length)
{
    cc0_compiler_prepare_symbols();
    if (cc0_compiler_parse_program_(source, length,
        CC0_COMPILER_PHASE_COLLECT)) {
        return CC0_TRUE;
    }
    return cc0_compiler_parse_program_(source, length,
        CC0_COMPILER_PHASE_RESOLVE);
}
