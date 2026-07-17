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
    "../tcc_27_layered_take3/cc2_static_start.c", "-o",
    "cc2_js_static_start.o"], "compile static startup");
requireCc2(["cc2", "-nostdinc", "-Dfunction=int", "-Dvar=int", "-c",
    "../tcc_27_layered_take3/linux_i386_syscalls.c", "-o",
    "cc2_js_syscalls.o"], "compile the i386 syscall entry");
requireCc2(["cc2", "-nostdinc", "-Dfunction=int", "-Dvar=int", "-c",
    "../tcc_27_layered_take3/cc0_static_syscalls.c", "-o",
    "cc2_js_static_syscalls.o"], "compile static syscall wrappers");
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
requireCc2(["cc2", "-nostdinc", "-Dfunction=int", "-Dvar=int", "-c",
    "../tcc_27_layered_take3/cc1_libc.c", "-o",
    "cc2_js_libc.o"], "compile the shared libc");
requireCc2(["cc2", "-nostdinc", "-Dfunction=int", "-Dvar=int", "-c",
    "../tcc_27_layered_take3/cc1_libc_asm.c", "-o",
    "cc2_js_libc_asm.o"], "compile libc stack primitives");
requireCc2(["cc2", "-nostdinc", "-c",
    "../tcc_27_layered_take3/cc2_libc.c", "-o",
    "cc2_js_float_libc.o"], "compile typed float conversion");
requireCc2(["cc2", "-nostdlib", "-static",
    "cc2_js_linux_i386_start.o", "cc2_js_static_start.o",
    "cc2_js_syscalls.o", "cc2_js_static_syscalls.o",
    "cc2_js_prims.o", "cc2_js.o", "cc2_js_tcc_rest.o",
    "cc2_js_runtime.o", "cc2_js_libc.o", "cc2_js_libc_asm.o",
    "cc2_js_float_libc.o", "-o", "cc2_js_static_seed.exe"],
    "link the standalone static cc2 seed");
