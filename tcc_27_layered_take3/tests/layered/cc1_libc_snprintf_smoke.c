/* Verify bounded formatting through cc1's variadic argument address. */
function main_(argc, argv, output, length)
{
    cc1_libc_init();
    output = malloc(8);
    if (eq(output, 0)) {
        return 1;
    }
    length = snprintf(output, 8, mks("%s-%02x-%d"), mks("abcdef"), 10,
        sub(0, 3));
    if (not(eq(length, 12))) {
        return 2;
    }
    if (not(eq(strcmp(output, mks("abcdef-")), 0))) {
        return 3;
    }
    free(output);
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
