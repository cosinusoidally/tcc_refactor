void *memcpy(void *dst, void *src, unsigned long len);
void *memmove(void *dst, void *src, unsigned long len);

void *probe(void *dst, void *src, unsigned long len)
{
    memmove(dst, src, len);
    return memcpy(dst, src, len);
}
