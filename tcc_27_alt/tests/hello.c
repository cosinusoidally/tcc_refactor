int printf(const char *, ...);

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    printf("hello i386 %d\n", add(20, 22));
    return 0;
}
