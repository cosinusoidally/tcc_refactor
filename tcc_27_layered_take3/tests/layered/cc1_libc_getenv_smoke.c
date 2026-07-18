/* Verify exact environment-name matching and returned value storage. */
function main_(argc, argv, value)
{
    cc0_libc_set_environment_from_arguments(argc, argv);
    value = getenv(mks("CC1_LIBC_SMOKE_VALUE"));
    if (eq(value, 0)) {
        return 1;
    }
    if (not(eq(strlen(value), 7))) {
        return 2;
    }
    if (not(eq(ri8(value), mkC("l")))) {
        return 3;
    }
    if (not(eq(ri8(add(value, 6)), mkC("d")))) {
        return 4;
    }
    if (not(eq(getenv(mks("CC1_LIBC_SMOKE")), 0))) {
        return 5;
    }
    if (not(eq(getenv(mks("CC1_LIBC_SMOKE_VALUE=")), 0))) {
        return 6;
    }
    if (not(eq(getenv(mks("CC1_LIBC_MISSING")), 0))) {
        return 7;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0);
}
