/* Load the production shared sources directly in SpiderMonkey 45. */
load("prims.js");
load("cc0.c");
load("cc1.c");

cc1_expression_init();
if (CC1_EXPRESSION_CONDITIONAL_KIND !== 25) {
    throw new Error("cc1 expression constants were not initialized");
}
if (cc1_expression_new(CC1_EXPRESSION_ATOM_KIND, 7, 0, 0) === 0) {
    throw new Error("cc1 could not allocate an expression record");
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
