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

cc0_source_set16(32, 32, 32, 32, 32, 32, 32, 32, 52, -1, -1, -1, -1, -1, -1, -1);

if (cc0_scan_next() !== 2)
    throw new Error("cc0 scanner 16-byte window class failed");

if (cc0_get_tok_start() !== 8 || cc0_get_tok_value() !== 4)
    throw new Error("cc0 scanner 16-byte window value failed");

load("../tcc_27_layered/cc1.c");
load("../tcc_27_layered/cc2.c");

if (cc1_compile_unit(0) !== 1)
    throw new Error("cc1 stub compile failed");

if (cc1_has_real_parser() !== 1)
    throw new Error("cc1 parser marker failed");

if (cc1_parse_sum8(49, 50, 43, 51, 32, -1, -1, -1) !== 1)
    throw new Error("cc1 sum parse failed");

if (cc1_get_last_value() !== 15)
    throw new Error("cc1 sum value failed");

if (cc1_parse_sum8(50, 43, 51, 42, 52, -1, -1, -1) !== 1)
    throw new Error("cc1 precedence parse failed");

if (cc1_get_last_value() !== 14)
    throw new Error("cc1 precedence value failed");

if (cc1_parse_sum8(40, 50, 43, 51, 41, 42, 52, -1) !== 1)
    throw new Error("cc1 parenthesized parse failed");

if (cc1_get_last_value() !== 20)
    throw new Error("cc1 parenthesized value failed");

if (cc1_bind_name_value(97, 4) !== 1)
    throw new Error("cc1 name bind failed");

if (cc1_parse_expr8(97, 42, 51, 43, 50, -1, -1, -1) !== 1)
    throw new Error("cc1 name expression parse failed");

if (cc1_get_last_value() !== 14)
    throw new Error("cc1 name expression value failed");

if (cc1_parse_assignment8(98, 61, 50, 43, 51, 42, 52, -1) !== 1)
    throw new Error("cc1 assignment parse failed");

if (cc1_get_last_name() !== 98 || cc1_get_last_value() !== 14)
    throw new Error("cc1 assignment state failed");

if (cc1_parse_expr8(98, 43, 49, -1, -1, -1, -1, -1) !== 1)
    throw new Error("cc1 assigned name parse failed");

if (cc1_get_last_value() !== 15)
    throw new Error("cc1 assigned name value failed");

if (cc1_parse_program16(97, 61, 49, 59, 98, 61, 97, 43, 50, -1, -1, -1, -1, -1, -1, -1) !== 1)
    throw new Error("cc1 program parse failed");

if (cc1_get_last_name() !== 98 || cc1_get_last_value() !== 3)
    throw new Error("cc1 program final state failed");

if (cc1_parse_expr8(98, 42, 52, -1, -1, -1, -1, -1) !== 1)
    throw new Error("cc1 program binding parse failed");

if (cc1_get_last_value() !== 12)
    throw new Error("cc1 program binding value failed");

if (cc1_parse_sum8(49, 43, 43, 50, -1, -1, -1, -1) !== 0)
    throw new Error("cc1 bad sum accepted");

if (cc1_get_error() === 0)
    throw new Error("cc1 bad sum did not report error");

if (cc2_ar_is_conflict_option(97) !== 1)
    throw new Error("cc2 ar conflict option failed");

if (cc2_ar_is_conflict_option(114) !== 0)
    throw new Error("cc2 ar allowed option failed");

if (cc2_ar_is_verbose_option(118) !== 1)
    throw new Error("cc2 ar verbose option failed");

if (cc2_ar_be32(1) !== 16777216)
    throw new Error("cc2 ar byte swap failed");

if (cc2_ar_is_exported_symbol(16) !== 1 || cc2_ar_is_exported_symbol(19) !== 0)
    throw new Error("cc2 ar exported symbol failed");
