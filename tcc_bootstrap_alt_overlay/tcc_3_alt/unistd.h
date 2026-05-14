#ifndef _UNISTD_H
#define _UNISTD_H

int open(const char *pathname, int flags, ...);
int close(int fd);
int read(int fd, void *buf, unsigned int count);
int getcwd(char *buf, int size);
long lseek(int fd, long offset, int whence);

#endif
