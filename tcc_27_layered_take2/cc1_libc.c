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

function fprintf(stream, format, value)
{
    return cc1_libc_unimplemented(mks("fprintf"));
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

function printf(format, value)
{
    return cc1_libc_unimplemented(mks("printf"));
}

function qsort(base, count, size, compare)
{
    return cc1_libc_unimplemented(mks("qsort"));
}

function remove(path)
{
    return cc1_libc_unimplemented(mks("remove"));
}

function snprintf(output, size, format, value)
{
    return cc1_libc_unimplemented(mks("snprintf"));
}

function sprintf(output, format, value)
{
    return cc1_libc_unimplemented(mks("sprintf"));
}

function setjmp(environment)
{
    /* Temporary bootstrap behavior: cc2 always enters the protected body. */
    return 0;
}

function strcat(destination, source)
{
    strcpy(add(destination, strlen(destination)), source);
    return destination;
}

function strchr(text, character)
{
    return cc1_libc_unimplemented(mks("strchr"));
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

function strncmp(left, right, size)
{
    return cc1_libc_unimplemented(mks("strncmp"));
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

function strtod(text, end)
{
    return cc1_libc_unimplemented(mks("strtod"));
}

function strtof(text, end)
{
    return cc1_libc_unimplemented(mks("strtof"));
}

function strtold(text, end)
{
    return cc1_libc_unimplemented(mks("strtold"));
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

function vsnprintf(output, size, format, arguments)
{
    return cc1_libc_unimplemented(mks("vsnprintf"));
}
