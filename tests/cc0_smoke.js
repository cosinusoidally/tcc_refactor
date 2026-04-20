load("../tcc_27_layered/cc0.c");

if (cc0_add(2, 3) !== 5)
    throw new Error("cc0_add failed");

if (cc0_select(1, 7, 9) !== 7)
    throw new Error("cc0_select true branch failed");

if (cc0_select(0, 7, 9) !== 9)
    throw new Error("cc0_select false branch failed");

if (cc0_not(0) !== 1 || cc0_not(4) !== 0)
    throw new Error("cc0_not failed");

if (!cc0_is_digit(48) || !cc0_is_digit(57) || cc0_is_digit(58))
    throw new Error("cc0_is_digit failed");

if (!cc0_is_name_start(95) || !cc0_is_name_start(65))
    throw new Error("cc0_is_name_start failed");

if (!cc0_is_name_continue(57) || cc0_is_name_continue(45))
    throw new Error("cc0_is_name_continue failed");

if (!cc0_is_space(32) || !cc0_is_space(10) || cc0_is_space(65))
    throw new Error("cc0_is_space failed");

if (cc0_token_class(-1) !== 0)
    throw new Error("cc0 eof token failed");

if (cc0_token_class(65) !== 1)
    throw new Error("cc0 name token failed");

if (cc0_token_class(52) !== 2)
    throw new Error("cc0 number token failed");

if (cc0_token_class(32) !== 3)
    throw new Error("cc0 space token failed");

if (cc0_token_class(43) !== 4)
    throw new Error("cc0 punct token failed");

cc0_source_set8(32, 97, 98, 49, 32, 50, 51, -1);

if (cc0_scan_next() !== 1)
    throw new Error("cc0 scanner name class failed");

if (cc0_get_tok_start() !== 1 || cc0_get_tok_len() !== 3)
    throw new Error("cc0 scanner name span failed");

if (cc0_scan_next() !== 2)
    throw new Error("cc0 scanner number class failed");

if (cc0_get_tok_start() !== 5 || cc0_get_tok_len() !== 2)
    throw new Error("cc0 scanner number span failed");

if (cc0_get_tok_value() !== 23)
    throw new Error("cc0 scanner number value failed");

if (cc0_scan_next() !== 0)
    throw new Error("cc0 scanner eof failed");

load("../tcc_27_layered/cc1.c");

if (cc1_compile_unit(0) !== 1)
    throw new Error("cc1 stub compile failed");

if (cc1_has_real_parser() !== 1)
    throw new Error("cc1 parser marker failed");

if (cc1_parse_sum8(49, 50, 43, 51, 32, -1, -1, -1) !== 1)
    throw new Error("cc1 sum parse failed");

if (cc1_get_last_value() !== 15)
    throw new Error("cc1 sum value failed");

if (cc1_parse_sum8(49, 43, 43, 50, -1, -1, -1, -1) !== 0)
    throw new Error("cc1 bad sum accepted");

if (cc1_get_error() === 0)
    throw new Error("cc1 bad sum did not report error");
