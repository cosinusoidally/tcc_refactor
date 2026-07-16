load("../tcc_27_layered_take3/prims.js");
load("../tcc_27_layered_take3/cc0.c");

cc0_init();
if (add(20, 22) !== 42 || sub(50, 8) !== 42) {
    throw new Error("cc0 arithmetic primitives failed");
}
if (not(0) !== 1 || not(7) !== 0) {
    throw new Error("cc0 boolean primitive failed");
}
if (!cc0_is_decimal_digit(48) || cc0_is_decimal_digit(65)) {
    throw new Error("cc0 decimal classification failed");
}
if (!cc0_is_octal_digit(55) || cc0_is_octal_digit(56)) {
    throw new Error("cc0 octal classification failed");
}
if (!cc0_is_name_start(95) || cc0_is_name_start(45)) {
    throw new Error("cc0 name-start classification failed");
}
if (!cc0_is_name_continue(57) || cc0_is_name_continue(45)) {
    throw new Error("cc0 name classification failed");
}
if (!cc0_is_space(32) || !cc0_is_space(11) || cc0_is_space(10)) {
    throw new Error("cc0 space classification failed");
}
if (cc0_to_upper(97) !== 65 || cc0_to_upper(65) !== 65) {
    throw new Error("cc0 uppercase conversion failed");
}

var characterFlags = 1024;
var previousSpace = 2048;
if (cc0_set_idnum(characterFlags, 32, 1) !== 0) {
    throw new Error("cc0 character flag initial value failed");
}
if (cc0_set_idnum(characterFlags, 32, 1) !== 1) {
    throw new Error("cc0 character flag replacement failed");
}
wi32(previousSpace, 0);
if (cc0_check_space(characterFlags, 32, previousSpace) !== 0 ||
    ri32(previousSpace) !== 1) {
    throw new Error("cc0 first space state failed");
}
if (cc0_check_space(characterFlags, 32, previousSpace) !== 1) {
    throw new Error("cc0 repeated space state failed");
}
if (cc0_check_space(characterFlags, 65, previousSpace) !== 0 ||
    ri32(previousSpace) !== 0) {
    throw new Error("cc0 non-space reset failed");
}
