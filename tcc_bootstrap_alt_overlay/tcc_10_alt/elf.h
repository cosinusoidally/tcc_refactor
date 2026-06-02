#ifndef _ELF_H
#define _ELF_H 1

typedef unsigned short int Elf32_Half;
typedef unsigned int Elf32_Word;
typedef int Elf32_Sword;
typedef unsigned int Elf32_Addr;
typedef unsigned int Elf32_Off;
typedef unsigned short int Elf32_Section;

typedef struct
{
  unsigned char e_ident0;
  unsigned char e_ident1;
  unsigned char e_ident2;
  unsigned char e_ident3;
  unsigned char e_ident4;
  unsigned char e_ident5;
  unsigned char e_ident6;
  unsigned char e_ident7;
  unsigned char e_ident8;
  unsigned char e_ident9;
  unsigned char e_ident10;
  unsigned char e_ident11;
  unsigned char e_ident12;
  unsigned char e_ident13;
  unsigned char e_ident14;
  unsigned char e_ident15;
  Elf32_Half e_type;
  Elf32_Half e_machine;
  Elf32_Word e_version;
  Elf32_Addr e_entry;
  Elf32_Off e_phoff;
  Elf32_Off e_shoff;
  Elf32_Word e_flags;
  Elf32_Half e_ehsize;
  Elf32_Half e_phentsize;
  Elf32_Half e_phnum;
  Elf32_Half e_shentsize;
  Elf32_Half e_shnum;
  Elf32_Half e_shstrndx;
} Elf32_Ehdr;

typedef struct
{
  Elf32_Word sh_name;
  Elf32_Word sh_type;
  Elf32_Word sh_flags;
  Elf32_Addr sh_addr;
  Elf32_Off sh_offset;
  Elf32_Word sh_size;
  Elf32_Word sh_link;
  Elf32_Word sh_info;
  Elf32_Word sh_addralign;
  Elf32_Word sh_entsize;
} Elf32_Shdr;

typedef struct
{
  Elf32_Word st_name;
  Elf32_Addr st_value;
  Elf32_Word st_size;
  unsigned char st_info;
  unsigned char st_other;
  Elf32_Section st_shndx;
} Elf32_Sym;

typedef struct
{
  Elf32_Addr r_offset;
  Elf32_Word r_info;
} Elf32_Rel;

typedef struct
{
  Elf32_Word p_type;
  Elf32_Off p_offset;
  Elf32_Addr p_vaddr;
  Elf32_Addr p_paddr;
  Elf32_Word p_filesz;
  Elf32_Word p_memsz;
  Elf32_Word p_flags;
  Elf32_Word p_align;
} Elf32_Phdr;

typedef struct
{
  Elf32_Sword d_tag;
  union {
    Elf32_Word d_val;
    Elf32_Addr d_ptr;
  } d_un;
} Elf32_Dyn;

#define EI_MAG0 0
#define EI_MAG1 1
#define EI_MAG2 2
#define EI_MAG3 3
#define ELFMAG0 0x7f
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'
#define ELFCLASS32 1
#define ELFDATA2LSB 1
#define EV_CURRENT 1

#define ET_REL 1
#define ET_EXEC 2
#define ET_DYN 3

#define EM_386 3

#define SHN_UNDEF 0
#define SHN_ABS 0xfff1
#define SHN_COMMON 0xfff2
#define SHN_LORESERVE 0xff00

#define SHT_NULL 0
#define SHT_PROGBITS 1
#define SHT_SYMTAB 2
#define SHT_STRTAB 3
#define SHT_HASH 5
#define SHT_DYNAMIC 6
#define SHT_REL 9
#define SHT_NOBITS 8
#define SHT_DYNSYM 11

#define SHF_WRITE 0x1
#define SHF_ALLOC 0x2
#define SHF_EXECINSTR 0x4

#define STB_LOCAL 0
#define STB_GLOBAL 1
#define STB_WEAK 2

#define STT_NOTYPE 0
#define STT_OBJECT 1
#define STT_FUNC 2
#define STT_SECTION 3
#define STT_FILE 4

#define R_386_NONE 0
#define R_386_32 1
#define R_386_PC32 2
#define R_386_GOT32 3
#define R_386_PLT32 4
#define R_386_COPY 5
#define R_386_GLOB_DAT 6
#define R_386_JMP_SLOT 7
#define R_386_RELATIVE 8
#define R_386_GOTOFF 9
#define R_386_GOTPC 10

#define PT_LOAD 1
#define PT_DYNAMIC 2
#define PT_INTERP 3

#define PF_X 0x1
#define PF_W 0x2
#define PF_R 0x4

#define DT_NULL 0
#define DT_NEEDED 1
#define DT_HASH 4
#define DT_STRTAB 5
#define DT_SYMTAB 6
#define DT_STRSZ 10
#define DT_SYMENT 11
#define DT_SONAME 14
#define DT_REL 17
#define DT_RELSZ 18
#define DT_RELENT 19
#define DT_TEXTREL 22

#endif
