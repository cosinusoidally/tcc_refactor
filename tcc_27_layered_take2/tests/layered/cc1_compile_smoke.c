#define RESULT 0
int global_result;

int identity(int value)
{
    return value;
}

#ifdef RESULT
int main()
{
    global_result = identity(RESULT + 2);
    return !(global_result == 2);
}
#else
int main()
{
    return 1;
}
#endif
