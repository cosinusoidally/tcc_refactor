typedef enum result_kind {
    RESULT_ZERO,
    RESULT_THREE = 1 + 2,
    RESULT_FOUR
} result_kind;

typedef int (*result_transform)(int);

result_kind global_result = RESULT_THREE;

int main()
{
    result_kind local_result = RESULT_FOUR;
    int values[3];
    values[1] = local_result;
    return (global_result - 3) + (local_result - 4) + RESULT_ZERO
        + (sizeof(result_transform) - 4) + (values[1] - 4);
}
