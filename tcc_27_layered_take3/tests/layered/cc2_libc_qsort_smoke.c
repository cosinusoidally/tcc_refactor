/* Exercise typed comparators and swaps wider than a machine word. */

struct qsort_item {
    int key;
    int identity;
};

void qsort(void *array, unsigned int count, unsigned int size,
           int (*compare)(const void *, const void *));

static int compare_ascending(const void *left_pointer,
                             const void *right_pointer)
{
    const struct qsort_item *left;
    const struct qsort_item *right;

    left = left_pointer;
    right = right_pointer;
    if (left->key < right->key) {
        return -1;
    }
    if (left->key > right->key) {
        return 1;
    }
    return 0;
}

static int compare_descending(const void *left, const void *right)
{
    return compare_ascending(right, left);
}

int main(int argc, char **argv)
{
    struct qsort_item items[6];
    int index;

    items[0].key = 5;
    items[0].identity = 50;
    items[1].key = -2;
    items[1].identity = -20;
    items[2].key = 9;
    items[2].identity = 90;
    items[3].key = 0;
    items[3].identity = 0;
    items[4].key = 3;
    items[4].identity = 30;
    items[5].key = 1;
    items[5].identity = 10;

    qsort(items, 6, sizeof(items[0]), compare_ascending);
    for (index = 0; index < 5; ++index) {
        if (items[index].key >= items[index + 1].key) {
            return 1;
        }
    }
    for (index = 0; index < 6; ++index) {
        if (items[index].identity != items[index].key * 10) {
            return 2;
        }
    }

    qsort(items, 6, sizeof(items[0]), compare_descending);
    for (index = 0; index < 5; ++index) {
        if (items[index].key <= items[index + 1].key) {
            return 3;
        }
    }

    qsort(items, 0, sizeof(items[0]), compare_ascending);
    qsort(items, 6, 0, compare_ascending);
    return 0;
}
