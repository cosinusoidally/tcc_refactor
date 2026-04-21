/*
 * cc1 scaffold for the staged bootstrap.
 *
 * Like cc0.c, this file stays in the JavaScript/C intersection. The functions
 * hold the first layer above cc0. cc1 currently parses only a tiny expression
 * grammar over the cc0 scanner:
 *
 *     expr    := sum (("==" | "!=" | "<" | "<=" | ">" | ">=") sum)*
 *     sum     := product (("+" | "-") product)*
 *     product := primary ("*" primary)*
 *     primary := "!" primary | number | name | mkc(char) | mks(string)
 *              | cc0_heap_get(expr, expr) | "(" expr ")"
 *     func    := "function" name "(" params? ")" "{" var_stmt* if_ret* "return" expr ";" "}"
 *     params  := name ("," name)*
 *     var_stmt := "var" name "=" expr ";"
 *     if_ret  := "if" "(" expr ")" ("if" "(" expr ")")? "return" expr ";"
 */

var cc1_version;
var cc1_last_value;
var cc1_last_name;
var cc1_error;
var cc1_name_0;
var cc1_name_1;
var cc1_name_2;
var cc1_name_3;
var cc1_name_4;
var cc1_name_5;
var cc1_name_6;
var cc1_name_7;
var cc1_name_8;
var cc1_value_0;
var cc1_value_1;
var cc1_value_2;
var cc1_value_3;
var cc1_value_4;
var cc1_value_5;
var cc1_value_6;
var cc1_value_7;
var cc1_value_8;
var cc1_arg_0;
var cc1_arg_1;
var cc1_arg_2;
var cc1_arg_3;
var cc1_arg_4;
var cc1_arg_5;
var cc1_arg_6;
var cc1_arg_7;
var cc1_arg_8;
var cc1_function_count;
var cc1_top_decl_count;
var cc1_return_count;
var cc1_if_count;
var cc1_while_count;
var cc1_local_decl_count;
var cc1_body_semi_count;
var cc1_max_body_depth;
var cc1_param_count;
var cc1_max_param_count;
var cc1_body_call_count;
var cc1_max_body_call_arg_count;
var cc1_body_assignment_count;
var cc1_max_body_expr_depth;
var cc1_current_function_statement_count;
var cc1_max_function_statement_count;
var cc1_current_function_local_count;
var cc1_max_function_local_count;
var cc1_body_expr_statement_count;
var cc1_body_call_statement_count;
var cc1_body_return_call_count;
var cc1_body_local_init_count;
var cc1_body_name_assignment_count;
var cc1_body_plus_op_count;
var cc1_body_minus_op_count;
var cc1_body_star_op_count;
var cc1_body_compare_op_count;
var cc1_body_not_op_count;
var cc1_function_name_char_count;
var cc1_max_function_name_len;
var cc1_function_name_hash;
var cc1_global_name_char_count;
var cc1_max_global_name_len;
var cc1_global_name_hash;
var cc1_current_function_source_start;
var cc1_max_function_source_span;
var cc1_function_slot0_hash;
var cc1_function_slot0_len;
var cc1_function_slot1_hash;
var cc1_function_slot1_len;
var cc1_function_slot2_hash;
var cc1_function_slot2_len;
var cc1_function_slot3_hash;
var cc1_function_slot3_len;
var cc1_global_slot0_hash;
var cc1_global_slot0_len;
var cc1_global_slot1_hash;
var cc1_global_slot1_len;
var cc1_global_slot2_hash;
var cc1_global_slot2_len;
var cc1_global_slot3_hash;
var cc1_global_slot3_len;
var cc1_symbol_table_ptr;
var cc1_symbol_table_limit;
var cc1_symbol_table_count;
var cc1_symbol_table_overflow;
var cc1_function_table_ptr;
var cc1_function_table_limit;
var cc1_function_table_count;
var cc1_function_table_overflow;
var cc1_current_function_name_hash;
var cc1_current_function_name_len;
var cc1_current_function_param_count;
var cc1_statement_table_ptr;
var cc1_statement_table_limit;
var cc1_statement_table_count;
var cc1_statement_table_overflow;
var cc1_current_function_ordinal;
var cc1_param_table_ptr;
var cc1_param_table_limit;
var cc1_param_table_count;
var cc1_param_table_overflow;
var cc1_local_table_ptr;
var cc1_local_table_limit;
var cc1_local_table_count;
var cc1_local_table_overflow;
var cc1_expr_table_ptr;
var cc1_expr_table_limit;
var cc1_expr_table_count;
var cc1_expr_table_overflow;
var cc1_symbol_table_capacity;
var cc1_function_table_capacity;
var cc1_statement_table_capacity;
var cc1_param_table_capacity;
var cc1_local_table_capacity;
var cc1_expr_table_capacity;

cc1_version = 1;
cc1_symbol_table_capacity = 256;
cc1_function_table_capacity = 64;
cc1_statement_table_capacity = 512;
cc1_param_table_capacity = 128;
cc1_local_table_capacity = 128;
cc1_expr_table_capacity = 512;
cc1_last_value = 0;
cc1_last_name = 0;
cc1_error = 0;
cc1_name_0 = -1;
cc1_name_1 = -1;
cc1_name_2 = -1;
cc1_name_3 = -1;
cc1_name_4 = -1;
cc1_name_5 = -1;
cc1_name_6 = -1;
cc1_name_7 = -1;
cc1_name_8 = -1;
cc1_value_0 = 0;
cc1_value_1 = 0;
cc1_value_2 = 0;
cc1_value_3 = 0;
cc1_value_4 = 0;
cc1_value_5 = 0;
cc1_value_6 = 0;
cc1_value_7 = 0;
cc1_value_8 = 0;
cc1_arg_0 = 0;
cc1_arg_1 = 0;
cc1_arg_2 = 0;
cc1_arg_3 = 0;
cc1_arg_4 = 0;
cc1_arg_5 = 0;
cc1_arg_6 = 0;
cc1_arg_7 = 0;
cc1_arg_8 = 0;
cc1_function_count = 0;
cc1_top_decl_count = 0;
cc1_return_count = 0;
cc1_if_count = 0;
cc1_while_count = 0;
cc1_local_decl_count = 0;
cc1_body_semi_count = 0;
cc1_max_body_depth = 0;
cc1_param_count = 0;
cc1_max_param_count = 0;
cc1_body_call_count = 0;
cc1_max_body_call_arg_count = 0;
cc1_body_assignment_count = 0;
cc1_max_body_expr_depth = 0;
cc1_current_function_statement_count = 0;
cc1_max_function_statement_count = 0;
cc1_current_function_local_count = 0;
cc1_max_function_local_count = 0;
cc1_body_expr_statement_count = 0;
cc1_body_call_statement_count = 0;
cc1_body_return_call_count = 0;
cc1_body_local_init_count = 0;
cc1_body_name_assignment_count = 0;
cc1_body_plus_op_count = 0;
cc1_body_minus_op_count = 0;
cc1_body_star_op_count = 0;
cc1_body_compare_op_count = 0;
cc1_body_not_op_count = 0;
cc1_function_name_char_count = 0;
cc1_max_function_name_len = 0;
cc1_function_name_hash = 0;
cc1_global_name_char_count = 0;
cc1_max_global_name_len = 0;
cc1_global_name_hash = 0;
cc1_current_function_source_start = 0;
cc1_max_function_source_span = 0;
cc1_function_slot0_hash = 0;
cc1_function_slot0_len = 0;
cc1_function_slot1_hash = 0;
cc1_function_slot1_len = 0;
cc1_function_slot2_hash = 0;
cc1_function_slot2_len = 0;
cc1_function_slot3_hash = 0;
cc1_function_slot3_len = 0;
cc1_global_slot0_hash = 0;
cc1_global_slot0_len = 0;
cc1_global_slot1_hash = 0;
cc1_global_slot1_len = 0;
cc1_global_slot2_hash = 0;
cc1_global_slot2_len = 0;
cc1_global_slot3_hash = 0;
cc1_global_slot3_len = 0;
cc1_symbol_table_ptr = 0;
cc1_symbol_table_limit = 0;
cc1_symbol_table_count = 0;
cc1_symbol_table_overflow = 0;
cc1_function_table_ptr = 0;
cc1_function_table_limit = 0;
cc1_function_table_count = 0;
cc1_function_table_overflow = 0;
cc1_current_function_name_hash = 0;
cc1_current_function_name_len = 0;
cc1_current_function_param_count = 0;
cc1_statement_table_ptr = 0;
cc1_statement_table_limit = 0;
cc1_statement_table_count = 0;
cc1_statement_table_overflow = 0;
cc1_current_function_ordinal = 0;
cc1_param_table_ptr = 0;
cc1_param_table_limit = 0;
cc1_param_table_count = 0;
cc1_param_table_overflow = 0;
cc1_local_table_ptr = 0;
cc1_local_table_limit = 0;
cc1_local_table_count = 0;
cc1_local_table_overflow = 0;
cc1_expr_table_ptr = 0;
cc1_expr_table_limit = 0;
cc1_expr_table_count = 0;
cc1_expr_table_overflow = 0;

function cc1_compile_unit(source_id)
{
    if (source_id == 0) {
        cc1_error = 70;
        return 0;
    }
    return cc1_parse_cc0_source_string(source_id);
}

function cc1_has_real_parser()
{
    return 1;
}

function cc1_reset_name_table()
{
    cc1_name_0 = -1;
    cc1_name_1 = -1;
    cc1_name_2 = -1;
    cc1_name_3 = -1;
    cc1_name_4 = -1;
    cc1_name_5 = -1;
    cc1_name_6 = -1;
    cc1_name_7 = -1;
    cc1_name_8 = -1;
    cc1_value_0 = 0;
    cc1_value_1 = 0;
    cc1_value_2 = 0;
    cc1_value_3 = 0;
    cc1_value_4 = 0;
    cc1_value_5 = 0;
    cc1_value_6 = 0;
    cc1_value_7 = 0;
    cc1_value_8 = 0;
    return 1;
}

function cc1_reset()
{
    cc1_last_value = 0;
    cc1_last_name = 0;
    cc1_error = 0;
    cc1_function_count = 0;
    cc1_top_decl_count = 0;
    cc1_return_count = 0;
    cc1_if_count = 0;
    cc1_while_count = 0;
    cc1_local_decl_count = 0;
    cc1_body_semi_count = 0;
    cc1_max_body_depth = 0;
    cc1_param_count = 0;
    cc1_max_param_count = 0;
    cc1_body_call_count = 0;
    cc1_max_body_call_arg_count = 0;
    cc1_body_assignment_count = 0;
    cc1_max_body_expr_depth = 0;
    cc1_current_function_statement_count = 0;
    cc1_max_function_statement_count = 0;
    cc1_current_function_local_count = 0;
    cc1_max_function_local_count = 0;
    cc1_body_expr_statement_count = 0;
    cc1_body_call_statement_count = 0;
    cc1_body_return_call_count = 0;
    cc1_body_local_init_count = 0;
    cc1_body_name_assignment_count = 0;
    cc1_body_plus_op_count = 0;
    cc1_body_minus_op_count = 0;
    cc1_body_star_op_count = 0;
    cc1_body_compare_op_count = 0;
    cc1_body_not_op_count = 0;
    cc1_function_name_char_count = 0;
    cc1_max_function_name_len = 0;
    cc1_function_name_hash = 0;
    cc1_global_name_char_count = 0;
    cc1_max_global_name_len = 0;
    cc1_global_name_hash = 0;
    cc1_current_function_source_start = 0;
    cc1_max_function_source_span = 0;
    cc1_function_slot0_hash = 0;
    cc1_function_slot0_len = 0;
    cc1_function_slot1_hash = 0;
    cc1_function_slot1_len = 0;
    cc1_function_slot2_hash = 0;
    cc1_function_slot2_len = 0;
    cc1_function_slot3_hash = 0;
    cc1_function_slot3_len = 0;
    cc1_global_slot0_hash = 0;
    cc1_global_slot0_len = 0;
    cc1_global_slot1_hash = 0;
    cc1_global_slot1_len = 0;
    cc1_global_slot2_hash = 0;
    cc1_global_slot2_len = 0;
    cc1_global_slot3_hash = 0;
    cc1_global_slot3_len = 0;
    cc1_symbol_table_ptr = 0;
    cc1_symbol_table_limit = 0;
    cc1_symbol_table_count = 0;
    cc1_symbol_table_overflow = 0;
    cc1_function_table_ptr = 0;
    cc1_function_table_limit = 0;
    cc1_function_table_count = 0;
    cc1_function_table_overflow = 0;
    cc1_current_function_name_hash = 0;
    cc1_current_function_name_len = 0;
    cc1_current_function_param_count = 0;
    cc1_statement_table_ptr = 0;
    cc1_statement_table_limit = 0;
    cc1_statement_table_count = 0;
    cc1_statement_table_overflow = 0;
    cc1_current_function_ordinal = 0;
    cc1_param_table_ptr = 0;
    cc1_param_table_limit = 0;
    cc1_param_table_count = 0;
    cc1_param_table_overflow = 0;
    cc1_local_table_ptr = 0;
    cc1_local_table_limit = 0;
    cc1_local_table_count = 0;
    cc1_local_table_overflow = 0;
    cc1_expr_table_ptr = 0;
    cc1_expr_table_limit = 0;
    cc1_expr_table_count = 0;
    cc1_expr_table_overflow = 0;
    return 0;
}

function cc1_symbol_table_reset()
{
    cc1_symbol_table_limit = cc1_symbol_table_capacity;
    cc1_symbol_table_count = 0;
    cc1_symbol_table_overflow = 0;
    cc1_symbol_table_ptr = cc0_cell_alloc(cc1_symbol_table_limit * 4);
    return 1;
}

function cc1_symbol_table_add(kind, hash, len, ordinal)
{
    var index;

    if (cc1_symbol_table_count >= cc1_symbol_table_limit) {
        cc1_symbol_table_overflow = 1;
        return 1;
    }
    index = cc1_symbol_table_count * 4;
    cc0_cell_set(cc1_symbol_table_ptr, index + 0, kind);
    cc0_cell_set(cc1_symbol_table_ptr, index + 1, hash);
    cc0_cell_set(cc1_symbol_table_ptr, index + 2, len);
    cc0_cell_set(cc1_symbol_table_ptr, index + 3, ordinal);
    cc1_symbol_table_count = cc1_symbol_table_count + 1;
    return 1;
}

function cc1_function_table_reset()
{
    cc1_function_table_limit = cc1_function_table_capacity;
    cc1_function_table_count = 0;
    cc1_function_table_overflow = 0;
    cc1_function_table_ptr = cc0_cell_alloc(cc1_function_table_limit * 6);
    return 1;
}

function cc1_function_table_add(hash, len, param_count, source_start, source_span, ordinal)
{
    var index;

    if (cc1_function_table_count >= cc1_function_table_limit) {
        cc1_function_table_overflow = 1;
        return 1;
    }
    index = cc1_function_table_count * 6;
    cc0_cell_set(cc1_function_table_ptr, index + 0, hash);
    cc0_cell_set(cc1_function_table_ptr, index + 1, len);
    cc0_cell_set(cc1_function_table_ptr, index + 2, param_count);
    cc0_cell_set(cc1_function_table_ptr, index + 3, source_start);
    cc0_cell_set(cc1_function_table_ptr, index + 4, source_span);
    cc0_cell_set(cc1_function_table_ptr, index + 5, ordinal);
    cc1_function_table_count = cc1_function_table_count + 1;
    return 1;
}

function cc1_statement_table_reset()
{
    cc1_statement_table_limit = cc1_statement_table_capacity;
    cc1_statement_table_count = 0;
    cc1_statement_table_overflow = 0;
    cc1_statement_table_ptr = cc0_cell_alloc(cc1_statement_table_limit * 4);
    return 1;
}

function cc1_statement_table_add(kind, depth, source_start, function_ordinal)
{
    var index;

    if (cc1_statement_table_count >= cc1_statement_table_limit) {
        cc1_statement_table_overflow = 1;
        return 1;
    }
    index = cc1_statement_table_count * 4;
    cc0_cell_set(cc1_statement_table_ptr, index + 0, kind);
    cc0_cell_set(cc1_statement_table_ptr, index + 1, depth);
    cc0_cell_set(cc1_statement_table_ptr, index + 2, source_start);
    cc0_cell_set(cc1_statement_table_ptr, index + 3, function_ordinal);
    cc1_statement_table_count = cc1_statement_table_count + 1;
    return 1;
}

function cc1_param_table_reset()
{
    cc1_param_table_limit = cc1_param_table_capacity;
    cc1_param_table_count = 0;
    cc1_param_table_overflow = 0;
    cc1_param_table_ptr = cc0_cell_alloc(cc1_param_table_limit * 4);
    return 1;
}

function cc1_param_table_add(hash, len, ordinal, function_ordinal)
{
    var index;

    if (cc1_param_table_count >= cc1_param_table_limit) {
        cc1_param_table_overflow = 1;
        return 1;
    }
    index = cc1_param_table_count * 4;
    cc0_cell_set(cc1_param_table_ptr, index + 0, hash);
    cc0_cell_set(cc1_param_table_ptr, index + 1, len);
    cc0_cell_set(cc1_param_table_ptr, index + 2, ordinal);
    cc0_cell_set(cc1_param_table_ptr, index + 3, function_ordinal);
    cc1_param_table_count = cc1_param_table_count + 1;
    return 1;
}

function cc1_local_table_reset()
{
    cc1_local_table_limit = cc1_local_table_capacity;
    cc1_local_table_count = 0;
    cc1_local_table_overflow = 0;
    cc1_local_table_ptr = cc0_cell_alloc(cc1_local_table_limit * 4);
    return 1;
}

function cc1_local_table_add(hash, len, ordinal, function_ordinal)
{
    var index;

    if (cc1_local_table_count >= cc1_local_table_limit) {
        cc1_local_table_overflow = 1;
        return 1;
    }
    index = cc1_local_table_count * 4;
    cc0_cell_set(cc1_local_table_ptr, index + 0, hash);
    cc0_cell_set(cc1_local_table_ptr, index + 1, len);
    cc0_cell_set(cc1_local_table_ptr, index + 2, ordinal);
    cc0_cell_set(cc1_local_table_ptr, index + 3, function_ordinal);
    cc1_local_table_count = cc1_local_table_count + 1;
    return 1;
}

function cc1_expr_table_reset()
{
    cc1_expr_table_limit = cc1_expr_table_capacity;
    cc1_expr_table_count = 0;
    cc1_expr_table_overflow = 0;
    cc1_expr_table_ptr = cc0_cell_alloc(cc1_expr_table_limit * 5);
    return 1;
}

function cc1_expr_table_add(kind, source_start, source_span, function_ordinal, flags)
{
    var index;

    if (cc1_expr_table_count >= cc1_expr_table_limit) {
        cc1_expr_table_overflow = 1;
        return 1;
    }
    index = cc1_expr_table_count * 5;
    cc0_cell_set(cc1_expr_table_ptr, index + 0, kind);
    cc0_cell_set(cc1_expr_table_ptr, index + 1, source_start);
    cc0_cell_set(cc1_expr_table_ptr, index + 2, source_span);
    cc0_cell_set(cc1_expr_table_ptr, index + 3, function_ordinal);
    cc0_cell_set(cc1_expr_table_ptr, index + 4, flags);
    cc1_expr_table_count = cc1_expr_table_count + 1;
    return 1;
}

function cc1_parse_number()
{
    if (cc0_get_tok_class() != CC0_TOK_NUMBER) {
        cc1_error = 1;
        return 0;
    }
    return cc0_get_tok_value();
}

function cc1_bind_name_value(name, value)
{
    if (cc1_name_0 == name) {
        cc1_value_0 = value;
        return 1;
    }
    if (cc1_name_1 == name) {
        cc1_value_1 = value;
        return 1;
    }
    if (cc1_name_2 == name) {
        cc1_value_2 = value;
        return 1;
    }
    if (cc1_name_3 == name) {
        cc1_value_3 = value;
        return 1;
    }
    if (cc1_name_4 == name) {
        cc1_value_4 = value;
        return 1;
    }
    if (cc1_name_5 == name) {
        cc1_value_5 = value;
        return 1;
    }
    if (cc1_name_6 == name) {
        cc1_value_6 = value;
        return 1;
    }
    if (cc1_name_7 == name) {
        cc1_value_7 = value;
        return 1;
    }
    if (cc1_name_8 == name) {
        cc1_value_8 = value;
        return 1;
    }
    if (cc1_name_0 < 0) {
        cc1_name_0 = name;
        cc1_value_0 = value;
        return 1;
    }
    if (cc1_name_1 < 0) {
        cc1_name_1 = name;
        cc1_value_1 = value;
        return 1;
    }
    if (cc1_name_2 < 0) {
        cc1_name_2 = name;
        cc1_value_2 = value;
        return 1;
    }
    if (cc1_name_3 < 0) {
        cc1_name_3 = name;
        cc1_value_3 = value;
        return 1;
    }
    if (cc1_name_4 < 0) {
        cc1_name_4 = name;
        cc1_value_4 = value;
        return 1;
    }
    if (cc1_name_5 < 0) {
        cc1_name_5 = name;
        cc1_value_5 = value;
        return 1;
    }
    if (cc1_name_6 < 0) {
        cc1_name_6 = name;
        cc1_value_6 = value;
        return 1;
    }
    if (cc1_name_7 < 0) {
        cc1_name_7 = name;
        cc1_value_7 = value;
        return 1;
    }
    if (cc1_name_8 < 0) {
        cc1_name_8 = name;
        cc1_value_8 = value;
        return 1;
    }
    cc1_error = 5;
    return 0;
}

function cc1_lookup_name(name)
{
    if (cc1_name_0 == name)
        return cc1_value_0;
    if (cc1_name_1 == name)
        return cc1_value_1;
    if (cc1_name_2 == name)
        return cc1_value_2;
    if (cc1_name_3 == name)
        return cc1_value_3;
    if (cc1_name_4 == name)
        return cc1_value_4;
    if (cc1_name_5 == name)
        return cc1_value_5;
    if (cc1_name_6 == name)
        return cc1_value_6;
    if (cc1_name_7 == name)
        return cc1_value_7;
    if (cc1_name_8 == name)
        return cc1_value_8;
    cc1_error = 6;
    return 0;
}

function cc1_hash_current_name_with(seed)
{
    var h;
    var i;
    h = seed;
    i = 0;
    while (i < cc0_get_tok_len()) {
        h = (h * 33 + cc0_source_at(cc0_get_tok_start() + i)) % 32749;
        i = i + 1;
    }
    return h;
}

function cc1_note_function_name_token()
{
    var name_hash;
    name_hash = cc1_hash_current_name_with(0);
    cc1_current_function_name_hash = name_hash;
    cc1_current_function_name_len = cc0_get_tok_len();
    if (cc1_function_count == 0) {
        cc1_function_slot0_hash = name_hash;
        cc1_function_slot0_len = cc0_get_tok_len();
    }
    if (cc1_function_count == 1) {
        cc1_function_slot1_hash = name_hash;
        cc1_function_slot1_len = cc0_get_tok_len();
    }
    if (cc1_function_count == 2) {
        cc1_function_slot2_hash = name_hash;
        cc1_function_slot2_len = cc0_get_tok_len();
    }
    if (cc1_function_count == 3) {
        cc1_function_slot3_hash = name_hash;
        cc1_function_slot3_len = cc0_get_tok_len();
    }
    cc1_symbol_table_add(1, name_hash, cc0_get_tok_len(), cc1_function_count);
    cc1_function_name_char_count = cc1_function_name_char_count + cc0_get_tok_len();
    if (cc0_get_tok_len() > cc1_max_function_name_len)
        cc1_max_function_name_len = cc0_get_tok_len();
    cc1_function_name_hash = cc1_hash_current_name_with(cc1_function_name_hash);
    return 1;
}

function cc1_note_global_name_token()
{
    var name_hash;
    name_hash = cc1_hash_current_name_with(0);
    if (cc1_top_decl_count == 0) {
        cc1_global_slot0_hash = name_hash;
        cc1_global_slot0_len = cc0_get_tok_len();
    }
    if (cc1_top_decl_count == 1) {
        cc1_global_slot1_hash = name_hash;
        cc1_global_slot1_len = cc0_get_tok_len();
    }
    if (cc1_top_decl_count == 2) {
        cc1_global_slot2_hash = name_hash;
        cc1_global_slot2_len = cc0_get_tok_len();
    }
    if (cc1_top_decl_count == 3) {
        cc1_global_slot3_hash = name_hash;
        cc1_global_slot3_len = cc0_get_tok_len();
    }
    cc1_symbol_table_add(2, name_hash, cc0_get_tok_len(), cc1_top_decl_count);
    cc1_global_name_char_count = cc1_global_name_char_count + cc0_get_tok_len();
    if (cc0_get_tok_len() > cc1_max_global_name_len)
        cc1_max_global_name_len = cc0_get_tok_len();
    cc1_global_name_hash = cc1_hash_current_name_with(cc1_global_name_hash);
    return 1;
}

function cc1_tok_is_cc0_ch_digit(digit)
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 8)
        return 0;
    if (cc0_source_at(cc0_get_tok_start()) != CC0_CH_C)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 1) != CC0_CH_C)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 2) != CC0_CH_0)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 3) != CC0_CH_UNDERSCORE)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 4) != CC0_CH_C)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 5) != CC0_CH_H)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 6) != CC0_CH_UNDERSCORE)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 7) != digit)
        return 0;
    return 1;
}

function cc1_tok_is_cc0_ch_single()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 8)
        return 0;
    if (cc0_source_at(cc0_get_tok_start()) != CC0_CH_C)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 1) != CC0_CH_C)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 2) != CC0_CH_0)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 3) != CC0_CH_UNDERSCORE)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 4) != CC0_CH_C)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 5) != CC0_CH_H)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 6) != CC0_CH_UNDERSCORE)
        return 0;
    return 1;
}

function cc1_tok_is_cc0_ch_name3(c0, c1, c2)
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 10)
        return 0;
    if (cc0_source_at(cc0_get_tok_start()) != CC0_CH_C)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 1) != CC0_CH_C)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 2) != CC0_CH_0)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 3) != CC0_CH_UNDERSCORE)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 4) != CC0_CH_C)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 5) != CC0_CH_H)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 6) != CC0_CH_UNDERSCORE)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 7) != c0)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 8) != c1)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 9) != c2)
        return 0;
    return 1;
}

function cc1_lookup_current_name()
{
    if (cc1_tok_is_cc0_ch_single())
        return cc0_source_at(cc0_get_tok_start() + 7);
    if (cc1_tok_is_cc0_ch_name3(mkc('N'), mkc('U'), mkc('L')))
        return CC0_CH_NUL;
    if (cc1_tok_is_cc0_ch_digit(CC0_CH_0))
        return CC0_CH_0;
    if (cc1_tok_is_cc0_ch_digit(CC0_CH_7))
        return CC0_CH_7;
    if (cc1_tok_is_cc0_ch_digit(CC0_CH_9))
        return CC0_CH_9;
    return cc1_lookup_name(cc1_hash_current_name_with(0));
}

function cc1_tok_is_word_cc0_is_digit()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 12)
        return 0;
    if (cc0_source_at(cc0_get_tok_start()) != CC0_CH_c)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 1) != CC0_CH_c)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 2) != CC0_CH_0)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 3) != CC0_CH_UNDERSCORE)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 4) != CC0_CH_i)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 5) != CC0_CH_s)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 6) != CC0_CH_UNDERSCORE)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 7) != CC0_CH_d)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 8) != CC0_CH_i)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 9) != CC0_CH_g)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 10) != CC0_CH_i)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 11) != CC0_CH_t)
        return 0;
    return 1;
}

function cc1_tok_is_word_cc0_heap_get()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME)
        return 0;
    if (cc0_get_tok_len() != 12)
        return 0;
    if (cc0_source_at(cc0_get_tok_start()) != CC0_CH_c)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 1) != CC0_CH_c)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 2) != CC0_CH_0)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 3) != CC0_CH_UNDERSCORE)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 4) != CC0_CH_h)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 5) != CC0_CH_e)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 6) != CC0_CH_a)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 7) != CC0_CH_p)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 8) != CC0_CH_UNDERSCORE)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 9) != CC0_CH_g)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 10) != CC0_CH_e)
        return 0;
    if (cc0_source_at(cc0_get_tok_start() + 11) != CC0_CH_t)
        return 0;
    return 1;
}

function cc1_parse_call_cc0_is_digit()
{
    var value;
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_LPAREN)) {
        cc1_error = 29;
        return 0;
    }
    cc0_scan_next();
    value = cc1_parse_expr_tokens();
    if (cc1_error)
        return 0;
    if (!cc1_at_punct(CC0_CH_RPAREN)) {
        cc1_error = 30;
        return 0;
    }
    cc0_scan_next();
    return cc0_is_digit(value);
}

function cc1_parse_call_mkc()
{
    var value;
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_LPAREN)) {
        cc1_error = 31;
        return 0;
    }
    cc0_scan_next();
    if (cc0_get_tok_class() != CC0_TOK_CHAR) {
        cc1_error = 32;
        return 0;
    }
    value = cc0_get_tok_value();
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_RPAREN)) {
        cc1_error = 33;
        return 0;
    }
    cc0_scan_next();
    return mkc(value);
}

function cc1_parse_call_mks()
{
    var value;
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_LPAREN)) {
        cc1_error = 34;
        return 0;
    }
    cc0_scan_next();
    if (cc0_get_tok_class() != CC0_TOK_STRING) {
        cc1_error = 35;
        return 0;
    }
    value = cc0_get_tok_value();
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_RPAREN)) {
        cc1_error = 36;
        return 0;
    }
    cc0_scan_next();
    return value;
}

function cc1_parse_call_cc0_heap_get()
{
    var ptr;
    var offset;
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_LPAREN)) {
        cc1_error = 37;
        return 0;
    }
    cc0_scan_next();
    ptr = cc1_parse_expr_tokens();
    if (cc1_error)
        return 0;
    if (!cc1_at_punct(CC0_CH_COMMA)) {
        cc1_error = 38;
        return 0;
    }
    cc0_scan_next();
    offset = cc1_parse_expr_tokens();
    if (cc1_error)
        return 0;
    if (!cc1_at_punct(CC0_CH_RPAREN)) {
        cc1_error = 39;
        return 0;
    }
    cc0_scan_next();
    return cc0_heap_get(ptr, offset);
}

function cc1_function_arg_value(index)
{
    if (index == 0)
        return cc1_arg_0;
    if (index == 1)
        return cc1_arg_1;
    if (index == 2)
        return cc1_arg_2;
    if (index == 3)
        return cc1_arg_3;
    if (index == 4)
        return cc1_arg_4;
    if (index == 5)
        return cc1_arg_5;
    if (index == 6)
        return cc1_arg_6;
    if (index == 7)
        return cc1_arg_7;
    if (index == 8)
        return cc1_arg_8;
    cc1_error = 19;
    return 0;
}

function cc1_at_punct(c)
{
    if (cc0_get_tok_class() != CC0_TOK_PUNCT)
        return 0;
    if (cc0_get_tok_first() != c)
        return 0;
    return 1;
}

function cc1_at_punct2(c0, c1)
{
    if (!cc1_at_punct(c0))
        return 0;
    cc0_scan_next();
    if (!cc1_at_punct(c1)) {
        cc1_error = 26;
        return 0;
    }
    return 1;
}

function cc1_parse_primary()
{
    var value;
    if (cc1_at_punct(CC0_CH_BANG)) {
        cc0_scan_next();
        value = cc1_parse_primary();
        if (cc1_error)
            return 0;
        if (value)
            return 0;
        return 1;
    }
    if (cc0_get_tok_class() == CC0_TOK_NUMBER) {
        value = cc1_parse_number();
        cc0_scan_next();
        return value;
    }
    if (cc0_get_tok_class() == CC0_TOK_NAME) {
        if (cc0_tok_is_word_mkc())
            return cc1_parse_call_mkc();
        if (cc0_tok_is_word_mks())
            return cc1_parse_call_mks();
        if (cc1_tok_is_word_cc0_is_digit())
            return cc1_parse_call_cc0_is_digit();
        if (cc1_tok_is_word_cc0_heap_get())
            return cc1_parse_call_cc0_heap_get();
        value = cc1_lookup_current_name();
        cc0_scan_next();
        return value;
    }
    if (cc1_at_punct(CC0_CH_LPAREN)) {
        cc0_scan_next();
        value = cc1_parse_expr_tokens();
        if (cc1_error)
            return 0;
        if (!cc1_at_punct(CC0_CH_RPAREN)) {
            cc1_error = 4;
            return 0;
        }
        cc0_scan_next();
        return value;
    }
    cc1_error = 1;
    return 0;
}

function cc1_parse_product()
{
    var value;
    var rhs;
    value = cc1_parse_primary();
    while (cc1_error == 0) {
        if (!cc1_at_punct(CC0_CH_STAR))
            return value;
        cc0_scan_next();
        rhs = cc1_parse_primary();
        value = value * rhs;
    }
    return 0;
}

function cc1_parse_sum_tokens()
{
    var value;
    var rhs;
    value = cc1_parse_product();
    while (cc1_error == 0) {
        if (cc1_at_punct(CC0_CH_PLUS)) {
            cc0_scan_next();
            rhs = cc1_parse_product();
            value = value + rhs;
        } else {
            if (!cc1_at_punct(CC0_CH_MINUS))
                return value;
            cc0_scan_next();
            rhs = cc1_parse_product();
            value = value - rhs;
        }
    }
    return 0;
}

function cc1_parse_expr_tokens()
{
    var value;
    var rhs;
    value = cc1_parse_sum_tokens();
    while (cc1_error == 0) {
        if (cc1_at_punct(CC0_CH_EQUAL)) {
            if (!cc1_at_punct2(CC0_CH_EQUAL, CC0_CH_EQUAL))
                return 0;
            cc0_scan_next();
            rhs = cc1_parse_sum_tokens();
            if (value == rhs)
                value = 1;
            else
                value = 0;
        } else {
            if (cc1_at_punct(CC0_CH_BANG)) {
                if (!cc1_at_punct2(CC0_CH_BANG, CC0_CH_EQUAL))
                    return 0;
                cc0_scan_next();
                rhs = cc1_parse_sum_tokens();
                if (value != rhs)
                    value = 1;
                else
                    value = 0;
            } else {
                if (cc1_at_punct(CC0_CH_LT)) {
                    cc0_scan_next();
                    if (cc1_at_punct(CC0_CH_EQUAL)) {
                        cc0_scan_next();
                        rhs = cc1_parse_sum_tokens();
                        if (value <= rhs)
                            value = 1;
                        else
                            value = 0;
                    } else {
                        rhs = cc1_parse_sum_tokens();
                        if (value < rhs)
                            value = 1;
                        else
                            value = 0;
                    }
                } else {
                    if (!cc1_at_punct(CC0_CH_GT))
                        return value;
                    cc0_scan_next();
                    if (cc1_at_punct(CC0_CH_EQUAL)) {
                        cc0_scan_next();
                        rhs = cc1_parse_sum_tokens();
                        if (value >= rhs)
                            value = 1;
                        else
                            value = 0;
                    } else {
                        rhs = cc1_parse_sum_tokens();
                        if (value > rhs)
                            value = 1;
                        else
                            value = 0;
                    }
                }
            }
        }
    }
    return 0;
}

function cc1_parse_expr8(c0, c1, c2, c3, c4, c5, c6, c7)
{
    var value;
    cc1_reset();
    cc0_source_set8(c0, c1, c2, c3, c4, c5, c6, c7);
    cc0_scan_next();
    value = cc1_parse_expr_tokens();
    if (cc1_error)
        return 0;
    if (cc0_get_tok_class() != CC0_TOK_EOF) {
        cc1_error = 2;
        return 0;
    }
    cc1_last_value = value;
    return 1;
}

function cc1_parse_expr_string(source)
{
    var value;
    cc1_reset();
    cc0_source_set_string(source);
    cc0_scan_next();
    value = cc1_parse_expr_tokens();
    if (cc1_error)
        return 0;
    if (cc0_get_tok_class() != CC0_TOK_EOF) {
        cc1_error = 2;
        return 0;
    }
    cc1_last_value = value;
    return 1;
}

function cc1_parse_sum8(c0, c1, c2, c3, c4, c5, c6, c7)
{
    return cc1_parse_expr8(c0, c1, c2, c3, c4, c5, c6, c7);
}

function cc1_parse_assignment_tokens()
{
    var name_key;
    var value;
    if (cc0_get_tok_class() != CC0_TOK_NAME) {
        cc1_error = 7;
        return 0;
    }
    name_key = cc1_hash_current_name_with(0);
    cc1_last_name = cc0_get_tok_first();
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_EQUAL)) {
        cc1_error = 8;
        return 0;
    }
    cc0_scan_next();
    value = cc1_parse_expr_tokens();
    if (cc1_error)
        return 0;
    cc1_last_value = value;
    cc1_bind_name_value(name_key, value);
    if (cc1_error)
        return 0;
    return 1;
}

function cc1_parse_assignment8(c0, c1, c2, c3, c4, c5, c6, c7)
{
    cc1_reset();
    cc0_source_set8(c0, c1, c2, c3, c4, c5, c6, c7);
    cc0_scan_next();
    if (!cc1_parse_assignment_tokens())
        return 0;
    if (cc0_get_tok_class() != CC0_TOK_EOF) {
        cc1_error = 2;
        return 0;
    }
    return 1;
}

function cc1_parse_assignment_string(source)
{
    cc1_reset();
    cc0_source_set_string(source);
    cc0_scan_next();
    if (!cc1_parse_assignment_tokens())
        return 0;
    if (cc0_get_tok_class() != CC0_TOK_EOF) {
        cc1_error = 2;
        return 0;
    }
    return 1;
}

function cc1_parse_program_tokens()
{
    while (cc0_get_tok_class() != CC0_TOK_EOF) {
        if (!cc1_parse_assignment_tokens())
            return 0;
        if (cc0_get_tok_class() == CC0_TOK_EOF)
            return 1;
        if (!cc1_at_punct(CC0_CH_SEMI)) {
            cc1_error = 9;
            return 0;
        }
        cc0_scan_next();
    }
    return 1;
}

function cc1_parse_program16(c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15)
{
    cc1_reset();
    cc0_source_set16(c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15);
    cc0_scan_next();
    return cc1_parse_program_tokens();
}

function cc1_parse_program_string(source)
{
    cc1_reset();
    cc0_source_set_string(source);
    cc0_scan_next();
    return cc1_parse_program_tokens();
}

function cc1_note_body_block_depth(depth)
{
    if (depth > cc1_max_body_depth)
        cc1_max_body_depth = depth;
    return 1;
}

function cc1_note_body_call_args(arg_count)
{
    if (arg_count > cc1_max_body_call_arg_count)
        cc1_max_body_call_arg_count = arg_count;
    return 1;
}

function cc1_note_body_expr_depth(expr_depth)
{
    if (expr_depth > cc1_max_body_expr_depth)
        cc1_max_body_expr_depth = expr_depth;
    return 1;
}

function cc1_begin_function_body_metrics()
{
    cc1_current_function_statement_count = 0;
    cc1_current_function_local_count = 0;
    return 1;
}

function cc1_finish_function_body_metrics()
{
    if (cc1_current_function_statement_count > cc1_max_function_statement_count)
        cc1_max_function_statement_count = cc1_current_function_statement_count;
    if (cc1_current_function_local_count > cc1_max_function_local_count)
        cc1_max_function_local_count = cc1_current_function_local_count;
    return 1;
}

function cc1_prev_nonspace_from(pos)
{
    var c;
    pos = pos - 1;
    c = cc0_source_at(pos);
    while (cc0_is_space(c)) {
        pos = pos - 1;
        c = cc0_source_at(pos);
    }
    return c;
}

function cc1_next_nonspace_from(pos)
{
    var c;
    c = cc0_source_at(pos);
    while (cc0_is_space(c)) {
        pos = pos + 1;
        c = cc0_source_at(pos);
    }
    return c;
}

function cc1_current_equal_is_assignment()
{
    var next;
    var prev;
    if (!cc1_at_punct(CC0_CH_EQUAL))
        return 0;
    prev = cc1_prev_nonspace_from(cc0_get_tok_start());
    next = cc1_next_nonspace_from(cc0_get_tok_start() + 1);
    if (prev == CC0_CH_EQUAL)
        return 0;
    if (prev == CC0_CH_BANG)
        return 0;
    if (prev == CC0_CH_LT)
        return 0;
    if (prev == CC0_CH_GT)
        return 0;
    if (next == CC0_CH_EQUAL)
        return 0;
    return 1;
}

function cc1_note_body_operator_token()
{
    var next;
    if (cc1_at_punct(CC0_CH_PLUS)) {
        cc1_body_plus_op_count = cc1_body_plus_op_count + 1;
        return 1;
    }
    if (cc1_at_punct(CC0_CH_MINUS)) {
        cc1_body_minus_op_count = cc1_body_minus_op_count + 1;
        return 1;
    }
    if (cc1_at_punct(CC0_CH_STAR)) {
        cc1_body_star_op_count = cc1_body_star_op_count + 1;
        return 1;
    }
    if (cc1_at_punct(CC0_CH_LT)) {
        cc1_body_compare_op_count = cc1_body_compare_op_count + 1;
        return 1;
    }
    if (cc1_at_punct(CC0_CH_GT)) {
        cc1_body_compare_op_count = cc1_body_compare_op_count + 1;
        return 1;
    }
    if (cc1_at_punct(CC0_CH_EQUAL)) {
        next = cc1_next_nonspace_from(cc0_get_tok_start() + 1);
        if (next == CC0_CH_EQUAL)
            cc1_body_compare_op_count = cc1_body_compare_op_count + 1;
        return 1;
    }
    if (cc1_at_punct(CC0_CH_BANG)) {
        next = cc1_next_nonspace_from(cc0_get_tok_start() + 1);
        if (next == CC0_CH_EQUAL)
            cc1_body_compare_op_count = cc1_body_compare_op_count + 1;
        else
            cc1_body_not_op_count = cc1_body_not_op_count + 1;
        return 1;
    }
    return 0;
}

function cc1_scan_paren_expr_tokens(is_call, expr_depth)
{
    var arg_count;
    var previous_was_name;
    var saw_arg;
    if (!cc1_at_punct(CC0_CH_LPAREN)) {
        cc1_error = 51;
        return 0;
    }
    arg_count = 0;
    previous_was_name = 0;
    saw_arg = 0;
    cc1_note_body_expr_depth(expr_depth);
    cc0_scan_next();
    while (cc0_get_tok_class() != CC0_TOK_EOF) {
        if (cc1_at_punct(CC0_CH_RPAREN)) {
            if (is_call) {
                if (saw_arg)
                    arg_count = arg_count + 1;
                cc1_note_body_call_args(arg_count);
            }
            cc0_scan_next();
            return 1;
        }
        if (cc1_at_punct(CC0_CH_COMMA)) {
            if (is_call) {
                arg_count = arg_count + 1;
                saw_arg = 0;
            }
            previous_was_name = 0;
            cc0_scan_next();
            continue;
        }
        if (cc1_at_punct(CC0_CH_LPAREN)) {
            if (previous_was_name) {
                cc1_body_call_count = cc1_body_call_count + 1;
                if (!cc1_scan_paren_expr_tokens(1, expr_depth + 1))
                    return 0;
            } else {
                if (!cc1_scan_paren_expr_tokens(0, expr_depth + 1))
                    return 0;
            }
            previous_was_name = 0;
            saw_arg = 1;
            continue;
        }
        if (cc1_current_equal_is_assignment()) {
            cc1_body_assignment_count = cc1_body_assignment_count + 1;
            if (previous_was_name)
                cc1_body_name_assignment_count = cc1_body_name_assignment_count + 1;
        }
        cc1_note_body_operator_token();
        if (cc1_at_punct(CC0_CH_LBRACE)) {
            cc1_error = 58;
            return 0;
        }
        if (cc1_at_punct(CC0_CH_RBRACE)) {
            cc1_error = 59;
            return 0;
        }
        if (cc0_get_tok_class() == CC0_TOK_NAME)
            previous_was_name = 1;
        else
            previous_was_name = 0;
        saw_arg = 1;
        cc0_scan_next();
    }
    cc1_error = 52;
    return 0;
}

function cc1_parse_balanced_parens_tokens()
{
    return cc1_scan_paren_expr_tokens(0, 1);
}

function cc1_parse_statement_tail_tokens(mode)
{
    var expr_start;
    var expr_flags;
    var has_assignment;
    var has_call;
    var previous_was_name;
    expr_start = cc0_get_tok_start();
    expr_flags = 0;
    has_assignment = 0;
    has_call = 0;
    previous_was_name = 0;
    while (cc0_get_tok_class() != CC0_TOK_EOF) {
        if (cc1_at_punct(CC0_CH_SEMI)) {
            cc1_expr_table_add(mode, expr_start, cc0_get_tok_start() - expr_start, cc1_current_function_ordinal, expr_flags);
            if (mode == 1) {
                if (has_call)
                    cc1_body_return_call_count = cc1_body_return_call_count + 1;
            } else {
                if (mode == 2) {
                    if (has_assignment)
                        cc1_body_local_init_count = cc1_body_local_init_count + 1;
                } else {
                    cc1_body_expr_statement_count = cc1_body_expr_statement_count + 1;
                    if (has_call)
                        cc1_body_call_statement_count = cc1_body_call_statement_count + 1;
                }
            }
            cc1_body_semi_count = cc1_body_semi_count + 1;
            cc0_scan_next();
            return 1;
        }
        if (cc1_at_punct(CC0_CH_LPAREN)) {
            if (previous_was_name) {
                has_call = 1;
                expr_flags = expr_flags | 2;
                cc1_body_call_count = cc1_body_call_count + 1;
                if (!cc1_scan_paren_expr_tokens(1, 1))
                    return 0;
            } else {
                if (!cc1_scan_paren_expr_tokens(0, 1))
                    return 0;
            }
            previous_was_name = 0;
            continue;
        }
        if (cc1_current_equal_is_assignment()) {
            has_assignment = 1;
            expr_flags = expr_flags | 1;
            cc1_body_assignment_count = cc1_body_assignment_count + 1;
            if (previous_was_name)
                cc1_body_name_assignment_count = cc1_body_name_assignment_count + 1;
        }
        if (cc1_at_punct(CC0_CH_PLUS))
            expr_flags = expr_flags | 4;
        if (cc1_at_punct(CC0_CH_MINUS))
            expr_flags = expr_flags | 8;
        if (cc1_at_punct(CC0_CH_STAR))
            expr_flags = expr_flags | 16;
        if (cc1_at_punct(CC0_CH_LT))
            expr_flags = expr_flags | 32;
        if (cc1_at_punct(CC0_CH_GT))
            expr_flags = expr_flags | 32;
        if (cc1_at_punct(CC0_CH_EQUAL))
            if (!cc1_current_equal_is_assignment())
                expr_flags = expr_flags | 32;
        if (cc1_at_punct(CC0_CH_BANG))
            expr_flags = expr_flags | 64;
        cc1_note_body_operator_token();
        if (cc1_at_punct(CC0_CH_RPAREN)) {
            cc1_error = 53;
            return 0;
        }
        if (cc1_at_punct(CC0_CH_LBRACE)) {
            cc1_error = 54;
            return 0;
        }
        if (cc1_at_punct(CC0_CH_RBRACE)) {
            cc1_error = 55;
            return 0;
        }
        if (cc0_get_tok_class() == CC0_TOK_NAME)
            previous_was_name = 1;
        else
            previous_was_name = 0;
        cc0_scan_next();
    }
    cc1_error = 56;
    return 0;
}

function cc1_skip_to_semi()
{
    while (cc0_get_tok_class() != CC0_TOK_EOF) {
        if (cc1_at_punct(CC0_CH_SEMI)) {
            cc0_scan_next();
            return 1;
        }
        cc0_scan_next();
    }
    cc1_error = 40;
    return 0;
}

function cc1_parse_top_var_decl_tokens()
{
    cc0_scan_next();
    if (cc0_get_tok_class() != CC0_TOK_NAME) {
        cc1_error = 41;
        return 0;
    }
    cc1_note_global_name_token();
    cc1_top_decl_count = cc1_top_decl_count + 1;
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_SEMI)) {
        cc1_error = 42;
        return 0;
    }
    cc0_scan_next();
    return 1;
}

function cc1_parse_top_assignment_tokens()
{
    if (cc0_get_tok_class() != CC0_TOK_NAME) {
        cc1_error = 43;
        return 0;
    }
    cc1_note_global_name_token();
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_EQUAL)) {
        cc1_error = 44;
        return 0;
    }
    cc0_scan_next();
    cc1_top_decl_count = cc1_top_decl_count + 1;
    return cc1_skip_to_semi();
}

function cc1_parse_function_signature_tokens()
{
    var param_count;
    cc1_current_function_source_start = cc0_get_tok_start();
    cc0_scan_next();
    if (cc0_get_tok_class() != CC0_TOK_NAME) {
        cc1_error = 45;
        return 0;
    }
    cc1_last_name = cc0_get_tok_first();
    cc1_note_function_name_token();
    cc1_function_count = cc1_function_count + 1;
    cc1_current_function_ordinal = cc1_function_count - 1;
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_LPAREN)) {
        cc1_error = 46;
        return 0;
    }
    cc0_scan_next();
    param_count = 0;
    while (!cc1_at_punct(CC0_CH_RPAREN)) {
        if (cc0_get_tok_class() != CC0_TOK_NAME) {
            cc1_error = 47;
            return 0;
        }
        cc1_param_table_add(
            cc1_hash_current_name_with(0),
            cc0_get_tok_len(),
            param_count,
            cc1_current_function_ordinal);
        param_count = param_count + 1;
        cc1_param_count = cc1_param_count + 1;
        cc0_scan_next();
        if (cc1_at_punct(CC0_CH_RPAREN))
            break;
        if (!cc1_at_punct(CC0_CH_COMMA)) {
            cc1_error = 48;
            return 0;
        }
        cc0_scan_next();
    }
    if (param_count > cc1_max_param_count)
        cc1_max_param_count = param_count;
    cc1_current_function_param_count = param_count;
    cc0_scan_next();
    return 1;
}

function cc1_parse_var_statement_tokens()
{
    cc1_local_decl_count = cc1_local_decl_count + 1;
    cc1_current_function_local_count = cc1_current_function_local_count + 1;
    cc0_scan_next();
    if (cc0_get_tok_class() != CC0_TOK_NAME) {
        cc1_error = 57;
        return 0;
    }
    cc1_local_table_add(
        cc1_hash_current_name_with(0),
        cc0_get_tok_len(),
        cc1_current_function_local_count - 1,
        cc1_current_function_ordinal);
    cc0_scan_next();
    return cc1_parse_statement_tail_tokens(2);
}

function cc1_parse_return_statement_tokens()
{
    cc1_return_count = cc1_return_count + 1;
    cc0_scan_next();
    return cc1_parse_statement_tail_tokens(1);
}

function cc1_parse_if_statement_tokens(body_depth)
{
    cc1_if_count = cc1_if_count + 1;
    cc0_scan_next();
    if (!cc1_parse_balanced_parens_tokens())
        return 0;
    return cc1_parse_body_statement_tokens(body_depth);
}

function cc1_parse_while_statement_tokens(body_depth)
{
    cc1_while_count = cc1_while_count + 1;
    cc0_scan_next();
    if (!cc1_parse_balanced_parens_tokens())
        return 0;
    return cc1_parse_body_statement_tokens(body_depth);
}

function cc1_parse_block_tokens(body_depth)
{
    if (!cc1_at_punct(CC0_CH_LBRACE)) {
        cc1_error = 49;
        return 0;
    }
    cc1_note_body_block_depth(body_depth);
    cc0_scan_next();
    while (cc0_get_tok_class() != CC0_TOK_EOF) {
        if (cc1_at_punct(CC0_CH_RBRACE)) {
            cc0_scan_next();
            return 1;
        }
        if (!cc1_parse_body_statement_tokens(body_depth))
            return 0;
    }
    cc1_error = 50;
    return 0;
}

function cc1_parse_body_statement_tokens(body_depth)
{
    var statement_kind;
    var statement_start;

    cc1_current_function_statement_count = cc1_current_function_statement_count + 1;
    statement_start = cc0_get_tok_start();
    statement_kind = 5;
    if (cc0_tok_is_word_return())
        statement_kind = 1;
    if (cc0_tok_is_word_if())
        statement_kind = 2;
    if (cc0_tok_is_word_while())
        statement_kind = 3;
    if (cc0_tok_is_word_var())
        statement_kind = 4;
    if (cc1_at_punct(CC0_CH_LBRACE))
        statement_kind = 6;
    cc1_statement_table_add(statement_kind, body_depth, statement_start, cc1_current_function_ordinal);
    if (cc0_tok_is_word_return())
        return cc1_parse_return_statement_tokens();
    if (cc0_tok_is_word_if())
        return cc1_parse_if_statement_tokens(body_depth);
    if (cc0_tok_is_word_while())
        return cc1_parse_while_statement_tokens(body_depth);
    if (cc0_tok_is_word_var())
        return cc1_parse_var_statement_tokens();
    if (cc1_at_punct(CC0_CH_LBRACE))
        return cc1_parse_block_tokens(body_depth + 1);
    return cc1_parse_statement_tail_tokens(0);
}

function cc1_skip_function_body_tokens()
{
    var span;
    cc1_begin_function_body_metrics();
    if (!cc1_parse_block_tokens(1))
        return 0;
    span = cc0_get_tok_start() - cc1_current_function_source_start;
    if (span > cc1_max_function_source_span)
        cc1_max_function_source_span = span;
    cc1_function_table_add(
        cc1_current_function_name_hash,
        cc1_current_function_name_len,
        cc1_current_function_param_count,
        cc1_current_function_source_start,
        span,
        cc1_function_count - 1);
    return cc1_finish_function_body_metrics();
}

function cc1_parse_cc0_source_tokens()
{
    while (cc0_get_tok_class() != CC0_TOK_EOF) {
        if (cc0_tok_is_word_var()) {
            if (!cc1_parse_top_var_decl_tokens())
                return 0;
        } else {
            if (cc0_tok_is_word_function()) {
                if (!cc1_parse_function_signature_tokens())
                    return 0;
                if (!cc1_skip_function_body_tokens())
                    return 0;
            } else {
                if (!cc1_parse_top_assignment_tokens())
                    return 0;
            }
        }
    }
    return 1;
}

function cc1_parse_cc0_source_string(source)
{
    cc1_reset();
    cc1_symbol_table_reset();
    cc1_function_table_reset();
    cc1_statement_table_reset();
    cc1_param_table_reset();
    cc1_local_table_reset();
    cc1_expr_table_reset();
    cc0_source_set_string(source);
    cc0_scan_next();
    if (!cc1_parse_cc0_source_tokens())
        return 0;
    if (cc0_get_tok_class() != CC0_TOK_EOF) {
        cc1_error = 2;
        return 0;
    }
    return 1;
}

function cc1_eval_expr_table_value(index)
{
    var flags;
    var kind;
    var start;
    if (index < 0) {
        cc1_error = 65;
        return 0;
    }
    if (index >= cc1_expr_table_count) {
        cc1_error = 66;
        return 0;
    }
    kind = cc1_get_expr_table_cell(index, 0);
    start = cc1_get_expr_table_cell(index, 1);
    flags = cc1_get_expr_table_cell(index, 4);
    cc0_source_seek(start);
    cc0_scan_next();
    if (kind == 2) {
        if (!cc1_at_punct(CC0_CH_EQUAL)) {
            cc1_error = 67;
            return 0;
        }
        cc0_scan_next();
        cc1_last_value = cc1_parse_expr_tokens();
        if (cc1_error)
            return 0;
        return 1;
    }
    if (flags & 1) {
        if (!cc1_parse_assignment_tokens())
            return 0;
        return 1;
    }
    cc1_last_value = cc1_parse_expr_tokens();
    if (cc1_error)
        return 0;
    return 1;
}

function cc1_eval_function_table2(index, arg0, arg1)
{
    if (index < 0) {
        cc1_error = 68;
        return 0;
    }
    if (index >= cc1_function_table_count) {
        cc1_error = 69;
        return 0;
    }
    return cc1_eval_function_table4(index, arg0, arg1, 0, 0);
}

function cc1_eval_function_table4(index, arg0, arg1, arg2, arg3)
{
    return cc1_eval_function_table9(index, arg0, arg1, arg2, arg3, 0, 0, 0, 0, 0);
}

function cc1_eval_function_table9(index, arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)
{
    var source_start;
    if (index < 0) {
        cc1_error = 68;
        return 0;
    }
    if (index >= cc1_function_table_count) {
        cc1_error = 69;
        return 0;
    }
    source_start = cc1_get_function_table_cell(index, 3);
    cc1_arg_0 = arg0;
    cc1_arg_1 = arg1;
    cc1_arg_2 = arg2;
    cc1_arg_3 = arg3;
    cc1_arg_4 = arg4;
    cc1_arg_5 = arg5;
    cc1_arg_6 = arg6;
    cc1_arg_7 = arg7;
    cc1_arg_8 = arg8;
    cc1_error = 0;
    cc1_reset_name_table();
    cc0_source_seek(source_start);
    cc0_scan_next();
    if (!cc1_parse_function_return_tokens())
        return 0;
    return 1;
}

function cc1_parse_function_return_tokens()
{
    var candidate_active;
    var candidate_value;
    var function_name;
    var param_count;
    var selected_value;
    var selected_value_set;
    var value;
    if (!cc0_tok_is_word_function()) {
        cc1_error = 10;
        return 0;
    }
    cc0_scan_next();
    if (cc0_get_tok_class() != CC0_TOK_NAME) {
        cc1_error = 11;
        return 0;
    }
    function_name = cc0_get_tok_first();
    cc1_last_name = function_name;
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_LPAREN)) {
        cc1_error = 12;
        return 0;
    }
    cc0_scan_next();
    param_count = 0;
    while (!cc1_at_punct(CC0_CH_RPAREN)) {
        if (cc0_get_tok_class() != CC0_TOK_NAME) {
            cc1_error = 20;
            return 0;
        }
        cc1_bind_name_value(cc1_hash_current_name_with(0), cc1_function_arg_value(param_count));
        if (cc1_error)
            return 0;
        param_count = param_count + 1;
        cc0_scan_next();
        if (cc1_at_punct(CC0_CH_RPAREN))
            break;
        if (!cc1_at_punct(CC0_CH_COMMA)) {
            cc1_error = 21;
            return 0;
        }
        cc0_scan_next();
    }
    if (!cc1_at_punct(CC0_CH_RPAREN)) {
        cc1_error = 13;
        return 0;
    }
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_LBRACE)) {
        cc1_error = 14;
        return 0;
    }
    cc0_scan_next();
    selected_value = 0;
    selected_value_set = 0;
    while (cc0_tok_is_word_var()) {
        cc0_scan_next();
        if (!cc1_parse_assignment_tokens())
            return 0;
        if (!cc1_at_punct(CC0_CH_SEMI)) {
            cc1_error = 18;
            return 0;
        }
        cc0_scan_next();
    }
    while (cc0_tok_is_word_if()) {
        cc0_scan_next();
        if (!cc1_at_punct(CC0_CH_LPAREN)) {
            cc1_error = 22;
            return 0;
        }
        cc0_scan_next();
        value = cc1_parse_expr_tokens();
        if (cc1_error)
            return 0;
        if (!cc1_at_punct(CC0_CH_RPAREN)) {
            cc1_error = 23;
            return 0;
        }
        cc0_scan_next();
        candidate_active = value;
        if (cc0_tok_is_word_if()) {
            cc0_scan_next();
            if (!cc1_at_punct(CC0_CH_LPAREN)) {
                cc1_error = 27;
                return 0;
            }
            cc0_scan_next();
            value = cc1_parse_expr_tokens();
            if (cc1_error)
                return 0;
            if (!cc1_at_punct(CC0_CH_RPAREN)) {
                cc1_error = 28;
                return 0;
            }
            cc0_scan_next();
            if (!value)
                candidate_active = 0;
        }
        if (!cc0_tok_is_word_return()) {
            cc1_error = 24;
            return 0;
        }
        cc0_scan_next();
        candidate_value = cc1_parse_expr_tokens();
        if (cc1_error)
            return 0;
        if (candidate_active)
            if (!selected_value_set)
                selected_value = candidate_value;
        if (candidate_active)
            selected_value_set = 1;
        if (!cc1_at_punct(CC0_CH_SEMI)) {
            cc1_error = 25;
            return 0;
        }
        cc0_scan_next();
    }
    if (!cc0_tok_is_word_return()) {
        cc1_error = 15;
        return 0;
    }
    cc0_scan_next();
    value = cc1_parse_expr_tokens();
    if (cc1_error)
        return 0;
    if (!cc1_at_punct(CC0_CH_SEMI)) {
        cc1_error = 16;
        return 0;
    }
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_RBRACE)) {
        cc1_error = 17;
        return 0;
    }
    cc0_scan_next();
    if (selected_value_set)
        value = selected_value;
    cc1_last_name = function_name;
    cc1_last_value = value;
    return 1;
}

function cc1_parse_function_return_string(source)
{
    cc1_reset();
    cc1_arg_0 = 0;
    cc1_arg_1 = 0;
    cc1_arg_2 = 0;
    cc1_arg_3 = 0;
    cc1_arg_4 = 0;
    cc1_arg_5 = 0;
    cc1_arg_6 = 0;
    cc1_arg_7 = 0;
    cc1_arg_8 = 0;
    cc1_reset_name_table();
    cc0_source_set_string(source);
    cc0_scan_next();
    if (!cc1_parse_function_return_tokens())
        return 0;
    if (cc0_get_tok_class() != CC0_TOK_EOF) {
        cc1_error = 2;
        return 0;
    }
    return 1;
}

function cc1_parse_function2_string(source, arg0, arg1)
{
    cc1_reset();
    cc1_arg_0 = arg0;
    cc1_arg_1 = arg1;
    cc1_arg_2 = 0;
    cc1_arg_3 = 0;
    cc1_arg_4 = 0;
    cc1_arg_5 = 0;
    cc1_arg_6 = 0;
    cc1_arg_7 = 0;
    cc1_arg_8 = 0;
    cc1_reset_name_table();
    cc0_source_set_string(source);
    cc0_scan_next();
    if (!cc1_parse_function_return_tokens())
        return 0;
    if (cc0_get_tok_class() != CC0_TOK_EOF) {
        cc1_error = 2;
        return 0;
    }
    return 1;
}

function cc1_get_last_value()
{
    return cc1_last_value;
}

function cc1_get_last_name()
{
    return cc1_last_name;
}

function cc1_get_error()
{
    return cc1_error;
}

function cc1_get_function_count()
{
    return cc1_function_count;
}

function cc1_get_top_decl_count()
{
    return cc1_top_decl_count;
}

function cc1_get_return_count()
{
    return cc1_return_count;
}

function cc1_get_if_count()
{
    return cc1_if_count;
}

function cc1_get_while_count()
{
    return cc1_while_count;
}

function cc1_get_local_decl_count()
{
    return cc1_local_decl_count;
}

function cc1_get_body_semi_count()
{
    return cc1_body_semi_count;
}

function cc1_get_max_body_depth()
{
    return cc1_max_body_depth;
}

function cc1_get_param_count()
{
    return cc1_param_count;
}

function cc1_get_max_param_count()
{
    return cc1_max_param_count;
}

function cc1_get_body_call_count()
{
    return cc1_body_call_count;
}

function cc1_get_max_body_call_arg_count()
{
    return cc1_max_body_call_arg_count;
}

function cc1_get_body_assignment_count()
{
    return cc1_body_assignment_count;
}

function cc1_get_max_body_expr_depth()
{
    return cc1_max_body_expr_depth;
}

function cc1_get_max_function_statement_count()
{
    return cc1_max_function_statement_count;
}

function cc1_get_max_function_local_count()
{
    return cc1_max_function_local_count;
}

function cc1_get_body_expr_statement_count()
{
    return cc1_body_expr_statement_count;
}

function cc1_get_body_call_statement_count()
{
    return cc1_body_call_statement_count;
}

function cc1_get_body_return_call_count()
{
    return cc1_body_return_call_count;
}

function cc1_get_body_local_init_count()
{
    return cc1_body_local_init_count;
}

function cc1_get_body_name_assignment_count()
{
    return cc1_body_name_assignment_count;
}

function cc1_get_body_plus_op_count()
{
    return cc1_body_plus_op_count;
}

function cc1_get_body_minus_op_count()
{
    return cc1_body_minus_op_count;
}

function cc1_get_body_star_op_count()
{
    return cc1_body_star_op_count;
}

function cc1_get_body_compare_op_count()
{
    return cc1_body_compare_op_count;
}

function cc1_get_body_not_op_count()
{
    return cc1_body_not_op_count;
}

function cc1_get_function_name_char_count()
{
    return cc1_function_name_char_count;
}

function cc1_get_max_function_name_len()
{
    return cc1_max_function_name_len;
}

function cc1_get_function_name_hash()
{
    return cc1_function_name_hash;
}

function cc1_get_global_name_char_count()
{
    return cc1_global_name_char_count;
}

function cc1_get_max_global_name_len()
{
    return cc1_max_global_name_len;
}

function cc1_get_global_name_hash()
{
    return cc1_global_name_hash;
}

function cc1_get_max_function_source_span()
{
    return cc1_max_function_source_span;
}

function cc1_get_function_slot_hash(index)
{
    if (index == 0)
        return cc1_function_slot0_hash;
    if (index == 1)
        return cc1_function_slot1_hash;
    if (index == 2)
        return cc1_function_slot2_hash;
    if (index == 3)
        return cc1_function_slot3_hash;
    return -1;
}

function cc1_get_function_slot_len(index)
{
    if (index == 0)
        return cc1_function_slot0_len;
    if (index == 1)
        return cc1_function_slot1_len;
    if (index == 2)
        return cc1_function_slot2_len;
    if (index == 3)
        return cc1_function_slot3_len;
    return -1;
}

function cc1_get_global_slot_hash(index)
{
    if (index == 0)
        return cc1_global_slot0_hash;
    if (index == 1)
        return cc1_global_slot1_hash;
    if (index == 2)
        return cc1_global_slot2_hash;
    if (index == 3)
        return cc1_global_slot3_hash;
    return -1;
}

function cc1_get_global_slot_len(index)
{
    if (index == 0)
        return cc1_global_slot0_len;
    if (index == 1)
        return cc1_global_slot1_len;
    if (index == 2)
        return cc1_global_slot2_len;
    if (index == 3)
        return cc1_global_slot3_len;
    return -1;
}

function cc1_get_symbol_table_count()
{
    return cc1_symbol_table_count;
}

function cc1_get_symbol_table_overflow()
{
    return cc1_symbol_table_overflow;
}

function cc1_get_symbol_table_cell(index, field)
{
    if (index < 0)
        return -1;
    if (index >= cc1_symbol_table_count)
        return -1;
    if (field < 0)
        return -1;
    if (field > 3)
        return -1;
    return cc0_cell_get(cc1_symbol_table_ptr, index * 4 + field);
}

function cc1_get_function_table_count()
{
    return cc1_function_table_count;
}

function cc1_get_function_table_overflow()
{
    return cc1_function_table_overflow;
}

function cc1_get_function_table_cell(index, field)
{
    if (index < 0)
        return -1;
    if (index >= cc1_function_table_count)
        return -1;
    if (field < 0)
        return -1;
    if (field > 5)
        return -1;
    return cc0_cell_get(cc1_function_table_ptr, index * 6 + field);
}

function cc1_get_statement_table_count()
{
    return cc1_statement_table_count;
}

function cc1_get_statement_table_overflow()
{
    return cc1_statement_table_overflow;
}

function cc1_get_statement_table_cell(index, field)
{
    if (index < 0)
        return -1;
    if (index >= cc1_statement_table_count)
        return -1;
    if (field < 0)
        return -1;
    if (field > 3)
        return -1;
    return cc0_cell_get(cc1_statement_table_ptr, index * 4 + field);
}

function cc1_get_param_table_count()
{
    return cc1_param_table_count;
}

function cc1_get_param_table_overflow()
{
    return cc1_param_table_overflow;
}

function cc1_get_param_table_cell(index, field)
{
    if (index < 0)
        return -1;
    if (index >= cc1_param_table_count)
        return -1;
    if (field < 0)
        return -1;
    if (field > 3)
        return -1;
    return cc0_cell_get(cc1_param_table_ptr, index * 4 + field);
}

function cc1_get_local_table_count()
{
    return cc1_local_table_count;
}

function cc1_get_local_table_overflow()
{
    return cc1_local_table_overflow;
}

function cc1_get_local_table_cell(index, field)
{
    if (index < 0)
        return -1;
    if (index >= cc1_local_table_count)
        return -1;
    if (field < 0)
        return -1;
    if (field > 3)
        return -1;
    return cc0_cell_get(cc1_local_table_ptr, index * 4 + field);
}

function cc1_get_expr_table_count()
{
    return cc1_expr_table_count;
}

function cc1_get_expr_table_overflow()
{
    return cc1_expr_table_overflow;
}

function cc1_get_expr_table_cell(index, field)
{
    if (index < 0)
        return -1;
    if (index >= cc1_expr_table_count)
        return -1;
    if (field < 0)
        return -1;
    if (field > 4)
        return -1;
    return cc0_cell_get(cc1_expr_table_ptr, index * 5 + field);
}
