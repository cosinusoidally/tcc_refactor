/*
 *  ELF file handling for TCC
 *
 *  Copyright (c) 2001-2004 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "tcc.h"

/* Define this to get some debug output during relocation processing.  */
#undef DEBUG_RELOC

/********************************************************/
/* global variables */

ST_DATA Section *text_section, *data_section, *bss_section; /* predefined sections */
ST_DATA Section *common_section;
ST_DATA Section *cur_text_section; /* current section where function code is generated */
#ifdef CONFIG_TCC_ASM
ST_DATA Section *last_text_section; /* to handle .previous asm directive */
#endif
#ifdef CONFIG_TCC_BCHECK
/* bound check related sections */
ST_DATA Section *bounds_section; /* contains global data bound description */
ST_DATA Section *lbounds_section; /* contains local data bound description */
#endif
/* symbol sections */
ST_DATA Section *symtab_section;
/* debug sections */
ST_DATA Section *stab_section, *stabstr_section;

/* XXX: avoid static variable */
/* special flag to indicate that the section should not be linked to the other ones */
#define SHF_PRIVATE 0x80000000
/* section is dynsymtab_section */
#define SHF_DYNSYM 0x40000000

/* ------------------------------------------------------------------------- */

ST_FUNC void tccelf_new(TCCState *s)
{
    cc2_bind_tcc_globals(s);
    /* no section zero */
    dynarray_add(&s->sections, &s->nb_sections, NULL);

    /* create standard sections */
    text_section = new_section(s, ".text", SHT_PROGBITS, SHF_ALLOC | SHF_EXECINSTR);
    data_section = new_section(s, ".data", SHT_PROGBITS, SHF_ALLOC | SHF_WRITE);
    bss_section = new_section(s, ".bss", SHT_NOBITS, SHF_ALLOC | SHF_WRITE);
    common_section = new_section(s, ".common", SHT_NOBITS, SHF_PRIVATE);
    common_section->sh_num = SHN_COMMON;

    /* symbols are always generated for linking stage */
    symtab_section = new_symtab(s, ".symtab", SHT_SYMTAB, 0,
                                ".strtab",
                                ".hashtab", SHF_PRIVATE);
    s->symtab = symtab_section;

    /* private symbol table for dynamic symbols */
    s->dynsymtab_section = new_symtab(s, ".dynsymtab", SHT_SYMTAB, SHF_PRIVATE|SHF_DYNSYM,
                                      ".dynstrtab",
                                      ".dynhashtab", SHF_PRIVATE);
    get_sym_attr(s, 0, 1);
}

#ifdef CONFIG_TCC_BCHECK
ST_FUNC void tccelf_bounds_new(TCCState *s)
{
    /* create bounds sections */
    bounds_section = new_section(s, ".bounds",
                                 SHT_PROGBITS, SHF_ALLOC);
    lbounds_section = new_section(s, ".lbounds",
                                  SHT_PROGBITS, SHF_ALLOC);
}
#endif

ST_FUNC void tccelf_stab_new(TCCState *s)
{
    stab_section = new_section(s, ".stab", SHT_PROGBITS, 0);
    stab_section->sh_entsize = sizeof(Stab_Sym);
    stabstr_section = new_section(s, ".stabstr", SHT_STRTAB, 0);
    put_elf_str(stabstr_section, "");
    stab_section->link = stabstr_section;
    /* put first entry */
    put_stabs("", 0, 0, 0, 0);
}

static void free_section(Section *s)
{
    tcc_free(s->data);
}

ST_FUNC void tccelf_delete(TCCState *s1)
{
    int i;

    /* free all sections */
    for(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);

    for(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);

    /* free any loaded DLLs */
#ifdef TCC_IS_NATIVE
    for ( i = 0; i < s1->nb_loaded_dlls; i++) {
        DLLReference *ref = s1->loaded_dlls[i];
        if ( ref->handle )
# ifdef _WIN32
            FreeLibrary((HMODULE)ref->handle);
# else
            dlclose(ref->handle);
# endif
    }
#endif
    /* free loaded dlls array */
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1->sym_attrs);

    symtab_section = NULL; /* for tccrun.c:rt_printline() */
}

/* return elf symbol value */
LIBTCCAPI void *tcc_get_symbol(TCCState *s, const char *name)
{
    return (void*)(uintptr_t)get_elf_sym_addr(s, name, 0);
}

#if defined TCC_IS_NATIVE || defined TCC_TARGET_PE
/* return elf symbol value or error */
ST_FUNC void* tcc_get_symbol_err(TCCState *s, const char *name)
{
    return (void*)(uintptr_t)get_elf_sym_addr(s, name, 1);
}
#endif

/* Browse each elem of type <type> in section <sec> starting at elem <startoff>
   using variable <elem> */
#define for_each_elem(sec, startoff, elem, type) \
    for (elem = (type *) sec->data + startoff; \
         elem < (type *) (sec->data + sec->data_offset); elem++)

/* In an ELF file symbol table, the local symbols must appear below
   the global and weak ones. Since TCC cannot sort it while generating
   the code, we must do it after. All the relocation tables are also
   modified to take into account the symbol table sorting */

static int tcc_add_support(TCCState *s1, const char *filename)
{
    char buf[1024];
    snprintf(buf, sizeof(buf), "%s/%s", s1->tcc_lib_path, filename);
    return tcc_add_file(s1, buf);
}

ST_FUNC void tcc_add_bcheck(TCCState *s1)
{
#ifdef CONFIG_TCC_BCHECK
    addr_t *ptr;
    int sym_index;

    if (0 == s1->do_bounds_check)
        return;
    /* XXX: add an object file to do that */
    ptr = section_ptr_add(bounds_section, sizeof(*ptr));
    *ptr = 0;
    set_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0,
                bounds_section->sh_num, "__bounds_start");
    /* pull bcheck.o from libtcc1.a */
    sym_index = set_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0,
                SHN_UNDEF, "__bound_init");
    if (s1->output_type != TCC_OUTPUT_MEMORY) {
        /* add 'call __bound_init()' in .init section */
        Section *init_section = find_section(s1, ".init");
        unsigned char *pinit = section_ptr_add(init_section, 5);
        pinit[0] = 0xe8;
        write32le(pinit + 1, -4);
        put_elf_reloc(symtab_section, init_section,
            init_section->data_offset - 4, R_386_PC32, sym_index);
            /* R_386_PC32 = R_X86_64_PC32 = 2 */
    }
#endif
}

/* add tcc runtime libraries */
ST_FUNC void tcc_add_runtime(TCCState *s1)
{
    tcc_add_bcheck(s1);
    tcc_add_pragma_libs(s1);
    /* add libc */
    if (!s1->nostdlib) {
        tcc_add_library_err(s1, "c");
#ifdef TCC_LIBGCC
        if (!s1->static_link) {
            if (TCC_LIBGCC[0] == '/')
                tcc_add_file(s1, TCC_LIBGCC);
            else
                tcc_add_dll(s1, TCC_LIBGCC, 0);
        }
#endif
        tcc_add_support(s1, TCC_LIBTCC1);
        /* add crt end if not memory output */
        if (s1->output_type != TCC_OUTPUT_MEMORY)
            tcc_add_crt(s1, "crtn.o");
    }
}

static void tcc_output_binary(TCCState *s1, FILE *f,
                              const int *sec_order)
{
    Section *s;
    int i, offset, size;

    offset = 0;
    for(i=1;i<s1->nb_sections;i++) {
        s = s1->sections[sec_order[i]];
        if (s->sh_type != SHT_NOBITS &&
            (s->sh_flags & SHF_ALLOC)) {
            while (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            fwrite(s->data, 1, size, f);
            offset += size;
        }
    }
}


/* Info to be copied in dynamic section */
struct dyn_inf {
    Section *dynamic;
    Section *dynstr;
    unsigned long data_offset;
    addr_t rel_addr;
    addr_t rel_size;
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    addr_t bss_addr;
    addr_t bss_size;
#endif
};

/* Assign sections to segments and decide how are sections laid out when loaded
   in memory. This function also fills corresponding program headers. */
static int layout_sections(TCCState *s1, ElfW(Phdr) *phdr, int phnum,
                           Section *interp, Section* strsec,
                           struct dyn_inf *dyninf, int *sec_order)
{
    int i, j, k, file_type, sh_order_index, file_offset;
    unsigned long s_align;
    long long tmp;
    addr_t addr;
    ElfW(Phdr) *ph;
    Section *s;

    file_type = s1->output_type;
    sh_order_index = 1;
    file_offset = 0;
    if (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        file_offset = sizeof(ElfW(Ehdr)) + phnum * sizeof(ElfW(Phdr));
    s_align = ELF_PAGE_SIZE;
    if (s1->section_align)
        s_align = s1->section_align;

    if (phnum > 0) {
        if (s1->has_text_addr) {
            int a_offset, p_offset;
            addr = s1->text_addr;
            /* we ensure that (addr % ELF_PAGE_SIZE) == file_offset %
               ELF_PAGE_SIZE */
            a_offset = (int) (addr & (s_align - 1));
            p_offset = file_offset & (s_align - 1);
            if (a_offset < p_offset)
                a_offset += s_align;
            file_offset += (a_offset - p_offset);
        } else {
            if (file_type == TCC_OUTPUT_DLL)
                addr = 0;
            else
                addr = ELF_START_ADDR;
            /* compute address after headers */
            addr += (file_offset & (s_align - 1));
        }

        ph = &phdr[0];
        /* Leave one program headers for the program interpreter and one for
           the program header table itself if needed. These are done later as
           they require section layout to be done first. */
        if (interp)
            ph += 2;

        /* dynamic relocation table information, for .dynamic section */
        dyninf->rel_addr = dyninf->rel_size = 0;
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
        dyninf->bss_addr = dyninf->bss_size = 0;
#endif

        for(j = 0; j < 2; j++) {
            ph->p_type = PT_LOAD;
            if (j == 0)
                ph->p_flags = PF_R | PF_X;
            else
                ph->p_flags = PF_R | PF_W;
            ph->p_align = s_align;

            /* Decide the layout of sections loaded in memory. This must
               be done before program headers are filled since they contain
               info about the layout. We do the following ordering: interp,
               symbol tables, relocations, progbits, nobits */
            /* XXX: do faster and simpler sorting */
            for(k = 0; k < 5; k++) {
                for(i = 1; i < s1->nb_sections; i++) {
                    s = s1->sections[i];
                    /* compute if section should be included */
                    if (j == 0) {
                        if ((s->sh_flags & (SHF_ALLOC | SHF_WRITE)) !=
                            SHF_ALLOC)
                            continue;
                    } else {
                        if ((s->sh_flags & (SHF_ALLOC | SHF_WRITE)) !=
                            (SHF_ALLOC | SHF_WRITE))
                            continue;
                    }
                    if (s == interp) {
                        if (k != 0)
                            continue;
                    } else if (s->sh_type == SHT_DYNSYM ||
                               s->sh_type == SHT_STRTAB ||
                               s->sh_type == SHT_HASH) {
                        if (k != 1)
                            continue;
                    } else if (s->sh_type == SHT_RELX) {
                        if (k != 2)
                            continue;
                    } else if (s->sh_type == SHT_NOBITS) {
                        if (k != 4)
                            continue;
                    } else {
                        if (k != 3)
                            continue;
                    }
                    sec_order[sh_order_index++] = i;

                    /* section matches: we align it and add its size */
                    tmp = addr;
                    addr = (addr + s->sh_addralign - 1) &
                        ~(s->sh_addralign - 1);
                    file_offset += (int) ( addr - tmp );
                    s->sh_offset = file_offset;
                    s->sh_addr = addr;

                    /* update program header infos */
                    if (ph->p_offset == 0) {
                        ph->p_offset = file_offset;
                        ph->p_vaddr = addr;
                        ph->p_paddr = ph->p_vaddr;
                    }
                    /* update dynamic relocation infos */
                    if (s->sh_type == SHT_RELX) {
#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
                        if (!strcmp(strsec->data + s->sh_name, ".rel.got")) {
                            dyninf->rel_addr = addr;
                            dyninf->rel_size += s->sh_size; /* XXX only first rel. */
                        }
                        if (!strcmp(strsec->data + s->sh_name, ".rel.bss")) {
                            dyninf->bss_addr = addr;
                            dyninf->bss_size = s->sh_size; /* XXX only first rel. */
                        }
#else
                        if (dyninf->rel_size == 0)
                            dyninf->rel_addr = addr;
                        dyninf->rel_size += s->sh_size;
#endif
                    }
                    addr += s->sh_size;
                    if (s->sh_type != SHT_NOBITS)
                        file_offset += s->sh_size;
                }
            }
	    if (j == 0) {
		/* Make the first PT_LOAD segment include the program
		   headers itself (and the ELF header as well), it'll
		   come out with same memory use but will make various
		   tools like binutils strip work better.  */
		ph->p_offset &= ~(ph->p_align - 1);
		ph->p_vaddr &= ~(ph->p_align - 1);
		ph->p_paddr &= ~(ph->p_align - 1);
	    }
            ph->p_filesz = file_offset - ph->p_offset;
            ph->p_memsz = addr - ph->p_vaddr;
            ph++;
            if (j == 0) {
                if (s1->output_format == TCC_OUTPUT_FORMAT_ELF) {
                    /* if in the middle of a page, we duplicate the page in
                       memory so that one copy is RX and the other is RW */
                    if ((addr & (s_align - 1)) != 0)
                        addr += s_align;
                } else {
                    addr = (addr + s_align - 1) & ~(s_align - 1);
                    file_offset = (file_offset + s_align - 1) & ~(s_align - 1);
                }
            }
        }
    }

    /* all other sections come after */
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        if (phnum > 0 && (s->sh_flags & SHF_ALLOC))
            continue;
        sec_order[sh_order_index++] = i;

        file_offset = (file_offset + s->sh_addralign - 1) &
            ~(s->sh_addralign - 1);
        s->sh_offset = file_offset;
        if (s->sh_type != SHT_NOBITS)
            file_offset += s->sh_size;
    }

    return file_offset;
}

static void fill_unloadable_phdr(ElfW(Phdr) *phdr, int phnum, Section *interp,
                                 Section *dynamic)
{
    ElfW(Phdr) *ph;

    /* if interpreter, then add corresponding program header */
    if (interp) {
        ph = &phdr[0];

        ph->p_type = PT_PHDR;
        ph->p_offset = sizeof(ElfW(Ehdr));
        ph->p_filesz = ph->p_memsz = phnum * sizeof(ElfW(Phdr));
        ph->p_vaddr = interp->sh_addr - ph->p_filesz;
        ph->p_paddr = ph->p_vaddr;
        ph->p_flags = PF_R | PF_X;
        ph->p_align = 4; /* interp->sh_addralign; */
        ph++;

        ph->p_type = PT_INTERP;
        ph->p_offset = interp->sh_offset;
        ph->p_vaddr = interp->sh_addr;
        ph->p_paddr = ph->p_vaddr;
        ph->p_filesz = interp->sh_size;
        ph->p_memsz = interp->sh_size;
        ph->p_flags = PF_R;
        ph->p_align = interp->sh_addralign;
    }

    /* if dynamic section, then add corresponding program header */
    if (dynamic) {
        ph = &phdr[phnum - 1];

        ph->p_type = PT_DYNAMIC;
        ph->p_offset = dynamic->sh_offset;
        ph->p_vaddr = dynamic->sh_addr;
        ph->p_paddr = ph->p_vaddr;
        ph->p_filesz = dynamic->sh_size;
        ph->p_memsz = dynamic->sh_size;
        ph->p_flags = PF_R | PF_W;
        ph->p_align = dynamic->sh_addralign;
    }
}

/* Relocate remaining sections and symbols (that is those not related to
   dynamic linking) */
static int final_sections_reloc(TCCState *s1)
{
    int i;
    Section *s;

    relocate_syms(s1, s1->symtab, 0);

    if (s1->nb_errors != 0)
        return -1;

    /* relocate sections */
    /* XXX: ignore sections with allocated relocations ? */
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
#if defined(TCC_TARGET_I386) || defined(TCC_MUSL)
        if (s->reloc && s != s1->got && (s->sh_flags & SHF_ALLOC)) //gr
        /* On X86 gdb 7.3 works in any case but gdb 6.6 will crash if SHF_ALLOC
        checking is removed */
#else
        if (s->reloc && s != s1->got)
        /* On X86_64 gdb 7.3 will crash if SHF_ALLOC checking is present */
#endif
            relocate_section(s1, s);
    }

    /* relocate relocation entries if the relocation tables are
       allocated in the executable */
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        if ((s->sh_flags & SHF_ALLOC) &&
            s->sh_type == SHT_RELX) {
            relocate_rel(s1, s);
        }
    }
    return 0;
}

/* Create an ELF file on disk.
   This function handle ELF specific layout requirements */
static void tcc_output_elf(TCCState *s1, FILE *f, int phnum, ElfW(Phdr) *phdr,
                           int file_offset, int *sec_order)
{
    int i, shnum, offset, size, file_type;
    Section *s;
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) shdr, *sh;

    file_type = s1->output_type;
    shnum = s1->nb_sections;

    memset(&ehdr, 0, sizeof(ehdr));

    if (phnum > 0) {
        ehdr.e_phentsize = sizeof(ElfW(Phdr));
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = sizeof(ElfW(Ehdr));
    }

    /* align to 4 */
    file_offset = (file_offset + 3) & -4;

    /* fill header */
    ehdr.e_ident[0] = ELFMAG0;
    ehdr.e_ident[1] = ELFMAG1;
    ehdr.e_ident[2] = ELFMAG2;
    ehdr.e_ident[3] = ELFMAG3;
    ehdr.e_ident[4] = ELFCLASSW;
    ehdr.e_ident[5] = ELFDATA2LSB;
    ehdr.e_ident[6] = EV_CURRENT;
#if !defined(TCC_TARGET_PE) && (defined(__FreeBSD__) || defined(__FreeBSD_kernel__))
    /* FIXME: should set only for freebsd _target_, but we exclude only PE target */
    ehdr.e_ident[EI_OSABI] = ELFOSABI_FREEBSD;
#endif
#ifdef TCC_TARGET_ARM
#ifdef TCC_ARM_EABI
    ehdr.e_ident[EI_OSABI] = 0;
    ehdr.e_flags = EF_ARM_EABI_VER4;
    if (file_type == TCC_OUTPUT_EXE || file_type == TCC_OUTPUT_DLL)
        ehdr.e_flags |= EF_ARM_HASENTRY;
    if (s1->float_abi == ARM_HARD_FLOAT)
        ehdr.e_flags |= EF_ARM_VFP_FLOAT;
    else
        ehdr.e_flags |= EF_ARM_SOFT_FLOAT;
#else
    ehdr.e_ident[EI_OSABI] = ELFOSABI_ARM;
#endif
#endif
    switch(file_type) {
    default:
    case TCC_OUTPUT_EXE:
        ehdr.e_type = ET_EXEC;
        ehdr.e_entry = get_elf_sym_addr(s1, "_start", 1);
        break;
    case TCC_OUTPUT_DLL:
        ehdr.e_type = ET_DYN;
        ehdr.e_entry = text_section->sh_addr; /* XXX: is it correct ? */
        break;
    case TCC_OUTPUT_OBJ:
        ehdr.e_type = ET_REL;
        break;
    }
    ehdr.e_machine = EM_TCC_TARGET;
    ehdr.e_version = EV_CURRENT;
    ehdr.e_shoff = file_offset;
    ehdr.e_ehsize = sizeof(ElfW(Ehdr));
    ehdr.e_shentsize = sizeof(ElfW(Shdr));
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;

    fwrite(&ehdr, 1, sizeof(ElfW(Ehdr)), f);
    fwrite(phdr, 1, phnum * sizeof(ElfW(Phdr)), f);
    offset = sizeof(ElfW(Ehdr)) + phnum * sizeof(ElfW(Phdr));

    sort_syms(s1, symtab_section);
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        if (s->sh_type != SHT_NOBITS) {
            while (offset < s->sh_offset) {
                fputc(0, f);
                offset++;
            }
            size = s->sh_size;
            if (size)
                fwrite(s->data, 1, size, f);
            offset += size;
        }
    }

    /* output section headers */
    while (offset < ehdr.e_shoff) {
        fputc(0, f);
        offset++;
    }

    for(i = 0; i < s1->nb_sections; i++) {
        sh = &shdr;
        memset(sh, 0, sizeof(ElfW(Shdr)));
        s = s1->sections[i];
        if (s) {
            sh->sh_name = s->sh_name;
            sh->sh_type = s->sh_type;
            sh->sh_flags = s->sh_flags;
            sh->sh_entsize = s->sh_entsize;
            sh->sh_info = s->sh_info;
            if (s->link)
                sh->sh_link = s->link->sh_num;
            sh->sh_addralign = s->sh_addralign;
            sh->sh_addr = s->sh_addr;
            sh->sh_offset = s->sh_offset;
            sh->sh_size = s->sh_size;
        }
        fwrite(sh, 1, sizeof(ElfW(Shdr)), f);
    }
}

/* Write an elf, coff or "binary" file */
static int tcc_write_elf_file(TCCState *s1, const char *filename, int phnum,
                              ElfW(Phdr) *phdr, int file_offset, int *sec_order)
{
    int fd, mode, file_type;
    FILE *f;

    file_type = s1->output_type;
    if (file_type == TCC_OUTPUT_OBJ)
        mode = 0666;
    else
        mode = 0777;
    unlink(filename);
/* LJW HACK remove use of fdopen
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, mode);
    if (fd < 0) {
        tcc_error_noabort("could not write '%s'", filename);
        return -1;
    }
    f = fdopen(fd, "wb");
*/
    f = fopen(filename, "wb");

    if (s1->verbose)
        printf("<- %s\n", filename);

#ifdef TCC_TARGET_COFF
    if (s1->output_format == TCC_OUTPUT_FORMAT_COFF)
        tcc_output_coff(s1, f);
    else
#endif
    if (s1->output_format == TCC_OUTPUT_FORMAT_ELF)
        tcc_output_elf(s1, f, phnum, phdr, file_offset, sec_order);
    else
        tcc_output_binary(s1, f, sec_order);
    fclose(f);

    return 0;
}

/* Sort section headers by assigned sh_addr, remove sections
   that we aren't going to output.  */
static void tidy_section_headers(TCCState *s1, int *sec_order)
{
    int i, nnew, l, *backmap;
    Section **snew, *s;
    ElfW(Sym) *sym;

    snew = tcc_malloc(s1->nb_sections * sizeof(snew[0]));
    backmap = tcc_malloc(s1->nb_sections * sizeof(backmap[0]));
    for (i = 0, nnew = 0, l = s1->nb_sections; i < s1->nb_sections; i++) {
	s = s1->sections[sec_order[i]];
	if (!i || s->sh_name) {
	    backmap[sec_order[i]] = nnew;
	    snew[nnew] = s;
	    ++nnew;
	} else {
	    backmap[sec_order[i]] = 0;
	    snew[--l] = s;
	}
    }
    for (i = 0; i < nnew; i++) {
	s = snew[i];
	if (s) {
	    s->sh_num = i;
            if (s->sh_type == SHT_RELX)
		s->sh_info = backmap[s->sh_info];
	}
    }

    for_each_elem(symtab_section, 1, sym, ElfW(Sym))
	if (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE)
	    sym->st_shndx = backmap[sym->st_shndx];
    if( !s1->static_link ) {
        for_each_elem(s1->dynsym, 1, sym, ElfW(Sym))
	    if (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE)
	        sym->st_shndx = backmap[sym->st_shndx];
    }
    for (i = 0; i < s1->nb_sections; i++)
	sec_order[i] = i;
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}

/* Output an elf, coff or binary file */
/* XXX: suppress unneeded sections */
static int elf_output_file(TCCState *s1, const char *filename)
{
    int i, ret, phnum, shnum, file_type, file_offset, *sec_order;
    struct dyn_inf dyninf = {0};
    ElfW(Phdr) *phdr;
    ElfW(Sym) *sym;
    Section *strsec, *interp, *dynamic, *dynstr;
    int textrel;

    file_type = s1->output_type;
    s1->nb_errors = 0;
    ret = -1;
    phdr = NULL;
    sec_order = NULL;
    interp = dynamic = dynstr = NULL; /* avoid warning */
    textrel = 0;

    if (file_type != TCC_OUTPUT_OBJ) {
        /* if linking, also link in runtime libraries (libc, libgcc, etc.) */
        tcc_add_runtime(s1);
	resolve_common_syms(s1);

        if (!s1->static_link) {
            if (file_type == TCC_OUTPUT_EXE) {
                char *ptr;
                /* allow override the dynamic loader */
                const char *elfint = getenv("LD_SO");
                if (elfint == NULL)
                    elfint = DEFAULT_ELFINTERP(s1);
                /* add interpreter section only if executable */
                interp = new_section(s1, ".interp", SHT_PROGBITS, SHF_ALLOC);
                interp->sh_addralign = 1;
                ptr = section_ptr_add(interp, 1 + strlen(elfint));
                strcpy(ptr, elfint);
            }

            /* add dynamic symbol table */
            s1->dynsym = new_symtab(s1, ".dynsym", SHT_DYNSYM, SHF_ALLOC,
                                    ".dynstr",
                                    ".hash", SHF_ALLOC);
            dynstr = s1->dynsym->link;

            /* add dynamic section */
            dynamic = new_section(s1, ".dynamic", SHT_DYNAMIC,
                                  SHF_ALLOC | SHF_WRITE);
            dynamic->link = dynstr;
            dynamic->sh_entsize = sizeof(ElfW(Dyn));

            build_got(s1);

            if (file_type == TCC_OUTPUT_EXE) {
                bind_exe_dynsyms(s1);
                if (s1->nb_errors)
                    goto the_end;
                bind_libs_dynsyms(s1);
            } else {
                /* shared library case: simply export all global symbols */
                export_global_syms(s1);
            }
        }
        build_got_entries(s1);
    }

    /* we add a section for symbols */
    strsec = new_section(s1, ".shstrtab", SHT_STRTAB, 0);
    put_elf_str(strsec, "");

    /* Allocate strings for section names */
    textrel = alloc_sec_names(s1, file_type, strsec);

    if (dynamic) {
        /* add a list of needed dlls */
        for(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            if (dllref->level == 0)
                put_dt(dynamic, DT_NEEDED, put_elf_str(dynstr, dllref->name));
        }

        if (s1->rpath)
            put_dt(dynamic, s1->enable_new_dtags ? DT_RUNPATH : DT_RPATH,
                   put_elf_str(dynstr, s1->rpath));

        if (file_type == TCC_OUTPUT_DLL) {
            if (s1->soname)
                put_dt(dynamic, DT_SONAME, put_elf_str(dynstr, s1->soname));
            /* XXX: currently, since we do not handle PIC code, we
               must relocate the readonly segments */
            if (textrel)
                put_dt(dynamic, DT_TEXTREL, 0);
        }

        if (s1->symbolic)
            put_dt(dynamic, DT_SYMBOLIC, 0);

        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        /* remember offset and reserve space for 2nd call below */
        dyninf.data_offset = dynamic->data_offset;
        fill_dynamic(s1, &dyninf);
        dynamic->sh_size = dynamic->data_offset;
        dynstr->sh_size = dynstr->data_offset;
    }

    /* compute number of program headers */
    if (file_type == TCC_OUTPUT_OBJ)
        phnum = 0;
    else if (file_type == TCC_OUTPUT_DLL)
        phnum = 3;
    else if (s1->static_link)
        phnum = 2;
    else
        phnum = 5;

    /* allocate program segment headers */
    phdr = tcc_mallocz(phnum * sizeof(ElfW(Phdr)));

    /* compute number of sections */
    shnum = s1->nb_sections;

    /* this array is used to reorder sections in the output file */
    sec_order = tcc_malloc(sizeof(int) * shnum);
    sec_order[0] = 0;

    /* compute section to program header mapping */
    file_offset = layout_sections(s1, phdr, phnum, interp, strsec, &dyninf,
                                  sec_order);

    /* Fill remaining program header and finalize relocation related to dynamic
       linking. */
    if (file_type != TCC_OUTPUT_OBJ) {
        fill_unloadable_phdr(phdr, phnum, interp, dynamic);
        if (dynamic) {
            dynamic->data_offset = dyninf.data_offset;
            fill_dynamic(s1, &dyninf);

            /* put in GOT the dynamic section address and relocate PLT */
            write32le(s1->got->data, dynamic->sh_addr);
            if (file_type == TCC_OUTPUT_EXE
                || (RELOCATE_DLLPLT && file_type == TCC_OUTPUT_DLL))
                relocate_plt(s1);

            /* relocate symbols in .dynsym now that final addresses are known */
            for_each_elem(s1->dynsym, 1, sym, ElfW(Sym)) {
                if (sym->st_shndx != SHN_UNDEF && sym->st_shndx < SHN_LORESERVE) {
                    /* do symbol relocation */
                    sym->st_value += s1->sections[sym->st_shndx]->sh_addr;
                }
            }
        }

        /* if building executable or DLL, then relocate each section
           except the GOT which is already relocated */
        ret = final_sections_reloc(s1);
        if (ret)
            goto the_end;
	tidy_section_headers(s1, sec_order);

        /* Perform relocation to GOT or PLT entries */
        if (file_type == TCC_OUTPUT_EXE && s1->static_link)
            fill_got(s1);
        else if (s1->got)
            fill_local_got_entries(s1);
    }

    /* Create the ELF file with name 'filename' */
    ret = tcc_write_elf_file(s1, filename, phnum, phdr, file_offset, sec_order);
    s1->nb_sections = shnum;
 the_end:
    tcc_free(sec_order);
    tcc_free(phdr);
    return ret;
}

LIBTCCAPI int tcc_output_file(TCCState *s, const char *filename)
{
    int ret;
#ifdef TCC_TARGET_PE
    if (s->output_type != TCC_OUTPUT_OBJ) {
        ret = pe_output_file(s, filename);
    } else
#endif
        ret = elf_output_file(s, filename);
    return ret;
}

static void *load_data(int fd, unsigned long file_offset, unsigned long size)
{
    void *data;

    data = tcc_malloc(size);
    lseek(fd, file_offset, SEEK_SET);
    read(fd, data, size);
    return data;
}

typedef struct SectionMergeInfo {
    Section *s;            /* corresponding existing section */
    unsigned long offset;  /* offset of the new section in the existing section */
    uint8_t new_section;       /* true if section 's' was added */
    uint8_t link_once;         /* true if link once section */
} SectionMergeInfo;

ST_FUNC int tcc_object_type(int fd, ElfW(Ehdr) *h)
{
    int size = read(fd, h, sizeof *h);
    if (size == sizeof *h && 0 == memcmp(h, ELFMAG, 4)) {
        if (h->e_type == ET_REL)
            return AFF_BINTYPE_REL;
        if (h->e_type == ET_DYN)
            return AFF_BINTYPE_DYN;
    } else if (size >= 8) {
        if (0 == memcmp(h, ARMAG, 8))
            return AFF_BINTYPE_AR;
#ifdef TCC_TARGET_COFF
        if (((struct filehdr*)h)->f_magic == COFF_C67_MAGIC)
            return AFF_BINTYPE_C67;
#endif
    }
    return 0;
}

/* load an object file and merge it with current files */
/* XXX: handle correctly stab (debug) info */
ST_FUNC int tcc_load_object_file(TCCState *s1,
                                int fd, unsigned long file_offset)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh;
    int size, i, j, offset, offseti, nb_syms, sym_index, ret, seencompressed;
    unsigned char *strsec, *strtab;
    int *old_to_new_syms;
    char *sh_name, *name;
    SectionMergeInfo *sm_table, *sm;
    ElfW(Sym) *sym, *symtab;
    ElfW_Rel *rel;
    Section *s;

    int stab_index;
    int stabstr_index;

    stab_index = stabstr_index = 0;

    lseek(fd, file_offset, SEEK_SET);
    if (tcc_object_type(fd, &ehdr) != AFF_BINTYPE_REL)
        goto fail1;
    /* test CPU specific stuff */
    if (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
    fail1:
        tcc_error_noabort("invalid object file");
        return -1;
    }
    /* read sections */
    shdr = load_data(fd, file_offset + ehdr.e_shoff,
                     sizeof(ElfW(Shdr)) * ehdr.e_shnum);
    sm_table = tcc_mallocz(sizeof(SectionMergeInfo) * ehdr.e_shnum);

    /* load section names */
    sh = &shdr[ehdr.e_shstrndx];
    strsec = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);

    /* load symtab and strtab */
    old_to_new_syms = NULL;
    symtab = NULL;
    strtab = NULL;
    nb_syms = 0;
    seencompressed = 0;
    for(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        if (sh->sh_type == SHT_SYMTAB) {
            if (symtab) {
                tcc_error_noabort("object must contain only one symtab");
            fail:
                ret = -1;
                goto the_end;
            }
            nb_syms = sh->sh_size / sizeof(ElfW(Sym));
            symtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
            sm_table[i].s = symtab_section;

            /* now load strtab */
            sh = &shdr[sh->sh_link];
            strtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
        }
	if (sh->sh_flags & SHF_COMPRESSED)
	    seencompressed = 1;
    }

    /* now examine each section and try to merge its content with the
       ones in memory */
    for(i = 1; i < ehdr.e_shnum; i++) {
        /* no need to examine section name strtab */
        if (i == ehdr.e_shstrndx)
            continue;
        sh = &shdr[i];
        sh_name = (char *) strsec + sh->sh_name;
        /* ignore sections types we do not handle */
        if (sh->sh_type != SHT_PROGBITS &&
            sh->sh_type != SHT_RELX &&
#ifdef TCC_ARM_EABI
            sh->sh_type != SHT_ARM_EXIDX &&
#endif
            sh->sh_type != SHT_NOBITS &&
            sh->sh_type != SHT_PREINIT_ARRAY &&
            sh->sh_type != SHT_INIT_ARRAY &&
            sh->sh_type != SHT_FINI_ARRAY &&
            strcmp(sh_name, ".stabstr")
            )
            continue;
	if (seencompressed
	    && (!strncmp(sh_name, ".debug_", sizeof(".debug_")-1)
		|| (sh->sh_type == SHT_RELX
		    && !strncmp((char*)strsec + shdr[sh->sh_info].sh_name,
			        ".debug_", sizeof(".debug_")-1))))
	  continue;
        if (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        /* find corresponding section, if any */
        for(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            if (!strcmp(s->name, sh_name)) {
                if (!strncmp(sh_name, ".gnu.linkonce",
                             sizeof(".gnu.linkonce") - 1)) {
                    /* if a 'linkonce' section is already present, we
                       do not add it again. It is a little tricky as
                       symbols can still be defined in
                       it. */
                    sm_table[i].link_once = 1;
                    goto next;
                } else {
                    goto found;
                }
            }
        }
        /* not found: create new section */
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~SHF_GROUP);
        /* take as much info as possible from the section. sh_link and
           sh_info will be updated later */
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_table[i].new_section = 1;
    found:
        if (sh->sh_type != s->sh_type) {
            tcc_error_noabort("invalid section type");
            goto fail;
        }

        /* align start of section */
        offset = s->data_offset;

        if (0 == strcmp(sh_name, ".stab")) {
            stab_index = i;
            goto no_align;
        }
        if (0 == strcmp(sh_name, ".stabstr")) {
            stabstr_index = i;
            goto no_align;
        }

        size = sh->sh_addralign - 1;
        offset = (offset + size) & ~size;
        if (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        s->data_offset = offset;
    no_align:
        sm_table[i].offset = offset;
        sm_table[i].s = s;
        /* concatenate sections */
        size = sh->sh_size;
        if (sh->sh_type != SHT_NOBITS) {
            unsigned char *ptr;
            lseek(fd, file_offset + sh->sh_offset, SEEK_SET);
            ptr = section_ptr_add(s, size);
            read(fd, ptr, size);
        } else {
            s->data_offset += size;
        }
    next: ;
    }

    /* gr relocate stab strings */
    if (stab_index && stabstr_index) {
        Stab_Sym *a, *b;
        unsigned o;
        s = sm_table[stab_index].s;
        a = (Stab_Sym *)(s->data + sm_table[stab_index].offset);
        b = (Stab_Sym *)(s->data + s->data_offset);
        o = sm_table[stabstr_index].offset;
        while (a < b)
            a->n_strx += o, a++;
    }

    /* second short pass to update sh_link and sh_info fields of new
       sections */
    for(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        if (!s || !sm_table[i].new_section)
            continue;
        sh = &shdr[i];
        if (sh->sh_link > 0)
            s->link = sm_table[sh->sh_link].s;
        if (sh->sh_type == SHT_RELX) {
            s->sh_info = sm_table[sh->sh_info].s->sh_num;
            /* update backward link */
            s1->sections[s->sh_info]->reloc = s;
        }
    }
    sm = sm_table;

    /* resolve symbols */
    old_to_new_syms = tcc_mallocz(nb_syms * sizeof(int));

    sym = symtab + 1;
    for(i = 1; i < nb_syms; i++, sym++) {
        if (sym->st_shndx != SHN_UNDEF &&
            sym->st_shndx < SHN_LORESERVE) {
            sm = &sm_table[sym->st_shndx];
            if (sm->link_once) {
                /* if a symbol is in a link once section, we use the
                   already defined symbol. It is very important to get
                   correct relocations */
                if (ELFW(ST_BIND)(sym->st_info) != STB_LOCAL) {
                    name = (char *) strtab + sym->st_name;
                    sym_index = find_elf_sym(symtab_section, name);
                    if (sym_index)
                        old_to_new_syms[i] = sym_index;
                }
                continue;
            }
            /* if no corresponding section added, no need to add symbol */
            if (!sm->s)
                continue;
            /* convert section number */
            sym->st_shndx = sm->s->sh_num;
            /* offset value */
            sym->st_value += sm->offset;
        }
        /* add symbol */
        name = (char *) strtab + sym->st_name;
        sym_index = set_elf_sym(symtab_section, sym->st_value, sym->st_size,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_to_new_syms[i] = sym_index;
    }

    /* third pass to patch relocation entries */
    for(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        if (!s)
            continue;
        sh = &shdr[i];
        offset = sm_table[i].offset;
        switch(s->sh_type) {
        case SHT_RELX:
            /* take relocation offset information */
            offseti = sm_table[sh->sh_info].offset;
            for_each_elem(s, (offset / sizeof(*rel)), rel, ElfW_Rel) {
                int type;
                unsigned sym_index;
                /* convert symbol index */
                type = ELFW(R_TYPE)(rel->r_info);
                sym_index = ELFW(R_SYM)(rel->r_info);
                /* NOTE: only one symtab assumed */
                if (sym_index >= nb_syms)
                    goto invalid_reloc;
                sym_index = old_to_new_syms[sym_index];
                /* ignore link_once in rel section. */
                if (!sym_index && !sm->link_once
#ifdef TCC_TARGET_ARM
                    && type != R_ARM_V4BX
#endif
                   ) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, rel->r_offset);
                    goto fail;
                }
                rel->r_info = ELFW(R_INFO)(sym_index, type);
                /* offset the relocation offset */
                rel->r_offset += offseti;
#ifdef TCC_TARGET_ARM
                /* Jumps and branches from a Thumb code to a PLT entry need
                   special handling since PLT entries are ARM code.
                   Unconditional bl instructions referencing PLT entries are
                   handled by converting these instructions into blx
                   instructions. Other case of instructions referencing a PLT
                   entry require to add a Thumb stub before the PLT entry to
                   switch to ARM mode. We set bit plt_thumb_stub of the
                   attribute of a symbol to indicate such a case. */
                if (type == R_ARM_THM_JUMP24)
                    get_sym_attr(s1, sym_index, 1)->plt_thumb_stub = 1;
#endif
            }
            break;
        default:
            break;
        }
    }

    ret = 0;
 the_end:
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_to_new_syms);
    tcc_free(sm_table);
    tcc_free(strsec);
    tcc_free(shdr);
    return ret;
}

typedef struct ArchiveHeader {
    char ar_name[16];           /* name of this member */
    char ar_date[12];           /* file mtime */
    char ar_uid[6];             /* owner uid; printed as decimal */
    char ar_gid[6];             /* owner gid; printed as decimal */
    char ar_mode[8];            /* file mode, printed as octal   */
    char ar_size[10];           /* file size, printed as decimal */
    char ar_fmag[2];            /* should contain ARFMAG */
} ArchiveHeader;

static int get_be32(const uint8_t *b)
{
    return b[3] | (b[2] << 8) | (b[1] << 16) | (b[0] << 24);
}

static long get_be64(const uint8_t *b)
{
  long long ret = get_be32(b);
  ret = (ret << 32) | (unsigned)get_be32(b+4);
  return (long)ret;
}

/* load only the objects which resolve undefined symbols */
static int tcc_load_alacarte(TCCState *s1, int fd, int size, int entrysize)
{
    long i, bound, nsyms, sym_index, off, ret;
    uint8_t *data;
    const char *ar_names, *p;
    const uint8_t *ar_index;
    ElfW(Sym) *sym;

    data = tcc_malloc(size);
    if (read(fd, data, size) != size)
        goto fail;
    nsyms = entrysize == 4 ? get_be32(data) : get_be64(data);
    ar_index = data + entrysize;
    ar_names = (char *) ar_index + nsyms * entrysize;

    do {
        bound = 0;
        for(p = ar_names, i = 0; i < nsyms; i++, p += strlen(p)+1) {
            sym_index = find_elf_sym(symtab_section, p);
            if(sym_index) {
                sym = &((ElfW(Sym) *)symtab_section->data)[sym_index];
                if(sym->st_shndx == SHN_UNDEF) {
                    off = (entrysize == 4
			   ? get_be32(ar_index + i * 4)
			   : get_be64(ar_index + i * 8))
			  + sizeof(ArchiveHeader);
                    ++bound;
                    if(tcc_load_object_file(s1, fd, off) < 0) {
                    fail:
                        ret = -1;
                        goto the_end;
                    }
                }
            }
        }
    } while(bound);
    ret = 0;
 the_end:
    tcc_free(data);
    return ret;
}

/* load a '.a' file */
ST_FUNC int tcc_load_archive(TCCState *s1, int fd)
{
    ArchiveHeader hdr;
    char ar_size[11];
    char ar_name[17];
    char magic[8];
    int size, len, i;
    unsigned long file_offset;

    /* skip magic which was already checked */
    read(fd, magic, sizeof(magic));

    for(;;) {
        len = read(fd, &hdr, sizeof(hdr));
        if (len == 0)
            break;
        if (len != sizeof(hdr)) {
            tcc_error_noabort("invalid archive");
            return -1;
        }
        memcpy(ar_size, hdr.ar_size, sizeof(hdr.ar_size));
        ar_size[sizeof(hdr.ar_size)] = '\0';
        size = strtol(ar_size, NULL, 0);
        memcpy(ar_name, hdr.ar_name, sizeof(hdr.ar_name));
        for(i = sizeof(hdr.ar_name) - 1; i >= 0; i--) {
            if (ar_name[i] != ' ')
                break;
        }
        ar_name[i + 1] = '\0';
        file_offset = lseek(fd, 0, SEEK_CUR);
        /* align to even */
        size = (size + 1) & ~1;
        if (!strcmp(ar_name, "/")) {
            /* coff symbol table : we handle it */
            if(s1->alacarte_link)
                return tcc_load_alacarte(s1, fd, size, 4);
	} else if (!strcmp(ar_name, "/SYM64/")) {
            if(s1->alacarte_link)
                return tcc_load_alacarte(s1, fd, size, 8);
        } else {
            ElfW(Ehdr) ehdr;
            if (tcc_object_type(fd, &ehdr) == AFF_BINTYPE_REL) {
                if (tcc_load_object_file(s1, fd, file_offset) < 0)
                    return -1;
            }
        }
        lseek(fd, file_offset + size, SEEK_SET);
    }
    return 0;
}

#ifndef TCC_TARGET_PE
/* load a DLL and all referenced DLLs. 'level = 0' means that the DLL
   is referenced by the user (so it should be added as DT_NEEDED in
   the generated ELF file) */
ST_FUNC int tcc_load_dll(TCCState *s1, int fd, const char *filename, int level)
{
    ElfW(Ehdr) ehdr;
    ElfW(Shdr) *shdr, *sh, *sh1;
    int i, j, nb_syms, nb_dts, sym_bind, ret;
    ElfW(Sym) *sym, *dynsym;
    ElfW(Dyn) *dt, *dynamic;
    unsigned char *dynstr;
    const char *name, *soname;
    DLLReference *dllref;

    read(fd, &ehdr, sizeof(ehdr));

    /* test CPU specific stuff */
    if (ehdr.e_ident[5] != ELFDATA2LSB ||
        ehdr.e_machine != EM_TCC_TARGET) {
        tcc_error_noabort("bad architecture");
        return -1;
    }

    /* read sections */
    shdr = load_data(fd, ehdr.e_shoff, sizeof(ElfW(Shdr)) * ehdr.e_shnum);

    /* load dynamic section and dynamic symbols */
    nb_syms = 0;
    nb_dts = 0;
    dynamic = NULL;
    dynsym = NULL; /* avoid warning */
    dynstr = NULL; /* avoid warning */
    for(i = 0, sh = shdr; i < ehdr.e_shnum; i++, sh++) {
        switch(sh->sh_type) {
        case SHT_DYNAMIC:
            nb_dts = sh->sh_size / sizeof(ElfW(Dyn));
            dynamic = load_data(fd, sh->sh_offset, sh->sh_size);
            break;
        case SHT_DYNSYM:
            nb_syms = sh->sh_size / sizeof(ElfW(Sym));
            dynsym = load_data(fd, sh->sh_offset, sh->sh_size);
            sh1 = &shdr[sh->sh_link];
            dynstr = load_data(fd, sh1->sh_offset, sh1->sh_size);
            break;
        default:
            break;
        }
    }

    /* compute the real library name */
    soname = tcc_basename(filename);

    for(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        if (dt->d_tag == DT_SONAME) {
            soname = (char *) dynstr + dt->d_un.d_val;
        }
    }

    /* if the dll is already loaded, do not load it */
    for(i = 0; i < s1->nb_loaded_dlls; i++) {
        dllref = s1->loaded_dlls[i];
        if (!strcmp(soname, dllref->name)) {
            /* but update level if needed */
            if (level < dllref->level)
                dllref->level = level;
            ret = 0;
            goto the_end;
        }
    }

    /* add the dll and its level */
    dllref = tcc_mallocz(sizeof(DLLReference) + strlen(soname));
    dllref->level = level;
    strcpy(dllref->name, soname);
    dynarray_add(&s1->loaded_dlls, &s1->nb_loaded_dlls, dllref);

    /* add dynamic symbols in dynsym_section */
    for(i = 1, sym = dynsym + 1; i < nb_syms; i++, sym++) {
        sym_bind = ELFW(ST_BIND)(sym->st_info);
        if (sym_bind == STB_LOCAL)
            continue;
        name = (char *) dynstr + sym->st_name;
        set_elf_sym(s1->dynsymtab_section, sym->st_value, sym->st_size,
                    sym->st_info, sym->st_other, sym->st_shndx, name);
    }

    /* load all referenced DLLs */
    for(i = 0, dt = dynamic; i < nb_dts; i++, dt++) {
        switch(dt->d_tag) {
        case DT_NEEDED:
            name = (char *) dynstr + dt->d_un.d_val;
            for(j = 0; j < s1->nb_loaded_dlls; j++) {
                dllref = s1->loaded_dlls[j];
                if (!strcmp(name, dllref->name))
                    goto already_loaded;
            }
            if (tcc_add_dll(s1, name, AFF_REFERENCED_DLL) < 0) {
                tcc_error_noabort("referenced dll '%s' not found", name);
                ret = -1;
                goto the_end;
            }
        already_loaded:
            break;
        }
    }
    ret = 0;
 the_end:
    tcc_free(dynstr);
    tcc_free(dynsym);
    tcc_free(dynamic);
    tcc_free(shdr);
    return ret;
}

#define LD_TOK_NAME 256
#define LD_TOK_EOF  (-1)

/* return next ld script token */
static int ld_next(TCCState *s1, char *name, int name_size)
{
    int c;
    char *q;

 redo:
    switch(ch) {
    case ' ':
    case '\t':
    case '\f':
    case '\v':
    case '\r':
    case '\n':
        inp();
        goto redo;
    case '/':
        minp();
        if (ch == '*') {
            file->buf_ptr = parse_comment(file->buf_ptr);
            ch = file->buf_ptr[0];
            goto redo;
        } else {
            q = name;
            *q++ = '/';
            goto parse_name;
        }
        break;
    case '\\':
        ch = handle_eob();
        if (ch != '\\')
            goto redo;
        /* fall through */
    /* case 'a' ... 'z': */
    case 'a':
       case 'b':
       case 'c':
       case 'd':
       case 'e':
       case 'f':
       case 'g':
       case 'h':
       case 'i':
       case 'j':
       case 'k':
       case 'l':
       case 'm':
       case 'n':
       case 'o':
       case 'p':
       case 'q':
       case 'r':
       case 's':
       case 't':
       case 'u':
       case 'v':
       case 'w':
       case 'x':
       case 'y':
       case 'z':
    /* case 'A' ... 'z': */
    case 'A':
       case 'B':
       case 'C':
       case 'D':
       case 'E':
       case 'F':
       case 'G':
       case 'H':
       case 'I':
       case 'J':
       case 'K':
       case 'L':
       case 'M':
       case 'N':
       case 'O':
       case 'P':
       case 'Q':
       case 'R':
       case 'S':
       case 'T':
       case 'U':
       case 'V':
       case 'W':
       case 'X':
       case 'Y':
       case 'Z':
    case '_':
    case '.':
    case '$':
    case '~':
        q = name;
    parse_name:
        for(;;) {
            if (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9') ||
                  strchr("/.-_+=$:\\,~", ch)))
                break;
            if ((q - name) < name_size - 1) {
                *q++ = ch;
            }
            minp();
        }
        *q = '\0';
        c = LD_TOK_NAME;
        break;
    case CH_EOF:
        c = LD_TOK_EOF;
        break;
    default:
        c = ch;
        inp();
        break;
    }
    return c;
}

static int ld_add_file(TCCState *s1, const char filename[])
{
    if (filename[0] == '/') {
        if (CONFIG_SYSROOT[0] == '\0'
            && tcc_add_file_internal(s1, filename, AFF_TYPE_BIN) == 0)
            return 0;
        filename = tcc_basename(filename);
    }
    return tcc_add_dll(s1, filename, 0);
}

static int ld_add_file_list(TCCState *s1, const char *cmd, int as_needed)
{
    char filename[1024], libname[1024];
    int t, group, nblibs = 0, ret = 0;
    char **libs = NULL;

    group = !strcmp(cmd, "GROUP");
    if (!as_needed)
        new_undef_syms();
    t = ld_next(s1, filename, sizeof(filename));
    if (t != '(')
        expect("(");
    t = ld_next(s1, filename, sizeof(filename));
    for(;;) {
        libname[0] = '\0';
        if (t == LD_TOK_EOF) {
            tcc_error_noabort("unexpected end of file");
            ret = -1;
            goto lib_parse_error;
        } else if (t == ')') {
            break;
        } else if (t == '-') {
            t = ld_next(s1, filename, sizeof(filename));
            if ((t != LD_TOK_NAME) || (filename[0] != 'l')) {
                tcc_error_noabort("library name expected");
                ret = -1;
                goto lib_parse_error;
            }
            pstrcpy(libname, sizeof libname, &filename[1]);
            if (s1->static_link) {
                snprintf(filename, sizeof filename, "lib%s.a", libname);
            } else {
                snprintf(filename, sizeof filename, "lib%s.so", libname);
            }
        } else if (t != LD_TOK_NAME) {
            tcc_error_noabort("filename expected");
            ret = -1;
            goto lib_parse_error;
        }
        if (!strcmp(filename, "AS_NEEDED")) {
            ret = ld_add_file_list(s1, cmd, 1);
            if (ret)
                goto lib_parse_error;
        } else {
            /* TODO: Implement AS_NEEDED support. Ignore it for now */
            if (!as_needed) {
                ret = ld_add_file(s1, filename);
                if (ret)
                    goto lib_parse_error;
                if (group) {
                    /* Add the filename *and* the libname to avoid future conversions */
                    dynarray_add(&libs, &nblibs, tcc_strdup(filename));
                    if (libname[0] != '\0')
                        dynarray_add(&libs, &nblibs, tcc_strdup(libname));
                }
            }
        }
        t = ld_next(s1, filename, sizeof(filename));
        if (t == ',') {
            t = ld_next(s1, filename, sizeof(filename));
        }
    }
    if (group && !as_needed) {
        while (new_undef_syms()) {
            int i;

            for (i = 0; i < nblibs; i ++)
                ld_add_file(s1, libs[i]);
        }
    }
lib_parse_error:
    dynarray_reset(&libs, &nblibs);
    return ret;
}

/* interpret a subset of GNU ldscripts to handle the dummy libc.so
   files */
ST_FUNC int tcc_load_ldscript(TCCState *s1)
{
    char cmd[64];
    char filename[1024];
    int t, ret;

    ch = handle_eob();
    for(;;) {
        t = ld_next(s1, cmd, sizeof(cmd));
        if (t == LD_TOK_EOF)
            return 0;
        else if (t != LD_TOK_NAME)
            return -1;
        if (!strcmp(cmd, "INPUT") ||
            !strcmp(cmd, "GROUP")) {
            ret = ld_add_file_list(s1, cmd, 0);
            if (ret)
                return ret;
        } else if (!strcmp(cmd, "OUTPUT_FORMAT") ||
                   !strcmp(cmd, "TARGET")) {
            /* ignore some commands */
            t = ld_next(s1, cmd, sizeof(cmd));
            if (t != '(')
                expect("(");
            for(;;) {
                t = ld_next(s1, filename, sizeof(filename));
                if (t == LD_TOK_EOF) {
                    tcc_error_noabort("unexpected end of file");
                    return -1;
                } else if (t == ')') {
                    break;
                }
            }
        } else {
            return -1;
        }
    }
    return 0;
}
#endif /* !TCC_TARGET_PE */
