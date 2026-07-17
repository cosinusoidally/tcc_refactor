/* Load the production compiler sources directly in SpiderMonkey 45. */
load("prims.js");
load("cc1_libc.c");
load("cc2_boot_storage.c");
load("cc2_backend_stubs.c");
load("cc2.c");

cc1_libc_init();
cc2_init();
if (!cc0_is_name_start(mkC("_")) || cc0_is_name_start(mkC("-"))) {
    throw new Error("cc2 character classification failed");
}
if (CC2_TCC_DOUBLE_TYPE !== 9) {
    throw new Error("cc2 type constants were not initialized");
}
if (exact_log2p1(256) !== 9) {
    throw new Error("cc2 integer helper returned the wrong result");
}
if (!is_float(CC2_TCC_LONG_DOUBLE_TYPE)) {
    throw new Error("cc2 floating type classification failed");
}

print("cc2 JavaScript smoke ok");
