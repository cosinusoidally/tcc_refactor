/* Verify update-stream positioning, overwrite behavior, and EOF recovery. */
function cc1_libc_fseek_smoke_path()
{
    return mks("artifacts/cc1_libc_fseek_smoke.tmp");
}

function main_(argc, argv, stream, buffer)
{
    cc1_libc_init();
    stream = fopen(cc1_libc_fseek_smoke_path(), mks("w+"));
    if (eq(stream, 0)) {
        return 1;
    }
    if (not(eq(fwrite(mks("abcdef"), 1, 6, stream), 6))) {
        return 2;
    }
    if (not(eq(fseek(stream, 2, 0), 0))) {
        return 3;
    }
    if (not(eq(fwrite(mks("X"), 1, 1, stream), 1))) {
        return 4;
    }
    if (not(eq(fseek(stream, 0, 0), 0))) {
        return 5;
    }
    buffer = malloc(6);
    if (eq(buffer, 0)) {
        return 6;
    }
    if (not(eq(fread(buffer, 1, 6, stream), 6))) {
        return 7;
    }
    if (not(eq(memcmp(buffer, mks("abXdef"), 6), 0))) {
        return 8;
    }
    if (not(eq(fread(buffer, 1, 1, stream), 0))) {
        return 9;
    }
    if (not(eq(fseek(stream, sub(0, 1), 2), 0))) {
        return 10;
    }
    if (not(eq(fread(buffer, 1, 1, stream), 1))) {
        return 11;
    }
    if (not(eq(ri8(buffer), mkC("f")))) {
        return 12;
    }
    fclose(stream);
    unlink(cc1_libc_fseek_smoke_path());
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
