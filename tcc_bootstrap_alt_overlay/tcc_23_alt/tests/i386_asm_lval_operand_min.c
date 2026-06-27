int load_word(int *p)
{
    int out;

    asm("movl %1, %0"
        : "=r"(out)
        : "m"(*p));
    return out;
}
