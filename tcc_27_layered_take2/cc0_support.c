/*
 * Host implementations of cc0 operations that cannot be written in the
 * operator-free dialect. Keep compiler policy and higher-level helpers out.
 */
int add(int left, int right) { return left + right; }
int sub(int left, int right) { return left - right; }
int eq(int left, int right) { return left == right; }
int lt(int left, int right) { return left < right; }
int le(int left, int right) { return left <= right; }
int not(int value) { return !value; }
