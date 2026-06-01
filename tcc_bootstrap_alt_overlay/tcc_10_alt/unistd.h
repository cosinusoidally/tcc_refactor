#ifndef _UNISTD_H
#define _UNISTD_H 1

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

int open(const char *pathname, int flags, ...);
int close(int fd);
int read(int fd, void *buf, unsigned int count);
int getcwd(char *buf, int size);
long lseek(int fd, long offset, int whence);

#endif
