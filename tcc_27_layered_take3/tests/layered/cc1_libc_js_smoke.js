load("../tcc_27_layered_take3/prims.js");
load("../tcc_27_layered_take3/cc1_libc.c");

if (typeof cc1_libc_init !== "function" ||
    typeof malloc !== "function" ||
    typeof vsnprintf !== "function") {
    throw new Error("cc1_libc.c did not define its shared libc surface");
}
