#ifndef _SYS_UCONTEXT_H
#define _SYS_UCONTEXT_H 1

typedef struct {
    unsigned long gregs[19];
} mcontext_t;

typedef struct {
    void *ss_sp;
    int ss_flags;
    unsigned int ss_size;
} stack_t;

struct ucontext {
    unsigned long uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    unsigned long uc_sigmask;
};

#endif
