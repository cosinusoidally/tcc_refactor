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
    wi32(add(record, CC1_TOKEN_SOURCE_OFFSET), source_offset);
    wi32(add(record, CC1_TOKEN_FILE_OFFSET), CC1_TOKEN_FILE);
    wi32(add(record, CC1_TOKEN_LINE_OFFSET), CC1_LOCATION_LINE);
    wi32(add(record, CC1_TOKEN_COLUMN_OFFSET), CC1_LOCATION_COLUMN);
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

function cc1_macro_define_(name, length, first_token, token_count, macro)
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
    return 0;
}

function cc1_macro_define(name, length, first_token, token_count)
{
    return cc1_macro_define_(name, length, first_token, token_count, 0);
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

function cc1_preprocess_define_(index, line, name_token, first, count)
{
    index = add(index, 2);
    if (not(lt(index, CC1_TOKEN_COUNT))) {
        return sub(0, 1);
    }
    name_token = cc1_token_record(index);
    if (not(eq(ri32(add(name_token, CC1_TOKEN_LINE_OFFSET)), line))) {
        return sub(0, 1);
    }
    first = add(index, 1);
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
        ri32(add(name_token, CC1_TOKEN_LENGTH_OFFSET)), first, count)) {
        return sub(0, 1);
    }
    return index;
}

function cc1_preprocess_define(index, line)
{
    return cc1_preprocess_define_(index, line, 0, 0, 0);
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
                if (cc1_macro_expand_token(token)) {
                    return 1;
                }
                previous_line = line;
                index = add(index, 1);
            }
        } else {
            if (active) {
                if (cc1_macro_expand_token(token)) {
                    return 1;
                }
            } else if (eq(kind, CC1_TOKEN_EOF)) {
                if (cc1_preprocessed_append(token)) {
                    return 1;
                }
            }
            previous_line = line;
            index = add(index, 1);
        }
    }
    return not(eq(CC1_CONDITION_DEPTH, 0));
}

function cc1_preprocess_tokens()
{
    return cc1_preprocess_tokens_(0, 0, 0, 0, 0, 0, 0, 0);
}

function cc1_preprocess(source, length, file)
{
    if (cc1_tokenize(source, length, file)) {
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

function cc1_normalized_reserve_(extra, needed, capacity, source, origins)
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
    if (eq(source, 0)) {
        return 1;
    }
    if (eq(origins, 0)) {
        return 1;
    }
    if (not(eq(CC1_NORMALIZED_SOURCE, 0))) {
        cc1_token_copy_bytes(source, CC1_NORMALIZED_SOURCE,
            CC1_NORMALIZED_LENGTH);
        cc1_token_copy_bytes(origins, CC1_NORMALIZED_ORIGINS,
            shl(CC1_NORMALIZED_LENGTH, 2));
    }
    CC1_NORMALIZED_SOURCE = source;
    CC1_NORMALIZED_ORIGINS = origins;
    CC1_NORMALIZED_CAPACITY = capacity;
    return 0;
}

function cc1_normalized_reserve(extra)
{
    return cc1_normalized_reserve_(extra, 0, 0, 0, 0);
}

function cc1_normalized_byte(value, origin)
{
    if (cc1_normalized_reserve(1)) {
        return 1;
    }
    wi8(add(CC1_NORMALIZED_SOURCE, CC1_NORMALIZED_LENGTH), value);
    wi32(add(CC1_NORMALIZED_ORIGINS, shl(CC1_NORMALIZED_LENGTH, 2)), origin);
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
        CC1_NORMALIZED_LENGTH = add(CC1_NORMALIZED_LENGTH, 1);
        index = add(index, 1);
    }
    return 0;
}

function cc1_normalized_text(text, length, origin)
{
    return cc1_normalized_text_(text, length, origin, 0);
}

function cc1_normalize_tokens_(index, token, kind, text, length, origin)
{
    CC1_NORMALIZED_LENGTH = 0;
    index = 0;
    while (lt(index, CC1_PREPROCESSED_COUNT)) {
        token = ri32(add(CC1_PREPROCESSED_TOKENS, shl(index, 2)));
        kind = ri32(add(token, CC1_TOKEN_KIND_OFFSET));
        if (eq(kind, CC1_TOKEN_EOF)) {
            return 0;
        }
        origin = ri32(add(token, CC1_TOKEN_SOURCE_OFFSET));
        if (cc1_normalized_byte(32, origin)) {
            return 1;
        }
        text = ri32(add(token, CC1_TOKEN_TEXT_OFFSET));
        length = ri32(add(token, CC1_TOKEN_LENGTH_OFFSET));
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
        index = add(index, 1);
    }
    return 1;
}

function cc1_normalize_tokens()
{
    return cc1_normalize_tokens_(0, 0, 0, 0, 0, 0);
}

/* This is the permanent frontend dispatch point replaced by cc1_stubs in cc0. */
function cc1_compile_(source, length, result, position)
{
    if (cc1_preprocess(source, length, mks("<cc1>"))) {
        return 1;
    }
    if (cc1_normalize_tokens()) {
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
        position = ri32(add(CC1_NORMALIZED_ORIGINS, shl(position, 2)));
        cc0_remap_error(source, length, position);
    }
    return result;
}

function cc1_compile(source, length)
{
    return cc1_compile_(source, length, 0, 0);
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
