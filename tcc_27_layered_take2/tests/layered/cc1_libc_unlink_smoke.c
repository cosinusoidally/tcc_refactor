/* Verify successful removal and failure for an already absent path. */
function cc1_libc_unlink_smoke_path()
{
    return mks("artifacts/cc1_libc_unlink_smoke.tmp");
}

function cc1_libc_unlink_smoke_create_flags()
{
    return 577;
}

function cc1_libc_unlink_smoke_create_mode()
{
    return 438;
}

function main_(argc, argv, descriptor)
{
    unlink(cc1_libc_unlink_smoke_path());
    descriptor = open(cc1_libc_unlink_smoke_path(),
        cc1_libc_unlink_smoke_create_flags(),
        cc1_libc_unlink_smoke_create_mode());
    if (lt(descriptor, 0)) {
        return 1;
    }
    if (not(eq(close(descriptor), 0))) {
        return 2;
    }
    if (not(eq(unlink(cc1_libc_unlink_smoke_path()), 0))) {
        return 3;
    }
    descriptor = open(cc1_libc_unlink_smoke_path(), 0, 0);
    if (not(lt(descriptor, 0))) {
        close(descriptor);
        return 4;
    }
    if (not(lt(unlink(cc1_libc_unlink_smoke_path()), 0))) {
        return 5;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0);
}
