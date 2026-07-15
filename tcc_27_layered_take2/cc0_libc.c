/* Small environment-neutral libc surface shared by static and dynamic links. */
var CC0_LIBC_STANDARD_OUTPUT;
var CC0_LIBC_NEWLINE;
var CC0_LIBC_NEWLINE_BYTES;

function cc0_libc_init()
{
    CC0_LIBC_STANDARD_OUTPUT = 1;
    CC0_LIBC_NEWLINE = mks("\n");
    CC0_LIBC_NEWLINE_BYTES = 1;
}

function cc0_libc_string_length_(text, length)
{
    length = 0;
    while (not(eq(ri8(add(text, length)), 0))) {
        length = add(length, 1);
    }
    return length;
}

function cc0_libc_string_length(text)
{
    return cc0_libc_string_length_(text, 0);
}

function puts(text)
{
    var result;

    cc0_libc_init();
    result = cc0_runtime_write(CC0_LIBC_STANDARD_OUTPUT, text,
        cc0_libc_string_length(text));
    if (lt(result, 0)) {
        return sub(0, 1);
    }
    result = cc0_runtime_write(CC0_LIBC_STANDARD_OUTPUT,
        CC0_LIBC_NEWLINE, CC0_LIBC_NEWLINE_BYTES);
    if (lt(result, 0)) {
        return sub(0, 1);
    }
    return 0;
}
