#include <stdlib.h>
#include <string.h>

struct mmap_args {
    void *addr;
    unsigned long len;
    int prot;
    int flags;
    int fd;
    unsigned long offset;
};

static void *sys_mmap_bytes(unsigned long n)
{
    struct mmap_args a;
    long ret;

    a.addr = 0;
    a.len = (n + 4095) & ~4095;
    a.prot = 7;
    a.flags = 0x22;
    a.fd = -1;
    a.offset = 0;
    __asm__ volatile (
        "int $0x80"
        : "=a"(ret)
        : "0"(90), "b"(&a)
        : "memory");
    if (ret < 0 && ret >= -4095)
        return (void *)-1;
    return (void *)ret;
}

static void *dup_alloc(unsigned int n)
{
    unsigned int *p;
    unsigned int total;

    total = (n + sizeof(unsigned int) + 7) & ~7;
    p = sys_mmap_bytes(total);
    if ((void *)p == (void *)-1)
        return 0;
    *p = n;
    return p + 1;
}

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
    return sys_mmap_bytes(length);
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
    r = dup_alloc(len);
    if (!r)
        return 0;
    dup_memcpy(r, s, len);
    return r;
}

int getc_unlocked(void *stream)
{
    unsigned char ch;
    long ret;
    int fd;

    fd = (int)stream;
    __asm__ volatile (
        "int $0x80"
        : "=a"(ret)
        : "0"(3), "b"(fd), "c"(&ch), "d"(1)
        : "memory");
    if (ret != 1)
        return -1;
    return ch;
}
