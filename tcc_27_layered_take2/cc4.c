/* Layer 4: the supported i386 backend and assembler. */
/* EBX remains reserved, matching the historical i386 TCC allocation. */
#define USE_EBX 0
ST_DATA const int reg_classes[NB_REGS] = {
    RC_INT | RC_EAX,
    RC_INT | RC_ECX,
    RC_INT | RC_EDX,
    (RC_INT | RC_EBX) * USE_EBX,
    RC_FLOAT | RC_ST0,
};
#include "i386-link.c"
#include "i386-asm.c"
#include "tccasm.c"
