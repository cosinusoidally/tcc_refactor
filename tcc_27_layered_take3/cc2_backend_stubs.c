function neg_zero(basic_type)
{
    return 0;
}

function cc2_toksym_alloc(size)
{
    return malloc(size);
}

function cc2_format_token_integer(output, low, high)
{
    sprintf(output, mks("%u"), low, 0);
    return 0;
}

function cc2_local_time(fields)
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

function vpush_bitfield_mask(type, size, position, invert)
{
    return 0;
}

function tcc_error(format, value, extra)
{
    puts(format);
    if (eq(strcmp(format, mks("redeclaration of '%s'")), 0)) {
        puts(value);
    }
    exit(1);
    return 1;
}

function tcc_warning(format, value, extra1, extra2)
{
    puts(format);
    if (eq(strcmp(format, mks("implicit declaration of function '%s'")),
        0)) {
        puts(value);
    }
    return 0;
}

function tcc_error_noabort(format, value, extra1, extra2)
{
    puts(format);
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
