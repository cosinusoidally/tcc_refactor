/* Verify element counts, file bytes, zero counts, and access validation. */
function cc1_libc_fwrite_smoke_path()
{
    return mks("artifacts/cc1_libc_fwrite_smoke.tmp");
}

function main_(argc, argv, stream, buffer, descriptor, result)
{
    cc1_libc_init();
    stream = fopen(cc1_libc_fwrite_smoke_path(), mks("w"));
    if (eq(stream, 0)) {
        return 1;
    }
    buffer = mks("abcdef");
    if (not(eq(fwrite(buffer, 3, 2, stream), 2))) {
        return 2;
    }
    if (not(eq(fwrite(buffer, 3, 0, stream), 0))) {
        return 3;
    }
    if (not(eq(close(cc1_libc_stream_descriptor(stream)), 0))) {
        return 4;
    }
    descriptor = open(cc1_libc_fwrite_smoke_path(), 0, 0);
    if (lt(descriptor, 0)) {
        return 5;
    }
    buffer = malloc(7);
    if (eq(buffer, 0)) {
        return 6;
    }
    result = read(descriptor, buffer, 6);
    if (not(eq(result, 6))) {
        return 7;
    }
    if (not(eq(memcmp(buffer, mks("abcdef"), 6), 0))) {
        return 8;
    }
    close(descriptor);
    stream = fopen(mks("tcc_27_layered_take3/cc1_libc.c"), mks("r"));
    if (eq(stream, 0)) {
        return 9;
    }
    if (not(eq(fwrite(mks("x"), 1, 1, stream), 0))) {
        return 10;
    }
    unlink(cc1_libc_fwrite_smoke_path());
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0, 0);
}
