/*
 * cc1 stubs for the staged bootstrap scaffold.
 *
 * Like cc0.c, this file stays in the JavaScript/C intersection. The functions
 * hold the first layer above cc0. cc1 currently parses only a tiny arithmetic
 * grammar over the cc0 scanner:
 *
 *     sum := number ("+" number)*
 */

var cc1_stub_version;
var cc1_last_value;
var cc1_error;

cc1_stub_version = 1;
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

function cc1_parse_sum8(c0, c1, c2, c3, c4, c5, c6, c7)
{
    var value;
    var rhs;
    cc1_reset();
    cc0_source_set8(c0, c1, c2, c3, c4, c5, c6, c7);
    cc0_scan_next();
    value = cc1_parse_number();
    while (cc1_error == 0) {
        cc0_scan_next();
        if (cc0_get_tok_class() == CC0_TOK_EOF) {
            cc1_last_value = value;
            return 1;
        }
        if (cc0_get_tok_class() != CC0_TOK_PUNCT) {
            cc1_error = 2;
            return 0;
        }
        if (cc0_get_tok_first() != 43) {
            cc1_error = 3;
            return 0;
        }
        cc0_scan_next();
        rhs = cc1_parse_number();
        value = value + rhs;
    }
    return 0;
}

function cc1_get_last_value()
{
    return cc1_last_value;
}

function cc1_get_error()
{
    return cc1_error;
}
