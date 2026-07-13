load("../tcc_27_layered_take2/prims.js");
load("../tcc_27_layered_take2/cc0.c");
load("../tcc_27_layered_take2/cc1_stubs.c");

function runCc0(arguments) {
    var argv = malloc(arguments.length * 4);
    var index = 0;
    while (index < arguments.length) {
        wi32(argv + index * 4, mks(arguments[index]));
        index++;
    }
    return main(arguments.length, argv);
}

if (runCc0(["cc0", "-c", "../tcc_27_layered_take2/cc0.c",
            "-o", "cc0_js.o"]) !== 0) {
    throw new Error("JavaScript cc0 could not compile cc0.c");
}
if (runCc0(["cc0", "-c", "../tcc_27_layered_take2/cc1_stubs.c",
            "-o", "cc1_stubs_js.o"]) !== 0) {
    throw new Error("JavaScript cc0 could not compile cc1_stubs.c");
}
if (runCc0(["cc0", "cc0_js.o", "cc1_stubs_js.o",
            "-o", "cc0_js.exe"]) !== 0) {
    throw new Error("JavaScript cc0 could not link cc0.exe");
}
