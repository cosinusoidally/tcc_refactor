#ifndef _DLFCN_H
#define _DLFCN_H

#define RTLD_LAZY 0

void *dlopen(const char *filename, int flag);
void *dlsym(void *handle, const char *symbol);

#endif
