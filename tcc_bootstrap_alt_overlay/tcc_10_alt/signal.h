#ifndef _SIGNAL_H
#define _SIGNAL_H

typedef int sig_atomic_t;
typedef unsigned long sigset_t;
typedef void (*__sighandler_t)();
typedef struct {
    int si_signo;
    int si_errno;
    int si_code;
} siginfo_t;
typedef struct {
    void *sa_handler;
    void *sa_sigaction;
    sigset_t sa_mask;
    int sa_flags;
    void *sa_restorer;
} sigaction_t;

#define SIG_DFL ((__sighandler_t)0)
#define SIG_IGN ((__sighandler_t)1)
#define SIG_ERR ((__sighandler_t)-1)

#define SIGILL 4
#define SIGABRT 6
#define SIGBUS 7
#define SIGFPE 8
#define SIGSEGV 11

#define FPE_INTDIV 1
#define FPE_FLTDIV 3

#define SA_SIGINFO 4
#define SA_ONESHOT 0x80000000

int signal();
int sigemptyset();
int sigaction();

#endif
