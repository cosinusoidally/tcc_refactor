int foo(int x);

int bar(int x)
{
    return foo(x) + 1;
}

int foo(int x)
{
    return x + 2;
}
