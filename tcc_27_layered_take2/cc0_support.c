/*
 * Host implementations of cc0 operations that cannot be written in the
 * operator-free dialect. Keep compiler policy and higher-level helpers out.
 */
#define CC0_SUPPORT_HEAP_BYTES (2 * 1024 * 1024)
static unsigned char cc0_support_heap[CC0_SUPPORT_HEAP_BYTES];
static unsigned cc0_support_heap_used;
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
    unsigned start = (cc0_support_heap_used + 3) & ~3u;
    unsigned end = start + (unsigned)size;
    if (end > CC0_SUPPORT_HEAP_BYTES) {
        return 0;
    }
    cc0_support_heap_used = end;
    return (int)(cc0_support_heap + start);
}
int ri8(int address) { return *(unsigned char *)address; }
int wi8(int address, int value) { *(unsigned char *)address = value; return value; }
int ri32(int address) { return *(int *)address; }
int wi32(int address, int value) { *(int *)address = value; return value; }
