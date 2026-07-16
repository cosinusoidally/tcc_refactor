/*
 * Runtime services used only by the mawkcc-compiled cc0 seed.  The canonical
 * cc1.exe rebuild uses the normal cc1.c and does not contain these functions.
 */
function malloc_(size, allocation_size, base)
{
    if (lt(size, 0)) {
        return 0;
    }
    /* Include a size word and preserve four-byte alignment. */
    allocation_size = mul(div(add(size, 7), 4), 4);
    base = brk(allocation_size);
    if (eq(base, 0)) {
        return 0;
    }
    wi32(base, size);
    return add(base, 4);
}

function malloc(size)
{
    return malloc_(size, 0, 0);
}

function realloc_(address, size, replacement, old_size, copy_size, index)
{
    if (eq(address, 0)) {
        return malloc(size);
    }
    replacement = malloc(size);
    if (eq(replacement, 0)) {
        return 0;
    }
    old_size = ri32(sub(address, 4));
    copy_size = old_size;
    if (lt(size, copy_size)) {
        copy_size = size;
    }
    index = 0;
    while (lt(index, copy_size)) {
        wi8(add(replacement, index), ri8(add(address, index)));
        index = add(index, 1);
    }
    return replacement;
}

function realloc(address, size)
{
    return realloc_(address, size, 0, 0, 0, 0);
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
