int add();
int sub();
int not();
int cc0_init();
int cc0_is_decimal_digit();
int cc0_is_octal_digit();
int cc0_is_name_start();
int cc0_is_name_continue();
int cc0_is_space();
int cc0_to_upper();
int cc0_set_idnum();
int cc0_check_space();

int main()
{
    unsigned char character_flags[257] = { 0 };
    int previous_space = 0;

    cc0_init();
    if (add(20, 22) != 42 || sub(50, 8) != 42) {
        return 1;
    }
    if (not(0) != 1 || not(7) != 0) {
        return 2;
    }
    if (!cc0_is_decimal_digit(48) || cc0_is_decimal_digit(65)) {
        return 3;
    }
    if (!cc0_is_octal_digit(55) || cc0_is_octal_digit(56)) {
        return 4;
    }
    if (!cc0_is_name_start(95) || cc0_is_name_start(45)) {
        return 5;
    }
    if (!cc0_is_name_continue(57) || cc0_is_name_continue(45)) {
        return 6;
    }
    if (!cc0_is_space(32) || !cc0_is_space(11) || cc0_is_space(10)) {
        return 7;
    }
    if (cc0_to_upper(97) != 65 || cc0_to_upper(65) != 65) {
        return 8;
    }
    if (cc0_set_idnum((int)character_flags, 32, 1) != 0) {
        return 9;
    }
    if (cc0_set_idnum((int)character_flags, 32, 1) != 1) {
        return 10;
    }
    if (cc0_check_space((int)character_flags, 32, (int)&previous_space) != 0 ||
        previous_space != 1) {
        return 11;
    }
    if (cc0_check_space((int)character_flags, 32, (int)&previous_space) != 1) {
        return 12;
    }
    if (cc0_check_space((int)character_flags, 65, (int)&previous_space) != 0 ||
        previous_space != 0) {
        return 13;
    }
    return 0;
}
