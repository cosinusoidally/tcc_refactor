load("../tcc_27_layered/cc0.c");

if (cc0_add(2, 3) !== 5)
    throw new Error("cc0_add failed");

if (cc0_select(1, 7, 9) !== 7)
    throw new Error("cc0_select true branch failed");

if (cc0_select(0, 7, 9) !== 9)
    throw new Error("cc0_select false branch failed");

if (cc0_not(0) !== 1 || cc0_not(4) !== 0)
    throw new Error("cc0_not failed");
