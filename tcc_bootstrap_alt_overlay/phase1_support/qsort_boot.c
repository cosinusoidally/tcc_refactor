int strcmp();
int strcpy();
int strcat();
int strtoul();
int int2str();
int fputs();
int fputc();

static int boot_copy_rel_name(int dst, int suffix)
{
    int o;

    o = strcpy(dst, ".rel");
    o = strcat(dst, suffix);
    return o - dst;
}

static int boot_copy_label_name(int dst, int value)
{
    int o;

    o = strcpy(dst, "L.");
    o = strcat(dst, int2str(value, 10, 0));
    return o - dst;
}

static int boot_copy_include_name(int dst, int prefix)
{
    int o;

    o = strcpy(dst, prefix);
    o = strcat(dst, "/include");
    return o - dst;
}

static int boot_copy_path_name(int dst, int prefix, int suffix)
{
    int o;

    o = strcpy(dst, prefix);
    o = strcat(dst, "/");
    o = strcat(dst, suffix);
    return o - dst;
}

static int boot_copy_symbol_edge(int dst, int middle, int tail)
{
    int o;

    o = strcpy(dst, "__");
    o = strcat(dst, middle);
    o = strcat(dst, tail);
    return o - dst;
}

static int boot_copy_percent_name(int dst, int suffix)
{
    int o;

    o = strcpy(dst, "%");
    o = strcat(dst, suffix);
    return o - dst;
}

static int boot_copy_paren_percent_name(int dst, int suffix)
{
    int o;

    o = strcpy(dst, "(%");
    o = strcat(dst, suffix);
    o = strcat(dst, ")");
    return o - dst;
}

static int boot_copy_signed_name(int dst, int value, int suffix)
{
    int o;

    o = strcpy(dst, int2str(value, 10, 1));
    o = strcat(dst, suffix);
    return o - dst;
}

int sprintf(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int format;
    int o;

    format = a2;
    if (strcmp(".rel%s", format) == 0) {
        return boot_copy_rel_name(a1, a3);
    } else if (strcmp("L.%u", format) == 0) {
        return boot_copy_label_name(a1, a3);
    } else if (strcmp("%s/include", format) == 0) {
        return boot_copy_include_name(a1, a3);
    } else if (strcmp("%s/%s", format) == 0) {
        return boot_copy_path_name(a1, a3, a4);
    } else if (strcmp("__%s_start", format) == 0) {
        return boot_copy_symbol_edge(a1, a3, "_start");
    } else if (strcmp("__%s_end", format) == 0) {
        return boot_copy_symbol_edge(a1, a3, "_end");
    } else if (strcmp("%%%s", format) == 0) {
        return boot_copy_percent_name(a1, a3);
    } else if (strcmp("(%%%s)", format) == 0) {
        return boot_copy_paren_percent_name(a1, a3);
    } else if (strcmp("%d(%%ebp)", format) == 0) {
        return boot_copy_signed_name(a1, a3, "(%ebp)");
    } else if (strcmp("%d", format) == 0) {
        o = strcpy(a1, int2str(a3, 10, 1));
        return o - a1;
    } else if (strcmp("%s", format) == 0) {
        o = strcpy(a1, a3);
        return o - a1;
    } else {
        puts("unsupported sprintf/snprintf format string");
        exit(1);
    }
    return 0;
}

int snprintf(int a1, int a2, int a3, int a4, int a5, int a6)
{
    sprintf(a1, a3, a4, a5, a6, 0);
    return 0;
}

int vsnprintf(int a1, int a2, int a3, int a4)
{
    int *args;
    int o;

    args = (int *)a4;
    if (strcmp("%s: error: '%s' defined twice", a3) == 0) {
        o = strcpy(a1, args[0]);
        o = strcat(a1, ": error: '");
        o = strcat(a1, args[1]);
        o = strcat(a1, "' defined twice");
    } else {
        strcpy(a1, a3);
    }
    return 0;
}

int fprintf(int stream, int fmt, int a1)
{
    if (strcmp("%s\n", fmt) == 0) {
        fputs(a1, 1);
        fputc('\n', 1);
    } else if (strcmp("%s", fmt) == 0) {
        fputs(a1, 1);
    } else {
        fputs(fmt, 1);
    }
    return 0;
}

int vfprintf(int stream, int fmt)
{
    fputs(fmt, 1);
    return 0;
}

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

int sscanf(int str, int format, int *a1, int *a2, int *a3, int *a4)
{
    if (strcmp(str, "0.9.26") == 0) {
        a1[0] = 0;
        a2[0] = 9;
        a3[0] = 26;
    } else if (strcmp(str, "0.9.27") == 0) {
        a1[0] = 0;
        a2[0] = 9;
        a3[0] = 27;
    } else {
        puts("unsupported sscanf format string");
        exit(1);
    }
    return 0;
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

int fflush(void)
{
    return 0;
}

int ftell(void)
{
    return -1;
}

int fread(void)
{
    return 0;
}

int getenv(void)
{
    return 0;
}

int getcwd(void)
{
    return 0;
}

int remove(void)
{
    return -1;
}

int unlink(void)
{
    return -1;
}

int dlclose(void)
{
    return 0;
}

unsigned long long strtoull(char *string, char **tailptr, int base)
{
    return strtoul(string, tailptr, base);
}

int execvp(void)
{
    return -1;
}
