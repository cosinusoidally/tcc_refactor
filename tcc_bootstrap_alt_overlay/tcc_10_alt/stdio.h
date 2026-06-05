#ifndef _STDIO_H
#define _STDIO_H 1

typedef struct _tcc_file FILE;

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

FILE *fopen();
int fclose();
int fflush();
int fprintf();
int vfprintf();
int printf();
int fputs();
int fputc();
int getc_unlocked();
unsigned int fwrite();

#endif
