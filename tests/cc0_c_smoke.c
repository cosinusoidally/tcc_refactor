int cc0_add();
int cc0_select();
int cc0_not();
int cc0_is_digit();
int cc0_is_name_start();
int cc0_is_name_continue();
int cc0_is_space();
int cc0_token_class();
int cc0_source_set8();
int cc0_scan_next();
int cc0_get_tok_class();
int cc0_get_tok_start();
int cc0_get_tok_len();
int cc1_compile_unit();
int cc1_has_real_parser();

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
    if (!cc0_is_space(32) || !cc0_is_space(10) || cc0_is_space(65))
        return 8;
    if (cc0_token_class(-1) != 0)
        return 9;
    if (cc0_token_class(65) != 1)
        return 10;
    if (cc0_token_class(52) != 2)
        return 11;
    if (cc0_token_class(32) != 3)
        return 12;
    if (cc0_token_class(43) != 4)
        return 13;
    cc0_source_set8(32, 97, 98, 49, 32, 50, 51, -1);
    if (cc0_scan_next() != 1)
        return 14;
    if (cc0_get_tok_class() != 1)
        return 15;
    if (cc0_get_tok_start() != 1 || cc0_get_tok_len() != 3)
        return 16;
    if (cc0_scan_next() != 2)
        return 17;
    if (cc0_get_tok_start() != 5 || cc0_get_tok_len() != 2)
        return 18;
    if (cc0_scan_next() != 0)
        return 19;
    if (cc1_compile_unit(0) != 1)
        return 20;
    if (cc1_has_real_parser() != 0)
        return 21;
    return 0;
}
