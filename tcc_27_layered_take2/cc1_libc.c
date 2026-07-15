/*
 * Layer-one libc surface required to start the cc2 bootstrap.
 *
 * These deliberately fatal definitions make the next implementation boundary
 * observable.  Implementations replace the stubs one at a time while the
 * public ABI and the cc2 link remain stable.
 */

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

function fclose(stream)
{
    return cc1_libc_unimplemented(mks("fclose"));
}

function fflush(stream)
{
    return cc1_libc_unimplemented(mks("fflush"));
}

function fopen(path, mode)
{
    return cc1_libc_unimplemented(mks("fopen"));
}

function fprintf(stream, format, value)
{
    return cc1_libc_unimplemented(mks("fprintf"));
}

function fputc(character, stream)
{
    return cc1_libc_unimplemented(mks("fputc"));
}

function fputs(text, stream)
{
    return cc1_libc_unimplemented(mks("fputs"));
}

function fread(buffer, size, count, stream)
{
    return cc1_libc_unimplemented(mks("fread"));
}

function free(address)
{
    return cc0_libc_release(address);
}

function fseek(stream, offset, origin)
{
    return cc1_libc_unimplemented(mks("fseek"));
}

function ftell(stream)
{
    return cc1_libc_unimplemented(mks("ftell"));
}

function fwrite(buffer, size, count, stream)
{
    return cc1_libc_unimplemented(mks("fwrite"));
}

function getcwd(buffer, size)
{
    return cc1_libc_unimplemented(mks("getcwd"));
}

function getenv(name)
{
    return cc1_libc_unimplemented(mks("getenv"));
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

function strcat(destination, source)
{
    return cc1_libc_unimplemented(mks("strcat"));
}

function strchr(text, character)
{
    return cc1_libc_unimplemented(mks("strchr"));
}

function strcmp(left, right)
{
    return cc1_libc_unimplemented(mks("strcmp"));
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

function strtoul(text, end, base)
{
    return cc1_libc_unimplemented(mks("strtoul"));
}

function unlink(path)
{
    return cc1_libc_unimplemented(mks("unlink"));
}
