/* Verify logical positions after writes, seeks, and cached reads. */
function cc1_libc_ftell_smoke_path()
{
    return mks("artifacts/cc1_libc_ftell_smoke.tmp");
}

function main_(argc, argv, stream, buffer)
{
    cc1_libc_init();
    stream = fopen(cc1_libc_ftell_smoke_path(), mks("w+"));
    if (eq(stream, 0)) {
        return 1;
    }
    if (not(eq(ftell(stream), 0))) {
        return 2;
    }
    if (not(eq(fwrite(mks("abcdef"), 1, 6, stream), 6))) {
        return 3;
    }
    if (not(eq(ftell(stream), 6))) {
        return 4;
    }
    if (not(eq(fseek(stream, 1, 0), 0))) {
        return 5;
    }
    if (not(eq(ftell(stream), 1))) {
        return 6;
    }
    buffer = malloc(2);
    if (eq(buffer, 0)) {
        return 7;
    }
    if (not(eq(fread(buffer, 1, 2, stream), 2))) {
        return 8;
    }
    if (not(eq(ftell(stream), 3))) {
        return 9;
    }
    fclose(stream);
    unlink(cc1_libc_ftell_smoke_path());
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
