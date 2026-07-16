load("../tcc_27_layered_take3/prims.js");
load("../tcc_27_layered_take3/cc0.c");
load("../tcc_27_layered_take3/cc1_stubs.c");

function runCc0(arguments) {
    var argv = malloc(arguments.length * 4);
    var index = 0;
    while (index < arguments.length) {
        wi32(argv + index * 4, mks(arguments[index]));
        index++;
    }
    return main(arguments.length, argv);
}

if (runCc0(["cc0", "-c", "../tcc_27_layered_take3/cc0.c",
            "-o", "cc0_js.o"]) !== 0) {
    throw new Error("JavaScript cc0 could not compile cc0.c");
}
if (runCc0(["cc0", "-c", "../tcc_27_layered_take3/cc1_stubs.c",
            "-o", "cc1_stubs_js.o"]) !== 0) {
    throw new Error("JavaScript cc0 could not compile cc1_stubs.c");
}
if (runCc0(["cc0", "-c",
            "../tcc_27_layered_take3/linux_i386_syscalls.c",
            "-o", "linux_i386_syscalls_js.o"]) !== 0) {
    throw new Error("JavaScript cc0 could not compile the syscall entry");
}
if (runCc0(["cc0", "-c",
            "../tcc_27_layered_take3/cc0_static_syscalls.c",
            "-o", "cc0_static_syscalls_js.o"]) !== 0) {
    throw new Error("JavaScript cc0 could not compile static syscalls");
}
if (runCc0(["cc0", "-c", "../tcc_27_layered_take3/cc0_static_start.c",
            "-o", "cc0_static_start_js.o"]) !== 0) {
    throw new Error("JavaScript cc0 could not compile static startup");
}
if (runCc0(["cc0", "-c", "../tcc_27_layered_take3/cc0_libc.c",
            "-o", "cc0_libc_js.o"]) !== 0) {
    throw new Error("JavaScript cc0 could not compile static libc");
}
if (runCc0(["cc0", "cc0_static_start_js.o",
            "linux_i386_syscalls_js.o", "cc0_static_syscalls_js.o",
            "cc0_js.o", "cc1_stubs_js.o", "cc0_libc_js.o",
            "-o", "cc0_static_js.exe"]) !== 0) {
    throw new Error("JavaScript cc0 could not link static cc0");
}
if (runCc0(["cc0", "cc0_js.o", "cc1_stubs_js.o",
            "-o", "cc0_js.exe"]) !== 0) {
    throw new Error("JavaScript cc0 could not link cc0.exe");
}
