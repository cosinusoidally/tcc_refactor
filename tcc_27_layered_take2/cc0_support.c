/*
 * Host implementations of cc0 operations that cannot be written in the
 * operator-free dialect. Keep compiler policy and higher-level helpers out.
 */
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
int ri8(int address) { return *(unsigned char *)address; }
int wi8(int address, int value) { *(unsigned char *)address = value; return value; }
int ri32(int address) { return *(int *)address; }
int wi32(int address, int value) { *(int *)address = value; return value; }
