/* Standalone cc2 has no code-generating VLA consumer yet. */
function gen_vla_sp_restore(address)
{
    return 0;
}

function sym_redeclaration_error(value)
{
    return 0;
}

function vstack_overflow_error(top, limit)
{
    return 0;
}

function gv(register_class)
{
    return 0;
}

function o(instruction)
{
    return 0;
}

function gsym(jump_chain)
{
    return 0;
}

function gsym_addr(jump_chain, address)
{
    return 0;
}

function gjmp(jump_chain)
{
    return jump_chain;
}

function gtst(inverted, jump_chain)
{
    return jump_chain;
}

function gjmp_addr(address)
{
    return 0;
}

function gtst_addr(invert, address)
{
    return 0;
}

function tok_str_alloc()
{
    return malloc(8);
}

function tok_str_add(stream, token)
{
    return 0;
}

function tok_str_add_tok(stream)
{
    return 0;
}

function skip(token)
{
    return 0;
}

function expr_const64_words(words)
{
    wi32(words, 0);
    wi32(add(words, 4), 0);
    return 0;
}

function parse_mult_str(string, message)
{
    wi32(string, 1);
    wi32(add(string, 4), mks(""));
    wi32(add(string, 8), 1);
    return 0;
}

function find_section(state, name)
{
    return 0;
}

function tok_alloc(text, length)
{
    return 0;
}

function cstr_free(string)
{
    return 0;
}

function put_extern_sym(symbol, section, offset, size)
{
    return 0;
}

function update_storage(symbol)
{
    return 0;
}

function elfsym(symbol)
{
    return 0;
}

function section_add(section, size, alignment)
{
    return 0;
}

function init_putv(type, section, offset)
{
    return 0;
}

function vpush_bitfield_mask(type, size, position, invert)
{
    return 0;
}

function store(reg, value)
{
    return 0;
}

function load(reg, value)
{
    return 0;
}

function get_tok_str(token, value)
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

function next()
{
    return 0;
}

function unary()
{
    return 0;
}

function gvtst(inverted, jump_chain)
{
    return jump_chain;
}

function gen_cast(type)
{
    return 0;
}

function gen_cast_constant(type)
{
    return 0;
}

function gen_cvt_ftof(type)
{
    return 0;
}

function gen_cvt_itof1(type)
{
    return 0;
}

function gen_cvt_ftoi1(type)
{
    return 0;
}

function gen_cvt_itof(type)
{
    return 0;
}

function gen_cvt_ftoi(type)
{
    return 0;
}

function gfunc_call(argument_count)
{
    return 0;
}

function gfunc_sret(type, variadic, return_type, alignment, register_size)
{
    return 0;
}

function vstore()
{
    return 0;
}

function expect(message)
{
    return 0;
}

function gv2(first_class, second_class)
{
    return 0;
}

function type_to_str(buffer, buffer_size, type, variable)
{
    return 0;
}

function tcc_error_type_pair(source_type, destination_type)
{
    return 0;
}

function gen_opic(operation)
{
    return 0;
}

function gen_opif(operation)
{
    return 0;
}

function unget_tok(token)
{
    return 0;
}

function block(break_symbol, continue_symbol, is_expression)
{
    return 0;
}
