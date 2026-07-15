/* Integer-only typed libc facilities used while constructing full cc2. */

typedef unsigned int size_t;

typedef int (*cc2_compare_function)(const void *, const void *);

static void cc2_qsort_swap(unsigned char *left, unsigned char *right,
                           size_t size)
{
    size_t index;
    unsigned char byte;

    for (index = 0; index < size; ++index) {
        byte = left[index];
        left[index] = right[index];
        right[index] = byte;
    }
}

/* Restore the max-heap below root. End is the inclusive final index. */
static void cc2_qsort_sift(unsigned char *base, size_t root, size_t end,
                           size_t size, cc2_compare_function compare)
{
    size_t child;
    size_t selected;

    if (end == 0) {
        return;
    }
    while (root <= (end - 1) / 2) {
        child = root * 2 + 1;
        selected = root;
        if (compare(base + selected * size, base + child * size) < 0) {
            selected = child;
        }
        if (child < end &&
            compare(base + selected * size, base + (child + 1) * size) < 0) {
            selected = child + 1;
        }
        if (selected == root) {
            return;
        }
        cc2_qsort_swap(base + root * size, base + selected * size, size);
        root = selected;
    }
}

void qsort(void *array, size_t count, size_t size,
           int (*compare)(const void *, const void *))
{
    unsigned char *base;
    size_t start;
    size_t end;

    if (count < 2 || size == 0) {
        return;
    }

    base = array;
    start = (count - 2) / 2;
    for (;;) {
        cc2_qsort_sift(base, start, count - 1, size, compare);
        if (start == 0) {
            break;
        }
        --start;
    }

    end = count - 1;
    while (end != 0) {
        cc2_qsort_swap(base, base + end * size, size);
        --end;
        cc2_qsort_sift(base, 0, end, size, compare);
    }
}
