/* Verify that cc1 exposes the unnamed i386 arguments through address-of. */
function cc1_libc_fprintf_smoke_path()
{
    return mks("artifacts/cc1_libc_fprintf_smoke.tmp");
}

function main_(argc, argv, stream, buffer, length)
{
    cc1_libc_init();
    stream = fopen(cc1_libc_fprintf_smoke_path(), mks("w+"));
    if (eq(stream, 0)) {
        return 1;
    }
    if (not(eq(fprintf(stream, mks("%s:%02x:%d"), mks("value"), 10,
        sub(0, 3)), 11))) {
        return 2;
    }
    if (not(eq(fseek(stream, 0, 0), 0))) {
        return 3;
    }
    buffer = malloc(12);
    if (eq(buffer, 0)) {
        return 4;
    }
    length = fread(buffer, 1, 11, stream);
    wi8(add(buffer, length), 0);
    if (or(not(eq(length, 11)),
        not(eq(strcmp(buffer, mks("value:0a:-3")), 0)))) {
        return 5;
    }
    free(buffer);
    fclose(stream);
    unlink(cc1_libc_fprintf_smoke_path());
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0);
}
