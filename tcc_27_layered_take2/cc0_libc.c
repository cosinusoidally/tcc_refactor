/* Small environment-neutral libc surface shared by static and dynamic links. */
var CC0_LIBC_HEAP_END;

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

function cc0_libc_allocation_alignment()
{
    return 8;
}

function cc0_libc_unsigned_less_(left, right, left_high, right_high)
{
    left_high = ushr(left, 31);
    right_high = ushr(right, 31);
    if (not(eq(left_high, right_high))) {
        return lt(left_high, right_high);
    }
    return lt(left, right);
}

function cc0_libc_unsigned_less(left, right)
{
    return cc0_libc_unsigned_less_(left, right, 0, 0);
}

/* cc0 does not free yet, so extending the process break cannot fragment. */
function malloc_(size, alignment, mask, allocation, current, start, next,
    result)
{
    if (le(size, 0)) {
        return 0;
    }
    alignment = cc0_libc_allocation_alignment();
    mask = sub(alignment, 1);
    allocation = and(add(size, mask), bnot(mask));
    if (lt(allocation, size)) {
        return 0;
    }
    current = CC0_LIBC_HEAP_END;
    if (eq(current, 0)) {
        current = cc0_runtime_brk(0);
        if (eq(current, 0)) {
            return 0;
        }
    }
    start = and(add(current, mask), bnot(mask));
    if (cc0_libc_unsigned_less(start, current)) {
        return 0;
    }
    next = add(start, allocation);
    if (cc0_libc_unsigned_less(next, start)) {
        return 0;
    }
    result = cc0_runtime_brk(next);
    if (not(eq(result, next))) {
        return 0;
    }
    CC0_LIBC_HEAP_END = next;
    return start;
}

function malloc(size)
{
    return malloc_(size, 0, 0, 0, 0, 0, 0, 0);
}

function realloc(address, size)
{
    return cc0_libc_unimplemented(mks("realloc"));
}

function open(path, flags, mode)
{
    return cc0_runtime_open(path, flags, mode);
}

function read(descriptor, buffer, count)
{
    return cc0_runtime_read(descriptor, buffer, count);
}

function write(descriptor, buffer, count)
{
    return cc0_runtime_write(descriptor, buffer, count);
}

function close(descriptor)
{
    return cc0_libc_unimplemented(mks("close"));
}
