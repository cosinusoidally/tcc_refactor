/* Small environment-neutral libc surface shared by static and dynamic links. */
var CC0_LIBC_HEAP_CURSOR;
var CC0_LIBC_HEAP_LIMIT;
var CC0_LIBC_HEAP_GROWTH_BYTES;
var CC0_LIBC_READ_CACHE_HEAD;
var CC0_LIBC_READ_CACHE_NEXT_OFFSET;
var CC0_LIBC_READ_CACHE_DESCRIPTOR_OFFSET;
var CC0_LIBC_READ_CACHE_BUFFER_OFFSET;
var CC0_LIBC_READ_CACHE_CURSOR_OFFSET;
var CC0_LIBC_READ_CACHE_END_OFFSET;
var CC0_LIBC_READ_CACHE_RECORD_BYTES;
var CC0_LIBC_READ_CACHE_BUFFER_BYTES;
var CC0_LIBC_SEEK_CURRENT;
var CC0_LIBC_INVALID_DESCRIPTOR;

function cc0_libc_init()
{
    CC0_LIBC_HEAP_CURSOR = 0;
    CC0_LIBC_HEAP_LIMIT = 0;
    /* Amortize brk calls without imposing a maximum allocation size. */
    CC0_LIBC_HEAP_GROWTH_BYTES = mul(1024, 1024);
    CC0_LIBC_READ_CACHE_HEAD = 0;
    CC0_LIBC_READ_CACHE_NEXT_OFFSET = 0;
    CC0_LIBC_READ_CACHE_DESCRIPTOR_OFFSET = 4;
    CC0_LIBC_READ_CACHE_BUFFER_OFFSET = 8;
    CC0_LIBC_READ_CACHE_CURSOR_OFFSET = 12;
    CC0_LIBC_READ_CACHE_END_OFFSET = 16;
    CC0_LIBC_READ_CACHE_RECORD_BYTES = 20;
    CC0_LIBC_READ_CACHE_BUFFER_BYTES = mul(64, 1024);
    CC0_LIBC_SEEK_CURRENT = 1;
    CC0_LIBC_INVALID_DESCRIPTOR = sub(0, 1);
}

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

function cc0_libc_reserve_heap_(next, limit, target, result)
{
    limit = CC0_LIBC_HEAP_LIMIT;
    if (not(cc0_libc_unsigned_less(limit, next))) {
        return 1;
    }
    target = add(limit, CC0_LIBC_HEAP_GROWTH_BYTES);
    if (or(cc0_libc_unsigned_less(target, limit),
        cc0_libc_unsigned_less(target, next))) {
        target = next;
    }
    result = cc0_runtime_brk(target);
    if (not(eq(result, target))) {
        return 0;
    }
    CC0_LIBC_HEAP_LIMIT = target;
    return 1;
}

function cc0_libc_reserve_heap(next)
{
    return cc0_libc_reserve_heap_(next, 0, 0, 0);
}

/* cc0 does not free yet, so the reserved break is a simple bump arena. */
function malloc_(size, alignment, mask, allocation, current, header, start,
    next)
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
    if (eq(CC0_LIBC_HEAP_GROWTH_BYTES, 0)) {
        cc0_libc_init();
    }
    current = CC0_LIBC_HEAP_CURSOR;
    if (eq(current, 0)) {
        current = cc0_runtime_brk(0);
        if (eq(current, 0)) {
            return 0;
        }
        CC0_LIBC_HEAP_CURSOR = current;
        CC0_LIBC_HEAP_LIMIT = current;
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
    if (not(cc0_libc_reserve_heap(next))) {
        return 0;
    }
    wi32(header, allocation);
    CC0_LIBC_HEAP_CURSOR = next;
    return start;
}

function malloc(size)
{
    return malloc_(size, 0, 0, 0, 0, 0, 0, 0);
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

function cc0_libc_read_cache_find_(descriptor, cache)
{
    cache = CC0_LIBC_READ_CACHE_HEAD;
    while (not(eq(cache, 0))) {
        if (eq(ri32(add(cache,
            CC0_LIBC_READ_CACHE_DESCRIPTOR_OFFSET)), descriptor)) {
            return cache;
        }
        cache = ri32(add(cache, CC0_LIBC_READ_CACHE_NEXT_OFFSET));
    }
    return 0;
}

function cc0_libc_read_cache_find(descriptor)
{
    return cc0_libc_read_cache_find_(descriptor, 0);
}

function cc0_libc_read_cache_create_(descriptor, cache, buffer)
{
    cache = malloc(CC0_LIBC_READ_CACHE_RECORD_BYTES);
    if (eq(cache, 0)) {
        return 0;
    }
    buffer = malloc(CC0_LIBC_READ_CACHE_BUFFER_BYTES);
    if (eq(buffer, 0)) {
        return 0;
    }
    wi32(add(cache, CC0_LIBC_READ_CACHE_NEXT_OFFSET),
        CC0_LIBC_READ_CACHE_HEAD);
    wi32(add(cache, CC0_LIBC_READ_CACHE_DESCRIPTOR_OFFSET), descriptor);
    wi32(add(cache, CC0_LIBC_READ_CACHE_BUFFER_OFFSET), buffer);
    wi32(add(cache, CC0_LIBC_READ_CACHE_CURSOR_OFFSET), 0);
    wi32(add(cache, CC0_LIBC_READ_CACHE_END_OFFSET), 0);
    CC0_LIBC_READ_CACHE_HEAD = cache;
    return cache;
}

function cc0_libc_read_cache_create(descriptor)
{
    return cc0_libc_read_cache_create_(descriptor, 0, 0);
}

function cc0_libc_read_cache_unread_(cache, cursor, end)
{
    if (eq(cache, 0)) {
        return 0;
    }
    cursor = ri32(add(cache, CC0_LIBC_READ_CACHE_CURSOR_OFFSET));
    end = ri32(add(cache, CC0_LIBC_READ_CACHE_END_OFFSET));
    return sub(end, cursor);
}

function cc0_libc_read_cache_unread(cache)
{
    return cc0_libc_read_cache_unread_(cache, 0, 0);
}

function cc0_libc_read_cache_discard(cache)
{
    if (not(eq(cache, 0))) {
        wi32(add(cache, CC0_LIBC_READ_CACHE_CURSOR_OFFSET), 0);
        wi32(add(cache, CC0_LIBC_READ_CACHE_END_OFFSET), 0);
    }
    return 0;
}

/* Restore the kernel offset before an operation bypasses buffered reads. */
function cc0_libc_read_cache_sync_(descriptor, cache, unread, result)
{
    cache = cc0_libc_read_cache_find(descriptor);
    unread = cc0_libc_read_cache_unread(cache);
    if (not(eq(unread, 0))) {
        result = cc0_runtime_lseek(descriptor, sub(0, unread),
            CC0_LIBC_SEEK_CURRENT);
        if (lt(result, 0)) {
            return result;
        }
    }
    cc0_libc_read_cache_discard(cache);
    return 0;
}

function cc0_libc_read_cache_sync(descriptor)
{
    return cc0_libc_read_cache_sync_(descriptor, 0, 0, 0);
}

function cc0_libc_read_(descriptor, buffer, count, cache, cursor, end,
    amount, position)
{
    if (le(count, 0)) {
        return cc0_runtime_read(descriptor, buffer, count);
    }
    if (eq(CC0_LIBC_HEAP_GROWTH_BYTES, 0)) {
        cc0_libc_init();
    }
    cache = cc0_libc_read_cache_find(descriptor);
    if (eq(cache, 0)) {
        position = cc0_runtime_lseek(descriptor, 0, CC0_LIBC_SEEK_CURRENT);
        if (lt(position, 0)) {
            return cc0_runtime_read(descriptor, buffer, count);
        }
        cache = cc0_libc_read_cache_create(descriptor);
        if (eq(cache, 0)) {
            return cc0_runtime_read(descriptor, buffer, count);
        }
    }
    cursor = ri32(add(cache, CC0_LIBC_READ_CACHE_CURSOR_OFFSET));
    end = ri32(add(cache, CC0_LIBC_READ_CACHE_END_OFFSET));
    if (eq(cursor, end)) {
        if (le(CC0_LIBC_READ_CACHE_BUFFER_BYTES, count)) {
            return cc0_runtime_read(descriptor, buffer, count);
        }
        amount = cc0_runtime_read(descriptor,
            ri32(add(cache, CC0_LIBC_READ_CACHE_BUFFER_OFFSET)),
            CC0_LIBC_READ_CACHE_BUFFER_BYTES);
        if (le(amount, 0)) {
            return amount;
        }
        cursor = 0;
        end = amount;
        wi32(add(cache, CC0_LIBC_READ_CACHE_END_OFFSET), end);
    }
    amount = sub(end, cursor);
    if (lt(count, amount)) {
        amount = count;
    }
    cc0_libc_copy(buffer,
        add(ri32(add(cache, CC0_LIBC_READ_CACHE_BUFFER_OFFSET)), cursor),
        amount);
    wi32(add(cache, CC0_LIBC_READ_CACHE_CURSOR_OFFSET),
        add(cursor, amount));
    return amount;
}

function open(path, flags, mode)
{
    return cc0_runtime_open(path, flags, mode);
}

function read(descriptor, buffer, count)
{
    return cc0_libc_read_(descriptor, buffer, count, 0, 0, 0, 0, 0);
}

function write(descriptor, buffer, count)
{
    if (lt(cc0_libc_read_cache_sync(descriptor), 0)) {
        return sub(0, 1);
    }
    return cc0_runtime_write(descriptor, buffer, count);
}

function close(descriptor)
{
    var cache;

    cache = cc0_libc_read_cache_find(descriptor);
    if (not(eq(cache, 0))) {
        cc0_libc_read_cache_discard(cache);
        wi32(add(cache, CC0_LIBC_READ_CACHE_DESCRIPTOR_OFFSET),
            CC0_LIBC_INVALID_DESCRIPTOR);
    }
    return cc0_runtime_close(descriptor);
}

function lseek(descriptor, offset, whence)
{
    var cache;
    var unread;

    cache = cc0_libc_read_cache_find(descriptor);
    unread = cc0_libc_read_cache_unread(cache);
    if (and(eq(whence, CC0_LIBC_SEEK_CURRENT), not(eq(unread, 0)))) {
        offset = sub(offset, unread);
    }
    cc0_libc_read_cache_discard(cache);
    return cc0_runtime_lseek(descriptor, offset, whence);
}
