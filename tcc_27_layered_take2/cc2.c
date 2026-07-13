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
/* Stable TCC CType basic-type encoding used at the cc2/remainder boundary. */
var CC2_TCC_BASIC_TYPE_MASK = 15;
var CC2_TCC_BYTE_TYPE = 1;
var CC2_TCC_SHORT_TYPE = 2;
var CC2_TCC_INT_TYPE = 3;
var CC2_TCC_LONG_LONG_TYPE = 4;
var CC2_TCC_FLOAT_TYPE = 8;
var CC2_TCC_DOUBLE_TYPE = 9;
var CC2_TCC_LONG_DOUBLE_TYPE = 10;
var CC2_TCC_QUAD_FLOAT_TYPE = 14;
var CC2_I386_FLOAT_RETURN_CLASS = 8;
var CC2_I386_FLOAT_RETURN_REGISTER = 4;
var CC2_I386_INTEGER_RETURN_REGISTER = 0;
var CC2_I386_LONG_LONG_RETURN_REGISTER = 2;
var CC2_I386_LONG_LONG_RETURN_CLASS = 32;
var CC2_I386_FLOAT_REGISTER_CLASS = 2;
/* TCC's i386 Sym layout and its existing 8192-byte allocation policy. */
var CC2_SYM_BYTES = 36;
var CC2_SYM_POOL_BYTES = 8192;
var CC2_SYM_NEXT_OFFSET = 24;
var CC2_SYM_PREV_OFFSET = 28;
var CC2_SYM_VALUE_OFFSET = 0;
var CC2_SYM_TYPE_OFFSET = 16;
var CC2_SYM_CONSTANT_OFFSET = 8;
var CC2_SYM_SCOPE_OFFSET = 12;
var CC2_SYM_TYPE_REFERENCE_OFFSET = 20;
var CC2_SYM_PREVIOUS_TOKEN_OFFSET = 32;
var CC2_TOKEN_SYMBOL_STRUCT_OFFSET = 12;
var CC2_TOKEN_SYMBOL_IDENTIFIER_OFFSET = 16;
var CC2_TOKEN_IDENTIFIER_BASE = 256;
var CC2_SYMBOL_STRUCT_FLAG = 1073741824;
var CC2_SYMBOL_FIELD_FLAG = 536870912;
var CC2_FIRST_ANONYMOUS_SYMBOL = 268435456;
var CC2_SVALUE_BYTES = 28;
var CC2_SVALUE_REGISTER_OFFSET = 8;
var CC2_SVALUE_CONSTANT_OFFSET = 12;
var CC2_SVALUE_SYMBOL_OFFSET = 24;
var CC2_VALUE_LOCATION_MASK = 63;
var CC2_VALUE_CONSTANT = 48;
var CC2_VALUE_COMPARISON = 51;
var CC2_VALUE_JUMP = 52;
var CC2_INTEGER_REGISTER_CLASS = 1;
var CC2_TCC_POINTER_TYPE = 5;
var CC2_TCC_VOID_TYPE = 0;
var CC2_TCC_BOOLEAN_TYPE = 11;
var CC2_TCC_UNSIGNED_TYPE = 16;
var CC2_TCC_STORAGE_MASK = 61440;
var CC2_TCC_LVALUE = 256;
var CC2_TCC_LVALUE_BYTE = 4096;
var CC2_TCC_LVALUE_SHORT = 8192;
var CC2_TCC_LVALUE_UNSIGNED = 16384;
var CC2_TCC_EXTERN_STORAGE = 4096;
var CC2_TCC_STATIC_STORAGE = 8192;
var CC2_TCC_SYMBOL_VALUE = 512;
var CC2_TCC_ASSEMBLER_TYPE = 16;
var CC2_I386_POP_FLOAT_STACK = 55517;
var CC2_VALUE_LOCAL_LVALUE = 49;
var CC2_VALUE_LOCAL = 50;
var CC2_VALUE_LVALUE_TYPE_MASK = 28672;
var CC2_I386_REGISTER_COUNT = 5;
var CC2_I386_EAX_CLASS = 5;
var CC2_I386_INTEGER_RETURN_CLASS = 4;
var CC2_I386_ECX_CLASS = 17;
var CC2_I386_EDX_CLASS = 33;
var CC2_I386_EBX_CLASS = 0;
var CC2_I386_ST0_CLASS = 10;
var CC2_TCC_TYPE_MASK = 986943;
var CC2_TCC_DEFAULT_SIGN = 32;
var CC2_TCC_CONST_QUALIFIER = 256;
var CC2_TCC_VOLATILE_QUALIFIER = 512;
var CC2_TCC_STRUCT_TYPE = 7;
var CC2_TCC_FUNCTION_TYPE = 6;
var CC2_TCC_OLD_FUNCTION = 2;
var CC2_SYM_FUNCTION_ATTRIBUTES_OFFSET = 12;
var CC2_TCC_ARRAY_TYPE = 64;
var CC2_TCC_ENUM_TYPE = 2097152;
var CC2_TCC_QUAD_INTEGER_TYPE = 13;
var CC2_I386_LONG_DOUBLE_BYTES = 12;
var CC2_I386_WORD_BYTES = 4;
var CC2_TCC_VLA_TYPE = 1024;
var CC2_TYPE_ALIGNMENT_TEMPORARY;
var CC2_COMPARISON_TYPES_TEMPORARY;
var CC2_VALUE_BOUNDED = 32768;
var CC2_TCC_INLINE_STORAGE = 32768;
var CC2_SYM_ATTRIBUTE_ALIGNED_MASK = 31;
var CC2_SYM_ATTRIBUTE_WEAK = 64;
var CC2_SYM_ATTRIBUTE_VISIBILITY_MASK = 384;
var CC2_ASCII_PERCENT = 37;
var CC2_ASCII_AMPERSAND = 38;
var CC2_ASCII_ASTERISK = 42;
var CC2_ASCII_PLUS = 43;
var CC2_ASCII_MINUS = 45;
var CC2_ASCII_SLASH = 47;
var CC2_ASCII_CARET = 94;
var CC2_ASCII_VERTICAL_BAR = 124;
var CC2_TOKEN_SHIFT_LEFT = 1;
var CC2_TOKEN_SHIFT_RIGHT = 2;
var CC2_TOKEN_UNSIGNED_LESS = 146;
var CC2_TOKEN_UNSIGNED_GREATER_EQUAL = 147;
var CC2_TOKEN_EQUAL = 148;
var CC2_TOKEN_NOT_EQUAL = 149;
var CC2_TOKEN_UNSIGNED_LESS_EQUAL = 150;
var CC2_TOKEN_GREATER = 159;
var CC2_TOKEN_LOGICAL_AND = 160;
var CC2_TOKEN_LOGICAL_OR = 161;
var CC2_VALUE_TEST_MASK = 831;
var CC2_VALUE_JUMP_FALSE = 53;
var CC2_TRUE = 1;
var CC2_TCC_BITFIELD = 128;
var CC2_TCC_MUST_CAST = 1024;
var CC2_TCC_ELLIPSIS_FUNCTION = 3;
var CC2_ASCII_COMMA = 44;
var CC2_ASCII_ASSIGN = 61;
var CC2_ASSIGNMENT_MODULO = 165;
var CC2_ASSIGNMENT_DIVIDE = 175;
var CC2_ASSIGNMENT_SHIFT_LEFT = 129;
var CC2_ASSIGNMENT_SHIFT_RIGHT = 130;
var CC2_ASSIGNMENT_XOR = 222;
var CC2_ASSIGNMENT_OR = 252;
var CC2_TOKEN_OPERATOR_MASK = 127;
var CC2_TOKEN_SIGNED_LESS = 156;
var CC2_TOKEN_SIGNED_GREATER_EQUAL = 157;
var CC2_TOKEN_SIGNED_LESS_EQUAL = 158;
var CC2_TOKEN_SIGNED_GREATER = 159;
var CC2_TOKEN_UNSIGNED_GREATER = 151;
var CC2_TOKEN_UNSIGNED_DIVIDE = 176;
var CC2_TOKEN_UNSIGNED_MODULO = 177;
var CC2_TOKEN_POINTER_DIVIDE = 178;
var CC2_TOKEN_UNSIGNED_SHIFT_RIGHT = 201;
var CC2_TCC_UNION_TYPE = 1048583;
var CC2_TCC_BITFIELD_POSITION_SHIFT = 20;
var CC2_TCC_BITFIELD_SIZE_SHIFT = 26;
var CC2_TCC_BITFIELD_VALUE_MASK = 63;
var CC2_TCC_BITFIELD_POSITION_MASK = 66060288;
var CC2_SYM_ATTRIBUTE_PACKED = 32;
var CC2_TOKEN_FLOAT_UNSIGNED_LONG_LONG_TO_FLOAT = 396;
var CC2_TOKEN_FLOAT_UNSIGNED_LONG_LONG_TO_DOUBLE = 397;
var CC2_TOKEN_FLOAT_UNSIGNED_LONG_LONG_TO_LONG_DOUBLE = 398;
var CC2_TOKEN_FLOAT_TO_UNSIGNED_LONG_LONG = 400;
var CC2_TOKEN_DOUBLE_TO_UNSIGNED_LONG_LONG = 401;
var CC2_TOKEN_LONG_DOUBLE_TO_UNSIGNED_LONG_LONG = 399;
var CC2_TOKEN_MEMMOVE = 387;
var CC2_TOKEN_SIGNED_LONG_LONG_DIVIDE = 389;
var CC2_TOKEN_UNSIGNED_LONG_LONG_DIVIDE = 391;
var CC2_TOKEN_SIGNED_LONG_LONG_MODULO = 390;
var CC2_TOKEN_UNSIGNED_LONG_LONG_MODULO = 392;
var CC2_TOKEN_ARITHMETIC_SHIFT_RIGHT_LONG_LONG = 393;
var CC2_TOKEN_LOGICAL_SHIFT_RIGHT_LONG_LONG = 394;
var CC2_TOKEN_SHIFT_LEFT_LONG_LONG = 395;
var CC2_TOKEN_UNSIGNED_MULTIPLY_LONG_LONG = 194;
var CC2_TOKEN_ADD_CARRY_FIRST = 195;
var CC2_TOKEN_SUBTRACT_CARRY_FIRST = 197;
var CC2_EXPRESSION_MODE_COMMA = 0;
var CC2_EXPRESSION_MODE_UNARY = 1;
var CC2_EXPRESSION_MODE_EQUALITY = 2;
var CC2_TOKEN_ATTRIBUTE_FIRST = 303;
var CC2_TOKEN_ATTRIBUTE_SECOND = 304;
var CC2_TOKEN_IDENTIFIER = 256;
var CC2_TOKEN_SECTION_FIRST = 338;
var CC2_TOKEN_SECTION_SECOND = 339;
var CC2_TOKEN_ALIAS_FIRST = 346;
var CC2_TOKEN_ALIAS_SECOND = 347;
var CC2_TOKEN_VISIBILITY_FIRST = 371;
var CC2_TOKEN_VISIBILITY_SECOND = 372;
var CC2_TOKEN_ALIGNED_FIRST = 340;
var CC2_TOKEN_ALIGNED_SECOND = 341;
var CC2_TOKEN_PACKED_FIRST = 342;
var CC2_TOKEN_PACKED_SECOND = 343;
var CC2_TOKEN_WEAK_FIRST = 344;
var CC2_TOKEN_WEAK_SECOND = 345;
var CC2_TOKEN_UNUSED_FIRST = 348;
var CC2_TOKEN_UNUSED_SECOND = 349;
var CC2_TOKEN_NORETURN_FIRST = 369;
var CC2_TOKEN_NORETURN_SECOND = 370;
var CC2_TOKEN_CDECL_FIRST = 350;
var CC2_TOKEN_CDECL_SECOND = 351;
var CC2_TOKEN_CDECL_THIRD = 352;
var CC2_TOKEN_STDCALL_FIRST = 353;
var CC2_TOKEN_STDCALL_SECOND = 354;
var CC2_TOKEN_STDCALL_THIRD = 355;
var CC2_TOKEN_REGPARM_FIRST = 359;
var CC2_TOKEN_REGPARM_SECOND = 360;
var CC2_TOKEN_FASTCALL_FIRST = 356;
var CC2_TOKEN_FASTCALL_SECOND = 357;
var CC2_TOKEN_FASTCALL_THIRD = 358;
var CC2_TOKEN_MODE = 361;
var CC2_TOKEN_MODE_QI = 362;
var CC2_TOKEN_MODE_DI = 363;
var CC2_TOKEN_MODE_HI = 364;
var CC2_TOKEN_MODE_SI = 365;
var CC2_TOKEN_MODE_WORD = 366;
var CC2_TOKEN_DLLEXPORT = 367;
var CC2_TOKEN_DLLIMPORT = 368;
var CC2_ATTRIBUTE_SECTION_OFFSET = 8;
var CC2_ATTRIBUTE_ALIAS_OFFSET = 12;
var CC2_ATTRIBUTE_MODE_OFFSET = 20;
var CC2_ATTRIBUTE_ALIGNED_MASK = 31;
var CC2_ATTRIBUTE_PACKED = 32;
var CC2_ATTRIBUTE_WEAK = 64;
var CC2_ATTRIBUTE_VISIBILITY_MASK = 384;
var CC2_ATTRIBUTE_VISIBILITY_SHIFT = 7;
var CC2_ATTRIBUTE_DLLEXPORT = 512;
var CC2_ATTRIBUTE_DLLIMPORT = 1024;
var CC2_FUNCTION_CALL_MASK = 7;
var CC2_FUNCTION_STDCALL = 1;
var CC2_FUNCTION_FASTCALL_FIRST = 2;
var CC2_FUNCTION_FASTCALL_WINDOWS = 5;

/* Production frontend state shared with the typed TCC remainder. */
var nb_sym_pools;
var rsym;
var anon_sym;
var ind;
var loc;
var local_scope;
var in_sizeof;
var section_sym;
var vlas_in_scope;
var vla_sp_root_loc;
var vla_sp_loc;
var const_wanted;
var nocode_wanted;
var global_expr;
var func_var;
var func_vc;
var last_line_num;
var last_ind;
var func_ind;
var g_debug;
/* Opaque i386 pointers are one word; their structures remain typed in TCC. */
var sym_free_first;
var sym_pools;
var global_stack;
var local_stack;
var define_stack;
var global_label_stack;
var local_label_stack;
var vtop;
var pvtop;
var vstack_base;
var vstack_limit;
var funcname;
var cur_switch;
var tok_ident;
var tok_address;
var data_section_address;
var tcc_state_address;
/* Verified with offsetof(TCCState, warn_unsupported) for i386. */
var CC2_TCC_STATE_WARN_UNSUPPORTED_OFFSET = 80;
var table_ident;
/* CType is two i386 words. */
var char_pointer_type[2];
var func_old_type[2];
var int_type[2];
var size_type[2];
var ptrdiff_type[2];
var int_type_address;
var size_type_address;
var func_old_type_address;
var ptrdiff_type_address;
/* TCC's 257-entry value stack, with seven i386 words per SValue. */
var __vstack[1799];
/* Scratch space is safe because TCC's frontend and value stack are global. */
var CC2_SVALUE_TEMPORARY;

function cc2_zero_bytes_(address, length, index)
{
    index = 0;
    while (lt(index, length)) {
        wi8(add(address, index), 0);
        index = add(index, 1);
    }
    return 0;
}

function cc2_zero_bytes(address, length)
{
    return cc2_zero_bytes_(address, length, 0);
}

/* Grow the pool pointer vector with the same power-of-two rule as TCC. */
function cc2_add_sym_pool_(pool, count, capacity, pools)
{
    count = nb_sym_pools;
    pools = sym_pools;
    if (eq(and(count, sub(count, 1)), 0)) {
        capacity = 1;
        if (not(eq(count, 0))) {
            capacity = mul(count, 2);
        }
        pools = realloc(pools, mul(capacity, 4));
        sym_pools = pools;
    }
    wi32(add(pools, mul(count, 4)), pool);
    nb_sym_pools = add(count, 1);
    return 0;
}

function cc2_add_sym_pool(pool)
{
    return cc2_add_sym_pool_(pool, 0, 0, 0);
}

function __sym_malloc_(pool, symbol, last_symbol, index, symbol_count)
{
    symbol_count = sdiv(CC2_SYM_POOL_BYTES, CC2_SYM_BYTES);
    pool = malloc(mul(symbol_count, CC2_SYM_BYTES));
    cc2_add_sym_pool(pool);
    last_symbol = sym_free_first;
    symbol = pool;
    index = 0;
    while (lt(index, symbol_count)) {
        wi32(add(symbol, CC2_SYM_NEXT_OFFSET), last_symbol);
        last_symbol = symbol;
        symbol = add(symbol, CC2_SYM_BYTES);
        index = add(index, 1);
    }
    sym_free_first = last_symbol;
    return last_symbol;
}

function __sym_malloc()
{
    return __sym_malloc_(0, 0, 0, 0, 0);
}

function sym_malloc_(symbol)
{
    symbol = sym_free_first;
    if (eq(symbol, 0)) {
        symbol = __sym_malloc();
    }
    sym_free_first = ri32(add(symbol, CC2_SYM_NEXT_OFFSET));
    return symbol;
}

function sym_malloc()
{
    return sym_malloc_(0);
}

function sym_free(symbol)
{
    wi32(add(symbol, CC2_SYM_NEXT_OFFSET), sym_free_first);
    sym_free_first = symbol;
    return 0;
}

function sym_push2_(stack_pointer, value, type, constant, symbol)
{
    symbol = sym_malloc();
    cc2_zero_bytes(symbol, CC2_SYM_BYTES);
    wi32(add(symbol, CC2_SYM_VALUE_OFFSET), value);
    wi32(add(symbol, CC2_SYM_TYPE_OFFSET), type);
    wi32(add(symbol, CC2_SYM_CONSTANT_OFFSET), constant);
    wi32(add(symbol, CC2_SYM_PREV_OFFSET), ri32(stack_pointer));
    wi32(stack_pointer, symbol);
    return symbol;
}

function sym_push2(stack_pointer, value, type, constant)
{
    return sym_push2_(stack_pointer, value, type, constant, 0);
}

function sym_find2(symbol, value)
{
    while (not(eq(symbol, 0))) {
        if (eq(ri32(add(symbol, CC2_SYM_VALUE_OFFSET)), value)) {
            return symbol;
        } else if (eq(ri32(add(symbol, CC2_SYM_VALUE_OFFSET)), sub(0, 1))) {
            return 0;
        }
        symbol = ri32(add(symbol, CC2_SYM_PREV_OFFSET));
    }
    return 0;
}

function cc2_token_symbol_(value, index)
{
    index = sub(value, CC2_TOKEN_IDENTIFIER_BASE);
    if (lt(index, 0)) {
        return 0;
    }
    if (not(lt(index, sub(tok_ident, CC2_TOKEN_IDENTIFIER_BASE)))) {
        return 0;
    }
    return ri32(add(table_ident, mul(index, 4)));
}

function cc2_token_symbol(value)
{
    return cc2_token_symbol_(value, 0);
}

function struct_find_(value, token_symbol)
{
    token_symbol = cc2_token_symbol(value);
    if (eq(token_symbol, 0)) {
        return 0;
    }
    return ri32(add(token_symbol, CC2_TOKEN_SYMBOL_STRUCT_OFFSET));
}

function struct_find(value)
{
    return struct_find_(value, 0);
}

function sym_find_(value, token_symbol)
{
    token_symbol = cc2_token_symbol(value);
    if (eq(token_symbol, 0)) {
        return 0;
    }
    return ri32(add(token_symbol, CC2_TOKEN_SYMBOL_IDENTIFIER_OFFSET));
}

function sym_find(value)
{
    return sym_find_(value, 0);
}

function cc2_push_selected_stack_(value, type, constant, symbol)
{
    symbol = sym_malloc();
    cc2_zero_bytes(symbol, CC2_SYM_BYTES);
    wi32(add(symbol, CC2_SYM_VALUE_OFFSET), value);
    wi32(add(symbol, CC2_SYM_TYPE_OFFSET), type);
    wi32(add(symbol, CC2_SYM_CONSTANT_OFFSET), constant);
    if (not(eq(local_stack, 0))) {
        wi32(add(symbol, CC2_SYM_PREV_OFFSET), local_stack);
        local_stack = symbol;
    } else {
        wi32(add(symbol, CC2_SYM_PREV_OFFSET), global_stack);
        global_stack = symbol;
    }
    return symbol;
}

function cc2_push_selected_stack(value, type, constant)
{
    return cc2_push_selected_stack_(value, type, constant, 0);
}

function sym_push_(value, type, reg, constant, symbol, plain_value,
    token_symbol, slot, previous)
{
    symbol = cc2_push_selected_stack(value, ri32(type), constant);
    wi32(add(symbol, CC2_SYM_TYPE_REFERENCE_OFFSET), ri32(add(type, 4)));
    wi32(add(symbol, 4), reg);
    plain_value = and(value, bnot(CC2_SYMBOL_STRUCT_FLAG));
    if (eq(and(value, CC2_SYMBOL_FIELD_FLAG), 0)) {
        if (lt(plain_value, CC2_FIRST_ANONYMOUS_SYMBOL)) {
            token_symbol = cc2_token_symbol(plain_value);
            slot = add(token_symbol, CC2_TOKEN_SYMBOL_IDENTIFIER_OFFSET);
            if (not(eq(and(value, CC2_SYMBOL_STRUCT_FLAG), 0))) {
                slot = add(token_symbol, CC2_TOKEN_SYMBOL_STRUCT_OFFSET);
            }
            previous = ri32(slot);
            wi32(add(symbol, CC2_SYM_PREVIOUS_TOKEN_OFFSET), previous);
            wi32(slot, symbol);
            wi32(add(symbol, CC2_SYM_SCOPE_OFFSET), local_scope);
            if (not(eq(previous, 0))) {
                if (eq(ri32(add(previous, CC2_SYM_SCOPE_OFFSET)),
                    local_scope)) {
                    sym_redeclaration_error(plain_value);
                }
            }
        }
    }
    return symbol;
}

function sym_push(value, type, reg, constant)
{
    return sym_push_(value, type, reg, constant, 0, 0, 0, 0, 0);
}

function global_identifier_push_(value, type, constant, symbol,
    token_symbol, slot, current)
{
    symbol = sym_malloc();
    cc2_zero_bytes(symbol, CC2_SYM_BYTES);
    wi32(add(symbol, CC2_SYM_VALUE_OFFSET), value);
    wi32(add(symbol, CC2_SYM_TYPE_OFFSET), type);
    wi32(add(symbol, CC2_SYM_CONSTANT_OFFSET), constant);
    wi32(add(symbol, CC2_SYM_PREV_OFFSET), global_stack);
    global_stack = symbol;
    if (lt(value, CC2_FIRST_ANONYMOUS_SYMBOL)) {
        token_symbol = cc2_token_symbol(value);
        slot = add(token_symbol, CC2_TOKEN_SYMBOL_IDENTIFIER_OFFSET);
        current = ri32(slot);
        while (not(eq(current, 0))) {
            if (eq(ri32(add(current, CC2_SYM_SCOPE_OFFSET)), 0)) {
                break;
            }
            slot = add(current, CC2_SYM_PREVIOUS_TOKEN_OFFSET);
            current = ri32(slot);
        }
        wi32(add(symbol, CC2_SYM_PREVIOUS_TOKEN_OFFSET), current);
        wi32(slot, symbol);
    }
    return symbol;
}

function global_identifier_push(value, type, constant)
{
    return global_identifier_push_(value, type, constant, 0, 0, 0, 0);
}

function sym_pop_(stack_pointer, boundary, keep, symbol, next, value,
    plain_value, token_symbol, slot)
{
    symbol = ri32(stack_pointer);
    while (not(eq(symbol, boundary))) {
        next = ri32(add(symbol, CC2_SYM_PREV_OFFSET));
        value = ri32(add(symbol, CC2_SYM_VALUE_OFFSET));
        plain_value = and(value, bnot(CC2_SYMBOL_STRUCT_FLAG));
        if (eq(and(value, CC2_SYMBOL_FIELD_FLAG), 0)) {
            if (lt(plain_value, CC2_FIRST_ANONYMOUS_SYMBOL)) {
                token_symbol = cc2_token_symbol(plain_value);
                slot = add(token_symbol, CC2_TOKEN_SYMBOL_IDENTIFIER_OFFSET);
                if (not(eq(and(value, CC2_SYMBOL_STRUCT_FLAG), 0))) {
                    slot = add(token_symbol, CC2_TOKEN_SYMBOL_STRUCT_OFFSET);
                }
                wi32(slot, ri32(add(symbol,
                    CC2_SYM_PREVIOUS_TOKEN_OFFSET)));
            }
        }
        if (eq(keep, 0)) {
            sym_free(symbol);
        }
        symbol = next;
    }
    if (eq(keep, 0)) {
        wi32(stack_pointer, boundary);
    }
    return 0;
}

function sym_pop(stack_pointer, boundary, keep)
{
    return sym_pop_(stack_pointer, boundary, keep, 0, 0, 0, 0, 0, 0);
}

function cc2_copy_svalue(destination, source)
{
    return cc2_copy_bytes(destination, source, CC2_SVALUE_BYTES);
}

function cc2_svalue_temporary()
{
    if (eq(CC2_SVALUE_TEMPORARY, 0)) {
        CC2_SVALUE_TEMPORARY = malloc(CC2_SVALUE_BYTES);
    }
    return CC2_SVALUE_TEMPORARY;
}

function cc2_materialize_top_flags_(location)
{
    if (not(lt(vtop, vstack_base))) {
        if (eq(nocode_wanted, 0)) {
            location = and(ri32(add(vtop,
                CC2_SVALUE_REGISTER_OFFSET)), CC2_VALUE_LOCATION_MASK);
            if (or(eq(location, CC2_VALUE_COMPARISON),
                eq(and(location, bnot(1)), CC2_VALUE_JUMP))) {
                gv(CC2_INTEGER_REGISTER_CLASS);
            }
        }
    }
    return 0;
}

function cc2_materialize_top_flags()
{
    return cc2_materialize_top_flags_(0);
}

function vsetc(type, reg, constant)
{
    if (not(lt(vtop, vstack_limit))) {
        vstack_overflow_error(vtop, vstack_limit);
    }
    cc2_materialize_top_flags();
    vtop = add(vtop, CC2_SVALUE_BYTES);
    cc2_copy_bytes(vtop, type, 8);
    wi32(add(vtop, CC2_SVALUE_REGISTER_OFFSET),
        or(reg, shl(CC2_VALUE_CONSTANT, 16)));
    cc2_copy_bytes(add(vtop, CC2_SVALUE_CONSTANT_OFFSET), constant, 12);
    wi32(add(vtop, CC2_SVALUE_SYMBOL_OFFSET), 0);
    return 0;
}

function vset_(type, reg, value, constant)
{
    constant = cc2_svalue_temporary();
    wi32(constant, value);
    wi32(add(constant, 4), 0);
    if (lt(value, 0)) {
        wi32(add(constant, 4), sub(0, 1));
    }
    wi32(add(constant, 8), 0);
    return vsetc(type, reg, constant);
}

function vset(type, reg, value)
{
    return vset_(type, reg, value, 0);
}

function vswap()
{
    cc2_materialize_top_flags();
    cc2_copy_svalue(cc2_svalue_temporary(), vtop);
    cc2_copy_svalue(vtop, sub(vtop, CC2_SVALUE_BYTES));
    cc2_copy_svalue(sub(vtop, CC2_SVALUE_BYTES),
        cc2_svalue_temporary());
    return 0;
}

function pointed_type(type)
{
    return add(ri32(add(type, 4)), CC2_SYM_TYPE_OFFSET);
}

function mk_pointer_(type, symbol, old_type)
{
    old_type = ri32(type);
    symbol = sym_push(CC2_SYMBOL_FIELD_FLAG, type, 0, sub(0, 1));
    wi32(type, or(CC2_TCC_POINTER_TYPE,
        and(old_type, CC2_TCC_STORAGE_MASK)));
    wi32(add(type, 4), symbol);
    return 0;
}

function mk_pointer(type)
{
    return mk_pointer_(type, 0, 0);
}

function lvalue_type_(type, basic_type, result)
{
    result = CC2_TCC_LVALUE;
    basic_type = and(type, CC2_TCC_BASIC_TYPE_MASK);
    if (or(eq(basic_type, CC2_TCC_BYTE_TYPE),
        eq(basic_type, CC2_TCC_BOOLEAN_TYPE))) {
        result = or(result, CC2_TCC_LVALUE_BYTE);
    } else if (eq(basic_type, CC2_TCC_SHORT_TYPE)) {
        result = or(result, CC2_TCC_LVALUE_SHORT);
    } else {
        return result;
    }
    if (not(eq(and(type, CC2_TCC_UNSIGNED_TYPE), 0))) {
        result = or(result, CC2_TCC_LVALUE_UNSIGNED);
    }
    return result;
}

function lvalue_type(type)
{
    return lvalue_type_(type, 0, 0);
}

function vpop_(location)
{
    location = and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
        CC2_VALUE_LOCATION_MASK);
    if (eq(location, CC2_I386_FLOAT_RETURN_REGISTER)) {
        o(CC2_I386_POP_FLOAT_STACK);
    } else if (or(eq(location, CC2_VALUE_JUMP),
        eq(location, add(CC2_VALUE_JUMP, 1)))) {
        gsym(ri32(add(vtop, CC2_SVALUE_CONSTANT_OFFSET)));
    }
    vtop = sub(vtop, CC2_SVALUE_BYTES);
    return 0;
}

function vpop()
{
    return vpop_(0);
}

function get_sym_ref_(type, section, offset, size, value, symbol)
{
    value = anon_sym;
    anon_sym = add(anon_sym, 1);
    symbol = global_identifier_push(value,
        or(ri32(type), CC2_TCC_STATIC_STORAGE), 0);
    wi32(add(symbol, CC2_SYM_TYPE_REFERENCE_OFFSET), ri32(add(type, 4)));
    wi32(add(symbol, 4), or(CC2_VALUE_CONSTANT, CC2_TCC_SYMBOL_VALUE));
    put_extern_sym(symbol, section, offset, size);
    return symbol;
}

function get_sym_ref(type, section, offset, size)
{
    return get_sym_ref_(type, section, offset, size, 0, 0);
}

function external_global_sym_(value, type, reg, symbol, symbol_type)
{
    symbol = sym_find(value);
    if (eq(symbol, 0)) {
        symbol = global_identifier_push(value,
            or(ri32(type), CC2_TCC_EXTERN_STORAGE), 0);
        wi32(add(symbol, CC2_SYM_TYPE_REFERENCE_OFFSET),
            ri32(add(type, 4)));
        wi32(add(symbol, 4), or(or(reg, CC2_VALUE_CONSTANT),
            CC2_TCC_SYMBOL_VALUE));
    } else {
        symbol_type = ri32(add(symbol, CC2_SYM_TYPE_OFFSET));
        if (eq(and(symbol_type, 31), CC2_TCC_ASSEMBLER_TYPE)) {
            wi32(add(symbol, CC2_SYM_TYPE_OFFSET), or(ri32(type),
                and(symbol_type, CC2_TCC_EXTERN_STORAGE)));
            wi32(add(symbol, CC2_SYM_TYPE_REFERENCE_OFFSET),
                ri32(add(type, 4)));
            update_storage(symbol);
        }
    }
    return symbol;
}

function external_global_sym(value, type, reg)
{
    return external_global_sym_(value, type, reg, 0, 0);
}

function vpush(type)
{
    return vset(type, CC2_VALUE_CONSTANT, 0);
}

function vpushsym(type, symbol)
{
    vset(type, or(CC2_VALUE_CONSTANT, CC2_TCC_SYMBOL_VALUE), 0);
    wi32(add(vtop, CC2_SVALUE_SYMBOL_OFFSET), symbol);
    return 0;
}

function vpush_ref(type, section, offset, size)
{
    return vpushsym(type, get_sym_ref(type, section, offset, size));
}

function vpush_global_sym(type, value)
{
    return vpushsym(type, external_global_sym(value, type, 0));
}

function vpushi(value)
{
    return vset(int_type_address, CC2_VALUE_CONSTANT, value);
}

function vpushs(value)
{
    return vset(size_type_address, CC2_VALUE_CONSTANT, value);
}

function vseti(reg, value)
{
    return vset(int_type_address, reg, value);
}

function save_reg(reg)
{
    return save_reg_upstack(reg, 0);
}

function save_regs_(count, entry, last)
{
    entry = vstack_base;
    last = sub(vtop, mul(count, CC2_SVALUE_BYTES));
    while (le(entry, last)) {
        save_reg(and(ri32(add(entry, CC2_SVALUE_REGISTER_OFFSET)), 65535));
        entry = add(entry, CC2_SVALUE_BYTES);
    }
    return 0;
}

function save_regs(count)
{
    return save_regs_(count, 0, 0);
}

function gaddrof_(registers, location)
{
    registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
    registers = and(registers, bnot(CC2_TCC_LVALUE));
    location = and(registers, CC2_VALUE_LOCATION_MASK);
    if (eq(location, CC2_VALUE_LOCAL_LVALUE)) {
        registers = and(registers,
            bnot(or(CC2_VALUE_LOCATION_MASK,
            CC2_VALUE_LVALUE_TYPE_MASK)));
        registers = or(registers,
            or(CC2_VALUE_LOCAL, CC2_TCC_LVALUE));
    }
    wi32(add(vtop, CC2_SVALUE_REGISTER_OFFSET), registers);
    return 0;
}

function gaddrof()
{
    return gaddrof_(0, 0);
}

function cc2_i386_register_class(reg)
{
    if (eq(reg, 0)) {
        return CC2_I386_EAX_CLASS;
    }
    if (eq(reg, 1)) {
        return CC2_I386_ECX_CLASS;
    }
    if (eq(reg, 2)) {
        return CC2_I386_EDX_CLASS;
    }
    if (eq(reg, 3)) {
        return CC2_I386_EBX_CLASS;
    }
    return CC2_I386_ST0_CLASS;
}

function cc2_register_used_(reg, entry, registers)
{
    entry = vstack_base;
    while (le(entry, vtop)) {
        registers = ri32(add(entry, CC2_SVALUE_REGISTER_OFFSET));
        if (eq(and(registers, CC2_VALUE_LOCATION_MASK), reg)) {
            return 1;
        }
        if (eq(and(ushr(registers, 16), CC2_VALUE_LOCATION_MASK), reg)) {
            return 1;
        }
        entry = add(entry, CC2_SVALUE_BYTES);
    }
    return 0;
}

function cc2_register_used(reg)
{
    return cc2_register_used_(reg, 0, 0);
}

function get_reg_(required_class, reg, entry, registers)
{
    reg = 0;
    while (lt(reg, CC2_I386_REGISTER_COUNT)) {
        if (not(eq(and(cc2_i386_register_class(reg), required_class), 0))) {
            if (not(eq(nocode_wanted, 0))) {
                return reg;
            }
            if (eq(cc2_register_used(reg), 0)) {
                return reg;
            }
        }
        reg = add(reg, 1);
    }
    entry = vstack_base;
    while (le(entry, vtop)) {
        registers = ri32(add(entry, CC2_SVALUE_REGISTER_OFFSET));
        reg = and(ushr(registers, 16), CC2_VALUE_LOCATION_MASK);
        if (lt(reg, CC2_VALUE_CONSTANT)) {
            if (not(eq(and(cc2_i386_register_class(reg),
                required_class), 0))) {
                save_reg(reg);
                return reg;
            }
        }
        reg = and(registers, CC2_VALUE_LOCATION_MASK);
        if (lt(reg, CC2_VALUE_CONSTANT)) {
            if (not(eq(and(cc2_i386_register_class(reg),
                required_class), 0))) {
                save_reg(reg);
                return reg;
            }
        }
        entry = add(entry, CC2_SVALUE_BYTES);
    }
    return sub(0, 1);
}

function get_reg(required_class)
{
    return get_reg_(required_class, 0, 0, 0);
}

function is_compatible_func_(type1, type2, symbol1, symbol2,
    attributes1, attributes2)
{
    symbol1 = ri32(add(type1, 4));
    symbol2 = ri32(add(type2, 4));
    if (eq(is_compatible_types(add(symbol1, CC2_SYM_TYPE_OFFSET),
        add(symbol2, CC2_SYM_TYPE_OFFSET)), 0)) {
        return 0;
    }
    attributes1 = ri32(add(symbol1, CC2_SYM_FUNCTION_ATTRIBUTES_OFFSET));
    attributes2 = ri32(add(symbol2, CC2_SYM_FUNCTION_ATTRIBUTES_OFFSET));
    if (not(eq(and(attributes1, 7), and(attributes2, 7)))) {
        return 0;
    }
    if (or(eq(and(ushr(attributes1, 3), 3), CC2_TCC_OLD_FUNCTION),
        eq(and(ushr(attributes2, 3), 3), CC2_TCC_OLD_FUNCTION))) {
        return 1;
    }
    if (not(eq(and(ushr(attributes1, 3), 3),
        and(ushr(attributes2, 3), 3)))) {
        return 0;
    }
    while (not(eq(symbol1, 0))) {
        if (eq(symbol2, 0)) {
            return 0;
        }
        if (eq(is_compatible_unqualified_types(
            add(symbol1, CC2_SYM_TYPE_OFFSET),
            add(symbol2, CC2_SYM_TYPE_OFFSET)), 0)) {
            return 0;
        }
        symbol1 = ri32(add(symbol1, CC2_SYM_NEXT_OFFSET));
        symbol2 = ri32(add(symbol2, CC2_SYM_NEXT_OFFSET));
    }
    return eq(symbol2, 0);
}

function is_compatible_func(type1, type2)
{
    return is_compatible_func_(type1, type2, 0, 0, 0, 0);
}

function compare_types_(type1, type2, unqualified, value1, value2,
    basic_type)
{
    value1 = and(ri32(type1), CC2_TCC_TYPE_MASK);
    value2 = and(ri32(type2), CC2_TCC_TYPE_MASK);
    if (not(eq(unqualified, 0))) {
        value1 = and(value1, bnot(or(CC2_TCC_CONST_QUALIFIER,
            CC2_TCC_VOLATILE_QUALIFIER)));
        value2 = and(value2, bnot(or(CC2_TCC_CONST_QUALIFIER,
            CC2_TCC_VOLATILE_QUALIFIER)));
    }
    if (not(eq(and(value1, CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_BYTE_TYPE))) {
        value1 = and(value1, bnot(CC2_TCC_DEFAULT_SIGN));
        value2 = and(value2, bnot(CC2_TCC_DEFAULT_SIGN));
    }
    if (not(eq(value1, value2))) {
        return 0;
    }
    basic_type = and(value1, CC2_TCC_BASIC_TYPE_MASK);
    if (eq(basic_type, CC2_TCC_POINTER_TYPE)) {
        return is_compatible_types(pointed_type(type1), pointed_type(type2));
    }
    if (eq(basic_type, CC2_TCC_STRUCT_TYPE)) {
        return eq(ri32(add(type1, 4)), ri32(add(type2, 4)));
    }
    if (eq(basic_type, CC2_TCC_FUNCTION_TYPE)) {
        return is_compatible_func(type1, type2);
    }
    return 1;
}

function compare_types(type1, type2, unqualified)
{
    return compare_types_(type1, type2, unqualified, 0, 0, 0);
}

function is_compatible_types(type1, type2)
{
    return compare_types(type1, type2, 0);
}

function is_compatible_unqualified_types(type1, type2)
{
    return compare_types(type1, type2, 1);
}

function type_size_(type, alignment, type_value, basic_type, symbol,
    element_size, count, structure_mask)
{
    type_value = ri32(type);
    basic_type = and(type_value, CC2_TCC_BASIC_TYPE_MASK);
    if (eq(basic_type, CC2_TCC_STRUCT_TYPE)) {
        symbol = ri32(add(type, 4));
        wi32(alignment, and(ri32(add(symbol, 4)), 65535));
        return ri32(add(symbol, CC2_SYM_CONSTANT_OFFSET));
    }
    if (eq(basic_type, CC2_TCC_POINTER_TYPE)) {
        if (not(eq(and(type_value, CC2_TCC_ARRAY_TYPE), 0))) {
            symbol = ri32(add(type, 4));
            element_size = type_size(add(symbol, CC2_SYM_TYPE_OFFSET),
                alignment);
            count = ri32(add(symbol, CC2_SYM_CONSTANT_OFFSET));
            if (lt(element_size, 0)) {
                if (lt(count, 0)) {
                    element_size = sub(0, element_size);
                }
            }
            return mul(element_size, count);
        }
        wi32(alignment, CC2_I386_WORD_BYTES);
        return CC2_I386_WORD_BYTES;
    }
    structure_mask = or(shl(4095, 20), 128);
    if (eq(and(type_value, structure_mask), CC2_TCC_ENUM_TYPE)) {
        symbol = ri32(add(type, 4));
        if (eq(ri32(add(symbol, CC2_SYM_CONSTANT_OFFSET)), sub(0, 1))) {
            return sub(0, 1);
        }
    }
    if (eq(basic_type, CC2_TCC_LONG_DOUBLE_TYPE)) {
        wi32(alignment, CC2_I386_WORD_BYTES);
        return CC2_I386_LONG_DOUBLE_BYTES;
    }
    if (or(eq(basic_type, CC2_TCC_DOUBLE_TYPE),
        eq(basic_type, CC2_TCC_LONG_LONG_TYPE))) {
        wi32(alignment, CC2_I386_WORD_BYTES);
        return 8;
    }
    if (or(eq(basic_type, CC2_TCC_INT_TYPE),
        eq(basic_type, CC2_TCC_FLOAT_TYPE))) {
        wi32(alignment, CC2_I386_WORD_BYTES);
        return CC2_I386_WORD_BYTES;
    }
    if (eq(basic_type, CC2_TCC_SHORT_TYPE)) {
        wi32(alignment, 2);
        return 2;
    }
    if (or(eq(basic_type, CC2_TCC_QUAD_INTEGER_TYPE),
        eq(basic_type, CC2_TCC_QUAD_FLOAT_TYPE))) {
        wi32(alignment, 8);
        return 16;
    }
    wi32(alignment, 1);
    return 1;
}

function type_size(type, alignment)
{
    return type_size_(type, alignment, 0, 0, 0, 0, 0, 0);
}

function cc2_type_alignment_temporary()
{
    if (eq(CC2_TYPE_ALIGNMENT_TEMPORARY, 0)) {
        CC2_TYPE_ALIGNMENT_TEMPORARY = malloc(CC2_I386_WORD_BYTES);
    }
    return CC2_TYPE_ALIGNMENT_TEMPORARY;
}

function vla_runtime_type_size_(type, alignment, symbol)
{
    if (not(eq(and(ri32(type), CC2_TCC_VLA_TYPE), 0))) {
        symbol = ri32(add(type, 4));
        type_size(add(symbol, CC2_SYM_TYPE_OFFSET), alignment);
        vset(int_type_address, or(CC2_VALUE_LOCAL, CC2_TCC_LVALUE),
            ri32(add(symbol, CC2_SYM_CONSTANT_OFFSET)));
    } else {
        vpushi(type_size(type, alignment));
    }
    return 0;
}

function vla_runtime_type_size(type, alignment)
{
    return vla_runtime_type_size_(type, alignment, 0);
}

function pointed_size(type)
{
    return type_size(pointed_type(type), cc2_type_alignment_temporary());
}

function vla_runtime_pointed_size(type)
{
    return vla_runtime_type_size(pointed_type(type),
        cc2_type_alignment_temporary());
}

function is_null_pointer_(value, registers, basic_type)
{
    registers = and(ri32(add(value, CC2_SVALUE_REGISTER_OFFSET)), 65535);
    if (not(eq(and(registers, 831), CC2_VALUE_CONSTANT))) {
        return 0;
    }
    basic_type = and(ri32(value), CC2_TCC_BASIC_TYPE_MASK);
    if (eq(basic_type, CC2_TCC_INT_TYPE)) {
        return eq(ri32(add(value, CC2_SVALUE_CONSTANT_OFFSET)), 0);
    }
    if (eq(basic_type, CC2_TCC_LONG_LONG_TYPE)) {
        return and(eq(ri32(add(value, CC2_SVALUE_CONSTANT_OFFSET)), 0),
            eq(ri32(add(value, add(CC2_SVALUE_CONSTANT_OFFSET, 4))), 0));
    }
    if (eq(basic_type, CC2_TCC_POINTER_TYPE)) {
        return eq(ri32(add(value, CC2_SVALUE_CONSTANT_OFFSET)), 0);
    }
    return 0;
}

function is_null_pointer(value)
{
    return is_null_pointer_(value, 0, 0);
}

function cc2_write_signed_constant(constant, value)
{
    wi32(constant, value);
    wi32(add(constant, 4), 0);
    if (lt(value, 0)) {
        wi32(add(constant, 4), sub(0, 1));
    }
    return 0;
}

function save_reg_upstack_(reg, count, entry, last, saved, stack_location,
    registers, type, size, alignment, spill, new_register)
{
    reg = and(reg, CC2_VALUE_LOCATION_MASK);
    if (not(lt(reg, CC2_VALUE_CONSTANT))) {
        return 0;
    }
    if (not(eq(nocode_wanted, 0))) {
        return 0;
    }
    entry = vstack_base;
    last = sub(vtop, mul(count, CC2_SVALUE_BYTES));
    saved = 0;
    stack_location = 0;
    while (le(entry, last)) {
        registers = ri32(add(entry, CC2_SVALUE_REGISTER_OFFSET));
        if (or(eq(and(registers, CC2_VALUE_LOCATION_MASK), reg),
            and(eq(and(ri32(entry), CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_LONG_LONG_TYPE), eq(and(ushr(registers, 16),
            CC2_VALUE_LOCATION_MASK), reg)))) {
            if (eq(saved, 0)) {
                reg = and(registers, CC2_VALUE_LOCATION_MASK);
                type = entry;
                if (or(not(eq(and(registers, CC2_TCC_LVALUE), 0)),
                    and(eq(is_float(ri32(type)), 0),
                    not(eq(and(ri32(type), CC2_TCC_BASIC_TYPE_MASK),
                    CC2_TCC_LONG_LONG_TYPE))))) {
                    type = int_type_address;
                }
                alignment = cc2_type_alignment_temporary();
                size = type_size(type, alignment);
                loc = and(sub(loc, size), sub(0, ri32(alignment)));
                spill = cc2_svalue_temporary();
                cc2_zero_bytes(spill, CC2_SVALUE_BYTES);
                wi32(spill, ri32(type));
                wi32(add(spill, CC2_SVALUE_REGISTER_OFFSET),
                    or(CC2_VALUE_LOCAL, CC2_TCC_LVALUE));
                cc2_write_signed_constant(add(spill,
                    CC2_SVALUE_CONSTANT_OFFSET), loc);
                store(reg, spill);
                if (eq(reg, CC2_I386_FLOAT_RETURN_REGISTER)) {
                    o(CC2_I386_POP_FLOAT_STACK);
                }
                if (eq(and(ri32(type), CC2_TCC_BASIC_TYPE_MASK),
                    CC2_TCC_LONG_LONG_TYPE)) {
                    cc2_write_signed_constant(add(spill,
                        CC2_SVALUE_CONSTANT_OFFSET),
                        add(ri32(add(spill, CC2_SVALUE_CONSTANT_OFFSET)), 4));
                    store(and(ushr(registers, 16), 65535), spill);
                }
                stack_location = loc;
                saved = 1;
            }
            if (not(eq(and(registers, CC2_TCC_LVALUE), 0))) {
                new_register = or(and(registers,
                    bnot(or(CC2_VALUE_LOCATION_MASK, CC2_VALUE_BOUNDED))),
                    CC2_VALUE_LOCAL_LVALUE);
            } else {
                new_register = or(lvalue_type(ri32(entry)), CC2_VALUE_LOCAL);
            }
            new_register = or(and(new_register, 65535),
                shl(CC2_VALUE_CONSTANT, 16));
            wi32(add(entry, CC2_SVALUE_REGISTER_OFFSET), new_register);
            cc2_write_signed_constant(add(entry,
                CC2_SVALUE_CONSTANT_OFFSET), stack_location);
        }
        entry = add(entry, CC2_SVALUE_BYTES);
    }
    return 0;
}

function save_reg_upstack(reg, count)
{
    return save_reg_upstack_(reg, count, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

function move_reg_(destination, source, type, value)
{
    if (not(eq(destination, source))) {
        save_reg(destination);
        value = cc2_svalue_temporary();
        cc2_zero_bytes(value, CC2_SVALUE_BYTES);
        wi32(value, type);
        wi32(add(value, CC2_SVALUE_REGISTER_OFFSET), source);
        cc2_write_signed_constant(add(value,
            CC2_SVALUE_CONSTANT_OFFSET), 0);
        load(destination, value);
    }
    return 0;
}

function move_reg(destination, source, type)
{
    return move_reg_(destination, source, type, 0);
}

function struct_add_offset_(symbol, offset, value, type_value)
{
    symbol = ri32(add(symbol, CC2_SYM_NEXT_OFFSET));
    while (not(eq(symbol, 0))) {
        value = ri32(add(symbol, CC2_SYM_VALUE_OFFSET));
        type_value = ri32(add(symbol, CC2_SYM_TYPE_OFFSET));
        if (not(eq(and(value, CC2_SYMBOL_FIELD_FLAG), 0))) {
            if (eq(and(type_value, CC2_TCC_BASIC_TYPE_MASK),
                CC2_TCC_STRUCT_TYPE)) {
                if (le(CC2_FIRST_ANONYMOUS_SYMBOL,
                    and(value, bnot(CC2_SYMBOL_FIELD_FLAG)))) {
                    struct_add_offset(ri32(add(symbol,
                        CC2_SYM_TYPE_REFERENCE_OFFSET)), offset);
                    symbol = ri32(add(symbol, CC2_SYM_NEXT_OFFSET));
                    continue;
                }
            }
        }
        wi32(add(symbol, CC2_SYM_CONSTANT_OFFSET),
            add(ri32(add(symbol, CC2_SYM_CONSTANT_OFFSET)), offset));
        symbol = ri32(add(symbol, CC2_SYM_NEXT_OFFSET));
    }
    return 0;
}

function struct_add_offset(symbol, offset)
{
    return struct_add_offset_(symbol, offset, 0, 0);
}

function find_field_(type, value, symbol, symbol_value, symbol_type, found)
{
    symbol = ri32(add(type, 4));
    value = or(value, CC2_SYMBOL_FIELD_FLAG);
    symbol = ri32(add(symbol, CC2_SYM_NEXT_OFFSET));
    while (not(eq(symbol, 0))) {
        symbol_value = ri32(add(symbol, CC2_SYM_VALUE_OFFSET));
        symbol_type = ri32(add(symbol, CC2_SYM_TYPE_OFFSET));
        if (not(eq(and(symbol_value, CC2_SYMBOL_FIELD_FLAG), 0))) {
            if (eq(and(symbol_type, CC2_TCC_BASIC_TYPE_MASK),
                CC2_TCC_STRUCT_TYPE)) {
                if (le(CC2_FIRST_ANONYMOUS_SYMBOL,
                    and(symbol_value, bnot(CC2_SYMBOL_FIELD_FLAG)))) {
                    found = find_field(add(symbol, CC2_SYM_TYPE_OFFSET), value);
                    if (not(eq(found, 0))) {
                        return found;
                    }
                }
            }
        }
        if (eq(symbol_value, value)) {
            return symbol;
        }
        symbol = ri32(add(symbol, CC2_SYM_NEXT_OFFSET));
    }
    return 0;
}

function find_field(type, value)
{
    return find_field_(type, value, 0, 0, 0, 0);
}

/* TCC's precedence ladder stays iterative so deeply nested source does not
   add recursion beyond the grammar's actual parenthesis nesting. */
function expr_prod_(operation)
{
    unary();
    while (or(or(eq(ri32(tok_address), CC2_ASCII_ASTERISK),
        eq(ri32(tok_address), CC2_ASCII_SLASH)),
        eq(ri32(tok_address), CC2_ASCII_PERCENT))) {
        operation = ri32(tok_address);
        next();
        unary();
        gen_op(operation);
    }
    return 0;
}

function expr_prod()
{
    return expr_prod_(0);
}

function expr_sum_(operation)
{
    expr_prod();
    while (or(eq(ri32(tok_address), CC2_ASCII_PLUS),
        eq(ri32(tok_address), CC2_ASCII_MINUS))) {
        operation = ri32(tok_address);
        next();
        expr_prod();
        gen_op(operation);
    }
    return 0;
}

function expr_sum()
{
    return expr_sum_(0);
}

function expr_shift_(operation)
{
    expr_sum();
    while (or(eq(ri32(tok_address), CC2_TOKEN_SHIFT_LEFT),
        eq(ri32(tok_address), CC2_TOKEN_SHIFT_RIGHT))) {
        operation = ri32(tok_address);
        next();
        expr_sum();
        gen_op(operation);
    }
    return 0;
}

function expr_shift()
{
    return expr_shift_(0);
}

function expr_cmp_(operation)
{
    expr_shift();
    while (or(and(le(CC2_TOKEN_UNSIGNED_LESS_EQUAL, ri32(tok_address)),
        le(ri32(tok_address), CC2_TOKEN_GREATER)),
        or(eq(ri32(tok_address), CC2_TOKEN_UNSIGNED_LESS),
        eq(ri32(tok_address), CC2_TOKEN_UNSIGNED_GREATER_EQUAL)))) {
        operation = ri32(tok_address);
        next();
        expr_shift();
        gen_op(operation);
    }
    return 0;
}

function expr_cmp()
{
    return expr_cmp_(0);
}

function expr_cmpeq_(operation)
{
    expr_cmp();
    while (or(eq(ri32(tok_address), CC2_TOKEN_EQUAL),
        eq(ri32(tok_address), CC2_TOKEN_NOT_EQUAL))) {
        operation = ri32(tok_address);
        next();
        expr_cmp();
        gen_op(operation);
    }
    return 0;
}

function expr_cmpeq()
{
    return expr_cmpeq_(0);
}

function expr_and()
{
    expr_cmpeq();
    while (eq(ri32(tok_address), CC2_ASCII_AMPERSAND)) {
        next();
        expr_cmpeq();
        gen_op(CC2_ASCII_AMPERSAND);
    }
    return 0;
}

function expr_xor()
{
    expr_and();
    while (eq(ri32(tok_address), CC2_ASCII_CARET)) {
        next();
        expr_and();
        gen_op(CC2_ASCII_CARET);
    }
    return 0;
}

function expr_or()
{
    expr_xor();
    while (eq(ri32(tok_address), CC2_ASCII_VERTICAL_BAR)) {
        next();
        expr_xor();
        gen_op(CC2_ASCII_VERTICAL_BAR);
    }
    return 0;
}

function expr_land_(jump_chain)
{
    expr_or();
    if (eq(ri32(tok_address), CC2_TOKEN_LOGICAL_AND)) {
        jump_chain = 0;
        while (CC2_TRUE) {
            if (eq(and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
                CC2_VALUE_TEST_MASK), CC2_VALUE_CONSTANT)) {
                gen_cast_s(CC2_TCC_BOOLEAN_TYPE);
                if (not(eq(ri32(add(vtop,
                    CC2_SVALUE_CONSTANT_OFFSET)), 0))) {
                    vpop();
                } else {
                    nocode_wanted = add(nocode_wanted, 1);
                    while (eq(ri32(tok_address), CC2_TOKEN_LOGICAL_AND)) {
                        next();
                        expr_or();
                        vpop();
                    }
                    nocode_wanted = sub(nocode_wanted, 1);
                    if (not(eq(jump_chain, 0))) {
                        gsym(jump_chain);
                    }
                    gen_cast_s(CC2_TCC_INT_TYPE);
                    return 0;
                }
            } else {
                if (eq(jump_chain, 0)) {
                    save_regs(1);
                }
                jump_chain = gvtst(1, jump_chain);
            }
            if (not(eq(ri32(tok_address), CC2_TOKEN_LOGICAL_AND))) {
                if (not(eq(jump_chain, 0))) {
                    vseti(CC2_VALUE_JUMP_FALSE, jump_chain);
                } else {
                    vpushi(1);
                }
                return 0;
            }
            next();
            expr_or();
        }
    }
    return 0;
}

function expr_land()
{
    return expr_land_(0);
}

function expr_lor_(jump_chain)
{
    expr_land();
    if (eq(ri32(tok_address), CC2_TOKEN_LOGICAL_OR)) {
        jump_chain = 0;
        while (CC2_TRUE) {
            if (eq(and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
                CC2_VALUE_TEST_MASK), CC2_VALUE_CONSTANT)) {
                gen_cast_s(CC2_TCC_BOOLEAN_TYPE);
                if (eq(ri32(add(vtop,
                    CC2_SVALUE_CONSTANT_OFFSET)), 0)) {
                    vpop();
                } else {
                    nocode_wanted = add(nocode_wanted, 1);
                    while (eq(ri32(tok_address), CC2_TOKEN_LOGICAL_OR)) {
                        next();
                        expr_land();
                        vpop();
                    }
                    nocode_wanted = sub(nocode_wanted, 1);
                    if (not(eq(jump_chain, 0))) {
                        gsym(jump_chain);
                    }
                    gen_cast_s(CC2_TCC_INT_TYPE);
                    return 0;
                }
            } else {
                if (eq(jump_chain, 0)) {
                    save_regs(1);
                }
                jump_chain = gvtst(0, jump_chain);
            }
            if (not(eq(ri32(tok_address), CC2_TOKEN_LOGICAL_OR))) {
                if (not(eq(jump_chain, 0))) {
                    vseti(CC2_VALUE_JUMP, jump_chain);
                } else {
                    vpushi(0);
                }
                return 0;
            }
            next();
            expr_land();
        }
    }
    return 0;
}

function expr_lor()
{
    return expr_lor_(0);
}

function condition_3way_(registers, symbol, attributes, result)
{
    registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
    result = sub(0, 1);
    if (eq(and(registers, or(CC2_VALUE_LOCATION_MASK, CC2_TCC_LVALUE)),
        CC2_VALUE_CONSTANT)) {
        symbol = ri32(add(vtop, CC2_SVALUE_SYMBOL_OFFSET));
        attributes = 0;
        if (not(eq(and(registers, CC2_TCC_SYMBOL_VALUE), 0))) {
            if (not(eq(symbol, 0))) {
                attributes = and(ushr(ri32(add(symbol, 4)), 16), 65535);
            }
        }
        if (or(eq(and(registers, CC2_TCC_SYMBOL_VALUE), 0),
            eq(and(attributes, CC2_SYM_ATTRIBUTE_WEAK), 0))) {
            vdup();
            gen_cast_s(CC2_TCC_BOOLEAN_TYPE);
            result = ri32(add(vtop, CC2_SVALUE_CONSTANT_OFFSET));
            vpop();
        }
    }
    return result;
}

function condition_3way()
{
    return condition_3way_(0, 0, 0, 0);
}

function gfunc_param_typed_(function_symbol, argument_symbol, function_type,
    value_type, temporary)
{
    function_type = and(ushr(ri32(add(function_symbol,
        CC2_SYM_FUNCTION_ATTRIBUTES_OFFSET)), 3), 3);
    if (or(eq(function_type, CC2_TCC_OLD_FUNCTION),
        and(eq(function_type, CC2_TCC_ELLIPSIS_FUNCTION),
        eq(argument_symbol, 0)))) {
        value_type = ri32(vtop);
        if (eq(and(value_type, CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_FLOAT_TYPE)) {
            gen_cast_s(CC2_TCC_DOUBLE_TYPE);
        } else if (not(eq(and(value_type, CC2_TCC_BITFIELD), 0))) {
            temporary = cc2_svalue_temporary();
            wi32(temporary, and(value_type,
                or(CC2_TCC_BASIC_TYPE_MASK, CC2_TCC_UNSIGNED_TYPE)));
            wi32(add(temporary, 4), ri32(add(vtop, 4)));
            gen_cast(temporary);
        }
    } else if (eq(argument_symbol, 0)) {
        tcc_error(mks("too many arguments to function"), 0);
    } else {
        temporary = cc2_svalue_temporary();
        wi32(temporary, and(ri32(add(argument_symbol, CC2_SYM_TYPE_OFFSET)),
            bnot(CC2_TCC_CONST_QUALIFIER)));
        wi32(add(temporary, 4), ri32(add(argument_symbol,
            CC2_SYM_TYPE_REFERENCE_OFFSET)));
        gen_assign_cast(temporary);
    }
    return 0;
}

function gfunc_param_typed(function_symbol, argument_symbol)
{
    return gfunc_param_typed_(function_symbol, argument_symbol, 0, 0, 0);
}

function cc2_is_assignment_token(token)
{
    if (eq(token, CC2_ASCII_ASSIGN)) {
        return CC2_TRUE;
    }
    if (and(le(CC2_ASSIGNMENT_MODULO, token),
        le(token, CC2_ASSIGNMENT_DIVIDE))) {
        return CC2_TRUE;
    }
    if (or(eq(token, CC2_ASSIGNMENT_XOR),
        eq(token, CC2_ASSIGNMENT_OR))) {
        return CC2_TRUE;
    }
    return or(eq(token, CC2_ASSIGNMENT_SHIFT_LEFT),
        eq(token, CC2_ASSIGNMENT_SHIFT_RIGHT));
}

function expr_eq_(operation)
{
    expr_cond();
    operation = ri32(tok_address);
    if (cc2_is_assignment_token(operation)) {
        test_lvalue();
        next();
        if (eq(operation, CC2_ASCII_ASSIGN)) {
            expr_eq();
        } else {
            vdup();
            expr_eq();
            gen_op(and(operation, CC2_TOKEN_OPERATOR_MASK));
        }
        vstore();
    }
    return 0;
}

function expr_eq()
{
    return expr_eq_(0);
}

function gexpr()
{
    expr_eq();
    while (eq(ri32(tok_address), CC2_ASCII_COMMA)) {
        vpop();
        next();
        expr_eq();
    }
    return 0;
}

function expr_const1()
{
    const_wanted = add(const_wanted, 1);
    nocode_wanted = add(nocode_wanted, 1);
    expr_cond();
    nocode_wanted = sub(nocode_wanted, 1);
    const_wanted = sub(const_wanted, 1);
    return 0;
}

function test_lvalue()
{
    if (eq(and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
        CC2_TCC_LVALUE), 0)) {
        expect(mks("lvalue"));
    }
    return 0;
}

function check_vstack()
{
    if (not(eq(pvtop, vtop))) {
        tcc_error(mks("internal compiler error: vstack leak (%d)"),
            sdiv(sub(vtop, pvtop), CC2_SVALUE_BYTES));
    }
    return 0;
}

function cc2_align_up(value, alignment)
{
    return and(add(value, sub(alignment, 1)), sub(0, alignment));
}

function cc2_symbol_attributes(symbol)
{
    return and(ushr(ri32(add(symbol, 4)), 16), 65535);
}

function cc2_symbol_set_register(symbol, reg)
{
    wi32(add(symbol, 4), or(and(ri32(add(symbol, 4)), bnot(65535)),
        and(reg, 65535)));
    return 0;
}

function cc2_bitfield_size(type_value)
{
    return and(ushr(type_value, CC2_TCC_BITFIELD_SIZE_SHIFT),
        CC2_TCC_BITFIELD_VALUE_MASK);
}

function cc2_bitfield_position(type_value)
{
    return and(ushr(type_value, CC2_TCC_BITFIELD_POSITION_SHIFT),
        CC2_TCC_BITFIELD_VALUE_MASK);
}

/* Named anonymous aggregates may share their member chain. Layout needs a
   private chain because it applies the containing aggregate's offset. */
function cc2_unshare_anonymous_(field, reference, value, source, destination,
    clone)
{
    reference = ri32(add(field, CC2_SYM_TYPE_REFERENCE_OFFSET));
    value = ri32(add(reference, CC2_SYM_VALUE_OFFSET));
    if (eq(and(value, CC2_SYMBOL_FIELD_FLAG), 0)) {
        if (lt(and(value, bnot(CC2_SYMBOL_STRUCT_FLAG)),
            CC2_FIRST_ANONYMOUS_SYMBOL)) {
            source = reference;
            clone = sym_push(or(anon_sym, CC2_SYMBOL_FIELD_FLAG),
                add(reference, CC2_SYM_TYPE_OFFSET), 0,
                ri32(add(reference, CC2_SYM_CONSTANT_OFFSET)));
            anon_sym = add(anon_sym, 1);
            wi32(add(field, CC2_SYM_TYPE_REFERENCE_OFFSET), clone);
            destination = clone;
            source = ri32(add(source, CC2_SYM_NEXT_OFFSET));
            while (not(eq(source, 0))) {
                clone = sym_push(ri32(add(source, CC2_SYM_VALUE_OFFSET)),
                    add(source, CC2_SYM_TYPE_OFFSET), 0,
                    ri32(add(source, CC2_SYM_CONSTANT_OFFSET)));
                wi32(add(destination, CC2_SYM_NEXT_OFFSET), clone);
                destination = clone;
                source = ri32(add(source, CC2_SYM_NEXT_OFFSET));
            }
            wi32(add(destination, CC2_SYM_NEXT_OFFSET), 0);
        }
    }
    return 0;
}

function cc2_unshare_anonymous(field)
{
    return cc2_unshare_anonymous_(field, 0, 0, 0, 0, 0);
}

function struct_layout_place_(type, attributes, pcc, pragma_pack, reference,
    field, maximum_alignment, offset, size_so_far, bit_position, bit_size,
    previous_basic_type, previous_bit_size, field_type, size, alignment,
    field_attributes, individual_alignment, packed, basic_type,
    alignment_bits, occupied_units, start_new_field, requested_alignment)
{
    reference = ri32(add(type, 4));
    field = ri32(add(reference, CC2_SYM_NEXT_OFFSET));
    maximum_alignment = 1;
    offset = 0;
    size_so_far = 0;
    bit_position = 0;
    previous_basic_type = CC2_TCC_STRUCT_TYPE;
    previous_bit_size = 0;
    while (not(eq(field, 0))) {
        field_type = ri32(add(field, CC2_SYM_TYPE_OFFSET));
        if (not(eq(and(field_type, CC2_TCC_BITFIELD), 0))) {
            bit_size = cc2_bitfield_size(field_type);
        } else {
            bit_size = sub(0, 1);
        }
        requested_alignment = cc2_type_alignment_temporary();
        size = type_size(add(field, CC2_SYM_TYPE_OFFSET), requested_alignment);
        alignment = ri32(requested_alignment);
        field_attributes = cc2_symbol_attributes(field);
        individual_alignment = and(field_attributes,
            CC2_SYM_ATTRIBUTE_ALIGNED_MASK);
        if (not(eq(individual_alignment, 0))) {
            individual_alignment = shl(1, sub(individual_alignment, 1));
        }
        packed = 0;
        if (not(and(pcc, eq(bit_size, 0)))) {
            if (pcc) {
                if (or(not(eq(and(field_attributes,
                    CC2_SYM_ATTRIBUTE_PACKED), 0)), not(eq(and(ri32(attributes),
                    CC2_SYM_ATTRIBUTE_PACKED), 0)))) {
                    alignment = 1;
                    packed = 1;
                }
            }
            if (not(eq(pragma_pack, 0))) {
                packed = 1;
                if (lt(pragma_pack, alignment)) {
                    alignment = pragma_pack;
                }
                if (and(pcc, lt(pragma_pack, individual_alignment))) {
                    individual_alignment = 0;
                }
            }
        }
        if (not(eq(individual_alignment, 0))) {
            alignment = individual_alignment;
        }
        if (eq(ri32(add(reference, CC2_SYM_TYPE_OFFSET)),
            CC2_TCC_UNION_TYPE)) {
            if (and(pcc, le(0, bit_size))) {
                size = ushr(add(bit_size, 7), 3);
            }
            offset = 0;
            if (lt(size_so_far, size)) {
                size_so_far = size;
            }
        } else if (lt(bit_size, 0)) {
            if (pcc) {
                size_so_far = add(size_so_far,
                    ushr(add(bit_position, 7), 3));
            }
            size_so_far = cc2_align_up(size_so_far, alignment);
            offset = size_so_far;
            if (lt(0, size)) {
                size_so_far = add(size_so_far, size);
            }
            bit_position = 0;
            previous_basic_type = CC2_TCC_STRUCT_TYPE;
            previous_bit_size = 0;
        } else if (pcc) {
            start_new_field = eq(bit_size, 0);
            if (not(eq(individual_alignment, 0))) {
                start_new_field = 1;
            } else if (eq(packed, 0)) {
                alignment_bits = mul(alignment, 8);
                occupied_units = sdiv(add(add(mod(add(mul(size_so_far, 8),
                    bit_position), alignment_bits), bit_size),
                    sub(alignment_bits, 1)), alignment_bits);
                if (lt(sdiv(size, alignment), occupied_units)) {
                    start_new_field = 1;
                }
            }
            if (start_new_field) {
                size_so_far = cc2_align_up(add(size_so_far,
                    ushr(add(bit_position, 7), 3)), alignment);
                bit_position = 0;
            }
            if (and(eq(size, 8), le(bit_size, 32))) {
                field_type = or(and(field_type,
                    bnot(CC2_TCC_BASIC_TYPE_MASK)), CC2_TCC_INT_TYPE);
                wi32(add(field, CC2_SYM_TYPE_OFFSET), field_type);
                size = 4;
            }
            while (le(mul(alignment, 8), bit_position)) {
                size_so_far = add(size_so_far, alignment);
                bit_position = sub(bit_position, mul(alignment, 8));
            }
            offset = size_so_far;
            if (not(eq(and(ri32(add(field, CC2_SYM_VALUE_OFFSET)),
                CC2_FIRST_ANONYMOUS_SYMBOL), 0))) {
                alignment = 1;
            }
            field_type = ri32(add(field, CC2_SYM_TYPE_OFFSET));
            wi32(add(field, CC2_SYM_TYPE_OFFSET), or(and(field_type,
                bnot(CC2_TCC_BITFIELD_POSITION_MASK)),
                shl(bit_position, CC2_TCC_BITFIELD_POSITION_SHIFT)));
            bit_position = add(bit_position, bit_size);
        } else {
            basic_type = and(field_type, CC2_TCC_BASIC_TYPE_MASK);
            if (or(lt(mul(size, 8), add(bit_position, bit_size)),
                eq(lt(0, bit_size), not(eq(basic_type,
                previous_basic_type))))) {
                size_so_far = cc2_align_up(size_so_far, alignment);
                offset = size_so_far;
                bit_position = 0;
                if (or(not(eq(bit_size, 0)),
                    not(eq(previous_bit_size, 0)))) {
                    size_so_far = add(size_so_far, size);
                }
            }
            if (and(eq(bit_size, 0),
                not(eq(previous_basic_type, basic_type)))) {
                alignment = 1;
            }
            previous_basic_type = basic_type;
            previous_bit_size = bit_size;
            wi32(add(field, CC2_SYM_TYPE_OFFSET), or(and(field_type,
                bnot(CC2_TCC_BITFIELD_POSITION_MASK)),
                shl(bit_position, CC2_TCC_BITFIELD_POSITION_SHIFT)));
            bit_position = add(bit_position, bit_size);
        }
        if (lt(maximum_alignment, alignment)) {
            maximum_alignment = alignment;
        }
        field_type = ri32(add(field, CC2_SYM_TYPE_OFFSET));
        if (and(not(eq(and(ri32(add(field, CC2_SYM_VALUE_OFFSET)),
            CC2_FIRST_ANONYMOUS_SYMBOL), 0)),
            eq(and(field_type, CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_STRUCT_TYPE))) {
            cc2_unshare_anonymous(field);
            struct_add_offset(ri32(add(field,
                CC2_SYM_TYPE_REFERENCE_OFFSET)), offset);
            wi32(add(field, CC2_SYM_CONSTANT_OFFSET), 0);
        } else {
            wi32(add(field, CC2_SYM_CONSTANT_OFFSET), offset);
        }
        cc2_symbol_set_register(field, 0);
        field = ri32(add(field, CC2_SYM_NEXT_OFFSET));
    }
    if (pcc) {
        size_so_far = add(size_so_far, ushr(add(bit_position, 7), 3));
    }
    requested_alignment = and(ri32(attributes),
        CC2_SYM_ATTRIBUTE_ALIGNED_MASK);
    if (not(eq(requested_alignment, 0))) {
        requested_alignment = shl(1, sub(requested_alignment, 1));
    } else {
        requested_alignment = 1;
    }
    individual_alignment = requested_alignment;
    if (lt(requested_alignment, maximum_alignment)) {
        requested_alignment = maximum_alignment;
    }
    cc2_symbol_set_register(reference, requested_alignment);
    if (and(and(not(eq(pragma_pack, 0)),
        lt(pragma_pack, maximum_alignment)), eq(pcc, 0))) {
        requested_alignment = pragma_pack;
        if (lt(requested_alignment, individual_alignment)) {
            requested_alignment = individual_alignment;
        }
    }
    size_so_far = cc2_align_up(size_so_far, requested_alignment);
    wi32(add(reference, CC2_SYM_CONSTANT_OFFSET), size_so_far);
    return size_so_far;
}

function struct_layout_place(type, attributes, pcc, pragma_pack)
{
    return struct_layout_place_(type, attributes, pcc, pragma_pack,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

/* Some bitfields cross their declared type's natural access unit. TCC picks
   the smallest safe scalar access, falling back to byte-wise access. */
function struct_layout_access_(type, total_size, reference, field, field_type,
    bit_size, bit_position, size, alignment_pointer, alignment, access_size,
    pixel, byte_offset, previous_offset, temporary_type)
{
    reference = ri32(add(type, 4));
    field = ri32(add(reference, CC2_SYM_NEXT_OFFSET));
    alignment_pointer = cc2_type_alignment_temporary();
    temporary_type = cc2_svalue_temporary();
    while (not(eq(field, 0))) {
        field_type = ri32(add(field, CC2_SYM_TYPE_OFFSET));
        if (not(eq(and(field_type, CC2_TCC_BITFIELD), 0))) {
            wi32(add(field, CC2_SYM_TYPE_REFERENCE_OFFSET), field);
            wi32(add(field, CC2_SYM_SCOPE_OFFSET), sub(0, 1));
            bit_size = cc2_bitfield_size(field_type);
            if (not(eq(bit_size, 0))) {
                bit_position = cc2_bitfield_position(field_type);
                size = type_size(add(field, CC2_SYM_TYPE_OFFSET),
                    alignment_pointer);
                alignment = ri32(alignment_pointer);
                if (or(lt(mul(size, 8), add(bit_position, bit_size)),
                    lt(total_size, add(ri32(add(field,
                    CC2_SYM_CONSTANT_OFFSET)), size)))) {
                    previous_offset = sub(0, 1);
                    access_size = 1;
                    alignment = 1;
                    while (not(eq(previous_offset, byte_offset))) {
                        pixel = add(mul(ri32(add(field,
                            CC2_SYM_CONSTANT_OFFSET)), 8), bit_position);
                        byte_offset = and(ushr(pixel, 3), sub(0, alignment));
                        pixel = sub(pixel, shl(byte_offset, 3));
                        if (not(eq(previous_offset, byte_offset))) {
                            access_size = ushr(add(add(pixel, bit_size), 7), 3);
                            if (lt(4, access_size)) {
                                wi32(temporary_type, CC2_TCC_LONG_LONG_TYPE);
                            } else if (lt(2, access_size)) {
                                wi32(temporary_type, CC2_TCC_INT_TYPE);
                            } else if (lt(1, access_size)) {
                                wi32(temporary_type, CC2_TCC_SHORT_TYPE);
                            } else {
                                wi32(temporary_type, CC2_TCC_BYTE_TYPE);
                            }
                            wi32(add(temporary_type, 4), 0);
                            access_size = type_size(temporary_type,
                                alignment_pointer);
                            alignment = ri32(alignment_pointer);
                            previous_offset = byte_offset;
                        }
                    }
                    if (and(le(add(pixel, bit_size), mul(access_size, 8)),
                        le(add(byte_offset, access_size), total_size))) {
                        wi32(add(field, CC2_SYM_CONSTANT_OFFSET), byte_offset);
                        wi32(add(field, CC2_SYM_TYPE_OFFSET), or(and(field_type,
                            bnot(CC2_TCC_BITFIELD_POSITION_MASK)),
                            shl(pixel, CC2_TCC_BITFIELD_POSITION_SHIFT)));
                        if (not(eq(access_size, size))) {
                            wi32(add(field, CC2_SYM_SCOPE_OFFSET),
                                ri32(temporary_type));
                        }
                    } else {
                        wi32(add(field, CC2_SYM_SCOPE_OFFSET),
                            CC2_TCC_STRUCT_TYPE);
                    }
                }
            }
        }
        field = ri32(add(field, CC2_SYM_NEXT_OFFSET));
    }
    return 0;
}

function struct_layout(type, attributes, pcc, pragma_pack)
{
    return struct_layout_access_(type,
        struct_layout_place(type, attributes, pcc, pragma_pack),
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, sub(0, 2), 0, 0);
}

function cc2_set_value_register(value, reg)
{
    wi32(add(value, CC2_SVALUE_REGISTER_OFFSET),
        or(and(ri32(add(value, CC2_SVALUE_REGISTER_OFFSET)), bnot(65535)),
        and(reg, 65535)));
    return 0;
}

function cc2_set_value_second_register(value, reg)
{
    wi32(add(value, CC2_SVALUE_REGISTER_OFFSET),
        or(and(ri32(add(value, CC2_SVALUE_REGISTER_OFFSET)), 65535),
        shl(and(reg, 65535), 16)));
    return 0;
}

/* i386 represents a long long as two ordinary integer stack values while an
   operation is generated, then joins their registers again afterwards. */
function lexpand_(sign, location, previous, registers)
{
    sign = and(ri32(vtop),
        or(CC2_TCC_DEFAULT_SIGN, CC2_TCC_UNSIGNED_TYPE));
    registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
    location = and(registers,
        or(CC2_VALUE_LOCATION_MASK, CC2_TCC_LVALUE));
    previous = vtop;
    if (eq(location, CC2_VALUE_CONSTANT)) {
        vdup();
        cc2_write_signed_constant(add(vtop, CC2_SVALUE_CONSTANT_OFFSET),
            ri32(add(previous, add(CC2_SVALUE_CONSTANT_OFFSET, 4))));
    } else if (or(eq(location, or(CC2_TCC_LVALUE, CC2_VALUE_CONSTANT)),
        eq(location, or(CC2_TCC_LVALUE, CC2_VALUE_LOCAL)))) {
        vdup();
        cc2_write_signed_constant(add(vtop, CC2_SVALUE_CONSTANT_OFFSET),
            add(ri32(add(vtop, CC2_SVALUE_CONSTANT_OFFSET)), 4));
    } else {
        gv(CC2_INTEGER_REGISTER_CLASS);
        previous = vtop;
        registers = ri32(add(previous, CC2_SVALUE_REGISTER_OFFSET));
        vdup();
        cc2_set_value_register(vtop, and(ushr(registers, 16), 65535));
        cc2_set_value_second_register(vtop, CC2_VALUE_CONSTANT);
        cc2_set_value_second_register(previous, CC2_VALUE_CONSTANT);
    }
    wi32(vtop, or(CC2_TCC_INT_TYPE, sign));
    wi32(sub(vtop, CC2_SVALUE_BYTES), or(CC2_TCC_INT_TYPE, sign));
    return 0;
}

function lexpand()
{
    return lexpand_(0, 0, 0, 0);
}

function lbuild(type)
{
    gv2(CC2_INTEGER_REGISTER_CLASS, CC2_INTEGER_REGISTER_CLASS);
    cc2_set_value_second_register(sub(vtop, CC2_SVALUE_BYTES),
        and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)), 65535));
    wi32(sub(vtop, CC2_SVALUE_BYTES), type);
    vpop();
    return 0;
}

function gv_dup_(type, register_class, source_register, destination_register,
    temporary)
{
    type = ri32(vtop);
    if (eq(and(type, CC2_TCC_BASIC_TYPE_MASK), CC2_TCC_LONG_LONG_TYPE)) {
        if (not(eq(and(type, CC2_TCC_BITFIELD), 0))) {
            gv(CC2_INTEGER_REGISTER_CLASS);
            type = ri32(vtop);
        }
        lexpand();
        gv_dup();
        vswap();
        vrotb(3);
        gv_dup();
        vrotb(4);
        lbuild(type);
        vrotb(3);
        vrotb(3);
        vswap();
        lbuild(type);
        vswap();
    } else {
        register_class = CC2_INTEGER_REGISTER_CLASS;
        temporary = cc2_svalue_temporary();
        cc2_zero_bytes(temporary, CC2_SVALUE_BYTES);
        wi32(temporary, CC2_TCC_INT_TYPE);
        if (is_float(type)) {
            register_class = CC2_I386_FLOAT_REGISTER_CLASS;
            wi32(temporary, type);
        }
        source_register = gv(register_class);
        destination_register = get_reg(register_class);
        cc2_set_value_register(temporary, source_register);
        cc2_write_signed_constant(add(temporary,
            CC2_SVALUE_CONSTANT_OFFSET), 0);
        load(destination_register, temporary);
        vdup();
        if (not(eq(source_register, destination_register))) {
            cc2_set_value_register(vtop, destination_register);
        }
    }
    return 0;
}

function gv_dup()
{
    return gv_dup_(0, 0, 0, 0, 0);
}

function inc(post, token)
{
    test_lvalue();
    vdup();
    if (post) {
        gv_dup();
        vrotb(3);
        vrotb(3);
    }
    vpushi(sub(token, 163));
    gen_op(CC2_ASCII_PLUS);
    vstore();
    if (post) {
        vpop();
    }
    return 0;
}

function indir_(type_value, registers, target_type)
{
    type_value = ri32(vtop);
    if (not(eq(and(type_value, CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_POINTER_TYPE))) {
        if (eq(and(type_value, CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_FUNCTION_TYPE)) {
            return 0;
        }
        expect(mks("pointer"));
    }
    registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
    if (not(eq(and(registers, CC2_TCC_LVALUE), 0))) {
        gv(CC2_INTEGER_REGISTER_CLASS);
    }
    target_type = pointed_type(vtop);
    wi32(vtop, ri32(target_type));
    wi32(add(vtop, 4), ri32(add(target_type, 4)));
    type_value = ri32(vtop);
    if (and(and(eq(and(type_value, CC2_TCC_ARRAY_TYPE), 0),
        eq(and(type_value, CC2_TCC_VLA_TYPE), 0)),
        not(eq(and(type_value, CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_FUNCTION_TYPE)))) {
        registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
        cc2_set_value_register(vtop, or(and(registers, 65535),
            lvalue_type(type_value)));
    }
    return 0;
}

function indir()
{
    return indir_(0, 0, 0);
}

function cc2_comparison_types_temporary()
{
    if (eq(CC2_COMPARISON_TYPES_TEMPORARY, 0)) {
        CC2_COMPARISON_TYPES_TEMPORARY = malloc(16);
    }
    return CC2_COMPARISON_TYPES_TEMPORARY;
}

function check_comparison_pointer_types_(first_value, second_value, operation,
    first_type, second_type, first_basic_type, second_basic_type, temporary,
    stripped_qualifiers)
{
    if (or(is_null_pointer(first_value), is_null_pointer(second_value))) {
        return 0;
    }
    first_type = first_value;
    second_type = second_value;
    first_basic_type = and(ri32(first_type), CC2_TCC_BASIC_TYPE_MASK);
    second_basic_type = and(ri32(second_type), CC2_TCC_BASIC_TYPE_MASK);
    if (and(or(is_integer_btype(first_basic_type),
        is_integer_btype(second_basic_type)),
        not(eq(operation, CC2_ASCII_MINUS)))) {
        if (and(not(eq(operation, CC2_TOKEN_LOGICAL_OR)),
            not(eq(operation, CC2_TOKEN_LOGICAL_AND)))) {
            tcc_warning(mks("comparison between pointer and integer"), 0);
        }
        return 0;
    }
    if (eq(first_basic_type, CC2_TCC_POINTER_TYPE)) {
        first_type = pointed_type(first_type);
    } else if (not(eq(first_basic_type, CC2_TCC_FUNCTION_TYPE))) {
        tcc_error(mks("invalid operands to binary %s"),
            get_tok_str(operation, 0));
    }
    if (eq(second_basic_type, CC2_TCC_POINTER_TYPE)) {
        second_type = pointed_type(second_type);
    } else if (not(eq(second_basic_type, CC2_TCC_FUNCTION_TYPE))) {
        tcc_error(mks("invalid operands to binary %s"),
            get_tok_str(operation, 0));
    }
    if (or(eq(and(ri32(first_type), CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_VOID_TYPE),
        eq(and(ri32(second_type), CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_VOID_TYPE))) {
        return 0;
    }
    stripped_qualifiers = or(or(CC2_TCC_DEFAULT_SIGN,
        CC2_TCC_UNSIGNED_TYPE), or(CC2_TCC_CONST_QUALIFIER,
        CC2_TCC_VOLATILE_QUALIFIER));
    temporary = cc2_comparison_types_temporary();
    wi32(temporary, and(ri32(first_type), bnot(stripped_qualifiers)));
    wi32(add(temporary, 4), ri32(add(first_type, 4)));
    wi32(add(temporary, 8), and(ri32(second_type),
        bnot(stripped_qualifiers)));
    wi32(add(temporary, 12), ri32(add(second_type, 4)));
    if (eq(is_compatible_types(temporary, add(temporary, 8)), 0)) {
        if (eq(operation, CC2_ASCII_MINUS)) {
            tcc_error(mks("invalid operands to binary %s"),
                get_tok_str(operation, 0));
        } else {
            tcc_warning(mks("comparison of distinct pointer types lacks a cast"),
                0);
        }
    }
    return 0;
}

function check_comparison_pointer_types(first_value, second_value, operation)
{
    return check_comparison_pointer_types_(first_value, second_value,
        operation, 0, 0, 0, 0, 0, 0);
}

function cc2_is_enum_type(type_value)
{
    return eq(and(ushr(type_value, CC2_TCC_BITFIELD_POSITION_SHIFT),
        4095), 2);
}

function cc2_assignment_cast_error(source_type, destination_type, buffers)
{
    tcc_error_type_pair(source_type, destination_type);
    return 0;
}

function gen_assign_cast_(destination_type, source_type, destination_basic,
    source_basic, first_target, second_target, first_value, second_value)
{
    source_type = vtop;
    destination_basic = and(ri32(destination_type),
        CC2_TCC_BASIC_TYPE_MASK);
    source_basic = and(ri32(source_type), CC2_TCC_BASIC_TYPE_MASK);
    if (or(eq(source_basic, CC2_TCC_VOID_TYPE),
        eq(destination_basic, CC2_TCC_VOID_TYPE))) {
        if (not(and(eq(source_basic, CC2_TCC_VOID_TYPE),
            eq(destination_basic, CC2_TCC_VOID_TYPE)))) {
            tcc_error(mks("cannot cast from/to void"), 0);
        }
    }
    if (not(eq(and(ri32(destination_type),
        CC2_TCC_CONST_QUALIFIER), 0))) {
        tcc_warning(mks("assignment of read-only location"), 0);
    }
    if (eq(destination_basic, CC2_TCC_POINTER_TYPE)) {
        if (is_null_pointer(vtop)) {
            gen_cast(destination_type);
            return 0;
        }
        if (is_integer_btype(source_basic)) {
            tcc_warning(mks("assignment makes pointer from integer without a cast"),
                0);
            gen_cast(destination_type);
            return 0;
        }
        first_target = pointed_type(destination_type);
        if (eq(source_basic, CC2_TCC_FUNCTION_TYPE)) {
            if (and(not(eq(and(ri32(first_target),
                CC2_TCC_BASIC_TYPE_MASK), CC2_TCC_VOID_TYPE)),
                eq(is_compatible_types(first_target, source_type), 0))) {
                tcc_warning(mks("assignment from incompatible pointer type"),
                    0);
            }
            gen_cast(destination_type);
            return 0;
        }
        if (not(eq(source_basic, CC2_TCC_POINTER_TYPE))) {
            cc2_assignment_cast_error(source_type, destination_type, 0);
            return 0;
        }
        second_target = pointed_type(source_type);
        if (and(not(eq(and(ri32(first_target), CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_VOID_TYPE)),
            not(eq(and(ri32(second_target), CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_VOID_TYPE)))) {
            if (eq(is_compatible_unqualified_types(first_target,
                second_target), 0)) {
                first_value = ri32(first_target);
                second_value = ri32(second_target);
                if (or(not(eq(and(first_value, 2063),
                    and(second_value, 2063))),
                    or(cc2_is_enum_type(first_value),
                    cc2_is_enum_type(second_value)))) {
                    tcc_warning(mks("assignment from incompatible pointer type"),
                        0);
                }
            }
        }
        first_value = ri32(first_target);
        second_value = ri32(second_target);
        if (or(and(eq(and(first_value, CC2_TCC_CONST_QUALIFIER), 0),
            not(eq(and(second_value, CC2_TCC_CONST_QUALIFIER), 0))),
            and(eq(and(first_value, CC2_TCC_VOLATILE_QUALIFIER), 0),
            not(eq(and(second_value, CC2_TCC_VOLATILE_QUALIFIER), 0))))) {
            tcc_warning(mks("assignment discards qualifiers from pointer target type"),
                0);
        }
    } else if (or(or(eq(destination_basic, CC2_TCC_BYTE_TYPE),
        eq(destination_basic, CC2_TCC_SHORT_TYPE)),
        or(eq(destination_basic, CC2_TCC_INT_TYPE),
        eq(destination_basic, CC2_TCC_LONG_LONG_TYPE)))) {
        if (or(eq(source_basic, CC2_TCC_POINTER_TYPE),
            eq(source_basic, CC2_TCC_FUNCTION_TYPE))) {
            tcc_warning(mks("assignment makes integer from pointer without a cast"),
                0);
        } else if (eq(source_basic, CC2_TCC_STRUCT_TYPE)) {
            cc2_assignment_cast_error(source_type, destination_type, 0);
            return 0;
        }
    } else if (eq(destination_basic, CC2_TCC_STRUCT_TYPE)) {
        if (eq(is_compatible_unqualified_types(destination_type,
            source_type), 0)) {
            cc2_assignment_cast_error(source_type, destination_type, 0);
            return 0;
        }
    }
    gen_cast(destination_type);
    return 0;
}

function gen_assign_cast(destination_type)
{
    return gen_assign_cast_(destination_type, 0, 0, 0, 0, 0, 0, 0);
}

function cc2_is_relational_operation(operation)
{
    return and(le(CC2_TOKEN_UNSIGNED_LESS, operation),
        le(operation, CC2_TOKEN_LOGICAL_OR));
}

function cc2_unsigned_operation(operation)
{
    if (eq(operation, CC2_TOKEN_SHIFT_RIGHT)) {
        return CC2_TOKEN_UNSIGNED_SHIFT_RIGHT;
    }
    if (eq(operation, CC2_ASCII_SLASH)) {
        return CC2_TOKEN_UNSIGNED_DIVIDE;
    }
    if (eq(operation, CC2_ASCII_PERCENT)) {
        return CC2_TOKEN_UNSIGNED_MODULO;
    }
    if (eq(operation, CC2_TOKEN_SIGNED_LESS)) {
        return CC2_TOKEN_UNSIGNED_LESS;
    }
    if (eq(operation, CC2_TOKEN_SIGNED_GREATER)) {
        return CC2_TOKEN_UNSIGNED_GREATER;
    }
    if (eq(operation, CC2_TOKEN_SIGNED_LESS_EQUAL)) {
        return CC2_TOKEN_UNSIGNED_LESS_EQUAL;
    }
    if (eq(operation, CC2_TOKEN_SIGNED_GREATER_EQUAL)) {
        return CC2_TOKEN_UNSIGNED_GREATER_EQUAL;
    }
    return operation;
}

function cc2_is_shift_operation(operation)
{
    return or(eq(operation, CC2_TOKEN_UNSIGNED_SHIFT_RIGHT),
        or(eq(operation, CC2_TOKEN_SHIFT_RIGHT),
        eq(operation, CC2_TOKEN_SHIFT_LEFT)));
}

/* Type policy stays here; gen_opic and gen_opif only emit the selected i386
   integer or floating operation. */
function gen_op_(operation, first, second, first_type, second_type,
    first_basic, second_basic, result_type, element_size, temporary_type,
    registers)
{
    temporary_type = malloc(8);
    first = sub(vtop, CC2_SVALUE_BYTES);
    second = vtop;
    first_type = ri32(first);
    second_type = ri32(second);
    first_basic = and(first_type, CC2_TCC_BASIC_TYPE_MASK);
    second_basic = and(second_type, CC2_TCC_BASIC_TYPE_MASK);
    while (or(eq(first_basic, CC2_TCC_FUNCTION_TYPE),
        eq(second_basic, CC2_TCC_FUNCTION_TYPE))) {
        if (eq(second_basic, CC2_TCC_FUNCTION_TYPE)) {
            mk_pointer(second);
            gaddrof();
        }
        if (eq(first_basic, CC2_TCC_FUNCTION_TYPE)) {
            vswap();
            mk_pointer(vtop);
            gaddrof();
            vswap();
        }
        first = sub(vtop, CC2_SVALUE_BYTES);
        second = vtop;
        first_type = ri32(first);
        second_type = ri32(second);
        first_basic = and(first_type, CC2_TCC_BASIC_TYPE_MASK);
        second_basic = and(second_type, CC2_TCC_BASIC_TYPE_MASK);
    }
    if (or(eq(first_basic, CC2_TCC_STRUCT_TYPE),
        eq(second_basic, CC2_TCC_STRUCT_TYPE))) {
        tcc_error(mks("operation on a struct"), 0);
    } else if (or(eq(first_basic, CC2_TCC_POINTER_TYPE),
        eq(second_basic, CC2_TCC_POINTER_TYPE))) {
        if (cc2_is_relational_operation(operation)) {
            check_comparison_pointer_types(first, second, operation);
            result_type = or(CC2_TCC_INT_TYPE, CC2_TCC_UNSIGNED_TYPE);
        } else if (and(eq(first_basic, CC2_TCC_POINTER_TYPE),
            eq(second_basic, CC2_TCC_POINTER_TYPE))) {
            if (not(eq(operation, CC2_ASCII_MINUS))) {
                tcc_error(mks("cannot use pointers here"), 0);
            }
            check_comparison_pointer_types(first, second, operation);
            if (not(eq(and(first_type, CC2_TCC_VLA_TYPE), 0))) {
                vla_runtime_pointed_size(first);
            } else {
                vpushi(pointed_size(first));
            }
            vrott(3);
            gen_opic(operation);
            wi32(vtop, ri32(ptrdiff_type_address));
            wi32(add(vtop, 4), ri32(add(ptrdiff_type_address, 4)));
            vswap();
            gen_op(CC2_TOKEN_POINTER_DIVIDE);
            result_type = sub(0, 1);
        } else {
            if (and(not(eq(operation, CC2_ASCII_MINUS)),
                not(eq(operation, CC2_ASCII_PLUS)))) {
                tcc_error(mks("cannot use pointers here"), 0);
            }
            if (eq(second_basic, CC2_TCC_POINTER_TYPE)) {
                vswap();
                first = sub(vtop, CC2_SVALUE_BYTES);
                second = vtop;
                first_type = ri32(first);
                second_type = ri32(second);
            }
            if (eq(and(ri32(second), CC2_TCC_BASIC_TYPE_MASK),
                CC2_TCC_LONG_LONG_TYPE)) {
                gen_cast_s(CC2_TCC_INT_TYPE);
            }
            wi32(temporary_type, and(ri32(first),
                bnot(CC2_TCC_ARRAY_TYPE)));
            wi32(add(temporary_type, 4), ri32(add(first, 4)));
            if (not(eq(and(ri32(first), CC2_TCC_VLA_TYPE), 0))) {
                vla_runtime_pointed_size(first);
            } else {
                element_size = pointed_size(first);
                if (lt(element_size, 0)) {
                    tcc_error(mks("unknown array element size"), 0);
                }
                vpushi(element_size);
            }
            gen_op(CC2_ASCII_ASTERISK);
            gen_opic(operation);
            wi32(vtop, ri32(temporary_type));
            wi32(add(vtop, 4), ri32(add(temporary_type, 4)));
            result_type = sub(0, 1);
        }
    } else if (or(is_float(first_basic), is_float(second_basic))) {
        if (or(eq(first_basic, CC2_TCC_LONG_DOUBLE_TYPE),
            eq(second_basic, CC2_TCC_LONG_DOUBLE_TYPE))) {
            result_type = CC2_TCC_LONG_DOUBLE_TYPE;
        } else if (or(eq(first_basic, CC2_TCC_DOUBLE_TYPE),
            eq(second_basic, CC2_TCC_DOUBLE_TYPE))) {
            result_type = CC2_TCC_DOUBLE_TYPE;
        } else {
            result_type = CC2_TCC_FLOAT_TYPE;
        }
        if (and(and(and(not(eq(operation, CC2_ASCII_PLUS)),
            not(eq(operation, CC2_ASCII_MINUS))),
            and(not(eq(operation, CC2_ASCII_ASTERISK)),
            not(eq(operation, CC2_ASCII_SLASH)))),
            not(and(le(CC2_TOKEN_UNSIGNED_LESS, operation),
            le(operation, CC2_TOKEN_SIGNED_GREATER))))) {
            tcc_error(mks("invalid operands for binary operation"), 0);
        }
    } else if (cc2_is_shift_operation(operation)) {
        if (eq(first_basic, CC2_TCC_LONG_LONG_TYPE)) {
            result_type = CC2_TCC_LONG_LONG_TYPE;
        } else {
            result_type = CC2_TCC_INT_TYPE;
        }
        if (eq(and(first_type, 159),
            or(result_type, CC2_TCC_UNSIGNED_TYPE))) {
            result_type = or(result_type, CC2_TCC_UNSIGNED_TYPE);
        }
        result_type = or(result_type, and(first_type, 2048));
    } else if (or(eq(first_basic, CC2_TCC_LONG_LONG_TYPE),
        eq(second_basic, CC2_TCC_LONG_LONG_TYPE))) {
        result_type = or(CC2_TCC_LONG_LONG_TYPE, 2048);
        if (eq(first_basic, CC2_TCC_LONG_LONG_TYPE)) {
            result_type = and(result_type, first_type);
        }
        if (eq(second_basic, CC2_TCC_LONG_LONG_TYPE)) {
            result_type = and(result_type, second_type);
        }
        if (or(eq(and(first_type, 159),
            or(CC2_TCC_LONG_LONG_TYPE, CC2_TCC_UNSIGNED_TYPE)),
            eq(and(second_type, 159),
            or(CC2_TCC_LONG_LONG_TYPE, CC2_TCC_UNSIGNED_TYPE)))) {
            result_type = or(result_type, CC2_TCC_UNSIGNED_TYPE);
        }
    } else {
        result_type = or(CC2_TCC_INT_TYPE,
            and(or(first_type, second_type), 2048));
        if (or(eq(and(first_type, 159),
            or(CC2_TCC_INT_TYPE, CC2_TCC_UNSIGNED_TYPE)),
            eq(and(second_type, 159),
            or(CC2_TCC_INT_TYPE, CC2_TCC_UNSIGNED_TYPE)))) {
            result_type = or(result_type, CC2_TCC_UNSIGNED_TYPE);
        }
    }
    if (not(eq(result_type, sub(0, 1)))) {
        if (not(eq(and(result_type, CC2_TCC_UNSIGNED_TYPE), 0))) {
            operation = cc2_unsigned_operation(operation);
        }
        wi32(temporary_type, result_type);
        wi32(add(temporary_type, 4), 0);
        vswap();
        gen_cast(temporary_type);
        vswap();
        if (cc2_is_shift_operation(operation)) {
            wi32(temporary_type, CC2_TCC_INT_TYPE);
        }
        gen_cast(temporary_type);
        if (is_float(result_type)) {
            gen_opif(operation);
        } else {
            gen_opic(operation);
        }
        if (and(le(CC2_TOKEN_UNSIGNED_LESS, operation),
            le(operation, CC2_TOKEN_SIGNED_GREATER))) {
            wi32(vtop, CC2_TCC_INT_TYPE);
        } else {
            wi32(vtop, result_type);
        }
    }
    registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
    if (not(eq(and(registers, CC2_TCC_LVALUE), 0))) {
        if (is_float(and(ri32(vtop), CC2_TCC_BASIC_TYPE_MASK))) {
            gv(CC2_I386_FLOAT_REGISTER_CLASS);
        } else {
            gv(CC2_INTEGER_REGISTER_CLASS);
        }
    }
    free(temporary_type);
    return 0;
}

function gen_op(operation)
{
    return gen_op_(operation, 0, 0, 0, 0, 0, 0, sub(0, 1), 0, 0, 0);
}

function force_charshort_cast_(type, bits, basic_type, mask)
{
    if (not(eq(and(ushr(nocode_wanted, 30), 3), 0))) {
        return 0;
    }
    basic_type = and(type, CC2_TCC_BASIC_TYPE_MASK);
    if (eq(basic_type, CC2_TCC_BYTE_TYPE)) {
        bits = 8;
    } else {
        bits = 16;
    }
    if (not(eq(and(type, CC2_TCC_UNSIGNED_TYPE), 0))) {
        mask = sub(shl(1, bits), 1);
        vpushi(mask);
        gen_op(CC2_ASCII_AMPERSAND);
    } else {
        if (eq(and(ri32(vtop), CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_LONG_LONG_TYPE)) {
            bits = sub(64, bits);
        } else {
            bits = sub(32, bits);
        }
        vpushi(bits);
        gen_op(CC2_TOKEN_SHIFT_LEFT);
        wi32(vtop, and(ri32(vtop), bnot(CC2_TCC_UNSIGNED_TYPE)));
        vpushi(bits);
        gen_op(CC2_TOKEN_SHIFT_RIGHT);
    }
    return 0;
}

function force_charshort_cast(type)
{
    return force_charshort_cast_(type, 0, 0, 0);
}

function gen_cast_s_(type_value, type)
{
    type = malloc(8);
    wi32(type, type_value);
    wi32(add(type, 4), 0);
    gen_cast(type);
    free(type);
    return 0;
}

function gen_cast_s(type_value)
{
    return gen_cast_s_(type_value, 0);
}

/* Apply TCC's cast policy. Exact 64-bit and floating constant conversion is
   delegated to a representation primitive; all target-code decisions remain
   in this layer. */
function gen_cast_(type, source_type, destination_type, source_float,
    destination_float, location, symbolic_constant, registers, target_symbol,
    target_value)
{
    registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
    if (not(eq(and(registers, CC2_TCC_MUST_CAST), 0))) {
        cc2_set_value_register(vtop, and(registers,
            bnot(CC2_TCC_MUST_CAST)));
        force_charshort_cast(ri32(vtop));
    }
    if (not(eq(and(ri32(vtop), CC2_TCC_BITFIELD), 0))) {
        gv(CC2_INTEGER_REGISTER_CLASS);
    }

    destination_type = and(ri32(type), or(CC2_TCC_BASIC_TYPE_MASK,
        CC2_TCC_UNSIGNED_TYPE));
    source_type = and(ri32(vtop), or(CC2_TCC_BASIC_TYPE_MASK,
        CC2_TCC_UNSIGNED_TYPE));
    if (not(eq(source_type, destination_type))) {
        source_float = is_float(source_type);
        destination_float = is_float(destination_type);
        location = and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
            CC2_VALUE_TEST_MASK);
        symbolic_constant = eq(location,
            or(CC2_VALUE_CONSTANT, CC2_TCC_SYMBOL_VALUE));
        if (eq(location, CC2_VALUE_CONSTANT)) {
            gen_cast_constant(type);
        } else if (and(symbolic_constant,
            eq(destination_type, CC2_TCC_BOOLEAN_TYPE))) {
            cc2_set_value_register(vtop, CC2_VALUE_CONSTANT);
            wi32(add(vtop, CC2_SVALUE_CONSTANT_OFFSET), 1);
            wi32(add(vtop, add(CC2_SVALUE_CONSTANT_OFFSET, 4)), 0);
        } else if (and(source_float, destination_float)) {
            gen_cvt_ftof(destination_type);
        } else if (destination_float) {
            gen_cvt_itof1(destination_type);
        } else if (source_float) {
            if (eq(destination_type, CC2_TCC_BOOLEAN_TYPE)) {
                vpushi(0);
                gen_op(CC2_TOKEN_NOT_EQUAL);
            } else {
                target_value = destination_type;
                if (and(not(eq(destination_type, or(CC2_TCC_INT_TYPE,
                    CC2_TCC_UNSIGNED_TYPE))), and(not(eq(destination_type,
                    or(CC2_TCC_LONG_LONG_TYPE, CC2_TCC_UNSIGNED_TYPE))),
                    not(eq(destination_type, CC2_TCC_LONG_LONG_TYPE))))) {
                    destination_type = CC2_TCC_INT_TYPE;
                }
                gen_cvt_ftoi1(destination_type);
                if (and(eq(destination_type, CC2_TCC_INT_TYPE),
                    not(eq(target_value, destination_type)))) {
                    wi32(vtop, destination_type);
                    gen_cast(type);
                }
            }
        } else if (eq(and(destination_type, CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_LONG_LONG_TYPE)) {
            if (not(eq(and(source_type, CC2_TCC_BASIC_TYPE_MASK),
                CC2_TCC_LONG_LONG_TYPE))) {
                gv(CC2_INTEGER_REGISTER_CLASS);
                if (eq(source_type, or(CC2_TCC_INT_TYPE,
                    CC2_TCC_UNSIGNED_TYPE))) {
                    vpushi(0);
                    gv(CC2_INTEGER_REGISTER_CLASS);
                } else {
                    if (eq(source_type, CC2_TCC_POINTER_TYPE)) {
                        gen_cast_s(CC2_TCC_INT_TYPE);
                    }
                    gv_dup();
                    vpushi(31);
                    gen_op(CC2_TOKEN_SHIFT_RIGHT);
                }
                registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
                cc2_set_value_second_register(sub(vtop, CC2_SVALUE_BYTES),
                    and(registers, 65535));
                vpop();
            }
        } else if (eq(destination_type, CC2_TCC_BOOLEAN_TYPE)) {
            vpushi(0);
            gen_op(CC2_TOKEN_NOT_EQUAL);
        } else if (or(eq(and(destination_type, CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_BYTE_TYPE), eq(and(destination_type,
            CC2_TCC_BASIC_TYPE_MASK), CC2_TCC_SHORT_TYPE))) {
            if (eq(source_type, CC2_TCC_POINTER_TYPE)) {
                wi32(vtop, CC2_TCC_INT_TYPE);
                tcc_warning(mks("nonportable conversion from pointer to char/short"), 0);
            }
            force_charshort_cast(destination_type);
        } else if (eq(and(destination_type, CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_INT_TYPE)) {
            if (eq(and(source_type, CC2_TCC_BASIC_TYPE_MASK),
                CC2_TCC_LONG_LONG_TYPE)) {
                lexpand();
                vpop();
            }
        }
    } else if (and(eq(and(destination_type, CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_POINTER_TYPE), eq(and(ri32(add(vtop,
        CC2_SVALUE_REGISTER_OFFSET)), CC2_TCC_LVALUE), 0))) {
        registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
        target_symbol = ri32(add(type, 4));
        cc2_set_value_register(vtop, or(and(registers,
            bnot(CC2_VALUE_LVALUE_TYPE_MASK)), and(lvalue_type(ri32(add(
            target_symbol, CC2_SYM_TYPE_OFFSET))),
            CC2_VALUE_LVALUE_TYPE_MASK)));
    }
    wi32(vtop, ri32(type));
    wi32(add(vtop, 4), ri32(add(type, 4)));
    return 0;
}

function gen_cast(type)
{
    return gen_cast_(type, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

function gen_cvt_itof1(type)
{
    if (eq(and(ri32(vtop), or(CC2_TCC_BASIC_TYPE_MASK,
        CC2_TCC_UNSIGNED_TYPE)), or(CC2_TCC_LONG_LONG_TYPE,
        CC2_TCC_UNSIGNED_TYPE))) {
        if (eq(type, CC2_TCC_FLOAT_TYPE)) {
            vpush_global_sym(func_old_type_address,
                CC2_TOKEN_FLOAT_UNSIGNED_LONG_LONG_TO_FLOAT);
        } else if (eq(type, CC2_TCC_LONG_DOUBLE_TYPE)) {
            vpush_global_sym(func_old_type_address,
                CC2_TOKEN_FLOAT_UNSIGNED_LONG_LONG_TO_LONG_DOUBLE);
        } else {
            vpush_global_sym(func_old_type_address,
                CC2_TOKEN_FLOAT_UNSIGNED_LONG_LONG_TO_DOUBLE);
        }
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        cc2_set_value_register(vtop, reg_fret(type));
    } else {
        gen_cvt_itof(type);
    }
    return 0;
}

function gen_cvt_ftoi1(type)
{
    if (eq(type, or(CC2_TCC_LONG_LONG_TYPE, CC2_TCC_UNSIGNED_TYPE))) {
        if (eq(and(ri32(vtop), CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_FLOAT_TYPE)) {
            vpush_global_sym(func_old_type_address,
                CC2_TOKEN_FLOAT_TO_UNSIGNED_LONG_LONG);
        } else if (eq(and(ri32(vtop), CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_LONG_DOUBLE_TYPE)) {
            vpush_global_sym(func_old_type_address,
                CC2_TOKEN_LONG_DOUBLE_TO_UNSIGNED_LONG_LONG);
        } else {
            vpush_global_sym(func_old_type_address,
                CC2_TOKEN_DOUBLE_TO_UNSIGNED_LONG_LONG);
        }
        vrott(2);
        gfunc_call(1);
        vpushi(0);
        cc2_set_value_register(vtop, CC2_I386_INTEGER_RETURN_REGISTER);
        cc2_set_value_second_register(vtop,
            CC2_I386_LONG_LONG_RETURN_REGISTER);
    } else {
        gen_cvt_ftoi(type);
    }
    return 0;
}

function incr_bf_adr(offset)
{
    wi32(vtop, ri32(char_pointer_type));
    wi32(add(vtop, 4), ri32(add(char_pointer_type, 4)));
    gaddrof();
    vpushi(offset);
    gen_op(CC2_ASCII_PLUS);
    wi32(vtop, or(and(ri32(vtop), bnot(or(CC2_TCC_BASIC_TYPE_MASK,
        CC2_TCC_DEFAULT_SIGN))), or(CC2_TCC_BYTE_TYPE,
        CC2_TCC_UNSIGNED_TYPE)));
    cc2_set_value_register(vtop, or(and(ri32(add(vtop,
        CC2_SVALUE_REGISTER_OFFSET)), bnot(CC2_VALUE_LVALUE_TYPE_MASK)),
        or(or(CC2_TCC_LVALUE_BYTE, CC2_TCC_LVALUE_UNSIGNED),
        CC2_TCC_LVALUE)));
    return 0;
}

function adjust_bf(value, bit_position, bit_size)
{
    bit_position = bit_position;
    bit_size = bit_size;
    if (eq(ri32(add(value, 4)), 0)) {
        return 0;
    }
    bit_position = ri32(add(ri32(add(value, 4)), CC2_SYM_SCOPE_OFFSET));
    if (and(not(eq(bit_position, sub(0, 1))),
        not(eq(bit_position, CC2_TCC_STRUCT_TYPE)))) {
        wi32(value, or(and(ri32(value), bnot(CC2_TCC_BASIC_TYPE_MASK)),
            bit_position));
        cc2_set_value_register(value, or(and(ri32(add(value,
            CC2_SVALUE_REGISTER_OFFSET)), bnot(CC2_VALUE_LVALUE_TYPE_MASK)),
            lvalue_type(ri32(value))));
    }
    return bit_position;
}

function load_packed_bf_(type, bit_position, bit_size, count, offset, bits)
{
    save_reg_upstack(and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
        65535), 1);
    vpushi(0);
    wi32(vtop, and(ri32(type), CC2_TCC_BASIC_TYPE_MASK));
    wi32(add(vtop, add(CC2_SVALUE_CONSTANT_OFFSET, 4)), 0);
    bits = 0;
    offset = ushr(bit_position, 3);
    bit_position = and(bit_position, 7);
    while (bit_size) {
        vswap();
        incr_bf_adr(offset);
        vdup();
        count = sub(8, bit_position);
        if (lt(bit_size, count)) {
            count = bit_size;
        }
        if (bit_position) {
            vpushi(bit_position);
            gen_op(CC2_TOKEN_UNSIGNED_SHIFT_RIGHT);
            bit_position = 0;
        }
        if (lt(count, 8)) {
            vpushi(sub(shl(1, count), 1));
            gen_op(CC2_ASCII_AMPERSAND);
        }
        gen_cast(type);
        if (bits) {
            vpushi(bits);
            gen_op(CC2_TOKEN_SHIFT_LEFT);
        }
        vrotb(3);
        gen_op(CC2_ASCII_VERTICAL_BAR);
        bits = add(bits, count);
        bit_size = sub(bit_size, count);
        offset = 1;
    }
    vswap();
    vpop();
    if (eq(and(ri32(type), CC2_TCC_UNSIGNED_TYPE), 0)) {
        if (eq(and(ri32(type), CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_LONG_LONG_TYPE)) {
            count = sub(64, bits);
        } else {
            count = sub(32, bits);
        }
        vpushi(count);
        gen_op(CC2_TOKEN_SHIFT_LEFT);
        vpushi(count);
        gen_op(CC2_TOKEN_SHIFT_RIGHT);
    }
    return 0;
}

function load_packed_bf(type, bit_position, bit_size)
{
    return load_packed_bf_(type, bit_position, bit_size, 0, 0, 0);
}

function store_packed_bf_(bit_position, bit_size, bits, count, offset,
    mask, is_constant)
{
    is_constant = eq(and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
        CC2_VALUE_TEST_MASK), CC2_VALUE_CONSTANT);
    vswap();
    save_reg_upstack(and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
        65535), 1);
    bits = 0;
    offset = ushr(bit_position, 3);
    bit_position = and(bit_position, 7);
    while (bit_size) {
        incr_bf_adr(offset);
        vswap();
        if (is_constant) {
            vdup();
        } else {
            gv_dup();
        }
        vrott(3);
        if (bits) {
            vpushi(bits);
            gen_op(CC2_TOKEN_UNSIGNED_SHIFT_RIGHT);
        }
        if (bit_position) {
            vpushi(bit_position);
            gen_op(CC2_TOKEN_SHIFT_LEFT);
        }
        count = sub(8, bit_position);
        if (lt(bit_size, count)) {
            count = bit_size;
        }
        if (lt(count, 8)) {
            mask = shl(sub(shl(1, count), 1), bit_position);
            vpushi(mask);
            gen_op(CC2_ASCII_AMPERSAND);
            vpushv(sub(vtop, CC2_SVALUE_BYTES));
            if (and(mask, 128)) {
                vpushi(and(bnot(mask), 127));
            } else {
                vpushi(bnot(mask));
            }
            gen_op(CC2_ASCII_AMPERSAND);
            gen_op(CC2_ASCII_VERTICAL_BAR);
        }
        vdup();
        cc2_copy_svalue(sub(vtop, CC2_SVALUE_BYTES),
            sub(vtop, mul(2, CC2_SVALUE_BYTES)));
        vstore();
        vpop();
        bits = add(bits, count);
        bit_size = sub(bit_size, count);
        bit_position = 0;
        offset = 1;
    }
    vpop();
    vpop();
    return 0;
}

function store_packed_bf(bit_position, bit_size)
{
    return store_packed_bf_(bit_position, bit_size, 0, 0, 0, 0, 0);
}

function gv_(required_class, result_register, bit_position, bit_size,
    adjusted_type, bits, type, alignment, size, section, offset,
    second_class, registers, second_register, original_type, memory_type)
{
    type = ri32(vtop);
    if (not(eq(and(type, CC2_TCC_BITFIELD), 0))) {
        bit_position = and(ushr(type, CC2_TCC_BITFIELD_POSITION_SHIFT), 63);
        bit_size = and(ushr(type, CC2_TCC_BITFIELD_SIZE_SHIFT), 63);
        /* VT_STRUCT_MASK occupies the bitfield flag and bits 20..31. */
        wi32(vtop, and(type, 1048447));
        adjusted_type = malloc(8);
        wi32(add(adjusted_type, 4), 0);
        wi32(adjusted_type, and(ri32(vtop), CC2_TCC_UNSIGNED_TYPE));
        if (eq(and(ri32(vtop), CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_BOOLEAN_TYPE)) {
            wi32(adjusted_type, or(ri32(adjusted_type),
                CC2_TCC_UNSIGNED_TYPE));
        }
        result_register = adjust_bf(vtop, bit_position, bit_size);
        if (eq(and(ri32(vtop), CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_LONG_LONG_TYPE)) {
            wi32(adjusted_type, or(ri32(adjusted_type),
                CC2_TCC_LONG_LONG_TYPE));
            bits = 64;
        } else {
            wi32(adjusted_type, or(ri32(adjusted_type), CC2_TCC_INT_TYPE));
            bits = 32;
        }
        if (eq(result_register, CC2_TCC_STRUCT_TYPE)) {
            load_packed_bf(adjusted_type, bit_position, bit_size);
        } else {
            gen_cast(adjusted_type);
            vpushi(sub(bits, add(bit_position, bit_size)));
            gen_op(CC2_TOKEN_SHIFT_LEFT);
            vpushi(sub(bits, bit_size));
            gen_op(CC2_TOKEN_SHIFT_RIGHT);
        }
        free(adjusted_type);
        return gv(required_class);
    }

    registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
    if (and(is_float(type), eq(and(registers,
        or(CC2_VALUE_LOCATION_MASK, CC2_TCC_LVALUE)),
        CC2_VALUE_CONSTANT))) {
        alignment = malloc(4);
        size = type_size(vtop, alignment);
        if (lt(0, nocode_wanted)) {
            size = 0;
            wi32(alignment, 1);
        }
        section = ri32(data_section_address);
        offset = section_add(section, size, ri32(alignment));
        vpush_ref(vtop, section, offset, size);
        vswap();
        init_putv(vtop, section, offset);
        cc2_set_value_register(vtop, or(ri32(add(vtop,
            CC2_SVALUE_REGISTER_OFFSET)), CC2_TCC_LVALUE));
        free(alignment);
    }

    registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
    result_register = and(registers, CC2_VALUE_LOCATION_MASK);
    if (not(eq(and(required_class, CC2_I386_FLOAT_REGISTER_CLASS), 0))) {
        second_class = CC2_I386_FLOAT_REGISTER_CLASS;
    } else {
        second_class = CC2_INTEGER_REGISTER_CLASS;
    }
    if (eq(required_class, CC2_I386_INTEGER_RETURN_CLASS)) {
        second_class = CC2_I386_LONG_LONG_RETURN_CLASS;
    }
    if (or(or(or(le(CC2_VALUE_CONSTANT, result_register),
        not(eq(and(registers, CC2_TCC_LVALUE), 0))),
        eq(and(cc2_i386_register_class(result_register), required_class), 0)),
        and(eq(and(type, CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_LONG_LONG_TYPE), eq(and(cc2_i386_register_class(and(ushr(
        registers, 16), CC2_VALUE_LOCATION_MASK)), second_class), 0)))) {
        result_register = get_reg(required_class);
        /* Allocation can spill the current value, so reload its state. */
        registers = ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET));
        type = ri32(vtop);
        if (eq(and(type, CC2_TCC_BASIC_TYPE_MASK),
            CC2_TCC_LONG_LONG_TYPE)) {
            original_type = type;
            if (eq(and(registers, or(CC2_VALUE_LOCATION_MASK,
                CC2_TCC_LVALUE)), CC2_VALUE_CONSTANT)) {
                memory_type = ri32(add(vtop,
                    add(CC2_SVALUE_CONSTANT_OFFSET, 4)));
                load(result_register, vtop);
                cc2_set_value_register(vtop, result_register);
                vpushi(memory_type);
            } else if (not(eq(and(registers, CC2_TCC_LVALUE), 0))) {
                save_reg_upstack(and(registers, 65535), 1);
                wi32(vtop, CC2_TCC_INT_TYPE);
                load(result_register, vtop);
                vdup();
                cc2_set_value_register(sub(vtop, CC2_SVALUE_BYTES),
                    result_register);
                wi32(vtop, CC2_TCC_INT_TYPE);
                gaddrof();
                vpushi(4);
                gen_op(CC2_ASCII_PLUS);
                cc2_set_value_register(vtop, or(ri32(add(vtop,
                    CC2_SVALUE_REGISTER_OFFSET)), CC2_TCC_LVALUE));
                wi32(vtop, CC2_TCC_INT_TYPE);
            } else {
                load(result_register, vtop);
                vdup();
                cc2_set_value_register(sub(vtop, CC2_SVALUE_BYTES),
                    result_register);
                cc2_set_value_register(vtop, and(ushr(registers, 16),
                    65535));
            }
            second_register = get_reg(second_class);
            load(second_register, vtop);
            vpop();
            cc2_set_value_second_register(vtop, second_register);
            wi32(vtop, original_type);
        } else if (and(not(eq(and(registers, CC2_TCC_LVALUE), 0)),
            eq(is_float(type), 0))) {
            memory_type = type;
            if (not(eq(and(registers, CC2_TCC_LVALUE_BYTE), 0))) {
                memory_type = CC2_TCC_BYTE_TYPE;
            } else if (not(eq(and(registers, CC2_TCC_LVALUE_SHORT), 0))) {
                memory_type = CC2_TCC_SHORT_TYPE;
            }
            if (not(eq(and(registers, CC2_TCC_LVALUE_UNSIGNED), 0))) {
                memory_type = or(memory_type, CC2_TCC_UNSIGNED_TYPE);
            }
            wi32(vtop, memory_type);
            load(result_register, vtop);
            wi32(vtop, type);
        } else {
            load(result_register, vtop);
        }
    }
    cc2_set_value_register(vtop, result_register);
    return result_register;
}

function gv(required_class)
{
    return gv_(required_class, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0);
}

function gv2(first_class, second_class)
{
    var location;
    location = and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
        CC2_VALUE_LOCATION_MASK);
    if (and(and(not(eq(location, CC2_VALUE_COMPARISON)),
        not(eq(and(location, bnot(1)), CC2_VALUE_JUMP))),
        le(first_class, second_class))) {
        vswap();
        gv(first_class);
        vswap();
        gv(second_class);
        if (le(CC2_VALUE_CONSTANT, and(ri32(add(sub(vtop,
            CC2_SVALUE_BYTES), CC2_SVALUE_REGISTER_OFFSET)),
            CC2_VALUE_LOCATION_MASK))) {
            vswap();
            gv(first_class);
            vswap();
        }
    } else {
        gv(second_class);
        vswap();
        gv(first_class);
        vswap();
        if (le(CC2_VALUE_CONSTANT, and(ri32(add(vtop,
            CC2_SVALUE_REGISTER_OFFSET)), CC2_VALUE_LOCATION_MASK))) {
            gv(second_class);
        }
    }
    return 0;
}

function gvtst(inverted, jump_chain)
{
    var location;
    var value;
    location = and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
        CC2_VALUE_LOCATION_MASK);
    if (and(not(eq(location, CC2_VALUE_COMPARISON)), and(not(eq(location,
        CC2_VALUE_JUMP)), not(eq(location, CC2_VALUE_JUMP_FALSE))))) {
        vpushi(0);
        gen_op(CC2_TOKEN_NOT_EQUAL);
    }
    if (eq(and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
        CC2_VALUE_TEST_MASK), CC2_VALUE_CONSTANT)) {
        value = not(eq(ri32(add(vtop, CC2_SVALUE_CONSTANT_OFFSET)), 0));
        if (not(eq(value, inverted))) {
            jump_chain = gjmp(jump_chain);
        }
        vtop = sub(vtop, CC2_SVALUE_BYTES);
        return jump_chain;
    }
    return gtst(inverted, jump_chain);
}

function cc2_swap_svalues_(first, second, temporary)
{
    temporary = malloc(CC2_SVALUE_BYTES);
    cc2_copy_svalue(temporary, first);
    cc2_copy_svalue(first, second);
    cc2_copy_svalue(second, temporary);
    free(temporary);
    return 0;
}

function cc2_swap_svalues(first, second)
{
    return cc2_swap_svalues_(first, second, 0);
}

function gen_opl_call_helper(token)
{
    vpush_global_sym(func_old_type_address, token);
    vrott(3);
    gfunc_call(2);
    vpushi(0);
    cc2_set_value_register(vtop, CC2_I386_INTEGER_RETURN_REGISTER);
    cc2_set_value_second_register(vtop,
        CC2_I386_LONG_LONG_RETURN_REGISTER);
    return 0;
}

function gen_opl_(operation, type, first_jump, second_jump,
    word_operation, shift, index, helper)
{
    if (or(or(eq(operation, CC2_ASCII_SLASH),
        eq(operation, CC2_TOKEN_POINTER_DIVIDE)),
        eq(operation, CC2_TOKEN_UNSIGNED_DIVIDE))) {
        if (eq(operation, CC2_TOKEN_UNSIGNED_DIVIDE)) {
            helper = CC2_TOKEN_UNSIGNED_LONG_LONG_DIVIDE;
        } else {
            helper = CC2_TOKEN_SIGNED_LONG_LONG_DIVIDE;
        }
        return gen_opl_call_helper(helper);
    }
    if (or(eq(operation, CC2_ASCII_PERCENT),
        eq(operation, CC2_TOKEN_UNSIGNED_MODULO))) {
        if (eq(operation, CC2_TOKEN_UNSIGNED_MODULO)) {
            helper = CC2_TOKEN_UNSIGNED_LONG_LONG_MODULO;
        } else {
            helper = CC2_TOKEN_SIGNED_LONG_LONG_MODULO;
        }
        return gen_opl_call_helper(helper);
    }
    if (or(or(or(eq(operation, CC2_ASCII_CARET),
        eq(operation, CC2_ASCII_AMPERSAND)),
        or(eq(operation, CC2_ASCII_VERTICAL_BAR),
        eq(operation, CC2_ASCII_ASTERISK))),
        or(eq(operation, CC2_ASCII_PLUS),
        eq(operation, CC2_ASCII_MINUS)))) {
        type = ri32(vtop);
        vswap();
        lexpand();
        vrotb(3);
        lexpand();
        cc2_swap_svalues(vtop, sub(vtop, mul(3, CC2_SVALUE_BYTES)));
        cc2_swap_svalues(sub(vtop, mul(2, CC2_SVALUE_BYTES)),
            sub(vtop, mul(3, CC2_SVALUE_BYTES)));
        vswap();
        if (eq(operation, CC2_ASCII_ASTERISK)) {
            vpushv(sub(vtop, CC2_SVALUE_BYTES));
            vpushv(sub(vtop, CC2_SVALUE_BYTES));
            gen_op(CC2_TOKEN_UNSIGNED_MULTIPLY_LONG_LONG);
            lexpand();
            index = 0;
            while (lt(index, 4)) {
                vrotb(6);
                index = add(index, 1);
            }
            cc2_swap_svalues(vtop, sub(vtop, mul(2, CC2_SVALUE_BYTES)));
            gen_op(CC2_ASCII_ASTERISK);
            vrotb(3);
            vrotb(3);
            gen_op(CC2_ASCII_ASTERISK);
            gen_op(CC2_ASCII_PLUS);
            gen_op(CC2_ASCII_PLUS);
        } else if (or(eq(operation, CC2_ASCII_PLUS),
            eq(operation, CC2_ASCII_MINUS))) {
            if (eq(operation, CC2_ASCII_PLUS)) {
                word_operation = CC2_TOKEN_ADD_CARRY_FIRST;
            } else {
                word_operation = CC2_TOKEN_SUBTRACT_CARRY_FIRST;
            }
            gen_op(word_operation);
            vrotb(3);
            vrotb(3);
            gen_op(add(word_operation, 1));
        } else {
            gen_op(operation);
            vrotb(3);
            vrotb(3);
            gen_op(operation);
        }
        return lbuild(type);
    }
    if (or(or(eq(operation, CC2_TOKEN_SHIFT_RIGHT),
        eq(operation, CC2_TOKEN_UNSIGNED_SHIFT_RIGHT)),
        eq(operation, CC2_TOKEN_SHIFT_LEFT))) {
        if (eq(and(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
            CC2_VALUE_TEST_MASK), CC2_VALUE_CONSTANT)) {
            type = ri32(sub(vtop, CC2_SVALUE_BYTES));
            vswap();
            lexpand();
            vrotb(3);
            shift = ri32(add(vtop, CC2_SVALUE_CONSTANT_OFFSET));
            vpop();
            if (not(eq(operation, CC2_TOKEN_SHIFT_LEFT))) {
                vswap();
            }
            if (le(32, shift)) {
                vpop();
                if (lt(32, shift)) {
                    vpushi(sub(shift, 32));
                    gen_op(operation);
                }
                if (not(eq(operation, CC2_TOKEN_SHIFT_RIGHT))) {
                    vpushi(0);
                } else {
                    gv_dup();
                    vpushi(31);
                    gen_op(CC2_TOKEN_SHIFT_RIGHT);
                }
                vswap();
            } else {
                vswap();
                gv_dup();
                vpushi(shift);
                gen_op(operation);
                vswap();
                vpushi(sub(32, shift));
                if (eq(operation, CC2_TOKEN_SHIFT_LEFT)) {
                    gen_op(CC2_TOKEN_UNSIGNED_SHIFT_RIGHT);
                } else {
                    gen_op(CC2_TOKEN_SHIFT_LEFT);
                }
                vrotb(3);
                vpushi(shift);
                if (eq(operation, CC2_TOKEN_SHIFT_LEFT)) {
                    gen_op(CC2_TOKEN_SHIFT_LEFT);
                } else {
                    gen_op(CC2_TOKEN_UNSIGNED_SHIFT_RIGHT);
                }
                gen_op(CC2_ASCII_VERTICAL_BAR);
            }
            if (not(eq(operation, CC2_TOKEN_SHIFT_LEFT))) {
                vswap();
            }
            return lbuild(type);
        }
        if (eq(operation, CC2_TOKEN_SHIFT_RIGHT)) {
            helper = CC2_TOKEN_ARITHMETIC_SHIFT_RIGHT_LONG_LONG;
        } else if (eq(operation, CC2_TOKEN_UNSIGNED_SHIFT_RIGHT)) {
            helper = CC2_TOKEN_LOGICAL_SHIFT_RIGHT_LONG_LONG;
        } else {
            helper = CC2_TOKEN_SHIFT_LEFT_LONG_LONG;
        }
        return gen_opl_call_helper(helper);
    }

    type = ri32(vtop);
    vswap();
    lexpand();
    vrotb(3);
    lexpand();
    cc2_swap_svalues(sub(vtop, CC2_SVALUE_BYTES),
        sub(vtop, mul(2, CC2_SVALUE_BYTES)));
    word_operation = operation;
    if (eq(word_operation, CC2_TOKEN_SIGNED_LESS)) {
        word_operation = CC2_TOKEN_SIGNED_LESS_EQUAL;
    } else if (eq(word_operation, CC2_TOKEN_SIGNED_GREATER)) {
        word_operation = CC2_TOKEN_SIGNED_GREATER_EQUAL;
    } else if (eq(word_operation, CC2_TOKEN_UNSIGNED_LESS)) {
        word_operation = CC2_TOKEN_UNSIGNED_LESS_EQUAL;
    } else if (eq(word_operation, CC2_TOKEN_UNSIGNED_GREATER)) {
        word_operation = CC2_TOKEN_UNSIGNED_GREATER_EQUAL;
    }
    first_jump = 0;
    second_jump = 0;
    gen_op(word_operation);
    if (eq(operation, CC2_TOKEN_NOT_EQUAL)) {
        second_jump = gvtst(0, 0);
    } else {
        first_jump = gvtst(1, 0);
        if (not(eq(operation, CC2_TOKEN_EQUAL))) {
            vpushi(CC2_TOKEN_NOT_EQUAL);
            cc2_set_value_register(vtop, CC2_VALUE_COMPARISON);
            second_jump = gvtst(0, 0);
        }
    }
    word_operation = operation;
    if (eq(word_operation, CC2_TOKEN_SIGNED_LESS)) {
        word_operation = CC2_TOKEN_UNSIGNED_LESS;
    } else if (eq(word_operation, CC2_TOKEN_SIGNED_LESS_EQUAL)) {
        word_operation = CC2_TOKEN_UNSIGNED_LESS_EQUAL;
    } else if (eq(word_operation, CC2_TOKEN_SIGNED_GREATER)) {
        word_operation = CC2_TOKEN_UNSIGNED_GREATER;
    } else if (eq(word_operation, CC2_TOKEN_SIGNED_GREATER_EQUAL)) {
        word_operation = CC2_TOKEN_UNSIGNED_GREATER_EQUAL;
    }
    gen_op(word_operation);
    first_jump = gvtst(1, first_jump);
    gsym(second_jump);
    vseti(CC2_VALUE_JUMP_FALSE, first_jump);
    return 0;
}

function gen_opl(operation)
{
    return gen_opl_(operation, 0, 0, 0, 0, 0, 0, 0);
}

function expr_type(type, mode)
{
    nocode_wanted = add(nocode_wanted, 1);
    if (eq(mode, CC2_EXPRESSION_MODE_UNARY)) {
        unary();
    } else if (eq(mode, CC2_EXPRESSION_MODE_EQUALITY)) {
        expr_eq();
    } else {
        gexpr();
    }
    wi32(type, ri32(vtop));
    wi32(add(type, 4), ri32(add(vtop, 4)));
    vpop();
    nocode_wanted = sub(nocode_wanted, 1);
    return 0;
}

function parse_expr_type_(type, attributes, identifier)
{
    attributes = malloc(20);
    identifier = malloc(4);
    skip(40);
    if (parse_btype(type, attributes)) {
        type_decl(type, attributes, identifier, 1);
    } else {
        expr_type(type, CC2_EXPRESSION_MODE_COMMA);
    }
    skip(41);
    free(attributes);
    free(identifier);
    return 0;
}

function parse_expr_type(type)
{
    return parse_expr_type_(type, 0, 0);
}

function parse_type_(type, attributes, identifier)
{
    attributes = malloc(20);
    identifier = malloc(4);
    if (eq(parse_btype(type, attributes), 0)) {
        expect(mks("type"));
    }
    type_decl(type, attributes, identifier, 1);
    free(attributes);
    free(identifier);
    return 0;
}

function parse_type(type)
{
    return parse_type_(type, 0, 0);
}

function parse_builtin_params_(no_code, arguments, character, separator,
    type)
{
    if (no_code) {
        nocode_wanted = add(nocode_wanted, 1);
    }
    next();
    separator = 40;
    while (ri8(arguments)) {
        character = ri8(arguments);
        arguments = add(arguments, 1);
        skip(separator);
        separator = 44;
        if (eq(character, 101)) {
            expr_eq();
        } else if (eq(character, 116)) {
            type = malloc(8);
            parse_type(type);
            vpush(type);
            free(type);
        } else {
            tcc_error(mks("internal error"), 0);
        }
    }
    skip(41);
    if (no_code) {
        nocode_wanted = sub(nocode_wanted, 1);
    }
    return 0;
}

function parse_builtin_params(no_code, arguments)
{
    return parse_builtin_params_(no_code, arguments, 0, 0, 0);
}

function expr_const_(words, low_word, high_word, signed_high_word)
{
    words = malloc(8);
    expr_const64_words(words);
    low_word = ri32(words);
    high_word = ri32(add(words, 4));
    if (lt(low_word, 0)) {
        signed_high_word = sub(0, 1);
    } else {
        signed_high_word = 0;
    }
    if (and(not(eq(high_word, signed_high_word)),
        not(eq(high_word, 0)))) {
        tcc_error(mks("constant exceeds 32 bit"), 0);
    }
    free(words);
    return low_word;
}

function expr_const()
{
    return expr_const_(0, 0, 0, 0);
}

function cc2_token_is_two(token, first, second)
{
    return or(eq(token, first), eq(token, second));
}

function cc2_token_is_three(token, first, second, third)
{
    return or(cc2_token_is_two(token, first, second), eq(token, third));
}

function cc2_attribute_set_call(attributes, call)
{
    wi32(add(attributes, 4), or(and(ri32(add(attributes, 4)),
        bnot(CC2_FUNCTION_CALL_MASK)), call));
    return 0;
}

function cc2_attribute_set_visibility(attributes, visibility)
{
    wi32(attributes, or(and(ri32(attributes),
        bnot(CC2_ATTRIBUTE_VISIBILITY_MASK)),
        shl(visibility, CC2_ATTRIBUTE_VISIBILITY_SHIFT)));
    return 0;
}

function parse_attribute_(attributes, token, value, string, data,
    parenthesis, aligned)
{
    while (cc2_token_is_two(ri32(tok_address), CC2_TOKEN_ATTRIBUTE_FIRST,
        CC2_TOKEN_ATTRIBUTE_SECOND)) {
        next();
        skip(40);
        skip(40);
        while (not(eq(ri32(tok_address), 41))) {
            if (lt(ri32(tok_address), CC2_TOKEN_IDENTIFIER)) {
                expect(mks("attribute name"));
            }
            token = ri32(tok_address);
            next();
            if (cc2_token_is_two(token, CC2_TOKEN_SECTION_FIRST,
                CC2_TOKEN_SECTION_SECOND)) {
                string = malloc(12);
                skip(40);
                parse_mult_str(string, mks("section name"));
                data = ri32(add(string, 4));
                wi32(add(attributes, CC2_ATTRIBUTE_SECTION_OFFSET),
                    find_section(tcc_state_address, data));
                skip(41);
                cstr_free(string);
                free(string);
            } else if (cc2_token_is_two(token, CC2_TOKEN_ALIAS_FIRST,
                CC2_TOKEN_ALIAS_SECOND)) {
                string = malloc(12);
                skip(40);
                parse_mult_str(string, mks("alias(\"target\")"));
                data = ri32(add(string, 4));
                value = tok_alloc(data, sub(ri32(string), 1));
                wi32(add(attributes, CC2_ATTRIBUTE_ALIAS_OFFSET),
                    ri32(add(value, 20)));
                skip(41);
                cstr_free(string);
                free(string);
            } else if (cc2_token_is_two(token,
                CC2_TOKEN_VISIBILITY_FIRST, CC2_TOKEN_VISIBILITY_SECOND)) {
                string = malloc(12);
                skip(40);
                parse_mult_str(string, mks("visibility(\"default|hidden|internal|protected\")"));
                data = ri32(add(string, 4));
                if (eq(strcmp(data, mks("default")), 0)) {
                    cc2_attribute_set_visibility(attributes, 0);
                } else if (eq(strcmp(data, mks("hidden")), 0)) {
                    cc2_attribute_set_visibility(attributes, 2);
                } else if (eq(strcmp(data, mks("internal")), 0)) {
                    cc2_attribute_set_visibility(attributes, 1);
                } else if (eq(strcmp(data, mks("protected")), 0)) {
                    cc2_attribute_set_visibility(attributes, 3);
                } else {
                    expect(mks("visibility(\"default|hidden|internal|protected\")"));
                }
                skip(41);
                cstr_free(string);
                free(string);
            } else if (cc2_token_is_two(token, CC2_TOKEN_ALIGNED_FIRST,
                CC2_TOKEN_ALIGNED_SECOND)) {
                if (eq(ri32(tok_address), 40)) {
                    next();
                    value = expr_const();
                    if (or(le(value, 0), not(eq(and(value,
                        sub(value, 1)), 0)))) {
                        tcc_error(mks("alignment must be a positive power of two"), 0);
                    }
                    skip(41);
                } else {
                    value = 8;
                }
                aligned = exact_log2p1(value);
                wi32(attributes, or(and(ri32(attributes),
                    bnot(CC2_ATTRIBUTE_ALIGNED_MASK)), aligned));
                if (not(eq(value, shl(1, sub(aligned, 1))))) {
                    tcc_error(mks("alignment of %d is larger than implemented"), value);
                }
            } else if (cc2_token_is_two(token, CC2_TOKEN_PACKED_FIRST,
                CC2_TOKEN_PACKED_SECOND)) {
                wi32(attributes, or(ri32(attributes),
                    CC2_ATTRIBUTE_PACKED));
            } else if (cc2_token_is_two(token, CC2_TOKEN_WEAK_FIRST,
                CC2_TOKEN_WEAK_SECOND)) {
                wi32(attributes, or(ri32(attributes), CC2_ATTRIBUTE_WEAK));
            } else if (or(cc2_token_is_two(token, CC2_TOKEN_UNUSED_FIRST,
                CC2_TOKEN_UNUSED_SECOND), cc2_token_is_two(token,
                CC2_TOKEN_NORETURN_FIRST, CC2_TOKEN_NORETURN_SECOND))) {
            } else if (cc2_token_is_three(token, CC2_TOKEN_CDECL_FIRST,
                CC2_TOKEN_CDECL_SECOND, CC2_TOKEN_CDECL_THIRD)) {
                cc2_attribute_set_call(attributes, 0);
            } else if (cc2_token_is_three(token, CC2_TOKEN_STDCALL_FIRST,
                CC2_TOKEN_STDCALL_SECOND, CC2_TOKEN_STDCALL_THIRD)) {
                cc2_attribute_set_call(attributes, CC2_FUNCTION_STDCALL);
            } else if (cc2_token_is_two(token, CC2_TOKEN_REGPARM_FIRST,
                CC2_TOKEN_REGPARM_SECOND)) {
                skip(40);
                value = expr_const();
                if (lt(3, value)) {
                    value = 3;
                } else if (lt(value, 0)) {
                    value = 0;
                }
                if (lt(0, value)) {
                    cc2_attribute_set_call(attributes, add(
                        CC2_FUNCTION_FASTCALL_FIRST, sub(value, 1)));
                }
                skip(41);
            } else if (cc2_token_is_three(token, CC2_TOKEN_FASTCALL_FIRST,
                CC2_TOKEN_FASTCALL_SECOND, CC2_TOKEN_FASTCALL_THIRD)) {
                cc2_attribute_set_call(attributes,
                    CC2_FUNCTION_FASTCALL_WINDOWS);
            } else if (eq(token, CC2_TOKEN_MODE)) {
                skip(40);
                token = ri32(tok_address);
                if (eq(token, CC2_TOKEN_MODE_DI)) {
                    wi8(add(attributes, CC2_ATTRIBUTE_MODE_OFFSET),
                        add(CC2_TCC_LONG_LONG_TYPE, 1));
                } else if (eq(token, CC2_TOKEN_MODE_QI)) {
                    wi8(add(attributes, CC2_ATTRIBUTE_MODE_OFFSET),
                        add(CC2_TCC_BYTE_TYPE, 1));
                } else if (eq(token, CC2_TOKEN_MODE_HI)) {
                    wi8(add(attributes, CC2_ATTRIBUTE_MODE_OFFSET),
                        add(CC2_TCC_SHORT_TYPE, 1));
                } else if (or(eq(token, CC2_TOKEN_MODE_SI),
                    eq(token, CC2_TOKEN_MODE_WORD))) {
                    wi8(add(attributes, CC2_ATTRIBUTE_MODE_OFFSET),
                        add(CC2_TCC_INT_TYPE, 1));
                } else {
                    tcc_warning(mks("__mode__(%s) not supported\n"),
                        get_tok_str(token, 0));
                }
                next();
                skip(41);
            } else if (eq(token, CC2_TOKEN_DLLEXPORT)) {
                wi32(attributes, or(ri32(attributes),
                    CC2_ATTRIBUTE_DLLEXPORT));
            } else if (eq(token, CC2_TOKEN_DLLIMPORT)) {
                wi32(attributes, or(ri32(attributes),
                    CC2_ATTRIBUTE_DLLIMPORT));
            } else {
                if (ri32(add(tcc_state_address,
                    CC2_TCC_STATE_WARN_UNSUPPORTED_OFFSET))) {
                    tcc_warning(mks("'%s' attribute ignored"),
                        get_tok_str(token, 0));
                }
                if (eq(ri32(tok_address), 40)) {
                    parenthesis = 0;
                    while (or(eq(parenthesis, 0), and(parenthesis,
                        not(eq(ri32(tok_address), sub(0, 1)))))) {
                        if (eq(ri32(tok_address), 40)) {
                            parenthesis = add(parenthesis, 1);
                        } else if (eq(ri32(tok_address), 41)) {
                            parenthesis = sub(parenthesis, 1);
                        }
                        next();
                        if (eq(parenthesis, 0)) {
                            parenthesis = 0;
                            break;
                        }
                    }
                }
            }
            if (not(eq(ri32(tok_address), 44))) {
                break;
            }
            next();
        }
        skip(41);
        skip(41);
    }
    return 0;
}

function parse_attribute(attributes)
{
    return parse_attribute_(attributes, 0, 0, 0, 0, 0, 0);
}

function vstore_(destination_type, source_basic, destination_basic,
    delayed_cast, size, alignment, bit_position, bit_size, result_register,
    adjusted_access, register_class, address_register, temporary_value,
    registers)
{
    destination_type = ri32(sub(vtop, CC2_SVALUE_BYTES));
    source_basic = and(ri32(vtop), CC2_TCC_BASIC_TYPE_MASK);
    destination_basic = and(destination_type, CC2_TCC_BASIC_TYPE_MASK);
    if (and(or(and(or(eq(source_basic, CC2_TCC_INT_TYPE),
        eq(source_basic, CC2_TCC_SHORT_TYPE)),
        eq(destination_basic, CC2_TCC_BYTE_TYPE)), and(eq(source_basic,
        CC2_TCC_INT_TYPE), eq(destination_basic, CC2_TCC_SHORT_TYPE))),
        eq(and(ri32(vtop), CC2_TCC_BITFIELD), 0))) {
        delayed_cast = CC2_TCC_MUST_CAST;
        wi32(vtop, and(destination_type, CC2_TCC_TYPE_MASK));
        if (not(eq(and(destination_type, CC2_TCC_CONST_QUALIFIER), 0))) {
            tcc_warning(mks("assignment of read-only location"), 0);
        }
    } else {
        delayed_cast = 0;
        if (eq(and(destination_type, CC2_TCC_BITFIELD), 0)) {
            gen_assign_cast(sub(vtop, CC2_SVALUE_BYTES));
        }
    }

    if (eq(source_basic, CC2_TCC_STRUCT_TYPE)) {
        alignment = malloc(4);
        size = type_size(vtop, alignment);
        vswap();
        wi32(vtop, CC2_TCC_POINTER_TYPE);
        gaddrof();
        vpush_global_sym(func_old_type_address, CC2_TOKEN_MEMMOVE);
        vswap();
        vpushv(sub(vtop, mul(2, CC2_SVALUE_BYTES)));
        wi32(vtop, CC2_TCC_POINTER_TYPE);
        gaddrof();
        vpushi(size);
        gfunc_call(3);
        free(alignment);
    } else if (not(eq(and(destination_type, CC2_TCC_BITFIELD), 0))) {
        vdup();
        cc2_copy_svalue(sub(vtop, CC2_SVALUE_BYTES),
            sub(vtop, mul(2, CC2_SVALUE_BYTES)));
        bit_position = and(ushr(destination_type,
            CC2_TCC_BITFIELD_POSITION_SHIFT), 63);
        bit_size = and(ushr(destination_type,
            CC2_TCC_BITFIELD_SIZE_SHIFT), 63);
        wi32(sub(vtop, CC2_SVALUE_BYTES), and(destination_type, 1048447));
        if (eq(destination_basic, CC2_TCC_BOOLEAN_TYPE)) {
            gen_cast(sub(vtop, CC2_SVALUE_BYTES));
            wi32(sub(vtop, CC2_SVALUE_BYTES), or(and(ri32(sub(vtop,
                CC2_SVALUE_BYTES)), bnot(CC2_TCC_BASIC_TYPE_MASK)),
                or(CC2_TCC_BYTE_TYPE, CC2_TCC_UNSIGNED_TYPE)));
        }
        adjusted_access = adjust_bf(sub(vtop, CC2_SVALUE_BYTES),
            bit_position, bit_size);
        if (eq(adjusted_access, CC2_TCC_STRUCT_TYPE)) {
            if (eq(destination_basic, CC2_TCC_LONG_LONG_TYPE)) {
                gen_cast_s(CC2_TCC_LONG_LONG_TYPE);
            } else {
                gen_cast_s(CC2_TCC_INT_TYPE);
            }
            store_packed_bf(bit_position, bit_size);
        } else {
            if (not(eq(destination_basic, CC2_TCC_BOOLEAN_TYPE))) {
                vpush_bitfield_mask(and(ri32(sub(vtop, CC2_SVALUE_BYTES)),
                    CC2_TCC_BASIC_TYPE_MASK), bit_size, 0, 0);
                gen_op(CC2_ASCII_AMPERSAND);
            }
            vpushi(bit_position);
            gen_op(CC2_TOKEN_SHIFT_LEFT);
            vswap();
            vdup();
            vrott(3);
            vpush_bitfield_mask(and(ri32(vtop), CC2_TCC_BASIC_TYPE_MASK),
                bit_size, bit_position, 1);
            gen_op(CC2_ASCII_AMPERSAND);
            gen_op(CC2_ASCII_VERTICAL_BAR);
            vstore();
            vpop();
        }
    } else if (eq(destination_basic, CC2_TCC_VOID_TYPE)) {
        vtop = sub(vtop, CC2_SVALUE_BYTES);
    } else {
        register_class = CC2_INTEGER_REGISTER_CLASS;
        if (is_float(destination_type)) {
            register_class = CC2_I386_FLOAT_REGISTER_CLASS;
        }
        result_register = gv(register_class);
        registers = ri32(add(sub(vtop, CC2_SVALUE_BYTES),
            CC2_SVALUE_REGISTER_OFFSET));
        if (eq(and(registers, CC2_VALUE_LOCATION_MASK),
            CC2_VALUE_LOCAL_LVALUE)) {
            address_register = get_reg(CC2_INTEGER_REGISTER_CLASS);
            temporary_value = malloc(CC2_SVALUE_BYTES);
            cc2_zero_bytes(temporary_value, CC2_SVALUE_BYTES);
            wi32(temporary_value, CC2_TCC_INT_TYPE);
            cc2_set_value_register(temporary_value,
                or(CC2_VALUE_LOCAL, CC2_TCC_LVALUE));
            wi32(add(temporary_value, CC2_SVALUE_CONSTANT_OFFSET), ri32(add(
                sub(vtop, CC2_SVALUE_BYTES), CC2_SVALUE_CONSTANT_OFFSET)));
            load(address_register, temporary_value);
            cc2_set_value_register(sub(vtop, CC2_SVALUE_BYTES),
                or(address_register, CC2_TCC_LVALUE));
            free(temporary_value);
        }
        if (eq(destination_basic, CC2_TCC_LONG_LONG_TYPE)) {
            wi32(sub(vtop, CC2_SVALUE_BYTES), CC2_TCC_INT_TYPE);
            store(result_register, sub(vtop, CC2_SVALUE_BYTES));
            vswap();
            wi32(vtop, CC2_TCC_INT_TYPE);
            gaddrof();
            vpushi(4);
            gen_op(CC2_ASCII_PLUS);
            cc2_set_value_register(vtop, or(ri32(add(vtop,
                CC2_SVALUE_REGISTER_OFFSET)), CC2_TCC_LVALUE));
            vswap();
            wi32(sub(vtop, CC2_SVALUE_BYTES), CC2_TCC_INT_TYPE);
            store(and(ushr(ri32(add(vtop, CC2_SVALUE_REGISTER_OFFSET)),
                16), 65535), sub(vtop, CC2_SVALUE_BYTES));
        } else {
            store(result_register, sub(vtop, CC2_SVALUE_BYTES));
        }
        vswap();
        vtop = sub(vtop, CC2_SVALUE_BYTES);
        cc2_set_value_register(vtop, or(ri32(add(vtop,
            CC2_SVALUE_REGISTER_OFFSET)), delayed_cast));
    }
    return 0;
}

function vstore()
{
    return vstore_(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

function gfunc_return_(function_type, value_type, return_type, alignment,
    register_size, return_registers, return_alignment, size, address,
    register_class)
{
    if (eq(and(ri32(function_type), CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_STRUCT_TYPE)) {
        value_type = malloc(8);
        return_type = malloc(8);
        alignment = malloc(4);
        register_size = malloc(4);
        return_registers = gfunc_sret(function_type, func_var, return_type,
            alignment, register_size);
        return_alignment = ri32(alignment);
        if (eq(return_registers, 0)) {
            wi32(value_type, ri32(function_type));
            wi32(add(value_type, 4), ri32(add(function_type, 4)));
            mk_pointer(value_type);
            vset(value_type, or(CC2_VALUE_LOCAL, CC2_TCC_LVALUE),
                func_vc);
            indir();
            vswap();
            vstore();
        } else {
            size = type_size(function_type, alignment);
            if (and(or(not(eq(and(ri32(add(vtop,
                CC2_SVALUE_REGISTER_OFFSET)), 65535),
                or(CC2_VALUE_LOCAL, CC2_TCC_LVALUE))),
                not(eq(and(ri32(add(vtop, CC2_SVALUE_CONSTANT_OFFSET)),
                sub(return_alignment, 1)), 0))), not(eq(and(ri32(alignment),
                sub(return_alignment, 1)), 0)))) {
                loc = and(sub(loc, size), sub(0, return_alignment));
                address = loc;
                wi32(value_type, ri32(function_type));
                wi32(add(value_type, 4), ri32(add(function_type, 4)));
                vset(value_type, or(CC2_VALUE_LOCAL,
                    CC2_TCC_LVALUE), address);
                vswap();
                vstore();
                vpop();
                vset(return_type, or(CC2_VALUE_LOCAL,
                    CC2_TCC_LVALUE), address);
            }
            wi32(vtop, ri32(return_type));
            wi32(add(vtop, 4), ri32(add(return_type, 4)));
            if (is_float(ri32(return_type))) {
                register_class = rc_fret(ri32(return_type));
            } else {
                register_class = CC2_I386_INTEGER_RETURN_CLASS;
            }
            if (eq(return_registers, 1)) {
                gv(register_class);
            } else {
                while (return_registers) {
                    vdup();
                    gv(register_class);
                    vpop();
                    return_registers = sub(return_registers, 1);
                    if (return_registers) {
                        register_class = shl(register_class, 1);
                        wi32(add(vtop, CC2_SVALUE_CONSTANT_OFFSET), add(ri32(
                            add(vtop, CC2_SVALUE_CONSTANT_OFFSET)),
                            ri32(register_size)));
                    }
                }
            }
        }
        free(value_type);
        free(return_type);
        free(alignment);
        free(register_size);
    } else if (is_float(ri32(function_type))) {
        gv(rc_fret(ri32(function_type)));
    } else {
        gv(CC2_I386_INTEGER_RETURN_CLASS);
    }
    vtop = sub(vtop, CC2_SVALUE_BYTES);
    return 0;
}

function gfunc_return(function_type)
{
    return gfunc_return_(function_type, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

/* Apply C storage and visibility attributes to TCC's ELF32 symbol. */
function update_storage_(symbol, elf_symbol, attributes, visibility,
    binding, previous_binding, info)
{
    elf_symbol = elfsym(symbol);
    if (eq(elf_symbol, 0)) {
        return 0;
    }
    attributes = ushr(ri32(add(symbol, 4)), 16);
    visibility = and(ushr(attributes, 7), 3);
    if (visibility) {
        wi8(add(elf_symbol, 13), or(and(ri8(add(elf_symbol, 13)),
            bnot(3)), visibility));
    }
    if (not(eq(and(ri32(add(symbol, CC2_SYM_TYPE_OFFSET)),
        CC2_TCC_STATIC_STORAGE), 0))) {
        binding = 0;
    } else if (not(eq(and(attributes, 64), 0))) {
        binding = 2;
    } else {
        binding = 1;
    }
    info = ri8(add(elf_symbol, 12));
    previous_binding = ushr(info, 4);
    if (not(eq(binding, previous_binding))) {
        wi8(add(elf_symbol, 12), or(shl(binding, 4), and(info, 15)));
    }
    return 0;
}

function update_storage(symbol)
{
    return update_storage_(symbol, 0, 0, 0, 0, 0, 0);
}

function is_label_(identifier_floor, saved_token)
{
    if (lt(ri32(tok_address), identifier_floor)) {
        return 0;
    }
    saved_token = ri32(tok_address);
    next();
    if (eq(ri32(tok_address), 58)) {
        return saved_token;
    }
    unget_tok(saved_token);
    return 0;
}

function is_label(identifier_floor)
{
    return is_label_(identifier_floor, 0);
}

function parse_btype_qualify_(type, qualifiers, type_value, symbol)
{
    type_value = ri32(type);
    while (not(eq(and(type_value, CC2_TCC_ARRAY_TYPE), 0))) {
        symbol = ri32(add(type, 4));
        symbol = sym_push(CC2_SYMBOL_FIELD_FLAG,
            add(symbol, CC2_SYM_TYPE_OFFSET), 0,
            ri32(add(symbol, CC2_SYM_CONSTANT_OFFSET)));
        wi32(add(type, 4), symbol);
        type = add(symbol, CC2_SYM_TYPE_OFFSET);
        type_value = ri32(type);
    }
    wi32(type, or(type_value, qualifiers));
    return 0;
}

function parse_btype_qualify(type, qualifiers)
{
    return parse_btype_qualify_(type, qualifiers, 0, 0);
}

function convert_parameter_type_(type, type_value)
{
    type_value = and(ri32(type), bnot(or(CC2_TCC_CONST_QUALIFIER,
        CC2_TCC_VOLATILE_QUALIFIER)));
    type_value = and(type_value, bnot(CC2_TCC_ARRAY_TYPE));
    wi32(type, type_value);
    if (eq(and(type_value, CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_FUNCTION_TYPE)) {
        mk_pointer(type);
    }
    return 0;
}

function convert_parameter_type(type)
{
    return convert_parameter_type_(type, 0);
}

function sym_to_attr_(attributes, symbol, symbol_attributes,
    declaration_attributes, symbol_function, declaration_function,
    aligned, function_call, function_type)
{
    symbol_attributes = and(ushr(ri32(add(symbol, 4)), 16), 65535);
    declaration_attributes = and(ri32(attributes), 65535);
    aligned = and(symbol_attributes, 31);
    if (not(eq(aligned, 0))) {
        if (eq(and(declaration_attributes, 31), 0)) {
            declaration_attributes = or(declaration_attributes, aligned);
        }
    }
    if (not(eq(and(symbol_attributes, 32), 0))) {
        declaration_attributes = or(declaration_attributes, 32);
    }
    wi32(attributes, or(and(ri32(attributes), bnot(65535)),
        declaration_attributes));
    symbol_function = ri32(add(symbol, CC2_SYM_FUNCTION_ATTRIBUTES_OFFSET));
    declaration_function = ri32(add(attributes, 4));
    function_call = and(symbol_function, 7);
    if (not(eq(function_call, 0))) {
        if (eq(and(declaration_function, 7), 0)) {
            declaration_function = or(declaration_function, function_call);
        }
    }
    function_type = and(symbol_function, 24);
    if (not(eq(function_type, 0))) {
        if (eq(and(declaration_function, 24), 0)) {
            declaration_function = or(declaration_function, function_type);
        }
    }
    wi32(add(attributes, 4), declaration_function);
    return 0;
}

function sym_to_attr(attributes, symbol)
{
    return sym_to_attr_(attributes, symbol, 0, 0, 0, 0, 0, 0, 0);
}

function cc2_symbol_name(symbol)
{
    return get_tok_str(ri32(add(symbol, CC2_SYM_VALUE_OFFSET)), 0);
}

function patch_type_(symbol, type, symbol_type, new_type, static_storage,
    symbol_reference, new_reference, new_count, old_count)
{
    symbol_type = ri32(add(symbol, CC2_SYM_TYPE_OFFSET));
    new_type = ri32(type);
    if (eq(and(new_type, CC2_TCC_EXTERN_STORAGE), 0)) {
        if (eq(and(symbol_type, CC2_TCC_EXTERN_STORAGE), 0)) {
            tcc_error(mks("redefinition of '%s'"), cc2_symbol_name(symbol));
        }
        symbol_type = and(symbol_type, bnot(CC2_TCC_EXTERN_STORAGE));
        wi32(add(symbol, CC2_SYM_TYPE_OFFSET), symbol_type);
    }
    if (eq(and(symbol_type, 31), CC2_TCC_ASSEMBLER_TYPE)) {
        symbol_type = and(new_type,
            or(symbol_type, bnot(CC2_TCC_STATIC_STORAGE)));
        wi32(add(symbol, CC2_SYM_TYPE_OFFSET), symbol_type);
        wi32(add(symbol, CC2_SYM_TYPE_REFERENCE_OFFSET), ri32(add(type, 4)));
    }
    symbol_type = ri32(add(symbol, CC2_SYM_TYPE_OFFSET));
    if (eq(is_compatible_types(add(symbol, CC2_SYM_TYPE_OFFSET), type), 0)) {
        tcc_error(mks("incompatible types for redefinition of '%s'"),
            cc2_symbol_name(symbol));
    } else if (eq(and(symbol_type, CC2_TCC_BASIC_TYPE_MASK),
        CC2_TCC_FUNCTION_TYPE)) {
        static_storage = and(symbol_type, CC2_TCC_STATIC_STORAGE);
        if (and(not(eq(and(new_type, CC2_TCC_STATIC_STORAGE), 0)),
            and(eq(static_storage, 0),
            eq(and(new_type, CC2_TCC_INLINE_STORAGE), 0)))) {
            tcc_warning(mks("static storage ignored for redefinition of '%s'"),
                cc2_symbol_name(symbol));
        }
        if (eq(and(new_type, CC2_TCC_EXTERN_STORAGE), 0)) {
            symbol_type = or(and(new_type,
                bnot(CC2_TCC_STATIC_STORAGE)), static_storage);
            if (not(eq(and(new_type, CC2_TCC_INLINE_STORAGE), 0))) {
                symbol_type = new_type;
            }
            wi32(add(symbol, CC2_SYM_TYPE_OFFSET), symbol_type);
            wi32(add(symbol, CC2_SYM_TYPE_REFERENCE_OFFSET),
                ri32(add(type, 4)));
        }
    } else {
        if (not(eq(and(symbol_type, CC2_TCC_ARRAY_TYPE), 0))) {
            new_reference = ri32(add(type, 4));
            new_count = ri32(add(new_reference, CC2_SYM_CONSTANT_OFFSET));
            if (le(0, new_count)) {
                symbol_reference = ri32(add(symbol,
                    CC2_SYM_TYPE_REFERENCE_OFFSET));
                old_count = ri32(add(symbol_reference,
                    CC2_SYM_CONSTANT_OFFSET));
                if (lt(old_count, 0)) {
                    wi32(add(symbol_reference, CC2_SYM_CONSTANT_OFFSET),
                        new_count);
                } else if (not(eq(old_count, new_count))) {
                    tcc_error(mks("conflicting type for '%s'"),
                        cc2_symbol_name(symbol));
                }
            }
        }
        if (not(eq(and(xor(new_type, symbol_type),
            CC2_TCC_STATIC_STORAGE), 0))) {
            tcc_warning(mks("storage mismatch for redefinition of '%s'"),
                cc2_symbol_name(symbol));
        }
    }
    return 0;
}

function patch_type(symbol, type)
{
    return patch_type_(symbol, type, 0, 0, 0, 0, 0, 0, 0);
}

function patch_storage_(symbol, attributes, type, symbol_attributes,
    new_attributes, visibility, new_visibility, aligned, asm_label)
{
    if (not(eq(type, 0))) {
        patch_type(symbol, type);
    }
    symbol_attributes = and(ushr(ri32(add(symbol, 4)), 16), 65535);
    new_attributes = and(ri32(attributes), 65535);
    symbol_attributes = or(symbol_attributes,
        and(new_attributes, CC2_SYM_ATTRIBUTE_WEAK));
    new_visibility = and(new_attributes,
        CC2_SYM_ATTRIBUTE_VISIBILITY_MASK);
    if (not(eq(new_visibility, 0))) {
        visibility = and(symbol_attributes,
            CC2_SYM_ATTRIBUTE_VISIBILITY_MASK);
        if (eq(visibility, 0)) {
            visibility = new_visibility;
        } else if (lt(new_visibility, visibility)) {
            visibility = new_visibility;
        }
        symbol_attributes = or(and(symbol_attributes,
            bnot(CC2_SYM_ATTRIBUTE_VISIBILITY_MASK)), visibility);
    }
    aligned = and(new_attributes, CC2_SYM_ATTRIBUTE_ALIGNED_MASK);
    if (not(eq(aligned, 0))) {
        symbol_attributes = or(and(symbol_attributes,
            bnot(CC2_SYM_ATTRIBUTE_ALIGNED_MASK)), aligned);
    }
    wi32(add(symbol, 4), or(and(ri32(add(symbol, 4)), 65535),
        shl(symbol_attributes, 16)));
    asm_label = ri32(add(attributes, 16));
    if (not(eq(asm_label, 0))) {
        wi32(add(symbol, CC2_SYM_NEXT_OFFSET), asm_label);
    }
    update_storage(symbol);
    return 0;
}

function patch_storage(symbol, attributes, type)
{
    return patch_storage_(symbol, attributes, type, 0, 0, 0, 0, 0, 0);
}

function external_sym_(value, type, reg, attributes, symbol,
    registers, symbol_attributes)
{
    symbol = sym_find(value);
    if (eq(symbol, 0)) {
        symbol = sym_push(value, type,
            or(or(reg, CC2_VALUE_CONSTANT), CC2_TCC_SYMBOL_VALUE), 0);
        wi32(add(symbol, CC2_SYM_TYPE_OFFSET),
            or(ri32(add(symbol, CC2_SYM_TYPE_OFFSET)),
            CC2_TCC_EXTERN_STORAGE));
        registers = ri32(add(symbol, 4));
        symbol_attributes = and(ri32(attributes), 65535);
        wi32(add(symbol, 4), or(and(registers, 65535),
            shl(symbol_attributes, 16)));
        wi32(add(symbol, CC2_SYM_SCOPE_OFFSET), 0);
    } else {
        if (eq(ri32(add(symbol, CC2_SYM_TYPE_REFERENCE_OFFSET)),
            ri32(add(func_old_type_address, 4)))) {
            wi32(add(symbol, CC2_SYM_TYPE_REFERENCE_OFFSET),
                ri32(add(type, 4)));
            registers = ri32(add(symbol, 4));
            wi32(add(symbol, 4), or(and(registers, bnot(65535)),
                or(or(reg, CC2_VALUE_CONSTANT), CC2_TCC_SYMBOL_VALUE)));
            wi32(add(symbol, CC2_SYM_TYPE_OFFSET),
                or(ri32(add(symbol, CC2_SYM_TYPE_OFFSET)),
                CC2_TCC_EXTERN_STORAGE));
        }
        patch_storage(symbol, attributes, type);
    }
    return symbol;
}

function external_sym(value, type, reg, attributes)
{
    return external_sym_(value, type, reg, attributes, 0, 0, 0);
}

function vpushv_(value, limit)
{
    limit = vstack_limit;
    if (not(lt(vtop, limit))) {
        vstack_overflow_error(vtop, limit);
    }
    vtop = add(vtop, CC2_SVALUE_BYTES);
    cc2_copy_svalue(vtop, value);
    return 0;
}

function vpushv(value)
{
    return vpushv_(value, 0);
}

function vdup()
{
    return vpushv(vtop);
}

function vrotb_(count, current, first)
{
    first = sub(vtop, mul(sub(count, 1), CC2_SVALUE_BYTES));
    cc2_copy_svalue(cc2_svalue_temporary(), first);
    current = first;
    while (not(eq(current, vtop))) {
        cc2_copy_svalue(current, add(current, CC2_SVALUE_BYTES));
        current = add(current, CC2_SVALUE_BYTES);
    }
    cc2_copy_svalue(vtop, cc2_svalue_temporary());
    return 0;
}

function vrotb(count)
{
    return vrotb_(count, 0, 0);
}

function vrote_(entry, count, index)
{
    cc2_copy_svalue(cc2_svalue_temporary(), entry);
    index = 0;
    while (lt(index, sub(count, 1))) {
        cc2_copy_svalue(sub(entry, mul(index, CC2_SVALUE_BYTES)),
            sub(entry, mul(add(index, 1), CC2_SVALUE_BYTES)));
        index = add(index, 1);
    }
    cc2_copy_svalue(sub(entry, mul(sub(count, 1), CC2_SVALUE_BYTES)),
        cc2_svalue_temporary());
    return 0;
}

function vrote(entry, count)
{
    return vrote_(entry, count, 0);
}

function vrott(count)
{
    return vrote(vtop, count);
}

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

function cc2_lower_arrays_(index, token, next, after, record, end,
    brace_depth)
{
    index = 0;
    brace_depth = 0;
    CC2_ARRAY_COUNT = 0;
    CC2_TOKEN_COUNT = 0;
    CC2_TOKENS = 0;
    CC2_TOKEN_CAPACITY = 0;
    CC2_INPUT_TOKEN_COUNT = cc1_layer_token_count();
    while (lt(index, CC2_INPUT_TOKEN_COUNT)) {
        token = cc2_token_at(index);
        if (eq(cc2_token_kind(token), 123)) {
            brace_depth = add(brace_depth, 1);
        } else if (eq(cc2_token_kind(token), 125)) {
            brace_depth = sub(brace_depth, 1);
        }
        next = token;
        after = token;
        if (lt(add(index, 1), CC2_INPUT_TOKEN_COUNT)) {
            next = cc2_token_at(add(index, 1));
        }
        if (lt(add(index, 2), CC2_INPUT_TOKEN_COUNT)) {
            after = cc2_token_at(add(index, 2));
        }
        if (not(eq(brace_depth, 0))) {
            if (lt(add(index, 5), CC2_INPUT_TOKEN_COUNT)) {
                if (eq(cc2_token_kind(token), 2)) {
                    if (eq(cc2_token_kind(next), 2)) {
                        if (eq(cc2_token_kind(after), 91)) {
                            if (eq(cc2_token_kind(cc2_token_at(add(index, 3))),
                                3)) {
                                if (eq(cc2_token_kind(cc2_token_at(add(index,
                                    4))), 93)) {
                                    if (eq(cc2_token_kind(cc2_token_at(add(
                                        index, 5))), 59)) {
                                        if (cc2_emit_array_declaration(token,
                                            next, cc2_token_at(add(index,
                                            3)))) {
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
    return cc2_lower_arrays_(0, 0, 0, 0, 0, 0, 0);
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

function is_float(type)
{
    var basic_type;
    basic_type = and(type, CC2_TCC_BASIC_TYPE_MASK);
    return or(or(eq(basic_type, CC2_TCC_LONG_DOUBLE_TYPE),
        eq(basic_type, CC2_TCC_DOUBLE_TYPE)),
        or(eq(basic_type, CC2_TCC_FLOAT_TYPE),
        eq(basic_type, CC2_TCC_QUAD_FLOAT_TYPE)));
}

function is_integer_btype(basic_type)
{
    return or(or(eq(basic_type, CC2_TCC_BYTE_TYPE),
        eq(basic_type, CC2_TCC_SHORT_TYPE)),
        or(eq(basic_type, CC2_TCC_INT_TYPE),
        eq(basic_type, CC2_TCC_LONG_LONG_TYPE)));
}

/* i386 returns every floating representation through the x87 ST0 class. */
function rc_fret(type)
{
    return CC2_I386_FLOAT_RETURN_CLASS;
}

function reg_fret(type)
{
    return CC2_I386_FLOAT_RETURN_REGISTER;
}

function vla_sp_restore()
{
    if (vlas_in_scope) {
        gen_vla_sp_restore(vla_sp_loc);
    }
    return 0;
}

function vla_sp_restore_root()
{
    if (vlas_in_scope) {
        gen_vla_sp_restore(vla_sp_root_loc);
    }
    return 0;
}
