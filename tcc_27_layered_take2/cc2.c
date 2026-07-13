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
var CC2_VALUE_BOUNDED = 32768;
var CC2_TCC_INLINE_STORAGE = 32768;
var CC2_SYM_ATTRIBUTE_ALIGNED_MASK = 31;
var CC2_SYM_ATTRIBUTE_WEAK = 64;
var CC2_SYM_ATTRIBUTE_VISIBILITY_MASK = 384;

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
