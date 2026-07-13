/* Compile-time contract for the single supported i386 Linux target. */
#define NB_REGS 5
#define NB_ASM_REGS 8
#define CONFIG_TCC_ASM

/* Ordered register classes are consumed by cc2's allocator policy. */
#define RC_INT 0x0001
#define RC_FLOAT 0x0002
#define RC_EAX 0x0004
#define RC_ST0 0x0008
#define RC_ECX 0x0010
#define RC_EDX 0x0020
#define RC_EBX 0x0040

#define RC_IRET RC_EAX
#define RC_LRET RC_EDX
#define RC_FRET RC_ST0

enum {
    TREG_EAX = 0,
    TREG_ECX,
    TREG_EDX,
    TREG_EBX,
    TREG_ST0,
    TREG_ESP = 4
};

#define REG_IRET TREG_EAX
#define REG_LRET TREG_EDX
#define REG_FRET TREG_ST0
#define INVERT_FUNC_PARAMS

#define PTR_SIZE 4
#define LDOUBLE_SIZE 12
#define LDOUBLE_ALIGN 4
#define MAX_ALIGN 8
