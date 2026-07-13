#define RESULT 0
int global_result;

int identity(int value)
{
    return value;
}

int record(int value)
{
    global_result = value;
    return 0;
}

#ifdef RESULT
int main()
{
    int temporary;
    temporary = identity((RESULT + 6 / 3 + 5 % 3 - 2) * 1);
    temporary = (temporary << 1) >> 1;
    temporary = (temporary | 8) ^ 8;
    temporary = temporary & ~0;
    record(temporary);
    while (global_result < 2) {
        global_result = global_result + 1;
    }
    if (global_result <= 2) {
        return !(global_result == 2);
    }
    return 1;
}
#else
int main()
{
    return 1;
}
#endif
