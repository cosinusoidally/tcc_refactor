/*
 * cc1 scaffold for the staged bootstrap.
 *
 * Like cc0.c, this file stays in the JavaScript/C intersection. The functions
 * hold the first layer above cc0. cc1 currently parses only a tiny expression
 * grammar over the cc0 scanner:
 *
 *     expr    := product ("+" product)*
 *     product := primary ("*" primary)*
 *     primary := number | "(" expr ")"
 */

var cc1_version;
var cc1_last_value;
var cc1_error;

cc1_version = 1;
cc1_last_value = 0;
cc1_error = 0;

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
    if (cc1_at_punct(40)) {
        cc0_scan_next();
        value = cc1_parse_sum_tokens();
        if (cc1_error)
            return 0;
        if (!cc1_at_punct(41)) {
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
        if (!cc1_at_punct(42))
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
        if (!cc1_at_punct(43))
            return value;
        cc0_scan_next();
        rhs = cc1_parse_product();
        value = value + rhs;
    }
    return 0;
}

function cc1_parse_sum8(c0, c1, c2, c3, c4, c5, c6, c7)
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

function cc1_get_last_value()
{
    return cc1_last_value;
}

function cc1_get_error()
{
    return cc1_error;
}
