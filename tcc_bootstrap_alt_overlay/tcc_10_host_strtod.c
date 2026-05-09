#include <stdio.h>
#include <string.h>

double strtod(const char *a, char **p)
{
    if (p)
        *p = (char *)a;
    if (strcmp("4294967296.0", a) == 0)
        return 4294967296.0;
    puts("tcc10 host strtod shim");
    return 0.0;
}
