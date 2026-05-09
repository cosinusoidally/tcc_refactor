#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <libio.h>
#include <unistd.h>
#include <stdarg.h>

static unsigned long long udivmod64(unsigned long long num,
                                    unsigned long long den,
                                    unsigned long long *rem)
{
    unsigned long long q;
    unsigned long long r;
    int i;

    if (den == 0)
        return 0;
    q = 0;
    r = 0;
    for (i = 63; i >= 0; --i) {
        r = (r << 1) | ((num >> i) & 1ULL);
        if (r >= den) {
            r = r - den;
            q |= 1ULL << i;
        }
    }
    if (rem)
        *rem = r;
    return q;
}

unsigned long long __udivdi3(unsigned long long num, unsigned long long den)
{
    return udivmod64(num, den, 0);
}

unsigned long long __umoddi3(unsigned long long num, unsigned long long den)
{
    unsigned long long rem;

    udivmod64(num, den, &rem);
    return rem;
}

long long __divdi3(long long num, long long den)
{
    unsigned long long unum;
    unsigned long long uden;
    unsigned long long q;
    int neg;

    if (den == 0)
        return 0;
    neg = 0;
    if (num < 0) {
        unum = (unsigned long long)(-num);
        neg = !neg;
    } else {
        unum = (unsigned long long)num;
    }
    if (den < 0) {
        uden = (unsigned long long)(-den);
        neg = !neg;
    } else {
        uden = (unsigned long long)den;
    }
    q = udivmod64(unum, uden, 0);
    if (neg)
        return -(long long)q;
    return (long long)q;
}

long long __moddi3(long long num, long long den)
{
    unsigned long long unum;
    unsigned long long uden;
    unsigned long long rem;
    int neg;

    if (den == 0)
        return 0;
    neg = 0;
    if (num < 0) {
        unum = (unsigned long long)(-num);
        neg = 1;
    } else {
        unum = (unsigned long long)num;
    }
    if (den < 0)
        uden = (unsigned long long)(-den);
    else
        uden = (unsigned long long)den;
    udivmod64(unum, uden, &rem);
    if (neg)
        return -(long long)rem;
    return (long long)rem;
}

static unsigned long long fixuns_generic(long double x)
{
    unsigned long long bit;
    unsigned long long r;
    long double cur;

    if (x <= 0)
        return 0;
    r = 0;
    bit = 1ULL << 63;
    cur = ldexp(1.0, 63);
    while (1) {
        if (x >= cur) {
            x = x - cur;
            r |= bit;
        }
        if (bit == 1)
            break;
        bit = bit >> 1;
        cur = cur * 0.5;
    }
    return r;
}

unsigned long long __fixunssfdi(float x)
{
    return fixuns_generic(x);
}

unsigned long long __fixunsdfdi(double x)
{
    return fixuns_generic(x);
}

unsigned long long __fixunsxfdi(long double x)
{
    return fixuns_generic(x);
}

int vfprintf(FILE *stream, const char *fmt, va_list ap)
{
    char buf[1024];
    int n;

    n = vsnprintf(buf, sizeof(buf), fmt, ap);
    fputs(buf, stream);
    return n;
}

int fprintf(FILE *stream, const char *fmt, ...)
{
    va_list ap;
    int n;

    va_start(ap, fmt);
    n = vfprintf(stream, fmt, ap);
    va_end(ap);
    return n;
}

int getc_unlocked(FILE *stream)
{
    char *buf;
    int n;
    int size;

    if (stream->_IO_read_ptr < stream->_IO_read_end)
        return *(unsigned char *)stream->_IO_read_ptr++;

    buf = stream->_IO_buf_base;
    size = stream->_IO_buf_end - stream->_IO_buf_base;
    if (!buf || size <= 0) {
        buf = stream->_shortbuf;
        size = 1;
        stream->_IO_buf_base = buf;
        stream->_IO_buf_end = buf + size;
    }
    n = read(stream->_fileno, buf, size);
    if (n <= 0)
        return -1;
    stream->_IO_read_base = buf;
    stream->_IO_read_ptr = buf + 1;
    stream->_IO_read_end = buf + n;
    return *(unsigned char *)buf;
}

char *strdup(char *s)
{
    int len;
    char *r;

    len = strlen(s) + 1;
    r = malloc(len);
    if (!r)
        return 0;
    memcpy(r, s, len);
    return r;
}

void *mmap(void *start, unsigned int length, int prot, int flags,
           int fd, unsigned int offset)
{
    return malloc(length);
}
