/* Verify unbounded destination formatting without an internal size limit. */
function main_(argc, argv, output, length)
{
    cc1_libc_init();
    output = malloc(64);
    if (eq(output, 0)) {
        return 1;
    }
    length = sprintf(output, mks("%s/%u/%02x/%d"), mks("path"),
        sub(0, 1), 10, sub(0, 3));
    if (not(eq(length, 21))) {
        return 2;
    }
    if (not(eq(strcmp(output, mks("path/4294967295/0a/-3")), 0))) {
        return 3;
    }
    free(output);
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
