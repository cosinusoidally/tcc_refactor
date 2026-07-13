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

/* ELF/link contract for i386 Linux. */
#define EM_TCC_TARGET EM_386
#define R_DATA_32 R_386_32
#define R_DATA_PTR R_386_32
#define R_JMP_SLOT R_386_JMP_SLOT
#define R_GLOB_DAT R_386_GLOB_DAT
#define R_COPY R_386_COPY
#define R_RELATIVE R_386_RELATIVE
#define R_NUM R_386_NUM
#define ELF_START_ADDR 0x08048000
#define ELF_PAGE_SIZE 0x1000
#define PCRELATIVE_DLLPLT 0
#define RELOCATE_DLLPLT 0
