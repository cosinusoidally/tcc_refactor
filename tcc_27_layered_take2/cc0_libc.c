/* Small environment-neutral libc surface shared by static and dynamic links. */
function cc0_libc_standard_output()
{
    return 1;
}

function cc0_libc_standard_error()
{
    return 2;
}

function cc0_libc_newline()
{
    return mks("\n");
}

function cc0_libc_newline_bytes()
{
    return 1;
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

    result = cc0_runtime_write(cc0_libc_standard_output(), text,
        cc0_libc_string_length(text));
    if (lt(result, 0)) {
        return sub(0, 1);
    }
    result = cc0_runtime_write(cc0_libc_standard_output(),
        cc0_libc_newline(), cc0_libc_newline_bytes());
    if (lt(result, 0)) {
        return sub(0, 1);
    }
    return 0;
}

/* Keep missing services loud until their environment-neutral versions land. */
function cc0_libc_unimplemented(name)
{
    cc0_runtime_write(cc0_libc_standard_error(), name,
        cc0_libc_string_length(name));
    cc0_runtime_write(cc0_libc_standard_error(),
        mks(" is unimplemented\n"),
        cc0_libc_string_length(mks(" is unimplemented\n")));
    exit(1);
    return 0;
}

function exit(status)
{
    cc0_runtime_exit(status);
    return 0;
}

function malloc(size)
{
    return cc0_libc_unimplemented(mks("malloc"));
}

function realloc(address, size)
{
    return cc0_libc_unimplemented(mks("realloc"));
}

function open(path, flags, mode)
{
    return cc0_libc_unimplemented(mks("open"));
}

function read(descriptor, buffer, count)
{
    return cc0_libc_unimplemented(mks("read"));
}

function write(descriptor, buffer, count)
{
    return cc0_libc_unimplemented(mks("write"));
}

function close(descriptor)
{
    return cc0_libc_unimplemented(mks("close"));
}
