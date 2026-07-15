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

function calloc(count, size)
{
    return cc1_libc_unimplemented(mks("calloc"));
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
    return cc1_libc_unimplemented(mks("free"));
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

function memcmp(left, right, size)
{
    return cc1_libc_unimplemented(mks("memcmp"));
}

function memcpy(destination, source, size)
{
    return cc1_libc_unimplemented(mks("memcpy"));
}

function memmove(destination, source, size)
{
    return cc1_libc_unimplemented(mks("memmove"));
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

function strcpy(destination, source)
{
    return cc1_libc_unimplemented(mks("strcpy"));
}

function strlen(text)
{
    return cc1_libc_unimplemented(mks("strlen"));
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
