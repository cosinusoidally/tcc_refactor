load("../tcc_27_layered_take3/prims.js");
load("../tcc_27_layered_take3/cc1_libc.c");
load("../tcc_27_layered_take3/cc2_boot_storage.c");
load("../tcc_27_layered_take3/cc2_backend_stubs.c");
load("../tcc_27_layered_take3/cc2.c");
cc1_libc_init();

function runCc2(argumentList) {
    var argv = malloc(argumentList.length * 4);
    var index = 0;
    while (index < argumentList.length) {
        wi32(argv + index * 4, mks(argumentList[index]));
        index++;
    }
    return main(argumentList.length, argv);
}

function requireCc2(argumentList, description) {
    if (runCc2(argumentList) !== 0) {
        throw new Error("JavaScript cc2 could not " + description);
    }
}

requireCc2(["cc2", "-nostdinc", "-c",
    "../tcc_27_layered_take3/linux_i386_start.c", "-o",
    "cc2_js_linux_i386_start.o"], "compile process stack access");
requireCc2(["cc2", "-nostdinc", "-c",
    "../tcc_27_layered_take3/cc2_start.c", "-o", "cc2_js_start.o"],
    "compile dynamic startup");
requireCc2(["cc2", "-nostdinc", "-c",
    "../tcc_27_layered_take3/prims.c", "-o", "cc2_js_prims.o"],
    "compile native primitives");
requireCc2(["cc2", "-nostdinc", "-Dfunction=int", "-Dvar=int", "-c",
    "../tcc_27_layered_take3/cc2.c", "-o", "cc2_js.o"],
    "compile cc2.c");
requireCc2(["cc2", "-nostdinc", "-c",
    "../tcc_27_layered_take3/cc2_runtime.c", "-o",
    "cc2_js_runtime.o"], "compile the typed runtime");
requireCc2(["cc2", "-nostdinc", "-I",
    "../../tcc_bootstrap_alt/woody/usr/include", "-I",
    "../tcc_27_layered_take3/include", "-I",
    "../tcc_27_layered_take3", "-U__linux__", "-c",
    "../tcc_27_layered_take3/tcc_unified.c", "-o",
    "cc2_js_tcc_rest.o"], "compile the typed TCC bridge");
requireCc2(["cc2", "-nostdlib", "cc2_js_linux_i386_start.o",
    "cc2_js_start.o", "cc2_js_prims.o", "cc2_js.o",
    "cc2_js_tcc_rest.o", "cc2_js_runtime.o", "cc2_js_libc.so",
    "cc2_js_libm.so", "-o", "cc2_js_seed.exe"],
    "link the standalone cc2 seed");
