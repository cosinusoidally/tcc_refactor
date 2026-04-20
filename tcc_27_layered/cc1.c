/*
 * cc1 scaffold for the staged bootstrap.
 *
 * Like cc0.c, this file stays in the JavaScript/C intersection. The functions
 * hold the first layer above cc0. cc1 currently parses only a tiny expression
 * grammar over the cc0 scanner:
 *
 *     expr    := product ("+" product)*
 *     product := primary ("*" primary)*
 *     primary := number | name | "(" expr ")"
 *     func    := "function" name "(" ")" "{" "return" expr ";" "}"
 */

var cc1_version;
var cc1_last_value;
var cc1_last_name;
var cc1_error;
var cc1_name_0;
var cc1_name_1;
var cc1_name_2;
var cc1_name_3;
var cc1_value_0;
var cc1_value_1;
var cc1_value_2;
var cc1_value_3;

cc1_version = 1;
cc1_last_value = 0;
cc1_last_name = 0;
cc1_error = 0;
cc1_name_0 = -1;
cc1_name_1 = -1;
cc1_name_2 = -1;
cc1_name_3 = -1;
cc1_value_0 = 0;
cc1_value_1 = 0;
cc1_value_2 = 0;
cc1_value_3 = 0;

function cc1_compile_unit(source_id)
{
    return 1;
}

function cc1_has_real_parser()
{
    return 1;
}

function cc1_reset()
{
    cc1_last_value = 0;
    cc1_last_name = 0;
    cc1_error = 0;
    return 0;
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
    cc1_error = 6;
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

function cc1_parse_primary()
{
    var value;
    if (cc0_get_tok_class() == CC0_TOK_NUMBER) {
        value = cc1_parse_number();
        cc0_scan_next();
        return value;
    }
    if (cc0_get_tok_class() == CC0_TOK_NAME) {
        value = cc1_lookup_name(cc0_get_tok_first());
        cc0_scan_next();
        return value;
    }
    if (cc1_at_punct(CC0_CH_LPAREN)) {
        cc0_scan_next();
        value = cc1_parse_sum_tokens();
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
        if (!cc1_at_punct(CC0_CH_PLUS))
            return value;
        cc0_scan_next();
        rhs = cc1_parse_product();
        value = value + rhs;
    }
    return 0;
}

function cc1_parse_expr8(c0, c1, c2, c3, c4, c5, c6, c7)
{
    var value;
    cc1_reset();
    cc0_source_set8(c0, c1, c2, c3, c4, c5, c6, c7);
    cc0_scan_next();
    value = cc1_parse_sum_tokens();
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
    value = cc1_parse_sum_tokens();
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
    var value;
    if (cc0_get_tok_class() != CC0_TOK_NAME) {
        cc1_error = 7;
        return 0;
    }
    cc1_last_name = cc0_get_tok_first();
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_EQUAL)) {
        cc1_error = 8;
        return 0;
    }
    cc0_scan_next();
    value = cc1_parse_sum_tokens();
    if (cc1_error)
        return 0;
    cc1_last_value = value;
    cc1_bind_name_value(cc1_last_name, value);
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

function cc1_parse_function_return_tokens()
{
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
    cc1_last_name = cc0_get_tok_first();
    cc0_scan_next();
    if (!cc1_at_punct(CC0_CH_LPAREN)) {
        cc1_error = 12;
        return 0;
    }
    cc0_scan_next();
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
    if (!cc0_tok_is_word_return()) {
        cc1_error = 15;
        return 0;
    }
    cc0_scan_next();
    value = cc1_parse_sum_tokens();
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
    cc1_last_value = value;
    return 1;
}

function cc1_parse_function_return_string(source)
{
    cc1_reset();
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
