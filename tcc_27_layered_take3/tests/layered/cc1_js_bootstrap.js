load("../tcc_27_layered_take3/prims.js");
load("../tcc_27_layered_take3/cc1.c");
load("../tcc_27_layered_take3/cc2_stubs.c");

function runCc1(arguments) {
    var argv = malloc(arguments.length * 4);
    var index = 0;
    while (index < arguments.length) {
        wi32(argv + index * 4, mks(arguments[index]));
        index++;
    }
    return main(arguments.length, argv);
}

if (runCc1(["cc1", "-c", "../tcc_27_layered_take3/cc1.c",
            "-o", "cc1_js.o"]) !== 0) {
    throw new Error("JavaScript cc1 could not compile cc1.c");
}
if (runCc1(["cc1", "-c", "../tcc_27_layered_take3/cc2_stubs.c",
            "-o", "cc2_stubs_js.o"]) !== 0) {
    throw new Error("JavaScript cc1 could not compile cc2_stubs.c");
}
if (runCc1(["cc1", "-c",
            "../tcc_27_layered_take3/linux_i386_syscalls.c",
            "-o", "linux_i386_syscalls_js.o"]) !== 0) {
    throw new Error("JavaScript cc1 could not compile the syscall entry");
}
if (runCc1(["cc1", "-c",
            "../tcc_27_layered_take3/cc0_static_syscalls.c",
            "-o", "cc0_static_syscalls_js.o"]) !== 0) {
    throw new Error("JavaScript cc1 could not compile static syscalls");
}
if (runCc1(["cc1", "-c", "../tcc_27_layered_take3/cc0_static_start.c",
            "-o", "cc0_static_start_js.o"]) !== 0) {
    throw new Error("JavaScript cc1 could not compile static startup");
}
if (runCc1(["cc1", "-c", "../tcc_27_layered_take3/cc0_libc.c",
            "-o", "cc0_libc_js.o"]) !== 0) {
    throw new Error("JavaScript cc1 could not compile static libc");
}
if (runCc1(["cc1", "cc0_static_start_js.o",
            "linux_i386_syscalls_js.o", "cc0_static_syscalls_js.o",
            "cc1_js.o", "cc2_stubs_js.o", "cc0_libc_js.o",
            "-o", "cc1_static_js.exe"]) !== 0) {
    throw new Error("JavaScript cc1 could not link static cc1");
}
if (runCc1(["cc1", "cc1_js.o", "cc2_stubs_js.o",
            "-o", "cc1_js.exe"]) !== 0) {
    throw new Error("JavaScript cc1 could not link cc1.exe");
}
