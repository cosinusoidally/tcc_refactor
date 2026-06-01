#ifndef _UNISTD_H
#define _UNISTD_H 1

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

int open();
int close();
int read();
int getcwd();
long lseek();

#endif
