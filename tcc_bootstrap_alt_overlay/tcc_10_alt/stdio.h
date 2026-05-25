#ifndef _STDIO_H
#define _STDIO_H

#include "stdarg.h"
#include "stddef.h"

typedef struct _tcc_file FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *stream);
int fflush(FILE *stream);
int fprintf();
int vfprintf();
int printf();
int sprintf();
int snprintf();
int vsnprintf();
int fputs(const char *s, FILE *stream);
int fputc(int c, FILE *stream);
int getc_unlocked(FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

#endif
