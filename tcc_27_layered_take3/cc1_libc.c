/* Shared C/JavaScript libc used by the cc1 and higher static layers. */
var CC0_LIBC_HEAP_CURSOR;
var CC0_LIBC_HEAP_LIMIT;
var CC0_LIBC_HEAP_GROWTH_BYTES;
var CC0_LIBC_FREE_HEAD;
var CC0_LIBC_ALLOCATION_SIZE_OFFSET;
var CC0_LIBC_ALLOCATION_NEXT_OFFSET;
var CC0_LIBC_ENVIRONMENT;
var CC0_LIBC_READ_CACHE_HEAD;
var CC0_LIBC_READ_CACHE_NEXT_OFFSET;
var CC0_LIBC_READ_CACHE_DESCRIPTOR_OFFSET;
var CC0_LIBC_READ_CACHE_BUFFER_OFFSET;
var CC0_LIBC_READ_CACHE_CURSOR_OFFSET;
var CC0_LIBC_READ_CACHE_END_OFFSET;
var CC0_LIBC_READ_CACHE_RECORD_BYTES;
var CC0_LIBC_READ_CACHE_BUFFER_BYTES;
var CC0_LIBC_WRITE_CACHE_HEAD;
var CC0_LIBC_WRITE_CACHE_NEXT_OFFSET;
var CC0_LIBC_WRITE_CACHE_DESCRIPTOR_OFFSET;
var CC0_LIBC_WRITE_CACHE_BUFFER_OFFSET;
var CC0_LIBC_WRITE_CACHE_END_OFFSET;
var CC0_LIBC_WRITE_CACHE_RECORD_BYTES;
var CC0_LIBC_WRITE_CACHE_BUFFER_BYTES;
var CC0_LIBC_OPEN_ACCESS_MASK;
var CC0_LIBC_OPEN_READ_ONLY;
var CC0_LIBC_SEEK_CURRENT;
var CC0_LIBC_INVALID_DESCRIPTOR;

function cc0_libc_init()
{
    CC0_LIBC_HEAP_CURSOR = 0;
    CC0_LIBC_HEAP_LIMIT = 0;
    CC0_LIBC_FREE_HEAD = 0;
    CC0_LIBC_ALLOCATION_SIZE_OFFSET = 0;
    CC0_LIBC_ALLOCATION_NEXT_OFFSET = 4;
    CC0_LIBC_ENVIRONMENT = 0;
    /* Grow by one i386 page without imposing a maximum allocation size. */
    CC0_LIBC_HEAP_GROWTH_BYTES = mul(4, 1024);
    CC0_LIBC_READ_CACHE_HEAD = 0;
    CC0_LIBC_READ_CACHE_NEXT_OFFSET = 0;
    CC0_LIBC_READ_CACHE_DESCRIPTOR_OFFSET = 4;
    CC0_LIBC_READ_CACHE_BUFFER_OFFSET = 8;
    CC0_LIBC_READ_CACHE_CURSOR_OFFSET = 12;
    CC0_LIBC_READ_CACHE_END_OFFSET = 16;
    CC0_LIBC_READ_CACHE_RECORD_BYTES = 20;
    CC0_LIBC_READ_CACHE_BUFFER_BYTES = mul(64, 1024);
    CC0_LIBC_WRITE_CACHE_HEAD = 0;
    CC0_LIBC_WRITE_CACHE_NEXT_OFFSET = 0;
    CC0_LIBC_WRITE_CACHE_DESCRIPTOR_OFFSET = 4;
    CC0_LIBC_WRITE_CACHE_BUFFER_OFFSET = 8;
    CC0_LIBC_WRITE_CACHE_END_OFFSET = 12;
    CC0_LIBC_WRITE_CACHE_RECORD_BYTES = 16;
    CC0_LIBC_WRITE_CACHE_BUFFER_BYTES = mul(64, 1024);
    CC0_LIBC_OPEN_ACCESS_MASK = 3;
    CC0_LIBC_OPEN_READ_ONLY = 0;
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

function cc0_libc_set_environment(environment)
{
    CC0_LIBC_ENVIRONMENT = environment;
    return 0;
}

function cc0_libc_set_environment_from_arguments(argc, argv)
{
    return cc0_libc_set_environment(add(argv, mul(add(argc, 1), 4)));
}

function cc0_libc_environment()
{
    return CC0_LIBC_ENVIRONMENT;
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

function puts_locals_(text, result)
{

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

function puts(text) {
    return puts_locals_(text, 0);
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
    cc0_libc_finish();
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

function cc0_libc_take_free_(allocation, previous, header, next, size)
{
    previous = 0;
    header = CC0_LIBC_FREE_HEAD;
    while (not(eq(header, 0))) {
        next = ri32(add(header, CC0_LIBC_ALLOCATION_NEXT_OFFSET));
        size = ri32(add(header, CC0_LIBC_ALLOCATION_SIZE_OFFSET));
        if (not(cc0_libc_unsigned_less(size, allocation))) {
            if (eq(previous, 0)) {
                CC0_LIBC_FREE_HEAD = next;
            } else {
                wi32(add(previous, CC0_LIBC_ALLOCATION_NEXT_OFFSET), next);
            }
            return add(header, cc0_libc_allocation_header_bytes());
        }
        previous = header;
        header = next;
    }
    return 0;
}

function cc0_libc_take_free(allocation)
{
    return cc0_libc_take_free_(allocation, 0, 0, 0, 0);
}

function cc0_libc_release_(address, header)
{
    if (eq(address, 0)) {
        return 0;
    }
    header = sub(address, cc0_libc_allocation_header_bytes());
    wi32(add(header, CC0_LIBC_ALLOCATION_NEXT_OFFSET), CC0_LIBC_FREE_HEAD);
    CC0_LIBC_FREE_HEAD = header;
    return 0;
}

function cc0_libc_release(address)
{
    return cc0_libc_release_(address, 0);
}

/* Extend the break only when no released allocation can satisfy the request. */
function malloc_(size, alignment, mask, allocation, reused, current, header,
    start, next)
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
    reused = cc0_libc_take_free(allocation);
    if (not(eq(reused, 0))) {
        return reused;
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
        cc0_libc_release(address);
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
    cc0_libc_release(address);
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

function cc0_libc_write_cache_find_(descriptor, cache)
{
    cache = CC0_LIBC_WRITE_CACHE_HEAD;
    while (not(eq(cache, 0))) {
        if (eq(ri32(add(cache,
            CC0_LIBC_WRITE_CACHE_DESCRIPTOR_OFFSET)), descriptor)) {
            return cache;
        }
        cache = ri32(add(cache, CC0_LIBC_WRITE_CACHE_NEXT_OFFSET));
    }
    return 0;
}

function cc0_libc_write_cache_find(descriptor)
{
    return cc0_libc_write_cache_find_(descriptor, 0);
}

function cc0_libc_write_cache_create_(descriptor, cache, buffer)
{
    cache = malloc(CC0_LIBC_WRITE_CACHE_RECORD_BYTES);
    if (eq(cache, 0)) {
        return 0;
    }
    buffer = malloc(CC0_LIBC_WRITE_CACHE_BUFFER_BYTES);
    if (eq(buffer, 0)) {
        return 0;
    }
    wi32(add(cache, CC0_LIBC_WRITE_CACHE_NEXT_OFFSET),
        CC0_LIBC_WRITE_CACHE_HEAD);
    wi32(add(cache, CC0_LIBC_WRITE_CACHE_DESCRIPTOR_OFFSET), descriptor);
    wi32(add(cache, CC0_LIBC_WRITE_CACHE_BUFFER_OFFSET), buffer);
    wi32(add(cache, CC0_LIBC_WRITE_CACHE_END_OFFSET), 0);
    CC0_LIBC_WRITE_CACHE_HEAD = cache;
    return cache;
}

function cc0_libc_write_cache_create(descriptor)
{
    return cc0_libc_write_cache_create_(descriptor, 0, 0);
}

function cc0_libc_write_cache_flush_(cache, descriptor, buffer, end,
    position, result)
{
    if (eq(cache, 0)) {
        return 0;
    }
    descriptor = ri32(add(cache, CC0_LIBC_WRITE_CACHE_DESCRIPTOR_OFFSET));
    buffer = ri32(add(cache, CC0_LIBC_WRITE_CACHE_BUFFER_OFFSET));
    end = ri32(add(cache, CC0_LIBC_WRITE_CACHE_END_OFFSET));
    position = 0;
    while (lt(position, end)) {
        result = cc0_runtime_write(descriptor, add(buffer, position),
            sub(end, position));
        if (le(result, 0)) {
            return sub(0, 1);
        }
        position = add(position, result);
    }
    wi32(add(cache, CC0_LIBC_WRITE_CACHE_END_OFFSET), 0);
    return 0;
}

function cc0_libc_write_cache_flush(cache)
{
    return cc0_libc_write_cache_flush_(cache, 0, 0, 0, 0, 0);
}

function cc0_libc_write_cache_flush_descriptor(descriptor)
{
    return cc0_libc_write_cache_flush(
        cc0_libc_write_cache_find(descriptor));
}

function cc0_libc_finish_(cache)
{
    cache = CC0_LIBC_WRITE_CACHE_HEAD;
    while (not(eq(cache, 0))) {
        if (not(eq(ri32(add(cache,
            CC0_LIBC_WRITE_CACHE_DESCRIPTOR_OFFSET)),
            CC0_LIBC_INVALID_DESCRIPTOR))) {
            cc0_libc_write_cache_flush(cache);
        }
        cache = ri32(add(cache, CC0_LIBC_WRITE_CACHE_NEXT_OFFSET));
    }
    return 0;
}

function cc0_libc_finish()
{
    return cc0_libc_finish_(0);
}

function cc0_libc_write_(descriptor, buffer, count, cache, written, end,
    space, amount)
{
    cache = cc0_libc_write_cache_find(descriptor);
    if (eq(cache, 0)) {
        return cc0_runtime_write(descriptor, buffer, count);
    }
    written = 0;
    while (lt(written, count)) {
        end = ri32(add(cache, CC0_LIBC_WRITE_CACHE_END_OFFSET));
        space = sub(CC0_LIBC_WRITE_CACHE_BUFFER_BYTES, end);
        amount = sub(count, written);
        if (lt(space, amount)) {
            amount = space;
        }
        cc0_libc_copy(add(ri32(add(cache,
            CC0_LIBC_WRITE_CACHE_BUFFER_OFFSET)), end),
            add(buffer, written), amount);
        end = add(end, amount);
        written = add(written, amount);
        wi32(add(cache, CC0_LIBC_WRITE_CACHE_END_OFFSET), end);
        if (eq(end, CC0_LIBC_WRITE_CACHE_BUFFER_BYTES)) {
            if (lt(cc0_libc_write_cache_flush(cache), 0)) {
                return sub(0, 1);
            }
        }
    }
    return written;
}

function cc0_libc_open_(path, flags, mode, descriptor, access)
{
    if (eq(CC0_LIBC_HEAP_GROWTH_BYTES, 0)) {
        cc0_libc_init();
    }
    descriptor = cc0_runtime_open(path, flags, mode);
    if (lt(descriptor, 0)) {
        return descriptor;
    }
    access = and(flags, CC0_LIBC_OPEN_ACCESS_MASK);
    if (not(eq(access, CC0_LIBC_OPEN_READ_ONLY))) {
        cc0_libc_write_cache_create(descriptor);
    }
    return descriptor;
}

function open(path, flags, mode)
{
    return cc0_libc_open_(path, flags, mode, 0, 0);
}

function read(descriptor, buffer, count)
{
    if (lt(cc0_libc_write_cache_flush_descriptor(descriptor), 0)) {
        return sub(0, 1);
    }
    return cc0_libc_read_(descriptor, buffer, count, 0, 0, 0, 0, 0);
}

function write(descriptor, buffer, count)
{
    if (lt(cc0_libc_read_cache_sync(descriptor), 0)) {
        return sub(0, 1);
    }
    return cc0_libc_write_(descriptor, buffer, count, 0, 0, 0, 0, 0);
}

function close_locals_(descriptor, cache, write_cache, result)
{

    result = cc0_libc_write_cache_flush_descriptor(descriptor);
    write_cache = cc0_libc_write_cache_find(descriptor);
    if (not(eq(write_cache, 0))) {
        wi32(add(write_cache, CC0_LIBC_WRITE_CACHE_DESCRIPTOR_OFFSET),
            CC0_LIBC_INVALID_DESCRIPTOR);
    }
    cache = cc0_libc_read_cache_find(descriptor);
    if (not(eq(cache, 0))) {
        cc0_libc_read_cache_discard(cache);
        wi32(add(cache, CC0_LIBC_READ_CACHE_DESCRIPTOR_OFFSET),
            CC0_LIBC_INVALID_DESCRIPTOR);
    }
    if (lt(cc0_runtime_close(descriptor), 0)) {
        return sub(0, 1);
    }
    return result;
}

function close(descriptor) {
    return close_locals_(descriptor, 0, 0, 0);
}

function lseek_locals_(descriptor, offset, whence, cache, unread)
{

    if (lt(cc0_libc_write_cache_flush_descriptor(descriptor), 0)) {
        return sub(0, 1);
    }
    cache = cc0_libc_read_cache_find(descriptor);
    unread = cc0_libc_read_cache_unread(cache);
    if (and(eq(whence, CC0_LIBC_SEEK_CURRENT), not(eq(unread, 0)))) {
        offset = sub(offset, unread);
    }
    cc0_libc_read_cache_discard(cache);
    return cc0_runtime_lseek(descriptor, offset, whence);
}

function lseek(descriptor, offset, whence) {
    return lseek_locals_(descriptor, offset, whence, 0, 0);
}
/*
 * Layer-one libc surface required to start the cc2 bootstrap.
 *
 * These deliberately fatal definitions make the next implementation boundary
 * observable.  Implementations replace the stubs one at a time while the
 * public ABI and the cc2 link remain stable.
 */

var stdin;
var stdout;
var stderr;
var CC1_LIBC_STREAM_HEAD;
var CC1_LIBC_STREAM_DESCRIPTOR_OFFSET;
var CC1_LIBC_STREAM_READABLE_OFFSET;
var CC1_LIBC_STREAM_WRITABLE_OFFSET;
var CC1_LIBC_STREAM_EOF_OFFSET;
var CC1_LIBC_STREAM_ERROR_OFFSET;
var CC1_LIBC_STREAM_OWNED_OFFSET;
var CC1_LIBC_STREAM_NEXT_OFFSET;
var CC1_LIBC_STREAM_SCRATCH_OFFSET;
var CC1_LIBC_STREAM_BYTES;
var CC1_LIBC_OPEN_READ_ONLY;
var CC1_LIBC_OPEN_WRITE_ONLY;
var CC1_LIBC_OPEN_READ_WRITE;
var CC1_LIBC_OPEN_CREATE;
var CC1_LIBC_OPEN_TRUNCATE;
var CC1_LIBC_OPEN_APPEND;
var CC1_LIBC_CREATE_MODE;

function cc1_libc_stream_create_(descriptor, readable, writable, owned,
    stream)
{
    stream = malloc(CC1_LIBC_STREAM_BYTES);
    if (eq(stream, 0)) {
        return 0;
    }
    wi32(add(stream, CC1_LIBC_STREAM_DESCRIPTOR_OFFSET), descriptor);
    wi32(add(stream, CC1_LIBC_STREAM_READABLE_OFFSET), readable);
    wi32(add(stream, CC1_LIBC_STREAM_WRITABLE_OFFSET), writable);
    wi32(add(stream, CC1_LIBC_STREAM_EOF_OFFSET), 0);
    wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 0);
    wi32(add(stream, CC1_LIBC_STREAM_OWNED_OFFSET), owned);
    wi32(add(stream, CC1_LIBC_STREAM_NEXT_OFFSET), CC1_LIBC_STREAM_HEAD);
    wi32(add(stream, CC1_LIBC_STREAM_SCRATCH_OFFSET), 0);
    CC1_LIBC_STREAM_HEAD = stream;
    return stream;
}

function cc1_libc_stream_create(descriptor, readable, writable, owned)
{
    return cc1_libc_stream_create_(descriptor, readable, writable, owned, 0);
}

function cc1_libc_init()
{
    if (not(eq(CC1_LIBC_STREAM_BYTES, 0))) {
        return 0;
    }
    cc0_libc_init();
    CC1_LIBC_STREAM_HEAD = 0;
    CC1_LIBC_STREAM_DESCRIPTOR_OFFSET = 0;
    CC1_LIBC_STREAM_READABLE_OFFSET = 4;
    CC1_LIBC_STREAM_WRITABLE_OFFSET = 8;
    CC1_LIBC_STREAM_EOF_OFFSET = 12;
    CC1_LIBC_STREAM_ERROR_OFFSET = 16;
    CC1_LIBC_STREAM_OWNED_OFFSET = 20;
    CC1_LIBC_STREAM_NEXT_OFFSET = 24;
    CC1_LIBC_STREAM_SCRATCH_OFFSET = 28;
    CC1_LIBC_STREAM_BYTES = 32;
    CC1_LIBC_OPEN_READ_ONLY = 0;
    CC1_LIBC_OPEN_WRITE_ONLY = 1;
    CC1_LIBC_OPEN_READ_WRITE = 2;
    CC1_LIBC_OPEN_CREATE = 64;
    CC1_LIBC_OPEN_TRUNCATE = 512;
    CC1_LIBC_OPEN_APPEND = 1024;
    CC1_LIBC_CREATE_MODE = 438;
    stdin = cc1_libc_stream_create(0, 1, 0, 0);
    stdout = cc1_libc_stream_create(1, 0, 1, 0);
    stderr = cc1_libc_stream_create(2, 0, 1, 0);
    if (or(eq(stdin, 0), or(eq(stdout, 0), eq(stderr, 0)))) {
        cc1_libc_unimplemented(mks("cc1 libc stream initialization"));
    }
    return 0;
}

function cc1_libc_finish()
{
    return fflush(0);
}

function cc1_libc_stream_descriptor(stream)
{
    return ri32(add(stream, CC1_LIBC_STREAM_DESCRIPTOR_OFFSET));
}

function cc1_libc_unimplemented(name)
{
    return cc0_libc_unimplemented(name);
}

function atoi(text)
{
    return cc1_libc_unimplemented(mks("atoi"));
}

/* Return zero when the unsigned product does not fit in one i386 word. */
function cc1_libc_size_product_(left, right, low, high, multiplicand_low,
    multiplicand_high, next_low, carry)
{
    low = 0;
    high = 0;
    multiplicand_low = left;
    multiplicand_high = 0;
    while (not(eq(right, 0))) {
        if (not(eq(and(right, 1), 0))) {
            next_low = add(low, multiplicand_low);
            carry = cc0_libc_unsigned_less(next_low, low);
            high = add(high, add(multiplicand_high, carry));
            low = next_low;
        }
        multiplicand_high = or(shl(multiplicand_high, 1),
            ushr(multiplicand_low, 31));
        multiplicand_low = shl(multiplicand_low, 1);
        right = ushr(right, 1);
    }
    if (not(eq(high, 0))) {
        return 0;
    }
    return low;
}

function calloc_(count, size, bytes, address)
{
    bytes = cc1_libc_size_product_(count, size, 0, 0, 0, 0, 0, 0);
    if (eq(bytes, 0)) {
        return 0;
    }
    address = malloc(bytes);
    if (eq(address, 0)) {
        return 0;
    }
    return memset(address, 0, bytes);
}

function calloc(count, size)
{
    return calloc_(count, size, 0, 0);
}

/* This hook becomes the single buffer-drain point when buffering is added. */
function cc1_libc_stream_flush(stream)
{
    if (eq(stream, 0)) {
        return sub(0, 1);
    }
    if (eq(ri32(add(stream, CC1_LIBC_STREAM_WRITABLE_OFFSET)), 0)) {
        return 0;
    }
    if (lt(cc0_libc_write_cache_flush_descriptor(
        cc1_libc_stream_descriptor(stream)), 0)) {
        wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 1);
        return sub(0, 1);
    }
    return 0;
}

function cc1_libc_stream_unlink_(stream, previous, current, next)
{
    previous = 0;
    current = CC1_LIBC_STREAM_HEAD;
    while (not(eq(current, 0))) {
        next = ri32(add(current, CC1_LIBC_STREAM_NEXT_OFFSET));
        if (eq(current, stream)) {
            if (eq(previous, 0)) {
                CC1_LIBC_STREAM_HEAD = next;
            } else {
                wi32(add(previous, CC1_LIBC_STREAM_NEXT_OFFSET), next);
            }
            return 1;
        }
        previous = current;
        current = next;
    }
    return 0;
}

function cc1_libc_stream_unlink(stream)
{
    return cc1_libc_stream_unlink_(stream, 0, 0, 0);
}

function fclose_(stream, result, close_result)
{
    if (eq(stream, 0)) {
        return sub(0, 1);
    }
    result = cc1_libc_stream_flush(stream);
    close_result = close(cc1_libc_stream_descriptor(stream));
    if (lt(close_result, 0)) {
        result = sub(0, 1);
    }
    cc1_libc_stream_unlink(stream);
    if (eq(stream, stdin)) {
        stdin = 0;
    }
    if (eq(stream, stdout)) {
        stdout = 0;
    }
    if (eq(stream, stderr)) {
        stderr = 0;
    }
    free(stream);
    return result;
}

function fclose(stream)
{
    return fclose_(stream, 0, 0);
}

function fflush_(stream, current, result)
{
    if (not(eq(stream, 0))) {
        return cc1_libc_stream_flush(stream);
    }
    result = 0;
    current = CC1_LIBC_STREAM_HEAD;
    while (not(eq(current, 0))) {
        if (lt(cc1_libc_stream_flush(current), 0)) {
            result = sub(0, 1);
        }
        current = ri32(add(current, CC1_LIBC_STREAM_NEXT_OFFSET));
    }
    return result;
}

function fflush(stream)
{
    return fflush_(stream, 0, 0);
}

function fopen_(path, mode, primary, index, byte, plus, flags, readable,
    writable, descriptor, stream)
{
    if (eq(CC1_LIBC_STREAM_BYTES, 0)) {
        cc1_libc_init();
    }
    primary = ri8(mode);
    if (eq(primary, 0)) {
        return 0;
    }
    plus = 0;
    index = 1;
    while (not(eq(ri8(add(mode, index)), 0))) {
        byte = ri8(add(mode, index));
        if (eq(byte, mkC("+"))) {
            if (plus) {
                return 0;
            }
            plus = 1;
        } else if (not(eq(byte, mkC("b")))) {
            return 0;
        }
        index = add(index, 1);
    }
    readable = 0;
    writable = 0;
    flags = 0;
    if (eq(primary, mkC("r"))) {
        readable = 1;
        flags = CC1_LIBC_OPEN_READ_ONLY;
    } else if (eq(primary, mkC("w"))) {
        writable = 1;
        flags = or(CC1_LIBC_OPEN_WRITE_ONLY,
            or(CC1_LIBC_OPEN_CREATE, CC1_LIBC_OPEN_TRUNCATE));
    } else if (eq(primary, mkC("a"))) {
        writable = 1;
        flags = or(CC1_LIBC_OPEN_WRITE_ONLY,
            or(CC1_LIBC_OPEN_CREATE, CC1_LIBC_OPEN_APPEND));
    } else {
        return 0;
    }
    if (plus) {
        readable = 1;
        writable = 1;
        flags = or(and(flags, bnot(3)), CC1_LIBC_OPEN_READ_WRITE);
    }
    descriptor = open(path, flags, CC1_LIBC_CREATE_MODE);
    if (lt(descriptor, 0)) {
        return 0;
    }
    stream = cc1_libc_stream_create(descriptor, readable, writable, 1);
    if (eq(stream, 0)) {
        close(descriptor);
        return 0;
    }
    return stream;
}

function fopen(path, mode)
{
    return fopen_(path, mode, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

function cc1_libc_argument_words_(first, second, third, fourth, fifth,
    arguments)
{
    arguments = malloc(20);
    if (arguments) {
        wi32(arguments, first);
        wi32(add(arguments, 4), second);
        wi32(add(arguments, 8), third);
        wi32(add(arguments, 12), fourth);
        wi32(add(arguments, 16), fifth);
    }
    return arguments;
}

function cc1_libc_argument_words(first, second, third, fourth, fifth)
{
    return cc1_libc_argument_words_(first, second, third, fourth, fifth, 0);
}

function fprintf_locals_(stream, format, first, second, third, fourth, fifth,
    arguments, length, buffer, written)
{

    arguments = cc1_libc_argument_words(first, second, third, fourth, fifth);
    length = vsnprintf(0, 0, format, arguments);
    if (lt(length, 0)) {
        return sub(0, 1);
    }
    buffer = malloc(add(length, 1));
    if (eq(buffer, 0)) {
        return sub(0, 1);
    }
    vsnprintf(buffer, add(length, 1), format, arguments);
    written = fwrite(buffer, 1, length, stream);
    free(buffer);
    if (not(eq(written, length))) {
        return sub(0, 1);
    }
    return length;
}

function fprintf(stream, format, first, second, third, fourth, fifth) {
    return fprintf_locals_(stream, format, first, second, third, fourth,
        fifth, 0, 0, 0, 0);
}

function fputc(character, stream)
{
    if (eq(stream, 0)) {
        return sub(0, 1);
    }
    wi8(add(stream, CC1_LIBC_STREAM_SCRATCH_OFFSET), character);
    if (not(eq(fwrite(add(stream, CC1_LIBC_STREAM_SCRATCH_OFFSET),
        1, 1, stream), 1))) {
        return sub(0, 1);
    }
    return and(character, 255);
}

function fputs_(text, stream, length)
{
    length = strlen(text);
    if (eq(length, 0)) {
        return 0;
    }
    if (not(eq(fwrite(text, 1, length, stream), length))) {
        return sub(0, 1);
    }
    return 0;
}

function fputs(text, stream)
{
    return fputs_(text, stream, 0);
}

function fread_(buffer, size, count, stream, bytes, consumed, result,
    descriptor)
{
    if (or(eq(size, 0), eq(count, 0))) {
        return 0;
    }
    if (or(eq(stream, 0), eq(ri32(add(stream,
        CC1_LIBC_STREAM_READABLE_OFFSET)), 0))) {
        if (not(eq(stream, 0))) {
            wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 1);
        }
        return 0;
    }
    bytes = cc1_libc_size_product_(size, count, 0, 0, 0, 0, 0, 0);
    if (eq(bytes, 0)) {
        wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 1);
        return 0;
    }
    descriptor = cc1_libc_stream_descriptor(stream);
    consumed = 0;
    while (lt(consumed, bytes)) {
        result = read(descriptor, add(buffer, consumed), sub(bytes, consumed));
        if (eq(result, 0)) {
            wi32(add(stream, CC1_LIBC_STREAM_EOF_OFFSET), 1);
            return sdiv(consumed, size);
        }
        if (lt(result, 0)) {
            wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 1);
            return sdiv(consumed, size);
        }
        consumed = add(consumed, result);
    }
    return count;
}

function fread(buffer, size, count, stream)
{
    return fread_(buffer, size, count, stream, 0, 0, 0, 0);
}

function free(address)
{
    return cc0_libc_release(address);
}

function fseek_(stream, offset, origin, position)
{
    if (eq(stream, 0)) {
        return sub(0, 1);
    }
    if (lt(cc1_libc_stream_flush(stream), 0)) {
        return sub(0, 1);
    }
    position = lseek(cc1_libc_stream_descriptor(stream), offset, origin);
    if (lt(position, 0)) {
        wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 1);
        return sub(0, 1);
    }
    wi32(add(stream, CC1_LIBC_STREAM_EOF_OFFSET), 0);
    return 0;
}

function fseek(stream, offset, origin)
{
    return fseek_(stream, offset, origin, 0);
}

function ftell_(stream, position)
{
    if (eq(stream, 0)) {
        return sub(0, 1);
    }
    position = lseek(cc1_libc_stream_descriptor(stream), 0, 1);
    if (lt(position, 0)) {
        wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 1);
        return sub(0, 1);
    }
    return position;
}

function ftell(stream)
{
    return ftell_(stream, 0);
}

function fwrite_(buffer, size, count, stream, bytes, written, result,
    descriptor)
{
    if (or(eq(size, 0), eq(count, 0))) {
        return 0;
    }
    if (or(eq(stream, 0), eq(ri32(add(stream,
        CC1_LIBC_STREAM_WRITABLE_OFFSET)), 0))) {
        if (not(eq(stream, 0))) {
            wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 1);
        }
        return 0;
    }
    bytes = cc1_libc_size_product_(size, count, 0, 0, 0, 0, 0, 0);
    if (eq(bytes, 0)) {
        wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 1);
        return 0;
    }
    descriptor = cc1_libc_stream_descriptor(stream);
    written = 0;
    while (lt(written, bytes)) {
        result = write(descriptor, add(buffer, written), sub(bytes, written));
        if (le(result, 0)) {
            wi32(add(stream, CC1_LIBC_STREAM_ERROR_OFFSET), 1);
            return sdiv(written, size);
        }
        written = add(written, result);
    }
    return count;
}

function fwrite(buffer, size, count, stream)
{
    return fwrite_(buffer, size, count, stream, 0, 0, 0, 0);
}

function getcwd(buffer, size)
{
    return cc1_libc_unimplemented(mks("getcwd"));
}

function getenv_(name, environment, entry, name_index, entry_index,
    name_byte, entry_byte)
{
    environment = cc0_libc_environment();
    if (eq(environment, 0)) {
        return 0;
    }
    entry_index = 0;
    while (1) {
        entry = ri32(add(environment, mul(entry_index, 4)));
        if (eq(entry, 0)) {
            return 0;
        }
        name_index = 0;
        while (1) {
            name_byte = ri8(add(name, name_index));
            entry_byte = ri8(add(entry, name_index));
            if (eq(name_byte, 0)) {
                if (eq(entry_byte, mkC("="))) {
                    return add(entry, add(name_index, 1));
                }
                break;
            }
            if (or(eq(name_byte, mkC("=")),
                not(eq(name_byte, entry_byte)))) {
                break;
            }
            name_index = add(name_index, 1);
        }
        entry_index = add(entry_index, 1);
    }
}

function getenv(name)
{
    return getenv_(name, 0, 0, 0, 0, 0, 0);
}

/* Typed cc2 calls these through its normal C ABI; each boundary stays fatal
 * until its real layer-one implementation and focused smoke test are added. */
function gettimeofday(value, timezone)
{
    return cc1_libc_unimplemented(mks("gettimeofday"));
}

function ldexp(value_low, value_high, exponent)
{
    return cc1_libc_unimplemented(mks("ldexp"));
}

function localtime(value)
{
    return cc1_libc_unimplemented(mks("localtime"));
}

function longjmp(environment, value)
{
    /* Temporary bootstrap behavior: fatal errors terminate instead of
     * restoring cc2's compilation scope. */
    cc1_libc_finish();
    exit(1);
    return 0;
}

function memcmp_(left, right, size, index, left_byte, right_byte)
{
    index = 0;
    while (lt(index, size)) {
        left_byte = ri8(add(left, index));
        right_byte = ri8(add(right, index));
        if (not(eq(left_byte, right_byte))) {
            if (lt(left_byte, right_byte)) {
                return sub(0, 1);
            }
            return 1;
        }
        index = add(index, 1);
    }
    return 0;
}

function memcmp(left, right, size)
{
    return memcmp_(left, right, size, 0, 0, 0);
}

function memcpy(destination, source, size)
{
    return cc0_libc_copy(destination, source, size);
}

function memmove_(destination, source, size, index)
{
    if (cc0_libc_unsigned_less(destination, source)) {
        index = 0;
        while (lt(index, size)) {
            wi8(add(destination, index), ri8(add(source, index)));
            index = add(index, 1);
        }
        return destination;
    }
    index = size;
    while (not(eq(index, 0))) {
        index = sub(index, 1);
        wi8(add(destination, index), ri8(add(source, index)));
    }
    return destination;
}

function memmove(destination, source, size)
{
    return memmove_(destination, source, size, 0);
}

function memset_(destination, value, size, index, byte)
{
    index = 0;
    byte = and(value, 255);
    while (lt(index, size)) {
        wi8(add(destination, index), byte);
        index = add(index, 1);
    }
    return destination;
}

function memset(destination, value, size)
{
    return memset_(destination, value, size, 0, 0);
}

function printf_locals_(format, first, second, third, arguments, length,
    buffer, written)
{

    arguments = cc1_libc_argument_words(first, second, third, 0, 0);
    length = vsnprintf(0, 0, format, arguments);
    if (lt(length, 0)) {
        return sub(0, 1);
    }
    buffer = malloc(add(length, 1));
    if (eq(buffer, 0)) {
        return sub(0, 1);
    }
    vsnprintf(buffer, add(length, 1), format, arguments);
    written = fwrite(buffer, 1, length, stdout);
    free(buffer);
    if (not(eq(written, length))) {
        return sub(0, 1);
    }
    return length;
}

function printf(format, first, second, third) {
    return printf_locals_(format, first, second, third, 0, 0, 0, 0);
}

function remove(path)
{
    return cc1_libc_unimplemented(mks("remove"));
}

function snprintf_locals_(output, size, format, first, second, third,
    arguments)
{

    arguments = cc1_libc_argument_words(first, second, third, 0, 0);
    return vsnprintf(output, size, format, arguments);
}

function snprintf(output, size, format, first, second, third) {
    return snprintf_locals_(output, size, format, first, second, third, 0);
}

function sprintf_locals_(output, format, first, second, arguments, length)
{

    arguments = cc1_libc_argument_words(first, second, 0, 0, 0);
    length = vsnprintf(0, 0, format, arguments);
    if (lt(length, 0)) {
        return length;
    }
    return vsnprintf(output, add(length, 1), format, arguments);
}

function sprintf(output, format, first, second) {
    return sprintf_locals_(output, format, first, second, 0, 0);
}

function setjmp(environment)
{
    /* Temporary bootstrap behavior: cc2 always enters the protected body. */
    return 0;
}

function _setjmp(environment)
{
    /* Historical TCC headers select this spelling for the same temporary
     * bootstrap behavior. */
    return setjmp(environment);
}

function strcat(destination, source)
{
    strcpy(add(destination, strlen(destination)), source);
    return destination;
}

function strchr_(text, character, index, byte, target)
{
    index = 0;
    target = and(character, 255);
    while (1) {
        byte = ri8(add(text, index));
        if (eq(byte, target)) {
            return add(text, index);
        }
        if (eq(byte, 0)) {
            return 0;
        }
        index = add(index, 1);
    }
}

function strchr(text, character)
{
    return strchr_(text, character, 0, 0, 0);
}

function strcmp_(left, right, index, left_byte, right_byte)
{
    index = 0;
    while (1) {
        left_byte = ri8(add(left, index));
        right_byte = ri8(add(right, index));
        if (not(eq(left_byte, right_byte))) {
            if (lt(left_byte, right_byte)) {
                return sub(0, 1);
            }
            return 1;
        }
        if (eq(left_byte, 0)) {
            return 0;
        }
        index = add(index, 1);
    }
}

function strcmp(left, right)
{
    return strcmp_(left, right, 0, 0, 0);
}

function strcpy_(destination, source, index, byte)
{
    index = 0;
    while (1) {
        byte = ri8(add(source, index));
        wi8(add(destination, index), byte);
        if (eq(byte, 0)) {
            return destination;
        }
        index = add(index, 1);
    }
}

function strcpy(destination, source)
{
    return strcpy_(destination, source, 0, 0);
}

function strlen(text)
{
    return cc0_libc_string_length(text);
}

function strncmp_(left, right, size, index, left_byte, right_byte)
{
    index = 0;
    while (lt(index, size)) {
        left_byte = ri8(add(left, index));
        right_byte = ri8(add(right, index));
        if (not(eq(left_byte, right_byte))) {
            if (lt(left_byte, right_byte)) {
                return sub(0, 1);
            }
            return 1;
        }
        if (eq(left_byte, 0)) {
            return 0;
        }
        index = add(index, 1);
    }
    return 0;
}

function strncmp(left, right, size)
{
    return strncmp_(left, right, size, 0, 0, 0);
}

function strpbrk(text, characters)
{
    return cc1_libc_unimplemented(mks("strpbrk"));
}

function strstr(text, needle)
{
    return cc1_libc_unimplemented(mks("strstr"));
}

function strtol(text, end, base)
{
    return cc1_libc_unimplemented(mks("strtol"));
}

function strtoul(text, end, base)
{
    return cc1_libc_unimplemented(mks("strtoul"));
}

function time(value)
{
    return cc1_libc_unimplemented(mks("time"));
}

function unlink(path)
{
    return cc0_runtime_unlink(path);
}

/* Append one logical output byte while retaining snprintf truncation rules. */
function cc1_libc_format_byte_(output, size, total, byte)
{
    if (and(lt(add(total, 1), size), not(eq(output, 0)))) {
        wi8(add(output, total), byte);
    }
    return add(total, 1);
}

/* Divide an unsigned i386 word by ten without requiring a typed primitive. */
function cc1_libc_unsigned_divide_ten_(value, result, bit, quotient,
    remainder, incoming)
{
    bit = 31;
    quotient = 0;
    remainder = 0;
    while (not(lt(bit, 0))) {
        incoming = and(ushr(value, bit), 1);
        remainder = add(shl(remainder, 1), incoming);
        if (not(lt(remainder, 10))) {
            remainder = sub(remainder, 10);
            quotient = or(quotient, shl(1, bit));
        }
        bit = sub(bit, 1);
    }
    wi32(result, quotient);
    wi32(add(result, 4), remainder);
    return 0;
}

function cc1_libc_format_unsigned_(output, size, total, value, base, width,
    precision, left, zero, negative, digits, division, count, digit, padding,
    prefix)
{
    /* 32 binary digits are the longest representation of one i386 word. */
    digits = malloc(32);
    division = malloc(8);
    if (or(eq(digits, 0), eq(division, 0))) {
        if (not(eq(digits, 0))) {
            free(digits);
        }
        if (not(eq(division, 0))) {
            free(division);
        }
        return cc1_libc_unimplemented(mks("vsnprintf allocation"));
    }
    count = 0;
    if (and(eq(value, 0), eq(precision, 0))) {
        count = 0;
    } else {
        while (1) {
            if (eq(base, 10)) {
                cc1_libc_unsigned_divide_ten_(value, division, 0, 0, 0, 0);
                digit = ri32(add(division, 4));
                value = ri32(division);
            } else {
                digit = and(value, 15);
                value = ushr(value, 4);
            }
            if (lt(digit, 10)) {
                wi8(add(digits, count), add(mkC("0"), digit));
            } else {
                wi8(add(digits, count), add(mkC("a"), sub(digit, 10)));
            }
            count = add(count, 1);
            if (eq(value, 0)) {
                break;
            }
        }
    }
    prefix = negative;
    padding = sub(width, add(count, prefix));
    if (not(lt(precision, 0))) {
        if (lt(count, precision)) {
            padding = sub(width, add(precision, prefix));
        }
        zero = 0;
    }
    if (lt(padding, 0)) {
        padding = 0;
    }
    if (and(not(left), not(zero))) {
        while (not(eq(padding, 0))) {
            total = cc1_libc_format_byte_(output, size, total, mkC(" "));
            padding = sub(padding, 1);
        }
    }
    if (negative) {
        total = cc1_libc_format_byte_(output, size, total, mkC("-"));
    }
    if (and(not(left), zero)) {
        while (not(eq(padding, 0))) {
            total = cc1_libc_format_byte_(output, size, total, mkC("0"));
            padding = sub(padding, 1);
        }
    }
    while (lt(count, precision)) {
        total = cc1_libc_format_byte_(output, size, total, mkC("0"));
        precision = sub(precision, 1);
    }
    while (not(eq(count, 0))) {
        count = sub(count, 1);
        total = cc1_libc_format_byte_(output, size, total,
            ri8(add(digits, count)));
    }
    if (left) {
        while (not(eq(padding, 0))) {
            total = cc1_libc_format_byte_(output, size, total, mkC(" "));
            padding = sub(padding, 1);
        }
    }
    free(division);
    free(digits);
    return total;
}

function cc1_libc_format_text_(output, size, total, text, width, precision,
    left, length, padding, index)
{
    if (eq(text, 0)) {
        text = mks("(null)");
    }
    length = strlen(text);
    if (and(not(lt(precision, 0)), lt(precision, length))) {
        length = precision;
    }
    padding = sub(width, length);
    if (lt(padding, 0)) {
        padding = 0;
    }
    if (not(left)) {
        while (not(eq(padding, 0))) {
            total = cc1_libc_format_byte_(output, size, total, mkC(" "));
            padding = sub(padding, 1);
        }
    }
    index = 0;
    while (lt(index, length)) {
        total = cc1_libc_format_byte_(output, size, total,
            ri8(add(text, index)));
        index = add(index, 1);
    }
    if (left) {
        padding = sub(width, length);
        while (lt(0, padding)) {
            total = cc1_libc_format_byte_(output, size, total, mkC(" "));
            padding = sub(padding, 1);
        }
    }
    return total;
}

function vsnprintf_(output, size, format, arguments, total, format_index,
    byte, left, zero, width, precision, value, negative)
{
    total = 0;
    format_index = 0;
    while (not(eq(ri8(add(format, format_index)), 0))) {
        byte = ri8(add(format, format_index));
        format_index = add(format_index, 1);
        if (not(eq(byte, mkC("%")))) {
            total = cc1_libc_format_byte_(output, size, total, byte);
        } else {
            left = 0;
            zero = 0;
            if (eq(ri8(add(format, format_index)), mkC("-"))) {
                left = 1;
                format_index = add(format_index, 1);
            }
            if (eq(ri8(add(format, format_index)), mkC("0"))) {
                zero = 1;
                format_index = add(format_index, 1);
            }
            width = 0;
            if (eq(ri8(add(format, format_index)), mkC("*"))) {
                width = ri32(arguments);
                arguments = add(arguments, 4);
                format_index = add(format_index, 1);
                if (lt(width, 0)) {
                    left = 1;
                    width = sub(0, width);
                }
            } else {
                while (and(not(lt(ri8(add(format, format_index)), mkC("0"))),
                    not(lt(mkC("9"), ri8(add(format, format_index)))))) {
                    width = add(mul(width, 10), sub(ri8(add(format,
                        format_index)), mkC("0")));
                    format_index = add(format_index, 1);
                }
            }
            precision = sub(0, 1);
            if (eq(ri8(add(format, format_index)), mkC("."))) {
                format_index = add(format_index, 1);
                precision = 0;
                if (eq(ri8(add(format, format_index)), mkC("*"))) {
                    precision = ri32(arguments);
                    arguments = add(arguments, 4);
                    format_index = add(format_index, 1);
                } else {
                    while (and(not(lt(ri8(add(format, format_index)),
                        mkC("0"))), not(lt(mkC("9"), ri8(add(format,
                        format_index)))))) {
                        precision = add(mul(precision, 10), sub(ri8(add(format,
                            format_index)), mkC("0")));
                        format_index = add(format_index, 1);
                    }
                }
            }
            byte = ri8(add(format, format_index));
            format_index = add(format_index, 1);
            if (eq(byte, mkC("%"))) {
                total = cc1_libc_format_byte_(output, size, total, byte);
            } else if (eq(byte, mkC("s"))) {
                value = ri32(arguments);
                arguments = add(arguments, 4);
                total = cc1_libc_format_text_(output, size, total, value,
                    width, precision, left, 0, 0, 0);
            } else if (eq(byte, mkC("c"))) {
                value = ri32(arguments);
                arguments = add(arguments, 4);
                if (not(left)) {
                    while (lt(1, width)) {
                        total = cc1_libc_format_byte_(output, size, total,
                            mkC(" "));
                        width = sub(width, 1);
                    }
                }
                total = cc1_libc_format_byte_(output, size, total, value);
                if (left) {
                    while (lt(1, width)) {
                        total = cc1_libc_format_byte_(output, size, total,
                            mkC(" "));
                        width = sub(width, 1);
                    }
                }
            } else if (or(eq(byte, mkC("d")), eq(byte, mkC("u")))) {
                value = ri32(arguments);
                arguments = add(arguments, 4);
                negative = 0;
                if (and(eq(byte, mkC("d")), lt(value, 0))) {
                    negative = 1;
                    value = sub(0, value);
                }
                total = cc1_libc_format_unsigned_(output, size, total, value,
                    10, width, precision, left, zero, negative, 0, 0, 0, 0,
                    0, 0);
            } else if (eq(byte, mkC("x"))) {
                value = ri32(arguments);
                arguments = add(arguments, 4);
                total = cc1_libc_format_unsigned_(output, size, total, value,
                    16, width, precision, left, zero, 0, 0, 0, 0, 0, 0, 0);
            } else {
                return cc1_libc_unimplemented(mks("vsnprintf conversion"));
            }
        }
    }
    if (and(not(eq(output, 0)), not(eq(size, 0)))) {
        if (lt(total, size)) {
            wi8(add(output, total), 0);
        } else {
            wi8(add(output, sub(size, 1)), 0);
        }
    }
    return total;
}

function vsnprintf(output, size, format, arguments)
{
    return vsnprintf_(output, size, format, arguments, 0, 0, 0, 0, 0, 0,
        0, 0, 0);
}
