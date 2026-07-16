/* Adapt the private cc0 runtime interface to the dynamically linked libc. */
function cc0_runtime_read(descriptor, buffer, count)
{
    return __read(descriptor, buffer, count);
}

function cc0_runtime_write(descriptor, buffer, count)
{
    return __write(descriptor, buffer, count);
}

function cc0_runtime_open(path, flags, mode)
{
    return __open(path, flags, mode);
}

function cc0_runtime_close(descriptor)
{
    return __close(descriptor);
}

function cc0_runtime_lseek(descriptor, offset, whence)
{
    return __lseek(descriptor, offset, whence);
}

function cc0_runtime_exit(status)
{
    _exit(status);
    return 0;
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

function cc0_dynamic_syscall_unlink()
{
    return 10;
}

/* Avoid interposing cc1's public unlink while still using the glibc ABI. */
function cc0_runtime_unlink(path)
{
    return syscall(cc0_dynamic_syscall_unlink(), path);
}
