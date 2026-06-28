void stable_function(void)
{
}

static const unsigned int asm_like_table[] = {
    0xe0, 0xe1, 0xe2, 0xe3, 0xd8d9, 0xd8c0
};

int read_table(int i)
{
    return asm_like_table[i];
}
