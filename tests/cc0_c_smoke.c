int cc0_add();
int cc0_select();
int cc0_not();
int cc0_is_word_function_chars();
int cc0_is_word_var_chars();
int cc0_is_dialect_type_chars();
int cc0_is_word_return_chars();
int cc0_is_word_if_chars();
int mks();
int mkc();
int cc0_heap_get();
int cc0_heap_slice();
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
int cc0_tok_is_word_if();
int cc0_tok_is_word_mkc();
int cc0_tok_is_word_mks();
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
int cc1_parse_cc0_source_string();
int cc1_parse_function_return_string();
int cc1_parse_function2_string();
int cc1_get_last_name();
int cc1_get_last_value();
int cc1_get_error();
int cc1_get_function_count();
int cc1_get_top_decl_count();
int cc1_get_return_count();
int cc1_get_if_count();
int cc1_get_while_count();
int cc1_get_local_decl_count();
int cc1_get_body_semi_count();
int cc1_get_max_body_depth();
int cc1_get_param_count();
int cc1_get_max_param_count();
int cc1_get_body_call_count();
int cc1_get_max_body_call_arg_count();
int cc1_get_body_assignment_count();
int cc1_get_max_body_expr_depth();
int cc1_get_max_function_statement_count();
int cc1_get_max_function_local_count();
int cc1_get_body_expr_statement_count();
int cc1_get_body_call_statement_count();
int cc1_get_body_return_call_count();
int cc1_get_body_local_init_count();
int cc1_get_body_name_assignment_count();
int cc1_get_body_plus_op_count();
int cc1_get_body_minus_op_count();
int cc1_get_body_star_op_count();
int cc1_get_body_compare_op_count();
int cc1_get_body_not_op_count();
int cc1_get_function_name_char_count();
int cc1_get_max_function_name_len();
int cc1_get_function_name_hash();
int cc1_get_global_name_char_count();
int cc1_get_max_global_name_len();
int cc1_get_global_name_hash();
int cc1_get_max_function_source_span();
int cc1_get_function_slot_hash();
int cc1_get_function_slot_len();
int cc1_get_global_slot_hash();
int cc1_get_global_slot_len();
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
    if (!cc0_is_word_if_chars('i', 'f', 0) ||
        cc0_is_word_if_chars('i', 'f', 's'))
        return 80;
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
    if (cc0_token_class(33) != 4)
        return 86;
    if (cc0_token_class(45) != 4 || cc0_token_class(60) != 4 || cc0_token_class(62) != 4)
        return 101;
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
    cc0_source_set_string(mks("function var return if"));
    if (cc0_scan_next() != 1 || !cc0_tok_is_word_function())
        return 71;
    if (cc0_scan_next() != 1 || !cc0_tok_is_word_var())
        return 72;
    if (cc0_scan_next() != 1 || !cc0_tok_is_word_return())
        return 73;
    if (cc0_scan_next() != 1 || !cc0_tok_is_word_if())
        return 81;
    cc0_source_set_string(mks("mkc('A') mks(\"Az\")"));
    if (cc0_scan_next() != 1 || !cc0_tok_is_word_mkc())
        return 126;
    if (cc0_scan_next() != 4 || cc0_scan_next() != 5)
        return 127;
    if (cc0_get_tok_value() != 'A')
        return 128;
    if (cc0_scan_next() != 4 || cc0_scan_next() != 1 || !cc0_tok_is_word_mks())
        return 129;
    if (cc0_scan_next() != 4 || cc0_scan_next() != 6)
        return 130;
    cc0_test_string = cc0_get_tok_value();
    if (cc0_heap_get(cc0_test_string, 0) != 'A' ||
        cc0_heap_get(cc0_test_string, 1) != 'z' ||
        cc0_heap_get(cc0_test_string, 2) != 0)
        return 131;
    if (cc0_scan_next() != 4 || cc0_scan_next() != 0)
        return 132;
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
    if (cc1_parse_expr_string(mks("2+3==5")) != 1)
        return 87;
    if (cc1_get_last_value() != 1)
        return 88;
    if (cc1_parse_expr_string(mks("2+3!=5")) != 1)
        return 89;
    if (cc1_get_last_value() != 0)
        return 90;
    if (cc1_parse_expr_string(mks("7-2*3")) != 1)
        return 102;
    if (cc1_get_last_value() != 1)
        return 103;
    if (cc1_parse_expr_string(mks("7>=5")) != 1)
        return 104;
    if (cc1_get_last_value() != 1)
        return 105;
    if (cc1_parse_expr_string(mks("7<=5")) != 1)
        return 106;
    if (cc1_get_last_value() != 0)
        return 107;
    if (cc1_parse_function_return_string(mks("function main(){return 7+8*2;}")) != 1)
        return 74;
    if (cc1_get_last_name() != 'm' || cc1_get_last_value() != 23)
        return 75;
    if (cc1_parse_function_return_string(mks("function main(){var a=7;var b=a*2;return b+3;}")) != 1)
        return 76;
    if (cc1_get_last_name() != 'm' || cc1_get_last_value() != 17)
        return 77;
    if (cc1_parse_function2_string(mks("function add(a,b){var c=a+b;return c*2;}"), 5, 6) != 1)
        return 78;
    if (cc1_get_last_name() != 'a' || cc1_get_last_value() != 22)
        return 79;
    if (cc1_parse_function2_string(mks("function pick(a,b){if(a)return b;return 3;}"), 1, 9) != 1)
        return 82;
    if (cc1_get_last_name() != 'p' || cc1_get_last_value() != 9)
        return 83;
    if (cc1_parse_function2_string(mks("function pick(a,b){if(a)return b;return 3;}"), 0, 9) != 1)
        return 84;
    if (cc1_get_last_name() != 'p' || cc1_get_last_value() != 3)
        return 85;
    if (cc1_parse_function2_string(mks("function ne(a,b){if(a!=b)return a;return b;}"), 4, 9) != 1)
        return 91;
    if (cc1_get_last_name() != 'n' || cc1_get_last_value() != 4)
        return 92;
    if (cc1_parse_function2_string(mks("function eq(a,b){if(a==b)return a+1;return b;}"), 4, 4) != 1)
        return 93;
    if (cc1_get_last_name() != 'e' || cc1_get_last_value() != 5)
        return 94;
    if (cc1_parse_function2_string(mks("function ch(a,b){if(a==0)return 7;if(b!=0)return b;return 3;}"), 0, 9) != 1)
        return 95;
    if (cc1_get_last_name() != 'c' || cc1_get_last_value() != 7)
        return 96;
    if (cc1_parse_function2_string(mks("function ch(a,b){if(a==0)return 7;if(b!=0)return b;return 3;}"), 1, 9) != 1)
        return 97;
    if (cc1_get_last_name() != 'c' || cc1_get_last_value() != 9)
        return 98;
    if (cc1_parse_function2_string(mks("function ch(a,b){if(a==0)return 7;if(b!=0)return b;return 3;}"), 1, 0) != 1)
        return 99;
    if (cc1_get_last_name() != 'c' || cc1_get_last_value() != 3)
        return 100;
    if (cc1_parse_function2_string(mks("function dg(c){if(c<48)return 0;if(c<=57)return 1;return 0;}"), 52, 0) != 1)
        return 108;
    if (cc1_get_last_name() != 'd' || cc1_get_last_value() != 1)
        return 109;
    if (cc1_parse_function2_string(mks("function dg(c){if(c<48)return 0;if(c<=57)return 1;return 0;}"), 58, 0) != 1)
        return 110;
    if (cc1_get_last_name() != 'd' || cc1_get_last_value() != 0)
        return 111;
    if (cc1_parse_function2_string(mks("function nd(c){if(c>=48)if(c<=57)return 1;return 0;}"), 52, 0) != 1)
        return 112;
    if (cc1_get_last_name() != 'n' || cc1_get_last_value() != 1)
        return 113;
    if (cc1_parse_function2_string(mks("function nd(c){if(c>=48)if(c<=57)return 1;return 0;}"), 47, 0) != 1)
        return 114;
    if (cc1_get_last_name() != 'n' || cc1_get_last_value() != 0)
        return 115;
    if (cc1_parse_function2_string(mks("function nd(c){if(c>=48)if(c<=57)return 1;return 0;}"), 58, 0) != 1)
        return 116;
    if (cc1_get_last_name() != 'n' || cc1_get_last_value() != 0)
        return 117;
    if (cc1_parse_function2_string(mks("function dc(c){if(c>=CC0_CH_0)if(c<=CC0_CH_9)return 1;return 0;}"), 52, 0) != 1)
        return 118;
    if (cc1_get_last_name() != 'd' || cc1_get_last_value() != 1)
        return 119;
    if (cc1_parse_function2_string(mks("function dc(c){if(c>=CC0_CH_0)if(c<=CC0_CH_9)return 1;return 0;}"), 58, 0) != 1)
        return 120;
    if (cc1_get_last_name() != 'd' || cc1_get_last_value() != 0)
        return 121;
    if (cc1_parse_function2_string(mks("function cd(c){if(cc0_is_digit(c))return 1;return 0;}"), 52, 0) != 1)
        return 122;
    if (cc1_get_last_name() != 'c' || cc1_get_last_value() != 1)
        return 123;
    if (cc1_parse_function2_string(mks("function cd(c){if(cc0_is_digit(c))return 1;return 0;}"), 65, 0) != 1)
        return 124;
    if (cc1_get_last_name() != 'c' || cc1_get_last_value() != 0)
        return 125;
    if (cc1_parse_expr_string(mks("mkc('A')")) != 1)
        return 133;
    if (cc1_get_last_value() != 'A')
        return 134;
    if (cc1_parse_expr_string(mks("cc0_heap_get(mks(\"Az\"),1)")) != 1)
        return 135;
    if (cc1_get_last_value() != 'z')
        return 136;
    if (cc1_parse_function_return_string(mks("function ch(){return mkc('C');}")) != 1)
        return 137;
    if (cc1_get_last_name() != 'c' || cc1_get_last_value() != 'C')
        return 138;
    if (cc1_parse_function_return_string(mks("function st(){return cc0_heap_get(mks(\"Hi\"),0);}")) != 1)
        return 139;
    if (cc1_get_last_name() != 's' || cc1_get_last_value() != 'H')
        return 140;
    if (cc1_parse_expr_string(mks("!0")) != 1)
        return 141;
    if (cc1_get_last_value() != 1)
        return 142;
    if (cc1_parse_expr_string(mks("!7")) != 1)
        return 143;
    if (cc1_get_last_value() != 0)
        return 144;
    if (cc1_parse_function2_string(mks("function nz(a,b){if(!a)return b;return a;}"), 0, 8) != 1)
        return 145;
    if (cc1_get_last_name() != 'n' || cc1_get_last_value() != 8)
        return 146;
    if (cc1_parse_function2_string(mks("function nz(a,b){if(!a)return b;return a;}"), 5, 8) != 1)
        return 147;
    if (cc1_get_last_name() != 'n' || cc1_get_last_value() != 5)
        return 148;
    if (cc1_parse_cc0_source_string(mks("/*comment*/var a;a=1;function f(x){if(x)return 1;return 0;}function w(x){var y=0;while(x)y=y+1;return y;}")) != 1)
        return 149;
    if (cc1_get_function_count() != 2)
        return 150;
    if (cc1_get_top_decl_count() != 2)
        return 151;
    if (cc1_get_return_count() != 3)
        return 152;
    if (cc1_get_if_count() != 1)
        return 153;
    if (cc1_get_while_count() != 1)
        return 154;
    if (cc1_get_local_decl_count() != 1)
        return 155;
    if (cc1_get_body_semi_count() != 5)
        return 156;
    if (cc1_get_max_body_depth() != 1)
        return 157;
    if (cc1_get_param_count() != 2)
        return 158;
    if (cc1_get_max_param_count() != 1)
        return 159;
    if (cc1_get_body_call_count() != 0)
        return 164;
    if (cc1_get_max_body_call_arg_count() != 0)
        return 165;
    if (cc1_get_body_assignment_count() != 2)
        return 166;
    if (cc1_get_max_body_expr_depth() != 1)
        return 167;
    if (cc1_get_max_function_statement_count() != 4)
        return 168;
    if (cc1_get_max_function_local_count() != 1)
        return 169;
    if (cc1_get_body_expr_statement_count() != 1)
        return 170;
    if (cc1_get_body_call_statement_count() != 0)
        return 171;
    if (cc1_get_body_return_call_count() != 0)
        return 172;
    if (cc1_get_body_local_init_count() != 1)
        return 173;
    if (cc1_get_body_name_assignment_count() != 1)
        return 174;
    if (cc1_get_body_plus_op_count() != 1)
        return 175;
    if (cc1_get_body_minus_op_count() != 0)
        return 176;
    if (cc1_get_body_star_op_count() != 0)
        return 177;
    if (cc1_get_body_compare_op_count() != 0)
        return 178;
    if (cc1_get_body_not_op_count() != 0)
        return 179;
    if (cc1_get_function_name_char_count() != 2)
        return 180;
    if (cc1_get_max_function_name_len() != 1)
        return 181;
    if (cc1_get_function_name_hash() != 3485)
        return 182;
    if (cc1_get_global_name_char_count() != 2)
        return 183;
    if (cc1_get_max_global_name_len() != 1)
        return 184;
    if (cc1_get_global_name_hash() != 3298)
        return 185;
    if (cc1_get_max_function_source_span() != 46)
        return 186;
    if (cc1_get_function_slot_hash(0) != 102)
        return 187;
    if (cc1_get_function_slot_len(0) != 1)
        return 188;
    if (cc1_get_function_slot_hash(1) != 119)
        return 189;
    if (cc1_get_function_slot_len(1) != 1)
        return 190;
    if (cc1_get_global_slot_hash(0) != 97)
        return 191;
    if (cc1_get_global_slot_len(0) != 1)
        return 192;
    if (cc1_get_global_slot_hash(1) != 97)
        return 193;
    if (cc1_get_global_slot_len(1) != 1)
        return 194;
    if (cc1_parse_cc0_source_string(mks("function bad(x){return 1}")) != 0)
        return 160;
    if (cc1_get_error() == 0)
        return 161;
    if (cc1_parse_cc0_source_string(mks("function bad(x){if((x)return 1;}")) != 0)
        return 162;
    if (cc1_get_error() == 0)
        return 163;
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
