int cc0_add();
int cc0_select();
int cc0_not();
int cc0_is_word_function_chars();
int cc0_is_word_var_chars();
int cc0_is_dialect_type_chars();
int cc0_is_word_return_chars();
int mks();
int mkc();
int cc0_heap_get();
int cc0_heap_is_string();
int cc0_is_digit();
int cc0_is_oct_digit();
int cc0_is_name_start();
int cc0_is_name_continue();
int cc0_is_space();
int cc0_tccpp_char_flags();
int cc0_tccpp_is_space();
int cc0_to_upper();
int cc0_token_class();
int cc0_source_set8();
int cc0_source_set16();
int cc0_source_set_string();
int cc0_scan_next();
int cc0_get_tok_class();
int cc0_get_tok_start();
int cc0_get_tok_len();
int cc0_get_tok_value();
int cc0_tok_is_word_function();
int cc0_tok_is_word_var();
int cc0_tok_is_word_return();
int cc1_compile_unit();
int cc1_has_real_parser();
int cc1_bind_name_value();
int cc1_parse_expr8();
int cc1_parse_expr_string();
int cc1_parse_sum8();
int cc1_parse_assignment8();
int cc1_parse_assignment_string();
int cc1_parse_program16();
int cc1_parse_program_string();
int cc1_parse_function_return_string();
int cc1_get_last_name();
int cc1_get_last_value();
int cc1_get_error();
int cc2_ar_is_conflict_option();
int cc2_ar_is_verbose_option();
int cc2_ar_be32();
int cc2_ar_is_exported_symbol();

int main()
{
    int cc0_test_string;

    if (cc0_add(2, 3) != 5)
        return 1;
    if (cc0_select(1, 7, 9) != 7)
        return 2;
    if (cc0_select(0, 7, 9) != 9)
        return 3;
    if (cc0_not(0) != 1 || cc0_not(4) != 0)
        return 4;
    if (mkc('A') != 'A')
        return 56;
    cc0_test_string = mks("Az");
    if (cc0_heap_get(cc0_test_string, 0) != 'A' ||
        cc0_heap_get(cc0_test_string, 1) != 'z' ||
        cc0_heap_get(cc0_test_string, 2) != 0)
        return 57;
    if (!cc0_heap_is_string(mks("var"), 'v', 'a', 'r', 0))
        return 58;
    if (!cc0_is_word_function_chars('f', 'u', 'n', 'c', 't', 'i', 'o', 'n', 0) ||
        cc0_is_word_function_chars('f', 'u', 'n', 'c', 't', 'i', 'o', 0, 0))
        return 53;
    if (!cc0_is_word_var_chars('v', 'a', 'r', 0) ||
        cc0_is_word_var_chars('v', 'a', 'r', 's'))
        return 54;
    if (!cc0_is_dialect_type_chars('f', 'u', 'n', 'c', 't', 'i', 'o', 'n', 0) ||
        !cc0_is_dialect_type_chars('v', 'a', 'r', 0, 0, 0, 0, 0, 0) ||
        cc0_is_dialect_type_chars('i', 'n', 't', 0, 0, 0, 0, 0, 0))
        return 55;
    if (!cc0_is_word_return_chars('r', 'e', 't', 'u', 'r', 'n', 0) ||
        cc0_is_word_return_chars('r', 'e', 't', 'u', 'r', 'n', 's'))
        return 70;
    if (!cc0_is_digit(48) || !cc0_is_digit(57) || cc0_is_digit(58))
        return 5;
    if (!cc0_is_oct_digit(48) || !cc0_is_oct_digit(55) || cc0_is_oct_digit(56))
        return 6;
    if (!cc0_is_name_start(95) || !cc0_is_name_start(65))
        return 7;
    if (cc0_to_upper(97) != 65 || cc0_to_upper(65) != 65 || cc0_to_upper(48) != 48)
        return 8;
    if (!cc0_is_name_continue(57) || cc0_is_name_continue(45))
        return 9;
    if (!cc0_is_space(32) || !cc0_is_space(10) || !cc0_is_space(12) || cc0_is_space(65))
        return 10;
    if (cc0_tccpp_char_flags(32) != 1 || cc0_tccpp_char_flags(10) != 0 || cc0_tccpp_char_flags(65) != 2 || cc0_tccpp_char_flags(48) != 4)
        return 11;
    if (!cc0_tccpp_is_space(32) || cc0_tccpp_is_space(10) || cc0_tccpp_is_space(65))
        return 12;
    if (cc0_token_class(-1) != 0)
        return 13;
    if (cc0_token_class(65) != 1)
        return 14;
    if (cc0_token_class(52) != 2)
        return 15;
    if (cc0_token_class(32) != 3)
        return 16;
    if (cc0_token_class(43) != 4)
        return 17;
    cc0_source_set8(32, 97, 98, 49, 32, 50, 51, -1);
    if (cc0_scan_next() != 1)
        return 18;
    if (cc0_get_tok_class() != 1)
        return 19;
    if (cc0_get_tok_start() != 1 || cc0_get_tok_len() != 3)
        return 20;
    if (cc0_scan_next() != 2)
        return 21;
    if (cc0_get_tok_start() != 5 || cc0_get_tok_len() != 2)
        return 22;
    if (cc0_get_tok_value() != 23)
        return 23;
    if (cc0_scan_next() != 0)
        return 24;
    cc0_source_set16(32, 32, 32, 32, 32, 32, 32, 32, 52, -1, -1, -1, -1, -1, -1, -1);
    if (cc0_scan_next() != 2)
        return 25;
    if (cc0_get_tok_start() != 8 || cc0_get_tok_value() != 4)
        return 26;
    cc0_source_set_string(mks("  abc1 23"));
    if (cc0_scan_next() != 1)
        return 59;
    if (cc0_get_tok_start() != 2 || cc0_get_tok_len() != 4)
        return 60;
    if (cc0_scan_next() != 2)
        return 61;
    if (cc0_get_tok_value() != 23)
        return 62;
    if (cc0_scan_next() != 0)
        return 63;
    cc0_source_set_string(mks("function var return"));
    if (cc0_scan_next() != 1 || !cc0_tok_is_word_function())
        return 71;
    if (cc0_scan_next() != 1 || !cc0_tok_is_word_var())
        return 72;
    if (cc0_scan_next() != 1 || !cc0_tok_is_word_return())
        return 73;
    if (cc1_compile_unit(0) != 1)
        return 27;
    if (cc1_has_real_parser() != 1)
        return 28;
    if (cc1_parse_sum8(49, 50, 43, 51, 32, -1, -1, -1) != 1)
        return 29;
    if (cc1_get_last_value() != 15)
        return 30;
    if (cc1_parse_sum8(50, 43, 51, 42, 52, -1, -1, -1) != 1)
        return 31;
    if (cc1_get_last_value() != 14)
        return 32;
    if (cc1_parse_sum8(40, 50, 43, 51, 41, 42, 52, -1) != 1)
        return 33;
    if (cc1_get_last_value() != 20)
        return 34;
    if (cc1_bind_name_value(97, 4) != 1)
        return 35;
    if (cc1_parse_expr8(97, 42, 51, 43, 50, -1, -1, -1) != 1)
        return 36;
    if (cc1_get_last_value() != 14)
        return 37;
    if (cc1_parse_assignment8(98, 61, 50, 43, 51, 42, 52, -1) != 1)
        return 38;
    if (cc1_get_last_name() != 98 || cc1_get_last_value() != 14)
        return 39;
    if (cc1_parse_expr8(98, 43, 49, -1, -1, -1, -1, -1) != 1)
        return 40;
    if (cc1_get_last_value() != 15)
        return 41;
    if (cc1_parse_program16(97, 61, 49, 59, 98, 61, 97, 43, 50, -1, -1, -1, -1, -1, -1, -1) != 1)
        return 42;
    if (cc1_get_last_name() != 98 || cc1_get_last_value() != 3)
        return 43;
    if (cc1_parse_expr8(98, 42, 52, -1, -1, -1, -1, -1) != 1)
        return 44;
    if (cc1_get_last_value() != 12)
        return 45;
    if (cc1_parse_assignment_string(mks("c=7+8*2")) != 1)
        return 64;
    if (cc1_get_last_name() != 'c' || cc1_get_last_value() != 23)
        return 65;
    if (cc1_parse_program_string(mks("a=1;b=a+2;c=(b+3)*4")) != 1)
        return 66;
    if (cc1_get_last_name() != 'c' || cc1_get_last_value() != 24)
        return 67;
    if (cc1_parse_expr_string(mks("c+1")) != 1)
        return 68;
    if (cc1_get_last_value() != 25)
        return 69;
    if (cc1_parse_function_return_string(mks("function main(){return 7+8*2;}")) != 1)
        return 74;
    if (cc1_get_last_name() != 'm' || cc1_get_last_value() != 23)
        return 75;
    if (cc1_parse_sum8(49, 43, 43, 50, -1, -1, -1, -1) != 0)
        return 46;
    if (cc1_get_error() == 0)
        return 47;
    if (cc2_ar_is_conflict_option(97) != 1)
        return 48;
    if (cc2_ar_is_conflict_option(114) != 0)
        return 49;
    if (cc2_ar_is_verbose_option(118) != 1)
        return 50;
    if (cc2_ar_be32(1) != 16777216)
        return 51;
    if (cc2_ar_is_exported_symbol(16) != 1 || cc2_ar_is_exported_symbol(19) != 0)
        return 52;
    return 0;
}
