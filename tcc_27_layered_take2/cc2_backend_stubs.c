function asm_global_instr()
{
    return 0;
}

function decl_record_inline(symbol)
{
    return 0;
}

function put_extern_sym2(symbol, section_index, value, size, add_underscore)
{
    return 0;
}

function put_elf_sym(section, value, size, information, other,
    section_index, name)
{
    return 1;
}

function put_elf_reloca(symbol_table, section, offset, type, symbol,
    addend)
{
    return 0;
}

function section_reserve(section, size)
{
    return 0;
}

function cstr_new(string)
{
    return 0;
}

function cstr_cat(string, source, length)
{
    return 0;
}

function cstr_ccat(string, character)
{
    return 0;
}

function tcc_debug_start(state)
{
    return 0;
}

function tcc_debug_end(state)
{
    return 0;
}

function cc2_put_stabs_reloc(text, type, other, description, value, section,
    symbol)
{
    return 0;
}

function cc2_put_stabs_number(type, other, description, value)
{
    return 0;
}

function section_realloc(section, size)
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

function decl_initializer_alloc(type, attributes, storage, has_initializer,
    value, scope)
{
    return 0;
}

function section_ptr_add(section, length)
{
    return malloc(length);
}

function tok_str_free(stream)
{
    return 0;
}

function begin_macro(stream, allocate)
{
    return 0;
}

function end_macro()
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

function squeeze_multi_relocs(section, old_offset)
{
    return 0;
}

function vpush_bitfield_mask(type, size, position, invert)
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

function gen_opi(operation)
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

function gen_opif(operation)
{
    return 0;
}

function gen_opf(operation)
{
    return 0;
}

function gen_opif_fold_constant(operation)
{
    return 0;
}

function unget_tok(token)
{
    return 0;
}

function tcc_debug_line(state)
{
    return 0;
}

function asm_instr()
{
    return 0;
}

function decl0(scope, is_for_initializer, function_symbol)
{
    return 0;
}

function dynarray_add(table_pointer, count_pointer, data)
{
    return 0;
}

function dynarray_reset(table_pointer, count_pointer)
{
    return 0;
}

function case_sort(base, count)
{
    return 0;
}

function label_find(token)
{
    return 0;
}

function label_push(stack_pointer, token, flags)
{
    return malloc(36);
}

function label_pop(stack_pointer, boundary, keep)
{
    return 0;
}

function tcc_debug_funcstart(state, symbol)
{
    return 0;
}

function tcc_debug_funcend(state, size)
{
    return 0;
}

function gfunc_prolog(type)
{
    return 0;
}

function gfunc_epilog()
{
    return 0;
}

function ggoto()
{
    return 0;
}
