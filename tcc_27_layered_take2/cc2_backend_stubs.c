function neg_zero(basic_type)
{
    return 0;
}

function vpush64_words(type, low_word, high_word)
{
    return 0;
}

function cc2_toksym_alloc(size)
{
    return malloc(size);
}

function cc2_format_token_integer(output, low, high)
{
    sprintf(output, mks("%u"), low);
    return 0;
}

function tcc_set_options(state, text)
{
    return 0;
}

function cc2_local_time(fields)
{
    return 0;
}

function cc2_error_scope(state, is_assembler, file_type)
{
    return 0;
}

function cc2_preprocess_start_bridge(state, is_assembler)
{
    return 0;
}

function cc2_tcc_preprocess_bridge(state)
{
    return 0;
}

function cc2_tccpp_new_bridge(state)
{
    return 0;
}

function cc2_tcc_state_slot()
{
    return 0;
}

function cc2_tcc_state_count_slot()
{
    return 0;
}

function cc2_stderr()
{
    return 0;
}

function cc2_stdout()
{
    return 0;
}

function cc2_call_error_function(function_pointer, opaque, message)
{
    return 0;
}

function cc2_longjmp_error(state)
{
    return 0;
}

function cc2_clock_ms()
{
    return 0;
}

function u64_mul_add(words, base, digit)
{
    return 0;
}

function u64_ge(words, low, high)
{
    return 0;
}

function store_strtof(destination, text)
{
    return 0;
}

function store_strtod(destination, text)
{
    return 0;
}

function store_strtold(destination, text)
{
    return 0;
}

function store_ldexp_float(destination, words, exponent)
{
    return 0;
}

function store_ldexp_double(destination, words, exponent)
{
    return 0;
}

function store_ldexp_long_double(destination, words, exponent)
{
    return 0;
}

function elfsym(symbol)
{
    return 0;
}

function vpush_bitfield_mask(type, size, position, invert)
{
    return 0;
}

function tcc_error(format, value)
{
    return 0;
}

function tcc_warning(format, value)
{
    return 0;
}

function tcc_error_noabort(format, value)
{
    return 0;
}

function cc2_dlsym_default(name)
{
    return 0;
}

function cc2_float_promote(value, source_basic)
{
    return 0;
}

function cc2_integer64_to_long_double(value, is_unsigned)
{
    return 0;
}

function cc2_integer32_to_long_double(value, is_unsigned)
{
    return 0;
}

function cc2_float_narrow(value, destination_basic)
{
    return 0;
}

function cc2_long_double_to_unsigned64(value)
{
    return 0;
}

function cc2_long_double_to_signed64(value)
{
    return 0;
}

function cc2_long_double_nonzero(value)
{
    return 0;
}

function type_to_str(buffer, buffer_size, type, variable)
{
    return 0;
}

function gen_opic_fold_constant(operation)
{
    return 0;
}

function gen_opic_power_shift()
{
    return sub(0, 1);
}

function gen_opic_merge_addend(operation)
{
    return 0;
}

function cc2_float_finite(value, basic_type)
{
    return 0;
}

function cc2_float_zero(value, basic_type)
{
    return 0;
}

function cc2_float_add(left, right, basic_type)
{
    return 0;
}

function cc2_float_subtract(left, right, basic_type)
{
    return 0;
}

function cc2_float_multiply(left, right, basic_type)
{
    return 0;
}

function cc2_float_divide(left, right, basic_type)
{
    return 0;
}

function cc2_i386_instruction_table()
{
    return 0;
}

function cc2_i386_zero_operand_codes()
{
    return 0;
}

function cc2_i386_segment_prefix_table()
{
    return 0;
}

function cc2_i386_test_bit_table()
{
    return 0;
}

function case_sort(base, count)
{
    return 0;
}

function cc2_dlopen_global(filename)
{
    return 0;
}

function cc2_bind_tcc_globals(state)
{
    return 0;
}
