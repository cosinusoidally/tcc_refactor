/* Low-level adapters that the mawkcc dialect cannot express directly. */
function cc0_runtime_brk_(target, current, amount, base)
{
    current = brk(0);
    if (eq(target, 0)) {
        return current;
    }
    amount = sub(target, current);
    if (lt(amount, 0)) {
        return current;
    }
    base = brk(amount);
    if (eq(base, current)) {
        return target;
    }
    return base;
}

function cc0_runtime_brk(target)
{
    return cc0_runtime_brk_(target, 0, 0, 0);
}

function cc0_runtime_write(descriptor, buffer, count)
{
    return write(descriptor, buffer, count);
}

function cc0_runtime_read(descriptor, buffer, count)
{
    return read(descriptor, buffer, count);
}

function cc0_runtime_open(path, flags, mode)
{
    return open(path, flags, mode);
}

function cc0_runtime_close(descriptor)
{
    return close(descriptor);
}

function cc0_runtime_exit(status)
{
    exit(status);
    return 0;
}

function cc0_runtime_lseek(descriptor, offset, whence)
{
    return lseek(descriptor, offset, whence);
}

function cc0_runtime_unlink(path)
{
    return unlink(path);
}

function bnot(value)
{
    return xor(value, sub(0, 1));
}
/* mawkcc exposes these operations under its shorter builtin spellings. */
function sdiv(left, right)
{
    return div(left, right);
}

function ushr(value, count)
{
    return shr(value, count);
}
