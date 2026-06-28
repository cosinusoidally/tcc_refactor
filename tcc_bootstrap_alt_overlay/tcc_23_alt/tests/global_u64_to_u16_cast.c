typedef unsigned short uint16_t;
typedef unsigned long long uint64_t;

struct narrowed {
    uint16_t opcode;
};

static struct narrowed value = { (uint64_t)0x1bc };

int read_opcode(void)
{
    return value.opcode;
}
