/* Layer two owns typed syntax. It lowers that syntax into cc1's scalar C. */
var CC2_ENUM_RECORD_SHIFT;
var CC2_ENUM_NAME_OFFSET;
var CC2_ENUM_LENGTH_OFFSET;
var CC2_ENUM_VALUE_OFFSET;
var CC2_ENUMS;
var CC2_ENUM_CAPACITY;
var CC2_ENUM_COUNT;
var CC2_TOKENS;
var CC2_TOKEN_CAPACITY;
var CC2_TOKEN_COUNT;
var CC2_INTEGER_TEXT_BYTES;
var CC2_ENUM_PARSED_VALUE;
var CC2_INPUT_TOKEN_COUNT;
var CC2_TOKEN_KIND_FIELD;
var CC2_TOKEN_TEXT_FIELD;
var CC2_TOKEN_LENGTH_FIELD;
var CC2_TOKEN_NUMBER_FIELD;
var CC2_TYPEDEF_RECORD_SHIFT;
var CC2_TYPEDEF_NAME_OFFSET;
var CC2_TYPEDEF_LENGTH_OFFSET;
var CC2_TYPEDEFS;
var CC2_TYPEDEF_CAPACITY;
var CC2_TYPEDEF_COUNT;
var CC2_ARRAY_RECORD_SHIFT;
var CC2_ARRAY_NAME_OFFSET;
var CC2_ARRAY_LENGTH_OFFSET;
var CC2_ARRAY_ELEMENT_BYTES_OFFSET;
var CC2_ARRAYS;
var CC2_ARRAY_CAPACITY;
var CC2_ARRAY_COUNT;

function cc2_copy_bytes_(destination, source, length, index)
{
    index = 0;
    while (lt(index, length)) {
        wi8(add(destination, index), ri8(add(source, index)));
        index = add(index, 1);
    }
    return 0;
}

function cc2_copy_bytes(destination, source, length)
{
    return cc2_copy_bytes_(destination, source, length, 0);
}

function cc2_slice_equal_(left, right, length, index)
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

function cc2_slice_equal(left, right, length)
{
    return cc2_slice_equal_(left, right, length, 0);
}

function cc2_text_equal_(left, length, right, index)
{
    index = 0;
    while (lt(index, length)) {
        if (not(eq(ri8(add(left, index)), ri8(add(right, index))))) {
            return 0;
        }
        index = add(index, 1);
    }
    return eq(ri8(add(right, length)), 0);
}

function cc2_text_equal(left, length, right)
{
    return cc2_text_equal_(left, length, right, 0);
}

function cc2_enum_record(index)
{
    return add(CC2_ENUMS, shl(index, CC2_ENUM_RECORD_SHIFT));
}

function cc2_enum_reserve_(needed, capacity, records, used)
{
    needed = shl(add(CC2_ENUM_COUNT, 1), CC2_ENUM_RECORD_SHIFT);
    if (le(needed, CC2_ENUM_CAPACITY)) {
        return 0;
    }
    capacity = CC2_ENUM_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    records = alloc(capacity);
    if (eq(records, 0)) {
        return 1;
    }
    used = shl(CC2_ENUM_COUNT, CC2_ENUM_RECORD_SHIFT);
    if (not(eq(CC2_ENUMS, 0))) {
        cc2_copy_bytes(records, CC2_ENUMS, used);
    }
    CC2_ENUMS = records;
    CC2_ENUM_CAPACITY = capacity;
    return 0;
}

function cc2_enum_reserve()
{
    return cc2_enum_reserve_(0, 0, 0, 0);
}

function cc2_enum_define(name, length, value)
{
    var record;
    if (cc2_enum_reserve()) {
        return 1;
    }
    record = cc2_enum_record(CC2_ENUM_COUNT);
    wi32(add(record, CC2_ENUM_NAME_OFFSET), name);
    wi32(add(record, CC2_ENUM_LENGTH_OFFSET), length);
    wi32(add(record, CC2_ENUM_VALUE_OFFSET), value);
    CC2_ENUM_COUNT = add(CC2_ENUM_COUNT, 1);
    return 0;
}

function cc2_enum_lookup_(name, length, index, record)
{
    index = CC2_ENUM_COUNT;
    while (not(eq(index, 0))) {
        index = sub(index, 1);
        record = cc2_enum_record(index);
        if (eq(ri32(add(record, CC2_ENUM_LENGTH_OFFSET)), length)) {
            if (cc2_slice_equal(name,
                ri32(add(record, CC2_ENUM_NAME_OFFSET)), length)) {
                return record;
            }
        }
    }
    return 0;
}

function cc2_enum_lookup(name, length)
{
    return cc2_enum_lookup_(name, length, 0, 0);
}

function cc2_typedef_record(index)
{
    return add(CC2_TYPEDEFS, shl(index, CC2_TYPEDEF_RECORD_SHIFT));
}

function cc2_typedef_reserve_(needed, capacity, records, used)
{
    needed = shl(add(CC2_TYPEDEF_COUNT, 1), CC2_TYPEDEF_RECORD_SHIFT);
    if (le(needed, CC2_TYPEDEF_CAPACITY)) {
        return 0;
    }
    capacity = CC2_TYPEDEF_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    records = alloc(capacity);
    if (eq(records, 0)) {
        return 1;
    }
    used = shl(CC2_TYPEDEF_COUNT, CC2_TYPEDEF_RECORD_SHIFT);
    if (not(eq(CC2_TYPEDEFS, 0))) {
        cc2_copy_bytes(records, CC2_TYPEDEFS, used);
    }
    CC2_TYPEDEFS = records;
    CC2_TYPEDEF_CAPACITY = capacity;
    return 0;
}

function cc2_typedef_reserve()
{
    return cc2_typedef_reserve_(0, 0, 0, 0);
}

function cc2_typedef_define(name, length)
{
    var record;
    if (cc2_typedef_reserve()) {
        return 1;
    }
    record = cc2_typedef_record(CC2_TYPEDEF_COUNT);
    wi32(add(record, CC2_TYPEDEF_NAME_OFFSET), name);
    wi32(add(record, CC2_TYPEDEF_LENGTH_OFFSET), length);
    CC2_TYPEDEF_COUNT = add(CC2_TYPEDEF_COUNT, 1);
    return 0;
}

function cc2_typedef_lookup_(name, length, index, record)
{
    index = CC2_TYPEDEF_COUNT;
    while (not(eq(index, 0))) {
        index = sub(index, 1);
        record = cc2_typedef_record(index);
        if (eq(ri32(add(record, CC2_TYPEDEF_LENGTH_OFFSET)), length)) {
            if (cc2_slice_equal(name,
                ri32(add(record, CC2_TYPEDEF_NAME_OFFSET)), length)) {
                return record;
            }
        }
    }
    return 0;
}

function cc2_typedef_lookup(name, length)
{
    return cc2_typedef_lookup_(name, length, 0, 0);
}

function cc2_array_record(index)
{
    return add(CC2_ARRAYS, shl(index, CC2_ARRAY_RECORD_SHIFT));
}

function cc2_array_reserve_(needed, capacity, records, used)
{
    needed = shl(add(CC2_ARRAY_COUNT, 1), CC2_ARRAY_RECORD_SHIFT);
    if (le(needed, CC2_ARRAY_CAPACITY)) {
        return 0;
    }
    capacity = CC2_ARRAY_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    records = alloc(capacity);
    if (eq(records, 0)) {
        return 1;
    }
    used = shl(CC2_ARRAY_COUNT, CC2_ARRAY_RECORD_SHIFT);
    if (not(eq(CC2_ARRAYS, 0))) {
        cc2_copy_bytes(records, CC2_ARRAYS, used);
    }
    CC2_ARRAYS = records;
    CC2_ARRAY_CAPACITY = capacity;
    return 0;
}

function cc2_array_reserve()
{
    return cc2_array_reserve_(0, 0, 0, 0);
}

function cc2_array_define(name, length, element_bytes)
{
    var record;
    if (cc2_array_reserve()) {
        return 1;
    }
    record = cc2_array_record(CC2_ARRAY_COUNT);
    wi32(add(record, CC2_ARRAY_NAME_OFFSET), name);
    wi32(add(record, CC2_ARRAY_LENGTH_OFFSET), length);
    wi32(add(record, CC2_ARRAY_ELEMENT_BYTES_OFFSET), element_bytes);
    CC2_ARRAY_COUNT = add(CC2_ARRAY_COUNT, 1);
    return 0;
}

function cc2_array_lookup_(name, length, index, record)
{
    index = CC2_ARRAY_COUNT;
    while (not(eq(index, 0))) {
        index = sub(index, 1);
        record = cc2_array_record(index);
        if (eq(ri32(add(record, CC2_ARRAY_LENGTH_OFFSET)), length)) {
            if (cc2_slice_equal(name,
                ri32(add(record, CC2_ARRAY_NAME_OFFSET)), length)) {
                return record;
            }
        }
    }
    return 0;
}

function cc2_array_lookup(name, length)
{
    return cc2_array_lookup_(name, length, 0, 0);
}

function cc2_token_reserve_(needed, capacity, tokens, used)
{
    needed = shl(add(CC2_TOKEN_COUNT, 1), 2);
    if (le(needed, CC2_TOKEN_CAPACITY)) {
        return 0;
    }
    capacity = CC2_TOKEN_CAPACITY;
    if (eq(capacity, 0)) {
        capacity = 256;
    }
    while (lt(capacity, needed)) {
        capacity = shl(capacity, 1);
    }
    tokens = alloc(capacity);
    if (eq(tokens, 0)) {
        return 1;
    }
    used = shl(CC2_TOKEN_COUNT, 2);
    if (not(eq(CC2_TOKENS, 0))) {
        cc2_copy_bytes(tokens, CC2_TOKENS, used);
    }
    CC2_TOKENS = tokens;
    CC2_TOKEN_CAPACITY = capacity;
    return 0;
}

function cc2_token_reserve()
{
    return cc2_token_reserve_(0, 0, 0, 0);
}

function cc2_token_append(token)
{
    if (cc2_token_reserve()) {
        return 1;
    }
    wi32(add(CC2_TOKENS, shl(CC2_TOKEN_COUNT, 2)), token);
    CC2_TOKEN_COUNT = add(CC2_TOKEN_COUNT, 1);
    return 0;
}

function cc2_token_append_new(origin, kind, text, length, number)
{
    var token;
    token = cc1_layer_token_new(origin, kind, text, length, number);
    if (eq(token, 0)) {
        return 1;
    }
    return cc2_token_append(token);
}

function cc2_token_kind(token)
{
    return cc1_layer_token_field(token, CC2_TOKEN_KIND_FIELD);
}

function cc2_token_text(token)
{
    return cc1_layer_token_field(token, CC2_TOKEN_TEXT_FIELD);
}

function cc2_token_length(token)
{
    return cc1_layer_token_field(token, CC2_TOKEN_LENGTH_FIELD);
}

function cc2_token_number(token)
{
    return cc1_layer_token_field(token, CC2_TOKEN_NUMBER_FIELD);
}

function cc2_integer_token_(origin, value, token, text, position, magnitude,
    digit, start)
{
    text = alloc(CC2_INTEGER_TEXT_BYTES);
    if (eq(text, 0)) {
        return 0;
    }
    position = CC2_INTEGER_TEXT_BYTES;
    magnitude = value;
    if (lt(magnitude, 0)) {
        magnitude = sub(0, magnitude);
    }
    do {
        position = sub(position, 1);
        digit = mod(magnitude, 10);
        wi8(add(text, position), add(48, digit));
        magnitude = sdiv(magnitude, 10);
    } while (not(eq(magnitude, 0)));
    if (lt(value, 0)) {
        position = sub(position, 1);
        wi8(add(text, position), 45);
    }
    start = add(text, position);
    return cc1_layer_token_new(origin, 3, start,
        sub(CC2_INTEGER_TEXT_BYTES, position), value);
}

function cc2_integer_token(origin, value)
{
    return cc2_integer_token_(origin, value, 0, 0, 0, 0, 0, 0);
}

function cc2_int_token(origin)
{
    return cc1_layer_token_new(origin, 2, mks("int"), 3, 0);
}

function cc2_token_at(index)
{
    return cc1_layer_token_at(index);
}

function cc2_token_is_identifier(token, text)
{
    if (not(eq(cc2_token_kind(token), 2))) {
        return 0;
    }
    return cc2_text_equal(cc2_token_text(token),
        cc2_token_length(token), text);
}

function cc2_enum_atom_(index, sign, token, record, value)
{
    sign = 1;
    token = cc2_token_at(index);
    if (eq(cc2_token_kind(token), 45)) {
        sign = sub(0, 1);
        index = add(index, 1);
        token = cc2_token_at(index);
    }
    if (eq(cc2_token_kind(token), 3)) {
        value = cc2_token_number(token);
    } else if (eq(cc2_token_kind(token), 2)) {
        record = cc2_enum_lookup(cc2_token_text(token),
            cc2_token_length(token));
        if (eq(record, 0)) {
            return 0;
        }
        value = ri32(add(record, CC2_ENUM_VALUE_OFFSET));
    } else {
        return 0;
    }
    CC2_ENUM_PARSED_VALUE = mul(value, sign);
    return add(index, 1);
}

/* Parse the deliberately small constant-expression subset needed by enums. */
function cc2_enum_value(index)
{
    var end;
    var token;
    var operation;
    var left;
    end = cc2_enum_atom_(index, 0, 0, 0, 0);
    if (eq(end, 0)) {
        return 0;
    }
    left = CC2_ENUM_PARSED_VALUE;
    token = cc2_token_at(end);
    while (or(eq(cc2_token_kind(token), 43),
        eq(cc2_token_kind(token), 45))) {
        operation = cc2_token_kind(token);
        end = cc2_enum_atom_(add(end, 1), 0, 0, 0, 0);
        if (eq(end, 0)) {
            return 0;
        }
        if (eq(operation, 43)) {
            left = add(left, CC2_ENUM_PARSED_VALUE);
        } else {
            left = sub(left, CC2_ENUM_PARSED_VALUE);
        }
        token = cc2_token_at(end);
    }
    CC2_ENUM_PARSED_VALUE = left;
    return end;
}

function cc2_lower_enum_body_(index, token, next_value, value_end, value,
    record)
{
    next_value = 0;
    while (lt(index, CC2_INPUT_TOKEN_COUNT)) {
        token = cc2_token_at(index);
        if (eq(cc2_token_kind(token), 125)) {
            return add(index, 1);
        }
        if (not(eq(cc2_token_kind(token), 2))) {
            return 0;
        }
        value = next_value;
        index = add(index, 1);
        if (eq(cc2_token_kind(cc2_token_at(index)), 61)) {
            value_end = cc2_enum_value(add(index, 1));
            if (eq(value_end, 0)) {
                return 0;
            }
            value = CC2_ENUM_PARSED_VALUE;
            index = value_end;
        }
        if (cc2_enum_define(cc2_token_text(token),
            cc2_token_length(token), value)) {
            return 0;
        }
        next_value = add(value, 1);
        token = cc2_token_at(index);
        if (eq(cc2_token_kind(token), 44)) {
            index = add(index, 1);
        } else if (not(eq(cc2_token_kind(token), 125))) {
            return 0;
        }
    }
    return 0;
}

function cc2_lower_enum_body(index)
{
    return cc2_lower_enum_body_(index, 0, 0, 0, 0, 0);
}

function cc2_lower_enums_(index, token, next, after, record, replacement)
{
    index = 0;
    CC2_ENUM_COUNT = 0;
    CC2_TOKEN_COUNT = 0;
    CC2_INPUT_TOKEN_COUNT = cc1_layer_token_count();
    while (lt(index, CC2_INPUT_TOKEN_COUNT)) {
        token = cc2_token_at(index);
        if (cc2_token_is_identifier(token, mks("enum"))) {
            next = add(index, 1);
            if (eq(cc2_token_kind(cc2_token_at(next)), 2)) {
                next = add(next, 1);
            }
            if (eq(cc2_token_kind(cc2_token_at(next)), 123)) {
                after = cc2_lower_enum_body(add(next, 1));
                if (eq(after, 0)) {
                    return 1;
                }
                if (eq(cc2_token_kind(cc2_token_at(after)), 59)) {
                    index = add(after, 1);
                } else {
                    replacement = cc2_int_token(token);
                    if (eq(replacement, 0)) {
                        return 1;
                    }
                    if (cc2_token_append(replacement)) {
                        return 1;
                    }
                    index = after;
                }
            } else {
                replacement = cc2_int_token(token);
                if (eq(replacement, 0)) {
                    return 1;
                }
                if (cc2_token_append(replacement)) {
                    return 1;
                }
                index = next;
            }
        } else {
            record = 0;
            if (eq(cc2_token_kind(token), 2)) {
                record = cc2_enum_lookup(cc2_token_text(token),
                    cc2_token_length(token));
            }
            if (not(eq(record, 0))) {
                replacement = cc2_integer_token(token,
                    ri32(add(record, CC2_ENUM_VALUE_OFFSET)));
                if (eq(replacement, 0)) {
                    return 1;
                }
                token = replacement;
            }
            if (cc2_token_append(token)) {
                return 1;
            }
            index = add(index, 1);
        }
    }
    return cc1_layer_replace_tokens(CC2_TOKENS, CC2_TOKEN_COUNT);
}

function cc2_lower_enums()
{
    return cc2_lower_enums_(0, 0, 0, 0, 0, 0);
}

function cc2_lower_typedefs_(index, token, scan, candidate, record,
    replacement, depth, previous, next)
{
    index = 0;
    CC2_TYPEDEF_COUNT = 0;
    CC2_TOKEN_COUNT = 0;
    CC2_TOKENS = 0;
    CC2_TOKEN_CAPACITY = 0;
    CC2_INPUT_TOKEN_COUNT = cc1_layer_token_count();
    while (lt(index, CC2_INPUT_TOKEN_COUNT)) {
        token = cc2_token_at(index);
        if (cc2_token_is_identifier(token, mks("typedef"))) {
            scan = add(index, 1);
            candidate = 0;
            depth = 0;
            previous = 0;
            while (lt(scan, CC2_INPUT_TOKEN_COUNT)) {
                token = cc2_token_at(scan);
                if (eq(cc2_token_kind(token), 59)) {
                    break;
                }
                next = cc2_token_at(add(scan, 1));
                if (eq(cc2_token_kind(token), 40)) {
                    depth = add(depth, 1);
                } else if (eq(cc2_token_kind(token), 41)) {
                    depth = sub(depth, 1);
                }
                if (eq(cc2_token_kind(token), 2)) {
                    if (eq(depth, 0)) {
                        if (eq(cc2_token_kind(next), 59)) {
                            candidate = token;
                        }
                        if (eq(cc2_token_kind(next), 91)) {
                            candidate = token;
                        }
                    }
                    if (not(eq(previous, 0))) {
                        if (eq(cc2_token_kind(previous), 42)) {
                            if (eq(cc2_token_kind(next), 41)) {
                                candidate = token;
                            }
                        }
                    }
                }
                previous = token;
                scan = add(scan, 1);
            }
            if (eq(candidate, 0)) {
                return 1;
            }
            if (not(lt(scan, CC2_INPUT_TOKEN_COUNT))) {
                return 1;
            }
            if (cc2_typedef_define(cc2_token_text(candidate),
                cc2_token_length(candidate))) {
                return 1;
            }
            index = add(scan, 1);
        } else {
            record = 0;
            if (eq(cc2_token_kind(token), 2)) {
                record = cc2_typedef_lookup(cc2_token_text(token),
                    cc2_token_length(token));
            }
            if (not(eq(record, 0))) {
                replacement = cc2_int_token(token);
                if (eq(replacement, 0)) {
                    return 1;
                }
                token = replacement;
            }
            if (cc2_token_append(token)) {
                return 1;
            }
            index = add(index, 1);
        }
    }
    return cc1_layer_replace_tokens(CC2_TOKENS, CC2_TOKEN_COUNT);
}

function cc2_lower_typedefs()
{
    return cc2_lower_typedefs_(0, 0, 0, 0, 0, 0, 0, 0, 0);
}

function cc2_array_type_bytes(token)
{
    if (cc2_token_is_identifier(token, mks("char"))) {
        return 1;
    }
    if (cc2_token_is_identifier(token, mks("short"))) {
        return 2;
    }
    return 4;
}

function cc2_emit_array_declaration_(type_token, name_token, count_token,
    element_bytes, total_bytes, number_token)
{
    element_bytes = cc2_array_type_bytes(type_token);
    total_bytes = mul(element_bytes, cc2_token_number(count_token));
    if (cc2_array_define(cc2_token_text(name_token),
        cc2_token_length(name_token), element_bytes)) {
        return 1;
    }
    if (cc2_token_append_new(type_token, 2, mks("int"), 3, 0)) {
        return 1;
    }
    if (cc2_token_append(name_token)) {
        return 1;
    }
    if (cc2_token_append_new(name_token, 61, mks("="), 1, 0)) {
        return 1;
    }
    if (cc2_token_append_new(name_token, 2, mks("malloc"), 6, 0)) {
        return 1;
    }
    if (cc2_token_append_new(name_token, 40, mks("("), 1, 0)) {
        return 1;
    }
    number_token = cc2_integer_token(count_token, total_bytes);
    if (eq(number_token, 0)) {
        return 1;
    }
    if (cc2_token_append(number_token)) {
        return 1;
    }
    if (cc2_token_append_new(name_token, 41, mks(")"), 1, 0)) {
        return 1;
    }
    return cc2_token_append_new(name_token, 59, mks(";"), 1, 0);
}

function cc2_emit_array_declaration(type_token, name_token, count_token)
{
    return cc2_emit_array_declaration_(type_token, name_token, count_token,
        0, 0, 0);
}

function cc2_emit_array_access_(name_token, record, index, end, depth,
    token, scale_token)
{
    if (cc2_token_append_new(name_token, 42, mks("*"), 1, 0)) {
        return 0;
    }
    if (cc2_token_append_new(name_token, 40, mks("("), 1, 0)) {
        return 0;
    }
    if (cc2_token_append(name_token)) {
        return 0;
    }
    if (cc2_token_append_new(name_token, 43, mks("+"), 1, 0)) {
        return 0;
    }
    if (cc2_token_append_new(name_token, 40, mks("("), 1, 0)) {
        return 0;
    }
    index = add(index, 2);
    depth = 1;
    while (lt(index, CC2_INPUT_TOKEN_COUNT)) {
        token = cc2_token_at(index);
        if (eq(cc2_token_kind(token), 91)) {
            depth = add(depth, 1);
        } else if (eq(cc2_token_kind(token), 93)) {
            depth = sub(depth, 1);
            if (eq(depth, 0)) {
                break;
            }
        }
        if (cc2_token_append(token)) {
            return 0;
        }
        index = add(index, 1);
    }
    if (not(eq(depth, 0))) {
        return 0;
    }
    if (cc2_token_append_new(name_token, 42, mks("*"), 1, 0)) {
        return 0;
    }
    scale_token = cc2_integer_token(name_token,
        ri32(add(record, CC2_ARRAY_ELEMENT_BYTES_OFFSET)));
    if (eq(scale_token, 0)) {
        return 0;
    }
    if (cc2_token_append(scale_token)) {
        return 0;
    }
    if (cc2_token_append_new(name_token, 41, mks(")"), 1, 0)) {
        return 0;
    }
    if (cc2_token_append_new(name_token, 41, mks(")"), 1, 0)) {
        return 0;
    }
    return add(index, 1);
}

function cc2_emit_array_access(name_token, record, index)
{
    return cc2_emit_array_access_(name_token, record, index, 0, 0, 0, 0);
}

function cc2_lower_arrays_(index, token, next, after, record, end)
{
    index = 0;
    CC2_ARRAY_COUNT = 0;
    CC2_TOKEN_COUNT = 0;
    CC2_TOKENS = 0;
    CC2_TOKEN_CAPACITY = 0;
    CC2_INPUT_TOKEN_COUNT = cc1_layer_token_count();
    while (lt(index, CC2_INPUT_TOKEN_COUNT)) {
        token = cc2_token_at(index);
        next = token;
        after = token;
        if (lt(add(index, 1), CC2_INPUT_TOKEN_COUNT)) {
            next = cc2_token_at(add(index, 1));
        }
        if (lt(add(index, 2), CC2_INPUT_TOKEN_COUNT)) {
            after = cc2_token_at(add(index, 2));
        }
        if (lt(add(index, 5), CC2_INPUT_TOKEN_COUNT)) {
            if (eq(cc2_token_kind(token), 2)) {
                if (eq(cc2_token_kind(next), 2)) {
                    if (eq(cc2_token_kind(after), 91)) {
                        if (eq(cc2_token_kind(cc2_token_at(add(index, 3))),
                            3)) {
                            if (eq(cc2_token_kind(cc2_token_at(add(index, 4))),
                                93)) {
                                if (eq(cc2_token_kind(cc2_token_at(add(index,
                                    5))), 59)) {
                                    if (cc2_emit_array_declaration(token, next,
                                        cc2_token_at(add(index, 3)))) {
                                        return 1;
                                    }
                                    index = add(index, 6);
                                    token = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        if (eq(token, 0)) {
        } else {
            record = 0;
            if (eq(cc2_token_kind(token), 2)) {
                record = cc2_array_lookup(cc2_token_text(token),
                    cc2_token_length(token));
            }
            if (not(eq(record, 0))) {
                if (eq(cc2_token_kind(next), 91)) {
                    end = cc2_emit_array_access(token, record, index);
                    if (eq(end, 0)) {
                        return 1;
                    }
                    index = end;
                    token = 0;
                }
            }
            if (not(eq(token, 0))) {
                if (cc2_token_append(token)) {
                    return 1;
                }
                index = add(index, 1);
            }
        }
    }
    return cc1_layer_replace_tokens(CC2_TOKENS, CC2_TOKEN_COUNT);
}

function cc2_lower_arrays()
{
    return cc2_lower_arrays_(0, 0, 0, 0, 0, 0);
}

function cc2_init()
{
    CC2_ENUM_RECORD_SHIFT = 4;
    CC2_ENUM_NAME_OFFSET = 0;
    CC2_ENUM_LENGTH_OFFSET = 4;
    CC2_ENUM_VALUE_OFFSET = 8;
    CC2_INTEGER_TEXT_BYTES = 16;
    CC2_TOKEN_KIND_FIELD = 0;
    CC2_TOKEN_TEXT_FIELD = 1;
    CC2_TOKEN_LENGTH_FIELD = 2;
    CC2_TOKEN_NUMBER_FIELD = 3;
    CC2_TYPEDEF_RECORD_SHIFT = 3;
    CC2_TYPEDEF_NAME_OFFSET = 0;
    CC2_TYPEDEF_LENGTH_OFFSET = 4;
    CC2_ARRAY_RECORD_SHIFT = 4;
    CC2_ARRAY_NAME_OFFSET = 0;
    CC2_ARRAY_LENGTH_OFFSET = 4;
    CC2_ARRAY_ELEMENT_BYTES_OFFSET = 8;
    return 0;
}

function cc2_compile(source, length, file)
{
    cc2_init();
    if (cc1_layer_begin(source, length, file)) {
        return 1;
    }
    if (cc2_lower_enums()) {
        return cc1_layer_fail(source, length);
    }
    if (cc2_lower_typedefs()) {
        return cc1_layer_fail(source, length);
    }
    if (cc2_lower_arrays()) {
        return cc1_layer_fail(source, length);
    }
    return cc1_layer_finish(source, length);
}

/* Return log2(value) + 1 for positive values, or zero for zero. */
function exact_log2p1(value)
{
    var result;
    if (not(value)) {
        return 0;
    }
    result = 1;
    while (le(shl(1, 8), value)) {
        result = add(result, 8);
        value = shr(value, 8);
    }
    if (le(shl(1, 4), value)) {
        result = add(result, 4);
        value = shr(value, 4);
    }
    if (le(shl(1, 2), value)) {
        result = add(result, 2);
        value = shr(value, 2);
    }
    if (le(shl(1, 1), value)) {
        result = add(result, 1);
    }
    return result;
}
