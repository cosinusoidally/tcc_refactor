/* Verify complete strings, empty strings, persisted bytes, and access errors. */
function cc1_libc_fputs_smoke_path()
{
    return mks("artifacts/cc1_libc_fputs_smoke.tmp");
}

function main_(argc, argv, stream, descriptor, buffer)
{
    cc1_libc_init();
    stream = fopen(cc1_libc_fputs_smoke_path(), mks("w"));
    if (eq(stream, 0)) {
        return 1;
    }
    if (lt(fputs(mks("text"), stream), 0)) {
        return 2;
    }
    if (lt(fputs(mks(""), stream), 0)) {
        return 3;
    }
    if (not(eq(fclose(stream), 0))) {
        return 4;
    }
    descriptor = open(cc1_libc_fputs_smoke_path(), 0, 0);
    buffer = malloc(4);
    if (or(lt(descriptor, 0), eq(buffer, 0))) {
        return 5;
    }
    if (not(eq(read(descriptor, buffer, 4), 4))) {
        return 6;
    }
    if (not(eq(memcmp(buffer, mks("text"), 4), 0))) {
        return 7;
    }
    close(descriptor);
    stream = fopen(cc1_libc_fputs_smoke_path(), mks("r"));
    if (eq(stream, 0)) {
        return 8;
    }
    if (not(lt(fputs(mks("x"), stream), 0))) {
        return 9;
    }
    fclose(stream);
    unlink(cc1_libc_fputs_smoke_path());
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0);
}
