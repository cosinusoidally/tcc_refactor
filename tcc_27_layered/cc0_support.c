/*
 * C runtime support for cc0 wrapper literals.
 *
 * The dialect can spell strings and character constants as mks("text") and
 * mkc('A'). The JS runtime stores strings in a virtual heap; the C runtime
 * mirrors that contract by copying strings onto the C heap and returning an
 * integer address for the early 32-bit bootstrap.
 */

void *malloc(unsigned int size);

int mkc(c)
    int c;
{
    return c;
}

int mks(s)
    char *s;
{
    char *copy;
    int len;
    int i;

    len = 0;
    while (s[len])
        len = len + 1;

    copy = malloc(len + 1);
    i = 0;
    while (i <= len) {
        copy[i] = s[i];
        i = i + 1;
    }
    return (int)copy;
}

int cc0_heap_get(ptr, offset)
    int ptr;
    int offset;
{
    unsigned char *p;

    p = (unsigned char *)ptr;
    return p[offset];
}

int cc0_heap_is_string(ptr, c0, c1, c2, c3)
    int ptr;
    int c0;
    int c1;
    int c2;
    int c3;
{
    if (cc0_heap_get(ptr, 0) != c0)
        return 0;
    if (cc0_heap_get(ptr, 1) != c1)
        return 0;
    if (cc0_heap_get(ptr, 2) != c2)
        return 0;
    if (cc0_heap_get(ptr, 3) != c3)
        return 0;
    return 1;
}
