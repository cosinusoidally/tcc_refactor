typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long long uint64_t;

struct ASMInstr {
    uint16_t sym;
    uint16_t opcode;
    uint16_t instr_type;
    uint8_t nb_ops;
    uint8_t op_type[3];
};

#define OPC_B          0x01
#define OPC_WL         0x02
#define OPC_BWL        (OPC_B | OPC_WL)
#define OPC_REG        0x04
#define OPC_MODRM      0x08
#define OPCT_MASK      0x70
#define OPC_TEST       0x50
#define OPC_0F         0x100
#define OPC_GROUP_SHIFT 13

enum {
    OPT_REG8 = 0,
    OPT_REG16,
    OPT_REG32,
    OPT_MMX,
    OPT_SSE,
    OPT_CR,
    OPT_TR,
    OPT_DB,
    OPT_SEG,
    OPT_ST,
    OPT_IM8,
    OPT_IM8S,
    OPT_IM16,
    OPT_IM32,
    OPT_EAX,
    OPT_ST0,
    OPT_CL,
    OPT_DX,
    OPT_ADDR,
    OPT_INDIR,
    OPT_COMPOSITE_FIRST,
    OPT_IM,
    OPT_REG,
    OPT_REGW,
    OPT_IMW,
    OPT_MMXSSE,
    OPT_DISP,
    OPT_DISP8,
    OPT_EA = 0x80
};

#define ALT(x) x
#define O(o) ((uint64_t)((((o) & 0xff00) == 0x0f00) ? ((((o) >> 8) & ~0xff) | ((o) & 0xff)) : (o)))
#define T(o, i, g) ((i) | ((g) << OPC_GROUP_SHIFT) | ((((o) & 0xff00) == 0x0f00) ? OPC_0F : 0))
#define DEF_ASM_OP0L(name, opcode, group, instr_type) { name, O(opcode), T(opcode, instr_type, group), 0, { 0 } }
#define DEF_ASM_OP1(name, opcode, group, instr_type, op0) { name, O(opcode), T(opcode, instr_type, group), 1, { op0 } }
#define DEF_ASM_OP2(name, opcode, group, instr_type, op0, op1) { name, O(opcode), T(opcode, instr_type, group), 2, { op0, op1 } }

void marker_before_table(void)
{
}

static const struct ASMInstr asm_instrs[] = {
    ALT(DEF_ASM_OP2(1, 0x0fbc, 0, OPC_MODRM | OPC_WL, OPT_REGW | OPT_EA, OPT_REGW)),
    ALT(DEF_ASM_OP2(2, 0x0fba, 4, OPC_MODRM | OPC_WL, OPT_IM8, OPT_REGW | OPT_EA)),
    ALT(DEF_ASM_OP1(3, 0x0f90, 0, OPC_MODRM | OPC_TEST, OPT_REG8 | OPT_EA)),
    DEF_ASM_OP1(4, 0xe0, 0, 0, OPT_DISP8),
    DEF_ASM_OP1(5, 0xe1, 0, 0, OPT_DISP8),
    DEF_ASM_OP1(6, 0xe2, 0, 0, OPT_DISP8),
    DEF_ASM_OP1(7, 0xe3, 0, 0, OPT_DISP8),
    ALT(DEF_ASM_OP0L(8, 0xd8d9, 0, 0)),
    ALT(DEF_ASM_OP0L(9, 0xd8c0, 0, 0)),
    { 0, }
};

int read_opcode(int i)
{
    return asm_instrs[i].opcode;
}
