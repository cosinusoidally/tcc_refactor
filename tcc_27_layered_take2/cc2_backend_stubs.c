function asm_global_instr()
{
    return 0;
}

function decl_record_inline(symbol)
{
    return 0;
}

function neg_zero(basic_type)
{
    return 0;
}

function vpush64_words(type, low_word, high_word)
{
    return 0;
}

function vstack_overflow_error(top, limit)
{
    return 0;
}

function expr_const64_words(words)
{
    wi32(words, 0);
    wi32(add(words, 4), 0);
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

function tcc_realloc(pointer, size)
{
    return realloc(pointer, size);
}

function tcc_mallocz(size)
{
    var pointer;

    pointer = malloc(size);
    if (not(eq(pointer, 0))) {
        memset(pointer, 0, size);
    }
    return pointer;
}

function tcc_set_options(state, text)
{
    return 0;
}

function cc2_pstrcpy(destination, capacity, source)
{
    return 0;
}

function cc2_tcc_open(state, filename)
{
    return sub(0, 1);
}

function cc2_tcc_close()
{
    return 0;
}

function cc2_define_symbol(state, name, value)
{
    return 0;
}

function cc2_open_buffer(state, name, size)
{
    return 0;
}

function cc2_local_time(fields)
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

function initializer_repeat(section, offset, element_size, element_count)
{
    return 0;
}

function initializer_copy_string(section, offset, source, count)
{
    return 0;
}

function initializer_rewind(stream)
{
    return 0;
}

function asm_parse_regvar(label)
{
    return sub(0, 1);
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

function gen_cast_constant(type)
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

function gen_opif_fold_constant(operation)
{
    return 0;
}

function asm_instr()
{
    return 0;
}

function case_sort(base, count)
{
    return 0;
}

function tcc_add_file(state, filename)
{
    return sub(0, 1);
}

function tcc_add_library_err(state, library)
{
    return sub(0, 1);
}
