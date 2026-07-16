/* Verify byte truncation, return value, persisted order, and access errors. */
function cc1_libc_fputc_smoke_path()
{
    return mks("artifacts/cc1_libc_fputc_smoke.tmp");
}

function main_(argc, argv, stream, descriptor, buffer)
{
    cc1_libc_init();
    stream = fopen(cc1_libc_fputc_smoke_path(), mks("w"));
    if (eq(stream, 0)) {
        return 1;
    }
    if (not(eq(fputc(add(256, mkC("A")), stream), mkC("A")))) {
        return 2;
    }
    if (not(eq(fputc(mkC("B"), stream), mkC("B")))) {
        return 3;
    }
    close(cc1_libc_stream_descriptor(stream));
    descriptor = open(cc1_libc_fputc_smoke_path(), 0, 0);
    buffer = malloc(2);
    if (or(lt(descriptor, 0), eq(buffer, 0))) {
        return 4;
    }
    if (not(eq(read(descriptor, buffer, 2), 2))) {
        return 5;
    }
    if (not(eq(memcmp(buffer, mks("AB"), 2), 0))) {
        return 6;
    }
    close(descriptor);
    stream = fopen(mks("tcc_27_layered_take2/cc1_libc.c"), mks("r"));
    if (eq(stream, 0)) {
        return 7;
    }
    if (not(lt(fputc(mkC("x"), stream), 0))) {
        return 8;
    }
    unlink(cc1_libc_fputc_smoke_path());
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0);
}
