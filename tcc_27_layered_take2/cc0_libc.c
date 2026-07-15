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

function cc0_libc_allocation_header_bytes()
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
function malloc_(size, alignment, mask, allocation, current, header, start,
    next, result)
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
    header = and(add(current, mask), bnot(mask));
    if (cc0_libc_unsigned_less(header, current)) {
        return 0;
    }
    start = add(header, cc0_libc_allocation_header_bytes());
    if (cc0_libc_unsigned_less(start, header)) {
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
    wi32(header, allocation);
    CC0_LIBC_HEAP_END = next;
    return start;
}

function malloc(size)
{
    return malloc_(size, 0, 0, 0, 0, 0, 0, 0, 0);
}

function cc0_libc_copy_(destination, source, count, index)
{
    index = 0;
    while (lt(index, count)) {
        wi8(add(destination, index), ri8(add(source, index)));
        index = add(index, 1);
    }
    return destination;
}

function cc0_libc_copy(destination, source, count)
{
    return cc0_libc_copy_(destination, source, count, 0);
}

function realloc_(address, size, header, old_size, replacement)
{
    if (eq(address, 0)) {
        return malloc(size);
    }
    if (le(size, 0)) {
        return 0;
    }
    header = sub(address, cc0_libc_allocation_header_bytes());
    old_size = ri32(header);
    if (le(size, old_size)) {
        return address;
    }
    replacement = malloc(size);
    if (eq(replacement, 0)) {
        return 0;
    }
    cc0_libc_copy(replacement, address, old_size);
    return replacement;
}

function realloc(address, size)
{
    return realloc_(address, size, 0, 0, 0);
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
