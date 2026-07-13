enum result_kind {
    RESULT_ZERO,
    RESULT_THREE = 3,
    RESULT_FOUR
};

enum result_kind global_result = RESULT_THREE;

int main()
{
    enum result_kind local_result = RESULT_FOUR;
    return (global_result - 3) + (local_result - 4) + RESULT_ZERO;
}
