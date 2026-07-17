#ifndef CC2_BOOTSTRAP_LIBC_H
#define CC2_BOOTSTRAP_LIBC_H

/*
 * Minimal i386 libc declarations for building cc2's typed boundary.
 * The bootstrap needs ABI declarations, not the host libc feature machinery.
 */
#include <stddef.h>

typedef struct cc2_bootstrap_file FILE;
typedef int jmp_buf[6];
typedef long time_t;

struct timeval {
    long tv_sec;
    long tv_usec;
};

struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
extern int errno;

void *malloc(size_t size);
void *calloc(size_t count, size_t size);
void *realloc(void *pointer, size_t size);
void free(void *pointer);
void exit(int status);
int puts(const char *text);
int sprintf(char *output, const char *format, ...);
int vsnprintf(char *output, size_t size, const char *format, char *arguments);

void *memcpy(void *destination, const void *source, size_t size);
void *memmove(void *destination, const void *source, size_t size);
void *memset(void *destination, int value, size_t size);
size_t strlen(const char *text);
int strcmp(const char *left, const char *right);

float strtof(const char *text, char **end);
double strtod(const char *text, char **end);
long double strtold(const char *text, char **end);
double ldexp(double value, int exponent);

int setjmp(jmp_buf environment);
void longjmp(jmp_buf environment, int value);
time_t time(time_t *value);
struct tm *localtime(const time_t *value);
int gettimeofday(struct timeval *value, void *timezone);

void *dlopen(const char *filename, int flags);
void *dlsym(void *handle, const char *name);

#define RTLD_LAZY 1
#define RTLD_GLOBAL 256
#define RTLD_DEFAULT ((void *)0)

#endif
