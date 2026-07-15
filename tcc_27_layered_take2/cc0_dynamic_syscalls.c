/* Adapt the private cc0 runtime interface to the dynamically linked libc. */
function cc0_runtime_read(descriptor, buffer, count)
{
    return read(descriptor, buffer, count);
}

function cc0_runtime_write(descriptor, buffer, count)
{
    return write(descriptor, buffer, count);
}

/* Emulate the raw Linux brk return contract through glibc. */
function cc0_runtime_brk_(address, current)
{
    current = sbrk(0);
    if (eq(address, 0)) {
        return current;
    }
    if (lt(brk(address), 0)) {
        return current;
    }
    return sbrk(0);
}

function cc0_runtime_brk(address)
{
    return cc0_runtime_brk_(address, 0);
}
