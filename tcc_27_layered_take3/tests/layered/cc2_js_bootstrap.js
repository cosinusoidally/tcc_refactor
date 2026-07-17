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

function elfRead16(data, offset) {
    return data[offset] | data[offset + 1] << 8;
}

function elfRead32(data, offset) {
    return (data[offset] | data[offset + 1] << 8 |
        data[offset + 2] << 16 | data[offset + 3] << 24) >>> 0;
}

function elfString(data, offset) {
    var result = "";
    while (data[offset] !== 0) {
        result += String.fromCharCode(data[offset]);
        offset++;
    }
    return result;
}

/* TCC-generated DSOs export linker boundary symbols absent from glibc. */
function localizeGeneratedDsoSymbols(path) {
    var elfHeaderSectionTableOffset = 32;
    var elfHeaderSectionCountOffset = 48;
    var elfSectionHeaderBytes = 40;
    var elfSectionTypeOffset = 4;
    var elfSectionFileOffsetOffset = 16;
    var elfSectionSizeOffset = 20;
    var elfSectionLinkOffset = 24;
    var elfDynamicSymbolSectionType = 11;
    var elfSymbolBytes = 16;
    var elfSymbolInfoOffset = 12;
    var elfSymbolTypeMask = 15;
    var generated = {
        "_etext": 1,
        "_edata": 1,
        "_end": 1,
        "__preinit_array_start": 1,
        "__preinit_array_end": 1,
        "__init_array_start": 1,
        "__init_array_end": 1,
        "__fini_array_start": 1,
        "__fini_array_end": 1,
        "_GLOBAL_OFFSET_TABLE_": 1
    };
    var data = os.file.readFile(path, "binary");
    var sectionOffset = elfRead32(data, elfHeaderSectionTableOffset);
    var sectionCount = elfRead16(data, elfHeaderSectionCountOffset);
    var dynamicSymbols = 0;
    var index = 0;
    var section;
    var strings;
    var symbol;
    var symbolEnd;
    var name;

    while (index < sectionCount) {
        section = sectionOffset + index * elfSectionHeaderBytes;
        if (elfRead32(data, section + elfSectionTypeOffset) ===
            elfDynamicSymbolSectionType) {
            dynamicSymbols = section;
        }
        index++;
    }
    if (dynamicSymbols === 0) {
        throw new Error("generated import library has no dynamic symbols");
    }
    section = sectionOffset +
        elfRead32(data, dynamicSymbols + elfSectionLinkOffset) *
        elfSectionHeaderBytes;
    strings = elfRead32(data, section + elfSectionFileOffsetOffset);
    symbol = elfRead32(data,
        dynamicSymbols + elfSectionFileOffsetOffset);
    symbolEnd = symbol + elfRead32(data,
        dynamicSymbols + elfSectionSizeOffset);
    while (symbol < symbolEnd) {
        name = elfString(data, strings + elfRead32(data, symbol));
        if (generated[name] === 1) {
            data[symbol + elfSymbolInfoOffset] &= elfSymbolTypeMask;
        }
        symbol += elfSymbolBytes;
    }
    os.file.writeTypedArrayToFile(path, data);
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
requireCc2(["cc2", "-nostdinc", "-c",
    "../tcc_27_layered_take3/cc2_dynamic_libc_imports.c", "-o",
    "cc2_js_dynamic_libc_imports.o"], "compile libc import metadata");
requireCc2(["cc2", "-nostdlib", "-shared", "-soname", "libc.so.6",
    "cc2_js_dynamic_libc_imports.o", "-o", "cc2_js_dynamic_libc.so"],
    "link libc import metadata");
requireCc2(["cc2", "-nostdinc", "-c",
    "../tcc_27_layered_take3/cc2_dynamic_libm_imports.c", "-o",
    "cc2_js_dynamic_libm_imports.o"], "compile libm import metadata");
requireCc2(["cc2", "-nostdlib", "-shared", "-soname", "libm.so.6",
    "cc2_js_dynamic_libm_imports.o", "-o", "cc2_js_dynamic_libm.so"],
    "link libm import metadata");
localizeGeneratedDsoSymbols("cc2_js_dynamic_libc.so");
localizeGeneratedDsoSymbols("cc2_js_dynamic_libm.so");
requireCc2(["cc2", "-nostdlib", "-static",
    "cc2_js_linux_i386_start.o", "cc2_js_static_start.o",
    "cc2_js_syscalls.o", "cc2_js_static_syscalls.o",
    "cc2_js_prims.o", "cc2_js.o", "cc2_js_tcc_rest.o",
    "cc2_js_runtime.o", "cc2_js_libc.o", "cc2_js_libc_asm.o",
    "cc2_js_float_libc.o", "-o", "cc2_js_static_seed.exe"],
    "link the standalone static cc2 seed");
