/* Verify mode parsing, successful opens, and missing-file failure. */
function main_(argc, argv, stream)
{
    cc1_libc_init();
    stream = fopen(mks("tcc_27_layered_take2/tests/layered/cc1_libc_fopen_smoke.c"),
        mks("rb"));
    if (eq(stream, 0)) {
        return 1;
    }
    if (lt(cc1_libc_stream_descriptor(stream), 0)) {
        return 2;
    }
    if (not(eq(fopen(mks("artifacts/cc1_libc_missing.file"), mks("r")),
        0))) {
        return 3;
    }
    if (not(eq(fopen(mks("artifacts/cc1_libc_invalid.file"), mks("q")),
        0))) {
        return 4;
    }
    if (eq(fopen(mks("artifacts/cc1_libc_fopen.tmp"), mks("w+b")), 0)) {
        return 5;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0);
}
