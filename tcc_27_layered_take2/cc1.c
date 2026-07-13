/*
 * Layer one currently supplies the TCC-backed link service. The reduced linker
 * will migrate here from tccelf.c while cc0 remains unchanged.
 */
var CC1_TOKEN_RECORD_SHIFT;
var CC1_TOKEN_KIND_OFFSET;
var CC1_TOKEN_TEXT_OFFSET;
var CC1_TOKEN_LENGTH_OFFSET;
var CC1_TOKEN_NUMBER_OFFSET;
var CC1_TOKEN_SOURCE_OFFSET;
var CC1_TOKEN_FILE_OFFSET;
var CC1_TOKEN_LINE_OFFSET;
var CC1_TOKEN_COLUMN_OFFSET;
var CC1_LEXER_FIELD_KIND;
var CC1_LEXER_FIELD_TEXT;
var CC1_LEXER_FIELD_LENGTH;
var CC1_LEXER_FIELD_NUMBER;
var CC1_TOKEN_EOF;
var CC1_TOKEN_ERROR;
var CC1_TOKEN_SOURCE;
var CC1_TOKEN_SOURCE_LENGTH;
var CC1_TOKEN_FILE;
var CC1_TOKEN_RECORDS;
var CC1_TOKEN_CAPACITY;
var CC1_TOKEN_COUNT;
var CC1_TOKEN_CURSOR;
var CC1_LOCATION_OFFSET;
var CC1_LOCATION_LINE;
var CC1_LOCATION_COLUMN;
var CC1_MACRO_RECORD_SHIFT;
var CC1_MACRO_NAME_OFFSET;
var CC1_MACRO_LENGTH_OFFSET;
var CC1_MACRO_FIRST_TOKEN_OFFSET;
var CC1_MACRO_TOKEN_COUNT_OFFSET;
var CC1_MACRO_DEFINED_OFFSET;
var CC1_MACRO_EXPANDING_OFFSET;
var CC1_MACRO_PARAMETER_FIRST_OFFSET;
var CC1_MACRO_PARAMETER_COUNT_OFFSET;
var CC1_MACROS;
var CC1_MACRO_CAPACITY;
var CC1_MACRO_COUNT;
var CC1_PREPROCESSED_TOKENS;
var CC1_PREPROCESSED_CAPACITY;
var CC1_PREPROCESSED_COUNT;
var CC1_PREPROCESSED_CURSOR;
var CC1_CONDITION_RECORD_SHIFT;
var CC1_CONDITION_PARENT_OFFSET;
var CC1_CONDITION_ACTIVE_OFFSET;
var CC1_CONDITION_TAKEN_OFFSET;
var CC1_CONDITIONS;
var CC1_CONDITION_CAPACITY;
var CC1_CONDITION_DEPTH;
var CC1_TYPE_RECORD_SHIFT;
var CC1_TYPE_KIND_OFFSET;
var CC1_TYPE_SIZE_OFFSET;
var CC1_TYPE_ALIGNMENT_OFFSET;
var CC1_TYPE_FLAGS_OFFSET;
var CC1_TYPE_BASE_OFFSET;
var CC1_TYPE_COUNT_OFFSET;
var CC1_TYPE_VOID_KIND;
var CC1_TYPE_CHAR_KIND;
var CC1_TYPE_SHORT_KIND;
var CC1_TYPE_INT_KIND;
var CC1_TYPE_POINTER_KIND;
var CC1_TYPE_ARRAY_KIND;
var CC1_TYPE_FUNCTION_KIND;
var CC1_TYPE_UNSIGNED_FLAG;
var CC1_TYPES;
var CC1_TYPE_CAPACITY;
var CC1_TYPE_COUNT;
var CC1_VOID_TYPE;
var CC1_CHAR_TYPE;
var CC1_UNSIGNED_CHAR_TYPE;
var CC1_SHORT_TYPE;
var CC1_UNSIGNED_SHORT_TYPE;
var CC1_INT_TYPE;
var CC1_UNSIGNED_INT_TYPE;
var CC1_SYMBOL_RECORD_SHIFT;
var CC1_SYMBOL_NAME_OFFSET;
var CC1_SYMBOL_LENGTH_OFFSET;
var CC1_SYMBOL_TYPE_OFFSET;
var CC1_SYMBOL_STORAGE_OFFSET;
var CC1_SYMBOL_DEPTH_OFFSET;
var CC1_SYMBOLS;
var CC1_SYMBOL_CAPACITY;
var CC1_SYMBOL_COUNT;
var CC1_SCOPE_MARKERS;
var CC1_SCOPE_CAPACITY;
var CC1_SCOPE_DEPTH;
var CC1_NORMALIZED_SOURCE;
var CC1_NORMALIZED_CAPACITY;
var CC1_NORMALIZED_LENGTH;
var CC1_NORMALIZED_ORIGINS;
var CC1_NORMALIZED_FILES;
var CC1_NORMALIZED_LINES;
var CC1_NORMALIZED_COLUMNS;
var CC1_NORMALIZED_CURRENT_FILE;
var CC1_NORMALIZED_CURRENT_LINE;
var CC1_NORMALIZED_CURRENT_COLUMN;
var CC1_EXPANDED_SOURCE;
var CC1_EXPANDED_FILES;
var CC1_EXPANDED_OFFSETS;
var CC1_EXPANDED_LINES;
var CC1_EXPANDED_COLUMNS;
var CC1_EXPANDED_CAPACITY;
var CC1_EXPANDED_LENGTH;
var CC1_EXPANSION_ACTIVE;
var CC1_ASCII_TAB;
var CC1_ASCII_LINE_FEED;
var CC1_ASCII_CARRIAGE_RETURN;
var CC1_ASCII_SPACE;
var CC1_ASCII_QUOTE;
var CC1_ASCII_HASH;
var CC1_ASCII_SLASH;
var CC1_EXPRESSION_RECORD_SHIFT;
var CC1_EXPRESSION_KIND_OFFSET;
var CC1_EXPRESSION_TOKEN_OFFSET;
var CC1_EXPRESSION_LEFT_OFFSET;
var CC1_EXPRESSION_RIGHT_OFFSET;
var CC1_EXPRESSION_ATOM_KIND;
var CC1_EXPRESSION_CALL_KIND;
var CC1_EXPRESSION_ARGUMENT_KIND;
var CC1_EXPRESSION_ADD_KIND;
var CC1_EXPRESSION_SUBTRACT_KIND;
var CC1_EXPRESSION_EQUAL_KIND;
var CC1_EXPRESSION_LESS_KIND;
var CC1_EXPRESSION_LESS_EQUAL_KIND;
var CC1_EXPRESSION_NOT_KIND;
var CC1_EXPRESSION_NEGATE_KIND;
var CC1_EXPRESSION_MULTIPLY_KIND;
var CC1_EXPRESSION_DIVIDE_KIND;
var CC1_EXPRESSION_REMAINDER_KIND;
var CC1_EXPRESSION_SHIFT_LEFT_KIND;
var CC1_EXPRESSION_SHIFT_RIGHT_KIND;
var CC1_EXPRESSION_BIT_AND_KIND;
var CC1_EXPRESSION_BIT_XOR_KIND;
var CC1_EXPRESSION_BIT_OR_KIND;
var CC1_EXPRESSION_COMPLEMENT_KIND;
var CC1_EXPRESSION_DEREFERENCE_KIND;
var CC1_EXPRESSION_ADDRESS_KIND;
var CC1_EXPRESSION_ASSIGN_KIND;
var CC1_EXPRESSION_LOGICAL_AND_KIND;
var CC1_EXPRESSION_LOGICAL_OR_KIND;
var CC1_EXPRESSION_CONDITIONAL_KIND;
var CC1_EXPRESSION_CONSTANT_KIND;
var CC1_EXPRESSION_COMMA_KIND;
var CC1_EXPRESSIONS;
var CC1_EXPRESSION_CAPACITY;
var CC1_EXPRESSION_COUNT;
var CC1_EXPRESSION_ERROR;

function cc1_token_record(index)
{
    return add(CC1_TOKEN_RECORDS, shl(index, CC1_TOKEN_RECORD_SHIFT));
}

function cc1_token_copy_bytes_(destination, source, count, index)
{
    index = 0;
    while (lt(index, count)) {
        wi8(add(destination, index), ri8(add(source, index)));
        index = add(index, 1);
    }
    return destination;
}

function cc1_token_copy_bytes(destination, source, count)
{
    return cc1_token_copy_bytes_(destination, source, count, 0);
}

function cc1_token_reserve_(needed, capacity, records, used)
{
    needed = shl(add(CC1_TOKEN_COUNT, 1), CC1_TOKEN_RECORD_SHIFT);
    if (le(needed, CC1_TOKEN_CAPACITY)) {
        return 0;
    }
    capacity = CC1_TOKEN_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    records = malloc(capacity);
    if (eq(records, 0)) {
        return 1;
    }
    used = shl(CC1_TOKEN_COUNT, CC1_TOKEN_RECORD_SHIFT);
    if (not(eq(CC1_TOKEN_RECORDS, 0))) {
        cc1_token_copy_bytes(records, CC1_TOKEN_RECORDS, used);
    }
    CC1_TOKEN_RECORDS = records;
    CC1_TOKEN_CAPACITY = capacity;
    return 0;
}

function cc1_token_reserve()
{
    return cc1_token_reserve_(0, 0, 0, 0);
}

function cc1_token_update_location_(source_offset, character)
{
    while (lt(CC1_LOCATION_OFFSET, source_offset)) {
        character = ri8(add(CC1_TOKEN_SOURCE, CC1_LOCATION_OFFSET));
        if (eq(character, 10)) {
            CC1_LOCATION_LINE = add(CC1_LOCATION_LINE, 1);
            CC1_LOCATION_COLUMN = 1;
        } else {
            CC1_LOCATION_COLUMN = add(CC1_LOCATION_COLUMN, 1);
        }
        CC1_LOCATION_OFFSET = add(CC1_LOCATION_OFFSET, 1);
    }
    return 0;
}

function cc1_token_update_location(source_offset)
{
    return cc1_token_update_location_(source_offset, 0);
}

function cc1_token_append_(kind, text, length, number, source_offset, record)
{
    if (cc1_token_reserve()) {
        return 1;
    }
    source_offset = sub(text, CC1_TOKEN_SOURCE);
    cc1_token_update_location(source_offset);
    record = cc1_token_record(CC1_TOKEN_COUNT);
    wi32(add(record, CC1_TOKEN_KIND_OFFSET), kind);
    wi32(add(record, CC1_TOKEN_TEXT_OFFSET), text);
    wi32(add(record, CC1_TOKEN_LENGTH_OFFSET), length);
    wi32(add(record, CC1_TOKEN_NUMBER_OFFSET), number);
    if (CC1_EXPANSION_ACTIVE) {
        if (not(lt(source_offset, CC1_EXPANDED_LENGTH))) {
            wi32(add(record, CC1_TOKEN_SOURCE_OFFSET),
                CC1_TOKEN_SOURCE_LENGTH);
            wi32(add(record, CC1_TOKEN_FILE_OFFSET), CC1_TOKEN_FILE);
            wi32(add(record, CC1_TOKEN_LINE_OFFSET), CC1_LOCATION_LINE);
            wi32(add(record, CC1_TOKEN_COLUMN_OFFSET), CC1_LOCATION_COLUMN);
        } else {
        wi32(add(record, CC1_TOKEN_SOURCE_OFFSET), ri32(add(
            CC1_EXPANDED_OFFSETS, shl(source_offset, 2))));
        wi32(add(record, CC1_TOKEN_FILE_OFFSET), ri32(add(
            CC1_EXPANDED_FILES, shl(source_offset, 2))));
        wi32(add(record, CC1_TOKEN_LINE_OFFSET), ri32(add(
            CC1_EXPANDED_LINES, shl(source_offset, 2))));
        wi32(add(record, CC1_TOKEN_COLUMN_OFFSET), ri32(add(
            CC1_EXPANDED_COLUMNS, shl(source_offset, 2))));
        }
    } else {
        wi32(add(record, CC1_TOKEN_SOURCE_OFFSET), source_offset);
        wi32(add(record, CC1_TOKEN_FILE_OFFSET), CC1_TOKEN_FILE);
        wi32(add(record, CC1_TOKEN_LINE_OFFSET), CC1_LOCATION_LINE);
        wi32(add(record, CC1_TOKEN_COLUMN_OFFSET), CC1_LOCATION_COLUMN);
    }
    CC1_TOKEN_COUNT = add(CC1_TOKEN_COUNT, 1);
    return 0;
}

function cc1_token_append(kind, text, length, number)
{
    return cc1_token_append_(kind, text, length, number, 0, 0);
}

function cc1_token_stream_reset(source, length, file)
{
    CC1_TOKEN_RECORD_SHIFT = 5;
    CC1_TOKEN_KIND_OFFSET = 0;
    CC1_TOKEN_TEXT_OFFSET = 4;
    CC1_TOKEN_LENGTH_OFFSET = 8;
    CC1_TOKEN_NUMBER_OFFSET = 12;
    CC1_TOKEN_SOURCE_OFFSET = 16;
    CC1_TOKEN_FILE_OFFSET = 20;
    CC1_TOKEN_LINE_OFFSET = 24;
    CC1_TOKEN_COLUMN_OFFSET = 28;
    CC1_LEXER_FIELD_KIND = 0;
    CC1_LEXER_FIELD_TEXT = 1;
    CC1_LEXER_FIELD_LENGTH = 2;
    CC1_LEXER_FIELD_NUMBER = 3;
    CC1_TOKEN_EOF = 0;
    CC1_TOKEN_ERROR = 1;
    CC1_MACRO_RECORD_SHIFT = 5;
    CC1_MACRO_NAME_OFFSET = 0;
    CC1_MACRO_LENGTH_OFFSET = 4;
    CC1_MACRO_FIRST_TOKEN_OFFSET = 8;
    CC1_MACRO_TOKEN_COUNT_OFFSET = 12;
    CC1_MACRO_DEFINED_OFFSET = 16;
    CC1_MACRO_EXPANDING_OFFSET = 20;
    CC1_MACRO_PARAMETER_FIRST_OFFSET = 24;
    CC1_MACRO_PARAMETER_COUNT_OFFSET = 28;
    CC1_CONDITION_RECORD_SHIFT = 4;
    CC1_CONDITION_PARENT_OFFSET = 0;
    CC1_CONDITION_ACTIVE_OFFSET = 4;
    CC1_CONDITION_TAKEN_OFFSET = 8;
    CC1_TOKEN_SOURCE = source;
    CC1_TOKEN_SOURCE_LENGTH = length;
    CC1_TOKEN_FILE = file;
    CC1_TOKEN_COUNT = 0;
    CC1_TOKEN_CURSOR = 0;
    CC1_LOCATION_OFFSET = 0;
    CC1_LOCATION_LINE = 1;
    CC1_LOCATION_COLUMN = 1;
    return 0;
}

function cc1_tokenize_(source, length, file, kind, text, token_length,
    number)
{
    cc1_token_stream_reset(source, length, file);
    cc0_lexer_start(source, length);
    while (1) {
        kind = cc0_lexer_field(CC1_LEXER_FIELD_KIND);
        text = cc0_lexer_field(CC1_LEXER_FIELD_TEXT);
        token_length = cc0_lexer_field(CC1_LEXER_FIELD_LENGTH);
        number = cc0_lexer_field(CC1_LEXER_FIELD_NUMBER);
        if (cc1_token_append(kind, text, token_length, number)) {
            return 1;
        }
        if (eq(kind, CC1_TOKEN_ERROR)) {
            return 1;
        }
        if (eq(kind, CC1_TOKEN_EOF)) {
            return 0;
        }
        cc0_lexer_advance();
    }
}

function cc1_tokenize(source, length, file)
{
    return cc1_tokenize_(source, length, file, 0, 0, 0, 0);
}

function cc1_token_peek_(distance, index)
{
    if (lt(distance, 0)) {
        return 0;
    }
    index = add(CC1_TOKEN_CURSOR, distance);
    if (not(lt(index, CC1_TOKEN_COUNT))) {
        return 0;
    }
    return cc1_token_record(index);
}

function cc1_token_peek(distance)
{
    return cc1_token_peek_(distance, 0);
}

function cc1_token_consume_(token)
{
    token = cc1_token_peek(0);
    if (not(eq(token, 0))) {
        CC1_TOKEN_CURSOR = add(CC1_TOKEN_CURSOR, 1);
    }
    return token;
}

function cc1_token_consume()
{
    return cc1_token_consume_(0);
}

function cc1_text_equal_(left, left_length, right, index)
{
    index = 0;
    while (lt(index, left_length)) {
        if (not(eq(ri8(add(left, index)), ri8(add(right, index))))) {
            return 0;
        }
        index = add(index, 1);
    }
    return eq(ri8(add(right, left_length)), 0);
}

function cc1_text_equal(left, left_length, right)
{
    return cc1_text_equal_(left, left_length, right, 0);
}

function cc1_slice_equal_(left, right, length, index)
{
    index = 0;
    while (lt(index, length)) {
        if (not(eq(ri8(add(left, index)), ri8(add(right, index))))) {
            return 0;
        }
        index = add(index, 1);
    }
    return 1;
}

function cc1_slice_equal(left, right, length)
{
    return cc1_slice_equal_(left, right, length, 0);
}

function cc1_macro_record(index)
{
    return add(CC1_MACROS, shl(index, CC1_MACRO_RECORD_SHIFT));
}

function cc1_macro_reserve_(needed, capacity, macros, used)
{
    needed = shl(add(CC1_MACRO_COUNT, 1), CC1_MACRO_RECORD_SHIFT);
    if (le(needed, CC1_MACRO_CAPACITY)) {
        return 0;
    }
    capacity = CC1_MACRO_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    macros = malloc(capacity);
    if (eq(macros, 0)) {
        return 1;
    }
    used = shl(CC1_MACRO_COUNT, CC1_MACRO_RECORD_SHIFT);
    if (not(eq(CC1_MACROS, 0))) {
        cc1_token_copy_bytes(macros, CC1_MACROS, used);
    }
    CC1_MACROS = macros;
    CC1_MACRO_CAPACITY = capacity;
    return 0;
}

function cc1_macro_reserve()
{
    return cc1_macro_reserve_(0, 0, 0, 0);
}

function cc1_macro_find_(name, length, index, macro)
{
    index = 0;
    while (lt(index, CC1_MACRO_COUNT)) {
        macro = cc1_macro_record(index);
        if (eq(ri32(add(macro, CC1_MACRO_LENGTH_OFFSET)), length)) {
            if (cc1_slice_equal(name,
                ri32(add(macro, CC1_MACRO_NAME_OFFSET)), length)) {
                return macro;
            }
        }
        index = add(index, 1);
    }
    return 0;
}

function cc1_macro_find(name, length)
{
    return cc1_macro_find_(name, length, 0, 0);
}

function cc1_macro_define_(name, length, first_token, token_count,
    parameter_first, parameter_count, macro)
{
    macro = cc1_macro_find(name, length);
    if (eq(macro, 0)) {
        if (cc1_macro_reserve()) {
            return 1;
        }
        macro = cc1_macro_record(CC1_MACRO_COUNT);
        CC1_MACRO_COUNT = add(CC1_MACRO_COUNT, 1);
        wi32(add(macro, CC1_MACRO_NAME_OFFSET), name);
        wi32(add(macro, CC1_MACRO_LENGTH_OFFSET), length);
    }
    wi32(add(macro, CC1_MACRO_FIRST_TOKEN_OFFSET), first_token);
    wi32(add(macro, CC1_MACRO_TOKEN_COUNT_OFFSET), token_count);
    wi32(add(macro, CC1_MACRO_DEFINED_OFFSET), 1);
    wi32(add(macro, CC1_MACRO_EXPANDING_OFFSET), 0);
    wi32(add(macro, CC1_MACRO_PARAMETER_FIRST_OFFSET), parameter_first);
    wi32(add(macro, CC1_MACRO_PARAMETER_COUNT_OFFSET), parameter_count);
    return 0;
}

function cc1_macro_define(name, length, first_token, token_count,
    parameter_first, parameter_count)
{
    return cc1_macro_define_(name, length, first_token, token_count,
        parameter_first, parameter_count, 0);
}

function cc1_macro_undefine_(name, length, macro)
{
    macro = cc1_macro_find(name, length);
    if (not(eq(macro, 0))) {
        wi32(add(macro, CC1_MACRO_DEFINED_OFFSET), 0);
    }
    return 0;
}

function cc1_macro_undefine(name, length)
{
    return cc1_macro_undefine_(name, length, 0);
}

function cc1_macro_is_defined_(name, length, macro)
{
    macro = cc1_macro_find(name, length);
    if (eq(macro, 0)) {
        return 0;
    }
    return ri32(add(macro, CC1_MACRO_DEFINED_OFFSET));
}

function cc1_macro_is_defined(name, length)
{
    return cc1_macro_is_defined_(name, length, 0);
}

function cc1_condition_record(index)
{
    return add(CC1_CONDITIONS, shl(index, CC1_CONDITION_RECORD_SHIFT));
}

function cc1_condition_active_(condition)
{
    if (eq(CC1_CONDITION_DEPTH, 0)) {
        return 1;
    }
    condition = cc1_condition_record(sub(CC1_CONDITION_DEPTH, 1));
    return ri32(add(condition, CC1_CONDITION_ACTIVE_OFFSET));
}

function cc1_condition_active()
{
    return cc1_condition_active_(0);
}

function cc1_condition_reserve_(needed, capacity, conditions, used)
{
    needed = shl(add(CC1_CONDITION_DEPTH, 1), CC1_CONDITION_RECORD_SHIFT);
    if (le(needed, CC1_CONDITION_CAPACITY)) {
        return 0;
    }
    capacity = CC1_CONDITION_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    conditions = malloc(capacity);
    if (eq(conditions, 0)) {
        return 1;
    }
    used = shl(CC1_CONDITION_DEPTH, CC1_CONDITION_RECORD_SHIFT);
    if (not(eq(CC1_CONDITIONS, 0))) {
        cc1_token_copy_bytes(conditions, CC1_CONDITIONS, used);
    }
    CC1_CONDITIONS = conditions;
    CC1_CONDITION_CAPACITY = capacity;
    return 0;
}

function cc1_condition_reserve()
{
    return cc1_condition_reserve_(0, 0, 0, 0);
}

function cc1_condition_push_(value, parent, active, condition)
{
    parent = cc1_condition_active();
    active = 0;
    if (parent) {
        if (value) {
            active = 1;
        }
    }
    if (cc1_condition_reserve()) {
        return 1;
    }
    condition = cc1_condition_record(CC1_CONDITION_DEPTH);
    wi32(add(condition, CC1_CONDITION_PARENT_OFFSET), parent);
    wi32(add(condition, CC1_CONDITION_ACTIVE_OFFSET), active);
    wi32(add(condition, CC1_CONDITION_TAKEN_OFFSET), active);
    CC1_CONDITION_DEPTH = add(CC1_CONDITION_DEPTH, 1);
    return 0;
}

function cc1_condition_push(value)
{
    return cc1_condition_push_(value, 0, 0, 0);
}

function cc1_condition_else_(condition, active)
{
    if (eq(CC1_CONDITION_DEPTH, 0)) {
        return 1;
    }
    condition = cc1_condition_record(sub(CC1_CONDITION_DEPTH, 1));
    active = 0;
    if (ri32(add(condition, CC1_CONDITION_PARENT_OFFSET))) {
        if (not(ri32(add(condition, CC1_CONDITION_TAKEN_OFFSET)))) {
            active = 1;
        }
    }
    wi32(add(condition, CC1_CONDITION_ACTIVE_OFFSET), active);
    wi32(add(condition, CC1_CONDITION_TAKEN_OFFSET), 1);
    return 0;
}

function cc1_condition_else()
{
    return cc1_condition_else_(0, 0);
}

function cc1_condition_elif_(value, condition, active)
{
    if (eq(CC1_CONDITION_DEPTH, 0)) {
        return 1;
    }
    condition = cc1_condition_record(sub(CC1_CONDITION_DEPTH, 1));
    active = 0;
    if (ri32(add(condition, CC1_CONDITION_PARENT_OFFSET))) {
        if (not(ri32(add(condition, CC1_CONDITION_TAKEN_OFFSET)))) {
            if (value) {
                active = 1;
            }
        }
    }
    wi32(add(condition, CC1_CONDITION_ACTIVE_OFFSET), active);
    if (active) {
        wi32(add(condition, CC1_CONDITION_TAKEN_OFFSET), 1);
    }
    return 0;
}

function cc1_condition_elif(value)
{
    return cc1_condition_elif_(value, 0, 0);
}

function cc1_condition_pop()
{
    if (eq(CC1_CONDITION_DEPTH, 0)) {
        return 1;
    }
    CC1_CONDITION_DEPTH = sub(CC1_CONDITION_DEPTH, 1);
    return 0;
}

function cc1_preprocessed_reserve_(needed, capacity, tokens, used)
{
    needed = shl(add(CC1_PREPROCESSED_COUNT, 1), 2);
    if (le(needed, CC1_PREPROCESSED_CAPACITY)) {
        return 0;
    }
    capacity = CC1_PREPROCESSED_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    tokens = malloc(capacity);
    if (eq(tokens, 0)) {
        return 1;
    }
    used = shl(CC1_PREPROCESSED_COUNT, 2);
    if (not(eq(CC1_PREPROCESSED_TOKENS, 0))) {
        cc1_token_copy_bytes(tokens, CC1_PREPROCESSED_TOKENS, used);
    }
    CC1_PREPROCESSED_TOKENS = tokens;
    CC1_PREPROCESSED_CAPACITY = capacity;
    return 0;
}

function cc1_preprocessed_reserve()
{
    return cc1_preprocessed_reserve_(0, 0, 0, 0);
}

function cc1_preprocessed_append(token)
{
    if (cc1_preprocessed_reserve()) {
        return 1;
    }
    wi32(add(CC1_PREPROCESSED_TOKENS, shl(CC1_PREPROCESSED_COUNT, 2)),
        token);
    CC1_PREPROCESSED_COUNT = add(CC1_PREPROCESSED_COUNT, 1);
    return 0;
}

function cc1_macro_expand_token_(token, macro, first, count, index)
{
    macro = cc1_macro_find(ri32(add(token, CC1_TOKEN_TEXT_OFFSET)),
        ri32(add(token, CC1_TOKEN_LENGTH_OFFSET)));
    if (eq(macro, 0)) {
        return cc1_preprocessed_append(token);
    }
    if (not(ri32(add(macro, CC1_MACRO_DEFINED_OFFSET)))) {
        return cc1_preprocessed_append(token);
    }
    if (ri32(add(macro, CC1_MACRO_EXPANDING_OFFSET))) {
        return cc1_preprocessed_append(token);
    }
    wi32(add(macro, CC1_MACRO_EXPANDING_OFFSET), 1);
    first = ri32(add(macro, CC1_MACRO_FIRST_TOKEN_OFFSET));
    count = ri32(add(macro, CC1_MACRO_TOKEN_COUNT_OFFSET));
    index = 0;
    while (lt(index, count)) {
        if (cc1_macro_expand_token(cc1_token_record(add(first, index)))) {
            wi32(add(macro, CC1_MACRO_EXPANDING_OFFSET), 0);
            return 1;
        }
        index = add(index, 1);
    }
    wi32(add(macro, CC1_MACRO_EXPANDING_OFFSET), 0);
    return 0;
}

function cc1_macro_expand_token(token)
{
    return cc1_macro_expand_token_(token, 0, 0, 0, 0);
}

function cc1_macro_parameter_index_(macro, token, first, count, index,
    parameter)
{
    first = ri32(add(macro, CC1_MACRO_PARAMETER_FIRST_OFFSET));
    count = ri32(add(macro, CC1_MACRO_PARAMETER_COUNT_OFFSET));
    index = 0;
    while (lt(index, count)) {
        parameter = cc1_token_record(add(first, shl(index, 1)));
        if (eq(ri32(add(parameter, CC1_TOKEN_LENGTH_OFFSET)),
            ri32(add(token, CC1_TOKEN_LENGTH_OFFSET)))) {
            if (cc1_slice_equal(ri32(add(parameter, CC1_TOKEN_TEXT_OFFSET)),
                ri32(add(token, CC1_TOKEN_TEXT_OFFSET)),
                ri32(add(token, CC1_TOKEN_LENGTH_OFFSET)))) {
                return index;
            }
        }
        index = add(index, 1);
    }
    return sub(0, 1);
}

function cc1_macro_parameter_index(macro, token)
{
    return cc1_macro_parameter_index_(macro, token, 0, 0, 0, 0);
}

/* Each actual argument is represented by its first raw token and token count. */
function cc1_macro_parse_arguments_(index, parameter_count, arguments,
    argument_index, start, cursor, depth, token, kind)
{
    if (eq(parameter_count, 0)) {
        if (not(eq(ri32(add(cc1_token_record(add(index, 2)),
            CC1_TOKEN_KIND_OFFSET)), 41))) {
            return sub(0, 1);
        }
        return add(index, 3);
    }
    arguments = malloc(shl(add(parameter_count, 1), 3));
    if (eq(arguments, 0)) {
        return sub(0, 1);
    }
    argument_index = 0;
    cursor = add(index, 2);
    while (lt(argument_index, parameter_count)) {
        start = cursor;
        depth = 0;
        while (lt(cursor, CC1_TOKEN_COUNT)) {
            token = cc1_token_record(cursor);
            kind = ri32(add(token, CC1_TOKEN_KIND_OFFSET));
            if (eq(kind, 40)) {
                depth = add(depth, 1);
            } else if (eq(kind, 41)) {
                if (eq(depth, 0)) {
                    break;
                }
                depth = sub(depth, 1);
            } else if (eq(kind, 44)) {
                if (eq(depth, 0)) {
                    break;
                }
            }
            cursor = add(cursor, 1);
        }
        wi32(add(arguments, shl(argument_index, 3)), start);
        wi32(add(arguments, add(shl(argument_index, 3), 4)),
            sub(cursor, start));
        argument_index = add(argument_index, 1);
        kind = ri32(add(cc1_token_record(cursor), CC1_TOKEN_KIND_OFFSET));
        if (lt(argument_index, parameter_count)) {
            if (not(eq(kind, 44))) {
                return sub(0, 1);
            }
            cursor = add(cursor, 1);
        } else if (not(eq(kind, 41))) {
            return sub(0, 1);
        }
    }
    wi32(add(arguments, shl(parameter_count, 3)), cursor);
    return arguments;
}

function cc1_macro_parse_arguments(index, parameter_count)
{
    return cc1_macro_parse_arguments_(index, parameter_count, 0, 0, 0,
        0, 0, 0, 0);
}

function cc1_macro_expand_function_(index, macro, parameter_count,
    arguments, cursor, first, count, replacement_index, token,
    parameter_index, argument_start, argument_count, argument_token_index,
    next_index)
{
    parameter_count = ri32(add(macro, CC1_MACRO_PARAMETER_COUNT_OFFSET));
    arguments = cc1_macro_parse_arguments(index, parameter_count);
    if (lt(arguments, 0)) {
        return sub(0, 1);
    }
    if (eq(parameter_count, 0)) {
        next_index = arguments;
    } else {
        cursor = ri32(add(arguments, shl(parameter_count, 3)));
        next_index = add(cursor, 1);
    }
    if (ri32(add(macro, CC1_MACRO_EXPANDING_OFFSET))) {
        if (cc1_preprocessed_append(cc1_token_record(index))) {
            return sub(0, 1);
        }
        return next_index;
    }
    wi32(add(macro, CC1_MACRO_EXPANDING_OFFSET), 1);
    first = ri32(add(macro, CC1_MACRO_FIRST_TOKEN_OFFSET));
    count = ri32(add(macro, CC1_MACRO_TOKEN_COUNT_OFFSET));
    replacement_index = 0;
    while (lt(replacement_index, count)) {
        token = cc1_token_record(add(first, replacement_index));
        parameter_index = cc1_macro_parameter_index(macro, token);
        if (lt(parameter_index, 0)) {
            if (cc1_macro_expand_token(token)) {
                wi32(add(macro, CC1_MACRO_EXPANDING_OFFSET), 0);
                return sub(0, 1);
            }
        } else {
            argument_start = ri32(add(arguments,
                shl(parameter_index, 3)));
            argument_count = ri32(add(arguments,
                add(shl(parameter_index, 3), 4)));
            argument_token_index = 0;
            while (lt(argument_token_index, argument_count)) {
                if (cc1_macro_expand_token(cc1_token_record(add(
                    argument_start, argument_token_index)))) {
                    wi32(add(macro, CC1_MACRO_EXPANDING_OFFSET), 0);
                    return sub(0, 1);
                }
                argument_token_index = add(argument_token_index, 1);
            }
        }
        replacement_index = add(replacement_index, 1);
    }
    wi32(add(macro, CC1_MACRO_EXPANDING_OFFSET), 0);
    return next_index;
}

function cc1_macro_expand_function(index, macro)
{
    return cc1_macro_expand_function_(index, macro, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0);
}

function cc1_macro_expand_at_(index, token, macro, parameter_count,
    next_token)
{
    token = cc1_token_record(index);
    macro = cc1_macro_find(ri32(add(token, CC1_TOKEN_TEXT_OFFSET)),
        ri32(add(token, CC1_TOKEN_LENGTH_OFFSET)));
    if (eq(macro, 0)) {
        if (cc1_preprocessed_append(token)) {
            return sub(0, 1);
        }
        return add(index, 1);
    }
    if (not(ri32(add(macro, CC1_MACRO_DEFINED_OFFSET)))) {
        if (cc1_preprocessed_append(token)) {
            return sub(0, 1);
        }
        return add(index, 1);
    }
    parameter_count = ri32(add(macro, CC1_MACRO_PARAMETER_COUNT_OFFSET));
    if (lt(parameter_count, 0)) {
        if (cc1_macro_expand_token(token)) {
            return sub(0, 1);
        }
        return add(index, 1);
    }
    if (not(lt(add(index, 1), CC1_TOKEN_COUNT))) {
        return sub(0, 1);
    }
    next_token = cc1_token_record(add(index, 1));
    if (not(eq(ri32(add(next_token, CC1_TOKEN_KIND_OFFSET)), 40))) {
        if (cc1_preprocessed_append(token)) {
            return sub(0, 1);
        }
        return add(index, 1);
    }
    return cc1_macro_expand_function(index, macro);
}

function cc1_macro_expand_at(index)
{
    return cc1_macro_expand_at_(index, 0, 0, 0, 0);
}

function cc1_preprocess_define_(index, line, name_token, first, count,
    next_token, parameter_first, parameter_count, kind)
{
    index = add(index, 2);
    if (not(lt(index, CC1_TOKEN_COUNT))) {
        return sub(0, 1);
    }
    name_token = cc1_token_record(index);
    if (not(eq(ri32(add(name_token, CC1_TOKEN_LINE_OFFSET)), line))) {
        return sub(0, 1);
    }
    parameter_first = 0;
    parameter_count = sub(0, 1);
    first = add(index, 1);
    if (lt(first, CC1_TOKEN_COUNT)) {
        next_token = cc1_token_record(first);
        if (eq(ri32(add(next_token, CC1_TOKEN_KIND_OFFSET)), 40)) {
            if (eq(ri32(add(next_token, CC1_TOKEN_SOURCE_OFFSET)),
                add(ri32(add(name_token, CC1_TOKEN_SOURCE_OFFSET)),
                ri32(add(name_token, CC1_TOKEN_LENGTH_OFFSET))))) {
                parameter_first = add(first, 1);
                parameter_count = 0;
                index = parameter_first;
                while (lt(index, CC1_TOKEN_COUNT)) {
                    next_token = cc1_token_record(index);
                    kind = ri32(add(next_token, CC1_TOKEN_KIND_OFFSET));
                    if (eq(kind, 41)) {
                        first = add(index, 1);
                        break;
                    }
                    if (not(eq(kind, 2))) {
                        return sub(0, 1);
                    }
                    parameter_count = add(parameter_count, 1);
                    index = add(index, 1);
                    next_token = cc1_token_record(index);
                    kind = ri32(add(next_token, CC1_TOKEN_KIND_OFFSET));
                    if (eq(kind, 44)) {
                        index = add(index, 1);
                    } else if (not(eq(kind, 41))) {
                        return sub(0, 1);
                    }
                }
            }
        }
    }
    index = first;
    while (lt(index, CC1_TOKEN_COUNT)) {
        if (not(eq(ri32(add(cc1_token_record(index),
            CC1_TOKEN_LINE_OFFSET)), line))) {
            break;
        }
        index = add(index, 1);
    }
    count = sub(index, first);
    if (cc1_macro_define(ri32(add(name_token, CC1_TOKEN_TEXT_OFFSET)),
        ri32(add(name_token, CC1_TOKEN_LENGTH_OFFSET)), first, count,
        parameter_first, parameter_count)) {
        return sub(0, 1);
    }
    return index;
}

function cc1_preprocess_define(index, line)
{
    return cc1_preprocess_define_(index, line, 0, 0, 0, 0, 0, 0, 0);
}

function cc1_preprocess_undef_(index, line, name_token)
{
    index = add(index, 2);
    if (not(lt(index, CC1_TOKEN_COUNT))) {
        return sub(0, 1);
    }
    name_token = cc1_token_record(index);
    if (not(eq(ri32(add(name_token, CC1_TOKEN_LINE_OFFSET)), line))) {
        return sub(0, 1);
    }
    cc1_macro_undefine(ri32(add(name_token, CC1_TOKEN_TEXT_OFFSET)),
        ri32(add(name_token, CC1_TOKEN_LENGTH_OFFSET)));
    index = add(index, 1);
    while (lt(index, CC1_TOKEN_COUNT)) {
        if (not(eq(ri32(add(cc1_token_record(index),
            CC1_TOKEN_LINE_OFFSET)), line))) {
            break;
        }
        index = add(index, 1);
    }
    return index;
}

function cc1_preprocess_undef(index, line)
{
    return cc1_preprocess_undef_(index, line, 0);
}

function cc1_preprocess_skip_line_(index, line)
{
    index = add(index, 1);
    while (lt(index, CC1_TOKEN_COUNT)) {
        if (not(eq(ri32(add(cc1_token_record(index),
            CC1_TOKEN_LINE_OFFSET)), line))) {
            break;
        }
        index = add(index, 1);
    }
    return index;
}

function cc1_preprocess_skip_line(index, line)
{
    return cc1_preprocess_skip_line_(index, line);
}

function cc1_preprocess_condition_(index, line, invert, name_token, value)
{
    if (not(lt(add(index, 2), CC1_TOKEN_COUNT))) {
        return sub(0, 1);
    }
    name_token = cc1_token_record(add(index, 2));
    if (not(eq(ri32(add(name_token, CC1_TOKEN_LINE_OFFSET)), line))) {
        return sub(0, 1);
    }
    value = cc1_macro_is_defined(
        ri32(add(name_token, CC1_TOKEN_TEXT_OFFSET)),
        ri32(add(name_token, CC1_TOKEN_LENGTH_OFFSET)));
    if (invert) {
        value = not(value);
    }
    if (cc1_condition_push(value)) {
        return sub(0, 1);
    }
    return cc1_preprocess_skip_line(index, line);
}

function cc1_preprocess_condition(index, line, invert)
{
    return cc1_preprocess_condition_(index, line, invert, 0, 0);
}

function cc1_preprocess_integer_value_(token, kind, macro, first,
    replacement)
{
    kind = ri32(add(token, CC1_TOKEN_KIND_OFFSET));
    if (eq(kind, 3)) {
        return ri32(add(token, CC1_TOKEN_NUMBER_OFFSET));
    }
    if (not(eq(kind, 2))) {
        return 0;
    }
    macro = cc1_macro_find(ri32(add(token, CC1_TOKEN_TEXT_OFFSET)),
        ri32(add(token, CC1_TOKEN_LENGTH_OFFSET)));
    if (eq(macro, 0)) {
        return 0;
    }
    if (not(ri32(add(macro, CC1_MACRO_DEFINED_OFFSET)))) {
        return 0;
    }
    if (not(eq(ri32(add(macro, CC1_MACRO_TOKEN_COUNT_OFFSET)), 1))) {
        return 0;
    }
    first = ri32(add(macro, CC1_MACRO_FIRST_TOKEN_OFFSET));
    replacement = cc1_token_record(first);
    if (not(eq(ri32(add(replacement, CC1_TOKEN_KIND_OFFSET)), 3))) {
        return 0;
    }
    return ri32(add(replacement, CC1_TOKEN_NUMBER_OFFSET));
}

function cc1_preprocess_integer_value(token)
{
    return cc1_preprocess_integer_value_(token, 0, 0, 0, 0);
}

function cc1_preprocess_if_value_(index, line, token, invert, value,
    name_token)
{
    index = add(index, 2);
    if (not(lt(index, CC1_TOKEN_COUNT))) {
        return 0;
    }
    token = cc1_token_record(index);
    if (not(eq(ri32(add(token, CC1_TOKEN_LINE_OFFSET)), line))) {
        return 0;
    }
    invert = 0;
    if (eq(ri32(add(token, CC1_TOKEN_KIND_OFFSET)), 33)) {
        invert = 1;
        index = add(index, 1);
        token = cc1_token_record(index);
    }
    if (cc1_text_equal(ri32(add(token, CC1_TOKEN_TEXT_OFFSET)),
        ri32(add(token, CC1_TOKEN_LENGTH_OFFSET)), mks("defined"))) {
        index = add(index, 1);
        token = cc1_token_record(index);
        if (eq(ri32(add(token, CC1_TOKEN_KIND_OFFSET)), 40)) {
            index = add(index, 1);
            token = cc1_token_record(index);
        }
        name_token = token;
        value = cc1_macro_is_defined(
            ri32(add(name_token, CC1_TOKEN_TEXT_OFFSET)),
            ri32(add(name_token, CC1_TOKEN_LENGTH_OFFSET)));
    } else {
        value = cc1_preprocess_integer_value(token);
    }
    if (invert) {
        value = not(value);
    }
    return value;
}

function cc1_preprocess_if_value(index, line)
{
    return cc1_preprocess_if_value_(index, line, 0, 0, 0, 0);
}

function cc1_preprocess_if_(index, line, value)
{
    value = cc1_preprocess_if_value(index, line);
    if (cc1_condition_push(value)) {
        return sub(0, 1);
    }
    return cc1_preprocess_skip_line(index, line);
}

function cc1_preprocess_if(index, line)
{
    return cc1_preprocess_if_(index, line, 0);
}

function cc1_preprocess_elif_(index, line, value)
{
    value = cc1_preprocess_if_value(index, line);
    if (cc1_condition_elif(value)) {
        return sub(0, 1);
    }
    return cc1_preprocess_skip_line(index, line);
}

function cc1_preprocess_elif(index, line)
{
    return cc1_preprocess_elif_(index, line, 0);
}

function cc1_preprocess_tokens_(index, previous_line, token, line,
    directive, next_index, active, kind)
{
    CC1_MACRO_COUNT = 0;
    CC1_CONDITION_DEPTH = 0;
    CC1_PREPROCESSED_COUNT = 0;
    CC1_PREPROCESSED_CURSOR = 0;
    index = 0;
    previous_line = 0;
    while (lt(index, CC1_TOKEN_COUNT)) {
        token = cc1_token_record(index);
        line = ri32(add(token, CC1_TOKEN_LINE_OFFSET));
        kind = ri32(add(token, CC1_TOKEN_KIND_OFFSET));
        active = cc1_condition_active();
        if (eq(kind, 35)) {
            if (not(eq(line, previous_line))) {
                if (not(lt(add(index, 1), CC1_TOKEN_COUNT))) {
                    return 1;
                }
                directive = cc1_token_record(add(index, 1));
                if (cc1_text_equal(ri32(add(directive, CC1_TOKEN_TEXT_OFFSET)),
                    ri32(add(directive, CC1_TOKEN_LENGTH_OFFSET)),
                    mks("define"))) {
                    if (active) {
                        next_index = cc1_preprocess_define(index, line);
                    } else {
                        next_index = cc1_preprocess_skip_line(index, line);
                    }
                } else if (cc1_text_equal(ri32(add(directive,
                    CC1_TOKEN_TEXT_OFFSET)), ri32(add(directive,
                    CC1_TOKEN_LENGTH_OFFSET)), mks("undef"))) {
                    if (active) {
                        next_index = cc1_preprocess_undef(index, line);
                    } else {
                        next_index = cc1_preprocess_skip_line(index, line);
                    }
                } else if (cc1_text_equal(ri32(add(directive,
                    CC1_TOKEN_TEXT_OFFSET)), ri32(add(directive,
                    CC1_TOKEN_LENGTH_OFFSET)), mks("ifdef"))) {
                    next_index = cc1_preprocess_condition(index, line, 0);
                } else if (cc1_text_equal(ri32(add(directive,
                    CC1_TOKEN_TEXT_OFFSET)), ri32(add(directive,
                    CC1_TOKEN_LENGTH_OFFSET)), mks("ifndef"))) {
                    next_index = cc1_preprocess_condition(index, line, 1);
                } else if (cc1_text_equal(ri32(add(directive,
                    CC1_TOKEN_TEXT_OFFSET)), ri32(add(directive,
                    CC1_TOKEN_LENGTH_OFFSET)), mks("if"))) {
                    next_index = cc1_preprocess_if(index, line);
                } else if (cc1_text_equal(ri32(add(directive,
                    CC1_TOKEN_TEXT_OFFSET)), ri32(add(directive,
                    CC1_TOKEN_LENGTH_OFFSET)), mks("elif"))) {
                    next_index = cc1_preprocess_elif(index, line);
                } else if (cc1_text_equal(ri32(add(directive,
                    CC1_TOKEN_TEXT_OFFSET)), ri32(add(directive,
                    CC1_TOKEN_LENGTH_OFFSET)), mks("else"))) {
                    if (cc1_condition_else()) {
                        return 1;
                    }
                    next_index = cc1_preprocess_skip_line(index, line);
                } else if (cc1_text_equal(ri32(add(directive,
                    CC1_TOKEN_TEXT_OFFSET)), ri32(add(directive,
                    CC1_TOKEN_LENGTH_OFFSET)), mks("endif"))) {
                    if (cc1_condition_pop()) {
                        return 1;
                    }
                    next_index = cc1_preprocess_skip_line(index, line);
                } else {
                    if (active) {
                        return 1;
                    }
                    next_index = cc1_preprocess_skip_line(index, line);
                }
                if (lt(next_index, 0)) {
                    return 1;
                }
                previous_line = line;
                index = next_index;
            } else {
                next_index = cc1_macro_expand_at(index);
                if (lt(next_index, 0)) {
                    return 1;
                }
                previous_line = line;
                index = next_index;
            }
        } else {
            if (active) {
                next_index = cc1_macro_expand_at(index);
                if (lt(next_index, 0)) {
                    return 1;
                }
                index = next_index;
            } else if (eq(kind, CC1_TOKEN_EOF)) {
                if (cc1_preprocessed_append(token)) {
                    return 1;
                }
                index = add(index, 1);
            } else {
                index = add(index, 1);
            }
            previous_line = line;
        }
    }
    return not(eq(CC1_CONDITION_DEPTH, 0));
}

function cc1_preprocess_tokens()
{
    return cc1_preprocess_tokens_(0, 0, 0, 0, 0, 0, 0, 0);
}

function cc1_expanded_reserve_(needed, capacity, source, files, offsets,
    lines, columns, used)
{
    needed = add(CC1_EXPANDED_LENGTH, 1);
    if (le(needed, CC1_EXPANDED_CAPACITY)) {
        return 0;
    }
    capacity = CC1_EXPANDED_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    source = malloc(capacity);
    files = malloc(shl(capacity, 2));
    offsets = malloc(shl(capacity, 2));
    lines = malloc(shl(capacity, 2));
    columns = malloc(shl(capacity, 2));
    if (eq(source, 0)) {
        return 1;
    }
    if (eq(files, 0)) {
        return 1;
    }
    if (eq(offsets, 0)) {
        return 1;
    }
    if (eq(lines, 0)) {
        return 1;
    }
    if (eq(columns, 0)) {
        return 1;
    }
    used = CC1_EXPANDED_LENGTH;
    if (not(eq(CC1_EXPANDED_SOURCE, 0))) {
        cc1_token_copy_bytes(source, CC1_EXPANDED_SOURCE, used);
        cc1_token_copy_bytes(files, CC1_EXPANDED_FILES, shl(used, 2));
        cc1_token_copy_bytes(offsets, CC1_EXPANDED_OFFSETS, shl(used, 2));
        cc1_token_copy_bytes(lines, CC1_EXPANDED_LINES, shl(used, 2));
        cc1_token_copy_bytes(columns, CC1_EXPANDED_COLUMNS, shl(used, 2));
    }
    CC1_EXPANDED_SOURCE = source;
    CC1_EXPANDED_FILES = files;
    CC1_EXPANDED_OFFSETS = offsets;
    CC1_EXPANDED_LINES = lines;
    CC1_EXPANDED_COLUMNS = columns;
    CC1_EXPANDED_CAPACITY = capacity;
    return 0;
}

function cc1_expanded_reserve()
{
    return cc1_expanded_reserve_(0, 0, 0, 0, 0, 0, 0, 0);
}

function cc1_expanded_append(value, file, offset, line, column)
{
    if (cc1_expanded_reserve()) {
        return 1;
    }
    wi8(add(CC1_EXPANDED_SOURCE, CC1_EXPANDED_LENGTH), value);
    wi32(add(CC1_EXPANDED_FILES, shl(CC1_EXPANDED_LENGTH, 2)), file);
    wi32(add(CC1_EXPANDED_OFFSETS, shl(CC1_EXPANDED_LENGTH, 2)), offset);
    wi32(add(CC1_EXPANDED_LINES, shl(CC1_EXPANDED_LENGTH, 2)), line);
    wi32(add(CC1_EXPANDED_COLUMNS, shl(CC1_EXPANDED_LENGTH, 2)), column);
    CC1_EXPANDED_LENGTH = add(CC1_EXPANDED_LENGTH, 1);
    return 0;
}

function cc1_c_string_equal_(left, right, left_value, right_value)
{
    while (1) {
        left_value = ri8(left);
        right_value = ri8(right);
        if (not(eq(left_value, right_value))) {
            return 0;
        }
        if (eq(left_value, 0)) {
            return 1;
        }
        left = add(left, 1);
        right = add(right, 1);
    }
}

function cc1_c_string_equal(left, right)
{
    return cc1_c_string_equal_(left, right, 0, 0);
}

function cc1_include_stack_contains_(stack, file)
{
    while (not(eq(stack, 0))) {
        if (cc1_c_string_equal(ri32(stack), file)) {
            return 1;
        }
        stack = ri32(add(stack, 4));
    }
    return 0;
}

function cc1_include_stack_contains(stack, file)
{
    return cc1_include_stack_contains_(stack, file);
}

function cc1_include_path_(file, text, length, directory_length, index,
    path)
{
    directory_length = 0;
    index = 0;
    while (not(eq(ri8(add(file, index)), 0))) {
        if (eq(ri8(add(file, index)), CC1_ASCII_SLASH)) {
            directory_length = add(index, 1);
        }
        index = add(index, 1);
    }
    path = malloc(add(add(directory_length, length), 1));
    if (eq(path, 0)) {
        return 0;
    }
    index = 0;
    while (lt(index, directory_length)) {
        wi8(add(path, index), ri8(add(file, index)));
        index = add(index, 1);
    }
    index = 0;
    while (lt(index, length)) {
        wi8(add(path, add(directory_length, index)), ri8(add(text, index)));
        index = add(index, 1);
    }
    wi8(add(path, add(directory_length, length)), 0);
    return path;
}

function cc1_include_path(file, text, length)
{
    return cc1_include_path_(file, text, length, 0, 0, 0);
}

function cc1_include_read_(file, size_pointer, descriptor, size, source,
    position, count)
{
    descriptor = open(file, 0, 0);
    if (lt(descriptor, 0)) {
        return 0;
    }
    size = lseek(descriptor, 0, 2);
    if (lt(size, 0)) {
        close(descriptor);
        return 0;
    }
    if (lt(lseek(descriptor, 0, 0), 0)) {
        close(descriptor);
        return 0;
    }
    source = malloc(add(size, 1));
    if (eq(source, 0)) {
        close(descriptor);
        return 0;
    }
    position = 0;
    while (lt(position, size)) {
        count = read(descriptor, add(source, position), sub(size, position));
        if (not(lt(0, count))) {
            close(descriptor);
            return 0;
        }
        position = add(position, count);
    }
    close(descriptor);
    wi8(add(source, size), 0);
    wi32(size_pointer, size);
    return source;
}

function cc1_include_read(file, size_pointer)
{
    return cc1_include_read_(file, size_pointer, 0, 0, 0, 0, 0);
}

function cc1_expand_source_recursive_(source, length, file, stack, index,
    line, column, cursor, word_start, path_start, path_length, path,
    size_pointer, included_source, included_length, child_stack, character)
{
    index = 0;
    line = 1;
    column = 1;
    while (lt(index, length)) {
        character = ri8(add(source, index));
        if (eq(column, 1)) {
            cursor = index;
            while (lt(cursor, length)) {
                character = ri8(add(source, cursor));
                if (eq(character, CC1_ASCII_SPACE)) {
                    cursor = add(cursor, 1);
                } else if (eq(character, CC1_ASCII_TAB)) {
                    cursor = add(cursor, 1);
                } else {
                    break;
                }
            }
            if (lt(cursor, length)) {
                if (eq(ri8(add(source, cursor)), CC1_ASCII_HASH)) {
                    cursor = add(cursor, 1);
                    while (lt(cursor, length)) {
                        character = ri8(add(source, cursor));
                        if (eq(character, CC1_ASCII_SPACE)) {
                            cursor = add(cursor, 1);
                        } else if (eq(character, CC1_ASCII_TAB)) {
                            cursor = add(cursor, 1);
                        } else {
                            break;
                        }
                    }
                    word_start = cursor;
                    if (le(add(cursor, 7), length)) {
                        cursor = add(cursor, 7);
                        if (cc1_slice_equal(add(source, word_start),
                            mks("include"), 7)) {
                            while (lt(cursor, length)) {
                                character = ri8(add(source, cursor));
                                if (eq(character, CC1_ASCII_SPACE)) {
                                    cursor = add(cursor, 1);
                                } else if (eq(character, CC1_ASCII_TAB)) {
                                    cursor = add(cursor, 1);
                                } else {
                                    break;
                                }
                            }
                            if (eq(ri8(add(source, cursor)),
                                CC1_ASCII_QUOTE)) {
                                path_start = add(cursor, 1);
                                cursor = path_start;
                                while (lt(cursor, length)) {
                                    if (eq(ri8(add(source, cursor)),
                                        CC1_ASCII_QUOTE)) {
                                        break;
                                    }
                                    cursor = add(cursor, 1);
                                }
                                path_length = sub(cursor, path_start);
                                path = cc1_include_path(file,
                                    add(source, path_start), path_length);
                                if (eq(path, 0)) {
                                    return 1;
                                }
                                if (not(cc1_include_stack_contains(stack,
                                    path))) {
                                    size_pointer = malloc(4);
                                    if (eq(size_pointer, 0)) {
                                        return 1;
                                    }
                                    included_source = cc1_include_read(path,
                                        size_pointer);
                                    if (eq(included_source, 0)) {
                                        return 1;
                                    }
                                    included_length = ri32(size_pointer);
                                    child_stack = malloc(8);
                                    if (eq(child_stack, 0)) {
                                        return 1;
                                    }
                                    wi32(child_stack, path);
                                    wi32(add(child_stack, 4), stack);
                                    if (cc1_expand_source_recursive(
                                        included_source, included_length,
                                        path, child_stack)) {
                                        return 1;
                                    }
                                }
                                while (lt(index, length)) {
                                    character = ri8(add(source, index));
                                    if (eq(character,
                                        CC1_ASCII_LINE_FEED)) {
                                        break;
                                    }
                                    index = add(index, 1);
                                }
                                column = 1;
                            }
                        }
                    }
                }
            }
        }
        if (lt(index, length)) {
            character = ri8(add(source, index));
            if (cc1_expanded_append(character, file, index, line, column)) {
                return 1;
            }
            if (eq(character, CC1_ASCII_LINE_FEED)) {
                line = add(line, 1);
                column = 1;
            } else {
                column = add(column, 1);
            }
            index = add(index, 1);
        }
    }
    return 0;
}

function cc1_expand_source_recursive(source, length, file, stack)
{
    return cc1_expand_source_recursive_(source, length, file, stack, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

function cc1_expand_source_(source, length, file, stack)
{
    CC1_ASCII_TAB = 9;
    CC1_ASCII_LINE_FEED = 10;
    CC1_ASCII_CARRIAGE_RETURN = 13;
    CC1_ASCII_SPACE = 32;
    CC1_ASCII_QUOTE = 34;
    CC1_ASCII_HASH = 35;
    CC1_ASCII_SLASH = 47;
    CC1_EXPANDED_LENGTH = 0;
    stack = malloc(8);
    if (eq(stack, 0)) {
        return 1;
    }
    wi32(stack, file);
    wi32(add(stack, 4), 0);
    if (cc1_expand_source_recursive(source, length, file, stack)) {
        return 1;
    }
    CC1_EXPANSION_ACTIVE = 1;
    return 0;
}

function cc1_expand_source(source, length, file)
{
    return cc1_expand_source_(source, length, file, 0);
}

function cc1_preprocess(source, length, file)
{
    CC1_EXPANSION_ACTIVE = 0;
    if (cc1_expand_source(source, length, file)) {
        return 1;
    }
    if (cc1_tokenize(CC1_EXPANDED_SOURCE, CC1_EXPANDED_LENGTH, file)) {
        return 1;
    }
    return cc1_preprocess_tokens();
}

function cc1_preprocessed_peek_(distance, index)
{
    if (lt(distance, 0)) {
        return 0;
    }
    index = add(CC1_PREPROCESSED_CURSOR, distance);
    if (not(lt(index, CC1_PREPROCESSED_COUNT))) {
        return 0;
    }
    return ri32(add(CC1_PREPROCESSED_TOKENS, shl(index, 2)));
}

function cc1_preprocessed_peek(distance)
{
    return cc1_preprocessed_peek_(distance, 0);
}

function cc1_preprocessed_consume_(token)
{
    token = cc1_preprocessed_peek(0);
    if (not(eq(token, 0))) {
        CC1_PREPROCESSED_CURSOR = add(CC1_PREPROCESSED_CURSOR, 1);
    }
    return token;
}

function cc1_preprocessed_consume()
{
    return cc1_preprocessed_consume_(0);
}

function cc1_normalized_reserve_(extra, needed, capacity, source, origins,
    files, lines, columns)
{
    needed = add(CC1_NORMALIZED_LENGTH, extra);
    if (le(needed, CC1_NORMALIZED_CAPACITY)) {
        return 0;
    }
    capacity = CC1_NORMALIZED_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    source = malloc(capacity);
    origins = malloc(shl(capacity, 2));
    files = malloc(shl(capacity, 2));
    lines = malloc(shl(capacity, 2));
    columns = malloc(shl(capacity, 2));
    if (eq(source, 0)) {
        return 1;
    }
    if (eq(origins, 0)) {
        return 1;
    }
    if (eq(files, 0)) {
        return 1;
    }
    if (eq(lines, 0)) {
        return 1;
    }
    if (eq(columns, 0)) {
        return 1;
    }
    if (not(eq(CC1_NORMALIZED_SOURCE, 0))) {
        cc1_token_copy_bytes(source, CC1_NORMALIZED_SOURCE,
            CC1_NORMALIZED_LENGTH);
        cc1_token_copy_bytes(origins, CC1_NORMALIZED_ORIGINS,
            shl(CC1_NORMALIZED_LENGTH, 2));
        cc1_token_copy_bytes(files, CC1_NORMALIZED_FILES,
            shl(CC1_NORMALIZED_LENGTH, 2));
        cc1_token_copy_bytes(lines, CC1_NORMALIZED_LINES,
            shl(CC1_NORMALIZED_LENGTH, 2));
        cc1_token_copy_bytes(columns, CC1_NORMALIZED_COLUMNS,
            shl(CC1_NORMALIZED_LENGTH, 2));
    }
    CC1_NORMALIZED_SOURCE = source;
    CC1_NORMALIZED_ORIGINS = origins;
    CC1_NORMALIZED_FILES = files;
    CC1_NORMALIZED_LINES = lines;
    CC1_NORMALIZED_COLUMNS = columns;
    CC1_NORMALIZED_CAPACITY = capacity;
    return 0;
}

function cc1_normalized_reserve(extra)
{
    return cc1_normalized_reserve_(extra, 0, 0, 0, 0, 0, 0, 0);
}

function cc1_normalized_byte(value, origin)
{
    if (cc1_normalized_reserve(1)) {
        return 1;
    }
    wi8(add(CC1_NORMALIZED_SOURCE, CC1_NORMALIZED_LENGTH), value);
    wi32(add(CC1_NORMALIZED_ORIGINS, shl(CC1_NORMALIZED_LENGTH, 2)), origin);
    wi32(add(CC1_NORMALIZED_FILES, shl(CC1_NORMALIZED_LENGTH, 2)),
        CC1_NORMALIZED_CURRENT_FILE);
    wi32(add(CC1_NORMALIZED_LINES, shl(CC1_NORMALIZED_LENGTH, 2)),
        CC1_NORMALIZED_CURRENT_LINE);
    wi32(add(CC1_NORMALIZED_COLUMNS, shl(CC1_NORMALIZED_LENGTH, 2)),
        CC1_NORMALIZED_CURRENT_COLUMN);
    CC1_NORMALIZED_LENGTH = add(CC1_NORMALIZED_LENGTH, 1);
    return 0;
}

function cc1_normalized_text_(text, length, origin, index)
{
    if (cc1_normalized_reserve(length)) {
        return 1;
    }
    index = 0;
    while (lt(index, length)) {
        wi8(add(CC1_NORMALIZED_SOURCE, CC1_NORMALIZED_LENGTH),
            ri8(add(text, index)));
        wi32(add(CC1_NORMALIZED_ORIGINS, shl(CC1_NORMALIZED_LENGTH, 2)),
            add(origin, index));
        wi32(add(CC1_NORMALIZED_FILES, shl(CC1_NORMALIZED_LENGTH, 2)),
            CC1_NORMALIZED_CURRENT_FILE);
        wi32(add(CC1_NORMALIZED_LINES, shl(CC1_NORMALIZED_LENGTH, 2)),
            CC1_NORMALIZED_CURRENT_LINE);
        wi32(add(CC1_NORMALIZED_COLUMNS, shl(CC1_NORMALIZED_LENGTH, 2)),
            add(CC1_NORMALIZED_CURRENT_COLUMN, index));
        CC1_NORMALIZED_LENGTH = add(CC1_NORMALIZED_LENGTH, 1);
        index = add(index, 1);
    }
    return 0;
}

function cc1_normalized_text(text, length, origin)
{
    return cc1_normalized_text_(text, length, origin, 0);
}

/* Expressions are buffered because infix C operands must be reordered into
 * primitive calls before the operator-free cc0 parser can consume them. */
function cc1_expression_record(index)
{
    return add(CC1_EXPRESSIONS, shl(index, CC1_EXPRESSION_RECORD_SHIFT));
}

function cc1_expression_reserve_(needed, capacity, expressions, used)
{
    needed = shl(add(CC1_EXPRESSION_COUNT, 1),
        CC1_EXPRESSION_RECORD_SHIFT);
    if (le(needed, CC1_EXPRESSION_CAPACITY)) {
        return 0;
    }
    capacity = CC1_EXPRESSION_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    expressions = malloc(capacity);
    if (eq(expressions, 0)) {
        return 1;
    }
    used = shl(CC1_EXPRESSION_COUNT, CC1_EXPRESSION_RECORD_SHIFT);
    if (not(eq(CC1_EXPRESSIONS, 0))) {
        cc1_token_copy_bytes(expressions, CC1_EXPRESSIONS, used);
    }
    CC1_EXPRESSIONS = expressions;
    CC1_EXPRESSION_CAPACITY = capacity;
    return 0;
}

function cc1_expression_reserve()
{
    return cc1_expression_reserve_(0, 0, 0, 0);
}

function cc1_expression_new_(kind, token, left, right, expression)
{
    if (cc1_expression_reserve()) {
        CC1_EXPRESSION_ERROR = 1;
        return 0;
    }
    expression = cc1_expression_record(CC1_EXPRESSION_COUNT);
    wi32(add(expression, CC1_EXPRESSION_KIND_OFFSET), kind);
    wi32(add(expression, CC1_EXPRESSION_TOKEN_OFFSET), token);
    wi32(add(expression, CC1_EXPRESSION_LEFT_OFFSET), left);
    wi32(add(expression, CC1_EXPRESSION_RIGHT_OFFSET), right);
    CC1_EXPRESSION_COUNT = add(CC1_EXPRESSION_COUNT, 1);
    return expression;
}

function cc1_expression_new(kind, token, left, right)
{
    return cc1_expression_new_(kind, token, left, right, 0);
}

function cc1_expression_init()
{
    CC1_EXPRESSION_RECORD_SHIFT = 4;
    CC1_EXPRESSION_KIND_OFFSET = 0;
    CC1_EXPRESSION_TOKEN_OFFSET = 4;
    CC1_EXPRESSION_LEFT_OFFSET = 8;
    CC1_EXPRESSION_RIGHT_OFFSET = 12;
    CC1_EXPRESSION_ATOM_KIND = 1;
    CC1_EXPRESSION_CALL_KIND = 2;
    CC1_EXPRESSION_ARGUMENT_KIND = 3;
    CC1_EXPRESSION_ADD_KIND = 4;
    CC1_EXPRESSION_SUBTRACT_KIND = 5;
    CC1_EXPRESSION_EQUAL_KIND = 6;
    CC1_EXPRESSION_LESS_KIND = 7;
    CC1_EXPRESSION_LESS_EQUAL_KIND = 8;
    CC1_EXPRESSION_NOT_KIND = 9;
    CC1_EXPRESSION_NEGATE_KIND = 10;
    CC1_EXPRESSION_MULTIPLY_KIND = 11;
    CC1_EXPRESSION_DIVIDE_KIND = 12;
    CC1_EXPRESSION_REMAINDER_KIND = 13;
    CC1_EXPRESSION_SHIFT_LEFT_KIND = 14;
    CC1_EXPRESSION_SHIFT_RIGHT_KIND = 15;
    CC1_EXPRESSION_BIT_AND_KIND = 16;
    CC1_EXPRESSION_BIT_XOR_KIND = 17;
    CC1_EXPRESSION_BIT_OR_KIND = 18;
    CC1_EXPRESSION_COMPLEMENT_KIND = 19;
    CC1_EXPRESSION_DEREFERENCE_KIND = 20;
    CC1_EXPRESSION_ADDRESS_KIND = 21;
    CC1_EXPRESSION_ASSIGN_KIND = 22;
    CC1_EXPRESSION_LOGICAL_AND_KIND = 23;
    CC1_EXPRESSION_LOGICAL_OR_KIND = 24;
    CC1_EXPRESSION_CONDITIONAL_KIND = 25;
    CC1_EXPRESSION_CONSTANT_KIND = 26;
    CC1_EXPRESSION_COMMA_KIND = 27;
    CC1_EXPRESSION_COUNT = 0;
    CC1_EXPRESSION_ERROR = 0;
    return 0;
}

function cc1_expression_token_kind_(token)
{
    token = cc1_preprocessed_peek(0);
    if (eq(token, 0)) {
        return 0;
    }
    return ri32(add(token, CC1_TOKEN_KIND_OFFSET));
}

function cc1_expression_token_kind()
{
    return cc1_expression_token_kind_(0);
}

function cc1_expression_accept(kind)
{
    if (not(eq(cc1_expression_token_kind(), kind))) {
        return 0;
    }
    cc1_preprocessed_consume();
    return 1;
}

function cc1_expression_parse_equality()
{
    return cc1_expression_parse_comma();
}

function cc1_expression_parse_primary_(token, kind, expression, first,
    last, argument, cast_token, cast_text, cast_length)
{
    token = cc1_preprocessed_consume();
    if (eq(token, 0)) {
        CC1_EXPRESSION_ERROR = 1;
        return 0;
    }
    kind = ri32(add(token, CC1_TOKEN_KIND_OFFSET));
    if (eq(kind, 40)) {
        cast_token = cc1_preprocessed_peek(0);
        if (not(eq(cast_token, 0))) {
            cast_text = ri32(add(cast_token, CC1_TOKEN_TEXT_OFFSET));
            cast_length = ri32(add(cast_token, CC1_TOKEN_LENGTH_OFFSET));
            if (cc1_declaration_type_word(cast_text, cast_length)) {
                while (not(eq(cc1_expression_token_kind(), 41))) {
                    cast_token = cc1_preprocessed_consume();
                    kind = ri32(add(cast_token, CC1_TOKEN_KIND_OFFSET));
                    cast_text = ri32(add(cast_token,
                        CC1_TOKEN_TEXT_OFFSET));
                    cast_length = ri32(add(cast_token,
                        CC1_TOKEN_LENGTH_OFFSET));
                    if (not(eq(kind, 42))) {
                        if (not(cc1_declaration_type_word(cast_text,
                            cast_length))) {
                            if (not(cc1_declaration_qualifier(cast_text,
                                cast_length))) {
                                CC1_EXPRESSION_ERROR = 1;
                                return 0;
                            }
                        }
                    }
                }
                cc1_preprocessed_consume();
                return cc1_expression_parse_unary();
            }
        }
        expression = cc1_expression_parse_equality();
        if (not(cc1_expression_accept(41))) {
            CC1_EXPRESSION_ERROR = 1;
            return 0;
        }
        return expression;
    }
    if (eq(kind, 2)) {
        if (eq(cc1_expression_token_kind(), 40)) {
            cc1_preprocessed_consume();
            first = 0;
            last = 0;
            if (not(eq(cc1_expression_token_kind(), 41))) {
                while (1) {
                    expression = cc1_expression_parse_assignment();
                    argument = cc1_expression_new(
                        CC1_EXPRESSION_ARGUMENT_KIND, token, expression, 0);
                    if (eq(first, 0)) {
                        first = argument;
                    } else {
                        wi32(add(last, CC1_EXPRESSION_RIGHT_OFFSET), argument);
                    }
                    last = argument;
                    if (not(cc1_expression_accept(44))) {
                        break;
                    }
                }
            }
            if (not(cc1_expression_accept(41))) {
                CC1_EXPRESSION_ERROR = 1;
                return 0;
            }
            return cc1_expression_new(CC1_EXPRESSION_CALL_KIND, token,
                first, 0);
        }
        return cc1_expression_new(CC1_EXPRESSION_ATOM_KIND, token, 0, 0);
    }
    if (eq(kind, 3)) {
        return cc1_expression_new(CC1_EXPRESSION_ATOM_KIND, token, 0, 0);
    }
    if (eq(kind, 4)) {
        return cc1_expression_new(CC1_EXPRESSION_ATOM_KIND, token, 0, 0);
    }
    CC1_EXPRESSION_ERROR = 1;
    return 0;
}

function cc1_expression_parse_primary()
{
    return cc1_expression_parse_primary_(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

function cc1_expression_parse_sizeof_(token, next_token, text, length,
    size, kind, operand)
{
    cc1_preprocessed_consume();
    size = 4;
    if (eq(cc1_expression_token_kind(), 40)) {
        next_token = cc1_preprocessed_peek(1);
        if (not(eq(next_token, 0))) {
            text = ri32(add(next_token, CC1_TOKEN_TEXT_OFFSET));
            length = ri32(add(next_token, CC1_TOKEN_LENGTH_OFFSET));
            if (cc1_declaration_type_word(text, length)) {
                cc1_preprocessed_consume();
                while (not(eq(cc1_expression_token_kind(), 41))) {
                    next_token = cc1_preprocessed_consume();
                    kind = ri32(add(next_token, CC1_TOKEN_KIND_OFFSET));
                    text = ri32(add(next_token, CC1_TOKEN_TEXT_OFFSET));
                    length = ri32(add(next_token, CC1_TOKEN_LENGTH_OFFSET));
                    if (eq(kind, 42)) {
                        size = 4;
                    } else if (cc1_text_equal(text, length, mks("char"))) {
                        size = 1;
                    } else if (cc1_text_equal(text, length, mks("short"))) {
                        size = 2;
                    } else if (cc1_declaration_type_word(text, length)) {
                    } else if (cc1_declaration_qualifier(text, length)) {
                    } else {
                        CC1_EXPRESSION_ERROR = 1;
                        return 0;
                    }
                }
                cc1_preprocessed_consume();
                return cc1_expression_new(CC1_EXPRESSION_CONSTANT_KIND,
                    token, size, 0);
            }
        }
    }
    operand = cc1_expression_parse_unary();
    if (eq(operand, 0)) {
        return 0;
    }
    return cc1_expression_new(CC1_EXPRESSION_CONSTANT_KIND, token, 4, 0);
}

function cc1_expression_parse_sizeof(token)
{
    return cc1_expression_parse_sizeof_(token, 0, 0, 0, 0, 0, 0);
}

function cc1_expression_parse_unary_(token, kind, expression)
{
    token = cc1_preprocessed_peek(0);
    kind = cc1_expression_token_kind();
    if (not(eq(token, 0))) {
        if (cc1_text_equal(ri32(add(token, CC1_TOKEN_TEXT_OFFSET)),
            ri32(add(token, CC1_TOKEN_LENGTH_OFFSET)), mks("sizeof"))) {
            return cc1_expression_parse_sizeof(token);
        }
    }
    if (eq(kind, 33)) {
        cc1_preprocessed_consume();
        expression = cc1_expression_parse_unary();
        return cc1_expression_new(CC1_EXPRESSION_NOT_KIND, token,
            expression, 0);
    }
    if (eq(kind, 45)) {
        cc1_preprocessed_consume();
        expression = cc1_expression_parse_unary();
        return cc1_expression_new(CC1_EXPRESSION_NEGATE_KIND, token,
            expression, 0);
    }
    if (eq(kind, 126)) {
        cc1_preprocessed_consume();
        expression = cc1_expression_parse_unary();
        return cc1_expression_new(CC1_EXPRESSION_COMPLEMENT_KIND, token,
            expression, 0);
    }
    if (eq(kind, 42)) {
        cc1_preprocessed_consume();
        expression = cc1_expression_parse_unary();
        return cc1_expression_new(CC1_EXPRESSION_DEREFERENCE_KIND, token,
            expression, 0);
    }
    if (eq(kind, 38)) {
        cc1_preprocessed_consume();
        expression = cc1_expression_parse_unary();
        return cc1_expression_new(CC1_EXPRESSION_ADDRESS_KIND, token,
            expression, 0);
    }
    return cc1_expression_parse_primary();
}

function cc1_expression_parse_unary()
{
    return cc1_expression_parse_unary_(0, 0, 0);
}

function cc1_expression_parse_multiplicative_(left, token, kind, right,
    expression_kind)
{
    left = cc1_expression_parse_unary();
    while (1) {
        kind = cc1_expression_token_kind();
        expression_kind = 0;
        if (eq(kind, 42)) {
            expression_kind = CC1_EXPRESSION_MULTIPLY_KIND;
        } else if (eq(kind, 47)) {
            expression_kind = CC1_EXPRESSION_DIVIDE_KIND;
        } else if (eq(kind, 37)) {
            expression_kind = CC1_EXPRESSION_REMAINDER_KIND;
        }
        if (eq(expression_kind, 0)) {
            return left;
        }
        token = cc1_preprocessed_consume();
        right = cc1_expression_parse_unary();
        left = cc1_expression_new(expression_kind, token,
            left, right);
    }
}

function cc1_expression_parse_multiplicative()
{
    return cc1_expression_parse_multiplicative_(0, 0, 0, 0, 0);
}

function cc1_expression_parse_additive_(left, token, kind, right,
    expression_kind)
{
    left = cc1_expression_parse_multiplicative();
    while (1) {
        token = cc1_preprocessed_peek(0);
        kind = cc1_expression_token_kind();
        expression_kind = 0;
        if (eq(kind, 43)) {
            expression_kind = CC1_EXPRESSION_ADD_KIND;
        } else if (eq(kind, 45)) {
            expression_kind = CC1_EXPRESSION_SUBTRACT_KIND;
        }
        if (eq(expression_kind, 0)) {
            return left;
        }
        cc1_preprocessed_consume();
        right = cc1_expression_parse_multiplicative();
        left = cc1_expression_new(expression_kind, token, left, right);
    }
}

function cc1_expression_parse_additive()
{
    return cc1_expression_parse_additive_(0, 0, 0, 0, 0);
}

function cc1_expression_parse_shift_(left, token, kind, right,
    expression_kind)
{
    left = cc1_expression_parse_additive();
    while (1) {
        token = cc1_preprocessed_peek(0);
        kind = cc1_expression_token_kind();
        expression_kind = 0;
        if (eq(kind, 60)) {
            cc1_preprocessed_consume();
            if (cc1_expression_accept(60)) {
                expression_kind = CC1_EXPRESSION_SHIFT_LEFT_KIND;
            } else {
                CC1_PREPROCESSED_CURSOR = sub(CC1_PREPROCESSED_CURSOR, 1);
            }
        } else if (eq(kind, 62)) {
            cc1_preprocessed_consume();
            if (cc1_expression_accept(62)) {
                expression_kind = CC1_EXPRESSION_SHIFT_RIGHT_KIND;
            } else {
                CC1_PREPROCESSED_CURSOR = sub(CC1_PREPROCESSED_CURSOR, 1);
            }
        }
        if (eq(expression_kind, 0)) {
            return left;
        }
        right = cc1_expression_parse_additive();
        left = cc1_expression_new(expression_kind, token, left, right);
    }
}

function cc1_expression_parse_shift()
{
    return cc1_expression_parse_shift_(0, 0, 0, 0, 0);
}

function cc1_expression_parse_relational_(left, token, kind, right,
    expression_kind, reverse)
{
    left = cc1_expression_parse_shift();
    while (1) {
        token = cc1_preprocessed_peek(0);
        kind = cc1_expression_token_kind();
        expression_kind = 0;
        reverse = 0;
        if (eq(kind, 60)) {
            expression_kind = CC1_EXPRESSION_LESS_KIND;
            cc1_preprocessed_consume();
            if (cc1_expression_accept(61)) {
                expression_kind = CC1_EXPRESSION_LESS_EQUAL_KIND;
            }
        } else if (eq(kind, 62)) {
            expression_kind = CC1_EXPRESSION_LESS_KIND;
            reverse = 1;
            cc1_preprocessed_consume();
            if (cc1_expression_accept(61)) {
                expression_kind = CC1_EXPRESSION_LESS_EQUAL_KIND;
            }
        }
        if (eq(expression_kind, 0)) {
            return left;
        }
        right = cc1_expression_parse_shift();
        if (reverse) {
            left = cc1_expression_new(expression_kind, token, right, left);
        } else {
            left = cc1_expression_new(expression_kind, token, left, right);
        }
    }
}

function cc1_expression_parse_relational()
{
    return cc1_expression_parse_relational_(0, 0, 0, 0, 0, 0);
}

function cc1_expression_parse_comparison_(left, token, kind, right)
{
    left = cc1_expression_parse_relational();
    while (1) {
        token = cc1_preprocessed_peek(0);
        kind = cc1_expression_token_kind();
        if (eq(kind, 61)) {
            cc1_preprocessed_consume();
            if (not(cc1_expression_accept(61))) {
                CC1_PREPROCESSED_CURSOR = sub(CC1_PREPROCESSED_CURSOR, 1);
                return left;
            }
            right = cc1_expression_parse_relational();
            left = cc1_expression_new(CC1_EXPRESSION_EQUAL_KIND, token,
                left, right);
        } else if (eq(kind, 33)) {
            cc1_preprocessed_consume();
            if (not(cc1_expression_accept(61))) {
                CC1_PREPROCESSED_CURSOR = sub(CC1_PREPROCESSED_CURSOR, 1);
                return left;
            }
            right = cc1_expression_parse_relational();
            right = cc1_expression_new(CC1_EXPRESSION_EQUAL_KIND, token,
                left, right);
            left = cc1_expression_new(CC1_EXPRESSION_NOT_KIND, token,
                right, 0);
        } else {
            return left;
        }
    }
}

function cc1_expression_parse_comparison()
{
    return cc1_expression_parse_comparison_(0, 0, 0, 0);
}

function cc1_expression_parse_bit_and_(left, token, right)
{
    left = cc1_expression_parse_comparison();
    while (eq(cc1_expression_token_kind(), 38)) {
        token = cc1_preprocessed_consume();
        if (eq(cc1_expression_token_kind(), 38)) {
            CC1_PREPROCESSED_CURSOR = sub(CC1_PREPROCESSED_CURSOR, 1);
            return left;
        }
        right = cc1_expression_parse_comparison();
        left = cc1_expression_new(CC1_EXPRESSION_BIT_AND_KIND, token,
            left, right);
    }
    return left;
}

function cc1_expression_parse_bit_and()
{
    return cc1_expression_parse_bit_and_(0, 0, 0);
}

function cc1_expression_parse_bit_xor_(left, token, right)
{
    left = cc1_expression_parse_bit_and();
    while (eq(cc1_expression_token_kind(), 94)) {
        token = cc1_preprocessed_consume();
        right = cc1_expression_parse_bit_and();
        left = cc1_expression_new(CC1_EXPRESSION_BIT_XOR_KIND, token,
            left, right);
    }
    return left;
}

function cc1_expression_parse_bit_xor()
{
    return cc1_expression_parse_bit_xor_(0, 0, 0);
}

function cc1_expression_parse_bit_or_(left, token, right)
{
    left = cc1_expression_parse_bit_xor();
    while (eq(cc1_expression_token_kind(), 124)) {
        token = cc1_preprocessed_consume();
        if (eq(cc1_expression_token_kind(), 124)) {
            CC1_PREPROCESSED_CURSOR = sub(CC1_PREPROCESSED_CURSOR, 1);
            return left;
        }
        right = cc1_expression_parse_bit_xor();
        left = cc1_expression_new(CC1_EXPRESSION_BIT_OR_KIND, token,
            left, right);
    }
    return left;
}

function cc1_expression_parse_bit_or()
{
    return cc1_expression_parse_bit_or_(0, 0, 0);
}

function cc1_expression_parse_logical_and_(left, token, right)
{
    left = cc1_expression_parse_bit_or();
    while (eq(cc1_expression_token_kind(), 38)) {
        token = cc1_preprocessed_consume();
        if (not(cc1_expression_accept(38))) {
            CC1_PREPROCESSED_CURSOR = sub(CC1_PREPROCESSED_CURSOR, 1);
            return left;
        }
        right = cc1_expression_parse_bit_or();
        left = cc1_expression_new(CC1_EXPRESSION_LOGICAL_AND_KIND, token,
            left, right);
    }
    return left;
}

function cc1_expression_parse_logical_and()
{
    return cc1_expression_parse_logical_and_(0, 0, 0);
}

function cc1_expression_parse_logical_or_(left, token, right)
{
    left = cc1_expression_parse_logical_and();
    while (eq(cc1_expression_token_kind(), 124)) {
        token = cc1_preprocessed_consume();
        if (not(cc1_expression_accept(124))) {
            CC1_PREPROCESSED_CURSOR = sub(CC1_PREPROCESSED_CURSOR, 1);
            return left;
        }
        right = cc1_expression_parse_logical_and();
        left = cc1_expression_new(CC1_EXPRESSION_LOGICAL_OR_KIND, token,
            left, right);
    }
    return left;
}

function cc1_expression_parse_logical_or()
{
    return cc1_expression_parse_logical_or_(0, 0, 0);
}

function cc1_expression_parse_conditional_(condition, token, when_true,
    when_false, choices)
{
    condition = cc1_expression_parse_logical_or();
    if (not(eq(cc1_expression_token_kind(), 63))) {
        return condition;
    }
    token = cc1_preprocessed_consume();
    when_true = cc1_expression_parse_assignment();
    if (not(cc1_expression_accept(58))) {
        CC1_EXPRESSION_ERROR = 1;
        return 0;
    }
    when_false = cc1_expression_parse_conditional();
    choices = cc1_expression_new(CC1_EXPRESSION_ARGUMENT_KIND, token,
        when_true, when_false);
    return cc1_expression_new(CC1_EXPRESSION_CONDITIONAL_KIND, token,
        condition, choices);
}

function cc1_expression_parse_conditional()
{
    return cc1_expression_parse_conditional_(0, 0, 0, 0, 0);
}

function cc1_expression_parse_assignment_(left, token, right)
{
    left = cc1_expression_parse_conditional();
    if (eq(cc1_expression_token_kind(), 61)) {
        token = cc1_preprocessed_consume();
        if (eq(cc1_expression_token_kind(), 61)) {
            CC1_PREPROCESSED_CURSOR = sub(CC1_PREPROCESSED_CURSOR, 1);
            return left;
        }
        right = cc1_expression_parse_assignment();
        return cc1_expression_new(CC1_EXPRESSION_ASSIGN_KIND, token,
            left, right);
    }
    return left;
}

function cc1_expression_parse_assignment()
{
    return cc1_expression_parse_assignment_(0, 0, 0);
}

function cc1_expression_parse_comma_(left, token, right)
{
    left = cc1_expression_parse_assignment();
    while (eq(cc1_expression_token_kind(), 44)) {
        token = cc1_preprocessed_consume();
        right = cc1_expression_parse_assignment();
        left = cc1_expression_new(CC1_EXPRESSION_COMMA_KIND, token,
            left, right);
    }
    return left;
}

function cc1_expression_parse_comma()
{
    return cc1_expression_parse_comma_(0, 0, 0);
}

function cc1_expression_emit_token_(token, kind, text, length, origin)
{
    kind = ri32(add(token, CC1_TOKEN_KIND_OFFSET));
    text = ri32(add(token, CC1_TOKEN_TEXT_OFFSET));
    length = ri32(add(token, CC1_TOKEN_LENGTH_OFFSET));
    origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
    if (eq(kind, 4)) {
        if (cc1_normalized_byte(34, origin)) {
            return 1;
        }
    }
    if (cc1_normalized_text(text, length, origin)) {
        return 1;
    }
    if (eq(kind, 4)) {
        return cc1_normalized_byte(34, add(origin, length));
    }
    return 0;
}

function cc1_expression_emit_token(token)
{
    return cc1_expression_emit_token_(token, 0, 0, 0, 0);
}

function cc1_expression_emit_name_(name, token, origin)
{
    origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
    return cc1_normalized_text(name, cc1_c_string_length(name), origin);
}

function cc1_expression_emit_name(name, token)
{
    return cc1_expression_emit_name_(name, token, 0);
}

function cc1_expression_emit_binary_(expression, name, token, left, right,
    origin)
{
    token = ri32(add(expression, CC1_EXPRESSION_TOKEN_OFFSET));
    left = ri32(add(expression, CC1_EXPRESSION_LEFT_OFFSET));
    right = ri32(add(expression, CC1_EXPRESSION_RIGHT_OFFSET));
    origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
    if (cc1_expression_emit_name(name, token)) {
        return 1;
    }
    if (cc1_normalized_byte(40, origin)) {
        return 1;
    }
    if (cc1_expression_emit(left)) {
        return 1;
    }
    if (cc1_normalized_byte(44, origin)) {
        return 1;
    }
    if (cc1_expression_emit(right)) {
        return 1;
    }
    return cc1_normalized_byte(41, origin);
}

function cc1_expression_emit_binary(expression, name)
{
    return cc1_expression_emit_binary_(expression, name, 0, 0, 0, 0);
}

function cc1_expression_emit_assignment_(expression, left, right, kind,
    token, origin)
{
    left = ri32(add(expression, CC1_EXPRESSION_LEFT_OFFSET));
    right = ri32(add(expression, CC1_EXPRESSION_RIGHT_OFFSET));
    kind = ri32(add(left, CC1_EXPRESSION_KIND_OFFSET));
    token = ri32(add(expression, CC1_EXPRESSION_TOKEN_OFFSET));
    origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
    if (eq(kind, CC1_EXPRESSION_ATOM_KIND)) {
        if (cc1_expression_emit_token(ri32(add(left,
            CC1_EXPRESSION_TOKEN_OFFSET)))) {
            return 1;
        }
        if (cc1_normalized_byte(61, origin)) {
            return 1;
        }
        return cc1_expression_emit(right);
    }
    if (not(eq(kind, CC1_EXPRESSION_DEREFERENCE_KIND))) {
        return 1;
    }
    if (cc1_expression_emit_name(mks("wi32"), token)) {
        return 1;
    }
    if (cc1_normalized_byte(40, origin)) {
        return 1;
    }
    if (cc1_expression_emit(ri32(add(left,
        CC1_EXPRESSION_LEFT_OFFSET)))) {
        return 1;
    }
    if (cc1_normalized_byte(44, origin)) {
        return 1;
    }
    if (cc1_expression_emit(right)) {
        return 1;
    }
    return cc1_normalized_byte(41, origin);
}

function cc1_expression_emit_assignment(expression)
{
    return cc1_expression_emit_assignment_(expression, 0, 0, 0, 0, 0);
}

function cc1_expression_emit_conditional_(expression, token, condition,
    choices, origin)
{
    token = ri32(add(expression, CC1_EXPRESSION_TOKEN_OFFSET));
    condition = ri32(add(expression, CC1_EXPRESSION_LEFT_OFFSET));
    choices = ri32(add(expression, CC1_EXPRESSION_RIGHT_OFFSET));
    origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
    if (cc1_expression_emit_name(mks("select"), token)) {
        return 1;
    }
    if (cc1_normalized_byte(40, origin)) {
        return 1;
    }
    if (cc1_expression_emit(condition)) {
        return 1;
    }
    if (cc1_normalized_byte(44, origin)) {
        return 1;
    }
    if (cc1_expression_emit(ri32(add(choices,
        CC1_EXPRESSION_LEFT_OFFSET)))) {
        return 1;
    }
    if (cc1_normalized_byte(44, origin)) {
        return 1;
    }
    if (cc1_expression_emit(ri32(add(choices,
        CC1_EXPRESSION_RIGHT_OFFSET)))) {
        return 1;
    }
    return cc1_normalized_byte(41, origin);
}

function cc1_expression_emit_conditional(expression)
{
    return cc1_expression_emit_conditional_(expression, 0, 0, 0, 0);
}

function cc1_normalized_set_token(token)
{
    CC1_NORMALIZED_CURRENT_FILE = ri32(add(token, CC1_TOKEN_FILE_OFFSET));
    CC1_NORMALIZED_CURRENT_LINE = ri32(add(token, CC1_TOKEN_LINE_OFFSET));
    CC1_NORMALIZED_CURRENT_COLUMN = ri32(add(token,
        CC1_TOKEN_COLUMN_OFFSET));
    return 0;
}

function cc1_expression_emit_(expression, kind, token, argument, origin)
{
    if (eq(expression, 0)) {
        return 1;
    }
    kind = ri32(add(expression, CC1_EXPRESSION_KIND_OFFSET));
    token = ri32(add(expression, CC1_EXPRESSION_TOKEN_OFFSET));
    cc1_normalized_set_token(token);
    if (eq(kind, CC1_EXPRESSION_CONSTANT_KIND)) {
        origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
        return cc1_normalized_byte(add(48, ri32(add(expression,
            CC1_EXPRESSION_LEFT_OFFSET))), origin);
    }
    if (eq(kind, CC1_EXPRESSION_ATOM_KIND)) {
        return cc1_expression_emit_token(token);
    }
    if (eq(kind, CC1_EXPRESSION_CALL_KIND)) {
        if (cc1_expression_emit_token(token)) {
            return 1;
        }
        origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
        if (cc1_normalized_byte(40, origin)) {
            return 1;
        }
        argument = ri32(add(expression, CC1_EXPRESSION_LEFT_OFFSET));
        while (not(eq(argument, 0))) {
            if (cc1_expression_emit(ri32(add(argument,
                CC1_EXPRESSION_LEFT_OFFSET)))) {
                return 1;
            }
            argument = ri32(add(argument, CC1_EXPRESSION_RIGHT_OFFSET));
            if (not(eq(argument, 0))) {
                if (cc1_normalized_byte(44, origin)) {
                    return 1;
                }
            }
        }
        return cc1_normalized_byte(41, origin);
    }
    if (eq(kind, CC1_EXPRESSION_ASSIGN_KIND)) {
        return cc1_expression_emit_assignment(expression);
    }
    if (eq(kind, CC1_EXPRESSION_CONDITIONAL_KIND)) {
        return cc1_expression_emit_conditional(expression);
    }
    if (eq(kind, CC1_EXPRESSION_ADD_KIND)) {
        return cc1_expression_emit_binary(expression, mks("add"));
    }
    if (eq(kind, CC1_EXPRESSION_SUBTRACT_KIND)) {
        return cc1_expression_emit_binary(expression, mks("sub"));
    }
    if (eq(kind, CC1_EXPRESSION_MULTIPLY_KIND)) {
        return cc1_expression_emit_binary(expression, mks("mul"));
    }
    if (eq(kind, CC1_EXPRESSION_DIVIDE_KIND)) {
        return cc1_expression_emit_binary(expression, mks("sdiv"));
    }
    if (eq(kind, CC1_EXPRESSION_REMAINDER_KIND)) {
        return cc1_expression_emit_binary(expression, mks("mod"));
    }
    if (eq(kind, CC1_EXPRESSION_SHIFT_LEFT_KIND)) {
        return cc1_expression_emit_binary(expression, mks("shl"));
    }
    if (eq(kind, CC1_EXPRESSION_SHIFT_RIGHT_KIND)) {
        return cc1_expression_emit_binary(expression, mks("shr"));
    }
    if (eq(kind, CC1_EXPRESSION_BIT_AND_KIND)) {
        return cc1_expression_emit_binary(expression, mks("and"));
    }
    if (eq(kind, CC1_EXPRESSION_BIT_XOR_KIND)) {
        return cc1_expression_emit_binary(expression, mks("xor"));
    }
    if (eq(kind, CC1_EXPRESSION_BIT_OR_KIND)) {
        return cc1_expression_emit_binary(expression, mks("or"));
    }
    if (eq(kind, CC1_EXPRESSION_LOGICAL_AND_KIND)) {
        return cc1_expression_emit_binary(expression, mks("land"));
    }
    if (eq(kind, CC1_EXPRESSION_LOGICAL_OR_KIND)) {
        return cc1_expression_emit_binary(expression, mks("lor"));
    }
    if (eq(kind, CC1_EXPRESSION_COMMA_KIND)) {
        return cc1_expression_emit_binary(expression, mks("comma"));
    }
    if (eq(kind, CC1_EXPRESSION_EQUAL_KIND)) {
        return cc1_expression_emit_binary(expression, mks("eq"));
    }
    if (eq(kind, CC1_EXPRESSION_LESS_KIND)) {
        return cc1_expression_emit_binary(expression, mks("lt"));
    }
    if (eq(kind, CC1_EXPRESSION_LESS_EQUAL_KIND)) {
        return cc1_expression_emit_binary(expression, mks("le"));
    }
    if (eq(kind, CC1_EXPRESSION_NOT_KIND)) {
        if (cc1_expression_emit_name(mks("not"), token)) {
            return 1;
        }
    } else if (eq(kind, CC1_EXPRESSION_NEGATE_KIND)) {
        if (cc1_expression_emit_name(mks("sub"), token)) {
            return 1;
        }
    } else if (eq(kind, CC1_EXPRESSION_COMPLEMENT_KIND)) {
        if (cc1_expression_emit_name(mks("bnot"), token)) {
            return 1;
        }
    } else if (eq(kind, CC1_EXPRESSION_DEREFERENCE_KIND)) {
        if (cc1_expression_emit_name(mks("ri32"), token)) {
            return 1;
        }
    } else if (eq(kind, CC1_EXPRESSION_ADDRESS_KIND)) {
        if (cc1_expression_emit_name(mks("addr"), token)) {
            return 1;
        }
    } else {
        return 1;
    }
    origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
    if (cc1_normalized_byte(40, origin)) {
        return 1;
    }
    if (eq(kind, CC1_EXPRESSION_NEGATE_KIND)) {
        if (cc1_normalized_byte(48, origin)) {
            return 1;
        }
        if (cc1_normalized_byte(44, origin)) {
            return 1;
        }
    }
    if (cc1_expression_emit(ri32(add(expression,
        CC1_EXPRESSION_LEFT_OFFSET)))) {
        return 1;
    }
    return cc1_normalized_byte(41, origin);
}

function cc1_expression_emit(expression)
{
    return cc1_expression_emit_(expression, 0, 0, 0, 0);
}

function cc1_declaration_type_word(text, length)
{
    if (cc1_text_equal(text, length, mks("void"))) {
        return 1;
    }
    if (cc1_text_equal(text, length, mks("char"))) {
        return 1;
    }
    if (cc1_text_equal(text, length, mks("short"))) {
        return 1;
    }
    if (cc1_text_equal(text, length, mks("int"))) {
        return 1;
    }
    if (cc1_text_equal(text, length, mks("long"))) {
        return 1;
    }
    if (cc1_text_equal(text, length, mks("signed"))) {
        return 1;
    }
    return cc1_text_equal(text, length, mks("unsigned"));
}

function cc1_declaration_qualifier(text, length)
{
    if (cc1_text_equal(text, length, mks("static"))) {
        return 1;
    }
    if (cc1_text_equal(text, length, mks("extern"))) {
        return 1;
    }
    if (cc1_text_equal(text, length, mks("const"))) {
        return 1;
    }
    if (cc1_text_equal(text, length, mks("volatile"))) {
        return 1;
    }
    if (cc1_text_equal(text, length, mks("register"))) {
        return 1;
    }
    return cc1_text_equal(text, length, mks("inline"));
}

function cc1_normalize_tokens_(index, token, kind, text, length, origin,
    header, next_token, following_token, skip, expression, declaration,
    declarator_index, declarator_token)
{
    CC1_NORMALIZED_LENGTH = 0;
    cc1_expression_init();
    index = 0;
    header = 0;
    declaration = 0;
    while (lt(index, CC1_PREPROCESSED_COUNT)) {
        token = ri32(add(CC1_PREPROCESSED_TOKENS, shl(index, 2)));
        kind = ri32(add(token, CC1_TOKEN_KIND_OFFSET));
        if (eq(kind, CC1_TOKEN_EOF)) {
            return 0;
        }
        cc1_normalized_set_token(token);
        origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
        if (cc1_normalized_byte(32, origin)) {
            return 1;
        }
        text = ri32(add(token, CC1_TOKEN_TEXT_OFFSET));
        length = ri32(add(token, CC1_TOKEN_LENGTH_OFFSET));
        skip = 0;
        if (cc1_text_equal(text, length, mks("for"))) {
            if (cc1_normalized_text(text, length, origin)) {
                return 1;
            }
            CC1_PREPROCESSED_CURSOR = add(index, 1);
            if (not(cc1_expression_accept(40))) {
                return 1;
            }
            if (cc1_normalized_byte(40, origin)) {
                return 1;
            }
            if (not(eq(cc1_expression_token_kind(), 59))) {
                expression = cc1_expression_parse_equality();
                if (cc1_expression_emit(expression)) {
                    return 1;
                }
            }
            if (not(cc1_expression_accept(59))) {
                return 1;
            }
            if (cc1_normalized_byte(59, origin)) {
                return 1;
            }
            if (not(eq(cc1_expression_token_kind(), 59))) {
                expression = cc1_expression_parse_equality();
                if (cc1_expression_emit(expression)) {
                    return 1;
                }
            }
            if (not(cc1_expression_accept(59))) {
                return 1;
            }
            if (cc1_normalized_byte(59, origin)) {
                return 1;
            }
            if (not(eq(cc1_expression_token_kind(), 41))) {
                expression = cc1_expression_parse_equality();
                if (cc1_expression_emit(expression)) {
                    return 1;
                }
            }
            if (not(cc1_expression_accept(41))) {
                return 1;
            }
            if (cc1_normalized_byte(41, origin)) {
                return 1;
            }
            index = sub(CC1_PREPROCESSED_CURSOR, 1);
            skip = 1;
        } else if (cc1_text_equal(text, length, mks("if"))) {
            if (not(lt(add(index, 2), CC1_PREPROCESSED_COUNT))) {
                return 1;
            }
            next_token = ri32(add(CC1_PREPROCESSED_TOKENS,
                shl(add(index, 1), 2)));
            if (not(eq(ri32(add(next_token, CC1_TOKEN_KIND_OFFSET)), 40))) {
                return 1;
            }
            if (cc1_normalized_text(text, length, origin)) {
                return 1;
            }
            if (cc1_normalized_byte(40, ri32(add(next_token,
                CC1_TOKEN_SOURCE_OFFSET)))) {
                return 1;
            }
            CC1_PREPROCESSED_CURSOR = add(index, 2);
            expression = cc1_expression_parse_equality();
            if (CC1_EXPRESSION_ERROR) {
                return 1;
            }
            if (cc1_expression_emit(expression)) {
                return 1;
            }
            if (not(cc1_expression_accept(41))) {
                return 1;
            }
            if (cc1_normalized_byte(41, origin)) {
                return 1;
            }
            index = sub(CC1_PREPROCESSED_CURSOR, 1);
            skip = 1;
        } else if (cc1_text_equal(text, length, mks("while"))) {
            if (not(lt(add(index, 2), CC1_PREPROCESSED_COUNT))) {
                return 1;
            }
            next_token = ri32(add(CC1_PREPROCESSED_TOKENS,
                shl(add(index, 1), 2)));
            if (not(eq(ri32(add(next_token, CC1_TOKEN_KIND_OFFSET)), 40))) {
                return 1;
            }
            if (cc1_normalized_text(text, length, origin)) {
                return 1;
            }
            if (cc1_normalized_byte(40, ri32(add(next_token,
                CC1_TOKEN_SOURCE_OFFSET)))) {
                return 1;
            }
            CC1_PREPROCESSED_CURSOR = add(index, 2);
            expression = cc1_expression_parse_equality();
            if (CC1_EXPRESSION_ERROR) {
                return 1;
            }
            if (cc1_expression_emit(expression)) {
                return 1;
            }
            if (not(cc1_expression_accept(41))) {
                return 1;
            }
            if (cc1_normalized_byte(41, origin)) {
                return 1;
            }
            index = sub(CC1_PREPROCESSED_CURSOR, 1);
            skip = 1;
        } else if (cc1_text_equal(text, length, mks("return"))) {
            if (cc1_normalized_text(text, length, origin)) {
                return 1;
            }
            if (cc1_normalized_byte(32, origin)) {
                return 1;
            }
            CC1_PREPROCESSED_CURSOR = add(index, 1);
            expression = cc1_expression_parse_equality();
            if (CC1_EXPRESSION_ERROR) {
                return 1;
            }
            if (cc1_expression_emit(expression)) {
                return 1;
            }
            index = sub(CC1_PREPROCESSED_CURSOR, 1);
            skip = 1;
        } else if (eq(kind, 42)) {
            if (not(declaration)) {
                CC1_PREPROCESSED_CURSOR = index;
                expression = cc1_expression_parse_equality();
                if (CC1_EXPRESSION_ERROR) {
                    return 1;
                }
                if (cc1_expression_emit(expression)) {
                    return 1;
                }
                index = sub(CC1_PREPROCESSED_CURSOR, 1);
                skip = 1;
            }
        } else if (eq(kind, 2)) {
            if (declaration) {
                if (not(cc1_declaration_type_word(text, length))) {
                    if (not(cc1_declaration_qualifier(text, length))) {
                        declaration = 0;
                    }
                }
            }
            if (lt(add(index, 1), CC1_PREPROCESSED_COUNT)) {
                next_token = ri32(add(CC1_PREPROCESSED_TOKENS,
                    shl(add(index, 1), 2)));
                if (eq(ri32(add(next_token, CC1_TOKEN_KIND_OFFSET)), 40)) {
                    if (not(header)) {
                        CC1_PREPROCESSED_CURSOR = index;
                        expression = cc1_expression_parse_equality();
                        if (CC1_EXPRESSION_ERROR) {
                            return 1;
                        }
                        if (cc1_expression_emit(expression)) {
                            return 1;
                        }
                        index = sub(CC1_PREPROCESSED_CURSOR, 1);
                        skip = 1;
                    }
                } else if (eq(ri32(add(next_token,
                    CC1_TOKEN_KIND_OFFSET)), 61)) {
                    if (not(lt(add(index, 2),
                        CC1_PREPROCESSED_COUNT))) {
                        return 1;
                    }
                    if (not(eq(ri32(add(ri32(add(CC1_PREPROCESSED_TOKENS,
                        shl(add(index, 2), 2))), CC1_TOKEN_KIND_OFFSET)),
                        61))) {
                        if (cc1_expression_emit_token(token)) {
                            return 1;
                        }
                        if (cc1_normalized_byte(61, ri32(add(next_token,
                            CC1_TOKEN_SOURCE_OFFSET)))) {
                            return 1;
                        }
                        CC1_PREPROCESSED_CURSOR = add(index, 2);
                        expression = cc1_expression_parse_equality();
                        if (CC1_EXPRESSION_ERROR) {
                            return 1;
                        }
                        if (cc1_expression_emit(expression)) {
                            return 1;
                        }
                        index = sub(CC1_PREPROCESSED_CURSOR, 1);
                        skip = 1;
                    }
                }
            }
        }
        if (skip) {
        } else if (cc1_declaration_qualifier(text, length)) {
            skip = 1;
        } else if (cc1_declaration_type_word(text, length)) {
            if (declaration) {
                skip = 1;
            } else {
                declaration = 1;
                if (header) {
                    skip = 1;
                } else {
                    declarator_index = add(index, 1);
                    while (lt(declarator_index, CC1_PREPROCESSED_COUNT)) {
                        declarator_token = ri32(add(CC1_PREPROCESSED_TOKENS,
                            shl(declarator_index, 2)));
                        if (eq(ri32(add(declarator_token,
                            CC1_TOKEN_KIND_OFFSET)), 42)) {
                            declarator_index = add(declarator_index, 1);
                        } else if (cc1_declaration_type_word(ri32(add(
                            declarator_token, CC1_TOKEN_TEXT_OFFSET)),
                            ri32(add(declarator_token,
                            CC1_TOKEN_LENGTH_OFFSET)))) {
                            declarator_index = add(declarator_index, 1);
                        } else {
                            break;
                        }
                    }
                    following_token = 0;
                    if (lt(add(declarator_index, 1),
                        CC1_PREPROCESSED_COUNT)) {
                        following_token = ri32(add(CC1_PREPROCESSED_TOKENS,
                            shl(add(declarator_index, 1), 2)));
                    }
                    if (not(eq(following_token, 0))) {
                        if (eq(ri32(add(following_token,
                            CC1_TOKEN_KIND_OFFSET)), 40)) {
                            text = mks("function");
                            length = 8;
                            header = 1;
                        } else {
                            text = mks("var");
                            length = 3;
                        }
                    } else {
                        return 1;
                    }
                }
            }
        } else if (declaration) {
            if (eq(kind, 42)) {
                skip = 1;
            } else if (eq(kind, 2)) {
                declaration = 0;
            }
        } else if (header) {
            if (cc1_text_equal(text, length, mks("void"))) {
                skip = 1;
            }
        }
        if (not(skip)) {
            if (eq(kind, 4)) {
                if (cc1_normalized_byte(34, origin)) {
                    return 1;
                }
            }
            if (cc1_normalized_text(text, length, origin)) {
                return 1;
            }
            if (eq(kind, 4)) {
                if (cc1_normalized_byte(34, add(origin, length))) {
                    return 1;
                }
            }
            if (eq(kind, 123)) {
                header = 0;
            }
        }
        index = add(index, 1);
    }
    return 1;
}

function cc1_normalize_tokens()
{
    return cc1_normalize_tokens_(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0);
}

function cc1_remap_frontend_error_(source, length, token, index)
{
    index = CC1_PREPROCESSED_CURSOR;
    if (not(eq(index, 0))) {
        index = sub(index, 1);
    }
    if (lt(index, CC1_PREPROCESSED_COUNT)) {
        token = ri32(add(CC1_PREPROCESSED_TOKENS, shl(index, 2)));
        return cc0_remap_error_location(source, length,
            ri32(add(token, CC1_TOKEN_SOURCE_OFFSET)),
            ri32(add(token, CC1_TOKEN_FILE_OFFSET)),
            ri32(add(token, CC1_TOKEN_LINE_OFFSET)),
            ri32(add(token, CC1_TOKEN_COLUMN_OFFSET)));
    }
    return cc0_remap_error(source, length, 0);
}

function cc1_remap_frontend_error(source, length)
{
    return cc1_remap_frontend_error_(source, length, 0, 0);
}

/* Compile an already preprocessed stream so higher layers can lower new syntax. */
function cc1_compile_preprocessed_(source, length, result, position, error_file,
    error_line, error_column, normalized_position)
{
    if (cc1_normalize_tokens()) {
        cc1_remap_frontend_error(source, length);
        return 1;
    }
    result = cc0_compile(CC1_NORMALIZED_SOURCE, CC1_NORMALIZED_LENGTH);
    if (result) {
        position = cc0_lexer_field(CC1_LEXER_FIELD_TEXT);
        position = sub(position, CC1_NORMALIZED_SOURCE);
        if (not(lt(position, CC1_NORMALIZED_LENGTH))) {
            position = sub(CC1_NORMALIZED_LENGTH, 1);
        }
        if (lt(position, 0)) {
            position = 0;
        }
        normalized_position = position;
        position = ri32(add(CC1_NORMALIZED_ORIGINS, shl(position, 2)));
        error_file = ri32(add(CC1_NORMALIZED_FILES,
            shl(normalized_position, 2)));
        error_line = ri32(add(CC1_NORMALIZED_LINES,
            shl(normalized_position, 2)));
        error_column = ri32(add(CC1_NORMALIZED_COLUMNS,
            shl(normalized_position, 2)));
        cc0_remap_error_location(source, length, position, error_file,
            error_line, error_column);
    }
    return result;
}

function cc1_compile_preprocessed(source, length)
{
    return cc1_compile_preprocessed_(source, length, 0, 0, 0, 0, 0, 0);
}

/* Higher layers use this API instead of depending on cc1's token storage. */
function cc1_layer_begin(source, length, file)
{
    if (cc1_preprocess(source, length, file)) {
        cc1_remap_frontend_error(source, length);
        return 1;
    }
    return 0;
}

function cc1_layer_finish(source, length)
{
    return cc1_compile_preprocessed(source, length);
}

function cc1_layer_fail(source, length)
{
    cc1_remap_frontend_error(source, length);
    return 1;
}

function cc1_layer_token_count()
{
    return CC1_PREPROCESSED_COUNT;
}

function cc1_layer_token_at(index)
{
    return ri32(add(CC1_PREPROCESSED_TOKENS, shl(index, 2)));
}

function cc1_layer_replace_tokens(tokens, count)
{
    CC1_PREPROCESSED_TOKENS = tokens;
    CC1_PREPROCESSED_COUNT = count;
    return 0;
}

function cc1_layer_token_field(token, field)
{
    return ri32(add(token, shl(field, 2)));
}

function cc1_layer_token_new(origin, kind, text, length, number)
{
    var token;
    token = malloc(shl(1, CC1_TOKEN_RECORD_SHIFT));
    if (eq(token, 0)) {
        return 0;
    }
    cc1_token_copy_bytes(token, origin, shl(1, CC1_TOKEN_RECORD_SHIFT));
    wi32(add(token, CC1_TOKEN_KIND_OFFSET), kind);
    wi32(add(token, CC1_TOKEN_TEXT_OFFSET), text);
    wi32(add(token, CC1_TOKEN_LENGTH_OFFSET), length);
    wi32(add(token, CC1_TOKEN_NUMBER_OFFSET), number);
    return token;
}

/* This is the permanent frontend dispatch point replaced by cc1_stubs in cc0. */
function cc1_compile_(source, length, file)
{
    if (cc1_preprocess(source, length, file)) {
        cc1_remap_frontend_error(source, length);
        return 1;
    }
    return cc1_compile_preprocessed(source, length);
}

function cc1_compile_base(source, length, file)
{
    return cc1_compile_(source, length, file);
}

/* cc2_stubs keeps cc1 standalone; the real cc2 object replaces that service. */
function cc1_compile(source, length, file)
{
    return cc2_compile(source, length, file);
}

function cc1_product_(left, right, result, index)
{
    result = 0;
    index = 0;
    while (lt(index, right)) {
        result = add(result, left);
        index = add(index, 1);
    }
    return result;
}

function cc1_product(left, right)
{
    return cc1_product_(left, right, 0, 0);
}

function cc1_type_record(index)
{
    return add(CC1_TYPES, shl(index, CC1_TYPE_RECORD_SHIFT));
}

function cc1_type_reserve_(needed, capacity, types, used)
{
    needed = shl(add(CC1_TYPE_COUNT, 1), CC1_TYPE_RECORD_SHIFT);
    if (le(needed, CC1_TYPE_CAPACITY)) {
        return 0;
    }
    capacity = CC1_TYPE_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    types = malloc(capacity);
    if (eq(types, 0)) {
        return 1;
    }
    used = shl(CC1_TYPE_COUNT, CC1_TYPE_RECORD_SHIFT);
    if (not(eq(CC1_TYPES, 0))) {
        cc1_token_copy_bytes(types, CC1_TYPES, used);
    }
    CC1_TYPES = types;
    CC1_TYPE_CAPACITY = capacity;
    return 0;
}

function cc1_type_reserve()
{
    return cc1_type_reserve_(0, 0, 0, 0);
}

function cc1_type_new_(kind, size, alignment, flags, base, count, type)
{
    if (cc1_type_reserve()) {
        return 0;
    }
    type = cc1_type_record(CC1_TYPE_COUNT);
    wi32(add(type, CC1_TYPE_KIND_OFFSET), kind);
    wi32(add(type, CC1_TYPE_SIZE_OFFSET), size);
    wi32(add(type, CC1_TYPE_ALIGNMENT_OFFSET), alignment);
    wi32(add(type, CC1_TYPE_FLAGS_OFFSET), flags);
    wi32(add(type, CC1_TYPE_BASE_OFFSET), base);
    wi32(add(type, CC1_TYPE_COUNT_OFFSET), count);
    CC1_TYPE_COUNT = add(CC1_TYPE_COUNT, 1);
    return type;
}

function cc1_type_new(kind, size, alignment, flags, base, count)
{
    return cc1_type_new_(kind, size, alignment, flags, base, count, 0);
}

function cc1_types_init()
{
    CC1_TYPE_RECORD_SHIFT = 5;
    CC1_TYPE_KIND_OFFSET = 0;
    CC1_TYPE_SIZE_OFFSET = 4;
    CC1_TYPE_ALIGNMENT_OFFSET = 8;
    CC1_TYPE_FLAGS_OFFSET = 12;
    CC1_TYPE_BASE_OFFSET = 16;
    CC1_TYPE_COUNT_OFFSET = 20;
    CC1_TYPE_VOID_KIND = 0;
    CC1_TYPE_CHAR_KIND = 1;
    CC1_TYPE_SHORT_KIND = 2;
    CC1_TYPE_INT_KIND = 3;
    CC1_TYPE_POINTER_KIND = 4;
    CC1_TYPE_ARRAY_KIND = 5;
    CC1_TYPE_FUNCTION_KIND = 6;
    CC1_TYPE_UNSIGNED_FLAG = 1;
    CC1_TYPE_COUNT = 0;
    CC1_VOID_TYPE = cc1_type_new(CC1_TYPE_VOID_KIND, 0, 1, 0, 0, 0);
    CC1_CHAR_TYPE = cc1_type_new(CC1_TYPE_CHAR_KIND, 1, 1, 0, 0, 0);
    CC1_UNSIGNED_CHAR_TYPE = cc1_type_new(CC1_TYPE_CHAR_KIND, 1, 1,
        CC1_TYPE_UNSIGNED_FLAG, 0, 0);
    CC1_SHORT_TYPE = cc1_type_new(CC1_TYPE_SHORT_KIND, 2, 2, 0, 0, 0);
    CC1_UNSIGNED_SHORT_TYPE = cc1_type_new(CC1_TYPE_SHORT_KIND, 2, 2,
        CC1_TYPE_UNSIGNED_FLAG, 0, 0);
    CC1_INT_TYPE = cc1_type_new(CC1_TYPE_INT_KIND, 4, 4, 0, 0, 0);
    CC1_UNSIGNED_INT_TYPE = cc1_type_new(CC1_TYPE_INT_KIND, 4, 4,
        CC1_TYPE_UNSIGNED_FLAG, 0, 0);
    return eq(CC1_UNSIGNED_INT_TYPE, 0);
}

function cc1_type_pointer(base)
{
    return cc1_type_new(CC1_TYPE_POINTER_KIND, 4, 4, 0, base, 0);
}

function cc1_type_array_(base, count, size)
{
    size = cc1_product(ri32(add(base, CC1_TYPE_SIZE_OFFSET)), count);
    return cc1_type_new(CC1_TYPE_ARRAY_KIND, size,
        ri32(add(base, CC1_TYPE_ALIGNMENT_OFFSET)), 0, base, count);
}

function cc1_type_array(base, count)
{
    return cc1_type_array_(base, count, 0);
}

function cc1_type_function(result_type, parameter_count)
{
    return cc1_type_new(CC1_TYPE_FUNCTION_KIND, 0, 1, 0, result_type,
        parameter_count);
}

function cc1_symbol_record(index)
{
    return add(CC1_SYMBOLS, shl(index, CC1_SYMBOL_RECORD_SHIFT));
}

function cc1_symbol_reserve_(needed, capacity, symbols, used)
{
    needed = shl(add(CC1_SYMBOL_COUNT, 1), CC1_SYMBOL_RECORD_SHIFT);
    if (le(needed, CC1_SYMBOL_CAPACITY)) {
        return 0;
    }
    capacity = CC1_SYMBOL_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    symbols = malloc(capacity);
    if (eq(symbols, 0)) {
        return 1;
    }
    used = shl(CC1_SYMBOL_COUNT, CC1_SYMBOL_RECORD_SHIFT);
    if (not(eq(CC1_SYMBOLS, 0))) {
        cc1_token_copy_bytes(symbols, CC1_SYMBOLS, used);
    }
    CC1_SYMBOLS = symbols;
    CC1_SYMBOL_CAPACITY = capacity;
    return 0;
}

function cc1_symbol_reserve()
{
    return cc1_symbol_reserve_(0, 0, 0, 0);
}

function cc1_scope_reserve_(needed, capacity, markers, used)
{
    needed = shl(add(CC1_SCOPE_DEPTH, 1), 2);
    if (le(needed, CC1_SCOPE_CAPACITY)) {
        return 0;
    }
    capacity = CC1_SCOPE_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    markers = malloc(capacity);
    if (eq(markers, 0)) {
        return 1;
    }
    used = shl(CC1_SCOPE_DEPTH, 2);
    if (not(eq(CC1_SCOPE_MARKERS, 0))) {
        cc1_token_copy_bytes(markers, CC1_SCOPE_MARKERS, used);
    }
    CC1_SCOPE_MARKERS = markers;
    CC1_SCOPE_CAPACITY = capacity;
    return 0;
}

function cc1_scope_reserve()
{
    return cc1_scope_reserve_(0, 0, 0, 0);
}

function cc1_symbols_init()
{
    CC1_SYMBOL_RECORD_SHIFT = 5;
    CC1_SYMBOL_NAME_OFFSET = 0;
    CC1_SYMBOL_LENGTH_OFFSET = 4;
    CC1_SYMBOL_TYPE_OFFSET = 8;
    CC1_SYMBOL_STORAGE_OFFSET = 12;
    CC1_SYMBOL_DEPTH_OFFSET = 16;
    CC1_SYMBOL_COUNT = 0;
    CC1_SCOPE_DEPTH = 0;
    return 0;
}

function cc1_symbol_lookup_(name, length, index, symbol)
{
    index = CC1_SYMBOL_COUNT;
    while (not(eq(index, 0))) {
        index = sub(index, 1);
        symbol = cc1_symbol_record(index);
        if (eq(ri32(add(symbol, CC1_SYMBOL_LENGTH_OFFSET)), length)) {
            if (cc1_slice_equal(name,
                ri32(add(symbol, CC1_SYMBOL_NAME_OFFSET)), length)) {
                return symbol;
            }
        }
    }
    return 0;
}

function cc1_symbol_lookup(name, length)
{
    return cc1_symbol_lookup_(name, length, 0, 0);
}

function cc1_symbol_define_(name, length, type, storage, existing, symbol)
{
    existing = cc1_symbol_lookup(name, length);
    if (not(eq(existing, 0))) {
        if (eq(ri32(add(existing, CC1_SYMBOL_DEPTH_OFFSET)),
            CC1_SCOPE_DEPTH)) {
            return 0;
        }
    }
    if (cc1_symbol_reserve()) {
        return 0;
    }
    symbol = cc1_symbol_record(CC1_SYMBOL_COUNT);
    wi32(add(symbol, CC1_SYMBOL_NAME_OFFSET), name);
    wi32(add(symbol, CC1_SYMBOL_LENGTH_OFFSET), length);
    wi32(add(symbol, CC1_SYMBOL_TYPE_OFFSET), type);
    wi32(add(symbol, CC1_SYMBOL_STORAGE_OFFSET), storage);
    wi32(add(symbol, CC1_SYMBOL_DEPTH_OFFSET), CC1_SCOPE_DEPTH);
    CC1_SYMBOL_COUNT = add(CC1_SYMBOL_COUNT, 1);
    return symbol;
}

function cc1_symbol_define(name, length, type, storage)
{
    return cc1_symbol_define_(name, length, type, storage, 0, 0);
}

function cc1_scope_push()
{
    if (cc1_scope_reserve()) {
        return 1;
    }
    wi32(add(CC1_SCOPE_MARKERS, shl(CC1_SCOPE_DEPTH, 2)), CC1_SYMBOL_COUNT);
    CC1_SCOPE_DEPTH = add(CC1_SCOPE_DEPTH, 1);
    return 0;
}

function cc1_scope_pop()
{
    if (eq(CC1_SCOPE_DEPTH, 0)) {
        return 1;
    }
    CC1_SCOPE_DEPTH = sub(CC1_SCOPE_DEPTH, 1);
    CC1_SYMBOL_COUNT = ri32(add(CC1_SCOPE_MARKERS,
        shl(CC1_SCOPE_DEPTH, 2)));
    return 0;
}

function cc1_c_string_length_(value, length)
{
    length = 0;
    while (not(eq(ri8(add(value, length)), 0))) {
        length = add(length, 1);
    }
    return length;
}

function cc1_c_string_length(value)
{
    return cc1_c_string_length_(value, 0);
}

function cc1_shell_argument_size_(value, index, size, character)
{
    index = 0;
    size = 3;
    while (not(eq(ri8(add(value, index)), 0))) {
        character = ri8(add(value, index));
        size = add(size, 1);
        if (eq(character, 39)) {
            size = add(size, 3);
        }
        index = add(index, 1);
    }
    return size;
}

function cc1_shell_argument_size(value)
{
    return cc1_shell_argument_size_(value, 0, 0, 0);
}

/* Single quotes preserve every byte; embedded quotes use the shell '\'' form. */
function cc1_append_shell_argument_(output, position, value, index, character)
{
    wi8(add(output, position), 39);
    position = add(position, 1);
    index = 0;
    while (not(eq(ri8(add(value, index)), 0))) {
        character = ri8(add(value, index));
        if (eq(character, 39)) {
            wi8(add(output, position), 39);
            wi8(add(output, add(position, 1)), 92);
            wi8(add(output, add(position, 2)), 39);
            wi8(add(output, add(position, 3)), 39);
            position = add(position, 4);
        } else {
            wi8(add(output, position), character);
            position = add(position, 1);
        }
        index = add(index, 1);
    }
    wi8(add(output, position), 39);
    return add(position, 1);
}

function cc1_append_shell_argument(output, position, value)
{
    return cc1_append_shell_argument_(output, position, value, 0, 0);
}

function cc1_copy_string_(output, position, value, index)
{
    index = 0;
    while (not(eq(ri8(add(value, index)), 0))) {
        wi8(add(output, position), ri8(add(value, index)));
        position = add(position, 1);
        index = add(index, 1);
    }
    return position;
}

function cc1_copy_string(output, position, value)
{
    return cc1_copy_string_(output, position, value, 0);
}

function cc1_find_output_(argc, argv, index, argument)
{
    index = 1;
    while (lt(add(index, 1), argc)) {
        argument = ri32(add(argv, shl(index, 2)));
        if (eq(ri8(argument), 45)) {
            if (eq(ri8(add(argument, 1)), 111)) {
                if (eq(ri8(add(argument, 2)), 0)) {
                    return ri32(add(argv, shl(add(index, 1), 2)));
                }
            }
        }
        index = add(index, 1);
    }
    return 0;
}

function cc1_find_output(argc, argv)
{
    return cc1_find_output_(argc, argv, 0, 0);
}

function cc1_link_(argc, argv, linker, runtime, capacity, index, argument,
    command, position, status, output)
{
    linker = mks("./tcc_27_layered_take2 -nostdlib crt1.o crti.o crtbegin.o");
    runtime = mks(" libc.so libgcc.a crtend.o crtn.o");
    capacity = add(cc1_c_string_length(linker),
        add(cc1_c_string_length(runtime), 1));
    index = 1;
    while (lt(index, argc)) {
        argument = ri32(add(argv, shl(index, 2)));
        capacity = add(capacity, cc1_shell_argument_size(argument));
        index = add(index, 1);
    }
    command = malloc(capacity);
    if (eq(command, 0)) {
        return 1;
    }
    position = cc1_copy_string(command, 0, linker);
    index = 1;
    while (lt(index, argc)) {
        wi8(add(command, position), 32);
        position = add(position, 1);
        argument = ri32(add(argv, shl(index, 2)));
        position = cc1_append_shell_argument(command, position, argument);
        index = add(index, 1);
    }
    position = cc1_copy_string(command, position, runtime);
    wi8(add(command, position), 0);
    status = system(command);
    if (not(eq(status, 0))) {
        return 1;
    }
    output = cc1_find_output(argc, argv);
    if (eq(output, 0)) {
        return 1;
    }
    status = chmod(output, 493);
    if (not(eq(status, 0))) {
        return 1;
    }
    return 0;
}

function cc1_link(argc, argv)
{
    return cc1_link_(argc, argv, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}
