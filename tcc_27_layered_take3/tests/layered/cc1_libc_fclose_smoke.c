/* Verify close status, descriptor release, and persisted output. */
function cc1_libc_fclose_smoke_path()
{
    return mks("artifacts/cc1_libc_fclose_smoke.tmp");
}

function main_(argc, argv, stream, descriptor, buffer)
{
    cc1_libc_init();
    stream = fopen(cc1_libc_fclose_smoke_path(), mks("w"));
    if (eq(stream, 0)) {
        return 1;
    }
    descriptor = cc1_libc_stream_descriptor(stream);
    if (not(eq(fwrite(mks("closed"), 1, 6, stream), 6))) {
        return 2;
    }
    if (not(eq(fclose(stream), 0))) {
        return 3;
    }
    if (not(lt(close(descriptor), 0))) {
        return 4;
    }
    descriptor = open(cc1_libc_fclose_smoke_path(), 0, 0);
    buffer = malloc(6);
    if (or(lt(descriptor, 0), eq(buffer, 0))) {
        return 5;
    }
    if (not(eq(read(descriptor, buffer, 6), 6))) {
        return 6;
    }
    if (not(eq(memcmp(buffer, mks("closed"), 6), 0))) {
        return 7;
    }
    close(descriptor);
    unlink(cc1_libc_fclose_smoke_path());
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0);
}
