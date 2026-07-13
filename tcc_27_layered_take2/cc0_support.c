/*
 * Host implementations of cc0 operations that cannot be written in the
 * operator-free dialect. Keep compiler policy and higher-level helpers out.
 */
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int add(int left, int right) { return (int)((unsigned)left + (unsigned)right); }
int sub(int left, int right) { return (int)((unsigned)left - (unsigned)right); }
int eq(int left, int right) { return left == right; }
int lt(int left, int right) { return left < right; }
int le(int left, int right) { return left <= right; }
int not(int value) { return !value; }
int and(int left, int right) { return left & right; }
int shl(int value, int count) { return (int)((unsigned)value << count); }
int ushr(int value, int count) { return (int)((unsigned)value >> count); }
int mks(int value) { return value; }
int alloc(int size)
{
    if (size < 0) {
        return 0;
    }
#ifdef _TCC_H
    return (int)tcc_malloc((unsigned)size);
#else
    return (int)malloc((unsigned)size);
#endif
}
int ri8(int address) { return *(unsigned char *)address; }
int wi8(int address, int value) { *(unsigned char *)address = value; return value; }
int ri32(int address) { return *(int *)address; }
int wi32(int address, int value) { *(int *)address = value; return value; }
int file_open_read(int path) { return open((char *)path, O_RDONLY); }
int file_open_write(int path)
{
    return open((char *)path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
}
int file_size(int descriptor)
{
    int size = lseek(descriptor, 0, SEEK_END);
    if (size >= 0) {
        lseek(descriptor, 0, SEEK_SET);
    }
    return size;
}
int file_read_byte(int descriptor)
{
    unsigned char value;
    if (read(descriptor, &value, 1) != 1) {
        return -1;
    }
    return value;
}
int file_write_byte(int descriptor, int value)
{
    unsigned char byte = value;
    return write(descriptor, &byte, 1);
}
int file_close(int descriptor) { return close(descriptor); }
