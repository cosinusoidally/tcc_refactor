void *memset(void *ptr, int c, unsigned long size);
void *malloc(unsigned long size);

void *alpha_long(unsigned long size);
void *alpha_longz(unsigned long size);

void *probe(unsigned long size)
{
    void *ptr;

    ptr = alpha_longz(size);
    ptr = alpha_long(size);
    memset(ptr, 0, size);
    return ptr;
}

void *alpha_long(unsigned long size)
{
    return malloc(size);
}

void *alpha_longz(unsigned long size)
{
    void *ptr;

    ptr = alpha_long(size);
    memset(ptr, 0, size);
    return ptr;
}
