#include "tcc.h"

ST_DATA int gnu_ext = 1;
ST_DATA int tcc_ext = 1;
ST_DATA struct TCCState *tcc_state;
static int nb_states;

#include "tccpp.c"
#include "tccgen.c"
#include "tccelf.c"

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
        tcc_error("memory full (malloc)");
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
        tcc_error("memory full (realloc)");
    return ptr1;
}
