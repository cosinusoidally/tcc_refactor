static void qswap(char *a, char *b, int size)
{
    char tmp;

    while (size > 0) {
        tmp = *a;
        *a = *b;
        *b = tmp;
        ++a;
        ++b;
        --size;
    }
}

void *memmove(void *dest, void *src, int n)
{
    char *d;
    char *s;

    d = dest;
    s = src;
    if (d == s || n <= 0)
        return dest;
    if (d < s) {
        while (n > 0) {
            *d = *s;
            ++d;
            ++s;
            --n;
        }
    } else {
        d += n;
        s += n;
        while (n > 0) {
            --d;
            --s;
            *d = *s;
            --n;
        }
    }
    return dest;
}

static int qpart(char *base, int count, int size,
                 int (*compare)(void *, void *))
{
    char *pivot;
    int i, j, c;

    pivot = base + count * size;
    i = 0;
    j = 0;
    while (j < count) {
        c = compare(base + j * size, pivot);
        if (c < 0) {
            qswap(base + i * size, base + j * size, size);
            ++i;
        } else if (c == 0) {
            ++i;
        }
        ++j;
    }
    if (compare(pivot, base + i * size) < 0)
        qswap(base + i * size, pivot, size);
    return i;
}

void qsort(void *base, int count, int size, int (*compare)(void *, void *))
{
    int p;
    char *data;

    if (count <= 1)
        return;
    data = base;
    p = qpart(data, count - 1, size, compare);
    qsort(data, p, size, compare);
    qsort(data + p * size, count - p, size, compare);
}

char *strstr(char *haystack, char *needle)
{
    char *h, *n, *start;

    if (*needle == '\0')
        return haystack;

    start = haystack;
    while (*start != '\0') {
        h = start;
        n = needle;
        while (*h != '\0' && *n != '\0' && *h == *n) {
            ++h;
            ++n;
        }
        if (*n == '\0')
            return start;
        ++start;
    }
    return 0;
}

int fseek(void)
{
    return -1;
}

int ftell(void)
{
    return -1;
}

int fread(void)
{
    return 0;
}

int remove(void)
{
    return -1;
}

int execvp(void)
{
    return -1;
}
