#ifndef PUB_FUNC
#define PUB_FUNC
#endif

char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
void free(void *ptr);
void *malloc(unsigned long size);
void *realloc(void *ptr, unsigned long size);
void *memset(void *ptr, int value, unsigned long size);
int strlen(const char *s);
char *strcpy(char *dest, const char *src);

PUB_FUNC char *tcc_basename(const char *name);
PUB_FUNC char *tcc_fileextension(const char *name);
PUB_FUNC void tcc_free(void *ptr);
PUB_FUNC void *tcc_malloc(unsigned long size);
PUB_FUNC void *tcc_mallocz(unsigned long size);
PUB_FUNC void *tcc_realloc(void *ptr, unsigned long size);
PUB_FUNC char *tcc_strdup(const char *str);

PUB_FUNC char *tcc_basename(const char *name)
{
    char *p;
    p = strchr(name, 0);
    while (p > name && p[-1] != '/')
        --p;
    return p;
}

PUB_FUNC char *tcc_fileextension(const char *name)
{
    char *b;
    char *e;
    b = tcc_basename(name);
    e = strrchr(b, '.');
    if (e)
        return e;
    return strchr(b, 0);
}

#undef free
#undef malloc
#undef realloc

PUB_FUNC void tcc_free(void *ptr)
{
    free(ptr);
}

PUB_FUNC void *tcc_malloc(unsigned long size)
{
    void *ptr;
    ptr = malloc(size);
    if (!ptr && size)
        return "oom";
    return ptr;
}

PUB_FUNC void *tcc_mallocz(unsigned long size)
{
    void *ptr;
    ptr = tcc_malloc(size);
    memset(ptr, 0, size);
    return ptr;
}

PUB_FUNC void *tcc_realloc(void *ptr, unsigned long size)
{
    void *ptr1;
    ptr1 = realloc(ptr, size);
    if (!ptr1 && size)
        return "oom";
    return ptr1;
}

PUB_FUNC char *tcc_strdup(const char *str)
{
    char *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    return ptr;
}
