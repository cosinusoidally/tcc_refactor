static int put_elf_str(Section *s, const char *sym)
{
    int offset, len;
    char *ptr;

    len = strlen(sym) + 1;
    offset = section_data_offset(s);
    ptr = section_ptr_add(s, len);
    memcpy(ptr, sym, len);
    return offset;
}

static void put_stabs(const char *str, int type, int other, int desc, int value)
{
}

static void put_stabn(int type, int other, int desc, int value)
{
}

static void put_stabd(int type, int other, int desc)
{
}

typedef struct ObjSym {
    Sym *sym;
    Section *sec;
    const char *name;
    unsigned long value;
    int name_offset;
    int shndx;
    int info;
    int index;
} ObjSym;

typedef struct ObjRel {
    Section *sec;
    unsigned long offset;
    int info;
} ObjRel;

static Section *section_for_addr(unsigned long addr, unsigned long *poff);
static int section_output_size(Section *sec);

static const char *obj_sym_name(Sym *sym)
{
    const char *name;
    char *buf;
    unsigned int v;
    int i, j;
    char digits[16];

    name = get_tok_str(sym->v, NULL);
    if (name)
        return name;

    buf = malloc(32);
    if (!buf)
        error("memory full");
    buf[0] = '.';
    buf[1] = 'L';
    buf[2] = '.';
    v = (unsigned int)sym->v;
    i = 0;
    do {
        digits[i++] = '0' + (v % 10);
        v = v / 10;
    } while (v);
    for (j = 0; j < i; j++)
        buf[3 + j] = digits[i - j - 1];
    buf[3 + i] = '\0';
    return buf;
}

static int obj_sym_info(Sym *sym)
{
    int bind;
    int type;

    if ((sym->t & VT_BTYPE) == VT_FUNC)
        type = STT_FUNC;
    else
        type = STT_OBJECT;
    if ((sym->t & VT_STATIC) || sym->v >= SYM_FIRST_ANOM)
        bind = STB_LOCAL;
    else
        bind = STB_GLOBAL;
    return ELF32_ST_INFO(bind, type);
}

static Section *obj_symbol_section(Sym *sym, unsigned long *poff)
{
    Section *sec;
    unsigned long raw;

    raw = (unsigned long)sym->c;
    sec = section_for_addr(raw, poff);
    if (sec)
        return sec;

    if (!(sym->r & VT_SYM))
        return NULL;

    if ((sym->t & VT_BTYPE) == VT_FUNC) {
        if (raw <= (unsigned long)section_output_size(text_section)) {
            *poff = raw;
            return text_section;
        }
    } else {
        if (raw <= (unsigned long)section_output_size(data_section)) {
            *poff = raw;
            return data_section;
        }
        if (raw <= bss_section->data_offset) {
            *poff = raw;
            return bss_section;
        }
    }
    return NULL;
}

static int section_output_size(Section *sec)
{
    return section_data_offset(sec);
}

static Section *section_for_addr(unsigned long addr, unsigned long *poff)
{
    Section *sec;
    unsigned int addr32, start32, end32;
    int size;

    addr32 = (unsigned int)addr;

    for (sec = first_section; sec; sec = sec->next) {
        size = section_output_size(sec);
        start32 = (unsigned int)sec->data;
        end32 = start32 + size;
        if (addr32 >= start32 && addr32 < end32) {
            *poff = addr32 - start32;
            return sec;
        }
    }
    return NULL;
}

static int sym_used_in_obj(Sym *sym);
static int obj_emit_sym(Sym *sym);
static int obj_global_sym_candidate(Sym *sym);
static void obj_add_sym(ObjSym *osyms, int *pnsyms, Sym *s);
static int obj_sym_already_added(ObjSym *osyms, int nsyms, Sym *sym, int sym_v);

static int obj_global_sym_candidate(Sym *sym)
{
    if (!(sym->r & VT_SYM))
        return 0;
    if (sym->v >= SYM_FIRST_ANOM)
        return 1;
    if (sym->t & VT_STATIC)
        return 1;
    return 0;
}

static int count_obj_syms(void)
{
    Sym *s;
    ObjReloc *p;
    int n;

    n = 0;
    if (experimental_object_mode && first_obj_reloc) {
        for (p = first_obj_reloc; p; p = p->next) {
            ObjReloc *q;

            if (!p->sym || !obj_emit_sym(p->sym))
                continue;
            for (q = first_obj_reloc; q != p; q = q->next) {
                if (q->sym == p->sym || q->sym_v == p->sym_v)
                    break;
            }
            if (q == p)
                n++;
        }
    }
    for (s = extern_stack.top; s; s = s->prev) {
        if (experimental_object_mode && !obj_emit_sym(s))
            continue;
        n++;
    }
    if (experimental_object_mode) {
        for (s = global_stack.top; s; s = s->prev) {
            if (!obj_global_sym_candidate(s))
                continue;
            if (!obj_emit_sym(s))
                continue;
            n++;
        }
    }
    return n;
}

static int count_obj_relocs(void)
{
    Sym *s;
    Reloc *rp;
    ObjReloc *p;
    int n;

    if (!first_obj_reloc) {
        n = 0;
        for (s = extern_stack.top; s; s = s->prev) {
            if (!(s->r & VT_FORWARD))
                continue;
            for (rp = (Reloc *)s->c; rp; rp = rp->next)
                n++;
        }
        return n;
    }

    n = 0;
    for (p = first_obj_reloc; p; p = p->next)
        n++;
    return n;
}

static int map_reloc_type(int type)
{
    if (type == RELOC_REL32)
        return R_386_PC32;
    return R_386_32;
}

static int sym_used_in_obj(Sym *sym)
{
    Reloc *rp;
    ObjReloc *p;

    if (experimental_object_mode) {
        for (p = first_obj_reloc; p; p = p->next) {
            if (p->sym == sym || p->sym_v == sym->v)
                return 1;
        }
        return 0;
    }

    for (rp = (Reloc *)sym->c; rp; rp = rp->next)
        return 1;
    return 0;
}

static int obj_emit_sym(Sym *sym)
{
    unsigned long off;

    if (sym->r & VT_FORWARD)
        return sym_used_in_obj(sym);

    return obj_symbol_section(sym, &off) != NULL;
}

static void fill_obj_syms(ObjSym *osyms, int *pnsyms)
{
    Sym *s;
    ObjReloc *p;
    int n;

    n = 0;
    if (experimental_object_mode) {
        if (first_obj_reloc) {
            for (p = first_obj_reloc; p; p = p->next) {
                if (!p->sym || !obj_emit_sym(p->sym))
                    continue;
                if (obj_sym_already_added(osyms, n, p->sym, p->sym_v))
                    continue;
                obj_add_sym(osyms, &n, p->sym);
            }
        }
        for (s = global_stack.top; s; s = s->prev) {
            if (!obj_global_sym_candidate(s))
                continue;
            if (!obj_emit_sym(s))
                continue;
            if (obj_sym_already_added(osyms, n, s, s->v))
                continue;
            obj_add_sym(osyms, &n, s);
        }
        for (s = extern_stack.top; s; s = s->prev) {
            if (!obj_emit_sym(s))
                continue;
            if (ELF32_ST_BIND(obj_sym_info(s)) != STB_LOCAL)
                continue;
            if (obj_sym_already_added(osyms, n, s, s->v))
                continue;
            obj_add_sym(osyms, &n, s);
        }
    }
    for (s = extern_stack.top; s; s = s->prev) {
        if (experimental_object_mode && !obj_emit_sym(s))
            continue;
        if (experimental_object_mode &&
            ELF32_ST_BIND(obj_sym_info(s)) == STB_LOCAL)
            continue;
        if (experimental_object_mode &&
            obj_sym_already_added(osyms, n, s, s->v))
            continue;
        obj_add_sym(osyms, &n, s);
    }
    *pnsyms = n;
}

static int obj_sym_already_added(ObjSym *osyms, int nsyms, Sym *sym, int sym_v)
{
    int i;

    for (i = 0; i < nsyms; i++) {
        if (osyms[i].sym == sym || osyms[i].sym->v == sym_v)
            return 1;
    }
    return 0;
}

static void obj_add_sym(ObjSym *osyms, int *pnsyms, Sym *s)
{
    ObjSym *os;
    unsigned long off;
    Section *sec;

    os = &osyms[*pnsyms];
    memset(os, 0, sizeof(*os));
    os->sym = s;
    if (experimental_object_mode)
        os->name = obj_sym_name(s);
    else
        os->name = get_tok_str(s->v, NULL);
    os->index = *pnsyms + 1;
    if (s->r & VT_FORWARD) {
        os->shndx = SHN_UNDEF;
        if (experimental_object_mode)
            os->info = obj_sym_info(s);
        else
            os->info = ELF32_ST_INFO(STB_GLOBAL, STT_NOTYPE);
        os->value = 0;
    } else {
        if (experimental_object_mode)
            sec = obj_symbol_section(s, &off);
        else
            sec = section_for_addr((unsigned long)s->c, &off);
        os->sec = sec;
        os->value = off;
        if (sec)
            os->shndx = sec->sh_num;
        else if (experimental_object_mode)
            os->shndx = SHN_UNDEF;
        else
            os->shndx = SHN_ABS;
        if (experimental_object_mode)
            os->info = obj_sym_info(s);
        else
            os->info = ELF32_ST_INFO(STB_GLOBAL,
                                     (s->t & VT_FUNC) ? STT_FUNC : STT_OBJECT);
    }
    (*pnsyms)++;
}

static int find_obj_sym_index(ObjSym *osyms, int nsyms, Sym *sym, int sym_v)
{
    int i;

    for (i = 0; i < nsyms; i++) {
        if (osyms[i].sym == sym || osyms[i].sym->v == sym_v)
            return osyms[i].index;
    }
    return 0;
}

static void fill_obj_relocs(ObjRel *orels, int *pnrels, ObjSym *osyms, int nsyms)
{
    Sym *s;
    Reloc *rp;
    ObjReloc *p;
    int n;

    if (!first_obj_reloc) {
        n = 0;
        for (s = extern_stack.top; s; s = s->prev) {
            int sym_index;

            if (!(s->r & VT_FORWARD))
                continue;
            sym_index = find_obj_sym_index(osyms, nsyms, s, s->v);
            for (rp = (Reloc *)s->c; rp; rp = rp->next) {
                unsigned long off;
                Section *sec;
                ObjRel *or;

                sec = section_for_addr((unsigned long)rp->addr, &off);
                if (!sec)
                    continue;
                or = &orels[n++];
                or->sec = sec;
                or->offset = off;
                or->info = ELF32_R_INFO(sym_index, map_reloc_type(rp->type));
            }
        }
        *pnrels = n;
        return;
    }

    n = 0;
    for (p = first_obj_reloc; p; p = p->next) {
        int sym_index;
        unsigned long off;
        ObjRel *or;
        Section *sec;

        sym_index = find_obj_sym_index(osyms, nsyms, p->sym, p->sym_v);
        if (!sym_index)
            continue;
        sec = section_for_addr(p->addr, &off);
        if (!sec)
            continue;
        or = &orels[n++];
        or->sec = sec;
        or->offset = off;
        or->info = ELF32_R_INFO(sym_index, map_reloc_type(p->type));
    }
    *pnrels = n;
}

static int write_padding(FILE *f, long cur, long target)
{
    while (cur < target) {
        fputc(0, f);
        cur++;
    }
    return cur;
}

int tcc_output_file(TCCState *s1, const char *filename)
{
    enum {
        SEC_NULL,
        SEC_TEXT,
        SEC_DATA,
        SEC_BSS,
        SEC_SYMTAB,
        SEC_STRTAB,
        SEC_REL_TEXT,
        SEC_REL_DATA,
        SEC_SHSTRTAB,
        SEC_COUNT
    };
    Elf32_Ehdr ehdr;
    Elf32_Shdr shdr[SEC_COUNT];
    Elf32_Sym sym;
    Elf32_Rel rel;
    ObjSym *osyms;
    ObjRel *orels;
    FILE *f;
    Section shstr;
    Section strtab;
    int nsyms, nrels, i;
    long off;
    int have_rel_text, have_rel_data;
    int text_size, data_size, bss_size;
    int symtab_size;
    int local_syms;

    memset(&shstr, 0, sizeof(shstr));
    memset(&strtab, 0, sizeof(strtab));
    memset(&ehdr, 0, sizeof(ehdr));
    memset(shdr, 0, sizeof(shdr));
    if (experimental_object_mode) {
        puts("writing experimental object");
        printf("obj reloc count %d\n", obj_reloc_count);
    }

    shstr.data = malloc(4096);
    strtab.data = malloc(65536);
    if (!shstr.data || !strtab.data)
        error("memory full");
    shstr.data_ptr = shstr.data;
    strtab.data_ptr = strtab.data;
    shstr.data_allocated = 4096;
    strtab.data_allocated = 65536;

    put_elf_str(&shstr, "");
    put_elf_str(&strtab, "");

    osyms = malloc(sizeof(ObjSym) * count_obj_syms());
    orels = malloc(sizeof(ObjRel) * count_obj_relocs());
    if ((!osyms && count_obj_syms()) || (!orels && count_obj_relocs()))
        error("memory full");

    fill_obj_syms(osyms, &nsyms);
    fill_obj_relocs(orels, &nrels, osyms, nsyms);
    local_syms = 0;
    if (experimental_object_mode) {
        for (i = 0; i < nsyms; i++) {
            if (ELF32_ST_BIND(osyms[i].info) == STB_LOCAL)
                local_syms++;
        }
    }

    have_rel_text = 0;
    have_rel_data = 0;
    for (i = 0; i < nrels; i++) {
        if (orels[i].sec == text_section)
            have_rel_text = 1;
        else if (orels[i].sec == data_section)
            have_rel_data = 1;
    }

    text_size = section_output_size(text_section);
    data_size = section_output_size(data_section);
    bss_size = section_output_size(bss_section);
    symtab_size = (nsyms + 1) * sizeof(Elf32_Sym);

    shdr[SEC_TEXT].sh_name = put_elf_str(&shstr, ".text");
    shdr[SEC_TEXT].sh_type = SHT_PROGBITS;
    shdr[SEC_TEXT].sh_flags = SHF_ALLOC | SHF_EXECINSTR;
    shdr[SEC_TEXT].sh_addralign = 16;
    shdr[SEC_TEXT].sh_size = text_size;

    shdr[SEC_DATA].sh_name = put_elf_str(&shstr, ".data");
    shdr[SEC_DATA].sh_type = SHT_PROGBITS;
    shdr[SEC_DATA].sh_flags = SHF_ALLOC | SHF_WRITE;
    shdr[SEC_DATA].sh_addralign = 16;
    shdr[SEC_DATA].sh_size = data_size;

    shdr[SEC_BSS].sh_name = put_elf_str(&shstr, ".bss");
    shdr[SEC_BSS].sh_type = SHT_NOBITS;
    shdr[SEC_BSS].sh_flags = SHF_ALLOC | SHF_WRITE;
    shdr[SEC_BSS].sh_addralign = 16;
    shdr[SEC_BSS].sh_size = bss_size;

    shdr[SEC_SYMTAB].sh_name = put_elf_str(&shstr, ".symtab");
    shdr[SEC_SYMTAB].sh_type = SHT_SYMTAB;
    shdr[SEC_SYMTAB].sh_addralign = 4;
    shdr[SEC_SYMTAB].sh_entsize = sizeof(Elf32_Sym);
    shdr[SEC_SYMTAB].sh_link = SEC_STRTAB;
    shdr[SEC_SYMTAB].sh_info = experimental_object_mode ? (local_syms + 1) : 1;
    shdr[SEC_SYMTAB].sh_size = symtab_size;

    shdr[SEC_STRTAB].sh_name = put_elf_str(&shstr, ".strtab");
    shdr[SEC_STRTAB].sh_type = SHT_STRTAB;
    shdr[SEC_STRTAB].sh_addralign = 1;

    if (have_rel_text) {
        shdr[SEC_REL_TEXT].sh_name = put_elf_str(&shstr, ".rel.text");
        shdr[SEC_REL_TEXT].sh_type = SHT_REL;
        shdr[SEC_REL_TEXT].sh_addralign = 4;
        shdr[SEC_REL_TEXT].sh_entsize = sizeof(Elf32_Rel);
        shdr[SEC_REL_TEXT].sh_link = SEC_SYMTAB;
        shdr[SEC_REL_TEXT].sh_info = SEC_TEXT;
    }

    if (have_rel_data) {
        shdr[SEC_REL_DATA].sh_name = put_elf_str(&shstr, ".rel.data");
        shdr[SEC_REL_DATA].sh_type = SHT_REL;
        shdr[SEC_REL_DATA].sh_addralign = 4;
        shdr[SEC_REL_DATA].sh_entsize = sizeof(Elf32_Rel);
        shdr[SEC_REL_DATA].sh_link = SEC_SYMTAB;
        shdr[SEC_REL_DATA].sh_info = SEC_DATA;
    }

    shdr[SEC_SHSTRTAB].sh_name = put_elf_str(&shstr, ".shstrtab");
    shdr[SEC_SHSTRTAB].sh_type = SHT_STRTAB;
    shdr[SEC_SHSTRTAB].sh_addralign = 1;

    for (i = 0; i < nsyms; i++)
        osyms[i].name_offset = put_elf_str(&strtab, osyms[i].name);

    shdr[SEC_STRTAB].sh_size = section_output_size(&strtab);
    shdr[SEC_REL_TEXT].sh_size = 0;
    shdr[SEC_REL_DATA].sh_size = 0;
    for (i = 0; i < nrels; i++) {
        if (orels[i].sec == text_section)
            shdr[SEC_REL_TEXT].sh_size += sizeof(Elf32_Rel);
        else if (orels[i].sec == data_section)
            shdr[SEC_REL_DATA].sh_size += sizeof(Elf32_Rel);
    }
    shdr[SEC_SHSTRTAB].sh_size = section_output_size(&shstr);

    off = sizeof(Elf32_Ehdr);
    for (i = 1; i < SEC_COUNT; i++) {
        int align;

        if (!shdr[i].sh_type)
            continue;
        if (shdr[i].sh_type == SHT_NOBITS)
            continue;
        align = shdr[i].sh_addralign ? shdr[i].sh_addralign : 1;
        off = (off + align - 1) & -align;
        shdr[i].sh_offset = off;
        off += shdr[i].sh_size;
    }
    ehdr.e_shoff = (off + 3) & -4;

    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASS32;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;
    ehdr.e_type = ET_REL;
    ehdr.e_machine = EM_386;
    ehdr.e_version = EV_CURRENT;
    ehdr.e_ehsize = sizeof(Elf32_Ehdr);
    ehdr.e_shentsize = sizeof(Elf32_Shdr);
    ehdr.e_shnum = SEC_COUNT;
    ehdr.e_shstrndx = SEC_SHSTRTAB;

    f = fopen(filename, "wb");
    if (!f)
        return -1;
    fwrite(&ehdr, 1, sizeof(ehdr), f);
    off = sizeof(Elf32_Ehdr);

    off = write_padding(f, off, shdr[SEC_TEXT].sh_offset);
    fwrite(text_section->data, 1, text_size, f);
    off += text_size;

    off = write_padding(f, off, shdr[SEC_DATA].sh_offset);
    fwrite(data_section->data, 1, data_size, f);
    off += data_size;

    off = write_padding(f, off, shdr[SEC_SYMTAB].sh_offset);
    memset(&sym, 0, sizeof(sym));
    fwrite(&sym, 1, sizeof(sym), f);
    off += sizeof(sym);
    for (i = 0; i < nsyms; i++) {
        memset(&sym, 0, sizeof(sym));
        sym.st_name = osyms[i].name_offset;
        sym.st_value = osyms[i].value;
        sym.st_size = 0;
        sym.st_info = osyms[i].info;
        sym.st_other = 0;
        sym.st_shndx = osyms[i].shndx;
        fwrite(&sym, 1, sizeof(sym), f);
        off += sizeof(sym);
    }

    off = write_padding(f, off, shdr[SEC_STRTAB].sh_offset);
    fwrite(strtab.data, 1, shdr[SEC_STRTAB].sh_size, f);
    off += shdr[SEC_STRTAB].sh_size;

    if (have_rel_text) {
        off = write_padding(f, off, shdr[SEC_REL_TEXT].sh_offset);
        for (i = 0; i < nrels; i++) {
            if (orels[i].sec != text_section)
                continue;
            rel.r_offset = orels[i].offset;
            rel.r_info = orels[i].info;
            fwrite(&rel, 1, sizeof(rel), f);
            off += sizeof(rel);
        }
    }

    if (have_rel_data) {
        off = write_padding(f, off, shdr[SEC_REL_DATA].sh_offset);
        for (i = 0; i < nrels; i++) {
            if (orels[i].sec != data_section)
                continue;
            rel.r_offset = orels[i].offset;
            rel.r_info = orels[i].info;
            fwrite(&rel, 1, sizeof(rel), f);
            off += sizeof(rel);
        }
    }

    off = write_padding(f, off, shdr[SEC_SHSTRTAB].sh_offset);
    fwrite(shstr.data, 1, shdr[SEC_SHSTRTAB].sh_size, f);
    off += shdr[SEC_SHSTRTAB].sh_size;

    off = write_padding(f, off, ehdr.e_shoff);
    fwrite(shdr, 1, sizeof(shdr), f);
    fclose(f);

    free(shstr.data);
    free(strtab.data);
    free(osyms);
    free(orels);
    return 0;
}
