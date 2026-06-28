#include "one_source_proto_reloc_header.h"

PUB_FUNC void *foo(unsigned long size)
{
    if (size)
        return "x";
    return 0;
}

PUB_FUNC void *bar(unsigned long size)
{
    return foo(size);
}
