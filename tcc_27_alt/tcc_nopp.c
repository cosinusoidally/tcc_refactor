typedef unsigned int size_t;
typedef int int32_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef char *va_list;
typedef int FILE;
extern FILE *stdout;
extern FILE *stderr;
struct TCCState;
typedef struct TCCState TCCState;
char *tcc_strdup(char *str);
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Word;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf32_Addr;
typedef uint32_t Elf32_Off;
typedef uint16_t Elf32_Section;
typedef unsigned char Elf32_Ehdr[52];
static unsigned char eh_ident(Elf32_Ehdr *eh, int index)
{
    return *(((unsigned char *)eh) + index);
}
static void eh_set_ident(Elf32_Ehdr *eh, int index, unsigned char value)
{
    *(((unsigned char *)eh) + index) = value;
}
static Elf32_Half eh_type(Elf32_Ehdr *eh)
{
    return *(Elf32_Half *)(((unsigned char *)eh) + 16);
}
static void eh_set_type(Elf32_Ehdr *eh, Elf32_Half type)
{
    *(Elf32_Half *)(((unsigned char *)eh) + 16) = type;
}
static Elf32_Half eh_machine(Elf32_Ehdr *eh)
{
    return *(Elf32_Half *)(((unsigned char *)eh) + 18);
}
static void eh_set_machine(Elf32_Ehdr *eh, Elf32_Half machine)
{
    *(Elf32_Half *)(((unsigned char *)eh) + 18) = machine;
}
static Elf32_Word eh_version(Elf32_Ehdr *eh)
{
    return *(Elf32_Word *)(((unsigned char *)eh) + 20);
}
static void eh_set_version(Elf32_Ehdr *eh, Elf32_Word version)
{
    *(Elf32_Word *)(((unsigned char *)eh) + 20) = version;
}
static Elf32_Addr eh_entry(Elf32_Ehdr *eh)
{
    return *(Elf32_Addr *)(((unsigned char *)eh) + 24);
}
static void eh_set_entry(Elf32_Ehdr *eh, Elf32_Addr entry)
{
    *(Elf32_Addr *)(((unsigned char *)eh) + 24) = entry;
}
static Elf32_Off eh_phoff(Elf32_Ehdr *eh)
{
    return *(Elf32_Off *)(((unsigned char *)eh) + 28);
}
static void eh_set_phoff(Elf32_Ehdr *eh, Elf32_Off phoff)
{
    *(Elf32_Off *)(((unsigned char *)eh) + 28) = phoff;
}
static Elf32_Off eh_shoff(Elf32_Ehdr *eh)
{
    return *(Elf32_Off *)(((unsigned char *)eh) + 32);
}
static void eh_set_shoff(Elf32_Ehdr *eh, Elf32_Off shoff)
{
    *(Elf32_Off *)(((unsigned char *)eh) + 32) = shoff;
}
static Elf32_Half eh_ehsize(Elf32_Ehdr *eh)
{
    return *(Elf32_Half *)(((unsigned char *)eh) + 40);
}
static void eh_set_ehsize(Elf32_Ehdr *eh, Elf32_Half ehsize)
{
    *(Elf32_Half *)(((unsigned char *)eh) + 40) = ehsize;
}
static Elf32_Half eh_phentsize(Elf32_Ehdr *eh)
{
    return *(Elf32_Half *)(((unsigned char *)eh) + 42);
}
static void eh_set_phentsize(Elf32_Ehdr *eh, Elf32_Half phentsize)
{
    *(Elf32_Half *)(((unsigned char *)eh) + 42) = phentsize;
}
static Elf32_Half eh_phnum(Elf32_Ehdr *eh)
{
    return *(Elf32_Half *)(((unsigned char *)eh) + 44);
}
static void eh_set_phnum(Elf32_Ehdr *eh, Elf32_Half phnum)
{
    *(Elf32_Half *)(((unsigned char *)eh) + 44) = phnum;
}
static Elf32_Half eh_shentsize(Elf32_Ehdr *eh)
{
    return *(Elf32_Half *)(((unsigned char *)eh) + 46);
}
static void eh_set_shentsize(Elf32_Ehdr *eh, Elf32_Half shentsize)
{
    *(Elf32_Half *)(((unsigned char *)eh) + 46) = shentsize;
}
static Elf32_Half eh_shnum(Elf32_Ehdr *eh)
{
    return *(Elf32_Half *)(((unsigned char *)eh) + 48);
}
static void eh_set_shnum(Elf32_Ehdr *eh, Elf32_Half shnum)
{
    *(Elf32_Half *)(((unsigned char *)eh) + 48) = shnum;
}
static Elf32_Half eh_shstrndx(Elf32_Ehdr *eh)
{
    return *(Elf32_Half *)(((unsigned char *)eh) + 50);
}
static void eh_set_shstrndx(Elf32_Ehdr *eh, Elf32_Half shstrndx)
{
    *(Elf32_Half *)(((unsigned char *)eh) + 50) = shstrndx;
}
typedef unsigned int Elf32_Shdr[10];
static Elf32_Word sh_name(Elf32_Shdr *sh)
{
    return *(unsigned int *)sh;
}
static void sh_set_name(Elf32_Shdr *sh, Elf32_Word name)
{
    *(unsigned int *)sh = name;
}
static Elf32_Word sh_type(Elf32_Shdr *sh)
{
    return *(((unsigned int *)sh) + 1);
}
static void sh_set_type(Elf32_Shdr *sh, Elf32_Word type)
{
    *(((unsigned int *)sh) + 1) = type;
}
static Elf32_Word sh_flags(Elf32_Shdr *sh)
{
    return *(((unsigned int *)sh) + 2);
}
static void sh_set_flags(Elf32_Shdr *sh, Elf32_Word flags)
{
    *(((unsigned int *)sh) + 2) = flags;
}
static Elf32_Addr sh_addr(Elf32_Shdr *sh)
{
    return *(((unsigned int *)sh) + 3);
}
static void sh_set_addr(Elf32_Shdr *sh, Elf32_Addr addr)
{
    *(((unsigned int *)sh) + 3) = addr;
}
static Elf32_Off sh_offset(Elf32_Shdr *sh)
{
    return *(((unsigned int *)sh) + 4);
}
static void sh_set_offset(Elf32_Shdr *sh, Elf32_Off offset)
{
    *(((unsigned int *)sh) + 4) = offset;
}
static Elf32_Word sh_size(Elf32_Shdr *sh)
{
    return *(((unsigned int *)sh) + 5);
}
static void sh_set_size(Elf32_Shdr *sh, Elf32_Word size)
{
    *(((unsigned int *)sh) + 5) = size;
}
static Elf32_Word sh_link(Elf32_Shdr *sh)
{
    return *(((unsigned int *)sh) + 6);
}
static void sh_set_link(Elf32_Shdr *sh, Elf32_Word link)
{
    *(((unsigned int *)sh) + 6) = link;
}
static Elf32_Word sh_info(Elf32_Shdr *sh)
{
    return *(((unsigned int *)sh) + 7);
}
static void sh_set_info(Elf32_Shdr *sh, Elf32_Word info)
{
    *(((unsigned int *)sh) + 7) = info;
}
static Elf32_Word sh_addralign(Elf32_Shdr *sh)
{
    return *(((unsigned int *)sh) + 8);
}
static void sh_set_addralign(Elf32_Shdr *sh, Elf32_Word addralign)
{
    *(((unsigned int *)sh) + 8) = addralign;
}
static Elf32_Word sh_entsize(Elf32_Shdr *sh)
{
    return *(((unsigned int *)sh) + 9);
}
static void sh_set_entsize(Elf32_Shdr *sh, Elf32_Word entsize)
{
    *(((unsigned int *)sh) + 9) = entsize;
}
typedef unsigned char Elf32_Sym[16];
static Elf32_Word esy_name(Elf32_Sym *sym)
{
    return *(unsigned int *)sym;
}
static void esy_set_name(Elf32_Sym *sym, Elf32_Word name)
{
    *(unsigned int *)sym = name;
}
static Elf32_Addr esy_value(Elf32_Sym *sym)
{
    return *(((unsigned int *)sym) + 1);
}
static void esy_set_value(Elf32_Sym *sym, Elf32_Addr value)
{
    *(((unsigned int *)sym) + 1) = value;
}
static void esy_add_value(Elf32_Sym *sym, Elf32_Addr value)
{
    esy_set_value(sym, esy_value(sym) + value);
}
static Elf32_Word esy_size(Elf32_Sym *sym)
{
    return *(((unsigned int *)sym) + 2);
}
static void esy_set_size(Elf32_Sym *sym, Elf32_Word size)
{
    *(((unsigned int *)sym) + 2) = size;
}
static unsigned char esy_info(Elf32_Sym *sym)
{
    return *(((unsigned char *)sym) + 12);
}
static void esy_set_info(Elf32_Sym *sym, unsigned char info)
{
    *(((unsigned char *)sym) + 12) = info;
}
static unsigned char esy_other(Elf32_Sym *sym)
{
    return *(((unsigned char *)sym) + 13);
}
static void esy_set_other(Elf32_Sym *sym, unsigned char other)
{
    *(((unsigned char *)sym) + 13) = other;
}
static Elf32_Section esy_shndx(Elf32_Sym *sym)
{
    return *(Elf32_Section *)(((unsigned char *)sym) + 14);
}
static void esy_set_shndx(Elf32_Sym *sym, Elf32_Section shndx)
{
    *(Elf32_Section *)(((unsigned char *)sym) + 14) = shndx;
}
typedef unsigned int Elf32_Rel[2];
static Elf32_Addr rel_offset(Elf32_Rel *rel)
{
    return *(unsigned int *)rel;
}
static void rel_set_offset(Elf32_Rel *rel, Elf32_Addr offset)
{
    *(unsigned int *)rel = offset;
}
static void rel_add_offset(Elf32_Rel *rel, Elf32_Addr offset)
{
    rel_set_offset(rel, rel_offset(rel) + offset);
}
static Elf32_Word rel_info(Elf32_Rel *rel)
{
    return *(((unsigned int *)rel) + 1);
}
static void rel_set_info(Elf32_Rel *rel, Elf32_Word info)
{
    *(((unsigned int *)rel) + 1) = info;
}
static int rel_type(Elf32_Rel *rel)
{
    return rel_info(rel) & 0xff;
}
static int rel_sym(Elf32_Rel *rel)
{
    return rel_info(rel) >> 8;
}
static void rel_set_sym_type(Elf32_Rel *rel, int sym, int type)
{
    rel_set_info(rel, (((sym) << 8) + ((type) & 0xff)));
}
typedef unsigned int Elf32_Phdr[8];
static Elf32_Word ph_type(Elf32_Phdr *ph)
{
    return *(unsigned int *)ph;
}
static void ph_set_type(Elf32_Phdr *ph, Elf32_Word type)
{
    *(unsigned int *)ph = type;
}
static Elf32_Off ph_offset(Elf32_Phdr *ph)
{
    return *(((unsigned int *)ph) + 1);
}
static void ph_set_offset(Elf32_Phdr *ph, Elf32_Off offset)
{
    *(((unsigned int *)ph) + 1) = offset;
}
static void ph_and_offset(Elf32_Phdr *ph, Elf32_Off mask)
{
    ph_set_offset(ph, ph_offset(ph) & mask);
}
static Elf32_Addr ph_vaddr(Elf32_Phdr *ph)
{
    return *(((unsigned int *)ph) + 2);
}
static void ph_set_vaddr(Elf32_Phdr *ph, Elf32_Addr vaddr)
{
    *(((unsigned int *)ph) + 2) = vaddr;
}
static void ph_and_vaddr(Elf32_Phdr *ph, Elf32_Addr mask)
{
    ph_set_vaddr(ph, ph_vaddr(ph) & mask);
}
static Elf32_Addr ph_paddr(Elf32_Phdr *ph)
{
    return *(((unsigned int *)ph) + 3);
}
static void ph_set_paddr(Elf32_Phdr *ph, Elf32_Addr paddr)
{
    *(((unsigned int *)ph) + 3) = paddr;
}
static Elf32_Word ph_filesz(Elf32_Phdr *ph)
{
    return *(((unsigned int *)ph) + 4);
}
static void ph_set_filesz(Elf32_Phdr *ph, Elf32_Word filesz)
{
    *(((unsigned int *)ph) + 4) = filesz;
}
static Elf32_Word ph_memsz(Elf32_Phdr *ph)
{
    return *(((unsigned int *)ph) + 5);
}
static void ph_set_memsz(Elf32_Phdr *ph, Elf32_Word memsz)
{
    *(((unsigned int *)ph) + 5) = memsz;
}
static void ph_set_sizes(Elf32_Phdr *ph, Elf32_Word filesz, Elf32_Word memsz)
{
    ph_set_filesz(ph, filesz);
    ph_set_memsz(ph, memsz);
}
static Elf32_Word ph_flags(Elf32_Phdr *ph)
{
    return *(((unsigned int *)ph) + 6);
}
static void ph_set_flags(Elf32_Phdr *ph, Elf32_Word flags)
{
    *(((unsigned int *)ph) + 6) = flags;
}
static Elf32_Word ph_align(Elf32_Phdr *ph)
{
    return *(((unsigned int *)ph) + 7);
}
static void ph_set_align(Elf32_Phdr *ph, Elf32_Word align)
{
    *(((unsigned int *)ph) + 7) = align;
}
typedef unsigned int Elf32_Dyn[2];
static void dyn_set_tag(Elf32_Dyn *dyn, Elf32_Sword tag)
{
    *(unsigned int *)dyn = tag;
}
static void dyn_set_un(Elf32_Dyn *dyn, Elf32_Word val)
{
    *(((unsigned int *)dyn) + 1) = val;
}
typedef unsigned char TokenSym;
static TokenSym **ts_hash_next_ref(TokenSym *ts)
{
    return (TokenSym **)ts;
}
static void ts_set_hash_next(TokenSym *ts, TokenSym *next)
{
    *(TokenSym **)ts = next;
}
static struct Sym *ts_sym_struct(TokenSym *ts)
{
    return *(struct Sym **)(ts + 4);
}
static struct Sym **ts_sym_struct_ref(TokenSym *ts)
{
    return (struct Sym **)(ts + 4);
}
static void ts_set_sym_struct(TokenSym *ts, struct Sym *sym)
{
    *(struct Sym **)(ts + 4) = sym;
}
static struct Sym *ts_sym_identifier(TokenSym *ts)
{
    return *(struct Sym **)(ts + 8);
}
static struct Sym **ts_sym_identifier_ref(TokenSym *ts)
{
    return (struct Sym **)(ts + 8);
}
static void ts_set_sym_identifier(TokenSym *ts, struct Sym *sym)
{
    *(struct Sym **)(ts + 8) = sym;
}
static int ts_tok(TokenSym *ts)
{
    return *(int *)(ts + 12);
}
static void ts_set_tok(TokenSym *ts, int tok)
{
    *(int *)(ts + 12) = tok;
}
static int ts_len(TokenSym *ts)
{
    return *(int *)(ts + 16);
}
static void ts_set_len(TokenSym *ts, int len)
{
    *(int *)(ts + 16) = len;
}
static char *ts_str(TokenSym *ts)
{
    return (char *)(ts + 20);
}
typedef unsigned int CString[3];
static int cstr_size(CString *cstr)
{
    return *(unsigned int *)cstr;
}
static void cstr_set_size(CString *cstr, int size)
{
    *(unsigned int *)cstr = size;
}
static void *cstr_data(CString *cstr)
{
    return (void *)*(((unsigned int *)cstr) + 1);
}
static void cstr_set_data(CString *cstr, void *data)
{
    *(((unsigned int *)cstr) + 1) = (unsigned int)data;
}
static int cstr_size_allocated(CString *cstr)
{
    return *(((unsigned int *)cstr) + 2);
}
static void cstr_set_size_allocated(CString *cstr, int size)
{
    *(((unsigned int *)cstr) + 2) = size;
}
typedef struct CType {
    int t;
    struct Sym *ref;
} CType;
static int ct_t(CType *ct)
{
    return ct->t;
}
static void ct_set_t(CType *ct, int t)
{
    ct->t = t;
}
static void ct_or_t(CType *ct, int t)
{
    ct->t |= t;
}
static void ct_and_t(CType *ct, int t)
{
    ct->t &= t;
}
static void ct_clear_t(CType *ct, int t)
{
    ct->t &= ~t;
}
static struct Sym *ct_ref(CType *ct)
{
    return ct->ref;
}
static void ct_set_ref(CType *ct, struct Sym *ref)
{
    ct->ref = ref;
}
static void ct_copy(CType *dst, CType *src)
{
    ct_set_t(dst, ct_t(src));
    ct_set_ref(dst, ct_ref(src));
}
typedef unsigned int CValue[3];
static unsigned int cv_i(CValue *cv)
{
    return *(unsigned int *)cv;
}
static void cv_set_i(CValue *cv, unsigned int v)
{
    *(unsigned int *)cv = v;
}
static int cv_str_size(CValue *cv)
{
    return *(((unsigned int *)cv) + 1);
}
static void cv_set_str_size(CValue *cv, int size)
{
    *(((unsigned int *)cv) + 1) = size;
}
static void *cv_str_data(CValue *cv)
{
    return (void *)*(((unsigned int *)cv) + 2);
}
static void cv_set_str_data(CValue *cv, void *data)
{
    *(((unsigned int *)cv) + 2) = (unsigned int)data;
}
static void cv_copy(CValue *dst, CValue *src)
{
    cv_set_i(dst, cv_i(src));
    cv_set_str_size(dst, cv_str_size(src));
    cv_set_str_data(dst, cv_str_data(src));
}
typedef struct SValue {
    CType type;
    unsigned short r;
    CValue c;
    struct Sym *sym;
} SValue;
typedef unsigned char AttributeDef;
static int ad_ft(AttributeDef *ad)
{
    return *ad;
}
static void ad_set_ft(AttributeDef *ad, int ft)
{
    *ad = ft;
}
typedef struct Sym {
    int v;
    unsigned short r;
    int c;
    int sym_scope;
    int jnext;
    unsigned char func_type;
    CType type;
    struct Sym *next;
    struct Sym *prev;
    struct Sym *prev_tok;
} Sym;
static int sym_ft(Sym *s)
{
    return s->func_type;
}
static void sym_set_ft(Sym *s, int ft)
{
    s->func_type = ft;
}
static void sym_set_ad_ft(Sym *s, AttributeDef *ad)
{
    s->func_type = ad_ft(ad);
}
static void ad_set_sym_ft(AttributeDef *ad, Sym *s)
{
    ad_set_ft(ad, sym_ft(s));
}
typedef struct Section {
    unsigned int data_offset;
    unsigned char *data;
    unsigned int data_allocated;
    int sh_name;
    int sh_num;
    int sh_type;
    int sh_flags;
    int sh_info;
    int sh_addralign;
    int sh_entsize;
    unsigned int sh_size;
    Elf32_Addr sh_addr;
    unsigned int sh_offset;
    int nb_hashed_syms;
    struct Section *link;
    struct Section *reloc;
    struct Section *hash;
    struct Section *prev;
    char name[1];
} Section;
typedef char DLLReference;
static int dllr_level(DLLReference *d)
{
    return 0;
}
static void dllr_set_level(DLLReference *d, int level)
{
}
static char *dllr_name(DLLReference *d)
{
    return d;
}
static void dllr_set_name(DLLReference **pd, char *name)
{
    *pd = tcc_strdup(name);
}
typedef char FileSpec;
static char *fs_name(FileSpec *f)
{
    return f;
}
static void fs_set_name(FileSpec **pf, char *name)
{
    *pf = tcc_strdup(name);
}
typedef unsigned char BufferedFile;
static uint8_t *bf_buf_ptr(BufferedFile *bf)
{
    return *(uint8_t **)bf;
}
static void bf_set_buf_ptr(BufferedFile *bf, uint8_t *p)
{
    *(uint8_t **)bf = p;
}
static uint8_t *bf_buf_end(BufferedFile *bf)
{
    return *(uint8_t **)(bf + 4);
}
static void bf_set_buf_end(BufferedFile *bf, uint8_t *p)
{
    *(uint8_t **)(bf + 4) = p;
}
static int bf_fd(BufferedFile *bf)
{
    return *(int *)(bf + 8);
}
static void bf_set_fd(BufferedFile *bf, int fd)
{
    *(int *)(bf + 8) = fd;
}
static BufferedFile *bf_prev(BufferedFile *bf)
{
    return *(BufferedFile **)(bf + 12);
}
static void bf_set_prev(BufferedFile *bf, BufferedFile *prev)
{
    *(BufferedFile **)(bf + 12) = prev;
}
static int bf_line_num(BufferedFile *bf)
{
    return *(int *)(bf + 16);
}
static void bf_set_line_num(BufferedFile *bf, int line_num)
{
    *(int *)(bf + 16) = line_num;
}
static void bf_inc_line_num(BufferedFile *bf)
{
    bf_set_line_num(bf, bf_line_num(bf) + 1);
}
static char *bf_filename(BufferedFile *bf)
{
    return (char *)(bf + 20);
}
static unsigned char *bf_buffer(BufferedFile *bf)
{
    return bf + 1044;
}
typedef unsigned int SymAttr;
static SymAttr *sattr_at(SymAttr *tab, int index)
{
    return tab + index + index + index + index;
}
static unsigned sattr_got_offset(SymAttr *a)
{
    return *a;
}
static void sattr_set_got_offset(SymAttr *a, unsigned v)
{
    *a = v;
}
static unsigned sattr_plt_offset(SymAttr *a)
{
    return *(a + 1);
}
static void sattr_set_plt_offset(SymAttr *a, unsigned v)
{
    *(a + 1) = v;
}
static int sattr_plt_sym(SymAttr *a)
{
    return *(a + 2);
}
static void sattr_set_plt_sym(SymAttr *a, int v)
{
    *(a + 2) = v;
}
static int sattr_dyn_index(SymAttr *a)
{
    return *(a + 3);
}
static void sattr_set_dyn_index(SymAttr *a, int v)
{
    *(a + 3) = v;
}
struct TCCState {
    int nostdlib;
    int output_type;
    DLLReference **loaded_dlls;
    int nb_loaded_dlls;
    Section **sections;
    int nb_sections;
    Section **priv_sections;
    int nb_priv_sections;
    Section *got;
    Section *plt;
    Section *dynsym;
    Section *symtab;
    SymAttr *sym_attrs;
    int nb_sym_attrs;
    FileSpec **files;
    int nb_files;
    char *outfile;
};
static char *pstrcpy(char *buf, int buf_size, char *s);
 char *tcc_basename(char *name);
 char *tcc_fileextension (char *name);
 void tcc_free(void *ptr);
 void *tcc_malloc(unsigned int size);
 void *tcc_mallocz(unsigned int size);
 void *tcc_realloc(void *ptr, unsigned int size);
 char *tcc_strdup(char *str);
  void tcc_error(char *fmt, ...);
static void dynarray_add(void *ptab, int *nb_ptr, void *data);
static void cstr_ccat(CString *cstr, int ch);
static void cstr_cat(CString *cstr, char *str, int len);
static void cstr_reset(CString *cstr);
static void sym_free(Sym *sym);
static Sym *sym_push2(Sym **ps, int v, int t, int c);
static Sym *sym_push(int v, CType *type, int r, int c);
static void sym_pop(Sym **ptop, Sym *b, int keep);
static Sym *struct_find(int v);
static Sym *sym_find(int v);
static Sym *global_identifier_push(int v, int t, int c);
static void tcc_open_bf(TCCState *s1, char *filename);
static int tcc_open(TCCState *s1, char *filename);
static void tcc_close(void);
static int tcc_add_file_internal(TCCState *s1, char *filename, int flags);
static void tcc_add_crt(TCCState *s, char *filename);
static void tcc_add_library(TCCState *s, char *libraryname);
static void tcc_parse_args(TCCState *s, int argc, char **argv);
static TokenSym *tok_alloc(char *str, int len);
static char *get_tok_str(int v, CValue *cv);
static int set_idnum(int c, int val);
static void next_nomacro(void);
static void next(void);
static void tccpp_new(TCCState *s);
static void skip(int c);
static  void expect(char *msg);
static int is_space(int ch) {
    return ch == ' ' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r';
}
static int isid(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}
static int isnum(int c) {
    return c >= '0' && c <= '9';
}
static int isoct(int c) {
    return c >= '0' && c <= '7';
}
static int toup(int c) {
    return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}
static Sym *sym_free_first;
static void **sym_pools;
static int nb_sym_pools;
static Sym *global_stack;
static Sym *local_stack;
static CType char_pointer_type, func_old_type, int_type, size_type;
static SValue __vstack[1+  256], *vtop, *pvtop;
static int rsym, anon_sym, ind, loc;
static int const_wanted;
static int nocode_wanted;
static int global_expr;
static CType func_vt;
static int func_ind;
static char *funcname;
static int tccgen_compile(TCCState *s1);
static void check_vstack(void);
static void test_lvalue(void);
static void vpushi(int v);
static Elf32_Sym *elfsym(Sym *);
static void update_storage(Sym *sym);
static Sym *external_global_sym(int v, CType *type, int r);
static void vset(CType *type, int r, int v);
static void vswap(void);
static void vpush_global_sym(CType *type, int v);
static void vrote(SValue *e, int n);
static void vrott(int n);
static void vrotb(int n);
static void vpushv(SValue *v);
static void save_reg(int r);
static void save_reg_upstack(int r, int n);
static int get_reg(int rc);
static void save_regs(int n);
static void gaddrof(void);
static int gv(int rc);
static void gv2(int rc1, int rc2);
static void vpop(void);
static void gen_op(int op);
static int type_size(CType *type, int *a);
static void mk_pointer(CType *type);
static void vstore(void);
static void inc(int post, int c);
static int lvalue_type(int t);
static void indir(void);
static void unary(void);
static void expr_prod(void);
static void expr_sum(void);
static void gexpr(void);
static int expr_const(void);
static Section *text_section, *data_section, *bss_section;
static Section *common_section;
static Section *cur_text_section;
static Section *symtab_section;
static void tccelf_new(TCCState *s);
static void tccelf_begin_file(TCCState *s1);
static void tccelf_end_file(TCCState *s1);
static Section *new_section(TCCState *s1, char *name, int sh_type, int sh_flags);
static void section_realloc(Section *sec, unsigned int new_size);
static size_t section_add(Section *sec, Elf32_Addr size, int align);
static void *section_ptr_add(Section *sec, Elf32_Addr size);
static void section_reserve(Section *sec, unsigned int size);
static Section *new_symtab(TCCState *s1, char *symtab_name, int sh_type, int sh_flags, char *strtab_name, char *hash_name, int hash_sh_flags);
static void put_extern_sym2(Sym *sym, int sh_num, Elf32_Addr value, unsigned int size);
static void put_extern_sym(Sym *sym, Section *section, Elf32_Addr value, unsigned int size);
static void greloc(Section *s, Sym *sym, unsigned int offset, int type);
static void greloca(Section *s, Sym *sym, unsigned int offset, int type, Elf32_Addr addend);
static int put_elf_str(Section *s, char *sym);
static int put_elf_sym(Section *s, Elf32_Addr value, unsigned int size, int info, int other, int shndx, char *name);
static int set_elf_sym(Section *s, Elf32_Addr value, unsigned int size, int info, int other, int shndx, char *name);
static int find_elf_sym(Section *s, char *name);
static void put_elf_reloc(Section *symtab, Section *s, unsigned int offset, int type, int symbol);
static void put_elf_reloca(Section *symtab, Section *s, unsigned int offset, int type, int symbol, Elf32_Addr addend);
static void resolve_common_syms(TCCState *s1);
static void relocate_syms(TCCState *s1, Section *symtab, int do_resolve);
static void relocate_section(TCCState *s1, Section *s);
static int tcc_object_type(int fd, Elf32_Ehdr *h);
static int tcc_load_object_file(TCCState *s1, int fd, unsigned int file_offset);
static void build_got_entries(TCCState *s1);
static SymAttr *get_sym_attr(TCCState *s1, int index, int alloc);
static Elf32_Addr get_elf_sym_addr(TCCState *s, char *name, int err);
static uint8_t *parse_comment(uint8_t *p);
static int handle_eob(void);
static int code_reloc (int reloc_type);
static int gotplt_entry_type (int reloc_type);
static unsigned create_plt_entry(TCCState *s1, unsigned got_offset, SymAttr *attr);
static void relocate(TCCState *s1, Elf32_Rel *rel, int type, unsigned char *ptr, Elf32_Addr addr, Elf32_Addr val);
static void relocate_plt(TCCState *s1);
static int reg_classes[4];
static void gsym_addr(int t, int a);
static void gsym(int t);
static void load(int r, SValue *sv);
static void store(int r, SValue *v);
static void gfunc_call(int nb_args);
static void gfunc_prolog(CType *func_type);
static void gfunc_epilog(void);
static int gjmp(int t);
static void gjmp_addr(int a);
static int gtst(int inv, int t);
static void gen_opi(int op);
static void o(unsigned int c);
static uint16_t read16le(unsigned char *p) {
    return p[0] | (uint16_t)p[1] << 8;
}
static void write16le(unsigned char *p, uint16_t x) {
    p[0] = x & 255;  p[1] = x >> 8 & 255;
}
static uint32_t read32le(unsigned char *p) {
  return read16le(p) | (uint32_t)read16le(p + 2) << 16;
}
static void write32le(unsigned char *p, uint32_t x) {
    write16le(p, x);  write16le(p + 2, x >> 16);
}
static void add32le(unsigned char *p, int32_t x) {
    write32le(p, read32le(p) + x);
}
static void g(int c);
static void gen_le32(int c);
static void gen_addr32(int r, Sym *sym, int c);
static TCCState *tcc_state;
static BufferedFile *file;
static int tok;
static CValue tokc;
static CString tokcstr;
static int tok_ident;
static TokenSym **table_ident;
static TokenSym *hash_ident[16384];
static char token_buf[1024 + 1];
static unsigned char isidnum_table[256 - (-1)];
static char tcc_keywords[148] =
     "int" "\0"
     "void" "\0"
     "char" "\0"
     "if" "\0"
     "else" "\0"
     "while" "\0"
     "break" "\0"
     "return" "\0"
     "for" "\0"
     "extern" "\0"
     "static" "\0"
     "unsigned" "\0"
     "continue" "\0"
     "switch" "\0"
     "case" "\0"
     "short" "\0"
     "struct" "\0"
     "typedef" "\0"
     "default" "\0"
     "sizeof" "\0"
     "memcpy" "\0"
     "memmove" "\0"
     "memset" "\0"
;
static unsigned char tok_two_chars[64] =
 {
    '<','=', 0x9e,
    '>','=', 0x9d,
    '!','=', 0x95,
    '&','&', 0xa0,
    '|','|', 0xa1,
    '+','+', 0xa4,
    '-','-', 0xa2,
    '=','=', 0x94,
    '<','<', 0x01,
    '>','>', 0x02,
    '+','=', 0xab,
    '-','=', 0xad,
    '*','=', 0xaa,
    '/','=', 0xaf,
    '%','=', 0xa5,
    '&','=', 0xa6,
    '^','=', 0xde,
    '|','=', 0xfc,
    '-','>', 0xc7,
    '.','.', 0xa8,
    '#','#', 0xca,
    0
};
static void skip(int c)
{
    if (tok != c)
        tcc_error("'%c' expected (got \"%s\")", c, get_tok_str(tok, &tokc));
    next();
}
static void expect(char *msg)
{
    tcc_error("%s expected", msg);
}
static void cstr_realloc(CString *cstr, int new_size)
{
    int size;
    size = cstr_size_allocated(cstr);
    if (size < 8)
        size = 8;
    while (size < new_size)
        size = size * 2;
    cstr_set_data(cstr, tcc_realloc(cstr_data(cstr), size));
    cstr_set_size_allocated(cstr, size);
}
static void cstr_ccat(CString *cstr, int ch)
{
    int size;
    size = cstr_size(cstr) + 1;
    if (size > cstr_size_allocated(cstr))
        cstr_realloc(cstr, size);
    ((unsigned char *)cstr_data(cstr))[size - 1] = ch;
    cstr_set_size(cstr, size);
}
static void cstr_cat(CString *cstr, char *str, int len)
{
    int size;
    if (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr_size(cstr) + len;
    if (size > cstr_size_allocated(cstr))
        cstr_realloc(cstr, size);
    memmove(((unsigned char *)cstr_data(cstr)) + cstr_size(cstr), str, len);
    cstr_set_size(cstr, size);
}
static void cstr_reset(CString *cstr)
{
    cstr_set_size(cstr, 0);
}
static TokenSym *tok_alloc_new(TokenSym **pts, char *str, int len)
{
    TokenSym *ts, **ptable;
    int i;
    if (tok_ident >= 0x10000000)
        tcc_error("memory full (symbols)");
    i = tok_ident - 256;
    if ((i % 512) == 0) {
        ptable = tcc_realloc(table_ident, (i + 512) * sizeof(TokenSym *));
        table_ident = ptable;
    }
    ts = tcc_realloc(0, 21 + len);
    table_ident[i] = ts;
    ts_set_tok(ts, tok_ident++);
    ts_set_sym_struct(ts, ((void*)0));
    ts_set_sym_identifier(ts, ((void*)0));
    ts_set_len(ts, len);
    ts_set_hash_next(ts, ((void*)0));
    memcpy(ts_str(ts), str, len);
    ts_str(ts)[len] = '\0';
    *pts = ts;
    return ts;
}
static TokenSym *tok_alloc(char *str, int len)
{
    TokenSym *ts, **pts;
    int i;
    unsigned int h;
    h = 1;
    for(i=0;i<len;i++)
        h = ((h) + ((h) << 5) + ((h) >> 27) + (((unsigned char *)str)[i]));
    h &= (16384 - 1);
    pts = &hash_ident[h];
    for(;;) {
        ts = *pts;
        if (!ts)
            break;
        if (ts_len(ts) == len && !memcmp(ts_str(ts), str, len))
            return ts;
        pts = ts_hash_next_ref(ts);
    }
    return tok_alloc_new(pts, str, len);
}
static char *get_tok_str(int v, CValue *cv)
{
    static char buf[64];
    char *p = buf;
    if (v == 0xb5 || v == 0xb6 || v == 0xce || v == 0xcf) {
        sprintf(p, "%u", cv_i(cv));
    } else if (v == 0xb3) {
        return "<char>";
    } else if (v == 0xbe || v == 0xbf) {
        return (char*)cv_str_data(cv);
    } else if (v == 0xb9) {
        return "<string>";
    } else if (v == 0x9c) {
        *p++ = '<';
        *p = '\0';
    } else if (v == 0x9f) {
        *p++ = '>';
        *p = '\0';
    } else if (v == 0xc8) {
        return strcpy(p, "...");
    } else if (v == 0x81) {
        return strcpy(p, "<<=");
    } else if (v == 0x82) {
        return strcpy(p, ">>=");
    } else if (v == (-1)) {
        return strcpy(p, "<eof>");
    } else {
        if (v < 256) {
            unsigned char *q = tok_two_chars;
            while (*q) {
                if (q[2] == v) {
                    *p++ = q[0];
                    *p++ = q[1];
                    *p = '\0';
            return buf;
        }
        q += 3;
    }
        if (v >= 127) {
            sprintf(buf, "<%02x>", v);
            return buf;
        }
            *p++ = v;
            *p = '\0';
        } else if (v < tok_ident) {
            return ts_str(table_ident[v - 256]);
        } else if (v >= 0x10000000) {
            sprintf(p, "L.%u", v - 0x10000000);
        } else {
            return ((void*)0);
        }
    }
    return buf;
}
static int handle_eob(void)
{
    BufferedFile *bf = file;
    int len;
    if (bf_buf_ptr(bf) >= bf_buf_end(bf)) {
        if (bf_fd(bf) >= 0) {
            len = 8192;
            len = read(bf_fd(bf), bf_buffer(bf), len);
            if (len < 0)
                len = 0;
        } else {
            len = 0;
        }
        bf_set_buf_ptr(bf, bf_buffer(bf));
        bf_set_buf_end(bf, bf_buffer(bf) + len);
        *bf_buf_end(bf) = '\\';
    }
    if (bf_buf_ptr(bf) < bf_buf_end(bf)) {
        return *bf_buf_ptr(bf);
    } else {
        bf_set_buf_ptr(bf, bf_buf_end(bf));
        return (-1);
    }
}
static int next_src_char(uint8_t **pp)
{
    uint8_t *p = *pp + 1;
    if (p >= bf_buf_end(file)) {
        bf_set_buf_ptr(file, p);
        if (handle_eob() == (-1)) {
            *pp = bf_buf_ptr(file);
            return (-1);
        }
        p = bf_buf_ptr(file);
    }
    *pp = p;
    return *p;
}
static uint8_t *parse_line_comment(uint8_t *p)
{
    int c;
    p++;
    for(;;) {
        c = *p;
        if (c == '\n' || c == (-1)) {
            break;
        } else if (c == '\\') {
            bf_set_buf_ptr(file, p);
            c = handle_eob();
            p = bf_buf_ptr(file);
            if (c == '\n' || c == (-1))
                break;
            if (c == '\\')
                continue;
            p++;
        } else {
            p++;
        }
    }
    return p;
}
static uint8_t *parse_comment(uint8_t *p)
{
    int c, done;
    p++;
    done = 0;
    while (!done) {
        for(;;) {
            c = *p;
            if (c == '\n' || c == '*' || c == '\\')
                break;
            p++;
            c = *p;
            if (c == '\n' || c == '*' || c == '\\')
                break;
            p++;
        }
        if (c == '\n') {
            bf_inc_line_num(file);
            p++;
        } else if (c == '*') {
            p++;
            for(;;) {
                c = *p;
                if (c == '*') {
                    p++;
                } else if (c == '/') {
                    done = 1;
                    break;
                } else if (c == '\\') {
                    bf_set_buf_ptr(file, p);
                    c = handle_eob();
                    p = bf_buf_ptr(file);
                    if (c == (-1))
                        tcc_error("unexpected end of file in comment");
                    break;
                } else {
                    break;
                }
            }
        } else {
            bf_set_buf_ptr(file, p);
            c = handle_eob();
            p = bf_buf_ptr(file);
            if (c == (-1)) {
                tcc_error("unexpected end of file in comment");
            } else if (c == '\\') {
                p++;
            }
        }
    }
    p++;
    return p;
}
static int set_idnum(int c, int val)
{
    int prev = isidnum_table[c - (-1)];
    isidnum_table[c - (-1)] = val;
    return prev;
}
static uint8_t *parse_pp_string(uint8_t *p, int sep, CString *str)
{
    int c;
    p++;
    for(;;) {
        c = *p;
        if (c == sep) {
            break;
        } else if (c == '\\') {
            bf_set_buf_ptr(file, p);
            c = handle_eob();
            p = bf_buf_ptr(file);
            if (c == (-1)) {
                tcc_error("missing terminating %c character", sep);
            } else if (c == '\\') {
                c = next_src_char(&p);
                if (c == '\n') {
                    bf_inc_line_num(file);
                    p++;
                } else if (c == '\r') {
                    c = next_src_char(&p);
                    if (c != '\n')
                        expect("'\n' after '\r'");
                    bf_inc_line_num(file);
                    p++;
                } else if (c == (-1)) {
                    tcc_error("missing terminating %c character", sep);
                } else {
                    cstr_ccat(str, '\\');
                    cstr_ccat(str, c);
                    p++;
                }
            }
        } else if (c == '\n') {
            bf_inc_line_num(file);
            cstr_ccat(str, c);
            p++;
        } else if (c == '\r') {
            c = next_src_char(&p);
            if (c != '\n') {
                cstr_ccat(str, '\r');
            } else {
                bf_inc_line_num(file);
                cstr_ccat(str, c);
                p++;
            }
        } else {
            cstr_ccat(str, c);
            p++;
        }
    }
    p++;
    return p;
}
static void parse_escape_string(CString *outstr, uint8_t *buf)
{
    int c, n;
    uint8_t *p;
    p = buf;
    for(;;) {
        c = *p;
        if (c == '\0')
            break;
        if (c == '\\') {
            p++;
            c = *p;
            if (isoct(c)) {
                n = c - '0';
                p++;
                c = *p;
                if (isoct(c)) {
                    n = n * 8 + c - '0';
                    p++;
                    c = *p;
                    if (isoct(c)) {
                        n = n * 8 + c - '0';
                        p++;
                    }
                }
                c = n;
                cstr_ccat(outstr, c);
                continue;
            } else if (c == 'x' || c == 'u' || c == 'U') {
                p++;
                n = 0;
                for(;;) {
                    c = *p;
                    if (c >= 'a' && c <= 'f')
                        c = c - 'a' + 10;
                    else if (c >= 'A' && c <= 'F')
                        c = c - 'A' + 10;
                    else if (isnum(c))
                        c = c - '0';
                    else
                        break;
                    n = n * 16 + c;
                    p++;
                }
                c = n;
                cstr_ccat(outstr, c);
                continue;
            } else if (c == 'a') {
                c = '\a';
            } else if (c == 'b') {
                c = '\b';
            } else if (c == 'f') {
                c = '\f';
            } else if (c == 'n') {
                c = '\n';
            } else if (c == 'r') {
                c = '\r';
            } else if (c == 't') {
                c = '\t';
            } else if (c == 'v') {
                c = '\v';
            }
        }
        p++;
        cstr_ccat(outstr, c);
    }
    cstr_ccat(outstr, '\0');
}
static void parse_string(char *s, int len)
{
    uint8_t buf[1000], *p = buf;
    int sep;
    sep = *s++;
    len -= 2;
    if (len >= sizeof buf)
        p = tcc_malloc(len + 1);
    memcpy(p, s, len);
    p[len] = 0;
    cstr_reset(&tokcstr);
    parse_escape_string(&tokcstr, p);
    if (p != buf)
        tcc_free(p);
    if (sep == '\'') {
        int i, n, c;
        tok = 0xb3;
        n = cstr_size(&tokcstr) - 1;
        if (n < 1)
            tcc_error("empty character constant");
        for (c = i = 0; i < n; ++i) {
            c = (c << 8) | ((char *)cstr_data(&tokcstr))[i];
        }
        cv_set_i(&tokc, c);
    } else {
        cv_set_str_size(&tokc, cstr_size(&tokcstr));
        cv_set_str_data(&tokc, cstr_data(&tokcstr));
        tok = 0xb9;
    }
}
static void parse_number(char *p)
{
    int b, t, ch;
    char *q;
    q = token_buf;
    ch = *p++;
    t = ch;
    ch = *p++;
    *q++ = t;
    b = 10;
    if (t == '.') {
        tcc_error("floating-point constants are not supported in tcc_27_alt");
    } else if (t == '0') {
        if (ch == 'x' || ch == 'X') {
            q--;
            ch = *p++;
            b = 16;
        }
    }
    while (1) {
        if (ch >= 'a' && ch <= 'f')
            t = ch - 'a' + 10;
        else if (ch >= 'A' && ch <= 'F')
            t = ch - 'A' + 10;
        else if (isnum(ch))
            t = ch - '0';
        else
            break;
        if (t >= b)
            break;
        if (q >= token_buf + 1024) {
            tcc_error("number too long");
        }
        *q++ = ch;
        ch = *p++;
    }
    if (ch == '.' ||
        ((ch == 'e' || ch == 'E') && b == 10) ||
        ((ch == 'p' || ch == 'P') && (b == 16 || b == 2))) {
        tcc_error("floating-point constants are not supported in tcc_27_alt");
    } else {
        unsigned int n, n1;
        int lcount, ucount;
        char *p1;
        *q = '\0';
        q = token_buf;
        if (b == 10 && *q == '0') {
            b = 8;
            q++;
        }
        n = 0;
        while(1) {
            t = *q++;
            if (t == '\0')
                break;
            else if (t >= 'a')
                t = t - 'a' + 10;
            else if (t >= 'A')
                t = t - 'A' + 10;
            else
                t = t - '0';
            if (t >= b)
                tcc_error("invalid digit");
            n1 = n;
            n = n * b + t;
            if (n1 >= 0x10000000U && n / b != n1)
                ;
        }
        lcount = ucount = 0;
        p1 = p;
        for(;;) {
            t = toup(ch);
            if (t == 'L') {
                if (lcount >= 2)
                    tcc_error("three 'l's in integer constant");
                if (lcount && *(p - 1) != ch)
                    tcc_error("incorrect integer suffix: %s", p1);
                lcount++;
                ch = *p++;
            } else if (t == 'U') {
                if (ucount >= 1)
                    tcc_error("two 'u's in integer constant");
                ucount++;
                ch = *p++;
            } else {
                break;
            }
        }
        if (ucount == 0 && b == 10) {
            if (n >= 0x80000000U)
                ucount = 1;
        } else {
            if (n >= 0x80000000U)
                ucount = 1;
        }
        tok = 0xb5;
        if (lcount > 1)
            tcc_error("64-bit integer constants are not supported in tcc_27_alt");
        if (lcount) {
            tok = 0xce;
        }
	if (ucount)
	    ++tok;
        cv_set_i(&tokc, n);
    }
    if (ch)
        tcc_error("invalid number\n");
}
static uint8_t *scan_ident_token(uint8_t *p, int c)
{
    TokenSym *ts;
    uint8_t *p1;
    unsigned int h;
    p1 = p;
    h = 1;
    h = ((h) + ((h) << 5) + ((h) >> 27) + (c));
    while (c = *++p, isidnum_table[c - (-1)] & (2|4))
        h = ((h) + ((h) << 5) + ((h) >> 27) + (c));
    if (c != '\\') {
        TokenSym **pts;
        h &= (16384 - 1);
        pts = &hash_ident[h];
        for(;;) {
            ts = *pts;
            if (!ts) {
                ts = tok_alloc_new(pts, (char *) p1, p - p1);
                break;
            }
            if (ts_len(ts) == p - p1 && !memcmp(ts_str(ts), p1, p - p1))
                break;
            pts = ts_hash_next_ref(ts);
        }
    } else {
        cstr_reset(&tokcstr);
        cstr_cat(&tokcstr, (char *) p1, p - p1);
        p--;
        c = next_src_char(&p);
        while (isidnum_table[c - (-1)] & (2|4))
        {
            cstr_ccat(&tokcstr, c);
            c = next_src_char(&p);
        }
        ts = tok_alloc(cstr_data(&tokcstr), cstr_size(&tokcstr));
    }
    tok = ts_tok(ts);
    return p;
}
static uint8_t *scan_number_token(uint8_t *p, int t, int c)
{
    cstr_reset(&tokcstr);
    for(;;) {
        cstr_ccat(&tokcstr, t);
        if (!((isidnum_table[c - (-1)] & (2|4))
              || c == '.'
              || ((c == '+' || c == '-')
                  && (((t == 'e' || t == 'E')
                        && !(((char*)cstr_data(&tokcstr))[0] == '0'
                            && toup(((char*)cstr_data(&tokcstr))[1]) == 'X'))
                      || t == 'p' || t == 'P'))))
            break;
        t = c;
        c = next_src_char(&p);
    }
    cstr_ccat(&tokcstr, '\0');
    cv_set_str_size(&tokc, cstr_size(&tokcstr));
    cv_set_str_data(&tokc, cstr_data(&tokcstr));
    tok = 0xbe;
    return p;
}
static void next_nomacro1(void)
{
    int t, c;
    uint8_t *p;
    p = bf_buf_ptr(file);
    for (;;) {
        c = *p;
        if (c == ' ' || c == '\t') {
            p++;
            while (isidnum_table[*p - (-1)] & 1)
                ++p;
            continue;
        } else if (c == '\f' || c == '\v' || c == '\r') {
            p++;
            continue;
        } else if (c == '\\') {
            bf_set_buf_ptr(file, p);
            c = handle_eob();
            p = bf_buf_ptr(file);
            if (c != (-1)) {
                if (c == '\\')
                    p++;
                continue;
            }
            tok = (-1);
            break;
        } else if (c == '\n') {
            bf_inc_line_num(file);
            p++;
            continue;
        } else if (c == '#') {
            tcc_error("preprocessor directives are not supported in tcc_27_alt");
            break;
        } else if (c == '$') {
            if (!(isidnum_table[c - (-1)] & 2)) {
                tok = c;
                p++;
                break;
            }
            p = scan_ident_token(p, c);
            break;
        } else if (isid(c)) {
            p = scan_ident_token(p, c);
            break;
        } else if (isnum(c)) {
            t = c;
            c = next_src_char(&p);
            p = scan_number_token(p, t, c);
            break;
        } else if (c == '.') {
            c = next_src_char(&p);
            if (isnum(c)) {
                p = scan_number_token(p, '.', c);
            } else if ((isidnum_table['.' - (-1)] & 2)
                       && (isidnum_table[c - (-1)] & (2|4))) {
                p--;
                p = scan_ident_token(p, '.');
            } else if (c == '.') {
                c = next_src_char(&p);
                if (c == '.') {
                    p++;
                    tok = 0xc8;
                } else {
                    *--p = '.';
                    tok = '.';
                }
            } else {
                tok = '.';
            }
            break;
        } else if (c == '\'' || c == '\"') {
            cstr_reset(&tokcstr);
            cstr_ccat(&tokcstr, c);
            p = parse_pp_string(p, c, &tokcstr);
            cstr_ccat(&tokcstr, c);
            cstr_ccat(&tokcstr, '\0');
            cv_set_str_size(&tokc, cstr_size(&tokcstr));
            cv_set_str_data(&tokc, cstr_data(&tokcstr));
            tok = 0xbf;
            break;
        } else if (c == '<') {
            c = next_src_char(&p);
            if (c == '=') {
                p++;
                tok = 0x9e;
            } else if (c == '<') {
                c = next_src_char(&p);
                if (c == '=') {
                    p++;
                    tok = 0x81;
                } else {
                    tok = 0x01;
                }
            } else {
                tok = 0x9c;
            }
            break;
        } else if (c == '>') {
            c = next_src_char(&p);
            if (c == '=') {
                p++;
                tok = 0x9d;
            } else if (c == '>') {
                c = next_src_char(&p);
                if (c == '=') {
                    p++;
                    tok = 0x82;
                } else {
                    tok = 0x02;
                }
            } else {
                tok = 0x9f;
            }
            break;
        } else if (c == '&') {
            c = next_src_char(&p);
            if (c == '&') {
                p++;
                tok = 0xa0;
            } else if (c == '=') {
                p++;
                tok = 0xa6;
            } else {
                tok = '&';
            }
            break;
        } else if (c == '|') {
            c = next_src_char(&p);
            if (c == '|') {
                p++;
                tok = 0xa1;
            } else if (c == '=') {
                p++;
                tok = 0xfc;
            } else {
                tok = '|';
            }
            break;
        } else if (c == '+') {
            c = next_src_char(&p);
            if (c == '+') {
                p++;
                tok = 0xa4;
            } else if (c == '=') {
                p++;
                tok = 0xab;
            } else {
                tok = '+';
            }
            break;
        } else if (c == '-') {
            c = next_src_char(&p);
            if (c == '-') {
                p++;
                tok = 0xa2;
            } else if (c == '=') {
                p++;
                tok = 0xad;
            } else if (c == '>') {
                p++;
                tok = 0xc7;
            } else {
                tok = '-';
            }
            break;
        } else if (c == '!') {
            c = next_src_char(&p); if (c == '=') { p++; tok = 0x95; } else { tok = '!'; } break;
        } else if (c == '=') {
            c = next_src_char(&p); if (c == '=') { p++; tok = 0x94; } else { tok = '='; } break;
        } else if (c == '*') {
            c = next_src_char(&p); if (c == '=') { p++; tok = 0xaa; } else { tok = '*'; } break;
        } else if (c == '%') {
            c = next_src_char(&p); if (c == '=') { p++; tok = 0xa5; } else { tok = '%'; } break;
        } else if (c == '^') {
            c = next_src_char(&p); if (c == '=') { p++; tok = 0xde; } else { tok = '^'; } break;
        } else if (c == '/') {
            c = next_src_char(&p);
            if (c == '*') {
                p = parse_comment(p);
                tok = ' ';
                continue;
            } else if (c == '/') {
                p = parse_line_comment(p);
                tok = ' ';
                continue;
            } else if (c == '=') {
                p++;
                tok = 0xaf;
            } else {
                tok = '/';
            }
            break;
        } else if (c == '(' || c == ')' || c == '[' || c == ']' ||
                   c == '{' || c == '}' || c == ',' || c == ';' ||
                   c == ':' || c == '?' || c == '~' || c == '@') {
            tok = c;
            p++;
            break;
        } else {
            if (c >= 0x80 && c <= 0xFF) {
                p = scan_ident_token(p, c);
                break;
            }
            tcc_error("unrecognized character \\x%02x", c);
            break;
        }
    }
    bf_set_buf_ptr(file, p);
}
static void next_nomacro(void)
{
    next_nomacro1();
    while (tok < 256 && (isidnum_table[tok - (-1)] & 1))
        next_nomacro1();
}
static void next(void)
{
    next_nomacro();
    if (tok == 0xbe) {
        parse_number((char *)cv_str_data(&tokc));
    } else if (tok == 0xbf) {
        parse_string((char *)cv_str_data(&tokc), cv_str_size(&tokc) - 1);
    }
}
static void tccpp_new(TCCState *s)
{
    int i, c;
    char *p, *r;
    for(i = (-1); i<128; i++)
        set_idnum(i,
            is_space(i) ? 1
            : isid(i) ? 2
            : isnum(i) ? 4
            : 0);
    for(i = 128; i<256; i++)
        set_idnum(i, 2);
    memset(hash_ident, 0, 16384 * sizeof(TokenSym *));
    tok_ident = 256;
    p = tcc_keywords;
    while (*p) {
        r = p;
        for(;;) {
            c = *r++;
            if (c == '\0')
                break;
        }
        tok_alloc(p, r - p - 1);
        p = r;
    }
}
static int rsym, anon_sym, ind, loc;
static Sym *sym_free_first;
static void **sym_pools;
static int nb_sym_pools;
static Sym *global_stack;
static Sym *local_stack;
static int local_scope;
static int in_sizeof;
static SValue __vstack[1+256], *vtop, *pvtop;
static int const_wanted;
static int nocode_wanted;
static int global_expr;
static CType func_vt;
static int func_ind;
static char *funcname;
static CType char_pointer_type, func_old_type, int_type, size_type, ptrdiff_type;
static void gen_cast(CType *type);
static void gen_cast_s(int t);
static CType *pointed_type(CType *type);
static int is_compatible_types(CType *type1, CType *type2);
static int parse_btype(CType *type, AttributeDef *ad);
static CType *type_decl(CType *type, AttributeDef *ad, int *v, int td);
static void init_putv(CType *type, Section *sec, unsigned int c);
static void decl_initializer(CType *type, Section *sec, unsigned int c, int first);
static void block(int *bsym, int *csym, int is_expr);
static void decl_initializer_alloc(CType *type, AttributeDef *ad, int r, int has_init, int v, int scope);
static void decl(int l);
static int decl0(int l, int is_for_loop_init, Sym *);
static void expr_eq(void);
static void vpush(CType *type);
static int gvtst(int inv, int t);
static void gv_dup(void);
static void test_lvalue(void)
{
    if (!(vtop->r & 0x0100))
        expect("lvalue");
}
static void check_vstack(void)
{
    if (pvtop != vtop)
        tcc_error("internal compiler error: vstack leak (%d)", vtop - pvtop);
}
static int tccgen_compile(TCCState *s1)
{
    cur_text_section = ((void*)0);
    funcname = "";
    anon_sym = 0x10000000;
    const_wanted = 0;
    nocode_wanted = 0x80000000;
    ct_set_t(&int_type, 3);
    ct_set_t(&char_pointer_type, 1);
    mk_pointer(&char_pointer_type);
    ct_set_t(&size_type, 3 | 0x0010);
    ct_set_t(&ptrdiff_type, 3);
    ct_set_t(&func_old_type, 6);
    ct_set_ref(&func_old_type, sym_push(0x20000000, &int_type, 0, 0));
    sym_set_ft(ct_ref(&func_old_type), 2);
    next();
    decl(0x0030);
    check_vstack();
    return 0;
}
static Elf32_Sym *elfsym(Sym *s)
{
  if (!s || !s->c)
    return ((void*)0);
  return &((Elf32_Sym *)symtab_section->data)[s->c];
}
static void update_storage(Sym *sym)
{
    Elf32_Sym *esym;
    int sym_bind, old_sym_bind;
    esym = elfsym(sym);
    if (!esym)
        return;
    if (ct_t(&sym->type) & 0x00002000)
        sym_bind = 0;
    else
        sym_bind = 1;
    old_sym_bind = (((unsigned char) (esy_info(esym))) >> 4);
    if (sym_bind != old_sym_bind) {
        esy_set_info(esym, (((sym_bind) << 4) + ((((esy_info(esym)) & 0xf)) & 0xf)));
    }
}
static void put_extern_sym2(Sym *sym, int sh_num,
                            Elf32_Addr value, unsigned int size)
{
    int sym_type, sym_bind, info, other, t;
    Elf32_Sym *esym;
    char *name;
    if (!sym->c) {
        name = get_tok_str(sym->v, ((void*)0));
        t = ct_t(&sym->type);
        if ((t & 0x000f) == 6) {
            sym_type = 2;
        } else if ((t & 0x000f) == 0) {
            sym_type = 0;
        } else {
            sym_type = 1;
        }
        if (t & 0x00002000)
            sym_bind = 0;
        else
            sym_bind = 1;
        other = 0;
        info = (((sym_bind) << 4) + ((sym_type) & 0xf));
        sym->c = put_elf_sym(symtab_section, value, size, info, other, sh_num, name);
    } else {
        esym = elfsym(sym);
        esy_set_value(esym, value);
        esy_set_size(esym, size);
        esy_set_shndx(esym, sh_num);
    }
    update_storage(sym);
}
static void put_extern_sym(Sym *sym, Section *section,
                           Elf32_Addr value, unsigned int size)
{
    int sh_num = section ? section->sh_num : 0;
    put_extern_sym2(sym, sh_num, value, size);
}
static void greloca(Section *s, Sym *sym, unsigned int offset, int type,
                     Elf32_Addr addend)
{
    int c = 0;
    if (nocode_wanted && s == cur_text_section)
        return;
    if (sym) {
        if (0 == sym->c)
            put_extern_sym(sym, ((void*)0), 0, 0);
        c = sym->c;
    }
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}
static void greloc(Section *s, Sym *sym, unsigned int offset, int type)
{
    greloca(s, sym, offset, type, 0);
}
static Sym *__sym_malloc(void)
{
    Sym *sym_pool, *sym, *last_sym;
    int i;
    sym_pool = tcc_malloc((8192 / sizeof(Sym)) * sizeof(Sym));
    dynarray_add(&sym_pools, &nb_sym_pools, sym_pool);
    last_sym = sym_free_first;
    sym = sym_pool;
    for(i = 0; i < (8192 / sizeof(Sym)); i++) {
        sym->next = last_sym;
        last_sym = sym;
        sym++;
    }
    sym_free_first = last_sym;
    return last_sym;
}
static Sym *sym_malloc(void)
{
    Sym *sym;
    sym = sym_free_first;
    if (!sym)
        sym = __sym_malloc();
    sym_free_first = sym->next;
    return sym;
}
static void sym_free(Sym *sym)
{
    sym->next = sym_free_first;
    sym_free_first = sym;
}
static Sym *sym_push2(Sym **ps, int v, int t, int c)
{
    Sym *s;
    s = sym_malloc();
    memset(s, 0, sizeof *s);
    s->v = v;
    ct_set_t(&s->type, t);
    s->c = c;
    s->prev = *ps;
    *ps = s;
    return s;
}
static Sym *struct_find(int v)
{
    v -= 256;
    if ((unsigned)v >= (unsigned)(tok_ident - 256))
        return ((void*)0);
    return ts_sym_struct(table_ident[v]);
}
static Sym *sym_find(int v)
{
    v -= 256;
    if ((unsigned)v >= (unsigned)(tok_ident - 256))
        return ((void*)0);
    return ts_sym_identifier(table_ident[v]);
}
static Sym *sym_push(int v, CType *type, int r, int c)
{
    Sym *s, **ps;
    TokenSym *ts;
    if (local_stack)
        ps = &local_stack;
    else
        ps = &global_stack;
    s = sym_push2(ps, v, ct_t(type), c);
    ct_set_ref(&s->type, ct_ref(type));
    s->r = r;
    if (!(v & 0x20000000) && (v & ~0x40000000) < 0x10000000) {
        ts = table_ident[(v & ~0x40000000) - 256];
        if (v & 0x40000000)
            ps = ts_sym_struct_ref(ts);
        else
            ps = ts_sym_identifier_ref(ts);
        s->prev_tok = *ps;
        *ps = s;
        s->sym_scope = local_scope;
        if (s->prev_tok && s->prev_tok->sym_scope == s->sym_scope)
            tcc_error("redeclaration of '%s'",
                get_tok_str(v & ~0x40000000, ((void*)0)));
    }
    return s;
}
static Sym *global_identifier_push(int v, int t, int c)
{
    Sym *s, **ps;
    s = sym_push2(&global_stack, v, t, c);
    if (v < 0x10000000) {
        ps = ts_sym_identifier_ref(table_ident[v - 256]);
        while (*ps != ((void*)0) && (*ps)->sym_scope)
            ps = &(*ps)->prev_tok;
        s->prev_tok = *ps;
        *ps = s;
    }
    return s;
}
static void sym_pop(Sym **ptop, Sym *b, int keep)
{
    Sym *s, *ss, **ps;
    TokenSym *ts;
    int v;
    s = *ptop;
    while(s != b) {
        ss = s->prev;
        v = s->v;
        if (!(v & 0x20000000) && (v & ~0x40000000) < 0x10000000) {
            ts = table_ident[(v & ~0x40000000) - 256];
            if (v & 0x40000000)
                ps = ts_sym_struct_ref(ts);
            else
                ps = ts_sym_identifier_ref(ts);
            *ps = s->prev_tok;
        }
	if (!keep)
	    sym_free(s);
        s = ss;
    }
    if (!keep)
	*ptop = b;
}
static void vsetc(CType *type, int r, CValue *vc)
{
    int v;
    if (vtop >= (__vstack + 1) + (256 - 1))
        tcc_error("memory full (vstack)");
    if (vtop >= (__vstack + 1) && !nocode_wanted) {
        v = vtop->r & 0x003f;
        if (v == 0x0033 || (v & ~1) == 0x0034)
            gv(0x0001);
    }
    vtop++;
    vtop->type = *type;
    vtop->r = r;
    cv_copy(&vtop->c, vc);
    vtop->sym = ((void*)0);
}
static void vswap(void)
{
    SValue tmp;
    if (vtop >= (__vstack + 1) && !nocode_wanted) {
        int v = vtop->r & 0x003f;
        if (v == 0x0033 || (v & ~1) == 0x0034)
            gv(0x0001);
    }
    tmp = vtop[0];
    vtop[0] = vtop[-1];
    vtop[-1] = tmp;
}
static void vpop(void)
{
    int v;
    v = vtop->r & 0x003f;
    if (v == 0x0034 || v == 0x0035) {
        gsym(cv_i(&vtop->c));
    }
    vtop--;
}
static void vpush(CType *type)
{
    vset(type, 0x0030, 0);
}
static void vpushi(int v)
{
    CValue cval;
    cv_set_i(&cval, v);
    vsetc(&int_type, 0x0030, &cval);
}
static void vpushs(Elf32_Addr v)
{
  CValue cval;
  cv_set_i(&cval, v);
  vsetc(&size_type, 0x0030, &cval);
}
static void vset(CType *type, int r, int v)
{
    CValue cval;
    cv_set_i(&cval, v);
    vsetc(type, r, &cval);
}
static void vseti(int r, int v)
{
    CType type;
    type.t = 3;
    type.ref = ((void*)0);
    vset(&type, r, v);
}
static void vpushv(SValue *v)
{
    if (vtop >= (__vstack + 1) + (256 - 1))
        tcc_error("memory full (vstack)");
    vtop++;
    *vtop = *v;
}
static void vdup(void)
{
    vpushv(vtop);
}
static void vrotb(int n)
{
    int i;
    SValue tmp;
    tmp = vtop[-n + 1];
    for(i=-n+1;i!=0;i++)
        vtop[i] = vtop[i+1];
    vtop[0] = tmp;
}
static void vrote(SValue *e, int n)
{
    int i;
    SValue tmp;
    tmp = *e;
    for(i = 0;i < n - 1; i++)
        e[-i] = e[-i - 1];
    e[-n + 1] = tmp;
}
static void vrott(int n)
{
    vrote(vtop, n);
}
static void vpushsym(CType *type, Sym *sym)
{
    CValue cval;
    cv_set_i(&cval, 0);
    vsetc(type, 0x0030 | 0x0200, &cval);
    vtop->sym = sym;
}
static Sym *get_sym_ref(CType *type, Section *sec, unsigned int offset, unsigned int size)
{
    int v;
    Sym *sym;
    v = anon_sym++;
    sym = global_identifier_push(v, type->t | 0x00002000, 0);
    sym->type.ref = type->ref;
    sym->r = 0x0030 | 0x0200;
    put_extern_sym(sym, sec, offset, size);
    return sym;
}
static Sym *external_global_sym(int v, CType *type, int r)
{
    Sym *s;
    s = sym_find(v);
    if (!s) {
        s = global_identifier_push(v, type->t | 0x00001000, 0);
        s->type.ref = type->ref;
        s->r = r | 0x0030 | 0x0200;
    } else if ((((s)->type.t & (0x000f | (0 | 0x0010))) == (0 | 0x0010))) {
        s->type.t = type->t | (s->type.t & 0x00001000);
        s->type.ref = type->ref;
        update_storage(s);
    }
    return s;
}
static void patch_type(Sym *sym, CType *type)
{
    if (!(type->t & 0x00001000)) {
        if (!(sym->type.t & 0x00001000))
            tcc_error("redefinition of '%s'", get_tok_str(sym->v, ((void*)0)));
        sym->type.t &= ~0x00001000;
    }
    if ((((sym)->type.t & (0x000f | (0 | 0x0010))) == (0 | 0x0010))) {
        sym->type.t = type->t & (sym->type.t | ~0x00002000);
        sym->type.ref = type->ref;
    }
    if (!is_compatible_types(&sym->type, type)) {
        tcc_error("incompatible types for redefinition of '%s'",
                  get_tok_str(sym->v, ((void*)0)));
    } else if ((sym->type.t & 0x000f) == 6) {
        int static_proto = sym->type.t & 0x00002000;
        if (0 == (type->t & 0x00001000)) {
            sym->type.t = (type->t & ~0x00002000) | static_proto;
            sym->type.ref = type->ref;
        }
    } else {
        if ((sym->type.t & 0x0040) && type->ref->c >= 0) {
            if (sym->type.ref->c < 0)
                sym->type.ref->c = type->ref->c;
            else if (sym->type.ref->c != type->ref->c)
                tcc_error("conflicting type for '%s'", get_tok_str(sym->v, ((void*)0)));
        }
    }
}
static void patch_storage(Sym *sym, AttributeDef *ad, CType *type)
{
    if (type)
        patch_type(sym, type);
    update_storage(sym);
}
static Sym *external_sym(int v, CType *type, int r, AttributeDef *ad)
{
    Sym *s;
    s = sym_find(v);
    if (!s) {
        s = sym_push(v, type, r | 0x0030 | 0x0200, 0);
        s->type.t |= 0x00001000;
        s->sym_scope = 0;
    } else {
        if (s->type.ref == func_old_type.ref) {
            s->type.ref = type->ref;
            s->r = r | 0x0030 | 0x0200;
            s->type.t |= 0x00001000;
        }
        patch_storage(s, ad, type);
    }
    return s;
}
static void vpush_global_sym(CType *type, int v)
{
    vpushsym(type, external_global_sym(v, type, 0));
}
static void save_regs(int n)
{
    SValue *p, *p1;
    for(p = (__vstack + 1), p1 = vtop - n; p <= p1; p++)
        save_reg(p->r);
}
static void save_reg(int r)
{
    save_reg_upstack(r, 0);
}
static void save_reg_upstack(int r, int n)
{
    int l, saved, size, align;
    SValue *p, *p1, sv;
    CType *type;
    if ((r &= 0x003f) >= 0x0030)
        return;
    if (nocode_wanted)
        return;
    saved = 0;
    l = 0;
    for(p = (__vstack + 1), p1 = vtop - n; p <= p1; p++) {
        if ((p->r & 0x003f) == r) {
            if (!saved) {
                r = p->r & 0x003f;
                type = &p->type;
                if (p->r & 0x0100)
                    type = &int_type;
                size = type_size(type, &align);
                loc = (loc - size) & -align;
                sv.type.t = type->t;
                sv.r = 0x0032 | 0x0100;
                cv_set_i(&sv.c, loc);
                store(r, &sv);
                l = loc;
                saved = 1;
            }
            if (p->r & 0x0100) {
                p->r = (p->r & ~(0x003f | 0x8000)) | 0x0031;
            } else {
                p->r = lvalue_type(p->type.t) | 0x0032;
            }
            cv_set_i(&p->c, l);
        }
    }
}
static int get_reg(int rc)
{
    int r;
    SValue *p;
    for(r=0;r<4;r++) {
        if (reg_classes[r] & rc) {
            int used = 0;
            if (nocode_wanted)
                return r;
            for(p=(__vstack + 1);p<=vtop;p++) {
                if ((p->r & 0x003f) == r)
                    used = 1;
            }
            if (!used)
                return r;
        }
    }
    for(p=(__vstack + 1);p<=vtop;p++) {
        r = p->r & 0x003f;
        if (r < 0x0030 && (reg_classes[r] & rc)) {
            save_reg(r);
            return r;
        }
    }
    return -1;
}
static void move_reg(int r, int s, int t)
{
    SValue sv;
    if (r != s) {
        save_reg(r);
        sv.type.t = t;
        sv.type.ref = ((void*)0);
        sv.r = s;
        cv_set_i(&sv.c, 0);
        load(r, &sv);
    }
}
static void gaddrof(void)
{
    vtop->r &= ~0x0100;
    if ((vtop->r & 0x003f) == 0x0031)
        vtop->r = (vtop->r & ~(0x003f | (0x1000 | 0x2000 | 0x4000))) | 0x0032 | 0x0100;
}
static int gv(int rc)
{
    int r;
    if (vtop->type.t & 0x0080) {
        tcc_error("bit-fields are not supported in tcc_27_alt");
    } else {
        r = vtop->r & 0x003f;
        if (r >= 0x0030
         || (vtop->r & 0x0100)
         || !(reg_classes[r] & rc)
            )
        {
            r = get_reg(rc);
            if (vtop->r & 0x0100) {
                int t1, t;
                t = vtop->type.t;
                t1 = t;
                if (vtop->r & 0x1000)
                    t = 1;
                else if (vtop->r & 0x2000)
                    t = 2;
                if (vtop->r & 0x4000)
                    t |= 0x0010;
                vtop->type.t = t;
                load(r, vtop);
                vtop->type.t = t1;
            } else {
                load(r, vtop);
            }
        }
        vtop->r = r;
    }
    return r;
}
static void gv2(int rc1, int rc2)
{
    int v;
    v = vtop[0].r & 0x003f;
    if (v != 0x0033 && (v & ~1) != 0x0034 && rc1 <= rc2) {
        vswap();
        gv(rc1);
        vswap();
        gv(rc2);
        if ((vtop[-1].r & 0x003f) >= 0x0030) {
            vswap();
            gv(rc1);
            vswap();
        }
    } else {
        gv(rc2);
        vswap();
        gv(rc1);
        vswap();
        if ((vtop[0].r & 0x003f) >= 0x0030) {
            gv(rc2);
        }
    }
}
static void gv_dup(void)
{
    int rc, r, r1;
    SValue sv;
    rc = 0x0001;
    sv.type.t = 3;
    r = gv(rc);
    r1 = get_reg(rc);
    sv.r = r;
    cv_set_i(&sv.c, 0);
    load(r1, &sv);
    vdup();
    if (r != r1)
        vtop->r = r1;
}
static int gvtst(int inv, int t)
{
    int v = vtop->r & 0x003f;
    if (v != 0x0033 && v != 0x0034 && v != 0x0035) {
        vpushi(0);
        gen_op(0x95);
    }
    if ((vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030) {
        if ((cv_i(&vtop->c) != 0) != inv)
            t = gjmp(t);
        vtop--;
        return t;
    }
    return gtst(inv, t);
}
static unsigned int gen_opic_sdiv(unsigned int a, unsigned int b)
{
    unsigned int x = (a >> 31 ? -a : a) / (b >> 31 ? -b : b);
    return (a ^ b) >> 31 ? -x : x;
}
static int gen_opic_lt(unsigned int a, unsigned int b)
{
    return (a ^ (unsigned int)1 << 31) < (b ^ (unsigned int)1 << 31);
}
static void gen_opic(int op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    int t1 = v1->type.t & 0x000f;
    int t2 = v2->type.t & 0x000f;
    int c1 = (v1->r & (0x003f | 0x0100 | 0x0200)) == 0x0030;
    int c2 = (v2->r & (0x003f | 0x0100 | 0x0200)) == 0x0030;
    unsigned int l1 = c1 ? cv_i(&v1->c) : 0;
    unsigned int l2 = c2 ? cv_i(&v2->c) : 0;
    int shm = 31;
    int folded = 0;
    if (t1 != 4 && (4 != 8 || t1 != 5))
        l1 = ((uint32_t)l1 |
              (v1->type.t & 0x0010 ? 0 : -(l1 & 0x80000000)));
    if (t2 != 4 && (4 != 8 || t2 != 5))
        l2 = ((uint32_t)l2 |
              (v2->type.t & 0x0010 ? 0 : -(l2 & 0x80000000)));
    if (c1 && c2) {
        folded = 1;
        if (op == '+') l1 += l2;
        else if (op == '-') l1 -= l2;
        else if (op == '&') l1 &= l2;
        else if (op == '^') l1 ^= l2;
        else if (op == '|') l1 |= l2;
        else if (op == '*') l1 *= l2;
        else if (op == 0xb2 || op == '/' || op == '%' || op == 0xb0 || op == 0xb1) {
            if (l2 == 0) {
                if (const_wanted)
                    tcc_error("division by zero in constant");
                folded = 0;
            } else if (op == '%') {
                l1 = l1 - l2 * gen_opic_sdiv(l1, l2);
            } else if (op == 0xb0) {
                l1 = l1 / l2;
            } else if (op == 0xb1) {
                l1 = l1 % l2;
            } else {
                l1 = gen_opic_sdiv(l1, l2);
            }
        } else if (op == 0x01) l1 <<= (l2 & shm);
        else if (op == 0xc9) l1 >>= (l2 & shm);
        else if (op == 0x02) {
            l1 = (l1 >> 31) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
        } else if (op == 0x92) l1 = l1 < l2;
        else if (op == 0x93) l1 = l1 >= l2;
        else if (op == 0x94) l1 = l1 == l2;
        else if (op == 0x95) l1 = l1 != l2;
        else if (op == 0x96) l1 = l1 <= l2;
        else if (op == 0x97) l1 = l1 > l2;
        else if (op == 0x9c) l1 = gen_opic_lt(l1, l2);
        else if (op == 0x9d) l1 = !gen_opic_lt(l1, l2);
        else if (op == 0x9e) l1 = !gen_opic_lt(l2, l1);
        else if (op == 0x9f) l1 = gen_opic_lt(l2, l1);
        else if (op == 0xa0) l1 = l1 && l2;
        else if (op == 0xa1) l1 = l1 || l2;
        else {
            folded = 0;
        }
        if (folded) {
	    if (t1 != 4 && (4 != 8 || t1 != 5))
	        l1 = ((uint32_t)l1 |
		    (v1->type.t & 0x0010 ? 0 : -(l1 & 0x80000000)));
            cv_set_i(&v1->c, l1);
            vtop--;
            return;
        }
    }
        if (c1 && (op == '+' || op == '&' || op == '^' ||
                   op == '|' || op == '*')) {
            vswap();
            c2 = c1;
            l2 = l1;
        }
        if (!const_wanted &&
            c1 && ((l1 == 0 &&
                    (op == 0x01 || op == 0xc9 || op == 0x02)) ||
                   (l1 == -1 && op == 0x02))) {
            vtop--;
        } else if (!const_wanted &&
                   c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != 4))) ||
                          (l2 == 1 && (op == '%' || op == 0xb1)))) {
            if (l2 == 1)
                cv_set_i(&vtop->c, 0);
            vswap();
            vtop--;
        } else if (c2 && (((op == '*' || op == '/' || op == 0xb0 ||
                          op == 0xb2) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == 0x01 || op == 0xc9 || op == 0x02) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != 4))))) {
            vtop--;
        } else if (c2 && (op == '*' || op == 0xb2 || op == 0xb0)) {
            if (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                int n = -1;
                while (l2) {
                    l2 >>= 1;
                    n++;
                }
                cv_set_i(&vtop->c, n);
                if (op == '*')
                    op = 0x01;
                else if (op == 0xb2)
                    op = 0x02;
                else
                    op = 0xc9;
            }
            gen_opi(op);
        } else if (c2 && (op == '+' || op == '-') &&
                   (((vtop[-1].r & (0x003f | 0x0100 | 0x0200)) == (0x0030 | 0x0200))
                    || (vtop[-1].r & (0x003f | 0x0100)) == 0x0032)) {
            if (op == '-')
                l2 = -l2;
	    l2 += cv_i(&vtop[-1].c);
	    if ((int)l2 == l2) {
                vtop--;
                cv_set_i(&vtop->c, l2);
            } else {
                gen_opi(op);
            }
        } else {
            gen_opi(op);
        }
}
static int pointed_size(CType *type)
{
    int align;
    return type_size(pointed_type(type), &align);
}
static int is_null_pointer(SValue *p)
{
    if ((p->r & (0x003f | 0x0100 | 0x0200)) != 0x0030)
        return 0;
    return ((p->type.t & 0x000f) == 3 && (uint32_t)cv_i(&p->c) == 0) ||
        ((p->type.t & 0x000f) == 5 && (uint32_t)cv_i(&p->c) == 0);
}
static int is_integer_btype(int bt)
{
    return (bt == 1 || bt == 2 || bt == 3);
}
static void check_comparison_pointer_types(SValue *p1, SValue *p2, int op)
{
    CType *type1, *type2, tmp_type1, tmp_type2;
    int bt1, bt2;
    if (is_null_pointer(p1) || is_null_pointer(p2))
        return;
    type1 = &p1->type;
    type2 = &p2->type;
    bt1 = type1->t & 0x000f;
    bt2 = type2->t & 0x000f;
    if ((is_integer_btype(bt1) || is_integer_btype(bt2)) && op != '-') {
        if (op != 0xa1 && op != 0xa0 )
        return;
    }
    if (bt1 == 5) {
        type1 = pointed_type(type1);
    } else if (bt1 != 6) {
        tcc_error("invalid operands to binary %s", get_tok_str(op, ((void*)0)));
    }
    if (bt2 == 5) {
        type2 = pointed_type(type2);
    } else if (bt2 != 6) {
        tcc_error("invalid operands to binary %s", get_tok_str(op, ((void*)0)));
    }
    if ((type1->t & 0x000f) == 0 ||
        (type2->t & 0x000f) == 0)
        return;
    tmp_type1 = *type1;
    tmp_type2 = *type2;
    tmp_type1.t &= ~(0x0020 | 0x0010 | 0x0100 | 0x0200);
    tmp_type2.t &= ~(0x0020 | 0x0010 | 0x0100 | 0x0200);
    if (!is_compatible_types(&tmp_type1, &tmp_type2) && op == '-')
        tcc_error("invalid operands to binary %s", get_tok_str(op, ((void*)0)));
}
static void gen_standard_op(int op, int t)
{
    CType type1;
    if (t & 0x0010) {
        if (op == 0x02)
            op = 0xc9;
        else if (op == '/')
            op = 0xb0;
        else if (op == '%')
            op = 0xb1;
        else if (op == 0x9c)
            op = 0x92;
        else if (op == 0x9f)
            op = 0x97;
        else if (op == 0x9e)
            op = 0x96;
        else if (op == 0x9d)
            op = 0x93;
    }
    vswap();
    type1.t = t;
    type1.ref = ((void*)0);
    gen_cast(&type1);
    vswap();
    if (op == 0xc9 || op == 0x02 || op == 0x01)
        type1.t = 3;
    gen_cast(&type1);
    gen_opic(op);
    if (op >= 0x92 && op <= 0x9f) {
        vtop->type.t = 3;
    } else {
        vtop->type.t = t;
    }
}
static void gen_op(int op)
{
    int u, t1, t2, bt1, bt2, t;
    CType type1;
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & 0x000f;
    bt2 = t2 & 0x000f;
    while (bt1 == 6 || bt2 == 6) {
	if (bt2 == 6) {
	    mk_pointer(&vtop->type);
	    gaddrof();
	}
	if (bt1 == 6) {
	    vswap();
	    mk_pointer(&vtop->type);
	    gaddrof();
	    vswap();
	}
        t1 = vtop[-1].type.t;
        t2 = vtop[0].type.t;
        bt1 = t1 & 0x000f;
        bt2 = t2 & 0x000f;
    }
    if (bt1 == 7 || bt2 == 7) {
        tcc_error("operation on a struct");
    } else if (bt1 == 5 || bt2 == 5) {
        if (op >= 0x92 && op <= 0xa1) {
            check_comparison_pointer_types(vtop - 1, vtop, op);
            t = 3 | 0x0010;
            gen_standard_op(op, t);
        }
        else if (bt1 == 5 && bt2 == 5) {
            if (op != '-')
                tcc_error("cannot use pointers here");
            check_comparison_pointer_types(vtop - 1, vtop, op);
            if (vtop[-1].type.t & 0x0400)
                tcc_error("variable length arrays are not supported in tcc_27_alt");
            vpushi(pointed_size(&vtop[-1].type));
            vrott(3);
            gen_opic(op);
            vtop->type.t = ptrdiff_type.t;
            vswap();
            gen_op(0xb2);
        } else {
            if (op != '-' && op != '+')
                tcc_error("cannot use pointers here");
            if (bt2 == 5) {
                vswap();
                t = t1, t1 = t2, t2 = t;
            }
            type1 = vtop[-1].type;
            type1.t &= ~0x0040;
            if (vtop[-1].type.t & 0x0400)
                tcc_error("variable length arrays are not supported in tcc_27_alt");
            u = pointed_size(&vtop[-1].type);
            if (u < 0)
                tcc_error("unknown array element size");
            vpushi(u);
            gen_op('*');
            {
                gen_opic(op);
            }
            vtop->type = type1;
        }
    } else if (op == 0xc9 || op == 0x02 || op == 0x01) {
        t = 3;
        if ((t1 & (0x000f | 0x0010 | 0x0080)) == (t | 0x0010))
          t |= 0x0010;
        gen_standard_op(op, t);
    } else {
        t = 3;
        if ((t1 & (0x000f | 0x0010 | 0x0080)) == (3 | 0x0010) ||
            (t2 & (0x000f | 0x0010 | 0x0080)) == (3 | 0x0010))
            t |= 0x0010;
        gen_standard_op(op, t);
    }
    if (vtop->r & 0x0100)
        gv(0x0001);
}
static void force_charshort_cast(int t)
{
    int bits, dbt;
    if ((nocode_wanted & 0xC0000000))
	return;
    dbt = t & 0x000f;
    if (dbt == 1)
        bits = 8;
    else
        bits = 16;
    if (t & 0x0010) {
        vpushi((1 << bits) - 1);
        gen_op('&');
    } else {
        bits = 32 - bits;
        vpushi(bits);
        gen_op(0x01);
        vtop->type.t &= ~0x0010;
        vpushi(bits);
        gen_op(0x02);
    }
}
static void gen_cast_s(int t)
{
    CType type;
    type.t = t;
    type.ref = ((void*)0);
    gen_cast(&type);
}
static void gen_cast(CType *type)
{
    int sbt, dbt, c, p;
    if (vtop->r & 0x0400) {
        vtop->r &= ~0x0400;
        force_charshort_cast(vtop->type.t);
    }
    dbt = type->t & (0x000f | 0x0010);
    sbt = vtop->type.t & (0x000f | 0x0010);
    if (sbt != dbt) {
        c = (vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030;
        p = (vtop->r & (0x003f | 0x0100 | 0x0200)) == (0x0030 | 0x0200);
        if (c) {
            if (sbt & 0x0010)
                cv_set_i(&vtop->c, (uint32_t)cv_i(&vtop->c));
            else
                cv_set_i(&vtop->c, ((uint32_t)cv_i(&vtop->c) |
                              -(cv_i(&vtop->c) & 0x80000000)));
            if (dbt == 11)
                cv_set_i(&vtop->c, (cv_i(&vtop->c) != 0));
            else {
                uint32_t m = ((dbt & 0x000f) == 1 ? 0xff :
                              (dbt & 0x000f) == 2 ? 0xffff :
                              0xffffffff);
                cv_set_i(&vtop->c, cv_i(&vtop->c) & m);
                if (!(dbt & 0x0010))
                    cv_set_i(&vtop->c, cv_i(&vtop->c) | -(cv_i(&vtop->c) & ((m >> 1) + 1)));
            }
        } else if (p && dbt == 11) {
            vtop->r = 0x0030;
            cv_set_i(&vtop->c, 1);
        } else {
            if (dbt == 11) {
                vpushi(0);
                gen_op(0x95);
            } else if ((dbt & 0x000f) == 1 ||
                       (dbt & 0x000f) == 2) {
                if (sbt == 5) {
                    vtop->type.t = 3;
                }
                force_charshort_cast(dbt);
            }
        }
    } else if ((dbt & 0x000f) == 5 && !(vtop->r & 0x0100)) {
        vtop->r = (vtop->r & ~(0x1000 | 0x2000 | 0x4000))
                  | (lvalue_type(type->ref->type.t) & (0x1000 | 0x2000 | 0x4000));
    }
    vtop->type = *type;
}
static int type_size(CType *type, int *a)
{
    Sym *s;
    int bt;
    bt = type->t & 0x000f;
    if (bt == 7) {
        s = type->ref;
        *a = s->r;
        return s->c;
    } else if (bt == 5) {
        if (type->t & 0x0040) {
            int ts;
            s = type->ref;
            ts = type_size(&s->type, a);
            if (ts < 0 && s->c < 0)
                ts = -ts;
            return ts * s->c;
        } else {
            *a = 4;
            return 4;
        }
    } else if (bt == 3) {
        *a = 4;
        return 4;
    } else if (bt == 2) {
        *a = 2;
        return 2;
    } else if (bt == 13 || bt == 14) {
        *a = 8;
        return 16;
    } else {
        *a = 1;
        return 1;
    }
}
static CType *pointed_type(CType *type)
{
    return &type->ref->type;
}
static void mk_pointer(CType *type)
{
    Sym *s;
    s = sym_push(0x20000000, type, 0, -1);
    type->t = 5 | (type->t & (0x00001000 | 0x00002000 | 0x00004000));
    type->ref = s;
}
static int is_compatible_func(CType *type1, CType *type2)
{
    Sym *s1, *s2;
    s1 = type1->ref;
    s2 = type2->ref;
    if (!is_compatible_types(&s1->type, &s2->type))
        return 0;
    if (sym_ft(s1) == 2 || sym_ft(s2) == 2)
        return 1;
    if (sym_ft(s1) != sym_ft(s2))
        return 0;
    while (s1 != ((void*)0)) {
        if (s2 == ((void*)0))
            return 0;
        if (!is_compatible_types(&s1->type, &s2->type))
            return 0;
        s1 = s1->next;
        s2 = s2->next;
    }
    if (s2)
        return 0;
    return 1;
}
static int is_compatible_types(CType *type1, CType *type2)
{
    int bt1, t1, t2;
    t1 = type1->t & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)));
    t2 = type2->t & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)));
    if ((t1 & 0x000f) != 1) {
        t1 &= ~0x0020;
        t2 &= ~0x0020;
    }
    if (t1 != t2)
        return 0;
    bt1 = t1 & 0x000f;
    if (bt1 == 5) {
        type1 = pointed_type(type1);
        type2 = pointed_type(type2);
        return is_compatible_types(type1, type2);
    } else if (bt1 == 7) {
        return (type1->ref == type2->ref);
    } else if (bt1 == 6) {
        return is_compatible_func(type1, type2);
    } else {
        return 1;
    }
}
static void type_to_str(char *buf, int buf_size,
                 CType *type, char *varstr)
{
    (void)type;
    if (varstr)
        snprintf(buf, buf_size, "<type> %s", varstr);
    else
        snprintf(buf, buf_size, "<type>");
}
static void gen_assign_cast(CType *dt)
{
    CType *st, *type1, *type2;
    char buf1[256], buf2[256];
    int dbt, sbt, ok;
    st = &vtop->type;
    dbt = dt->t & 0x000f;
    sbt = st->t & 0x000f;
    if (sbt == 0 || dbt == 0) {
	if (sbt == 0 && dbt == 0)
	    ;
	else
    	    tcc_error("cannot cast from/to void");
    }
    ok = 1;
    if (dbt == 5) {
        if (is_null_pointer(vtop))
            ;
        else if (!is_integer_btype(sbt) && sbt != 6) {
            if (sbt != 5) {
                ok = 0;
            } else {
                type1 = pointed_type(dt);
                type2 = pointed_type(st);
                if ((type1->t & 0x000f) != 0 &&
                    (type2->t & 0x000f) != 0 &&
                    !is_compatible_types(type1, type2)) {
                }
            }
        }
    } else if (dbt == 1 || dbt == 2 || dbt == 3 || dbt == 4) {
        if (sbt == 7)
            ok = is_compatible_types(dt, st);
    } else if (dbt == 7) {
        ok = is_compatible_types(dt, st);
    }
    if (!ok) {
        type_to_str(buf1, sizeof(buf1), st, ((void*)0));
        type_to_str(buf2, sizeof(buf2), dt, ((void*)0));
        tcc_error("cannot cast '%s' to '%s'", buf1, buf2);
    }
    gen_cast(dt);
}
static void vstore(void)
{
    int sbt, dbt, ft, r, t, size, align, rc, delayed_cast;
    ft = vtop[-1].type.t;
    sbt = vtop->type.t & 0x000f;
    dbt = ft & 0x000f;
    if ((((sbt == 3 || sbt == 2) && dbt == 1) ||
         (sbt == 3 && dbt == 2))
	&& !(vtop->type.t & 0x0080)) {
        delayed_cast = 0x0400;
        vtop->type.t = ft & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)));
    } else {
        delayed_cast = 0;
        if (!(ft & 0x0080))
            gen_assign_cast(&vtop[-1].type);
    }
    if (sbt == 7) {
            size = type_size(&vtop->type, &align);
            vswap();
            vtop->type.t = 5;
            gaddrof();
            vpush_global_sym(&func_old_type, 277);
            vswap();
            vpushv(vtop - 2);
            vtop->type.t = 5;
            gaddrof();
            vpushi(size);
            gfunc_call(3);
    } else if (ft & 0x0080) {
        tcc_error("bit-fields are not supported in tcc_27_alt");
    } else if (dbt == 0) {
        --vtop;
    } else {
            rc = 0x0001;
            r = gv(rc);
            if ((vtop[-1].r & 0x003f) == 0x0031) {
                SValue sv;
                t = get_reg(0x0001);
                sv.type.t = 3;
                sv.r = 0x0032 | 0x0100;
                cv_set_i(&sv.c, cv_i(&vtop[-1].c));
                load(t, &sv);
                vtop[-1].r = t | 0x0100;
            }
            store(r, vtop - 1);
        vswap();
        vtop--;
        vtop->r |= delayed_cast;
    }
}
static void inc(int post, int c)
{
    test_lvalue();
    vdup();
    if (post) {
        gv_dup();
        vrotb(3);
        vrotb(3);
    }
    vpushi(c - 0xa3);
    gen_op('+');
    vstore();
    if (post)
        vpop();
}
static Sym * find_field (CType *type, int v)
{
    Sym *s = type->ref;
    v |= 0x20000000;
    while ((s = s->next) != ((void*)0)) {
	if ((s->v & 0x20000000) &&
	    (s->type.t & 0x000f) == 7 &&
	    (s->v & ~0x20000000) >= 0x10000000) {
	    Sym *ret = find_field (&s->type, v);
	    if (ret)
	        return ret;
	}
	if (s->v == v)
	  break;
    }
    return s;
}
static void struct_add_offset (Sym *s, int offset)
{
    while ((s = s->next) != ((void*)0)) {
	if ((s->v & 0x20000000) &&
	    (s->type.t & 0x000f) == 7 &&
	    (s->v & ~0x20000000) >= 0x10000000) {
	    struct_add_offset(s->type.ref, offset);
	} else
	  s->c += offset;
    }
}
static void struct_layout(CType *type, AttributeDef *ad)
{
    int size, align, maxalign, offset, c, a;
    Sym *f;
    maxalign = 1;
    offset = 0;
    c = 0;
    for (f = type->ref->next; f; f = f->next) {
        size = type_size(&f->type, &align);
        c = (c + align - 1) & -align;
        offset = c;
        if (size > 0)
            c += size;
	if (align > maxalign)
	    maxalign = align;
	if (f->v & 0x10000000 && (f->type.t & 0x000f) == 7) {
	    Sym *ass;
	    int v2 = f->type.ref->v;
	    if (!(v2 & 0x20000000) &&
		(v2 & ~0x40000000) < 0x10000000) {
		Sym **pps;
		ass = f->type.ref;
		f->type.ref = sym_push(anon_sym++ | 0x20000000,
				       &f->type.ref->type, 0,
				       f->type.ref->c);
		pps = &f->type.ref->next;
		while ((ass = ass->next) != ((void*)0)) {
		    *pps = sym_push(ass->v, &ass->type, 0, ass->c);
		    pps = &((*pps)->next);
		}
		*pps = ((void*)0);
	    }
	    struct_add_offset(f->type.ref, offset);
	    f->c = 0;
	} else {
	    f->c = offset;
	}
	f->r = 0;
    }
    a = 1;
    if (a < maxalign)
        a = maxalign;
    type->ref->r = a;
    c = (c + a - 1) & -a;
    type->ref->c = c;
}
static void struct_decl(CType *type, int u)
{
    int v, align, use_existing;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;
    memset(&ad, 0, sizeof ad);
    s = ((void*)0);
    use_existing = 0;
    next();
    if (tok != '{') {
        v = tok;
        next();
        if (v < 256)
            expect("struct name");
        s = struct_find(v);
        if (s && (s->sym_scope == local_scope || tok != '{') && u != s->type.t) {
            tcc_error("redefinition of '%s'", get_tok_str(v, ((void*)0)));
        }
        if (s && (s->sym_scope == local_scope || tok != '{'))
            use_existing = 1;
    } else {
        v = anon_sym++;
    }
    if (!use_existing) {
        type1.t = u;
        type1.ref = ((void*)0);
        s = sym_push(v | 0x40000000, &type1, 0, -1);
        s->r = 0;
    }
    type->t = s->type.t;
    type->ref = s;
    if (tok == '{') {
        next();
        if (s->c != -1)
            tcc_error("struct already defined");
        ps = &s->next;
        while (tok != '}') {
                if (!parse_btype(&btype, &ad1)) {
		    skip(';');
		    continue;
		}
                while (1) {
	                    v = 0;
                    type1 = btype;
                    if (tok != ':') {
			if (tok != ';')
                            type_decl(&type1, &ad1, &v, 2);
                        if (v == 0) {
                    	    if ((type1.t & 0x000f) != 7)
                        	expect("identifier");
                    	    else {
				int v = btype.ref->v;
				if (!(v & 0x20000000) && (v & ~0x40000000) < 0x10000000) {
				}
                    	    }
                        }
                        if (type_size(&type1, &align) < 0) {
				    tcc_error("field '%s' has incomplete type",
                                      get_tok_str(v, ((void*)0)));
                        }
                        if ((type1.t & 0x000f) == 6 ||
                            (type1.t & (0x00001000 | 0x00002000 | 0x00004000)))
                            tcc_error("invalid type for '%s'",
                                  get_tok_str(v, ((void*)0)));
                    }
                    if (tok == ':') {
                        tcc_error("bit-fields are not supported in tcc_27_alt");
                    }
                    if (v == 0 &&
			((type1.t & 0x000f) == 7)) {
		        v = anon_sym++;
		    }
                    if (v) {
                        ss = sym_push(v | 0x20000000, &type1, 0, 0);
                        *ps = ss;
                        ps = &ss->next;
                    }
                    if (tok == ';' || tok == (-1))
                        break;
                    skip(',');
                }
                skip(';');
        }
        skip('}');
        struct_layout(type, &ad);
    }
}
static void sym_to_attr(AttributeDef *ad, Sym *s)
{
    if (sym_ft(s) && 0 == ad_ft(ad))
        ad_set_sym_ft(ad, s);
}
static int parse_btype(CType *type, AttributeDef *ad)
{
    int t, u, bt, st, type_found, typespec_found, g, done, basic;
    Sym *s;
    CType type1;
    memset(ad, 0, sizeof(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = 3;
    bt = st = -1;
    type->ref = ((void*)0);
    done = 0;
    while(!done) {
        basic = 0;
        if (tok == 258) {
            u = 1; next(); basic = 1;
        } else if (tok == 257) {
            u = 0; next(); basic = 1;
        } else if (tok == 271) {
            u = 2; next(); basic = 1;
        } else if (tok == 256) {
            u = 3; next(); basic = 1;
        } else if (tok == 272) {
            struct_decl(&type1, 7);
            u = type1.t;
            type->ref = type1.ref;
            basic = 1;
        } else if (tok == 267) {
            if ((t & (0x0020|0x0010)) == 0x0020)
                tcc_error("signed and unsigned modifier");
            t |= 0x0020 | 0x0010;
            next();
            typespec_found = 1;
        } else if (tok == 265 || tok == 266 || tok == 273) {
            if (tok == 265)
                g = 0x00001000;
            else if (tok == 266)
                g = 0x00002000;
            else
                g = 0x00004000;
            if (t & (0x00001000|0x00002000|0x00004000) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
        } else {
            if (typespec_found) {
                done = 1;
            } else {
                s = sym_find(tok);
                if (!s || !(s->type.t & 0x00004000)) {
                    done = 1;
                } else {
                    t &= ~0x000f;
                    type->t = (s->type.t & ~0x00004000) | t;
                    type->ref = s->type.ref;
                    t = type->t;
                    sym_to_attr(ad, s);
                    next();
                    typespec_found = 1;
                    st = bt = -2;
                }
            }
        }
        if (done)
            continue;
        if (basic) {
            if (u == 2) {
                if (st != -1 || (bt != -1 && bt != 3))
                    tcc_error("too many basic types");
                st = u;
            } else {
                if (bt != -1 || (st != -1 && u != 3))
                    tcc_error("too many basic types");
                bt = u;
            }
            if (u != 3)
                t = (t & ~0x000f) | u;
            typespec_found = 1;
        }
        type_found = 1;
    }
    bt = t & 0x000f;
    type->t = t;
    return type_found;
}
static void convert_parameter_type(CType *pt)
{
    pt->t &= ~0x0040;
    if ((pt->t & 0x000f) == 6) {
        mk_pointer(pt);
    }
}
static int post_type(CType *type, AttributeDef *ad, int storage, int td)
{
    int n, l;
    Sym **plast, *s, *first;
    AttributeDef ad1;
    CType pt;
    if (tok == '(') {
        l = 0;
        next();
	if (td && !(td & 1))
	  return 0;
		if (tok == ')')
		  l = 0;
		else if (parse_btype(&pt, &ad1))
		  l = 1;
		else if (td)
		  return 0;
		else
		  tcc_error("parameter type expected");
        first = ((void*)0);
        plast = &first;
        if (l) {
            for(;;) {
		                if ((pt.t & 0x000f) == 0 && tok == ')')
		                    break;
		                type_decl(&pt, &ad1, &n, 2 | 1);
		                if ((pt.t & 0x000f) == 0)
		                    tcc_error("parameter declared as void");
                convert_parameter_type(&pt);
                s = sym_push(n | 0x20000000, &pt, 0, 0);
                *plast = s;
                plast = &s->next;
                if (tok == ')')
                    break;
                skip(',');
                if (l == 1 && tok == 0xc8) {
                    l = 3;
                    next();
                    break;
                }
		if (l == 1 && !parse_btype(&pt, &ad1))
		    tcc_error("invalid type");
            }
        }
        skip(')');
        if (tok == '[') {
            next();
            skip(']');
            mk_pointer(type);
        }
        ad_set_ft(ad, l);
        s = sym_push(0x20000000, type, 0, 0);
        sym_set_ad_ft(s, ad);
        s->next = first;
        type->t = 6;
        type->ref = s;
    } else if (tok == '[') {
        next();
        if (tok == ']')
            tcc_error("array size expected");
        n = expr_const();
        if (n < 0)
            tcc_error("invalid array size");
        skip(']');
        post_type(type, ad, storage, 0);
        if (type->t == 6)
            tcc_error("declaration of an array of functions");
        s = sym_push(0x20000000, type, 0, n);
        type->t = 0x0040 | 5;
        type->ref = s;
    }
    return 1;
}
static CType *type_decl(CType *type, AttributeDef *ad, int *v, int td)
{
    CType *post, *ret;
    int storage;
    storage = type->t & (0x00001000 | 0x00002000 | 0x00004000);
    type->t &= ~(0x00001000 | 0x00002000 | 0x00004000);
    post = ret = type;
    while (tok == '*') {
        next();
        mk_pointer(type);
	if (ret == type)
	    ret = pointed_type(type);
    }
    if (tok == '(') {
	if (!post_type(type, ad, 0, td)) {
	    post = type_decl(type, ad, v, td);
	    skip(')');
	}
    } else if (tok >= 256 && (td & 2)) {
	*v = tok;
	next();
    } else {
	if (!(td & 1))
	  expect("identifier");
	*v = 0;
    }
    post_type(post, ad, storage, 0);
    type->t |= storage;
    return ret;
}
static int lvalue_type(int t)
{
    int bt, r;
    r = 0x0100;
    bt = t & 0x000f;
    if (bt == 1 || bt == 11)
        r |= 0x1000;
    else if (bt == 2)
        r |= 0x2000;
    else
        return r;
    if (t & 0x0010)
        r |= 0x4000;
    return r;
}
static void indir(void)
{
    if ((vtop->type.t & 0x000f) != 5) {
        if ((vtop->type.t & 0x000f) == 6)
            return;
        expect("pointer");
    }
    if (vtop->r & 0x0100)
        gv(0x0001);
    vtop->type = *pointed_type(&vtop->type);
    if (!(vtop->type.t & 0x0040) && !(vtop->type.t & 0x0400)
        && (vtop->type.t & 0x000f) != 6) {
        vtop->r |= lvalue_type(vtop->type.t);
    }
}
static void expr_type(CType *type, void (*expr_fn)(void))
{
    nocode_wanted++;
    expr_fn();
    *type = vtop->type;
    vpop();
    nocode_wanted--;
}
static void unary(void)
{
    int n, t, align, size, r, sizeof_caller;
    CType type;
    Sym *s;
    AttributeDef ad;
    sizeof_caller = in_sizeof;
    in_sizeof = 0;
    type.ref = ((void*)0);
    if (tok == 0xb5 || tok == 0xb3) {
	t = 3;
	type.t = t;
	vsetc(&type, 0x0030, &tokc);
        next();
    } else if (tok == 0xb6) {
        t = 3 | 0x0010;
	type.t = t;
	vsetc(&type, 0x0030, &tokc);
        next();
    } else if (tok == 0xce) {
        t = 3;
	type.t = t;
	vsetc(&type, 0x0030, &tokc);
        next();
    } else if (tok == 0xcf) {
        t = 3 | 0x0010;
	type.t = t;
	vsetc(&type, 0x0030, &tokc);
        next();
    } else if (tok == 0xb9) {
        t = 1;
        type.t = t;
        mk_pointer(&type);
        type.t |= 0x0040;
        type.ref->c = cv_str_size(&tokc);
        memset(&ad, 0, sizeof(AttributeDef));
        decl_initializer_alloc(&type, &ad, 0x0030, 2, 0, 0);
    } else if (tok == '(') {
        next();
        if (parse_btype(&type, &ad)) {
            type_decl(&type, &ad, &n, 1);
            skip(')');
            if (sizeof_caller) {
                vpush(&type);
                return;
            }
            unary();
            gen_cast(&type);
        } else {
            gexpr();
            skip(')');
        }
    } else if (tok == '*') {
        next();
        unary();
        indir();
    } else if (tok == '&') {
        next();
        unary();
        if ((vtop->type.t & 0x000f) != 6 &&
            !(vtop->type.t & 0x0040))
            test_lvalue();
        mk_pointer(&vtop->type);
        gaddrof();
    } else if (tok == '!') {
        next();
        unary();
        if ((vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030) {
            gen_cast_s(11);
            cv_set_i(&vtop->c, !cv_i(&vtop->c));
        } else if ((vtop->r & 0x003f) == 0x0033)
            cv_set_i(&vtop->c, cv_i(&vtop->c) ^ 1);
        else {
            save_regs(1);
            vseti(0x0034, gvtst(1, 0));
        }
    } else if (tok == '~') {
        next();
        unary();
        vpushi(-1);
        gen_op('^');
    } else if (tok == '+') {
        next();
        unary();
        if ((vtop->type.t & 0x000f) == 5)
            tcc_error("pointer not accepted for unary plus");
        vpushi(0);
        gen_op('+');
    } else if (tok == 275) {
        next();
        in_sizeof++;
        expr_type(&type, unary);
        s = vtop[1].sym;
        size = type_size(&type, &align);
        if (size < 0)
            tcc_error("sizeof applied to an incomplete type");
        vpushs(size);
        vtop->type.t |= 0x0010;
    } else if (tok == 0xa4 || tok == 0xa2) {
        t = tok;
        next();
        unary();
        inc(0, t);
    } else if (tok == '-') {
        next();
        unary();
        t = vtop->type.t & 0x000f;
        vpushi(0);
	vswap();
	gen_op('-');
    } else {
        t = tok;
        next();
        if (t <= 275)
            expect("identifier");
        s = sym_find(t);
        if (!s || (((s)->type.t & (0x000f | (0 | 0x0010))) == (0 | 0x0010))) {
            char *name = get_tok_str(t, ((void*)0));
            if (tok != '(')
                tcc_error("'%s' undeclared", name);
            s = external_global_sym(t, &func_old_type, 0);
        }
        r = s->r;
        if ((r & 0x003f) < 0x0030)
            r = (r & ~0x003f) | 0x0032;
        vset(&s->type, r, s->c);
	vtop->sym = s;
        if (r & 0x0200) {
            cv_set_i(&vtop->c, 0);
        }
    }
    while (1) {
        if (tok == 0xa4 || tok == 0xa2) {
            inc(1, tok);
            next();
        } else if (tok == '.' || tok == 0xc7) {
            if (tok == 0xc7)
                indir();
            test_lvalue();
            gaddrof();
            if ((vtop->type.t & 0x000f) != 7)
                expect("struct");
            next();
            if (tok == 0xb5 || tok == 0xb6)
                expect("field name");
	    s = find_field(&vtop->type, tok);
            if (!s)
                tcc_error("field not found: %s",  get_tok_str(tok & ~0x20000000, &tokc));
            vtop->type = char_pointer_type;
            vpushi(s->c);
            gen_op('+');
            vtop->type = s->type;
            if (!(vtop->type.t & 0x0040)) {
                vtop->r |= lvalue_type(vtop->type.t);
            }
            next();
        } else if (tok == '[') {
            next();
            gexpr();
            gen_op('+');
            indir();
            skip(']');
        } else if (tok == '(') {
            SValue ret;
            int nb_args;
            if ((vtop->type.t & 0x000f) != 6) {
                if ((vtop->type.t & (0x000f | 0x0040)) == 5) {
                    vtop->type = *pointed_type(&vtop->type);
                    if ((vtop->type.t & 0x000f) != 6)
                        expect("function pointer");
                } else {
                    expect("function pointer");
                }
            } else {
                vtop->r &= ~0x0100;
            }
            s = vtop->type.ref;
            next();
            nb_args = 0;
            if ((s->type.t & 0x000f) == 7)
                tcc_error("struct return values are not supported in tcc_27_alt");
            ret.type = s->type;
            ret.r = 0;
            cv_set_i(&ret.c, 0);
            if (tok != ')') {
                for(;;) {
                    expr_eq();
                    nb_args++;
                    if (tok == ')')
                        break;
                    skip(',');
                }
            }
            skip(')');
            gfunc_call(nb_args);
            vsetc(&ret.type, ret.r, &ret.c);
        } else {
            break;
        }
    }
}
static void expr_prod(void)
{
    int t;
    unary();
    while (tok == '*' || tok == '/' || tok == '%') {
        t = tok;
        next();
        unary();
        gen_op(t);
    }
}
static void expr_sum(void)
{
    int t;
    expr_prod();
    while (tok == '+' || tok == '-') {
        t = tok;
        next();
        expr_prod();
        gen_op(t);
    }
}
static void expr_shift(void)
{
    int t;
    expr_sum();
    while (tok == 0x01 || tok == 0x02) {
        t = tok;
        next();
        expr_sum();
        gen_op(t);
    }
}
static void expr_cmp(void)
{
    int t;
    expr_shift();
    while ((tok >= 0x96 && tok <= 0x9f) ||
           tok == 0x92 || tok == 0x93) {
        t = tok;
        next();
        expr_shift();
        gen_op(t);
    }
}
static void expr_cmpeq(void)
{
    int t;
    expr_cmp();
    while (tok == 0x94 || tok == 0x95) {
        t = tok;
        next();
        expr_cmp();
        gen_op(t);
    }
}
static void expr_and(void)
{
    expr_cmpeq();
    while (tok == '&') {
        next();
        expr_cmpeq();
        gen_op('&');
    }
}
static void expr_xor(void)
{
    expr_and();
    while (tok == '^') {
        next();
        expr_and();
        gen_op('^');
    }
}
static void expr_or(void)
{
    expr_xor();
    while (tok == '|') {
        next();
        expr_xor();
        gen_op('|');
    }
}
static void expr_land(void)
{
    expr_or();
    if (tok == 0xa0) {
	int t = 0;
	for(;;) {
	    if ((vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030) {
                gen_cast_s(11);
		if (cv_i(&vtop->c)) {
		    vpop();
		} else {
		    nocode_wanted++;
		    while (tok == 0xa0) {
			next();
			expr_or();
			vpop();
		    }
		    nocode_wanted--;
		    if (t)
		      gsym(t);
		    gen_cast_s(3);
		    break;
		}
	    } else {
		if (!t)
		  save_regs(1);
		t = gvtst(1, t);
	    }
	    if (tok != 0xa0) {
		if (t)
		  vseti(0x0035, t);
		else
		  vpushi(1);
		break;
	    }
	    next();
	    expr_or();
	}
    }
}
static void expr_lor(void)
{
    expr_land();
    if (tok == 0xa1) {
	int t = 0;
	for(;;) {
	    if ((vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030) {
                gen_cast_s(11);
		if (!cv_i(&vtop->c)) {
		    vpop();
		} else {
		    nocode_wanted++;
		    while (tok == 0xa1) {
			next();
			expr_land();
			vpop();
		    }
		    nocode_wanted--;
		    if (t)
		      gsym(t);
		    gen_cast_s(3);
		    break;
		}
	    } else {
		if (!t)
		  save_regs(1);
		t = gvtst(0, t);
	    }
	    if (tok != 0xa1) {
		if (t)
		  vseti(0x0034, t);
		else
		  vpushi(0);
		break;
	    }
	    next();
	    expr_land();
	}
    }
}
static int condition_3way(void)
{
    int c = -1;
    if ((vtop->r & (0x003f | 0x0100)) == 0x0030 &&
	!(vtop->r & 0x0200)) {
	vdup();
        gen_cast_s(11);
	c = cv_i(&vtop->c);
	vpop();
    }
    return c;
}
static void expr_cond(void)
{
    int tt, u, r1, r2, rc, t1, t2, bt1, bt2, islv, c;
    SValue sv;
    CType type, type1, type2;
    expr_lor();
    if (tok == '?') {
        next();
	c = condition_3way();
        if (c < 0) {
            rc = 0x0001;
            gv(rc);
            save_regs(1);
            tt = gvtst(1, 0);
        } else {
            vpop();
            tt = 0;
        }
        if (1) {
            if (c == 0)
                nocode_wanted++;
            gexpr();
            type1 = vtop->type;
            sv = *vtop;
            vtop--;
            skip(':');
            u = 0;
            if (c < 0)
                u = gjmp(0);
            gsym(tt);
            if (c == 0)
                nocode_wanted--;
            if (c == 1)
                nocode_wanted++;
            expr_cond();
            if (c == 1)
                nocode_wanted--;
            type2 = vtop->type;
            t1 = type1.t;
            bt1 = t1 & 0x000f;
            t2 = type2.t;
            bt2 = t2 & 0x000f;
            type.ref = ((void*)0);
            if (bt1 == 5 || bt2 == 5) {
		if (is_null_pointer (vtop))
		  type = type1;
		else if (is_null_pointer (&sv))
		  type = type2;
		else
		  type = type1;
            } else if (bt1 == 6 || bt2 == 6) {
                type = bt1 == 6 ? type1 : type2;
            } else if (bt1 == 7 || bt2 == 7) {
                type = bt1 == 7 ? type1 : type2;
            } else if (bt1 == 0 || bt2 == 0) {
                type.t = 0;
            } else {
                type.t = 3;
                if ((t1 & (0x000f | 0x0010 | 0x0080)) == (3 | 0x0010) ||
                    (t2 & (0x000f | 0x0010 | 0x0080)) == (3 | 0x0010))
                    type.t |= 0x0010;
            }
            islv = (vtop->r & 0x0100) && (sv.r & 0x0100) && 7 == (type.t & 0x000f);
            islv &= c < 0;
            if (c != 1) {
                gen_cast(&type);
                if (islv) {
                    mk_pointer(&vtop->type);
                    gaddrof();
                } else if (7 == (vtop->type.t & 0x000f))
                    gaddrof();
            }
            rc = 0x0001;
            tt = r2 = 0;
            if (c < 0) {
                r2 = gv(rc);
                tt = gjmp(0);
            }
            gsym(u);
            if (c != 0) {
                *vtop = sv;
                gen_cast(&type);
                if (islv) {
                    mk_pointer(&vtop->type);
                    gaddrof();
                } else if (7 == (vtop->type.t & 0x000f))
                    gaddrof();
            }
            if (c < 0) {
                r1 = gv(rc);
                move_reg(r2, r1, type.t);
                vtop->r = r2;
                gsym(tt);
                if (islv)
                    indir();
            }
        }
    }
}
static void expr_eq(void)
{
    int t;
    expr_cond();
    if (tok == '=' ||
        (tok >= 0xa5 && tok <= 0xaf) ||
        tok == 0xde || tok == 0xfc ||
        tok == 0x81 || tok == 0x82) {
        test_lvalue();
        t = tok;
        next();
        if (t == '=') {
            expr_eq();
        } else {
            vdup();
            expr_eq();
            gen_op(t & 0x7f);
        }
        vstore();
    }
}
static void gexpr(void)
{
    while (1) {
        expr_eq();
        if (tok != ',')
            break;
        vpop();
        next();
    }
}
static void expr_const1(void)
{
    const_wanted++;
    nocode_wanted++;
    expr_cond();
    nocode_wanted--;
    const_wanted--;
}
static int expr_const(void)
{
    int c;
    expr_const1();
    if ((vtop->r & (0x003f | 0x0100 | 0x0200)) != 0x0030)
        expect("constant expression");
    c = cv_i(&vtop->c);
    vpop();
    return c;
}
static void gfunc_return(CType *func_type)
{
    if ((func_type->t & 0x000f) == 7) {
        tcc_error("struct return values are not supported in tcc_27_alt");
    } else {
        gv(0x0004);
    }
    vtop--;
}
static void block(int *bsym, int *csym, int is_expr)
{
    int a, b, c, d, cond;
    Sym *s;
    if (is_expr) {
        vpushi(0);
        vtop->type.t = 0;
    }
    if (tok == 259) {
	int saved_nocode_wanted = nocode_wanted;
        next();
        skip('(');
        gexpr();
        skip(')');
	cond = condition_3way();
        if (cond == 1)
            a = 0, vpop();
        else
            a = gvtst(1, 0);
        if (cond == 0)
	    nocode_wanted |= 0x20000000;
        block(bsym, csym, 0);
	if (cond != 1)
	    nocode_wanted = saved_nocode_wanted;
        c = tok;
        if (c == 260) {
            next();
            d = gjmp(0);
            gsym(a);
	    if (cond == 1)
	        nocode_wanted |= 0x20000000;
            block(bsym, csym, 0);
            gsym(d);
	    if (cond != 0)
		nocode_wanted = saved_nocode_wanted;
        } else
            gsym(a);
    } else if (tok == 261) {
	int saved_nocode_wanted;
	nocode_wanted &= ~0x20000000;
        next();
        d = ind;
        skip('(');
        gexpr();
        skip(')');
        a = gvtst(1, 0);
        b = 0;
        ++local_scope;
	saved_nocode_wanted = nocode_wanted;
        block(&a, &b, 0);
	nocode_wanted = saved_nocode_wanted;
        --local_scope;
        gjmp_addr(d);
        gsym(a);
        gsym_addr(b, d);
    } else if (tok == '{') {
        next();
        s = local_stack;
        ++local_scope;
        while (tok != '}') {
	    decl(0x0032);
            if (tok != '}') {
                if (is_expr)
                    vpop();
                block(bsym, csym, is_expr);
            }
        }
        --local_scope;
	sym_pop(&local_stack, s, is_expr);
        next();
    } else if (tok == 263) {
        next();
        if (tok != ';') {
            gexpr();
            gen_assign_cast(&func_vt);
            if ((func_vt.t & 0x000f) == 0)
                vtop--;
            else
                gfunc_return(&func_vt);
        }
        skip(';');
        if (tok != '}' || local_scope != 1)
            rsym = gjmp(rsym);
	nocode_wanted |= 0x20000000;
    } else if (tok == 262) {
        if (!bsym)
            tcc_error("cannot break");
        *bsym = gjmp(*bsym);
        next();
        skip(';');
	nocode_wanted |= 0x20000000;
    } else if (tok == 268) {
        if (!csym)
            tcc_error("cannot continue");
        *csym = gjmp(*csym);
        next();
        skip(';');
    } else if (tok == 264) {
        int e;
	int saved_nocode_wanted;
	nocode_wanted &= ~0x20000000;
        next();
        skip('(');
        s = local_stack;
        ++local_scope;
        if (tok != ';') {
            if (!decl0(0x0032, 1, ((void*)0))) {
                gexpr();
                vpop();
            }
        }
        skip(';');
        d = ind;
        c = ind;
        a = 0;
        b = 0;
        if (tok != ';') {
            gexpr();
            a = gvtst(1, 0);
        }
        skip(';');
        if (tok != ')') {
            e = gjmp(0);
            c = ind;
            gexpr();
            vpop();
            gjmp_addr(d);
            gsym(e);
        }
        skip(')');
	saved_nocode_wanted = nocode_wanted;
        block(&a, &b, 0);
	nocode_wanted = saved_nocode_wanted;
        gjmp_addr(c);
        gsym(a);
        gsym_addr(b, c);
        --local_scope;
        sym_pop(&local_stack, s, 0);
    } else {
        if (tok != ';') {
            if (is_expr) {
                vpop();
                gexpr();
            } else {
                gexpr();
                vpop();
            }
        }
        skip(';');
    }
}
static void parse_init_elem(int expr_type)
{
    int saved_global_expr;
    if (expr_type == 1) {
        saved_global_expr = global_expr;
        global_expr = 1;
        expr_const1();
        global_expr = saved_global_expr;
        if (((vtop->r & (0x003f | 0x0100)) != 0x0030
	     && ((vtop->r & (0x0200|0x0100)) != (0x0200|0x0100)
		 || vtop->sym->v < 0x10000000))
            )
            tcc_error("initializer element is not constant");
    } else if (expr_type == 2) {
        expr_eq();
    }
}
static void init_putz(Section *sec, unsigned int c, int size)
{
    if (sec) {
    } else {
        vpush_global_sym(&func_old_type, 278);
        vseti(0x0032, c);
        vpushi(0);
        vpushs(size);
        gfunc_call(3);
    }
}
static int decl_designator(CType *type, Section *sec, unsigned int c,
                           Sym **cur_field, int al)
{
    Sym *f;
    int index, align, size;
    unsigned int corig = c;
    if (tok == '[' || tok == '.')
        tcc_error("designated initializers are not supported in tcc_27_alt");
    if (cur_field) {
        if (type->t & 0x0040) {
            index = (*cur_field)->c;
            if (type->ref->c >= 0 && index >= type->ref->c)
                tcc_error("index too large");
            type = pointed_type(type);
            c += index * type_size(type, &align);
        } else {
            f = *cur_field;
            if (!f)
                tcc_error("too many field init");
            type = &f->type;
            c += f->c;
        }
    }
    if (c - corig > al)
	init_putz(sec, corig + al, c - corig - al);
    decl_initializer(type, sec, c, 0);
    size = type_size(type, &align);
    if (c - corig + size > al)
        al = c - corig + size;
    return al;
}
static void init_putv(CType *type, Section *sec, unsigned int c)
{
    int bt;
    void *ptr;
    CType dtype;
    dtype = *type;
    dtype.t &= ~0x0100;
    if (sec) {
	int size, align;
        gen_assign_cast(&dtype);
        bt = type->t & 0x000f;
        if ((vtop->r & 0x0200)
            && bt != 5
            && bt != 6
            && (bt != 3 || (type->t & 0x0080))
            && !((vtop->r & 0x0030) && vtop->sym->v >= 0x10000000)
            )
            tcc_error("initializer element is not computable at load time");
        if ((nocode_wanted > 0)) {
            vtop--;
            return;
        }
	size = type_size(type, &align);
	section_reserve(sec, c + size);
        ptr = sec->data + c;
	if ((vtop->r & (0x0200|0x0030)) == (0x0200|0x0030) &&
	    vtop->sym->v >= 0x10000000 &&
	    (vtop->type.t & 0x000f) != 5) {
	    Section *ssec;
	    Elf32_Sym *esym;
	    Elf32_Rel *rel;
	    esym = elfsym(vtop->sym);
	    ssec = tcc_state->sections[esy_shndx(esym)];
	    memmove (ptr, ssec->data + esy_value(esym), size);
	    if (ssec->reloc) {
		int num_relocs = ssec->reloc->data_offset / sizeof(*rel);
		rel = (Elf32_Rel*)(ssec->reloc->data + ssec->reloc->data_offset);
		while (num_relocs--) {
		    rel--;
		    if (rel_offset(rel) >= esy_value(esym) + size)
		      continue;
		    if (rel_offset(rel) < esy_value(esym))
		      break;
		    put_elf_reloca(symtab_section, sec,
				   c + rel_offset(rel) - esy_value(esym),
				   rel_type(rel),
				   rel_sym(rel),
				   0
				  );
		}
	    }
	} else {
            if (bt == 11) {
		cv_set_i(&vtop->c, cv_i(&vtop->c) != 0);
                *(char *)ptr |= cv_i(&vtop->c);
            } else if (bt == 1) {
		*(char *)ptr |= cv_i(&vtop->c);
            } else if (bt == 2) {
		*(short *)ptr |= cv_i(&vtop->c);
            } else if (bt == 4) {
		*(int *)ptr |= cv_i(&vtop->c);
            } else if (bt == 5) {
		    Elf32_Addr val = cv_i(&vtop->c);
		    if (vtop->r & 0x0200)
		      greloc(sec, vtop->sym, c, 1);
		    *(Elf32_Addr *)ptr |= val;
            } else {
		    int val = cv_i(&vtop->c);
		    if (vtop->r & 0x0200)
		      greloc(sec, vtop->sym, c, 1);
		    *(int *)ptr |= val;
            }
	}
        vtop--;
    } else {
        vset(&dtype, 0x0032|0x0100, c);
        vswap();
        vstore();
        vpop();
    }
}
static int decl_initializer_list(CType *type, Section *sec, unsigned int c,
    Sym **pf, Sym *indexsym, int have_elem, int no_oblock, int n, int size1)
{
    int len = 0;
    while (tok != '}' || have_elem) {
        len = decl_designator(type, sec, c, pf, len);
        have_elem = 0;
        if (type->t & 0x0040) {
            ++indexsym->c;
            if (no_oblock && len >= n * size1)
                break;
        } else {
            *pf = (*pf)->next;
            if (no_oblock && *pf == ((void*)0))
                break;
        }
        if (tok == '}')
            break;
        skip(',');
    }
    return len;
}
static void decl_initializer(CType *type, Section *sec, unsigned int c,
                             int first)
{
    int len, n, no_oblock, nb, i;
    int size1, align1;
    int have_elem;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;
    have_elem = tok == '}' || tok == ',';
    if (!have_elem && tok != '{' &&
	tok != 0xb9) {
	parse_init_elem(!sec ? 2 : 1);
	have_elem = 1;
    }
    if (have_elem &&
	!(type->t & 0x0040) &&
	is_compatible_types(type, &vtop->type)) {
        init_putv(type, sec, c);
    } else if (type->t & 0x0040) {
        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_size(t1, &align1);
        no_oblock = 1;
        if ((first && tok != 0xb9) ||
            tok == '{') {
            if (tok != '{')
                tcc_error("character array initializer must be a literal,"
                    " optionally enclosed in braces");
            skip('{');
            no_oblock = 0;
        }
        if (tok == 0xb9 && (t1->t & 0x000f) == 1) {
	    len = 0;
            while (tok == 0xb9) {
                int cstr_len, ch;
                cstr_len = cv_str_size(&tokc);
                cstr_len--;
                nb = cstr_len;
                if (n >= 0 && nb > (n - len))
                    nb = n - len;
                if (sec && size1 == 1) {
                    if (!(nocode_wanted > 0))
                        memcpy(sec->data + c + len, cv_str_data(&tokc), nb);
                } else {
                    for(i=0;i<nb;i++) {
                        ch = ((unsigned char *)cv_str_data(&tokc))[i];
		        vpushi(ch);
                        init_putv(t1, sec, c + (len + i) * size1);
                    }
                }
                len += nb;
                next();
            }
            if (n < 0 || len < n) {
		vpushi(0);
                init_putv(t1, sec, c + (len * size1));
                len++;
            }
	    len *= size1;
        } else {
	    indexsym.c = 0;
	    f = &indexsym;
            len = decl_initializer_list(type, sec, c, &f, &indexsym,
                                        have_elem, no_oblock, n, size1);
        }
		if (len < n*size1)
		    init_putz(sec, c + len, n*size1 - len);
        if (!no_oblock)
            skip('}');
        if (n < 0)
            s->c = size1 == 1 ? len : ((len + size1 - 1)/size1);
    } else if ((type->t & 0x000f) == 7) {
	size1 = 1;
        no_oblock = 1;
        if (first || tok == '{') {
            skip('{');
            no_oblock = 0;
        }
        s = type->ref;
        f = s->next;
        n = s->c;
        len = decl_initializer_list(type, sec, c, &f, &indexsym,
                                    have_elem, no_oblock, n, size1);
        if (len < n*size1)
            init_putz(sec, c + len, n*size1 - len);
        if (!no_oblock)
            skip('}');
	    } else if (tok == '{') {
	        next();
	        decl_initializer(type, sec, c, first);
	        skip('}');
	    } else {
	if (!have_elem) {
	    if (tok != 0xb9)
	      expect("string constant");
	    parse_init_elem(!sec ? 2 : 1);
	}
        init_putv(type, sec, c);
    }
}
static void decl_initializer_alloc(CType *type, AttributeDef *ad, int r,
                                   int has_init, int v, int scope)
{
    int size, align, addr;
    int do_alloc = 1;
    Section *sec;
    Sym *sym = ((void*)0);
    int saved_nocode_wanted = nocode_wanted;
    if (type->t & 0x00002000)
        nocode_wanted |= (nocode_wanted > 0) ? 0x40000000 : 0x80000000;
    size = type_size(type, &align);
    if (size < 0)
        tcc_error("unknown type size");
    if ((nocode_wanted > 0))
        size = 0, align = 1;
    if ((r & 0x003f) == 0x0032) {
        sec = ((void*)0);
        loc = (loc - size) & -align;
        addr = loc;
        if (v) {
            sym = sym_push(v, type, r, addr);
        } else {
            vset(type, r, addr);
        }
    } else {
        if (v && scope == 0x0030) {
            sym = sym_find(v);
            if (sym) {
                patch_storage(sym, ad, type);
                if (!has_init && sym->c && esy_shndx(elfsym(sym)) != 0)
                    do_alloc = 0;
            }
        }
        if (do_alloc) {
            if (has_init)
                sec = data_section;
            else
                sec = bss_section;
            if (sec) {
	        addr = section_add(sec, size, align);
            } else {
                addr = align;
	        sec = common_section;
            }
            if (v) {
                if (!sym) {
                    sym = sym_push(v, type, r | 0x0200, 0);
                    patch_storage(sym, ad, ((void*)0));
                }
                sym->sym_scope = 0;
	        put_extern_sym(sym, sec, addr, size);
            } else {
                sym = get_sym_ref(type, sec, addr, size);
	        vpushsym(type, sym);
	        vtop->r |= r;
            }
        }
    }
    if (do_alloc && type->t & 0x0400) {
        tcc_error("variable length arrays are not supported in tcc_27_alt");
    } else if (do_alloc && has_init) {
        decl_initializer(type, sec, addr, 1);
    }
    nocode_wanted = saved_nocode_wanted;
}
static void gen_function(Sym *sym)
{
    nocode_wanted = 0;
    ind = cur_text_section->data_offset;
    put_extern_sym(sym, cur_text_section, ind, 0);
    funcname = get_tok_str(sym->v, ((void*)0));
    func_ind = ind;
    sym_push2(&local_stack, 0x20000000, 0, 0);
    local_scope = 1;
    gfunc_prolog(&sym->type);
    local_scope = 0;
    rsym = 0;
    block(((void*)0), ((void*)0), 0);
    nocode_wanted = 0;
    gsym(rsym);
    gfunc_epilog();
    cur_text_section->data_offset = ind;
    local_scope = 0;
    sym_pop(&local_stack, ((void*)0), 0);
    esy_set_size(elfsym(sym), ind - func_ind);
    cur_text_section = ((void*)0);
    funcname = "";
    func_vt.t = 0;
    ind = 0;
    nocode_wanted = 0x80000000;
    check_vstack();
}
static int decl0(int l, int is_for_loop_init, Sym *func_sym)
{
    int v, has_init, r;
    CType type, btype;
    Sym *sym;
    AttributeDef ad;
    while (1) {
        if (!parse_btype(&btype, &ad)) {
            if (is_for_loop_init)
                return 0;
            if (tok == ';' && l != 0x0033) {
                next();
                continue;
            }
            if (l != 0x0030)
                break;
            if (tok > 275) {
                btype.t = 3;
            } else {
                if (tok != (-1))
                    expect("declaration");
                break;
            }
        }
        if (tok == ';') {
		    if ((btype.t & 0x000f) == 7) {
                next();
	                continue;
		    }
        }
        while (1) {
            type = btype;
	    if ((type.t & 0x0040) && type.ref->c < 0) {
		type.ref = sym_push(0x20000000, &type.ref->type, 0, type.ref->c);
	    }
            type_decl(&type, &ad, &v, 2);
            if ((type.t & 0x000f) == 6) {
                if ((type.t & 0x00002000) && (l == 0x0032)) {
                    tcc_error("function without file scope cannot be static");
                }
                sym = type.ref;
            }
            if (tok == '{') {
                if (l != 0x0030)
                    tcc_error("cannot use local functions");
                if ((type.t & 0x000f) != 6)
                    expect("function definition");
                sym = type.ref;
                while ((sym = sym->next) != ((void*)0)) {
                    if (!(sym->v & ~0x20000000))
                        expect("identifier");
		    if (sym->type.t == 0)
		        sym->type = int_type;
		}
                sym = external_global_sym(v, &type, 0);
                type.t &= ~0x00001000;
                patch_storage(sym, &ad, &type);
                cur_text_section = text_section;
                gen_function(sym);
                break;
            } else {
			if (type.t & 0x00004000) {
                    sym = sym_find(v);
                    if (sym && sym->sym_scope == local_scope) {
                        if (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & 0x00004000))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, ((void*)0)));
                        sym->type = type;
                    } else {
                        sym = sym_push(v, &type, 0, 0);
                    }
                    sym_set_ad_ft(sym, &ad);
                } else {
                    r = 0;
                    if ((type.t & 0x000f) == 6) {
                        sym_set_ad_ft(type.ref, &ad);
                    } else if (!(type.t & 0x0040)) {
                        r |= lvalue_type(type.t);
                    }
                    has_init = (tok == '=');
                    if (has_init && (type.t & 0x0400))
                        tcc_error("variable length array cannot be initialized");
                    if (((type.t & 0x00001000) && (!has_init || l != 0x0030)) ||
			((type.t & 0x000f) == 6) ||
                        ((type.t & 0x0040) && (type.t & 0x00002000) &&
                         !has_init && l == 0x0030 && type.ref->c < 0)) {
                        type.t |= 0x00001000;
                        sym = external_sym(v, &type, r, &ad);
                    } else {
                        if (type.t & 0x00002000)
                            r |= 0x0030;
                        else
                            r |= l;
                        if (has_init)
                            next();
                        else if (l == 0x0030)
                            type.t |= 0x00001000;
                        decl_initializer_alloc(&type, &ad, r, has_init, v, l);
                    }
                }
                if (tok != ',') {
                    if (is_for_loop_init)
                        return 1;
                    skip(';');
                    break;
                }
                next();
            }
        }
    }
    return 0;
}
static void decl(int l)
{
    decl0(l, 0, ((void*)0));
}
static Section *text_section, *data_section, *bss_section;
static Section *common_section;
static Section *cur_text_section;
static Section *symtab_section;
static int new_undef_sym = 0;
static void tccelf_new(TCCState *s)
{
    dynarray_add(&s->sections, &s->nb_sections, ((void*)0));
    text_section = new_section(s, ".text", 1, (1 << 1) | (1 << 2));
    data_section = new_section(s, ".data", 1, (1 << 1) | (1 << 0));
    bss_section = new_section(s, ".bss", 8, (1 << 1) | (1 << 0));
    common_section = new_section(s, ".common", 8, 0x80000000);
    common_section->sh_num = 0xfff2;
    symtab_section = new_symtab(s, ".symtab", 2, 0,
                                ".strtab",
                                ".hashtab", 0x80000000);
    s->symtab = symtab_section;
    get_sym_attr(s, 0, 1);
}
static void tccelf_begin_file(TCCState *s1)
{
    Section *s; int i;
    for (i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        s->sh_offset = s->data_offset;
    }
    s = s1->symtab, s->reloc = s->hash, s->hash = ((void*)0);
}
static void tccelf_end_file(TCCState *s1)
{
    Section *s = s1->symtab;
    int first_sym, nb_syms, *tr, i;
    first_sym = s->sh_offset / sizeof (Elf32_Sym);
    nb_syms = s->data_offset / sizeof (Elf32_Sym) - first_sym;
    s->data_offset = s->sh_offset;
    s->link->data_offset = s->link->sh_offset;
    s->hash = s->reloc, s->reloc = ((void*)0);
    tr = tcc_mallocz(nb_syms * sizeof *tr);
    for (i = 0; i < nb_syms; ++i) {
        Elf32_Sym *sym = (Elf32_Sym*)s->data + first_sym + i;
        if (esy_shndx(sym) == 0
            && (((unsigned char) (esy_info(sym))) >> 4) == 0)
            esy_set_info(sym, (((1) << 4) + ((((esy_info(sym)) & 0xf)) & 0xf)));
        tr[i] = set_elf_sym(s, esy_value(sym), esy_size(sym), esy_info(sym),
            esy_other(sym), esy_shndx(sym), s->link->data + esy_name(sym));
    }
    for (i = 1; i < s1->nb_sections; i++) {
        Section *sr = s1->sections[i];
        if (sr->sh_type == 9 && sr->link == s) {
            Elf32_Rel *rel = (Elf32_Rel*)(sr->data + sr->sh_offset);
            Elf32_Rel *rel_end = (Elf32_Rel*)(sr->data + sr->data_offset);
            for (; rel < rel_end; ++rel) {
                int n = rel_sym(rel) - first_sym;
                rel_set_sym_type(rel, tr[n], rel_type(rel));
            }
        }
    }
    tcc_free(tr);
}
static Section *new_section(TCCState *s1, char *name, int sh_type, int sh_flags)
{
    Section *sec;
    sec = tcc_mallocz(sizeof(Section) + strlen(name));
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    if (sh_type == 3)
        sec->sh_addralign = 1;
    else
        sec->sh_addralign =  4;
    if (sh_flags & 0x80000000) {
        dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } else {
        sec->sh_num = s1->nb_sections;
        dynarray_add(&s1->sections, &s1->nb_sections, sec);
    }
    return sec;
}
static Section *new_symtab(TCCState *s1,
                           char *symtab_name, int sh_type, int sh_flags,
                           char *strtab_name,
                           char *hash_name, int hash_sh_flags)
{
    Section *symtab, *strtab, *hash;
    int *ptr, nb_buckets;
    symtab = new_section(s1, symtab_name, sh_type, sh_flags);
    symtab->sh_entsize = sizeof(Elf32_Sym);
    strtab = new_section(s1, strtab_name, 3, sh_flags);
    put_elf_str(strtab, "");
    symtab->link = strtab;
    put_elf_sym(symtab, 0, 0, 0, 0, 0, ((void*)0));
    nb_buckets = 1;
    hash = new_section(s1, hash_name, 5, hash_sh_flags);
    hash->sh_entsize = sizeof(int);
    symtab->hash = hash;
    hash->link = symtab;
    ptr = section_ptr_add(hash, (2 + nb_buckets + 1) * sizeof(int));
    ptr[0] = nb_buckets;
    ptr[1] = 1;
    memset(ptr + 2, 0, (nb_buckets + 1) * sizeof(int));
    return symtab;
}
static void section_realloc(Section *sec, unsigned int new_size)
{
    unsigned int size;
    unsigned char *data;
    size = sec->data_allocated;
    if (size == 0)
        size = 1;
    while (size < new_size)
        size = size * 2;
    data = tcc_realloc(sec->data, size);
    memset(data + sec->data_allocated, 0, size - sec->data_allocated);
    sec->data = data;
    sec->data_allocated = size;
}
static size_t section_add(Section *sec, Elf32_Addr size, int align)
{
    size_t offset, offset1;
    offset = (sec->data_offset + align - 1) & -align;
    offset1 = offset + size;
    if (sec->sh_type != 8 && offset1 > sec->data_allocated)
        section_realloc(sec, offset1);
    sec->data_offset = offset1;
    if (align > sec->sh_addralign)
        sec->sh_addralign = align;
    return offset;
}
static void *section_ptr_add(Section *sec, Elf32_Addr size)
{
    size_t offset = section_add(sec, size, 1);
    return sec->data + offset;
}
static void section_reserve(Section *sec, unsigned int size)
{
    if (size > sec->data_allocated)
        section_realloc(sec, size);
    if (size > sec->data_offset)
        sec->data_offset = size;
}
static int put_elf_str(Section *s, char *sym)
{
    int offset, len;
    char *ptr;
    len = strlen(sym) + 1;
    offset = s->data_offset;
    ptr = section_ptr_add(s, len);
    memmove(ptr, sym, len);
    return offset;
}
static unsigned int elf_hash(unsigned char *name)
{
    unsigned int h = 0, g;
    while (*name) {
        h = (h << 4) + *name++;
        g = h & 0xf0000000;
        if (g)
            h ^= g >> 24;
        h &= ~g;
    }
    return h;
}
static void rebuild_hash(Section *s, unsigned int nb_buckets)
{
    Elf32_Sym *sym;
    int *ptr, *hash, nb_syms, sym_index, h;
    unsigned char *strtab;
    strtab = s->link->data;
    nb_syms = s->data_offset / sizeof(Elf32_Sym);
    if (!nb_buckets)
        nb_buckets = ((int*)s->hash->data)[0];
    s->hash->data_offset = 0;
    ptr = section_ptr_add(s->hash, (2 + nb_buckets + nb_syms) * sizeof(int));
    ptr[0] = nb_buckets;
    ptr[1] = nb_syms;
    ptr += 2;
    hash = ptr;
    memset(hash, 0, (nb_buckets + 1) * sizeof(int));
    ptr += nb_buckets + 1;
    sym = (Elf32_Sym *)s->data + 1;
    for(sym_index = 1; sym_index < nb_syms; sym_index++) {
        if ((((unsigned char) (esy_info(sym))) >> 4) != 0) {
            h = elf_hash(strtab + esy_name(sym)) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_index;
        } else {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}
static int put_elf_sym(Section *s, Elf32_Addr value, unsigned int size,
    int info, int other, int shndx, char *name)
{
    int name_offset, sym_index;
    int nbuckets, h;
    Elf32_Sym *sym;
    Section *hs;
    sym = section_ptr_add(s, sizeof(Elf32_Sym));
    if (name && name[0])
        name_offset = put_elf_str(s->link, name);
    else
        name_offset = 0;
    esy_set_name(sym, name_offset);
    esy_set_value(sym, value);
    esy_set_size(sym, size);
    esy_set_info(sym, info);
    esy_set_other(sym, other);
    esy_set_shndx(sym, shndx);
    sym_index = sym - (Elf32_Sym *)s->data;
    hs = s->hash;
    if (hs) {
        int *ptr, *base;
        ptr = section_ptr_add(hs, sizeof(int));
        base = (int *)hs->data;
        if ((((unsigned char) (info)) >> 4) != 0) {
            nbuckets = base[0];
            h = elf_hash((unsigned char *)s->link->data + name_offset) % nbuckets;
            *ptr = base[2 + h];
            base[2 + h] = sym_index;
            base[1]++;
            hs->nb_hashed_syms++;
            if (hs->nb_hashed_syms > 2 * nbuckets) {
                rebuild_hash(s, 2 * nbuckets);
            }
        } else {
            *ptr = 0;
            base[1]++;
        }
    }
    return sym_index;
}
static int find_elf_sym(Section *s, char *name)
{
    Elf32_Sym *sym;
    Section *hs;
    int nbuckets, sym_index, h;
    char *name1;
    hs = s->hash;
    if (!hs)
        return 0;
    nbuckets = ((int *)hs->data)[0];
    h = elf_hash((unsigned char *) name) % nbuckets;
    sym_index = ((int *)hs->data)[2 + h];
    while (sym_index != 0) {
        sym = &((Elf32_Sym *)s->data)[sym_index];
        name1 = (char *) s->link->data + esy_name(sym);
        if (!strcmp(name, name1))
            return sym_index;
        sym_index = ((int *)hs->data)[2 + nbuckets + sym_index];
    }
    return 0;
}
static Elf32_Addr get_elf_sym_addr(TCCState *s, char *name, int err)
{
    int sym_index;
    Elf32_Sym *sym;
    sym_index = find_elf_sym(s->symtab, name);
    sym = &((Elf32_Sym *)s->symtab->data)[sym_index];
    if (!sym_index || esy_shndx(sym) == 0) {
        if (err)
            tcc_error("%s not defined", name);
        return 0;
    }
    return esy_value(sym);
}
static int set_elf_sym(Section *s, Elf32_Addr value, unsigned int size,
                       int info, int other, int shndx, char *name)
{
    Elf32_Sym *esym;
    int sym_bind, sym_index, sym_type, esym_bind;
    unsigned char sym_vis, esym_vis, new_vis;
    sym_bind = (((unsigned char) (info)) >> 4);
    sym_type = ((info) & 0xf);
    sym_vis = ((other) & 0x03);
    if (sym_bind != 0) {
        sym_index = find_elf_sym(s, name);
        if (sym_index) {
            int patch = 0;
            esym = &((Elf32_Sym *)s->data)[sym_index];
            if (esy_value(esym) == value && esy_size(esym) == size && esy_info(esym) == info
                && esy_other(esym) == other && esy_shndx(esym) == shndx)
                return sym_index;
            if (esy_shndx(esym) != 0) {
                esym_bind = (((unsigned char) (esy_info(esym))) >> 4);
                esym_vis = ((esy_other(esym)) & 0x03);
                if (esym_vis == 0) {
                    new_vis = sym_vis;
                } else if (sym_vis == 0) {
                    new_vis = esym_vis;
                } else {
                    new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
                }
                esy_set_other(esym, (esy_other(esym) & ~((-1) & 0x03))
                                 | new_vis);
                other = esy_other(esym);
                if (shndx == 0) {
                } else if (sym_bind == 1 && esym_bind == 2) {
                    patch = 1;
                } else if (sym_bind == 2 && esym_bind == 1) {
                } else if (sym_bind == 2 && esym_bind == 2) {
                } else if (sym_vis == 2 || sym_vis == 1) {
                } else if ((esy_shndx(esym) == 0xfff2
                                || esy_shndx(esym) == bss_section->sh_num)
                            && (shndx < 0xff00
                                && shndx != bss_section->sh_num)) {
                    patch = 1;
                } else if (shndx == 0xfff2 || shndx == bss_section->sh_num) {
                } else if (s->sh_flags & 0x40000000) {
	        } else if (esy_other(esym) & 0x04) {
		    patch = 1;
                } else {
                    tcc_error("'%s' defined twice", name);
                }
            } else {
                patch = 1;
            }
            if (patch) {
                esy_set_info(esym, (((sym_bind) << 4) + ((sym_type) & 0xf)));
                esy_set_shndx(esym, shndx);
                new_undef_sym = 1;
                esy_set_value(esym, value);
                esy_set_size(esym, size);
                esy_set_other(esym, other);
            }
        } else {
            sym_index = put_elf_sym(s, value, size,
                                    (((sym_bind) << 4) + ((sym_type) & 0xf)), other,
                                    shndx, name);
        }
    } else {
        sym_index = put_elf_sym(s, value, size,
                                (((sym_bind) << 4) + ((sym_type) & 0xf)), other,
                                shndx, name);
    }
    return sym_index;
}
static void put_elf_reloca(Section *symtab, Section *s, unsigned int offset,
                            int type, int symbol, Elf32_Addr addend)
{
    char buf[256];
    Section *sr;
    Elf32_Rel *rel;
    sr = s->reloc;
    if (!sr) {
        snprintf(buf, sizeof(buf), ".rel%s", s->name);
        sr = new_section(tcc_state, buf, 9, symtab->sh_flags);
        sr->sh_entsize = sizeof(Elf32_Rel);
        sr->link = symtab;
        sr->sh_info = s->sh_num;
        s->reloc = sr;
    }
    rel = section_ptr_add(sr, sizeof(Elf32_Rel));
    rel_set_offset(rel, offset);
    rel_set_sym_type(rel, symbol, type);
    if (addend)
        tcc_error("non-zero addend on REL architecture");
}
static void put_elf_reloc(Section *symtab, Section *s, unsigned int offset,
                           int type, int symbol)
{
    put_elf_reloca(symtab, s, offset, type, symbol, 0);
}
static SymAttr *get_sym_attr(TCCState *s1, int index, int alloc)
{
    int n;
    SymAttr *tab;
    if (index >= s1->nb_sym_attrs) {
        if (!alloc)
            return s1->sym_attrs;
        n = 1;
        while (index >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * 4 * sizeof(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(sattr_at(s1->sym_attrs, s1->nb_sym_attrs), 0,
               (n - s1->nb_sym_attrs) * 4 * sizeof(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    return sattr_at(s1->sym_attrs, index);
}
static void sort_syms(TCCState *s1, Section *s)
{
    int *old_to_new_syms;
    Elf32_Sym *new_syms;
    int nb_syms, i;
    Elf32_Sym *p, *q;
    Elf32_Rel *rel;
    Section *sr;
    int type, sym_index;
    nb_syms = s->data_offset / sizeof(Elf32_Sym);
    new_syms = tcc_malloc(nb_syms * sizeof(Elf32_Sym));
    old_to_new_syms = tcc_malloc(nb_syms * sizeof(int));
    p = (Elf32_Sym *)s->data;
    q = new_syms;
    for(i = 0; i < nb_syms; i++) {
        if ((((unsigned char) (esy_info(p))) >> 4) == 0) {
            old_to_new_syms[i] = q - new_syms;
            memcpy(q, p, sizeof(Elf32_Sym));
            q++;
        }
        p++;
    }
    if( s->sh_size )
        s->sh_info = q - new_syms;
    p = (Elf32_Sym *)s->data;
    for(i = 0; i < nb_syms; i++) {
        if ((((unsigned char) (esy_info(p))) >> 4) != 0) {
            old_to_new_syms[i] = q - new_syms;
            memcpy(q, p, sizeof(Elf32_Sym));
            q++;
        }
        p++;
    }
    memcpy(s->data, new_syms, nb_syms * sizeof(Elf32_Sym));
    tcc_free(new_syms);
    for(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        if (sr->sh_type == 9 && sr->link == s) {
            for (rel = (Elf32_Rel *) sr->data + 0; rel < (Elf32_Rel *) (sr->data + sr->data_offset); rel++) {
                sym_index = rel_sym(rel);
                type = rel_type(rel);
                sym_index = old_to_new_syms[sym_index];
                rel_set_sym_type(rel, sym_index, type);
            }
        }
    }
    tcc_free(old_to_new_syms);
}
static void relocate_syms(TCCState *s1, Section *symtab, int do_resolve)
{
    Elf32_Sym *sym;
    int sym_bind, sh_num;
    char *name;
    for (sym = (Elf32_Sym *) symtab->data + 1; sym < (Elf32_Sym *) (symtab->data + symtab->data_offset); sym++) {
        sh_num = esy_shndx(sym);
        if (sh_num == 0) {
            name = (char *) s1->symtab->link->data + esy_name(sym);
            if (!(!do_resolve && s1->dynsym && find_elf_sym(s1->dynsym, name)) &&
                strcmp(name, "_fp_hw")) {
                sym_bind = (((unsigned char) (esy_info(sym))) >> 4);
                if (sym_bind == 2)
                    esy_set_value(sym, 0);
                else
                    tcc_error("undefined symbol '%s'", name);
            }
        } else if (sh_num < 0xff00) {
            esy_add_value(sym, s1->sections[esy_shndx(sym)]->sh_addr);
        }
    }
}
static void relocate_section(TCCState *s1, Section *s)
{
    Section *sr = s->reloc;
    Elf32_Rel *rel;
    Elf32_Sym *sym;
    int type, sym_index;
    unsigned char *ptr;
    Elf32_Addr tgt, addr;
    for (rel = (Elf32_Rel *) sr->data + 0; rel < (Elf32_Rel *) (sr->data + sr->data_offset); rel++) {
        ptr = s->data + rel_offset(rel);
        sym_index = rel_sym(rel);
        sym = &((Elf32_Sym *)symtab_section->data)[sym_index];
        type = rel_type(rel);
        tgt = esy_value(sym);
        addr = s->sh_addr + rel_offset(rel);
        relocate(s1, rel, type, ptr, addr, tgt);
    }
    if (sr->sh_flags & (1 << 1))
        sr->link = s1->dynsym;
}
static void relocate_rel(TCCState *s1, Section *sr)
{
    Section *s;
    Elf32_Rel *rel;
    s = s1->sections[sr->sh_info];
    for (rel = (Elf32_Rel *) sr->data + 0; rel < (Elf32_Rel *) (sr->data + sr->data_offset); rel++)
        rel_add_offset(rel, s->sh_addr);
}
static void build_got(TCCState *s1)
{
    s1->got = new_section(s1, ".got", 1, (1 << 1) | (1 << 0));
    s1->got->sh_entsize = 4;
    set_elf_sym(symtab_section, 0, 4, (((1) << 4) + ((1) & 0xf)),
                0, s1->got->sh_num, "_GLOBAL_OFFSET_TABLE_");
    section_ptr_add(s1->got, 3 * 4);
}
static SymAttr * put_got_entry(TCCState *s1, int dyn_reloc_type,
                               unsigned int size,
                               int info, int sym_index)
{
    int need_plt_entry;
    char *name;
    Elf32_Sym *sym;
    SymAttr *attr;
    unsigned got_offset;
    char plt_name[100];
    int len;
    need_plt_entry = (dyn_reloc_type == 7);
    attr = get_sym_attr(s1, sym_index, 1);
    if (need_plt_entry ? sattr_plt_offset(attr) : sattr_got_offset(attr))
        return attr;
    got_offset = s1->got->data_offset;
    section_ptr_add(s1->got, 4);
    sym = &((Elf32_Sym *) symtab_section->data)[sym_index];
    name = (char *) symtab_section->link->data + esy_name(sym);
    if (s1->dynsym) {
	if ((((unsigned char) (esy_info(sym))) >> 4) == 0) {
	    put_elf_reloc(s1->dynsym, s1->got, got_offset, 8,
			  sym_index);
	} else {
	    if (0 == sattr_dyn_index(attr))
                sattr_set_dyn_index(attr, set_elf_sym(s1->dynsym, esy_value(sym), size,
					      info, 0, esy_shndx(sym), name));
	    put_elf_reloc(s1->dynsym, s1->got, got_offset, dyn_reloc_type,
			  sattr_dyn_index(attr));
	}
    } else {
        put_elf_reloc(symtab_section, s1->got, got_offset, dyn_reloc_type,
                      sym_index);
    }
    if (need_plt_entry) {
        if (!s1->plt) {
    	    s1->plt = new_section(s1, ".plt", 1,
    			          (1 << 1) | (1 << 2));
    	    s1->plt->sh_entsize = 4;
        }
        sattr_set_plt_offset(attr, create_plt_entry(s1, got_offset, attr));
        len = strlen(name);
        if (len > sizeof plt_name - 5)
            len = sizeof plt_name - 5;
        memcpy(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        sattr_set_plt_sym(attr, put_elf_sym(s1->symtab, sattr_plt_offset(attr), esy_size(sym),
            (((1) << 4) + ((2) & 0xf)), 0, s1->plt->sh_num, plt_name));
    } else {
        sattr_set_got_offset(attr, got_offset);
    }
    return attr;
}
static void build_got_entries(TCCState *s1)
{
    Section *s;
    Elf32_Rel *rel;
    Elf32_Sym *sym;
    int i, type, gotplt_entry, reloc_type, sym_index;
    SymAttr *attr;
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        if (s->sh_type != 9)
            continue;
        if (s->link != symtab_section)
            continue;
        for (rel = (Elf32_Rel *) s->data + 0; rel < (Elf32_Rel *) (s->data + s->data_offset); rel++) {
            type = rel_type(rel);
            gotplt_entry = gotplt_entry_type(type);
            sym_index = rel_sym(rel);
            sym = &((Elf32_Sym *)symtab_section->data)[sym_index];
            if (gotplt_entry == 0) {
                continue;
            }
            if (gotplt_entry == 2) {
                int use_jmp_slot = 0;
                if (esy_shndx(sym) == 0) {
                    Elf32_Sym *esym;
		    int dynindex;
		    if (s1->dynsym) {
			dynindex = sattr_dyn_index(get_sym_attr(s1, sym_index, 0));
			esym = (Elf32_Sym *)s1->dynsym->data + dynindex;
			if (dynindex
			    && (((esy_info(esym)) & 0xf) == 2
				|| (((esy_info(esym)) & 0xf) == 0
				    && ((esy_info(sym)) & 0xf) == 2)))
			    use_jmp_slot = 1;
		    }
	                } else
	                    continue;
                reloc_type = use_jmp_slot || code_reloc(type) ? 7 : 6;
            } else {
                reloc_type = code_reloc(type) ? 7 : 6;
            }
            if (!s1->got)
                build_got(s1);
            if (gotplt_entry == 1)
                continue;
            attr = put_got_entry(s1, reloc_type, esy_size(sym), esy_info(sym),
                                 sym_index);
            if (reloc_type == 7)
                rel_set_sym_type(rel, sattr_plt_sym(attr), type);
        }
    }
}
static void put_dt(Section *dynamic, int dt, Elf32_Addr val)
{
    Elf32_Dyn *dyn;
    dyn = section_ptr_add(dynamic, sizeof(Elf32_Dyn));
    dyn_set_tag(dyn, dt);
    dyn_set_un(dyn, val);
}
static void tcc_add_runtime(TCCState *s1)
{
    if (!s1->nostdlib) {
        tcc_add_library(s1, "c");
        tcc_add_crt(s1, "crtn.o");
    }
}
static void tcc_add_linker_symbols(TCCState *s1)
{
    set_elf_sym(symtab_section,
                text_section->data_offset, 0,
                (((1) << 4) + ((0) & 0xf)), 0,
                text_section->sh_num, "_etext");
    set_elf_sym(symtab_section,
                data_section->data_offset, 0,
                (((1) << 4) + ((0) & 0xf)), 0,
                data_section->sh_num, "_edata");
    set_elf_sym(symtab_section,
                bss_section->data_offset, 0,
                (((1) << 4) + ((0) & 0xf)), 0,
                bss_section->sh_num, "_end");
}
static void resolve_common_syms(TCCState *s1)
{
    Elf32_Sym *sym;
    for (sym = (Elf32_Sym *) symtab_section->data + 1; sym < (Elf32_Sym *) (symtab_section->data + symtab_section->data_offset); sym++) {
        if (esy_shndx(sym) == 0xfff2) {
	    esy_set_value(sym, section_add(bss_section, esy_size(sym),
					esy_value(sym)));
            esy_set_shndx(sym, bss_section->sh_num);
        }
    }
    tcc_add_linker_symbols(s1);
}
static void fill_local_got_entries(TCCState *s1)
{
    Elf32_Rel *rel;
    for (rel = (Elf32_Rel *) s1->got->reloc->data + 0; rel < (Elf32_Rel *) (s1->got->reloc->data + s1->got->reloc->data_offset); rel++) {
	if (rel_type(rel) == 8) {
	    int sym_index = rel_sym(rel);
	    Elf32_Sym *sym = &((Elf32_Sym *) symtab_section->data)[sym_index];
	    SymAttr *attr = get_sym_attr(s1, sym_index, 0);
	    unsigned offset = sattr_got_offset(attr);
	    if (offset != rel_offset(rel) - s1->got->sh_addr)
	      tcc_error("huh");
	    rel_set_sym_type(rel, 0, 8);
	    write32le(s1->got->data + offset, esy_value(sym));
	}
    }
}
static void bind_exe_dynsyms(TCCState *s1)
{
    char *name;
    int dynindex, index;
    Elf32_Sym *sym;
    for (sym = (Elf32_Sym *) symtab_section->data + 1; sym < (Elf32_Sym *) (symtab_section->data + symtab_section->data_offset); sym++) {
        if (esy_shndx(sym) == 0) {
            name = (char *) symtab_section->link->data + esy_name(sym);
            if ((((unsigned char) (esy_info(sym))) >> 4) == 2 ||
                !strcmp(name, "_fp_hw"))
                continue;
            dynindex = put_elf_sym(s1->dynsym, 0, esy_size(sym),
                                   (((1) << 4) + ((2) & 0xf)), 0, 0,
                                   name);
            index = sym - (Elf32_Sym *) symtab_section->data;
            sattr_set_dyn_index(get_sym_attr(s1, index, 1), dynindex);
        }
    }
}
static void alloc_sec_names(TCCState *s1, int file_type, Section *strsec)
{
    int i;
    Section *s;
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        if (file_type == 4 ||
            (s->sh_flags & (1 << 1)) ||
	    i == (s1->nb_sections - 1)) {
            s->sh_size = s->data_offset;
        }
	if (s->sh_size || (s->sh_flags & (1 << 1)))
            s->sh_name = put_elf_str(strsec, s->name);
    }
    strsec->sh_size = strsec->data_offset;
}
typedef unsigned int DynInf;
static Section *dyni_dynamic(DynInf *d)
{
    return (Section *)*d;
}
static void dyni_set_dynamic(DynInf *d, Section *s)
{
    *d = (unsigned int)s;
}
static Section *dyni_dynstr(DynInf *d)
{
    return (Section *)*(d + 1);
}
static void dyni_set_dynstr(DynInf *d, Section *s)
{
    *(d + 1) = (unsigned int)s;
}
static unsigned int dyni_data_offset(DynInf *d)
{
    return *(d + 2);
}
static void dyni_set_data_offset(DynInf *d, unsigned int offset)
{
    *(d + 2) = offset;
}
static Elf32_Addr dyni_rel_addr(DynInf *d)
{
    return *(d + 3);
}
static void dyni_set_rel_addr(DynInf *d, Elf32_Addr addr)
{
    *(d + 3) = addr;
}
static Elf32_Addr dyni_rel_size(DynInf *d)
{
    return *(d + 4);
}
static void dyni_set_rel_size(DynInf *d, Elf32_Addr size)
{
    *(d + 4) = size;
}
static void dyni_add_rel_size(DynInf *d, Elf32_Addr size)
{
    *(d + 4) = *(d + 4) + size;
}
static int layout_sections(TCCState *s1, Elf32_Phdr *phdr, int phnum,
                           Section *interp, Section* strsec,
                           DynInf *dyninf, int *sec_order)
{
    int i, j, k, sh_order_index, file_offset;
    unsigned int s_align;
    int tmp;
    Elf32_Addr addr;
    Elf32_Phdr *ph;
    Section *s;
    sh_order_index = 1;
    file_offset = sizeof(Elf32_Ehdr) + phnum * sizeof(Elf32_Phdr);
    s_align = 0x1000;
    if (phnum > 0) {
        addr = 0x08048000 + (file_offset & (s_align - 1));
        ph = &phdr[0];
        if (interp)
            ph += 2;
        dyni_set_rel_addr(dyninf, 0);
        dyni_set_rel_size(dyninf, 0);
        for(j = 0; j < 2; j++) {
            ph_set_type(ph, 1);
            if (j == 0)
                ph_set_flags(ph, (1 << 2) | (1 << 0));
            else
                ph_set_flags(ph, (1 << 2) | (1 << 1));
            ph_set_align(ph, s_align);
            for(k = 0; k < 5; k++) {
                for(i = 1; i < s1->nb_sections; i++) {
                    s = s1->sections[i];
                    if (j == 0) {
                        if ((s->sh_flags & ((1 << 1) | (1 << 0))) !=
                            (1 << 1))
                            continue;
                    } else {
                        if ((s->sh_flags & ((1 << 1) | (1 << 0))) !=
                            ((1 << 1) | (1 << 0)))
                            continue;
                    }
                    if (s == interp) {
                        if (k != 0)
                            continue;
                    } else if (s->sh_type == 11 ||
                               s->sh_type == 3 ||
                               s->sh_type == 5) {
                        if (k != 1)
                            continue;
                    } else if (s->sh_type == 9) {
                        if (k != 2)
                            continue;
                    } else if (s->sh_type == 8) {
                        if (k != 4)
                            continue;
                    } else {
                        if (k != 3)
                            continue;
                    }
                    sec_order[sh_order_index++] = i;
                    tmp = addr;
                    addr = (addr + s->sh_addralign - 1) &
                        ~(s->sh_addralign - 1);
                    file_offset += (int) ( addr - tmp );
                    s->sh_offset = file_offset;
                    s->sh_addr = addr;
                    if (ph_offset(ph) == 0) {
                        ph_set_offset(ph, file_offset);
                        ph_set_vaddr(ph, addr);
                        ph_set_paddr(ph, ph_vaddr(ph));
                    }
                    if (s->sh_type == 9) {
                        if (dyni_rel_size(dyninf) == 0)
                            dyni_set_rel_addr(dyninf, addr);
                        dyni_add_rel_size(dyninf, s->sh_size);
                    }
                    addr += s->sh_size;
                    if (s->sh_type != 8)
                        file_offset += s->sh_size;
                }
            }
	    if (j == 0) {
		ph_and_offset(ph, ~(ph_align(ph) - 1));
		ph_and_vaddr(ph, ~(ph_align(ph) - 1));
		ph_set_paddr(ph, ph_paddr(ph) & ~(ph_align(ph) - 1));
	    }
            ph_set_filesz(ph, file_offset - ph_offset(ph));
            ph_set_memsz(ph, addr - ph_vaddr(ph));
            ph++;
            if (j == 0) {
                if ((addr & (s_align - 1)) != 0)
                    addr += s_align;
            }
        }
    }
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        if (phnum > 0 && (s->sh_flags & (1 << 1)))
            continue;
        sec_order[sh_order_index++] = i;
        file_offset = (file_offset + s->sh_addralign - 1) &
            ~(s->sh_addralign - 1);
        s->sh_offset = file_offset;
        if (s->sh_type != 8)
            file_offset += s->sh_size;
    }
    return file_offset;
}
static void fill_unloadable_phdr(Elf32_Phdr *phdr, int phnum, Section *interp,
                                 Section *dynamic)
{
    Elf32_Phdr *ph;
    if (interp) {
        ph = &phdr[0];
        ph_set_type(ph, 6);
        ph_set_offset(ph, sizeof(Elf32_Ehdr));
        ph_set_sizes(ph, phnum * sizeof(Elf32_Phdr),
                     phnum * sizeof(Elf32_Phdr));
        ph_set_vaddr(ph, interp->sh_addr - ph_filesz(ph));
        ph_set_paddr(ph, ph_vaddr(ph));
        ph_set_flags(ph, (1 << 2) | (1 << 0));
        ph_set_align(ph, 4);
        ph++;
        ph_set_type(ph, 3);
        ph_set_offset(ph, interp->sh_offset);
        ph_set_vaddr(ph, interp->sh_addr);
        ph_set_paddr(ph, ph_vaddr(ph));
        ph_set_filesz(ph, interp->sh_size);
        ph_set_memsz(ph, interp->sh_size);
        ph_set_flags(ph, (1 << 2));
        ph_set_align(ph, interp->sh_addralign);
    }
    if (dynamic) {
        ph = &phdr[phnum - 1];
        ph_set_type(ph, 2);
        ph_set_offset(ph, dynamic->sh_offset);
        ph_set_vaddr(ph, dynamic->sh_addr);
        ph_set_paddr(ph, ph_vaddr(ph));
        ph_set_filesz(ph, dynamic->sh_size);
        ph_set_memsz(ph, dynamic->sh_size);
        ph_set_flags(ph, (1 << 2) | (1 << 1));
        ph_set_align(ph, dynamic->sh_addralign);
    }
}
static void fill_dynamic(TCCState *s1, DynInf *dyninf)
{
    Section *dynamic = dyni_dynamic(dyninf);
    put_dt(dynamic, 4, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, 5, dyni_dynstr(dyninf)->sh_addr);
    put_dt(dynamic, 6, s1->dynsym->sh_addr);
    put_dt(dynamic, 10, dyni_dynstr(dyninf)->data_offset);
    put_dt(dynamic, 11, sizeof(Elf32_Sym));
    put_dt(dynamic, 17, dyni_rel_addr(dyninf));
    put_dt(dynamic, 18, dyni_rel_size(dyninf));
    put_dt(dynamic, 19, sizeof(Elf32_Rel));
    put_dt(dynamic, 0, 0);
}
static int final_sections_reloc(TCCState *s1)
{
    int i;
    Section *s;
    relocate_syms(s1, s1->symtab, 0);
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        if (s->reloc && s != s1->got && (s->sh_flags & (1 << 1)))
            relocate_section(s1, s);
    }
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        if ((s->sh_flags & (1 << 1)) &&
            s->sh_type == 9) {
            relocate_rel(s1, s);
        }
    }
    return 0;
}
static void tcc_output_elf(TCCState *s1, FILE *f, int phnum, Elf32_Phdr *phdr,
                           int file_offset, int *sec_order)
{
    int i, shnum, offset, size, file_type;
    Section *s;
    Elf32_Ehdr ehdr;
    Elf32_Shdr shdr, *sh;
    file_type = s1->output_type;
    shnum = s1->nb_sections;
    memset(&ehdr, 0, sizeof(ehdr));
    if (phnum > 0) {
        eh_set_phentsize(&ehdr, sizeof(Elf32_Phdr));
        eh_set_phnum(&ehdr, phnum);
        eh_set_phoff(&ehdr, sizeof(Elf32_Ehdr));
    }
    file_offset = (file_offset + 3) & -4;
    eh_set_ident(&ehdr, 0, 0x7f);
    eh_set_ident(&ehdr, 1, 'E');
    eh_set_ident(&ehdr, 2, 'L');
    eh_set_ident(&ehdr, 3, 'F');
    eh_set_ident(&ehdr, 4, 1);
    eh_set_ident(&ehdr, 5, 1);
    eh_set_ident(&ehdr, 6, 1);
    if (file_type == 4) {
        eh_set_type(&ehdr, 1);
    } else {
        eh_set_type(&ehdr, 2);
        eh_set_entry(&ehdr, get_elf_sym_addr(s1, "_start", 1));
    }
    eh_set_machine(&ehdr, 3);
    eh_set_version(&ehdr, 1);
    eh_set_shoff(&ehdr, file_offset);
    eh_set_ehsize(&ehdr, sizeof(Elf32_Ehdr));
    eh_set_shentsize(&ehdr, sizeof(Elf32_Shdr));
    eh_set_shnum(&ehdr, shnum);
    eh_set_shstrndx(&ehdr, shnum - 1);
    fwrite(&ehdr, 1, sizeof(Elf32_Ehdr), f);
    fwrite(phdr, 1, phnum * sizeof(Elf32_Phdr), f);
    offset = sizeof(Elf32_Ehdr) + phnum * sizeof(Elf32_Phdr);
    sort_syms(s1, symtab_section);
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[sec_order[i]];
        if (s->sh_type != 8) {
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
    while (offset < eh_shoff(&ehdr)) {
        fputc(0, f);
        offset++;
    }
    for(i = 0; i < s1->nb_sections; i++) {
        sh = &shdr;
        memset(sh, 0, sizeof(Elf32_Shdr));
        s = s1->sections[i];
        if (s) {
            sh_set_name(sh, s->sh_name);
            sh_set_type(sh, s->sh_type);
            sh_set_flags(sh, s->sh_flags);
            sh_set_entsize(sh, s->sh_entsize);
            sh_set_info(sh, s->sh_info);
            if (s->link)
                sh_set_link(sh, s->link->sh_num);
            sh_set_addralign(sh, s->sh_addralign);
            sh_set_addr(sh, s->sh_addr);
            sh_set_offset(sh, s->sh_offset);
            sh_set_size(sh, s->sh_size);
        }
        fwrite(sh, 1, sizeof(Elf32_Shdr), f);
    }
}
static int tcc_write_elf_file(TCCState *s1, char *filename, int phnum,
                              Elf32_Phdr *phdr, int file_offset, int *sec_order)
{
    FILE *f;
    unlink(filename);
    f = fopen(filename, "wb");
    tcc_output_elf(s1, f, phnum, phdr, file_offset, sec_order);
    fclose(f);
    return 0;
}
static void tidy_section_headers(TCCState *s1, int *sec_order)
{
    int i, nnew, l, *backmap;
    Section **snew, *s;
    Elf32_Sym *sym;
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
            if (s->sh_type == 9)
		s->sh_info = backmap[s->sh_info];
	}
    }
    for (sym = (Elf32_Sym *) symtab_section->data + 1; sym < (Elf32_Sym *) (symtab_section->data + symtab_section->data_offset); sym++)
	if (esy_shndx(sym) != 0 && esy_shndx(sym) < 0xff00)
	    esy_set_shndx(sym, backmap[esy_shndx(sym)]);
    for (sym = (Elf32_Sym *) s1->dynsym->data + 1; sym < (Elf32_Sym *) (s1->dynsym->data + s1->dynsym->data_offset); sym++)
        if (esy_shndx(sym) != 0 && esy_shndx(sym) < 0xff00)
            esy_set_shndx(sym, backmap[esy_shndx(sym)]);
    for (i = 0; i < s1->nb_sections; i++)
	sec_order[i] = i;
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}
static int elf_output_file(TCCState *s1, char *filename)
{
    int i, ret, phnum, shnum, file_type, file_offset, *sec_order;
    DynInf dyninf[5] = {0};
    Elf32_Phdr *phdr;
    Elf32_Sym *sym;
    Section *strsec, *interp, *dynamic, *dynstr;
    file_type = s1->output_type;
    ret = 0;
    phdr = ((void*)0);
    sec_order = ((void*)0);
    interp = dynamic = dynstr = ((void*)0);
    if (file_type != 4) {
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        if (file_type == 2) {
            char *ptr;
            interp = new_section(s1, ".interp", 1, (1 << 1));
            interp->sh_addralign = 1;
            ptr = section_ptr_add(interp, 1 + strlen("/lib/ld-linux.so.2"));
            strcpy(ptr, "/lib/ld-linux.so.2");
        }
        s1->dynsym = new_symtab(s1, ".dynsym", 11, (1 << 1),
                                ".dynstr",
                                ".hash", (1 << 1));
        dynstr = s1->dynsym->link;
        dynamic = new_section(s1, ".dynamic", 6,
                              (1 << 1) | (1 << 0));
        dynamic->link = dynstr;
        dynamic->sh_entsize = sizeof(Elf32_Dyn);
        build_got(s1);
        bind_exe_dynsyms(s1);
        build_got_entries(s1);
    }
    strsec = new_section(s1, ".shstrtab", 3, 0);
    put_elf_str(strsec, "");
    alloc_sec_names(s1, file_type, strsec);
    if (dynamic) {
        for(i = 0; i < s1->nb_loaded_dlls; i++) {
            DLLReference *dllref = s1->loaded_dlls[i];
            if (dllr_level(dllref) == 0)
                put_dt(dynamic, 1, put_elf_str(dynstr, dllr_name(dllref)));
        }
        dyni_set_dynamic(dyninf, dynamic);
        dyni_set_dynstr(dyninf, dynstr);
        dyni_set_data_offset(dyninf, dynamic->data_offset);
        fill_dynamic(s1, dyninf);
        dynamic->sh_size = dynamic->data_offset;
        dynstr->sh_size = dynstr->data_offset;
    }
    if (file_type == 4)
        phnum = 0;
    else
        phnum = 5;
    phdr = tcc_mallocz(phnum * sizeof(Elf32_Phdr));
    shnum = s1->nb_sections;
    sec_order = tcc_malloc(sizeof(int) * shnum);
    sec_order[0] = 0;
    file_offset = layout_sections(s1, phdr, phnum, interp, strsec, dyninf,
                                  sec_order);
    if (file_type != 4) {
        fill_unloadable_phdr(phdr, phnum, interp, dynamic);
        if (dynamic) {
            dynamic->data_offset = dyni_data_offset(dyninf);
            fill_dynamic(s1, dyninf);
            write32le(s1->got->data, dynamic->sh_addr);
            relocate_plt(s1);
            for (sym = (Elf32_Sym *) s1->dynsym->data + 1; sym < (Elf32_Sym *) (s1->dynsym->data + s1->dynsym->data_offset); sym++) {
                if (esy_shndx(sym) != 0 && esy_shndx(sym) < 0xff00) {
                    esy_add_value(sym, s1->sections[esy_shndx(sym)]->sh_addr);
                }
            }
        }
        ret = final_sections_reloc(s1);
        if (!ret) {
	    tidy_section_headers(s1, sec_order);
            if (s1->got && s1->got->reloc)
                fill_local_got_entries(s1);
        }
    }
    if (!ret)
        ret = tcc_write_elf_file(s1, filename, phnum, phdr, file_offset, sec_order);
    s1->nb_sections = shnum;
    tcc_free(sec_order);
    tcc_free(phdr);
    return ret;
}
static void *load_data(int fd, unsigned int file_offset, unsigned int size)
{
    void *data;
    data = tcc_malloc(size);
    lseek(fd, file_offset, 0);
    read(fd, data, size);
    return data;
}
typedef unsigned int SectionMergeInfo;
static SectionMergeInfo *smi_at(SectionMergeInfo *table, int index)
{
    return table + index + index + index;
}
static Section *smi_s(SectionMergeInfo *sm)
{
    return (Section *)*sm;
}
static void smi_set_s(SectionMergeInfo *sm, Section *s)
{
    *sm = (unsigned int)s;
}
static unsigned int smi_offset(SectionMergeInfo *sm)
{
    return *(sm + 1);
}
static void smi_set_offset(SectionMergeInfo *sm, unsigned int offset)
{
    *(sm + 1) = offset;
}
static int smi_new_section(SectionMergeInfo *sm)
{
    return *(sm + 2);
}
static void smi_set_new_section(SectionMergeInfo *sm, int val)
{
    *(sm + 2) = val;
}
static int tcc_object_type(int fd, Elf32_Ehdr *h)
{
    int size = read(fd, h, sizeof *h);
    if (size == sizeof *h && 0 == memcmp(h, "\177ELF", 4)) {
        if (eh_type(h) == 1)
            return 1;
    }
    return 0;
}
static int tcc_load_object_file(TCCState *s1,
                                int fd, unsigned int file_offset)
{
    Elf32_Ehdr ehdr;
    Elf32_Shdr *shdr, *sh;
    int size, i, j, offset, offseti, nb_syms, sym_index, ret, failed;
    unsigned char *strsec, *strtab;
    int *old_to_new_syms;
    char *sec_name, *name;
    SectionMergeInfo *sm_table, *sm;
    Elf32_Sym *sym, *symtab;
    Elf32_Rel *rel;
    Section *s;
    lseek(fd, file_offset, 0);
    if (tcc_object_type(fd, &ehdr) != 1 ||
        eh_ident(&ehdr, 5) != 1 ||
        eh_machine(&ehdr) != 3) {
        tcc_error("invalid object file");
        return -1;
    }
    shdr = load_data(fd, file_offset + eh_shoff(&ehdr),
                     sizeof(Elf32_Shdr) * eh_shnum(&ehdr));
    sm_table = tcc_mallocz(sizeof(SectionMergeInfo) * eh_shnum(&ehdr) * 3);
    sh = &shdr[eh_shstrndx(&ehdr)];
    strsec = load_data(fd, file_offset + sh_offset(sh), sh_size(sh));
    old_to_new_syms = ((void*)0);
    symtab = ((void*)0);
    strtab = ((void*)0);
    nb_syms = 0;
    ret = -1;
    failed = 0;
    for(i = 1; i < eh_shnum(&ehdr); i++) {
        sh = &shdr[i];
        if (sh_type(sh) == 2) {
            if (symtab) {
                tcc_error("object must contain only one symtab");
                failed = 1;
                break;
            }
            nb_syms = sh_size(sh) / sizeof(Elf32_Sym);
            symtab = load_data(fd, file_offset + sh_offset(sh), sh_size(sh));
            smi_set_s(smi_at(sm_table, i), symtab_section);
            sh = &shdr[sh_link(sh)];
            strtab = load_data(fd, file_offset + sh_offset(sh), sh_size(sh));
        }
    }
    for(i = 1; !failed && i < eh_shnum(&ehdr); i++) {
        if (i == eh_shstrndx(&ehdr))
            continue;
        sh = &shdr[i];
        sec_name = (char *) strsec + sh_name(sh);
        if (sh_type(sh) != 1 &&
            sh_type(sh) != 9 &&
            sh_type(sh) != 8 &&
            sh_type(sh) != 16 &&
            sh_type(sh) != 14 &&
            sh_type(sh) != 15 &&
	    strcmp(sec_name, ".stabstr")
            )
            continue;
        if (sh_addralign(sh) < 1)
            sh_set_addralign(sh, 1);
        s = ((void*)0);
        for(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            if (!strcmp(s->name, sec_name))
                break;
            s = ((void*)0);
        }
        if (!s) {
            s = new_section(s1, sec_name, sh_type(sh), sh_flags(sh) & ~(1 << 9));
            s->sh_addralign = sh_addralign(sh);
            s->sh_entsize = sh_entsize(sh);
            smi_set_new_section(smi_at(sm_table, i), 1);
        }
        if (sh_type(sh) != s->sh_type) {
            tcc_error("invalid section type");
            failed = 1;
            break;
        }
        offset = s->data_offset;
        size = sh_addralign(sh) - 1;
        offset = (offset + size) & ~size;
        if (sh_addralign(sh) > s->sh_addralign)
            s->sh_addralign = sh_addralign(sh);
        s->data_offset = offset;
        smi_set_offset(smi_at(sm_table, i), offset);
        smi_set_s(smi_at(sm_table, i), s);
        size = sh_size(sh);
        if (sh_type(sh) != 8) {
            unsigned char *ptr;
            lseek(fd, file_offset + sh_offset(sh), 0);
            ptr = section_ptr_add(s, size);
            read(fd, ptr, size);
        } else {
            s->data_offset += size;
        }
    }
    for(i = 1; !failed && i < eh_shnum(&ehdr); i++) {
        s = smi_s(smi_at(sm_table, i));
        if (!s || !smi_new_section(smi_at(sm_table, i)))
            continue;
        sh = &shdr[i];
        if (sh_link(sh) > 0)
            s->link = smi_s(smi_at(sm_table, sh_link(sh)));
        if (sh_type(sh) == 9) {
            s->sh_info = smi_s(smi_at(sm_table, sh_info(sh)))->sh_num;
            s1->sections[s->sh_info]->reloc = s;
        }
    }
    sm = smi_at(sm_table, 0);
    old_to_new_syms = tcc_mallocz(nb_syms * sizeof(int));
    if (!failed && nb_syms) {
        sym = symtab + 1;
        for(i = 1; i < nb_syms; i++, sym++) {
            if (esy_shndx(sym) != 0 &&
                esy_shndx(sym) < 0xff00) {
                sm = smi_at(sm_table, esy_shndx(sym));
                if (!smi_s(sm))
                    continue;
                esy_set_shndx(sym, smi_s(sm)->sh_num);
                esy_add_value(sym, smi_offset(sm));
            }
            name = (char *) strtab + esy_name(sym);
            sym_index = set_elf_sym(symtab_section, esy_value(sym), esy_size(sym),
                                    esy_info(sym), esy_other(sym),
                                    esy_shndx(sym), name);
            old_to_new_syms[i] = sym_index;
        }
    }
    for(i = 1; !failed && i < eh_shnum(&ehdr); i++) {
        s = smi_s(smi_at(sm_table, i));
        if (!s)
            continue;
        sh = &shdr[i];
        offset = smi_offset(smi_at(sm_table, i));
        if (s->sh_type == 9) {
            offseti = smi_offset(smi_at(sm_table, sh_info(sh)));
            for (rel = (Elf32_Rel *) s->data + (offset / sizeof(*rel)); rel < (Elf32_Rel *) (s->data + s->data_offset); rel++) {
                int type;
                unsigned sym_index;
                type = rel_type(rel);
                sym_index = rel_sym(rel);
                if (sym_index < nb_syms)
                    sym_index = old_to_new_syms[sym_index];
                else
                    sym_index = 0;
                if (!sym_index) {
                    tcc_error("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh_name(sh), rel_offset(rel));
                    failed = 1;
                    break;
                }
                rel_set_sym_type(rel, sym_index, type);
                rel_add_offset(rel, offseti);
            }
        }
    }
    if (!failed)
        ret = 0;
    tcc_free(symtab);
    tcc_free(strtab);
    tcc_free(old_to_new_syms);
    tcc_free(sm_table);
    tcc_free(strsec);
    tcc_free(shdr);
    return ret;
}
static int reg_classes[4] = {
      0x0001 | 0x0004,
      0x0001 | 0x0010,
      0x0001 | 0x0020,
      (0x0001 | 0x0040) * 0,
};
static unsigned int func_sub_sp_offset;
static int func_ret_sub;
static void g(int c)
{
    int ind1;
    if (nocode_wanted)
        return;
    ind1 = ind + 1;
    if (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}
static void o(unsigned int c)
{
    while (c) {
        g(c);
        c = c >> 8;
    }
}
static void gen_le32(int c)
{
    g(c);
    g(c >> 8);
    g(c >> 16);
    g(c >> 24);
}
static void gsym_addr(int t, int a)
{
    while (t) {
        unsigned char *ptr = cur_text_section->data + t;
        uint32_t n = read32le(ptr);
        write32le(ptr, a - t - 4);
        t = n;
    }
}
static void gsym(int t)
{
    gsym_addr(t, ind);
}
static int oad(int c, int s)
{
    int t;
    if (nocode_wanted)
        return s;
    o(c);
    t = ind;
    gen_le32(s);
    return t;
}
static void gen_addr32(int r, Sym *sym, int c)
{
    if (r & 0x0200)
        greloc(cur_text_section, sym, ind, 1);
    gen_le32(c);
}
static void gen_modrm(int op_reg, int r, Sym *sym, int c)
{
    op_reg = op_reg << 3;
    if ((r & 0x003f) == 0x0030) {
        o(0x05 | op_reg);
        gen_addr32(r, sym, c);
    } else if ((r & 0x003f) == 0x0032) {
        if (c == (char)c) {
            o(0x45 | op_reg);
            g(c);
        } else {
            oad(0x85 | op_reg, c);
        }
    } else {
        g(0x00 | op_reg | (r & 0x003f));
    }
}
static void load(int r, SValue *sv)
{
    int v, t, ft, fc, fr;
    SValue v1;
    fr = sv->r;
    ft = sv->type.t & ~0x0020;
    fc = cv_i(&sv->c);
    ft &= ~(0x0200 | 0x0100);
    v = fr & 0x003f;
    if (fr & 0x0100) {
        if (v == 0x0031) {
            v1.type.t = 3;
            v1.r = 0x0032 | 0x0100;
            cv_set_i(&v1.c, fc);
            fr = r;
            if (!(reg_classes[fr] & 0x0001))
                fr = get_reg(0x0001);
            load(fr, &v1);
        }
        if ((ft & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)))) == 1 || (ft & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)))) == 11) {
            o(0xbe0f);
        } else if ((ft & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)))) == (1 | 0x0010)) {
            o(0xb60f);
        } else if ((ft & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)))) == 2) {
            o(0xbf0f);
        } else if ((ft & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)))) == (2 | 0x0010)) {
            o(0xb70f);
        } else {
            o(0x8b);
        }
        gen_modrm(r, fr, sv->sym, fc);
    } else {
        if (v == 0x0030) {
            o(0xb8 + r);
            gen_addr32(fr, sv->sym, fc);
        } else if (v == 0x0032) {
            if (fc) {
                o(0x8d);
                gen_modrm(r, 0x0032, sv->sym, fc);
            } else {
                o(0x89);
                o(0xe8 + r);
            }
        } else if (v == 0x0033) {
            oad(0xb8 + r, 0);
            o(0x0f);
            o(fc);
            o(0xc0 + r);
        } else if (v == 0x0034 || v == 0x0035) {
            t = v & 1;
            oad(0xb8 + r, t);
            o(0x05eb);
            gsym(fc);
            oad(0xb8 + r, t ^ 1);
        } else if (v != r) {
            o(0x89);
            o(0xc0 + r + v * 8);
        }
    }
}
static void store(int r, SValue *v)
{
    int fr, bt, ft, fc;
    ft = v->type.t;
    fc = cv_i(&v->c);
    fr = v->r & 0x003f;
    ft &= ~(0x0200 | 0x0100);
    bt = ft & 0x000f;
    if (bt == 2)
        o(0x66);
    if (bt == 1 || bt == 11)
        o(0x88);
    else
        o(0x89);
    if (fr == 0x0030 ||
        fr == 0x0032 ||
        (v->r & 0x0100)) {
        gen_modrm(r, v->r, v->sym, fc);
    } else if (fr != r) {
        o(0xc0 + fr + r * 8);
    }
}
static void gadd_sp(int val)
{
    if (val == (char)val) {
        o(0xc483);
        g(val);
    } else {
        oad(0xc481, val);
    }
}
static void gcall_or_jmp(int is_jmp)
{
    int r;
    if ((vtop->r & (0x003f | 0x0100)) == 0x0030 && (vtop->r & 0x0200)) {
        greloc(cur_text_section, vtop->sym, ind + 1, 2);
        oad(0xe8 + is_jmp, cv_i(&vtop->c) - 4);
    } else {
        r = gv(0x0001);
        o(0xff);
        o(0xd0 + r + (is_jmp << 4));
    }
    if (!is_jmp) {
        int rt;
        rt = vtop->type.ref->type.t;
        if ((rt & 0x000f) == 1) {
            if (rt & 0x0010) {
                o(0xc0b60f);
            } else {
                o(0xc0be0f);
            }
        } else if ((rt & 0x000f) == 2) {
            if (rt & 0x0010) {
                o(0xc0b70f);
            } else {
                o(0xc0bf0f);
            }
        }
    }
}
static void gfunc_call(int nb_args)
{
    int size, r, args_size, i;
    args_size = 0;
    for(i = 0;i < nb_args; i++) {
        if ((vtop->type.t & 0x000f) == 7) {
            tcc_error("struct arguments are not supported in tcc_27_alt");
        } else {
            r = gv(0x0001);
            size = 4;
            o(0x50 + r);
            args_size += size;
        }
        vtop--;
    }
    save_regs(0);
    gcall_or_jmp(0);
    if (args_size)
        gadd_sp(args_size);
    vtop--;
}
static void gfunc_prolog(CType *func_type)
{
    int addr, align, size, param_addr;
    Sym *sym;
    CType *type;
    sym = func_type->ref;
    addr = 8;
    loc = 0;
    ind += (9 + 0);
    func_sub_sp_offset = ind;
    func_vt = sym->type;
    if ((func_vt.t & 0x000f) == 7)
        tcc_error("struct return values are not supported in tcc_27_alt");
    while ((sym = sym->next) != ((void*)0)) {
        type = &sym->type;
        if ((type->t & 0x000f) == 7)
            tcc_error("struct arguments are not supported in tcc_27_alt");
        size = type_size(type, &align);
        size = (size + 3) & ~3;
        param_addr = addr;
        addr += size;
        sym_push(sym->v & ~0x20000000, type,
                 0x0032 | lvalue_type(type->t), param_addr);
    }
    func_ret_sub = 0;
}
static void gfunc_epilog(void)
{
    Elf32_Addr v, saved_ind;
    v = (-loc + 3) & -4;
    o(0xc9);
    if (func_ret_sub == 0) {
        o(0xc3);
    } else {
        o(0xc2);
        g(func_ret_sub);
        g(func_ret_sub >> 8);
    }
    saved_ind = ind;
    ind = func_sub_sp_offset - (9 + 0);
    {
        o(0xe58955);
        o(0xec81);
        gen_le32(v);
    }
    o(0x53 * 0);
    ind = saved_ind;
}
static int gjmp(int t)
{
    return oad(0xe9,t);
}
static void gjmp_addr(int a)
{
    int r;
    r = a - ind - 2;
    if (r == (char)r) {
        g(0xeb);
        g(r);
    } else {
        oad(0xe9, a - ind - 5);
    }
}
static int gtst(int inv, int t)
{
    int v = vtop->r & 0x003f;
    if (nocode_wanted) {
        ;
    } else if (v == 0x0033) {
        g(0x0f);
        t = oad((cv_i(&vtop->c) - 16) ^ inv,t);
    } else if (v == 0x0034 || v == 0x0035) {
        if ((v & 1) == inv) {
            uint32_t n1, n = cv_i(&vtop->c);
            if (n) {
                while ((n1 = read32le(cur_text_section->data + n)))
                    n = n1;
                write32le(cur_text_section->data + n, t);
                t = cv_i(&vtop->c);
            }
        } else {
            t = gjmp(t);
            gsym(cv_i(&vtop->c));
        }
    }
    vtop--;
    return t;
}
static void gen_op8(int op, int opc)
{
    int r, fr, c;
    if ((vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030) {
        vswap();
        r = gv(0x0001);
        vswap();
        c = cv_i(&vtop->c);
        if (c == (char)c) {
            if (c==1 && opc==0 && op != 0xc3) {
                o (0x40 | r);
            } else if (c==1 && opc==5 && op != 0xc5) {
                o (0x48 | r);
            } else {
                o(0x83);
                o(0xc0 | (opc << 3) | r);
                g(c);
            }
        } else {
            o(0x81);
            oad(0xc0 | (opc << 3) | r, c);
        }
    } else {
        gv2(0x0001, 0x0001);
        r = vtop[-1].r;
        fr = vtop[0].r;
        o((opc << 3) | 0x01);
        o(0xc0 + r + fr * 8);
    }
    vtop--;
    if (op >= 0x92 && op <= 0x9f) {
        vtop->r = 0x0033;
        cv_set_i(&vtop->c, op);
    }
}
static void gen_shift_op(int opc)
{
    int r, c;
    opc = 0xc0 | (opc << 3);
    if ((vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030) {
        vswap();
        r = gv(0x0001);
        vswap();
        c = cv_i(&vtop->c) & 0x1f;
        o(0xc1);
        o(opc | r);
        g(c);
    } else {
        gv2(0x0001, 0x0010);
        r = vtop[-1].r;
        o(0xd3);
        o(opc | r);
    }
    vtop--;
}
static void gen_opi(int op)
{
    int r, fr;
    if (op == '+' || op == 0xc3) {
        gen_op8(op, 0);
    } else if (op == '-' || op == 0xc5) {
        gen_op8(op, 5);
    } else if (op == 0xc4) {
        gen_op8(op, 2);
    } else if (op == 0xc6) {
        gen_op8(op, 3);
    } else if (op == '&') {
        gen_op8(op, 4);
    } else if (op == '^') {
        gen_op8(op, 6);
    } else if (op == '|') {
        gen_op8(op, 1);
    } else if (op == '*') {
        gv2(0x0001, 0x0001);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        o(0xaf0f);
        o(0xc0 + fr + r * 8);
    } else if (op == 0x01) {
        gen_shift_op(4);
    } else if (op == 0xc9) {
        gen_shift_op(5);
    } else if (op == 0x02) {
        gen_shift_op(7);
    } else if (op == '/' || op == 0xb0 || op == 0xb2 ||
               op == '%' || op == 0xb1 || op == 0xc2) {
        gv2(0x0004, 0x0010);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(2);
        save_reg_upstack(0, 1);
        if (op == 0xc2) {
            o(0xf7);
            o(0xe0 + fr);
            r = 0;
        } else {
            if (op == 0xb0 || op == 0xb1) {
                o(0xf7d231);
                o(0xf0 + fr);
            } else {
                o(0xf799);
                o(0xf8 + fr);
            }
            if (op == '%' || op == 0xb1)
                r = 2;
            else
                r = 0;
        }
        vtop->r = r;
    } else {
        gen_op8(op, 7);
    }
}
int code_reloc (int reloc_type)
{
    if (reloc_type == 8 || reloc_type == 20 || reloc_type == 1 ||
        reloc_type == 10 || reloc_type == 9 || reloc_type == 3 ||
        reloc_type == 43 || reloc_type == 6 || reloc_type == 5)
        return 0;
    if (reloc_type == 21 || reloc_type == 2 || reloc_type == 4 ||
        reloc_type == 7)
        return 1;
    tcc_error ("Unknown relocation type: %d", reloc_type);
    return -1;
}
int gotplt_entry_type (int reloc_type)
{
    if (reloc_type == 8 || reloc_type == 20 || reloc_type == 6 ||
        reloc_type == 7 || reloc_type == 5)
        return 0;
    if (reloc_type == 1 || reloc_type == 21 || reloc_type == 2)
        return 2;
    if (reloc_type == 10 || reloc_type == 9)
        return 1;
    if (reloc_type == 3 || reloc_type == 43 || reloc_type == 4)
        return 3;
    tcc_error ("Unknown relocation type: %d", reloc_type);
    return -1;
}
static unsigned create_plt_entry(TCCState *s1, unsigned got_offset, SymAttr *attr)
{
    Section *plt = s1->plt;
    uint8_t *p;
    int modrm;
    unsigned plt_offset, relofs;
    modrm = 0x25;
    if (plt->data_offset == 0) {
        p = section_ptr_add(plt, 16);
        p[0] = 0xff;
        p[1] = modrm + 0x10;
        write32le(p + 2, 4);
        p[6] = 0xff;
        p[7] = modrm;
        write32le(p + 8, 4 * 2);
    }
    plt_offset = plt->data_offset;
    relofs = s1->got->reloc ? s1->got->reloc->data_offset : 0;
    p = section_ptr_add(plt, 16);
    p[0] = 0xff;
    p[1] = modrm;
    write32le(p + 2, got_offset);
    p[6] = 0x68;
    write32le(p + 7, relofs);
    p[11] = 0xe9;
    write32le(p + 12, -(plt->data_offset));
    return plt_offset;
}
static void relocate_plt(TCCState *s1)
{
    uint8_t *p, *p_end;
    if (!s1->plt)
      return;
    p = s1->plt->data;
    p_end = p + s1->plt->data_offset;
    if (p < p_end) {
        add32le(p + 2, s1->got->sh_addr);
        add32le(p + 8, s1->got->sh_addr);
        p += 16;
        while (p < p_end) {
            add32le(p + 2, s1->got->sh_addr);
            p += 16;
        }
    }
}
void relocate(TCCState *s1, Elf32_Rel *rel, int type, unsigned char *ptr, Elf32_Addr addr, Elf32_Addr val)
{
    int sym_index;
    sym_index = rel_sym(rel);
    if (type == 1) {
        add32le(ptr, val);
    } else if (type == 2 || type == 4) {
        add32le(ptr, val - addr);
    } else if (type == 6 || type == 7) {
        write32le(ptr, val);
    } else if (type == 10) {
        add32le(ptr, s1->got->sh_addr - addr);
    } else if (type == 9) {
        add32le(ptr, val - s1->got->sh_addr);
    } else if (type == 3 || type == 43) {
        add32le(ptr, sattr_got_offset(sattr_at(s1->sym_attrs, sym_index)));
    } else if (type == 20) {
        tcc_error("16-bit binary output is not supported");
        write16le(ptr, read16le(ptr) + val);
    } else if (type == 21) {
        tcc_error("16-bit binary output is not supported");
        write16le(ptr, read16le(ptr) + val - addr);
    } else if (type == 8 || type == 5) {
    } else {
        fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
            type, (unsigned)addr, ptr, (unsigned)val);
    }
}
static char *pstrcpy(char *buf, int buf_size, char *s)
{
    char *q, *q_end;
    int c;
    if (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        while (q < q_end) {
            c = *s++;
            if (c == '\0')
                break;
            *q++ = c;
        }
        *q = '\0';
    }
    return buf;
}
 char *tcc_basename(char *name)
{
    char *p = strchr(name, 0);
    while (p > name && !(p[-1] == '/'))
        --p;
    return p;
}
 char *tcc_fileextension (char *name)
{
    char *b = tcc_basename(name);
    char *e = strrchr(b, '.');
    return e ? e : strchr(b, 0);
}
 void tcc_free(void *ptr)
{
    free(ptr);
}
 void *tcc_malloc(unsigned int size)
{
    void *ptr;
    ptr = malloc(size);
    if (!ptr && size)
        tcc_error("memory full (malloc)");
    return ptr;
}
 void *tcc_mallocz(unsigned int size)
{
    void *ptr;
    ptr = tcc_malloc(size);
    memset(ptr, 0, size);
    return ptr;
}
 void *tcc_realloc(void *ptr, unsigned int size)
{
    void *ptr1;
    ptr1 = realloc(ptr, size);
    if (!ptr1 && size)
        tcc_error("memory full (realloc)");
    return ptr1;
}
 char *tcc_strdup(char *str)
{
    char *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    return ptr;
}
static void dynarray_add(void *ptab, int *nb_ptr, void *data)
{
    int nb, nb_alloc;
    void **pp;
    nb = *nb_ptr;
    pp = *(void ***)ptab;
    if ((nb & (nb - 1)) == 0) {
        if (!nb)
            nb_alloc = 1;
        else
            nb_alloc = nb * 2;
        pp = tcc_realloc(pp, nb_alloc * sizeof(void *));
        *(void***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}
static void strcat_vprintf(char *buf, int buf_size, char *fmt, va_list ap)
{
    int len;
    len = strlen(buf);
    vsnprintf(buf + len, buf_size - len, fmt, ap);
}
static void strcat_printf(char *buf, int buf_size, char *fmt, ...)
{
    va_list ap;
    ap = ((char *)&(fmt)) + ((sizeof(fmt)+3)&~3);
    strcat_vprintf(buf, buf_size, fmt, ap);
    ;
}
static void error1(TCCState *s1, char *fmt, va_list ap)
{
    char buf[2048];
    BufferedFile *f;
    buf[0] = '\0';
    for (f = file; f && *bf_filename(f) == ':'; f = bf_prev(f))
     ;
    if (f) {
        strcat_printf(buf, sizeof(buf), "%s:%d: ", bf_filename(f), bf_line_num(f));
    } else {
        strcat_printf(buf, sizeof(buf), "tcc: ");
    }
    strcat_printf(buf, sizeof(buf), "error: ");
    strcat_vprintf(buf, sizeof(buf), fmt, ap);
    fflush(stdout);
    fprintf(stderr, "%s\n", buf);
    fflush(stderr);
}
 void tcc_error(char *fmt, ...)
{
    TCCState *s1 = tcc_state;
    va_list ap;
    ap = ((char *)&(fmt)) + ((sizeof(fmt)+3)&~3);
    error1(s1, fmt, ap);
    ;
    exit(1);
}
static void tcc_open_bf(TCCState *s1, char *filename)
{
    BufferedFile *bf;
    bf = tcc_mallocz(1045 + 8192);
    bf_set_buf_ptr(bf, bf_buffer(bf));
    bf_set_buf_end(bf, bf_buffer(bf));
    *bf_buf_end(bf) = '\\';
    pstrcpy(bf_filename(bf), 1024, filename);
    bf_set_line_num(bf, 1);
    bf_set_fd(bf, -1);
    bf_set_prev(bf, file);
    file = bf;
}
static void tcc_close(void)
{
    BufferedFile *bf = file;
    if (bf_fd(bf) > 0) {
        close(bf_fd(bf));
    }
    file = bf_prev(bf);
    tcc_free(bf);
}
static int tcc_open(TCCState *s1, char *filename)
{
    int fd;
    if (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    else
        fd = open(filename, 00 | 0);
    if (fd < 0)
        return -1;
    tcc_open_bf(s1, filename);
    bf_set_fd(file, fd);
    return fd;
}
static int tcc_compile(TCCState *s1)
{
    tccelf_begin_file(s1);
    pvtop = vtop = (__vstack + 1) - 1;
    tccgen_compile(s1);
    sym_pop(&global_stack, ((void*)0), 0);
    sym_pop(&local_stack, ((void*)0), 0);
    tccelf_end_file(s1);
    return 0;
}
static int tcc_add_file_internal(TCCState *s1, char *filename, int flags)
{
    int ret;
    ret = tcc_open(s1, filename);
    if (ret < 0)
        tcc_error("file '%s' not found", filename);
    if (flags & 0x40) {
        Elf32_Ehdr ehdr;
        int fd, obj_type;
        fd = bf_fd(file);
        obj_type = tcc_object_type(fd, &ehdr);
        lseek(fd, 0, 0);
        if (obj_type == 1) {
            ret = tcc_load_object_file(s1, fd, 0);
        } else {
            tcc_error("unrecognized file type");
        }
    } else {
        ret = tcc_compile(s1);
    }
    tcc_close();
    return ret;
}
static void tcc_add_file(TCCState *s, char *filename)
{
    int flags = 0x10;
    char *ext = tcc_fileextension(filename);
    if (ext[0] && strcmp(ext + 1, "c"))
        flags |= 0x40;
    tcc_add_file_internal(s, filename, flags);
}
static void tcc_add_crt(TCCState *s, char *filename)
{
    char *paths[4];
    char buf[1024];
    int i;
    paths[0] = "/usr/lib/i386-linux-gnu";
    paths[1] = "/lib/i386-linux-gnu";
    paths[2] = "/usr/lib32";
    paths[3] = "/lib32";
    for(i = 0; i < 4; i++) {
        snprintf(buf, sizeof(buf), "%s/%s", paths[i], filename);
        if (access(buf, 0) == 0) {
            tcc_add_file_internal(s, buf, 0x40);
            return;
        }
    }
    tcc_error("file '%s' not found", filename);
}
static void tcc_add_needed_dll(TCCState *s, char *soname)
{
    int i;
    DLLReference *dllref;
    for(i = 0; i < s->nb_loaded_dlls; i++) {
        dllref = s->loaded_dlls[i];
        if (!strcmp(soname, dllr_name(dllref)))
            return;
    }
    dllr_set_name(&dllref, soname);
    dllr_set_level(dllref, 0);
    dynarray_add(&s->loaded_dlls, &s->nb_loaded_dlls, dllref);
}
static void tcc_add_library(TCCState *s, char *libraryname)
{
    if (!strcmp(libraryname, "c"))
        tcc_add_needed_dll(s, "libc.so.6");
    else if (!strcmp(libraryname, "m"))
        tcc_add_needed_dll(s, "libm.so.6");
    else if (!strcmp(libraryname, "dl"))
        tcc_add_needed_dll(s, "libdl.so.2");
    else
        tcc_add_needed_dll(s, libraryname);
}
static void args_parser_add_file(TCCState *s, char* filename)
{
    FileSpec *f;
    fs_set_name(&f, filename);
    dynarray_add(&s->files, &s->nb_files, f);
}
static char *take_arg(int argc, char **argv, int *optind,
                            char *r, int prefix_len)
{
    if (r[prefix_len])
        return r + prefix_len;
    if (*optind >= argc)
        tcc_error("argument to '%s' is missing", r);
    return argv[(*optind)++];
}
static void tcc_parse_args(TCCState *s, int argc, char **argv)
{
    char *r, *optarg;
    int optind = 1;
    while (optind < argc) {
        r = argv[optind++];
        if (r[0] != '-' || r[1] == '\0') {
            args_parser_add_file(s, r);
            continue;
        }
        if (!strcmp(r, "-c")) {
            s->output_type = 4;
        } else if (!strcmp(r, "-v")) {
            printf("tcc_27_alt i386 Linux\n");
            exit(0);
        } else if (!strcmp(r, "-nostdlib")) {
            s->nostdlib = 1;
        } else if (!strncmp(r, "-l", 2)) {
            optarg = take_arg(argc, argv, &optind, r, 2);
            tcc_add_library(s, optarg);
        } else if (!strcmp(r, "-o")) {
            optarg = take_arg(argc, argv, &optind, r, 2);
            tcc_free(s->outfile);
            s->outfile = tcc_strdup(optarg);
        } else if (!strncmp(r, "-o", 2)) {
            tcc_free(s->outfile);
            s->outfile = tcc_strdup(r + 2);
        } else {
            tcc_error("unsupported option '%s'", r);
        }
    }
}
static char *default_outputfile(TCCState *s, char *first_file)
{
    char buf[1024];
    char *ext;
    char *name = "a";
    if (first_file && strcmp(first_file, "-"))
        name = tcc_basename(first_file);
    snprintf(buf, sizeof(buf), "%s", name);
    ext = tcc_fileextension(buf);
    if (s->output_type == 4 && *ext)
        strcpy(ext, ".o");
    else
        strcpy(buf, "a.out");
    return tcc_strdup(buf);
}
int main(int argc0, char **argv0)
{
    TCCState *s;
    int i;
    char *first_file;
    s = tcc_mallocz(sizeof(TCCState));
    tcc_state = s;
    tccelf_new(s);
    tccpp_new(s);
    tcc_parse_args(s, argc0, argv0);
    if (s->nb_files == 0)
        tcc_error("no input files\n");
    if (s->output_type == 0)
        s->output_type = 2;
    if (s->output_type == 4 && s->nb_files > 1)
        tcc_error("-c accepts one input file in tcc_27_alt");
    if (s->output_type == 2 && !s->nostdlib) {
        tcc_add_crt(s, "crt1.o");
        tcc_add_crt(s, "crti.o");
    }
    first_file = fs_name(s->files[0]);
    for (i = 0; i < s->nb_files; ++i)
        tcc_add_file(s, fs_name(s->files[i]));
    if (!s->outfile)
        s->outfile = default_outputfile(s, first_file);
    elf_output_file(s, s->outfile);
    return 0;
}
