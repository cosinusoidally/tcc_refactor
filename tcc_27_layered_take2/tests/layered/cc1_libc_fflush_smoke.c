/* Verify stream and all-stream flushes expose data before close. */
function cc1_libc_fflush_smoke_path()
{
    return mks("artifacts/cc1_libc_fflush_smoke.tmp");
}

function main_(argc, argv, stream, descriptor, buffer)
{
    cc1_libc_init();
    stream = fopen(cc1_libc_fflush_smoke_path(), mks("w"));
    if (eq(stream, 0)) {
        return 1;
    }
    if (not(eq(fwrite(mks("flush"), 1, 5, stream), 5))) {
        return 2;
    }
    if (not(eq(fflush(stream), 0))) {
        return 3;
    }
    descriptor = open(cc1_libc_fflush_smoke_path(), 0, 0);
    buffer = malloc(5);
    if (or(lt(descriptor, 0), eq(buffer, 0))) {
        return 4;
    }
    if (not(eq(read(descriptor, buffer, 5), 5))) {
        return 5;
    }
    if (not(eq(memcmp(buffer, mks("flush"), 5), 0))) {
        return 6;
    }
    close(descriptor);
    if (not(eq(fflush(0), 0))) {
        return 7;
    }
    if (not(eq(fclose(stream), 0))) {
        return 8;
    }
    unlink(cc1_libc_fflush_smoke_path());
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0);
}
