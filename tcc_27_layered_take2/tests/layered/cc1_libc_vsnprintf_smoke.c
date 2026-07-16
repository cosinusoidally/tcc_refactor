/* Exercise i386 va_list traversal, formatting, padding, and truncation. */
function main_(argc, argv, arguments, output, length)
{
    cc1_libc_init();
    arguments = malloc(32);
    output = malloc(64);
    if (or(eq(arguments, 0), eq(output, 0))) {
        return 1;
    }
    wi32(arguments, mks("ok"));
    wi32(add(arguments, 4), mkC("A"));
    wi32(add(arguments, 8), sub(0, 12));
    wi32(add(arguments, 12), sub(0, 1));
    wi32(add(arguments, 16), 10);
    wi32(add(arguments, 20), mks("xy"));
    wi32(add(arguments, 24), 3);
    wi32(add(arguments, 28), mks("abcdef"));
    length = vsnprintf(output, 64,
        mks("[%s] %c %d %u %02x %-6s %.*s %%"), arguments);
    if (not(eq(length, strlen(mks("[ok] A -12 4294967295 0a xy     abc %"))))) {
        return 2;
    }
    if (not(eq(strcmp(output,
        mks("[ok] A -12 4294967295 0a xy     abc %")), 0))) {
        return 3;
    }
    length = vsnprintf(output, 6,
        mks("[%s] %c %d %u %02x %-6s %.*s %%"), arguments);
    if (not(eq(length, strlen(mks("[ok] A -12 4294967295 0a xy     abc %"))))) {
        return 4;
    }
    if (not(eq(strcmp(output, mks("[ok] ")), 0))) {
        return 5;
    }
    free(output);
    free(arguments);
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0);
}
