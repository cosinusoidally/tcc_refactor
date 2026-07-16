/* Verify element reads, EOF, zero counts, and access validation. */
function cc1_libc_fread_smoke_path()
{
    return mks("artifacts/cc1_libc_fread_smoke.tmp");
}

function main_(argc, argv, descriptor, stream, buffer)
{
    cc1_libc_init();
    descriptor = open(cc1_libc_fread_smoke_path(), 577, 438);
    if (lt(descriptor, 0)) {
        return 1;
    }
    if (not(eq(write(descriptor, mks("abcdef"), 6), 6))) {
        return 2;
    }
    close(descriptor);
    stream = fopen(cc1_libc_fread_smoke_path(), mks("r"));
    buffer = malloc(7);
    if (or(eq(stream, 0), eq(buffer, 0))) {
        return 3;
    }
    if (not(eq(fread(buffer, 2, 3, stream), 3))) {
        return 4;
    }
    if (not(eq(memcmp(buffer, mks("abcdef"), 6), 0))) {
        return 5;
    }
    if (not(eq(fread(buffer, 1, 1, stream), 0))) {
        return 6;
    }
    if (not(eq(fread(buffer, 1, 0, stream), 0))) {
        return 7;
    }
    fclose(stream);
    stream = fopen(cc1_libc_fread_smoke_path(), mks("w"));
    if (eq(stream, 0)) {
        return 8;
    }
    if (not(eq(fread(buffer, 1, 1, stream), 0))) {
        return 9;
    }
    fclose(stream);
    unlink(cc1_libc_fread_smoke_path());
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0);
}
