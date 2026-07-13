#define RESULT 0
int global_result;

int identity(int value)
{
    return value;
}

#ifdef RESULT
int main()
{
    global_result = identity(RESULT);
    return global_result;
}
#else
int main()
{
    return 1;
}
#endif
