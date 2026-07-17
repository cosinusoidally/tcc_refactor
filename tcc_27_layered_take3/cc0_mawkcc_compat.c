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

/* The disposable seed uses a monotonic allocator. */
function free(address)
{
    return 0;
}

function bnot(value)
{
    return xor(value, sub(0, 1));
}

function strlen_(text, length)
{
    while (ri8(add(text, length))) {
        length = add(length, 1);
    }
    return length;
}

function strlen(text)
{
    return strlen_(text, 0);
}

function memcpy_(destination, source, count, index)
{
    while (lt(index, count)) {
        wi8(add(destination, index), ri8(add(source, index)));
        index = add(index, 1);
    }
    return destination;
}

function memcpy(destination, source, count)
{
    return memcpy_(destination, source, count, 0);
}

function memmove_(destination, source, count, index)
{
    if (lt(destination, source)) {
        return memcpy(destination, source, count);
    }
    index = count;
    while (lt(0, index)) {
        index = sub(index, 1);
        wi8(add(destination, index), ri8(add(source, index)));
    }
    return destination;
}

function memmove(destination, source, count)
{
    return memmove_(destination, source, count, 0);
}

function memset_(destination, value, count, index)
{
    while (lt(index, count)) {
        wi8(add(destination, index), value);
        index = add(index, 1);
    }
    return destination;
}

function memset(destination, value, count)
{
    return memset_(destination, value, count, 0);
}

function calloc_(count, size, bytes, result)
{
    bytes = mul(count, size);
    result = malloc(bytes);
    if (result) {
        memset(result, 0, bytes);
    }
    return result;
}

function calloc(count, size)
{
    return calloc_(count, size, 0, 0);
}

function strcmp_(left, right, first, second)
{
    first = ri8(left);
    second = ri8(right);
    while (and(eq(first, second), first)) {
        left = add(left, 1);
        right = add(right, 1);
        first = ri8(left);
        second = ri8(right);
    }
    return sub(first, second);
}

function strcmp(left, right)
{
    return strcmp_(left, right, 0, 0);
}

function strncmp_(left, right, count, index, first, second)
{
    while (lt(index, count)) {
        first = ri8(add(left, index));
        second = ri8(add(right, index));
        if (not(eq(first, second))) {
            return sub(first, second);
        }
        if (eq(first, 0)) {
            return 0;
        }
        index = add(index, 1);
    }
    return 0;
}

function strncmp(left, right, count)
{
    return strncmp_(left, right, count, 0, 0, 0);
}

function strcpy(destination, source)
{
    memcpy(destination, source, add(strlen(source), 1));
    return destination;
}

function strcat_(destination, source, end)
{
    end = add(destination, strlen(destination));
    strcpy(end, source);
    return destination;
}

function strcat(destination, source)
{
    return strcat_(destination, source, 0);
}

function memcmp_(left, right, count, index, first, second)
{
    while (lt(index, count)) {
        first = ri8(add(left, index));
        second = ri8(add(right, index));
        if (not(eq(first, second))) {
            return sub(first, second);
        }
        index = add(index, 1);
    }
    return 0;
}

function memcmp(left, right, count)
{
    return memcmp_(left, right, count, 0, 0, 0);
}

function strchr_(text, character, current)
{
    current = ri8(text);
    while (not(eq(current, character))) {
        if (eq(current, 0)) {
            return 0;
        }
        text = add(text, 1);
        current = ri8(text);
    }
    return text;
}

function strchr(text, character)
{
    return strchr_(text, character, 0);
}

function puts_(text, length)
{
    length = strlen(text);
    write(1, text, length);
    write(1, mks("\n"), 1);
    return 0;
}

function puts(text)
{
    return puts_(text, 0);
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
