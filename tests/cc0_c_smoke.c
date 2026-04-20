int cc0_add();
int cc0_select();
int cc0_not();
int cc0_is_digit();
int cc0_is_name_start();
int cc0_is_name_continue();
int cc0_is_space();
int cc0_tccpp_char_flags();
int cc0_token_class();
int cc0_source_set8();
int cc0_source_set16();
int cc0_scan_next();
int cc0_get_tok_class();
int cc0_get_tok_start();
int cc0_get_tok_len();
int cc0_get_tok_value();
int cc1_compile_unit();
int cc1_has_real_parser();
int cc1_bind_name_value();
int cc1_parse_expr8();
int cc1_parse_sum8();
int cc1_parse_assignment8();
int cc1_parse_program16();
int cc1_get_last_name();
int cc1_get_last_value();
int cc1_get_error();
int cc2_ar_is_conflict_option();
int cc2_ar_is_verbose_option();
int cc2_ar_be32();
int cc2_ar_is_exported_symbol();

int main()
{
    if (cc0_add(2, 3) != 5)
        return 1;
    if (cc0_select(1, 7, 9) != 7)
        return 2;
    if (cc0_select(0, 7, 9) != 9)
        return 3;
    if (cc0_not(0) != 1 || cc0_not(4) != 0)
        return 4;
    if (!cc0_is_digit(48) || !cc0_is_digit(57) || cc0_is_digit(58))
        return 5;
    if (!cc0_is_name_start(95) || !cc0_is_name_start(65))
        return 6;
    if (!cc0_is_name_continue(57) || cc0_is_name_continue(45))
        return 7;
    if (!cc0_is_space(32) || !cc0_is_space(10) || !cc0_is_space(12) || cc0_is_space(65))
        return 8;
    if (cc0_tccpp_char_flags(32) != 1 || cc0_tccpp_char_flags(10) != 0 || cc0_tccpp_char_flags(65) != 2 || cc0_tccpp_char_flags(48) != 4)
        return 9;
    if (cc0_token_class(-1) != 0)
        return 10;
    if (cc0_token_class(65) != 1)
        return 11;
    if (cc0_token_class(52) != 2)
        return 12;
    if (cc0_token_class(32) != 3)
        return 13;
    if (cc0_token_class(43) != 4)
        return 14;
    cc0_source_set8(32, 97, 98, 49, 32, 50, 51, -1);
    if (cc0_scan_next() != 1)
        return 15;
    if (cc0_get_tok_class() != 1)
        return 16;
    if (cc0_get_tok_start() != 1 || cc0_get_tok_len() != 3)
        return 17;
    if (cc0_scan_next() != 2)
        return 18;
    if (cc0_get_tok_start() != 5 || cc0_get_tok_len() != 2)
        return 19;
    if (cc0_get_tok_value() != 23)
        return 20;
    if (cc0_scan_next() != 0)
        return 21;
    cc0_source_set16(32, 32, 32, 32, 32, 32, 32, 32, 52, -1, -1, -1, -1, -1, -1, -1);
    if (cc0_scan_next() != 2)
        return 22;
    if (cc0_get_tok_start() != 8 || cc0_get_tok_value() != 4)
        return 23;
    if (cc1_compile_unit(0) != 1)
        return 24;
    if (cc1_has_real_parser() != 1)
        return 25;
    if (cc1_parse_sum8(49, 50, 43, 51, 32, -1, -1, -1) != 1)
        return 26;
    if (cc1_get_last_value() != 15)
        return 27;
    if (cc1_parse_sum8(50, 43, 51, 42, 52, -1, -1, -1) != 1)
        return 28;
    if (cc1_get_last_value() != 14)
        return 29;
    if (cc1_parse_sum8(40, 50, 43, 51, 41, 42, 52, -1) != 1)
        return 30;
    if (cc1_get_last_value() != 20)
        return 31;
    if (cc1_bind_name_value(97, 4) != 1)
        return 32;
    if (cc1_parse_expr8(97, 42, 51, 43, 50, -1, -1, -1) != 1)
        return 33;
    if (cc1_get_last_value() != 14)
        return 34;
    if (cc1_parse_assignment8(98, 61, 50, 43, 51, 42, 52, -1) != 1)
        return 35;
    if (cc1_get_last_name() != 98 || cc1_get_last_value() != 14)
        return 36;
    if (cc1_parse_expr8(98, 43, 49, -1, -1, -1, -1, -1) != 1)
        return 37;
    if (cc1_get_last_value() != 15)
        return 38;
    if (cc1_parse_program16(97, 61, 49, 59, 98, 61, 97, 43, 50, -1, -1, -1, -1, -1, -1, -1) != 1)
        return 39;
    if (cc1_get_last_name() != 98 || cc1_get_last_value() != 3)
        return 40;
    if (cc1_parse_expr8(98, 42, 52, -1, -1, -1, -1, -1) != 1)
        return 41;
    if (cc1_get_last_value() != 12)
        return 42;
    if (cc1_parse_sum8(49, 43, 43, 50, -1, -1, -1, -1) != 0)
        return 43;
    if (cc1_get_error() == 0)
        return 44;
    if (cc2_ar_is_conflict_option(97) != 1)
        return 45;
    if (cc2_ar_is_conflict_option(114) != 0)
        return 46;
    if (cc2_ar_is_verbose_option(118) != 1)
        return 47;
    if (cc2_ar_be32(1) != 16777216)
        return 48;
    if (cc2_ar_is_exported_symbol(16) != 1 || cc2_ar_is_exported_symbol(19) != 0)
        return 49;
    return 0;
}
