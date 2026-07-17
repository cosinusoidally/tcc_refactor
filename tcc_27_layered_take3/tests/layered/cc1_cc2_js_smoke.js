/* Load the production shared sources directly in SpiderMonkey 45. */
load("prims.js");
load("cc1_libc.c");
load("cc1.c");
cc1_libc_init();

cc0_init();
if (!cc0_is_name_start(mkC("_")) || cc0_is_name_start(mkC("-"))) {
    throw new Error("cc1 character classification failed");
}

load("cc2.c");
cc2_init();
if (CC2_TCC_DOUBLE_TYPE !== 9) {
    throw new Error("cc2 type constants were not initialized");
}
if (exact_log2p1(256) !== 9) {
    throw new Error("cc2 integer helper returned the wrong result");
}
if (!is_float(CC2_TCC_LONG_DOUBLE_TYPE)) {
    throw new Error("cc2 floating type classification failed");
}

print("cc1/cc2 JavaScript smoke ok");
