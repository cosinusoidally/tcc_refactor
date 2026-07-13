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

function cc1_preprocess_tokens_(index, previous_line, token, line,
    directive, next_index)
{
    CC1_MACRO_COUNT = 0;
    CC1_PREPROCESSED_COUNT = 0;
    CC1_PREPROCESSED_CURSOR = 0;
    index = 0;
    previous_line = 0;
    while (lt(index, CC1_TOKEN_COUNT)) {
        token = cc1_token_record(index);
        line = ri32(add(token, CC1_TOKEN_LINE_OFFSET));
        if (eq(ri32(add(token, CC1_TOKEN_KIND_OFFSET)), 35)) {
            if (not(eq(line, previous_line))) {
                if (not(lt(add(index, 1), CC1_TOKEN_COUNT))) {
                    return 1;
                }
                directive = cc1_token_record(add(index, 1));
                if (cc1_text_equal(ri32(add(directive, CC1_TOKEN_TEXT_OFFSET)),
                    ri32(add(directive, CC1_TOKEN_LENGTH_OFFSET)),
                    mks("define"))) {
                    next_index = cc1_preprocess_define(index, line);
                } else if (cc1_text_equal(ri32(add(directive,
                    CC1_TOKEN_TEXT_OFFSET)), ri32(add(directive,
                    CC1_TOKEN_LENGTH_OFFSET)), mks("undef"))) {
                    next_index = cc1_preprocess_undef(index, line);
                } else {
                    return 1;
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
            if (cc1_macro_expand_token(token)) {
                return 1;
            }
            previous_line = line;
            index = add(index, 1);
        }
    }
    return 0;
}

function cc1_preprocess_tokens()
{
    return cc1_preprocess_tokens_(0, 0, 0, 0, 0, 0);
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
