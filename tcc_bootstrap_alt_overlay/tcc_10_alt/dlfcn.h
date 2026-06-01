#ifndef _DLFCN_H
#define _DLFCN_H 1

#define RTLD_LAZY 0x00001
#define RTLD_NOW 0x00002
#define RTLD_GLOBAL 0x00100
#define RTLD_LOCAL 0

void *dlopen();
void *dlsym();

#endif
