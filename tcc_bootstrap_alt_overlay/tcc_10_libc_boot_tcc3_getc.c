#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int read(int fd, void *buf, unsigned int count);
void *malloc(unsigned int size);
int fputc(int c, void *stream);
int fputs(const char *s, void *stream);

void free(void *ptr)
{
}

static unsigned int dup_strlen(const char *s)
{
    const char *p;

    p = s;
    while (*p)
        p++;
    return p - s;
}

static void *dup_memcpy(void *dest, const void *src, unsigned int n)
{
    char *d;
    const char *s;

    d = dest;
    s = src;
    while (n--)
        *d++ = *s++;
    return dest;
}

void *mmap(void *start, unsigned int length, int prot, int flags,
           int fd, unsigned int offset)
{
    return malloc(length);
}

float strtof(const char *nptr, char **endptr)
{
    return (float)strtod(nptr, endptr);
}

long double strtold(const char *nptr, char **endptr)
{
    return (long double)strtod(nptr, endptr);
}

char *strchr(const char *s, int c)
{
    while (*s) {
        if (*s == c)
            return (char *)s;
        s++;
    }
    if (c == 0)
        return (char *)s;
    return 0;
}

char *strrchr(const char *s, int c)
{
    const char *last;

    last = 0;
    while (*s) {
        if (*s == c)
            last = s;
        s++;
    }
    if (c == 0)
        return (char *)s;
    return (char *)last;
}

char *strdup(const char *s)
{
    size_t len;
    char *r;

    len = dup_strlen(s) + 1;
    r = malloc(len);
    if (!r)
        return 0;
    dup_memcpy(r, s, len);
    return r;
}

int getc_unlocked(void *stream)
{
    unsigned char ch;
    int fd;

    fd = (int)stream;
    if (read(fd, &ch, 1) != 1)
        return -1;
    return ch;
}

static int buf_putc(char **out, char *out_end, int ch)
{
    if (*out < out_end)
        **out = ch;
    (*out)++;
    return 1;
}

static int buf_puts(char **out, char *out_end, const char *s)
{
    int n;

    n = 0;
    if (!s)
        s = "(null)";
    while (*s) {
        buf_putc(out, out_end, *s++);
        n++;
    }
    return n;
}

static int buf_putu(char **out, char *out_end, unsigned int v, int base)
{
    char tmp[32];
    int i;
    int n;

    i = 0;
    do {
        int d;

        d = v % base;
        tmp[i++] = d < 10 ? ('0' + d) : ('a' + (d - 10));
        v /= base;
    } while (v);

    n = i;
    while (i--)
        buf_putc(out, out_end, tmp[i]);
    return n;
}

static int buf_putd(char **out, char *out_end, int v)
{
    unsigned int uv;
    int n;

    n = 0;
    if (v < 0) {
        buf_putc(out, out_end, '-');
        n++;
        uv = (unsigned int)(-v);
    } else {
        uv = (unsigned int)v;
    }
    return n + buf_putu(out, out_end, uv, 10);
}

static int mini_vsnprintf(char *str, unsigned int size, const char *fmt, va_list ap)
{
    char *out;
    char *out_end;
    int total;

    out = str;
    out_end = size ? (str + size - 1) : str;
    total = 0;
    while (*fmt) {
        if (*fmt != '%') {
            buf_putc(&out, out_end, *fmt++);
            total++;
            continue;
        }
        fmt++;
        switch (*fmt) {
        case '%':
            buf_putc(&out, out_end, '%');
            total++;
            break;
        case 'c':
            total += buf_putc(&out, out_end, va_arg(ap, int));
            break;
        case 's':
            total += buf_puts(&out, out_end, va_arg(ap, char *));
            break;
        case 'd':
            total += buf_putd(&out, out_end, va_arg(ap, int));
            break;
        case 'u':
            total += buf_putu(&out, out_end, va_arg(ap, unsigned int), 10);
            break;
        case 'x':
            total += buf_putu(&out, out_end, va_arg(ap, unsigned int), 16);
            break;
        default:
            total += buf_putc(&out, out_end, '%');
            if (*fmt)
                total += buf_putc(&out, out_end, *fmt);
            break;
        }
        if (*fmt)
            fmt++;
    }
    if (size) {
        if (out > out_end)
            out = out_end;
        *out = '\0';
    }
    return total;
}

int vsnprintf(char *str, unsigned int size, const char *fmt, va_list ap)
{
    return mini_vsnprintf(str, size, fmt, ap);
}

int snprintf(char *str, unsigned int size, const char *fmt, ...)
{
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = mini_vsnprintf(str, size, fmt, ap);
    va_end(ap);
    return n;
}

int sprintf(char *str, const char *fmt, ...)
{
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = mini_vsnprintf(str, 0xffffffffu, fmt, ap);
    va_end(ap);
    return n;
}

int vfprintf(void *stream, const char *fmt, va_list ap)
{
    char buf[1024];
    int n;

    n = mini_vsnprintf(buf, sizeof(buf), fmt, ap);
    fputs(buf, stream);
    return n;
}

int fprintf(void *stream, const char *fmt, ...)
{
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = vfprintf(stream, fmt, ap);
    va_end(ap);
    return n;
}
