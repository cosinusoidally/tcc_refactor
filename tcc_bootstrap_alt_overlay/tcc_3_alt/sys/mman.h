#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H

#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_EXEC 4

#define MAP_PRIVATE 2
#define MAP_ANONYMOUS 0x20

void *mmap(void *start, unsigned int length, int prot, int flags,
           int fd, unsigned int offset);

#endif
