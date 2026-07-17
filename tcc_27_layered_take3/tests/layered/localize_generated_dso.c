/* Hide linker-generated dynamic symbols so an import-only DSO behaves like
   the corresponding system library when cc2 resolves executable symbols. */
int read_u16(unsigned char *data, int offset)
{
    return data[offset] | data[offset + 1] << 8;
}

unsigned read_u32(unsigned char *data, int offset)
{
    return data[offset] | data[offset + 1] << 8 |
        data[offset + 2] << 16 | data[offset + 3] << 24;
}

int generated_symbol(char *name)
{
    static char *names[] = {
        "_etext", "_edata", "_end", "__preinit_array_start",
        "__preinit_array_end", "__init_array_start", "__init_array_end",
        "__fini_array_start", "__fini_array_end", "_GLOBAL_OFFSET_TABLE_",
        0
    };
    int index = 0;
    while (names[index]) {
        if (!strcmp(name, names[index])) {
            return 1;
        }
        ++index;
    }
    return 0;
}

int main(int argc, char **argv)
{
    unsigned char *data;
    int length;
    int section_table;
    int section_count;
    int dynamic_symbols = 0;
    int section;
    int strings;
    int symbol;
    int symbol_end;
    int index;
    void *file;

    if (argc != 2) {
        return 2;
    }
    file = fopen(argv[1], "rb");
    if (!file) {
        return 3;
    }
    fseek(file, 0, 2);
    length = ftell(file);
    fseek(file, 0, 0);
    data = malloc(length);
    if (!data || fread(data, 1, length, file) != length) {
        return 4;
    }
    fclose(file);

    section_table = read_u32(data, 32);
    section_count = read_u16(data, 48);
    for (index = 0; index < section_count; ++index) {
        section = section_table + index * 40;
        if (read_u32(data, section + 4) == 11) {
            dynamic_symbols = section;
        }
    }
    if (!dynamic_symbols) {
        return 5;
    }
    section = section_table + read_u32(data, dynamic_symbols + 24) * 40;
    strings = read_u32(data, section + 16);
    symbol = read_u32(data, dynamic_symbols + 16);
    symbol_end = symbol + read_u32(data, dynamic_symbols + 20);
    while (symbol < symbol_end) {
        if (generated_symbol((char *)data + strings + read_u32(data, symbol))) {
            data[symbol + 12] &= 15; /* Preserve type, clear global binding. */
        }
        symbol += 16;
    }

    file = fopen(argv[1], "wb");
    if (!file || fwrite(data, 1, length, file) != length) {
        return 6;
    }
    return fclose(file) != 0;
}
