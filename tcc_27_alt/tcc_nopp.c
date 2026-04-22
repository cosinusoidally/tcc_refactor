typedef unsigned int size_t;
typedef int ssize_t;
typedef int ptrdiff_t;
typedef int intptr_t;
typedef unsigned int uintptr_t;
typedef signed char int8_t;
typedef signed short int int16_t;
typedef signed int int32_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef long int off_t;
typedef int mode_t;
typedef char *va_list;
typedef va_list __gnuc_va_list;
typedef struct FILE FILE;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
void exit(int status);
char *getenv(const char *name);
void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
int atoi(const char *nptr);
long int strtol(const char *nptr, char **endptr, int base);
unsigned long int strtoul(const char *nptr, char **endptr, int base);
int open(const char *file, int oflag, ...);
int close(int fd);
ssize_t read(int fd, void *buf, size_t nbytes);
ssize_t write(int fd, const void *buf, size_t n);
off_t lseek(int fd, off_t offset, int whence);
int unlink(const char *name);
FILE *fopen(const char *filename, const char *modes);
int fclose(FILE *stream);
int fflush(FILE *stream);
int fprintf(FILE *stream, const char *format, ...);
int printf(const char *format, ...);
int sprintf(char *s, const char *format, ...);
int snprintf(char *s, size_t maxlen, const char *format, ...);
int vsnprintf(char *s, size_t maxlen, const char *format, va_list arg);
size_t fwrite(const void *ptr, size_t size, size_t n, FILE *stream);
void *memcpy(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
char *strcat(char *dest, const char *src);
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
char *strstr(const char *haystack, const char *needle);
size_t strlen(const char *s);
int fputs(const char *s, FILE *stream);
int fputc(int c, FILE *stream);
struct TCCState;
typedef struct TCCState TCCState;
TCCState *tcc_new(void);
void tcc_delete(TCCState *s);
int tcc_add_file(TCCState *s, const char *filename);
int tcc_add_library(TCCState *s, const char *libraryname);
int tcc_output_file(TCCState *s, const char *filename);
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Word;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf32_Addr;
typedef uint32_t Elf32_Off;
typedef uint16_t Elf32_Section;
typedef struct {
  unsigned char e_ident[16];
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
typedef struct {
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
typedef struct {
  Elf32_Word st_name;
  Elf32_Addr st_value;
  Elf32_Word st_size;
  unsigned char st_info;
  unsigned char st_other;
  Elf32_Section st_shndx;
} Elf32_Sym;
typedef struct {
  Elf32_Addr r_offset;
  Elf32_Word r_info;
} Elf32_Rel;
typedef struct {
  Elf32_Word p_type;
  Elf32_Off p_offset;
  Elf32_Addr p_vaddr;
  Elf32_Addr p_paddr;
  Elf32_Word p_filesz;
  Elf32_Word p_memsz;
  Elf32_Word p_flags;
  Elf32_Word p_align;
} Elf32_Phdr;
typedef struct {
  Elf32_Sword d_tag;
  union {
    Elf32_Word d_val;
    Elf32_Addr d_ptr;
  } d_un;
} Elf32_Dyn;
enum {
    TREG_EAX = 0,
    TREG_ECX,
    TREG_EDX,
    TREG_EBX,
    TREG_ESP = 4
};
typedef struct TokenSym {
    struct TokenSym *hash_next;
    struct Sym *sym_label;
    struct Sym *sym_struct;
    struct Sym *sym_identifier;
    int tok;
    int len;
    char str[1];
} TokenSym;
typedef struct CString {
    int size;
    void *data;
    int size_allocated;
} CString;
typedef struct CType {
    int t;
    struct Sym *ref;
} CType;
typedef union CValue {
    unsigned int i;
    struct {
        int size;
        const void *data;
    } str;
    int tab[12/4];
} CValue;
typedef struct SValue {
    CType type;
    unsigned short r;
    CValue c;
    struct Sym *sym;
} SValue;
struct FuncAttr {
    unsigned char func_type;
    unsigned short func_args;
};
typedef struct AttributeDef {
    struct FuncAttr f;
} AttributeDef;
typedef struct Sym {
    int v;
    unsigned short r;
    union {
        struct {
            int c;
            union {
                int sym_scope;
                int jnext;
                struct FuncAttr f;
            };
        };
        int enum_val;
        int *d;
    };
    CType type;
    union {
        struct Sym *next;
    };
    struct Sym *prev;
    struct Sym *prev_tok;
} Sym;
typedef struct Section {
    unsigned long data_offset;
    unsigned char *data;
    unsigned long data_allocated;
    int sh_name;
    int sh_num;
    int sh_type;
    int sh_flags;
    int sh_info;
    int sh_addralign;
    int sh_entsize;
    unsigned long sh_size;
    Elf32_Addr sh_addr;
    unsigned long sh_offset;
    int nb_hashed_syms;
    struct Section *link;
    struct Section *reloc;
    struct Section *hash;
    struct Section *prev;
    char name[1];
} Section;
typedef struct DLLReference {
    int level;
    void *handle;
    char name[1];
} DLLReference;
typedef struct BufferedFile {
    uint8_t *buf_ptr;
    uint8_t *buf_end;
    int fd;
    struct BufferedFile *prev;
    int line_num;
    char filename[1024];
    unsigned char buffer[1];
} BufferedFile;
typedef struct TokenString {
    int *str;
    int len;
    int lastlen;
    int allocated_len;
    int save_line_num;
    struct TokenString *prev;
    const int *prev_ptr;
    char alloc;
} TokenString;
typedef struct ExprValue {
    unsigned int v;
    Sym *sym;
    int pcrel;
} ExprValue;
struct sym_attr {
    unsigned got_offset;
    unsigned plt_offset;
    int plt_sym;
    int dyn_index;
};
struct TCCState {
    int nostdlib;
    int output_type;
    int seg_size;
    DLLReference **loaded_dlls;
    int nb_loaded_dlls;
    char **crt_paths;
    int nb_crt_paths;
    Section **sections;
    int nb_sections;
    Section **priv_sections;
    int nb_priv_sections;
    Section *got;
    Section *plt;
    Section *dynsym;
    Section *symtab;
    struct sym_attr *sym_attrs;
    int nb_sym_attrs;
    struct filespec **files;
    int nb_files;
    int filetype;
    char *outfile;
};
struct filespec {
    char type;
    char name[1];
};
enum tcc_token {
    TOK_LAST = 256 - 1
     ,TOK_INT
     ,TOK_VOID
     ,TOK_CHAR
     ,TOK_IF
     ,TOK_ELSE
     ,TOK_WHILE
     ,TOK_BREAK
     ,TOK_RETURN
     ,TOK_FOR
     ,TOK_EXTERN
     ,TOK_STATIC
     ,TOK_UNSIGNED
     ,TOK_GOTO
     ,TOK_CONTINUE
     ,TOK_SWITCH
     ,TOK_CASE
     ,TOK_CONST1
     ,TOK_CONST2
     ,TOK_CONST3
     ,TOK_VOLATILE1
     ,TOK_VOLATILE2
     ,TOK_VOLATILE3
     ,TOK_LONG
     ,TOK_REGISTER
     ,TOK_SIGNED1
     ,TOK_SIGNED2
     ,TOK_SIGNED3
     ,TOK_AUTO
     ,TOK_BOOL
     ,TOK_SHORT
     ,TOK_STRUCT
     ,TOK_UNION
     ,TOK_TYPEDEF
     ,TOK_DEFAULT
     ,TOK_ENUM
     ,TOK_SIZEOF
     ,TOK_memcpy
     ,TOK_memmove
     ,TOK_memset
};
static struct TCCState *tcc_state;
static char *pstrcpy(char *buf, int buf_size, const char *s);
 char *tcc_basename(const char *name);
 char *tcc_fileextension (const char *name);
 void tcc_free(void *ptr);
 void *tcc_malloc(unsigned long size);
 void *tcc_mallocz(unsigned long size);
 void *tcc_realloc(void *ptr, unsigned long size);
 char *tcc_strdup(const char *str);
 void tcc_memcheck(void);
 void tcc_error_noabort(const char *fmt, ...);
  void tcc_error(const char *fmt, ...);
static void dynarray_add(void *ptab, int *nb_ptr, void *data);
static void dynarray_reset(void *pp, int *n);
static void cstr_ccat(CString *cstr, int ch);
static void cstr_cat(CString *cstr, const char *str, int len);
static void cstr_new(CString *cstr);
static void cstr_free(CString *cstr);
static void cstr_reset(CString *cstr);
static void sym_free(Sym *sym);
static Sym *sym_push2(Sym **ps, int v, int t, int c);
static Sym *sym_push(int v, CType *type, int r, int c);
static void sym_pop(Sym **ptop, Sym *b, int keep);
static Sym *struct_find(int v);
static Sym *sym_find(int v);
static Sym *global_identifier_push(int v, int t, int c);
static void tcc_open_bf(TCCState *s1, const char *filename, int initlen);
static int tcc_open(TCCState *s1, const char *filename);
static void tcc_close(void);
static int tcc_add_file_internal(TCCState *s1, const char *filename, int flags);
static int tcc_add_crt(TCCState *s, const char *filename);
 int tcc_add_library_err(TCCState *s, const char *f);
static int tcc_parse_args(TCCState *s, int argc, char **argv);
static struct BufferedFile *file;
static int tok;
static CValue tokc;
static const int *macro_ptr;
static int tok_flags;
static CString tokcstr;
static int total_lines;
static int total_bytes;
static int tok_ident;
static TokenSym **table_ident;
static TokenSym *tok_alloc(const char *str, int len);
static const char *get_tok_str(int v, CValue *cv);
static void begin_macro(TokenString *str, int alloc);
static void end_macro(void);
static int set_idnum(int c, int val);
static void tok_str_new(TokenString *s);
static TokenString *tok_str_alloc(void);
static void tok_str_free(TokenString *s);
static void tok_str_free_str(int *str);
static void tok_str_add(TokenString *s, int t);
static void tok_str_add_tok(TokenString *s);
static Sym *label_find(int v);
static Sym *label_push(Sym **ptop, int v, int flags);
static void label_pop(Sym **ptop, Sym *slast, int keep);
static void next_nomacro(void);
static void next(void);
static void unget_tok(int last_tok);
static void preprocess_start(TCCState *s1);
static void preprocess_end(TCCState *s1);
static void tccpp_new(TCCState *s);
static void tccpp_delete(TCCState *s);
static void skip(int c);
static  void expect(const char *msg);
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
static Sym *local_label_stack;
static Sym *global_label_stack;
static CType char_pointer_type, func_old_type, int_type, size_type;
static SValue __vstack[1+  256], *vtop, *pvtop;
static int rsym, anon_sym, ind, loc;
static int const_wanted;
static int nocode_wanted;
static int global_expr;
static CType func_vt;
static int func_ind;
static const char *funcname;
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
static void tccelf_delete(TCCState *s);
static void tccelf_begin_file(TCCState *s1);
static void tccelf_end_file(TCCState *s1);
static Section *new_section(TCCState *s1, const char *name, int sh_type, int sh_flags);
static void section_realloc(Section *sec, unsigned long new_size);
static size_t section_add(Section *sec, Elf32_Addr size, int align);
static void *section_ptr_add(Section *sec, Elf32_Addr size);
static void section_reserve(Section *sec, unsigned long size);
static Section *new_symtab(TCCState *s1, const char *symtab_name, int sh_type, int sh_flags, const char *strtab_name, const char *hash_name, int hash_sh_flags);
static void put_extern_sym2(Sym *sym, int sh_num, Elf32_Addr value, unsigned long size);
static void put_extern_sym(Sym *sym, Section *section, Elf32_Addr value, unsigned long size);
static void greloc(Section *s, Sym *sym, unsigned long offset, int type);
static void greloca(Section *s, Sym *sym, unsigned long offset, int type, Elf32_Addr addend);
static int put_elf_str(Section *s, const char *sym);
static int put_elf_sym(Section *s, Elf32_Addr value, unsigned long size, int info, int other, int shndx, const char *name);
static int set_elf_sym(Section *s, Elf32_Addr value, unsigned long size, int info, int other, int shndx, const char *name);
static int find_elf_sym(Section *s, const char *name);
static void put_elf_reloc(Section *symtab, Section *s, unsigned long offset, int type, int symbol);
static void put_elf_reloca(Section *symtab, Section *s, unsigned long offset, int type, int symbol, Elf32_Addr addend);
static void resolve_common_syms(TCCState *s1);
static void relocate_syms(TCCState *s1, Section *symtab, int do_resolve);
static void relocate_section(TCCState *s1, Section *s);
static int tcc_object_type(int fd, Elf32_Ehdr *h);
static int tcc_load_object_file(TCCState *s1, int fd, unsigned long file_offset);
static void tcc_add_runtime(TCCState *s1);
static void build_got_entries(TCCState *s1);
static struct sym_attr *get_sym_attr(TCCState *s1, int index, int alloc);
static Elf32_Addr get_elf_sym_addr(TCCState *s, const char *name, int err);
static uint8_t *parse_comment(uint8_t *p);
static int handle_eob(void);
enum gotplt_entry {
    NO_GOTPLT_ENTRY,
    BUILD_GOT_ONLY,
    AUTO_GOTPLT_ENTRY,
    ALWAYS_GOTPLT_ENTRY
};
static int code_reloc (int reloc_type);
static int gotplt_entry_type (int reloc_type);
static unsigned create_plt_entry(TCCState *s1, unsigned got_offset, struct sym_attr *attr);
static void relocate(TCCState *s1, Elf32_Rel *rel, int type, unsigned char *ptr, Elf32_Addr addr, Elf32_Addr val);
static void relocate_plt(TCCState *s1);
static const int reg_classes[4];
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
static void gtst_addr(int inv, int a);
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
static struct TCCState *tcc_state;
static int nb_states;
static int tok_flags;
static struct BufferedFile *file;
static int tok;
static CValue tokc;
static const int *macro_ptr;
static CString tokcstr;
static int total_lines;
static int total_bytes;
static int tok_ident;
static TokenSym **table_ident;
static TokenSym *hash_ident[16384];
static char token_buf[1024 + 1];
static TokenString tokstr_buf;
static unsigned char isidnum_table[256 - (-1)];
static struct TinyAlloc *toksym_alloc;
static struct TinyAlloc *tokstr_alloc;
static struct TinyAlloc *cstr_alloc;
static TokenString *macro_stack;
static const char tcc_keywords[] =
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
     "goto" "\0"
     "continue" "\0"
     "switch" "\0"
     "case" "\0"
     "const" "\0"
     "__const" "\0"
     "__const__" "\0"
     "volatile" "\0"
     "__volatile" "\0"
     "__volatile__" "\0"
     "long" "\0"
     "register" "\0"
     "signed" "\0"
     "__signed" "\0"
     "__signed__" "\0"
     "auto" "\0"
     "_Bool" "\0"
     "short" "\0"
     "struct" "\0"
     "union" "\0"
     "typedef" "\0"
     "default" "\0"
     "enum" "\0"
     "sizeof" "\0"
     "memcpy" "\0"
     "memmove" "\0"
     "memset" "\0"
;
static const unsigned char tok_two_chars[] =
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
static void next_nomacro_spc(void);
static void skip(int c)
{
    if (tok != c)
        tcc_error("'%c' expected (got \"%s\")", c, get_tok_str(tok, &tokc));
    next();
}
static void expect(const char *msg)
{
    tcc_error("%s expected", msg);
}
typedef struct TinyAlloc {
    int dummy;
} TinyAlloc;
static TinyAlloc *tal_new(TinyAlloc **pal, unsigned limit, unsigned size)
{
    (void)limit;
    (void)size;
    if (pal)
        *pal = ((void*)0);
    return ((void*)0);
}
static void tal_delete(TinyAlloc *al)
{
    (void)al;
}
static void tal_free_impl(TinyAlloc *al, void *p )
{
    (void)al;
    if (p)
        tcc_free(p);
}
static void *tal_realloc_impl(TinyAlloc **pal, void *p, unsigned size )
{
    (void)pal;
    return tcc_realloc(p, size);
}
static void cstr_realloc(CString *cstr, int new_size)
{
    int size;
    size = cstr->size_allocated;
    if (size < 8)
        size = 8;
    while (size < new_size)
        size = size * 2;
    cstr->data = tal_realloc_impl(&cstr_alloc, cstr->data, size);
    cstr->size_allocated = size;
}
static void cstr_ccat(CString *cstr, int ch)
{
    int size;
    size = cstr->size + 1;
    if (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    ((unsigned char *)cstr->data)[size - 1] = ch;
    cstr->size = size;
}
static void cstr_cat(CString *cstr, const char *str, int len)
{
    int size;
    if (len <= 0)
        len = strlen(str) + 1 + len;
    size = cstr->size + len;
    if (size > cstr->size_allocated)
        cstr_realloc(cstr, size);
    memmove(((unsigned char *)cstr->data) + cstr->size, str, len);
    cstr->size = size;
}
static void cstr_new(CString *cstr)
{
    memset(cstr, 0, sizeof(CString));
}
static void cstr_free(CString *cstr)
{
    tal_free_impl(cstr_alloc, cstr->data);
    cstr_new(cstr);
}
static void cstr_reset(CString *cstr)
{
    cstr->size = 0;
}
static TokenSym *tok_alloc_new(TokenSym **pts, const char *str, int len)
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
    ts = tal_realloc_impl(&toksym_alloc, 0, sizeof(TokenSym) + len);
    table_ident[i] = ts;
    ts->tok = tok_ident++;
    ts->sym_label = ((void*)0);
    ts->sym_struct = ((void*)0);
    ts->sym_identifier = ((void*)0);
    ts->len = len;
    ts->hash_next = ((void*)0);
    memcpy(ts->str, str, len);
    ts->str[len] = '\0';
    *pts = ts;
    return ts;
}
static TokenSym *tok_alloc(const char *str, int len)
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
        if (ts->len == len && !memcmp(ts->str, str, len))
            return ts;
        pts = &(ts->hash_next);
    }
    return tok_alloc_new(pts, str, len);
}
static const char *get_tok_str(int v, CValue *cv)
{
    static char buf[64];
    char *p = buf;
    switch(v) {
    case 0xb5:
    case 0xb6:
    case 0xce:
    case 0xcf:
        sprintf(p, "%u", cv->i);
        break;
    case 0xb3:
        return "<char>";
        break;
    case 0xbe:
    case 0xbf:
        return (char*)cv->str.data;
    case 0xb9:
        return "<string>";
        break;
    case 0x9c:
        v = '<';
        goto addv;
    case 0x9f:
        v = '>';
        goto addv;
    case 0xc8:
        return strcpy(p, "...");
    case 0x81:
        return strcpy(p, "<<=");
    case 0x82:
        return strcpy(p, ">>=");
    case (-1):
        return strcpy(p, "<eof>");
    default:
        if (v < 256) {
            const unsigned char *q = tok_two_chars;
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
        addv:
            *p++ = v;
            *p = '\0';
        } else if (v < tok_ident) {
            return table_ident[v - 256]->str;
        } else if (v >= 0x10000000) {
            sprintf(p, "L.%u", v - 0x10000000);
        } else {
            return ((void*)0);
        }
        break;
    }
    return buf;
}
static int handle_eob(void)
{
    BufferedFile *bf = file;
    int len;
    if (bf->buf_ptr >= bf->buf_end) {
        if (bf->fd >= 0) {
            len = 8192;
            len = read(bf->fd, bf->buffer, len);
            if (len < 0)
                len = 0;
        } else {
            len = 0;
        }
        total_bytes += len;
        bf->buf_ptr = bf->buffer;
        bf->buf_end = bf->buffer + len;
        *bf->buf_end = '\\';
    }
    if (bf->buf_ptr < bf->buf_end) {
        return bf->buf_ptr[0];
    } else {
        bf->buf_ptr = bf->buf_end;
        return (-1);
    }
}
static int next_src_char(uint8_t **pp)
{
    uint8_t *p = *pp + 1;
    if (p >= file->buf_end) {
        file->buf_ptr = p;
        if (handle_eob() == (-1)) {
            *pp = file->buf_ptr;
            return (-1);
        }
        p = file->buf_ptr;
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
    redo:
        if (c == '\n' || c == (-1)) {
            break;
        } else if (c == '\\') {
            file->buf_ptr = p;
            c = handle_eob();
            p = file->buf_ptr;
            goto redo;
        } else {
            p++;
        }
    }
    return p;
}
static uint8_t *parse_comment(uint8_t *p)
{
    int c;
    p++;
    for(;;) {
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
            file->line_num++;
            p++;
        } else if (c == '*') {
            p++;
            for(;;) {
                c = *p;
                if (c == '*') {
                    p++;
                } else if (c == '/') {
                    goto end_of_comment;
                } else if (c == '\\') {
                    file->buf_ptr = p;
                    c = handle_eob();
                    p = file->buf_ptr;
                    if (c == (-1))
                        tcc_error("unexpected end of file in comment");
                    goto after_star;
                } else {
                    break;
                }
            }
        after_star: ;
        } else {
            file->buf_ptr = p;
            c = handle_eob();
            p = file->buf_ptr;
            if (c == (-1)) {
                tcc_error("unexpected end of file in comment");
            } else if (c == '\\') {
                p++;
            }
        }
    }
 end_of_comment:
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
            file->buf_ptr = p;
            c = handle_eob();
            p = file->buf_ptr;
            if (c == (-1)) {
            unterminated_string:
                tcc_error("missing terminating %c character", sep);
            } else if (c == '\\') {
                c = next_src_char(&p);
                if (c == '\n') {
                    file->line_num++;
                    p++;
                } else if (c == '\r') {
                    c = next_src_char(&p);
                    if (c != '\n')
                        expect("'\n' after '\r'");
                    file->line_num++;
                    p++;
                } else if (c == (-1)) {
                    goto unterminated_string;
                } else {
                    cstr_ccat(str, '\\');
                    cstr_ccat(str, c);
                    p++;
                }
            }
        } else if (c == '\n') {
            file->line_num++;
            goto add_char;
        } else if (c == '\r') {
            c = next_src_char(&p);
            if (c != '\n') {
                cstr_ccat(str, '\r');
            } else {
                file->line_num++;
                goto add_char;
            }
        } else {
        add_char:
            cstr_ccat(str, c);
            p++;
        }
    }
    p++;
    return p;
}
static void tok_str_new(TokenString *s)
{
    s->str = ((void*)0);
    s->len = s->lastlen = 0;
    s->allocated_len = 0;
}
static TokenString *tok_str_alloc(void)
{
    TokenString *str = tal_realloc_impl(&tokstr_alloc, 0, sizeof *str);
    tok_str_new(str);
    return str;
}
static void tok_str_free_str(int *str)
{
    tal_free_impl(tokstr_alloc, str);
}
static void tok_str_free(TokenString *str)
{
    tok_str_free_str(str->str);
    tal_free_impl(tokstr_alloc, str);
}
static int *tok_str_realloc(TokenString *s, int new_size)
{
    int *str, size;
    size = s->allocated_len;
    if (size < 16)
        size = 16;
    while (size < new_size)
        size = size * 2;
    if (size > s->allocated_len) {
        str = tal_realloc_impl(&tokstr_alloc, s->str, size * sizeof(int));
        s->allocated_len = size;
        s->str = str;
    }
    return s->str;
}
static void tok_str_add(TokenString *s, int t)
{
    int len, *str;
    len = s->len;
    str = s->str;
    if (len >= s->allocated_len)
        str = tok_str_realloc(s, len + 1);
    str[len++] = t;
    s->len = len;
}
static void begin_macro(TokenString *str, int alloc)
{
    str->alloc = alloc;
    str->prev = macro_stack;
    str->prev_ptr = macro_ptr;
    str->save_line_num = file->line_num;
    macro_ptr = str->str;
    macro_stack = str;
}
static void end_macro(void)
{
    TokenString *str = macro_stack;
    macro_stack = str->prev;
    macro_ptr = str->prev_ptr;
    file->line_num = str->save_line_num;
    if (str->alloc == 2) {
        str->alloc = 3;
    } else {
        tok_str_free(str);
    }
}
static void tok_str_add2(TokenString *s, int t, CValue *cv)
{
    int len, *str;
    len = s->lastlen = s->len;
    str = s->str;
    if (len + 4 >= s->allocated_len)
        str = tok_str_realloc(s, len + 4 + 1);
    str[len++] = t;
    switch(t) {
    case 0xb5:
    case 0xb6:
    case 0xb3:
    case 0xce:
    case 0xcf:
        str[len++] = cv->tab[0];
        break;
    case 0xbe:
    case 0xbf:
    case 0xb9:
        {
            size_t nb_words =
                1 + (cv->str.size + sizeof(int) - 1) / sizeof(int);
            if (len + nb_words >= s->allocated_len)
                str = tok_str_realloc(s, len + nb_words + 1);
            str[len] = cv->str.size;
            memcpy(&str[len + 1], cv->str.data, cv->str.size);
            len += nb_words;
        }
        break;
    default:
        break;
    }
    s->len = len;
}
static void tok_str_add_tok(TokenString *s)
{
    tok_str_add2(s, tok, &tokc);
}
static void TOK_GET(int *t, const int **pp, CValue *cv)
{
    const int *p = *pp;
    switch(*t = *p++) {
    case 0xce:
    case 0xb5:
    case 0xb3:
        cv->i = *p++;
        break;
    case 0xcf:
    case 0xb6:
        cv->i = (unsigned)*p++;
        break;
    case 0xb9:
    case 0xbe:
    case 0xbf:
        cv->str.size = *p++;
        cv->str.data = p;
        p += (cv->str.size + sizeof(int) - 1) / sizeof(int);
        break;
    default:
        break;
    }
    *pp = p;
}
static Sym *label_find(int v)
{
    v -= 256;
    if ((unsigned)v >= (unsigned)(tok_ident - 256))
        return ((void*)0);
    return table_ident[v]->sym_label;
}
static Sym *label_push(Sym **ptop, int v, int flags)
{
    Sym *s, **ps;
    s = sym_push2(ptop, v, 0, 0);
    s->r = flags;
    ps = &table_ident[v - 256]->sym_label;
    if (ptop == &global_label_stack) {
        while (*ps != ((void*)0))
            ps = &(*ps)->prev_tok;
    }
    s->prev_tok = *ps;
    *ps = s;
    return s;
}
static void label_pop(Sym **ptop, Sym *slast, int keep)
{
    Sym *s, *s1;
    for(s = *ptop; s != slast; s = s1) {
        s1 = s->prev;
        if (s->r == 2) {
        } else if (s->r == 1) {
                tcc_error("label '%s' used but not defined",
                      get_tok_str(s->v, ((void*)0)));
        } else {
            if (s->c) {
                put_extern_sym(s, cur_text_section, s->jnext, 1);
            }
        }
        table_ident[s->v - 256]->sym_label = s->prev_tok;
        if (!keep)
            sym_free(s);
    }
    if (!keep)
        *ptop = slast;
}
static void parse_escape_string(CString *outstr, const uint8_t *buf)
{
    int c, n;
    const uint8_t *p;
    p = buf;
    for(;;) {
        c = *p;
        if (c == '\0')
            break;
        if (c == '\\') {
            p++;
            c = *p;
            switch(c) {
            case '0': case '1': case '2': case '3':
            case '4': case '5': case '6': case '7':
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
                goto add_char_nonext;
            case 'x':
            case 'u':
            case 'U':
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
                goto add_char_nonext;
            case 'a':
                c = '\a';
                break;
            case 'b':
                c = '\b';
                break;
            case 'f':
                c = '\f';
                break;
            case 'n':
                c = '\n';
                break;
            case 'r':
                c = '\r';
                break;
            case 't':
                c = '\t';
                break;
            case 'v':
                c = '\v';
                break;
            case '\'':
            case '\"':
            case '\\':
            case '?':
                break;
            default:
                break;
            }
        }
        p++;
    add_char_nonext:
        cstr_ccat(outstr, c);
    }
    cstr_ccat(outstr, '\0');
}
static void parse_string(const char *s, int len)
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
        n = tokcstr.size - 1;
        if (n < 1)
            tcc_error("empty character constant");
        for (c = i = 0; i < n; ++i) {
            c = (c << 8) | ((char *)tokcstr.data)[i];
        }
        tokc.i = c;
    } else {
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = 0xb9;
    }
}
static void parse_number(const char *p)
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
        const char *p1;
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
        tokc.i = n;
    }
    if (ch)
        tcc_error("invalid number\n");
}
static void next_nomacro1(void)
{
    int t, c, len;
    TokenSym *ts;
    uint8_t *p, *p1;
    unsigned int h;
    p = file->buf_ptr;
 redo_no_start:
    c = *p;
    switch(c) {
    case ' ':
    case '\t':
        p++;
        while (isidnum_table[*p - (-1)] & 1)
            ++p;
        goto redo_no_start;
    case '\f':
    case '\v':
    case '\r':
        p++;
        goto redo_no_start;
    case '\\':
        file->buf_ptr = p;
        c = handle_eob();
        p = file->buf_ptr;
        if (c != (-1)) {
            if (c == '\\')
                p++;
            goto redo_no_start;
        }
        tok = (-1);
        break;
    case '\n':
        file->line_num++;
        p++;
        goto redo_no_start;
    case '#':
        tcc_error("preprocessor directives are not supported in tcc_27_alt");
        break;
    case '$':
        if (!(isidnum_table[c - (-1)] & 2))
            goto parse_simple;
    case 'a': case 'b': case 'c': case 'd':
    case 'e': case 'f': case 'g': case 'h':
    case 'i': case 'j': case 'k': case 'l':
    case 'm': case 'n': case 'o': case 'p':
    case 'q': case 'r': case 's': case 't':
    case 'u': case 'v': case 'w': case 'x':
    case 'y': case 'z':
    case 'A': case 'B': case 'C': case 'D':
    case 'E': case 'F': case 'G': case 'H':
    case 'I': case 'J': case 'K': case 'L':
    case 'M': case 'N': case 'O': case 'P':
    case 'Q': case 'R': case 'S': case 'T':
    case 'U': case 'V': case 'W': case 'X':
    case 'Y': case 'Z':
    case '_':
    parse_ident_fast:
        p1 = p;
        h = 1;
        h = ((h) + ((h) << 5) + ((h) >> 27) + (c));
        while (c = *++p, isidnum_table[c - (-1)] & (2|4))
            h = ((h) + ((h) << 5) + ((h) >> 27) + (c));
        len = p - p1;
        if (c != '\\') {
            TokenSym **pts;
            h &= (16384 - 1);
            pts = &hash_ident[h];
            for(;;) {
                ts = *pts;
                if (!ts)
                    break;
                if (ts->len == len && !memcmp(ts->str, p1, len))
                    goto token_found;
                pts = &(ts->hash_next);
            }
            ts = tok_alloc_new(pts, (char *) p1, len);
        token_found: ;
        } else {
            cstr_reset(&tokcstr);
            cstr_cat(&tokcstr, (char *) p1, len);
            p--;
            c = next_src_char(&p);
            while (isidnum_table[c - (-1)] & (2|4))
            {
                cstr_ccat(&tokcstr, c);
                c = next_src_char(&p);
            }
            ts = tok_alloc(tokcstr.data, tokcstr.size);
        }
        tok = ts->tok;
        break;
    case '0': case '1': case '2': case '3':
    case '4': case '5': case '6': case '7':
    case '8': case '9':
        t = c;
        c = next_src_char(&p);
    parse_num:
        cstr_reset(&tokcstr);
        for(;;) {
            cstr_ccat(&tokcstr, t);
            if (!((isidnum_table[c - (-1)] & (2|4))
                  || c == '.'
                  || ((c == '+' || c == '-')
                      && (((t == 'e' || t == 'E')
                            && !(((char*)tokcstr.data)[0] == '0'
                                && toup(((char*)tokcstr.data)[1]) == 'X'))
                          || t == 'p' || t == 'P'))))
                break;
            t = c;
            c = next_src_char(&p);
        }
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = 0xbe;
        break;
    case '.':
        c = next_src_char(&p);
        if (isnum(c)) {
            t = '.';
            goto parse_num;
        } else if ((isidnum_table['.' - (-1)] & 2)
                   && (isidnum_table[c - (-1)] & (2|4))) {
            *--p = c = '.';
            goto parse_ident_fast;
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
    case '\'':
    case '\"':
        cstr_reset(&tokcstr);
        cstr_ccat(&tokcstr, c);
        p = parse_pp_string(p, c, &tokcstr);
        cstr_ccat(&tokcstr, c);
        cstr_ccat(&tokcstr, '\0');
        tokc.str.size = tokcstr.size;
        tokc.str.data = tokcstr.data;
        tok = 0xbf;
        break;
    case '<':
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
    case '>':
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
    case '&':
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
    case '|':
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
    case '+':
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
    case '-':
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
    case '!': c = next_src_char(&p); if (c == '=') { p++; tok = 0x95; } else { tok = '!'; } break;
    case '=': c = next_src_char(&p); if (c == '=') { p++; tok = 0x94; } else { tok = '='; } break;
    case '*': c = next_src_char(&p); if (c == '=') { p++; tok = 0xaa; } else { tok = '*'; } break;
    case '%': c = next_src_char(&p); if (c == '=') { p++; tok = 0xa5; } else { tok = '%'; } break;
    case '^': c = next_src_char(&p); if (c == '=') { p++; tok = 0xde; } else { tok = '^'; } break;
    case '/':
        c = next_src_char(&p);
        if (c == '*') {
            p = parse_comment(p);
            tok = ' ';
            goto redo_no_start;
        } else if (c == '/') {
            p = parse_line_comment(p);
            tok = ' ';
            goto redo_no_start;
        } else if (c == '=') {
            p++;
            tok = 0xaf;
        } else {
            tok = '/';
        }
        break;
    case '(':
    case ')':
    case '[':
    case ']':
    case '{':
    case '}':
    case ',':
    case ';':
    case ':':
    case '?':
    case '~':
    case '@':
    parse_simple:
        tok = c;
        p++;
        break;
    default:
        if (c >= 0x80 && c <= 0xFF)
	    goto parse_ident_fast;
        tcc_error("unrecognized character \\x%02x", c);
        break;
    }
    tok_flags = 0;
    file->buf_ptr = p;
}
static void next_nomacro_spc(void)
{
    if (macro_ptr) {
        tok = *macro_ptr;
        if (tok)
            TOK_GET(&tok, &macro_ptr, &tokc);
    } else {
        next_nomacro1();
    }
}
static void next_nomacro(void)
{
    next_nomacro_spc();
    while (tok < 256 && (isidnum_table[tok - (-1)] & 1))
        next_nomacro_spc();
}
static void next(void)
{
 redo:
    next_nomacro();
    if (macro_ptr) {
        if (tok == 0xcc || tok == 0xcb) {
            goto redo;
        } else if (tok == 0) {
            end_macro();
            goto redo;
        }
    }
    if (tok == 0xbe) {
        parse_number((char *)tokc.str.data);
    } else if (tok == 0xbf) {
        parse_string((char *)tokc.str.data, tokc.str.size - 1);
    }
}
static void unget_tok(int last_tok)
{
    TokenString *str = tok_str_alloc();
    tok_str_add2(str, tok, &tokc);
    tok_str_add(str, 0);
    begin_macro(str, 1);
    tok = last_tok;
}
static void preprocess_start(TCCState *s1)
{
    pvtop = vtop = (__vstack + 1) - 1;
    set_idnum('$', 0);
    set_idnum('.', 0);
    tok_flags = 0;
}
static void preprocess_end(TCCState *s1)
{
    while (macro_stack)
        end_macro();
    macro_ptr = ((void*)0);
}
static void tccpp_new(TCCState *s)
{
    int i, c;
    const char *p, *r;
    for(i = (-1); i<128; i++)
        set_idnum(i,
            is_space(i) ? 1
            : isid(i) ? 2
            : isnum(i) ? 4
            : 0);
    for(i = 128; i<256; i++)
        set_idnum(i, 2);
    tal_new(&toksym_alloc, 256, (768 * 1024));
    tal_new(&tokstr_alloc, 128, (768 * 1024));
    tal_new(&cstr_alloc, 1024, (256 * 1024));
    memset(hash_ident, 0, 16384 * sizeof(TokenSym *));
    tok_str_new(&tokstr_buf);
    tok_str_realloc(&tokstr_buf, 256);
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
static void tccpp_delete(TCCState *s)
{
    int i, n;
    n = tok_ident - 256;
    for(i = 0; i < n; i++)
        tal_free_impl(toksym_alloc, table_ident[i]);
    tcc_free(table_ident);
    table_ident = ((void*)0);
    cstr_free(&tokcstr);
    tok_str_free_str(tokstr_buf.str);
    tal_delete(toksym_alloc);
    toksym_alloc = ((void*)0);
    tal_delete(tokstr_alloc);
    tokstr_alloc = ((void*)0);
    tal_delete(cstr_alloc);
    cstr_alloc = ((void*)0);
}
static int rsym, anon_sym, ind, loc;
static Sym *sym_free_first;
static void **sym_pools;
static int nb_sym_pools;
static Sym *global_stack;
static Sym *local_stack;
static Sym *global_label_stack;
static Sym *local_label_stack;
static int local_scope;
static int in_sizeof;
static SValue __vstack[1+256], *vtop, *pvtop;
static int const_wanted;
static int nocode_wanted;
static int global_expr;
static CType func_vt;
static int func_ind;
static const char *funcname;
static CType char_pointer_type, func_old_type, int_type, size_type, ptrdiff_type;
static struct switch_t {
    struct case_t {
        int v1, v2;
	int sym;
    } **p; int n;
    int def_sym;
} *cur_switch;
static void gen_cast(CType *type);
static void gen_cast_s(int t);
static CType *pointed_type(CType *type);
static int is_compatible_types(CType *type1, CType *type2);
static int parse_btype(CType *type, AttributeDef *ad);
static CType *type_decl(CType *type, AttributeDef *ad, int *v, int td);
static void init_putv(CType *type, Section *sec, unsigned long c);
static void decl_initializer(CType *type, Section *sec, unsigned long c, int first, int size_only);
static void block(int *bsym, int *csym, int is_expr);
static void decl_initializer_alloc(CType *type, AttributeDef *ad, int r, int has_init, int v, int scope);
static void decl(int l);
static int decl0(int l, int is_for_loop_init, Sym *);
static void expr_eq(void);
static int is_compatible_unqualified_types(CType *type1, CType *type2);
static void vpush(CType *type);
static int gvtst(int inv, int t);
static void skip_or_save_block(TokenString **str);
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
    int_type.t = 3;
    char_pointer_type.t = 1;
    mk_pointer(&char_pointer_type);
    size_type.t = 3 | 0x0010;
    ptrdiff_type.t = 3;
    func_old_type.t = 6;
    func_old_type.ref = sym_push(0x20000000, &int_type, 0, 0);
    func_old_type.ref->f.func_type = 2;
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
    if (sym->type.t & 0x00002000)
        sym_bind = 0;
    else
        sym_bind = 1;
    old_sym_bind = (((unsigned char) (esym->st_info)) >> 4);
    if (sym_bind != old_sym_bind) {
        esym->st_info = (((sym_bind) << 4) + ((((esym->st_info) & 0xf)) & 0xf));
    }
}
static void put_extern_sym2(Sym *sym, int sh_num,
                            Elf32_Addr value, unsigned long size)
{
    int sym_type, sym_bind, info, other, t;
    Elf32_Sym *esym;
    const char *name;
    if (!sym->c) {
        name = get_tok_str(sym->v, ((void*)0));
        t = sym->type.t;
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
        esym->st_value = value;
        esym->st_size = size;
        esym->st_shndx = sh_num;
    }
    update_storage(sym);
}
static void put_extern_sym(Sym *sym, Section *section,
                           Elf32_Addr value, unsigned long size)
{
    int sh_num = section ? section->sh_num : 0;
    put_extern_sym2(sym, sh_num, value, size);
}
static void greloca(Section *s, Sym *sym, unsigned long offset, int type,
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
static void greloc(Section *s, Sym *sym, unsigned long offset, int type)
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
    s->type.t = t;
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
    return table_ident[v]->sym_struct;
}
static Sym *sym_find(int v)
{
    v -= 256;
    if ((unsigned)v >= (unsigned)(tok_ident - 256))
        return ((void*)0);
    return table_ident[v]->sym_identifier;
}
static Sym *sym_push(int v, CType *type, int r, int c)
{
    Sym *s, **ps;
    TokenSym *ts;
    if (local_stack)
        ps = &local_stack;
    else
        ps = &global_stack;
    s = sym_push2(ps, v, type->t, c);
    s->type.ref = type->ref;
    s->r = r;
    if (!(v & 0x20000000) && (v & ~0x40000000) < 0x10000000) {
        ts = table_ident[(v & ~0x40000000) - 256];
        if (v & 0x40000000)
            ps = &ts->sym_struct;
        else
            ps = &ts->sym_identifier;
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
        ps = &table_ident[v - 256]->sym_identifier;
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
                ps = &ts->sym_struct;
            else
                ps = &ts->sym_identifier;
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
    vtop->c = *vc;
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
        gsym(vtop->c.i);
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
    cval.i = v;
    vsetc(&int_type, 0x0030, &cval);
}
static void vpushs(Elf32_Addr v)
{
  CValue cval;
  cval.i = v;
  vsetc(&size_type, 0x0030, &cval);
}
static void vset(CType *type, int r, int v)
{
    CValue cval;
    cval.i = v;
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
    cval.i = 0;
    vsetc(type, 0x0030 | 0x0200, &cval);
    vtop->sym = sym;
}
static Sym *get_sym_ref(CType *type, Section *sec, unsigned long offset, unsigned long size)
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
                sv.c.i = loc;
                store(r, &sv);
                l = loc;
                saved = 1;
            }
            if (p->r & 0x0100) {
                p->r = (p->r & ~(0x003f | 0x8000)) | 0x0031;
            } else {
                p->r = lvalue_type(p->type.t) | 0x0032;
            }
            p->c.i = l;
        }
    }
}
static int get_reg(int rc)
{
    int r;
    SValue *p;
    for(r=0;r<4;r++) {
        if (reg_classes[r] & rc) {
            if (nocode_wanted)
                return r;
            for(p=(__vstack + 1);p<=vtop;p++) {
                if ((p->r & 0x003f) == r)
                    goto notfound;
            }
            return r;
        }
    notfound: ;
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
        sv.c.i = 0;
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
    sv.c.i = 0;
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
        if ((vtop->c.i != 0) != inv)
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
    unsigned int l1 = c1 ? v1->c.i : 0;
    unsigned int l2 = c2 ? v2->c.i : 0;
    int shm = 31;
    if (t1 != 4 && (4 != 8 || t1 != 5))
        l1 = ((uint32_t)l1 |
              (v1->type.t & 0x0010 ? 0 : -(l1 & 0x80000000)));
    if (t2 != 4 && (4 != 8 || t2 != 5))
        l2 = ((uint32_t)l2 |
              (v2->type.t & 0x0010 ? 0 : -(l2 & 0x80000000)));
    if (c1 && c2) {
        switch(op) {
        case '+': l1 += l2; break;
        case '-': l1 -= l2; break;
        case '&': l1 &= l2; break;
        case '^': l1 ^= l2; break;
        case '|': l1 |= l2; break;
        case '*': l1 *= l2; break;
        case 0xb2:
        case '/':
        case '%':
        case 0xb0:
        case 0xb1:
            if (l2 == 0) {
                if (const_wanted)
                    tcc_error("division by zero in constant");
                goto general_case;
            }
            switch(op) {
            default: l1 = gen_opic_sdiv(l1, l2); break;
            case '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); break;
            case 0xb0: l1 = l1 / l2; break;
            case 0xb1: l1 = l1 % l2; break;
            }
            break;
        case 0x01: l1 <<= (l2 & shm); break;
        case 0xc9: l1 >>= (l2 & shm); break;
        case 0x02:
            l1 = (l1 >> 31) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            break;
        case 0x92: l1 = l1 < l2; break;
        case 0x93: l1 = l1 >= l2; break;
        case 0x94: l1 = l1 == l2; break;
        case 0x95: l1 = l1 != l2; break;
        case 0x96: l1 = l1 <= l2; break;
        case 0x97: l1 = l1 > l2; break;
        case 0x9c: l1 = gen_opic_lt(l1, l2); break;
        case 0x9d: l1 = !gen_opic_lt(l1, l2); break;
        case 0x9e: l1 = !gen_opic_lt(l2, l1); break;
        case 0x9f: l1 = gen_opic_lt(l2, l1); break;
        case 0xa0: l1 = l1 && l2; break;
        case 0xa1: l1 = l1 || l2; break;
        default:
            goto general_case;
        }
	if (t1 != 4 && (4 != 8 || t1 != 5))
	    l1 = ((uint32_t)l1 |
		(v1->type.t & 0x0010 ? 0 : -(l1 & 0x80000000)));
        v1->c.i = l1;
        vtop--;
    } else {
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
                vtop->c.i = 0;
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
                vtop->c.i = n;
                if (op == '*')
                    op = 0x01;
                else if (op == 0xb2)
                    op = 0x02;
                else
                    op = 0xc9;
            }
            goto general_case;
        } else if (c2 && (op == '+' || op == '-') &&
                   (((vtop[-1].r & (0x003f | 0x0100 | 0x0200)) == (0x0030 | 0x0200))
                    || (vtop[-1].r & (0x003f | 0x0100)) == 0x0032)) {
            if (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    if ((int)l2 != l2)
	        goto general_case;
            vtop--;
            vtop->c.i = l2;
        } else {
        general_case:
                gen_opi(op);
        }
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
    return ((p->type.t & 0x000f) == 3 && (uint32_t)p->c.i == 0) ||
        ((p->type.t & 0x000f) == 5 && (uint32_t)p->c.i == 0);
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
    } else if (bt1 != 6)
        goto invalid_operands;
    if (bt2 == 5) {
        type2 = pointed_type(type2);
    } else if (bt2 != 6) {
    invalid_operands:
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
        goto invalid_operands;
}
static void gen_op(int op)
{
    int u, t1, t2, bt1, bt2, t;
    CType type1;
redo:
    t1 = vtop[-1].type.t;
    t2 = vtop[0].type.t;
    bt1 = t1 & 0x000f;
    bt2 = t2 & 0x000f;
    if (bt1 == 7 || bt2 == 7) {
        tcc_error("operation on a struct");
    } else if (bt1 == 6 || bt2 == 6) {
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
	goto redo;
    } else if (bt1 == 5 || bt2 == 5) {
        if (op >= 0x92 && op <= 0xa1) {
            check_comparison_pointer_types(vtop - 1, vtop, op);
            t = 3 | 0x0010;
            goto std_op;
        }
        if (bt1 == 5 && bt2 == 5) {
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
        goto std_op;
    } else {
        t = 3;
        if ((t1 & (0x000f | 0x0010 | 0x0080)) == (3 | 0x0010) ||
            (t2 & (0x000f | 0x0010 | 0x0080)) == (3 | 0x0010))
            t |= 0x0010;
    std_op:
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
                vtop->c.i = (uint32_t)vtop->c.i;
            else
                vtop->c.i = ((uint32_t)vtop->c.i |
                              -(vtop->c.i & 0x80000000));
            if (dbt == 11)
                vtop->c.i = (vtop->c.i != 0);
            else {
                uint32_t m = ((dbt & 0x000f) == 1 ? 0xff :
                              (dbt & 0x000f) == 2 ? 0xffff :
                              0xffffffff);
                vtop->c.i &= m;
                if (!(dbt & 0x0010))
                    vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
            }
        } else if (p && dbt == 11) {
            vtop->r = 0x0030;
            vtop->c.i = 1;
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
    } else if (((type->t & (((1 << (6+6)) - 1) << 20 | 0x0080)) == (2 << 20)) && type->ref->c == -1) {
        return -1;
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
    if (s1->f.func_type == 2 || s2->f.func_type == 2)
        return 1;
    if (s1->f.func_type != s2->f.func_type)
        return 0;
    while (s1 != ((void*)0)) {
        if (s2 == ((void*)0))
            return 0;
        if (!is_compatible_unqualified_types(&s1->type, &s2->type))
            return 0;
        s1 = s1->next;
        s2 = s2->next;
    }
    if (s2)
        return 0;
    return 1;
}
static int compare_types(CType *type1, CType *type2, int unqualified)
{
    int bt1, t1, t2;
    t1 = type1->t & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)));
    t2 = type2->t & (~((0x00001000 | 0x00002000 | 0x00004000)|(((1 << (6+6)) - 1) << 20 | 0x0080)));
    if (unqualified) {
        t1 &= ~(0x0100 | 0x0200);
        t2 &= ~(0x0100 | 0x0200);
    }
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
static int is_compatible_types(CType *type1, CType *type2)
{
    return compare_types(type1,type2,0);
}
static int is_compatible_unqualified_types(CType *type1, CType *type2)
{
    return compare_types(type1,type2,1);
}
static void type_to_str(char *buf, int buf_size,
                 CType *type, const char *varstr)
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
    int dbt, sbt;
    st = &vtop->type;
    dbt = dt->t & 0x000f;
    sbt = st->t & 0x000f;
    if (sbt == 0 || dbt == 0) {
	if (sbt == 0 && dbt == 0)
	    ;
	else
    	    tcc_error("cannot cast from/to void");
    }
    switch(dbt) {
    case 5:
        if (is_null_pointer(vtop))
            goto type_ok;
        if (is_integer_btype(sbt)) {
            goto type_ok;
        }
        type1 = pointed_type(dt);
        if (sbt == 6) {
            goto type_ok;
        }
        if (sbt != 5)
            goto error;
        type2 = pointed_type(st);
        if ((type1->t & 0x000f) == 0 ||
            (type2->t & 0x000f) == 0) {
        } else {
            if (!is_compatible_unqualified_types(type1, type2)) {
			if ((type1->t & 0x000f) != (type2->t & 0x000f)
                    || ((type1->t & (((1 << (6+6)) - 1) << 20 | 0x0080)) == (2 << 20)) || ((type2->t & (((1 << (6+6)) - 1) << 20 | 0x0080)) == (2 << 20))
                    )
                ;
		    }
	        }
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        if (sbt == 7) {
            goto case_VT_STRUCT;
        }
        break;
    case 7:
    case_VT_STRUCT:
        if (!is_compatible_unqualified_types(dt, st)) {
        error:
            type_to_str(buf1, sizeof(buf1), st, ((void*)0));
            type_to_str(buf2, sizeof(buf2), dt, ((void*)0));
            tcc_error("cannot cast '%s' to '%s'", buf1, buf2);
        }
        break;
    }
 type_ok:
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
            vpush_global_sym(&func_old_type, TOK_memmove);
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
                sv.c.i = vtop[-1].c.i;
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
        if (type->ref->type.t == (1 << 20 | 7)) {
	    offset = 0;
	    if (size > c)
	        c = size;
	} else {
	    c = (c + align - 1) & -align;
	    offset = c;
	    if (size > 0)
	        c += size;
	}
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
    int v, c, align, flexible;
    Sym *s, *ss, **ps;
    AttributeDef ad, ad1;
    CType type1, btype;
    memset(&ad, 0, sizeof ad);
    next();
    if (tok != '{') {
        v = tok;
        next();
        if (v < 256)
            expect("struct/union/enum name");
        s = struct_find(v);
        if (s && (s->sym_scope == local_scope || tok != '{')) {
            if (u == s->type.t)
                goto do_decl;
            if (u == (2 << 20) && ((s->type.t & (((1 << (6+6)) - 1) << 20 | 0x0080)) == (2 << 20)))
                goto do_decl;
            tcc_error("redefinition of '%s'", get_tok_str(v, ((void*)0)));
        }
    } else {
        v = anon_sym++;
    }
    type1.t = u == (2 << 20) ? u | 3 | 0x0010 : u;
    type1.ref = ((void*)0);
    s = sym_push(v | 0x40000000, &type1, 0, -1);
    s->r = 0;
do_decl:
    type->t = s->type.t;
    type->ref = s;
    if (tok == '{') {
        next();
        if (s->c != -1)
            tcc_error("struct/union/enum already defined");
        ps = &s->next;
        if (u == (2 << 20)) {
            int ll = 0, pl = 0, nl = 0;
	    CType t;
            t.ref = s;
            t.t = 3|0x00002000|(3 << 20);
            for(;;) {
                v = tok;
                if (v <= TOK_SIZEOF)
                    expect("identifier");
                ss = sym_find(v);
                if (ss && !local_stack)
                    tcc_error("redefinition of enumerator '%s'",
                              get_tok_str(v, ((void*)0)));
                next();
                if (tok == '=') {
                    next();
			    ll = expr_const();
                }
                ss = sym_push(v, &t, 0x0030, 0);
                ss->enum_val = ll;
                *ps = ss, ps = &ss->next;
                if (ll < nl)
                    nl = ll;
                if (ll > pl)
                    pl = ll;
                if (tok != ',')
                    break;
                next();
                ll++;
                if (tok == '}')
                    break;
            }
            skip('}');
            t.t = 3;
            if (nl >= 0) {
                t.t |= 0x0010;
            }
            s->type.t = type->t = t.t | (2 << 20);
            s->c = 0;
            for (ss = s->next; ss; ss = ss->next) {
                ll = ss->enum_val;
                if (ll == (int)ll)
                    continue;
                if (t.t & 0x0010) {
                    ss->type.t |= 0x0010;
                    if (ll == (unsigned)ll)
                        continue;
                }
	                ss->type.t = (ss->type.t & ~0x000f) | 3;
            }
        } else {
            c = 0;
            flexible = 0;
            while (tok != '}') {
                if (!parse_btype(&btype, &ad1)) {
		    skip(';');
		    continue;
		}
                while (1) {
		    if (flexible)
		        tcc_error("flexible array member '%s' not at the end of struct",
                              get_tok_str(v, ((void*)0)));
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
			    if ((u == 7) && (type1.t & 0x0040) && c)
			        flexible = 1;
			    else
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
                    if (v != 0 || (type1.t & 0x000f) == 7) {
			c = 1;
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
}
static void sym_to_attr(AttributeDef *ad, Sym *s)
{
    if (s->f.func_type && 0 == ad->f.func_type)
        ad->f.func_type = s->f.func_type;
}
static void parse_btype_qualify(CType *type, int qualifiers)
{
    while (type->t & 0x0040) {
        type->ref = sym_push(0x20000000, &type->ref->type, 0, type->ref->c);
        type = &type->ref->type;
    }
    type->t |= qualifiers;
}
static int parse_btype(CType *type, AttributeDef *ad)
{
    int t, u, bt, st, type_found, typespec_found, g;
    Sym *s;
    CType type1;
    memset(ad, 0, sizeof(AttributeDef));
    type_found = 0;
    typespec_found = 0;
    t = 3;
    bt = st = -1;
    type->ref = ((void*)0);
    while(1) {
        switch(tok) {
        case TOK_CHAR:
            u = 1;
        basic_type:
            next();
        basic_type1:
            if (u == 2) {
                if (st != -1 || (bt != -1 && bt != 3))
                    tmbt: tcc_error("too many basic types");
                st = u;
            } else {
                if (bt != -1 || (st != -1 && u != 3))
                    goto tmbt;
                bt = u;
            }
            if (u != 3)
                t = (t & ~0x000f) | u;
            typespec_found = 1;
            break;
        case TOK_VOID:
            u = 0;
            goto basic_type;
        case TOK_SHORT:
            u = 2;
            goto basic_type;
        case TOK_INT:
            u = 3;
            goto basic_type;
        case TOK_LONG:
            next();
            typespec_found = 1;
            break;
        case TOK_BOOL:
            u = 11;
            goto basic_type;
        case TOK_ENUM:
            struct_decl(&type1, (2 << 20));
        basic_type2:
            u = type1.t;
            type->ref = type1.ref;
            goto basic_type1;
        case TOK_STRUCT:
            struct_decl(&type1, 7);
            goto basic_type2;
        case TOK_UNION:
            struct_decl(&type1, (1 << 20 | 7));
            goto basic_type2;
        case TOK_CONST1:
        case TOK_CONST2:
        case TOK_CONST3:
            type->t = t;
            parse_btype_qualify(type, 0x0100);
            t = type->t;
            next();
            break;
        case TOK_VOLATILE1:
        case TOK_VOLATILE2:
        case TOK_VOLATILE3:
            type->t = t;
            parse_btype_qualify(type, 0x0200);
            t = type->t;
            next();
            break;
        case TOK_SIGNED1:
        case TOK_SIGNED2:
        case TOK_SIGNED3:
            if ((t & (0x0020|0x0010)) == (0x0020|0x0010))
                tcc_error("signed and unsigned modifier");
            t |= 0x0020;
            next();
            typespec_found = 1;
            break;
        case TOK_REGISTER:
        case TOK_AUTO:
            next();
            break;
        case TOK_UNSIGNED:
            if ((t & (0x0020|0x0010)) == 0x0020)
                tcc_error("signed and unsigned modifier");
            t |= 0x0020 | 0x0010;
            next();
            typespec_found = 1;
            break;
        case TOK_EXTERN:
            g = 0x00001000;
            goto storage;
        case TOK_STATIC:
            g = 0x00002000;
            goto storage;
        case TOK_TYPEDEF:
            g = 0x00004000;
            goto storage;
       storage:
            if (t & (0x00001000|0x00002000|0x00004000) & ~g)
                tcc_error("multiple storage classes");
            t |= g;
            next();
            break;
        default:
            if (typespec_found)
                goto the_end;
            s = sym_find(tok);
            if (!s || !(s->type.t & 0x00004000))
                goto the_end;
            t &= ~0x000f;
            u = t & ~(0x0100 | 0x0200), t ^= u;
            type->t = (s->type.t & ~0x00004000) | u;
            type->ref = s->type.ref;
            if (t)
                parse_btype_qualify(type, t);
            t = type->t;
            sym_to_attr(ad, s);
            next();
            typespec_found = 1;
            st = bt = -2;
            break;
        }
        type_found = 1;
    }
the_end:
    bt = t & 0x000f;
    type->t = t;
    return type_found;
}
static void convert_parameter_type(CType *pt)
{
    pt->t &= ~(0x0100 | 0x0200);
    pt->t &= ~0x0040;
    if ((pt->t & 0x000f) == 6) {
        mk_pointer(pt);
    }
}
static int post_type(CType *type, AttributeDef *ad, int storage, int td)
{
    int n, l, arg_size, align;
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
        arg_size = 0;
        if (l) {
            for(;;) {
	                if ((pt.t & 0x000f) == 0 && tok == ')')
	                    break;
	                type_decl(&pt, &ad1, &n, 2 | 1);
	                if ((pt.t & 0x000f) == 0)
	                    tcc_error("parameter declared as void");
	                arg_size += (type_size(&pt, &align) + 4 - 1) / 4;
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
        type->t &= ~0x0100;
        if (tok == '[') {
            next();
            skip(']');
            mk_pointer(type);
        }
        ad->f.func_args = arg_size;
        ad->f.func_type = l;
        s = sym_push(0x20000000, type, 0, 0);
        s->f = ad->f;
        s->next = first;
        type->t = 6;
        type->ref = s;
    } else if (tok == '[') {
        next();
        n = -1;
        if (tok != ']') {
            n = expr_const();
            if (n < 0)
                tcc_error("invalid array size");
        }
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
    int qualifiers, storage;
    storage = type->t & (0x00001000 | 0x00002000 | 0x00004000);
    type->t &= ~(0x00001000 | 0x00002000 | 0x00004000);
    post = ret = type;
    while (tok == '*') {
        qualifiers = 0;
    redo:
        next();
        switch(tok) {
        case TOK_CONST1:
        case TOK_CONST2:
        case TOK_CONST3:
            qualifiers |= 0x0100;
            goto redo;
        case TOK_VOLATILE1:
        case TOK_VOLATILE2:
        case TOK_VOLATILE3:
            qualifiers |= 0x0200;
            goto redo;
        }
        mk_pointer(type);
        type->t |= qualifiers;
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
static void gfunc_param_typed(Sym *func, Sym *arg)
{
    int func_type;
    CType type;
    func_type = func->f.func_type;
    if (func_type == 2 ||
        (func_type == 3 && arg == ((void*)0))) {
        if ((vtop->type.t & 0x000f) == 8) {
            gen_cast_s(9);
        }
    } else if (arg == ((void*)0)) {
        tcc_error("too many arguments to function");
    } else {
        type = arg->type;
        type.t &= ~0x0100;
        gen_assign_cast(&type);
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
    switch(tok) {
    case 0xb5:
    case 0xb3:
	t = 3;
 push_tokc:
	type.t = t;
	vsetc(&type, 0x0030, &tokc);
        next();
        break;
    case 0xb6:
        t = 3 | 0x0010;
        goto push_tokc;
    case 0xce:
        t = 3;
	goto push_tokc;
    case 0xcf:
        t = 3 | 0x0010;
	goto push_tokc;
    case 0xb9:
        t = 1;
        type.t = t;
        mk_pointer(&type);
        type.t |= 0x0040;
        memset(&ad, 0, sizeof(AttributeDef));
        decl_initializer_alloc(&type, &ad, 0x0030, 2, 0, 0);
        break;
    case '(':
        next();
        if (parse_btype(&type, &ad)) {
            type_decl(&type, &ad, &n, 1);
            skip(')');
            if (tok == '{') {
                if (global_expr)
                    r = 0x0030;
                else
                    r = 0x0032;
                if (!(type.t & 0x0040))
                    r |= lvalue_type(type.t);
                memset(&ad, 0, sizeof(AttributeDef));
                decl_initializer_alloc(&type, &ad, r, 1, 0, 0);
            } else {
                if (sizeof_caller) {
                    vpush(&type);
                    return;
                }
                unary();
                gen_cast(&type);
            }
        } else {
            gexpr();
            skip(')');
        }
        break;
    case '*':
        next();
        unary();
        indir();
        break;
    case '&':
        next();
        unary();
        if ((vtop->type.t & 0x000f) != 6 &&
            !(vtop->type.t & 0x0040))
            test_lvalue();
        mk_pointer(&vtop->type);
        gaddrof();
        break;
    case '!':
        next();
        unary();
        if ((vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030) {
            gen_cast_s(11);
            vtop->c.i = !vtop->c.i;
        } else if ((vtop->r & 0x003f) == 0x0033)
            vtop->c.i ^= 1;
        else {
            save_regs(1);
            vseti(0x0034, gvtst(1, 0));
        }
        break;
    case '~':
        next();
        unary();
        vpushi(-1);
        gen_op('^');
        break;
    case '+':
        next();
        unary();
        if ((vtop->type.t & 0x000f) == 5)
            tcc_error("pointer not accepted for unary plus");
        vpushi(0);
        gen_op('+');
        break;
    case TOK_SIZEOF:
        next();
        in_sizeof++;
        expr_type(&type, unary);
        s = vtop[1].sym;
        size = type_size(&type, &align);
        if (size < 0)
            tcc_error("sizeof applied to an incomplete type");
        vpushs(size);
        vtop->type.t |= 0x0010;
        break;
    case 0xa4:
    case 0xa2:
        t = tok;
        next();
        unary();
        inc(0, t);
        break;
    case '-':
        next();
        unary();
        t = vtop->type.t & 0x000f;
        vpushi(0);
	vswap();
	gen_op('-');
        break;
    default:
        t = tok;
        next();
        if (t <= TOK_SIZEOF)
            expect("identifier");
        s = sym_find(t);
        if (!s || (((s)->type.t & (0x000f | (0 | 0x0010))) == (0 | 0x0010))) {
            const char *name = get_tok_str(t, ((void*)0));
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
            vtop->c.i = 0;
        } else if (r == 0x0030 && ((s->type.t & (((1 << (6+6)) - 1) << 20 | 0x0080)) == (3 << 20))) {
            vtop->c.i = s->enum_val;
        }
        break;
    }
    while (1) {
        if (tok == 0xa4 || tok == 0xa2) {
            inc(1, tok);
            next();
        } else if (tok == '.' || tok == 0xc7) {
            int qualifiers;
            if (tok == 0xc7)
                indir();
            qualifiers = vtop->type.t & (0x0100 | 0x0200);
            test_lvalue();
            gaddrof();
            if ((vtop->type.t & 0x000f) != 7)
                expect("struct or union");
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
            vtop->type.t |= qualifiers;
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
            Sym *sa;
            int nb_args;
            if ((vtop->type.t & 0x000f) != 6) {
                if ((vtop->type.t & (0x000f | 0x0040)) == 5) {
                    vtop->type = *pointed_type(&vtop->type);
                    if ((vtop->type.t & 0x000f) != 6)
                        goto error_func;
                } else {
                error_func:
                    expect("function pointer");
                }
            } else {
                vtop->r &= ~0x0100;
            }
            s = vtop->type.ref;
            next();
            sa = s->next;
            nb_args = 0;
            if ((s->type.t & 0x000f) == 7)
                tcc_error("struct return values are not supported in tcc_27_alt");
            ret.type = s->type;
            ret.r = TREG_EAX;
            ret.c.i = 0;
            if (tok != ')') {
                for(;;) {
                    expr_eq();
                    gfunc_param_typed(s, sa);
                    nb_args++;
                    if (sa)
                        sa = sa->next;
                    if (tok == ')')
                        break;
                    skip(',');
                }
            }
            if (sa)
                tcc_error("too few arguments to function");
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
		if (vtop->c.i) {
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
		if (!vtop->c.i) {
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
	c = vtop->c.i;
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
    c = vtop->c.i;
    vpop();
    return c;
}
static int is_label(void)
{
    int last_tok;
    if (tok <= TOK_SIZEOF)
        return 0;
    last_tok = tok;
    next();
    if (tok == ':') {
        return last_tok;
    } else {
        unget_tok(last_tok);
        return 0;
    }
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
static int case_cmp(const void *pa, const void *pb)
{
    int a = (*(struct case_t**) pa)->v1;
    int b = (*(struct case_t**) pb)->v1;
    return a < b ? -1 : a > b;
}
static void gcase(struct case_t **base, int len, int *bsym)
{
    struct case_t *p;
    int e;
    gv(0x0001);
    while (len > 4) {
        p = base[len/2];
        vdup();
        vpushi(p->v2);
        gen_op(0x9e);
        e = gtst(1, 0);
        vdup();
        vpushi(p->v1);
        gen_op(0x9d);
        gtst_addr(0, p->sym);
        gcase(base, len/2, bsym);
        if (cur_switch->def_sym)
            gjmp_addr(cur_switch->def_sym);
        else
            *bsym = gjmp(*bsym);
        gsym(e);
        e = len/2 + 1;
        base += e; len -= e;
    }
    while (len--) {
        p = *base++;
        vdup();
        vpushi(p->v2);
        if (p->v1 == p->v2) {
            gen_op(0x94);
            gtst_addr(0, p->sym);
        } else {
            gen_op(0x9e);
            e = gtst(1, 0);
            vdup();
            vpushi(p->v1);
            gen_op(0x9d);
            gtst_addr(0, p->sym);
            gsym(e);
        }
    }
}
static void block(int *bsym, int *csym, int is_expr)
{
    int a, b, c, d, cond;
    Sym *s;
    if (is_expr) {
        vpushi(0);
        vtop->type.t = 0;
    }
    if (tok == TOK_IF) {
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
        if (c == TOK_ELSE) {
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
    } else if (tok == TOK_WHILE) {
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
        Sym *llabel;
        next();
        s = local_stack;
        llabel = local_label_stack;
        ++local_scope;
        while (tok != '}') {
	    if ((a = is_label()))
		unget_tok(a);
	    else
	        decl(0x0032);
            if (tok != '}') {
                if (is_expr)
                    vpop();
                block(bsym, csym, is_expr);
            }
        }
        label_pop(&local_label_stack, llabel, is_expr);
        --local_scope;
	sym_pop(&local_stack, s, is_expr);
        next();
    } else if (tok == TOK_RETURN) {
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
    } else if (tok == TOK_BREAK) {
        if (!bsym)
            tcc_error("cannot break");
        *bsym = gjmp(*bsym);
        next();
        skip(';');
	nocode_wanted |= 0x20000000;
    } else if (tok == TOK_CONTINUE) {
        if (!csym)
            tcc_error("cannot continue");
        *csym = gjmp(*csym);
        next();
        skip(';');
    } else if (tok == TOK_FOR) {
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
    } else
    if (tok == TOK_SWITCH) {
        struct switch_t *saved, sw;
	int saved_nocode_wanted = nocode_wanted;
	SValue switchval;
        next();
        skip('(');
        gexpr();
        skip(')');
	switchval = *vtop--;
        a = 0;
        b = gjmp(0);
        sw.p = ((void*)0); sw.n = 0; sw.def_sym = 0;
        saved = cur_switch;
        cur_switch = &sw;
        block(&a, csym, 0);
	nocode_wanted = saved_nocode_wanted;
        a = gjmp(a);
        gsym(b);
        qsort(sw.p, sw.n, sizeof(void*), case_cmp);
        for (b = 1; b < sw.n; b++)
            if (sw.p[b - 1]->v2 >= sw.p[b]->v1)
                tcc_error("duplicate case value");
        vpushv(&switchval);
        gcase(sw.p, sw.n, &a);
        vpop();
        if (sw.def_sym)
          gjmp_addr(sw.def_sym);
        dynarray_reset(&sw.p, &sw.n);
        cur_switch = saved;
        gsym(a);
    } else
    if (tok == TOK_CASE) {
        struct case_t *cr = tcc_malloc(sizeof(struct case_t));
        if (!cur_switch)
            expect("switch");
	nocode_wanted &= ~0x20000000;
        next();
        cr->v1 = cr->v2 = expr_const();
        cr->sym = ind;
        dynarray_add(&cur_switch->p, &cur_switch->n, cr);
        skip(':');
        is_expr = 0;
        goto block_after_label;
    } else
    if (tok == TOK_DEFAULT) {
        next();
        skip(':');
        if (!cur_switch)
            expect("switch");
        if (cur_switch->def_sym)
            tcc_error("too many 'default'");
        cur_switch->def_sym = ind;
        is_expr = 0;
        goto block_after_label;
    } else
    if (tok == TOK_GOTO) {
        next();
        if (tok > TOK_SIZEOF) {
            s = label_find(tok);
            if (!s) {
                s = label_push(&global_label_stack, tok, 1);
            } else {
                if (s->r == 2)
                    s->r = 1;
            }
	    if (s->r & 1)
                s->jnext = gjmp(s->jnext);
            else
                gjmp_addr(s->jnext);
            next();
        } else {
            expect("label identifier");
        }
        skip(';');
    } else {
        b = is_label();
        if (b) {
	    next();
            s = label_find(b);
            if (s) {
                if (s->r == 0)
                    tcc_error("duplicate label '%s'", get_tok_str(s->v, ((void*)0)));
                gsym(s->jnext);
                s->r = 0;
            } else {
                s = label_push(&global_label_stack, b, 0);
            }
            s->jnext = ind;
        block_after_label:
	    nocode_wanted &= ~0x20000000;
            if (tok != '}') {
                if (is_expr)
                    vpop();
                block(bsym, csym, is_expr);
            }
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
}
static void skip_or_save_block(TokenString **str)
{
    int braces = tok == '{';
    int level = 0;
    if (str)
      *str = tok_str_alloc();
    while ((level > 0 || (tok != '}' && tok != ',' && tok != ';' && tok != ')'))) {
	int t;
	if (tok == (-1)) {
	     if (str || level > 0)
	       tcc_error("unexpected end of file");
	     else
	       break;
	}
	if (str)
	  tok_str_add_tok(*str);
	t = tok;
	next();
	if (t == '{' || t == '(') {
	    level++;
	} else if (t == '}' || t == ')') {
	    level--;
	    if (level == 0 && braces && t == '}')
	      break;
	}
    }
    if (str) {
	tok_str_add(*str, -1);
	tok_str_add(*str, 0);
    }
}
static void parse_init_elem(int expr_type)
{
    int saved_global_expr;
    switch(expr_type) {
    case 1:
        saved_global_expr = global_expr;
        global_expr = 1;
        expr_const1();
        global_expr = saved_global_expr;
        if (((vtop->r & (0x003f | 0x0100)) != 0x0030
	     && ((vtop->r & (0x0200|0x0100)) != (0x0200|0x0100)
		 || vtop->sym->v < 0x10000000))
            )
            tcc_error("initializer element is not constant");
        break;
    case 2:
        expr_eq();
        break;
    }
}
static void init_putz(Section *sec, unsigned long c, int size)
{
    if (sec) {
    } else {
        vpush_global_sym(&func_old_type, TOK_memset);
        vseti(0x0032, c);
        vpushi(0);
        vpushs(size);
        gfunc_call(3);
    }
}
static int decl_designator(CType *type, Section *sec, unsigned long c,
                           Sym **cur_field, int size_only, int al)
{
    Sym *f;
    int index, align, size;
    unsigned long corig = c;
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
    if (!size_only && c - corig > al)
	init_putz(sec, corig + al, c - corig - al);
    decl_initializer(type, sec, c, 0, size_only);
    size = type_size(type, &align);
    if (c - corig + size > al)
        al = c - corig + size;
    return al;
}
static void init_putv(CType *type, Section *sec, unsigned long c)
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
	    ssec = tcc_state->sections[esym->st_shndx];
	    memmove (ptr, ssec->data + esym->st_value, size);
	    if (ssec->reloc) {
		int num_relocs = ssec->reloc->data_offset / sizeof(*rel);
		rel = (Elf32_Rel*)(ssec->reloc->data + ssec->reloc->data_offset);
		while (num_relocs--) {
		    rel--;
		    if (rel->r_offset >= esym->st_value + size)
		      continue;
		    if (rel->r_offset < esym->st_value)
		      break;
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_value,
				   ((rel->r_info) & 0xff),
				   ((rel->r_info) >> 8),
				   0
				  );
		}
	    }
	} else {
            switch(bt) {
	    case 11:
		vtop->c.i = vtop->c.i != 0;
	    case 1:
		*(char *)ptr |= vtop->c.i;
		break;
	    case 2:
		*(short *)ptr |= vtop->c.i;
		break;
	    case 4:
		*(int *)ptr |= vtop->c.i;
		break;
	    case 5:
		{
		    Elf32_Addr val = vtop->c.i;
		    if (vtop->r & 0x0200)
		      greloc(sec, vtop->sym, c, 1);
		    *(Elf32_Addr *)ptr |= val;
		    break;
		}
	    default:
		{
		    int val = vtop->c.i;
		    if (vtop->r & 0x0200)
		      greloc(sec, vtop->sym, c, 1);
		    *(int *)ptr |= val;
		    break;
		}
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
static void decl_initializer(CType *type, Section *sec, unsigned long c,
                             int first, int size_only)
{
    int len, n, no_oblock, nb, i;
    int size1, align1;
    int have_elem;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;
    have_elem = tok == '}' || tok == ',';
    if (!have_elem && tok != '{' &&
	tok != 0xb9 &&
	!size_only) {
	parse_init_elem(!sec ? 2 : 1);
	have_elem = 1;
    }
    if (have_elem &&
	!(type->t & 0x0040) &&
	is_compatible_unqualified_types(type, &vtop->type)) {
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
                cstr_len = tokc.str.size;
                cstr_len--;
                nb = cstr_len;
                if (n >= 0 && nb > (n - len))
                    nb = n - len;
                if (!size_only) {
                    if (sec && size1 == 1) {
                        if (!(nocode_wanted > 0))
                            memcpy(sec->data + c + len, tokc.str.data, nb);
                    } else {
                        for(i=0;i<nb;i++) {
                            ch = ((unsigned char *)tokc.str.data)[i];
			    vpushi(ch);
                            init_putv(t1, sec, c + (len + i) * size1);
                        }
                    }
                }
                len += nb;
                next();
            }
            if (n < 0 || len < n) {
                if (!size_only) {
		    vpushi(0);
                    init_putv(t1, sec, c + (len * size1));
                }
                len++;
            }
	    len *= size1;
        } else {
	    indexsym.c = 0;
	    f = &indexsym;
          do_init_list:
	    len = 0;
	    while (tok != '}' || have_elem) {
		len = decl_designator(type, sec, c, &f, size_only, len);
		have_elem = 0;
		if (type->t & 0x0040) {
		    ++indexsym.c;
		    if (no_oblock && len >= n*size1)
		        break;
		} else {
		    if (s->type.t == (1 << 20 | 7))
		        f = ((void*)0);
		    else
		        f = f->next;
		    if (no_oblock && f == ((void*)0))
		        break;
		}
		if (tok == '}')
		    break;
		skip(',');
	    }
        }
	if (!size_only && len < n*size1)
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
	goto do_init_list;
    } else if (tok == '{') {
        next();
        decl_initializer(type, sec, c, first, size_only);
        skip('}');
    } else if (size_only) {
        skip_or_save_block(((void*)0));
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
    TokenString *init_str = ((void*)0);
    Section *sec;
    Sym *flexible_array;
    Sym *sym = ((void*)0);
    int saved_nocode_wanted = nocode_wanted;
    if (type->t & 0x00002000)
        nocode_wanted |= (nocode_wanted > 0) ? 0x40000000 : 0x80000000;
    flexible_array = ((void*)0);
    if ((type->t & 0x000f) == 7) {
        Sym *field = type->ref->next;
        if (field) {
            while (field->next)
                field = field->next;
            if (field->type.t & 0x0040 && field->type.ref->c < 0)
                flexible_array = field;
        }
    }
    size = type_size(type, &align);
    if (size < 0 || (flexible_array && has_init)) {
        if (!has_init)
            tcc_error("unknown type size");
        if (has_init == 2) {
	    init_str = tok_str_alloc();
            while (tok == 0xb9) {
                tok_str_add_tok(init_str);
                next();
            }
	    tok_str_add(init_str, -1);
	    tok_str_add(init_str, 0);
        } else {
	    skip_or_save_block(&init_str);
        }
        unget_tok(0);
        begin_macro(init_str, 1);
        next();
        decl_initializer(type, ((void*)0), 0, 1, 1);
        macro_ptr = init_str->str;
        next();
        size = type_size(type, &align);
        if (size < 0)
            tcc_error("unknown type size");
    }
    if (flexible_array &&
	flexible_array->type.ref->c > 0)
        size += flexible_array->type.ref->c
	        * pointed_size(&flexible_array->type);
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
                if (!has_init && sym->c && elfsym(sym)->st_shndx != 0)
                    goto no_alloc;
            }
        }
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
    if (type->t & 0x0400) {
        tcc_error("variable length arrays are not supported in tcc_27_alt");
    } else if (has_init) {
        decl_initializer(type, sec, addr, 1, 0);
        if (flexible_array)
            flexible_array->type.ref->c = -1;
    }
 no_alloc:
    if (init_str) {
        end_macro();
        next();
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
    label_pop(&global_label_stack, ((void*)0), 0);
    local_scope = 0;
    sym_pop(&local_stack, ((void*)0), 0);
    elfsym(sym)->st_size = ind - func_ind;
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
            if (tok > TOK_SIZEOF) {
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
            if (((btype.t & (((1 << (6+6)) - 1) << 20 | 0x0080)) == (2 << 20))) {
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
                    sym->f = ad.f;
                } else {
                    r = 0;
                    if ((type.t & 0x000f) == 6) {
                        type.ref->f = ad.f;
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
static void free_section(Section *s)
{
    tcc_free(s->data);
}
static void tccelf_delete(TCCState *s1)
{
    int i;
    for(i = 1; i < s1->nb_sections; i++)
        free_section(s1->sections[i]);
    dynarray_reset(&s1->sections, &s1->nb_sections);
    for(i = 0; i < s1->nb_priv_sections; i++)
        free_section(s1->priv_sections[i]);
    dynarray_reset(&s1->priv_sections, &s1->nb_priv_sections);
    dynarray_reset(&s1->loaded_dlls, &s1->nb_loaded_dlls);
    tcc_free(s1->sym_attrs);
    symtab_section = ((void*)0);
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
        if (sym->st_shndx == 0
            && (((unsigned char) (sym->st_info)) >> 4) == 0)
            sym->st_info = (((1) << 4) + ((((sym->st_info) & 0xf)) & 0xf));
        tr[i] = set_elf_sym(s, sym->st_value, sym->st_size, sym->st_info,
            sym->st_other, sym->st_shndx, s->link->data + sym->st_name);
    }
    for (i = 1; i < s1->nb_sections; i++) {
        Section *sr = s1->sections[i];
        if (sr->sh_type == 9 && sr->link == s) {
            Elf32_Rel *rel = (Elf32_Rel*)(sr->data + sr->sh_offset);
            Elf32_Rel *rel_end = (Elf32_Rel*)(sr->data + sr->data_offset);
            for (; rel < rel_end; ++rel) {
                int n = ((rel->r_info) >> 8) - first_sym;
                rel->r_info = (((tr[n]) << 8) + ((((rel->r_info) & 0xff)) & 0xff));
            }
        }
    }
    tcc_free(tr);
}
static Section *new_section(TCCState *s1, const char *name, int sh_type, int sh_flags)
{
    Section *sec;
    sec = tcc_mallocz(sizeof(Section) + strlen(name));
    strcpy(sec->name, name);
    sec->sh_type = sh_type;
    sec->sh_flags = sh_flags;
    switch(sh_type) {
    case 5:
    case 9:
    case 4:
    case 11:
    case 2:
    case 6:
        sec->sh_addralign = 4;
        break;
    case 3:
        sec->sh_addralign = 1;
        break;
    default:
        sec->sh_addralign =  4;
        break;
    }
    if (sh_flags & 0x80000000) {
        dynarray_add(&s1->priv_sections, &s1->nb_priv_sections, sec);
    } else {
        sec->sh_num = s1->nb_sections;
        dynarray_add(&s1->sections, &s1->nb_sections, sec);
    }
    return sec;
}
static Section *new_symtab(TCCState *s1,
                           const char *symtab_name, int sh_type, int sh_flags,
                           const char *strtab_name,
                           const char *hash_name, int hash_sh_flags)
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
static void section_realloc(Section *sec, unsigned long new_size)
{
    unsigned long size;
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
static void section_reserve(Section *sec, unsigned long size)
{
    if (size > sec->data_allocated)
        section_realloc(sec, size);
    if (size > sec->data_offset)
        sec->data_offset = size;
}
static int put_elf_str(Section *s, const char *sym)
{
    int offset, len;
    char *ptr;
    len = strlen(sym) + 1;
    offset = s->data_offset;
    ptr = section_ptr_add(s, len);
    memmove(ptr, sym, len);
    return offset;
}
static unsigned long elf_hash(const unsigned char *name)
{
    unsigned long h = 0, g;
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
        if ((((unsigned char) (sym->st_info)) >> 4) != 0) {
            h = elf_hash(strtab + sym->st_name) % nb_buckets;
            *ptr = hash[h];
            hash[h] = sym_index;
        } else {
            *ptr = 0;
        }
        ptr++;
        sym++;
    }
}
static int put_elf_sym(Section *s, Elf32_Addr value, unsigned long size,
    int info, int other, int shndx, const char *name)
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
    sym->st_name = name_offset;
    sym->st_value = value;
    sym->st_size = size;
    sym->st_info = info;
    sym->st_other = other;
    sym->st_shndx = shndx;
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
static int find_elf_sym(Section *s, const char *name)
{
    Elf32_Sym *sym;
    Section *hs;
    int nbuckets, sym_index, h;
    const char *name1;
    hs = s->hash;
    if (!hs)
        return 0;
    nbuckets = ((int *)hs->data)[0];
    h = elf_hash((unsigned char *) name) % nbuckets;
    sym_index = ((int *)hs->data)[2 + h];
    while (sym_index != 0) {
        sym = &((Elf32_Sym *)s->data)[sym_index];
        name1 = (char *) s->link->data + sym->st_name;
        if (!strcmp(name, name1))
            return sym_index;
        sym_index = ((int *)hs->data)[2 + nbuckets + sym_index];
    }
    return 0;
}
static Elf32_Addr get_elf_sym_addr(TCCState *s, const char *name, int err)
{
    int sym_index;
    Elf32_Sym *sym;
    sym_index = find_elf_sym(s->symtab, name);
    sym = &((Elf32_Sym *)s->symtab->data)[sym_index];
    if (!sym_index || sym->st_shndx == 0) {
        if (err)
            tcc_error("%s not defined", name);
        return 0;
    }
    return sym->st_value;
}
static int set_elf_sym(Section *s, Elf32_Addr value, unsigned long size,
                       int info, int other, int shndx, const char *name)
{
    Elf32_Sym *esym;
    int sym_bind, sym_index, sym_type, esym_bind;
    unsigned char sym_vis, esym_vis, new_vis;
    sym_bind = (((unsigned char) (info)) >> 4);
    sym_type = ((info) & 0xf);
    sym_vis = ((other) & 0x03);
    if (sym_bind != 0) {
        sym_index = find_elf_sym(s, name);
        if (!sym_index)
            goto do_def;
        esym = &((Elf32_Sym *)s->data)[sym_index];
        if (esym->st_value == value && esym->st_size == size && esym->st_info == info
            && esym->st_other == other && esym->st_shndx == shndx)
            return sym_index;
        if (esym->st_shndx != 0) {
            esym_bind = (((unsigned char) (esym->st_info)) >> 4);
            esym_vis = ((esym->st_other) & 0x03);
            if (esym_vis == 0) {
                new_vis = sym_vis;
            } else if (sym_vis == 0) {
                new_vis = esym_vis;
            } else {
                new_vis = (esym_vis < sym_vis) ? esym_vis : sym_vis;
            }
            esym->st_other = (esym->st_other & ~((-1) & 0x03))
                             | new_vis;
            other = esym->st_other;
            if (shndx == 0) {
            } else if (sym_bind == 1 && esym_bind == 2) {
                goto do_patch;
            } else if (sym_bind == 2 && esym_bind == 1) {
            } else if (sym_bind == 2 && esym_bind == 2) {
            } else if (sym_vis == 2 || sym_vis == 1) {
            } else if ((esym->st_shndx == 0xfff2
                            || esym->st_shndx == bss_section->sh_num)
                        && (shndx < 0xff00
                            && shndx != bss_section->sh_num)) {
                goto do_patch;
            } else if (shndx == 0xfff2 || shndx == bss_section->sh_num) {
            } else if (s->sh_flags & 0x40000000) {
	    } else if (esym->st_other & 0x04) {
		goto do_patch;
            } else {
                tcc_error_noabort("'%s' defined twice", name);
            }
        } else {
        do_patch:
            esym->st_info = (((sym_bind) << 4) + ((sym_type) & 0xf));
            esym->st_shndx = shndx;
            new_undef_sym = 1;
            esym->st_value = value;
            esym->st_size = size;
            esym->st_other = other;
        }
    } else {
    do_def:
        sym_index = put_elf_sym(s, value, size,
                                (((sym_bind) << 4) + ((sym_type) & 0xf)), other,
                                shndx, name);
    }
    return sym_index;
}
static void put_elf_reloca(Section *symtab, Section *s, unsigned long offset,
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
    rel->r_offset = offset;
    rel->r_info = (((symbol) << 8) + ((type) & 0xff));
    if (addend)
        tcc_error("non-zero addend on REL architecture");
}
static void put_elf_reloc(Section *symtab, Section *s, unsigned long offset,
                           int type, int symbol)
{
    put_elf_reloca(symtab, s, offset, type, symbol, 0);
}
static struct sym_attr *get_sym_attr(TCCState *s1, int index, int alloc)
{
    int n;
    struct sym_attr *tab;
    if (index >= s1->nb_sym_attrs) {
        if (!alloc)
            return s1->sym_attrs;
        n = 1;
        while (index >= n)
            n *= 2;
        tab = tcc_realloc(s1->sym_attrs, n * sizeof(*s1->sym_attrs));
        s1->sym_attrs = tab;
        memset(s1->sym_attrs + s1->nb_sym_attrs, 0,
               (n - s1->nb_sym_attrs) * sizeof(*s1->sym_attrs));
        s1->nb_sym_attrs = n;
    }
    return &s1->sym_attrs[index];
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
        if ((((unsigned char) (p->st_info)) >> 4) == 0) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    if( s->sh_size )
        s->sh_info = q - new_syms;
    p = (Elf32_Sym *)s->data;
    for(i = 0; i < nb_syms; i++) {
        if ((((unsigned char) (p->st_info)) >> 4) != 0) {
            old_to_new_syms[i] = q - new_syms;
            *q++ = *p;
        }
        p++;
    }
    memcpy(s->data, new_syms, nb_syms * sizeof(Elf32_Sym));
    tcc_free(new_syms);
    for(i = 1; i < s1->nb_sections; i++) {
        sr = s1->sections[i];
        if (sr->sh_type == 9 && sr->link == s) {
            for (rel = (Elf32_Rel *) sr->data + 0; rel < (Elf32_Rel *) (sr->data + sr->data_offset); rel++) {
                sym_index = ((rel->r_info) >> 8);
                type = ((rel->r_info) & 0xff);
                sym_index = old_to_new_syms[sym_index];
                rel->r_info = (((sym_index) << 8) + ((type) & 0xff));
            }
        }
    }
    tcc_free(old_to_new_syms);
}
static void relocate_syms(TCCState *s1, Section *symtab, int do_resolve)
{
    Elf32_Sym *sym;
    int sym_bind, sh_num;
    const char *name;
    for (sym = (Elf32_Sym *) symtab->data + 1; sym < (Elf32_Sym *) (symtab->data + symtab->data_offset); sym++) {
        sh_num = sym->st_shndx;
        if (sh_num == 0) {
            name = (char *) s1->symtab->link->data + sym->st_name;
            if (do_resolve) {
            } else if (s1->dynsym && find_elf_sym(s1->dynsym, name))
                goto found;
            if (!strcmp(name, "_fp_hw"))
                goto found;
            sym_bind = (((unsigned char) (sym->st_info)) >> 4);
            if (sym_bind == 2)
                sym->st_value = 0;
            else
                tcc_error_noabort("undefined symbol '%s'", name);
        } else if (sh_num < 0xff00) {
            sym->st_value += s1->sections[sym->st_shndx]->sh_addr;
        }
    found: ;
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
        ptr = s->data + rel->r_offset;
        sym_index = ((rel->r_info) >> 8);
        sym = &((Elf32_Sym *)symtab_section->data)[sym_index];
        type = ((rel->r_info) & 0xff);
        tgt = sym->st_value;
        addr = s->sh_addr + rel->r_offset;
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
        rel->r_offset += s->sh_addr;
}
static void build_got(TCCState *s1)
{
    s1->got = new_section(s1, ".got", 1, (1 << 1) | (1 << 0));
    s1->got->sh_entsize = 4;
    set_elf_sym(symtab_section, 0, 4, (((1) << 4) + ((1) & 0xf)),
                0, s1->got->sh_num, "_GLOBAL_OFFSET_TABLE_");
    section_ptr_add(s1->got, 3 * 4);
}
static struct sym_attr * put_got_entry(TCCState *s1, int dyn_reloc_type,
                                       unsigned long size,
                                       int info, int sym_index)
{
    int need_plt_entry;
    const char *name;
    Elf32_Sym *sym;
    struct sym_attr *attr;
    unsigned got_offset;
    char plt_name[100];
    int len;
    need_plt_entry = (dyn_reloc_type == 7);
    attr = get_sym_attr(s1, sym_index, 1);
    if (need_plt_entry ? attr->plt_offset : attr->got_offset)
        return attr;
    got_offset = s1->got->data_offset;
    section_ptr_add(s1->got, 4);
    sym = &((Elf32_Sym *) symtab_section->data)[sym_index];
    name = (char *) symtab_section->link->data + sym->st_name;
    if (s1->dynsym) {
	if ((((unsigned char) (sym->st_info)) >> 4) == 0) {
	    put_elf_reloc(s1->dynsym, s1->got, got_offset, 8,
			  sym_index);
	} else {
	    if (0 == attr->dyn_index)
                attr->dyn_index = set_elf_sym(s1->dynsym, sym->st_value, size,
					      info, 0, sym->st_shndx, name);
	    put_elf_reloc(s1->dynsym, s1->got, got_offset, dyn_reloc_type,
			  attr->dyn_index);
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
        attr->plt_offset = create_plt_entry(s1, got_offset, attr);
        len = strlen(name);
        if (len > sizeof plt_name - 5)
            len = sizeof plt_name - 5;
        memcpy(plt_name, name, len);
        strcpy(plt_name + len, "@plt");
        attr->plt_sym = put_elf_sym(s1->symtab, attr->plt_offset, sym->st_size,
            (((1) << 4) + ((2) & 0xf)), 0, s1->plt->sh_num, plt_name);
    } else {
        attr->got_offset = got_offset;
    }
    return attr;
}
static void build_got_entries(TCCState *s1)
{
    Section *s;
    Elf32_Rel *rel;
    Elf32_Sym *sym;
    int i, type, gotplt_entry, reloc_type, sym_index;
    struct sym_attr *attr;
    for(i = 1; i < s1->nb_sections; i++) {
        s = s1->sections[i];
        if (s->sh_type != 9)
            continue;
        if (s->link != symtab_section)
            continue;
        for (rel = (Elf32_Rel *) s->data + 0; rel < (Elf32_Rel *) (s->data + s->data_offset); rel++) {
            type = ((rel->r_info) & 0xff);
            gotplt_entry = gotplt_entry_type(type);
            sym_index = ((rel->r_info) >> 8);
            sym = &((Elf32_Sym *)symtab_section->data)[sym_index];
            if (gotplt_entry == NO_GOTPLT_ENTRY) {
                continue;
            }
            if (gotplt_entry == AUTO_GOTPLT_ENTRY) {
                if (sym->st_shndx == 0) {
                    Elf32_Sym *esym;
		    int dynindex;
		    if (s1->dynsym) {
			dynindex = get_sym_attr(s1, sym_index, 0)->dyn_index;
			esym = (Elf32_Sym *)s1->dynsym->data + dynindex;
			if (dynindex
			    && (((esym->st_info) & 0xf) == 2
				|| (((esym->st_info) & 0xf) == 0
				    && ((sym->st_info) & 0xf) == 2)))
			    goto jmp_slot;
		    }
	                } else
	                    continue;
            }
            if (code_reloc(type)) {
            jmp_slot:
                reloc_type = 7;
            } else
                reloc_type = 6;
            if (!s1->got)
                build_got(s1);
            if (gotplt_entry == BUILD_GOT_ONLY)
                continue;
            attr = put_got_entry(s1, reloc_type, sym->st_size, sym->st_info,
                                 sym_index);
            if (reloc_type == 7)
                rel->r_info = (((attr->plt_sym) << 8) + ((type) & 0xff));
        }
    }
}
static void put_dt(Section *dynamic, int dt, Elf32_Addr val)
{
    Elf32_Dyn *dyn;
    dyn = section_ptr_add(dynamic, sizeof(Elf32_Dyn));
    dyn->d_tag = dt;
    dyn->d_un.d_val = val;
}
static void tcc_add_runtime(TCCState *s1)
{
    if (!s1->nostdlib) {
        tcc_add_library_err(s1, "c");
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
        if (sym->st_shndx == 0xfff2) {
	    sym->st_value = section_add(bss_section, sym->st_size,
					sym->st_value);
            sym->st_shndx = bss_section->sh_num;
        }
    }
    tcc_add_linker_symbols(s1);
}
static void fill_local_got_entries(TCCState *s1)
{
    Elf32_Rel *rel;
    for (rel = (Elf32_Rel *) s1->got->reloc->data + 0; rel < (Elf32_Rel *) (s1->got->reloc->data + s1->got->reloc->data_offset); rel++) {
	if (((rel->r_info) & 0xff) == 8) {
	    int sym_index = ((rel->r_info) >> 8);
	    Elf32_Sym *sym = &((Elf32_Sym *) symtab_section->data)[sym_index];
	    struct sym_attr *attr = get_sym_attr(s1, sym_index, 0);
	    unsigned offset = attr->got_offset;
	    if (offset != rel->r_offset - s1->got->sh_addr)
	      tcc_error_noabort("huh");
	    rel->r_info = (((0) << 8) + ((8) & 0xff));
	    write32le(s1->got->data + offset, sym->st_value);
	}
    }
}
static void bind_exe_dynsyms(TCCState *s1)
{
    const char *name;
    int dynindex, index;
    Elf32_Sym *sym;
    for (sym = (Elf32_Sym *) symtab_section->data + 1; sym < (Elf32_Sym *) (symtab_section->data + symtab_section->data_offset); sym++) {
        if (sym->st_shndx == 0) {
            name = (char *) symtab_section->link->data + sym->st_name;
            if ((((unsigned char) (sym->st_info)) >> 4) == 2 ||
                !strcmp(name, "_fp_hw"))
                continue;
            dynindex = put_elf_sym(s1->dynsym, 0, sym->st_size,
                                   (((1) << 4) + ((2) & 0xf)), 0, 0,
                                   name);
            index = sym - (Elf32_Sym *) symtab_section->data;
            get_sym_attr(s1, index, 1)->dyn_index = dynindex;
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
struct dyn_inf {
    Section *dynamic;
    Section *dynstr;
    unsigned long data_offset;
    Elf32_Addr rel_addr;
    Elf32_Addr rel_size;
};
static int layout_sections(TCCState *s1, Elf32_Phdr *phdr, int phnum,
                           Section *interp, Section* strsec,
                           struct dyn_inf *dyninf, int *sec_order)
{
    int i, j, k, sh_order_index, file_offset;
    unsigned long s_align;
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
        dyninf->rel_addr = dyninf->rel_size = 0;
        for(j = 0; j < 2; j++) {
            ph->p_type = 1;
            if (j == 0)
                ph->p_flags = (1 << 2) | (1 << 0);
            else
                ph->p_flags = (1 << 2) | (1 << 1);
            ph->p_align = s_align;
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
                    if (ph->p_offset == 0) {
                        ph->p_offset = file_offset;
                        ph->p_vaddr = addr;
                        ph->p_paddr = ph->p_vaddr;
                    }
                    if (s->sh_type == 9) {
                        if (dyninf->rel_size == 0)
                            dyninf->rel_addr = addr;
                        dyninf->rel_size += s->sh_size;
                    }
                    addr += s->sh_size;
                    if (s->sh_type != 8)
                        file_offset += s->sh_size;
                }
            }
	    if (j == 0) {
		ph->p_offset &= ~(ph->p_align - 1);
		ph->p_vaddr &= ~(ph->p_align - 1);
		ph->p_paddr &= ~(ph->p_align - 1);
	    }
            ph->p_filesz = file_offset - ph->p_offset;
            ph->p_memsz = addr - ph->p_vaddr;
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
        ph->p_type = 6;
        ph->p_offset = sizeof(Elf32_Ehdr);
        ph->p_filesz = ph->p_memsz = phnum * sizeof(Elf32_Phdr);
        ph->p_vaddr = interp->sh_addr - ph->p_filesz;
        ph->p_paddr = ph->p_vaddr;
        ph->p_flags = (1 << 2) | (1 << 0);
        ph->p_align = 4;
        ph++;
        ph->p_type = 3;
        ph->p_offset = interp->sh_offset;
        ph->p_vaddr = interp->sh_addr;
        ph->p_paddr = ph->p_vaddr;
        ph->p_filesz = interp->sh_size;
        ph->p_memsz = interp->sh_size;
        ph->p_flags = (1 << 2);
        ph->p_align = interp->sh_addralign;
    }
    if (dynamic) {
        ph = &phdr[phnum - 1];
        ph->p_type = 2;
        ph->p_offset = dynamic->sh_offset;
        ph->p_vaddr = dynamic->sh_addr;
        ph->p_paddr = ph->p_vaddr;
        ph->p_filesz = dynamic->sh_size;
        ph->p_memsz = dynamic->sh_size;
        ph->p_flags = (1 << 2) | (1 << 1);
        ph->p_align = dynamic->sh_addralign;
    }
}
static void fill_dynamic(TCCState *s1, struct dyn_inf *dyninf)
{
    Section *dynamic = dyninf->dynamic;
    put_dt(dynamic, 4, s1->dynsym->hash->sh_addr);
    put_dt(dynamic, 5, dyninf->dynstr->sh_addr);
    put_dt(dynamic, 6, s1->dynsym->sh_addr);
    put_dt(dynamic, 10, dyninf->dynstr->data_offset);
    put_dt(dynamic, 11, sizeof(Elf32_Sym));
    put_dt(dynamic, 17, dyninf->rel_addr);
    put_dt(dynamic, 18, dyninf->rel_size);
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
        ehdr.e_phentsize = sizeof(Elf32_Phdr);
        ehdr.e_phnum = phnum;
        ehdr.e_phoff = sizeof(Elf32_Ehdr);
    }
    file_offset = (file_offset + 3) & -4;
    ehdr.e_ident[0] = 0x7f;
    ehdr.e_ident[1] = 'E';
    ehdr.e_ident[2] = 'L';
    ehdr.e_ident[3] = 'F';
    ehdr.e_ident[4] = 1;
    ehdr.e_ident[5] = 1;
    ehdr.e_ident[6] = 1;
    switch(file_type) {
    default:
    case 2:
        ehdr.e_type = 2;
        ehdr.e_entry = get_elf_sym_addr(s1, "_start", 1);
        break;
    case 3:
        ehdr.e_type = 3;
        ehdr.e_entry = text_section->sh_addr;
        break;
    case 4:
        ehdr.e_type = 1;
        break;
    }
    ehdr.e_machine = 3;
    ehdr.e_version = 1;
    ehdr.e_shoff = file_offset;
    ehdr.e_ehsize = sizeof(Elf32_Ehdr);
    ehdr.e_shentsize = sizeof(Elf32_Shdr);
    ehdr.e_shnum = shnum;
    ehdr.e_shstrndx = shnum - 1;
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
    while (offset < ehdr.e_shoff) {
        fputc(0, f);
        offset++;
    }
    for(i = 0; i < s1->nb_sections; i++) {
        sh = &shdr;
        memset(sh, 0, sizeof(Elf32_Shdr));
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
        fwrite(sh, 1, sizeof(Elf32_Shdr), f);
    }
}
static int tcc_write_elf_file(TCCState *s1, const char *filename, int phnum,
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
	if (sym->st_shndx != 0 && sym->st_shndx < 0xff00)
	    sym->st_shndx = backmap[sym->st_shndx];
    for (sym = (Elf32_Sym *) s1->dynsym->data + 1; sym < (Elf32_Sym *) (s1->dynsym->data + s1->dynsym->data_offset); sym++)
        if (sym->st_shndx != 0 && sym->st_shndx < 0xff00)
            sym->st_shndx = backmap[sym->st_shndx];
    for (i = 0; i < s1->nb_sections; i++)
	sec_order[i] = i;
    tcc_free(s1->sections);
    s1->sections = snew;
    s1->nb_sections = nnew;
    tcc_free(backmap);
}
static int elf_output_file(TCCState *s1, const char *filename)
{
    int i, ret, phnum, shnum, file_type, file_offset, *sec_order;
    struct dyn_inf dyninf = {0};
    Elf32_Phdr *phdr;
    Elf32_Sym *sym;
    Section *strsec, *interp, *dynamic, *dynstr;
    file_type = s1->output_type;
    ret = -1;
    phdr = ((void*)0);
    sec_order = ((void*)0);
    interp = dynamic = dynstr = ((void*)0);
    if (file_type != 4) {
        tcc_add_runtime(s1);
	resolve_common_syms(s1);
        if (file_type == 2) {
            char *ptr;
            const char *elfint = getenv("LD_SO");
            if (elfint == ((void*)0))
                elfint = "/lib/ld-linux.so.2";
            interp = new_section(s1, ".interp", 1, (1 << 1));
            interp->sh_addralign = 1;
            ptr = section_ptr_add(interp, 1 + strlen(elfint));
            strcpy(ptr, elfint);
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
            if (dllref->level == 0)
                put_dt(dynamic, 1, put_elf_str(dynstr, dllref->name));
        }
        dyninf.dynamic = dynamic;
        dyninf.dynstr = dynstr;
        dyninf.data_offset = dynamic->data_offset;
        fill_dynamic(s1, &dyninf);
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
    file_offset = layout_sections(s1, phdr, phnum, interp, strsec, &dyninf,
                                  sec_order);
    if (file_type != 4) {
        fill_unloadable_phdr(phdr, phnum, interp, dynamic);
        if (dynamic) {
            dynamic->data_offset = dyninf.data_offset;
            fill_dynamic(s1, &dyninf);
            write32le(s1->got->data, dynamic->sh_addr);
            relocate_plt(s1);
            for (sym = (Elf32_Sym *) s1->dynsym->data + 1; sym < (Elf32_Sym *) (s1->dynsym->data + s1->dynsym->data_offset); sym++) {
                if (sym->st_shndx != 0 && sym->st_shndx < 0xff00) {
                    sym->st_value += s1->sections[sym->st_shndx]->sh_addr;
                }
            }
        }
        ret = final_sections_reloc(s1);
        if (ret)
            goto the_end;
	tidy_section_headers(s1, sec_order);
        if (s1->got)
            fill_local_got_entries(s1);
    }
    ret = tcc_write_elf_file(s1, filename, phnum, phdr, file_offset, sec_order);
    s1->nb_sections = shnum;
 the_end:
    tcc_free(sec_order);
    tcc_free(phdr);
    return ret;
}
 int tcc_output_file(TCCState *s, const char *filename)
{
    int ret;
        ret = elf_output_file(s, filename);
    return ret;
}
static void *load_data(int fd, unsigned long file_offset, unsigned long size)
{
    void *data;
    data = tcc_malloc(size);
    lseek(fd, file_offset, 0);
    read(fd, data, size);
    return data;
}
typedef struct SectionMergeInfo {
    Section *s;
    unsigned long offset;
    uint8_t new_section;
} SectionMergeInfo;
static int tcc_object_type(int fd, Elf32_Ehdr *h)
{
    int size = read(fd, h, sizeof *h);
    if (size == sizeof *h && 0 == memcmp(h, "\177ELF", 4)) {
        if (h->e_type == 1)
            return 1;
        if (h->e_type == 3)
            return 2;
    }
    return 0;
}
static int tcc_load_object_file(TCCState *s1,
                                int fd, unsigned long file_offset)
{
    Elf32_Ehdr ehdr;
    Elf32_Shdr *shdr, *sh;
    int size, i, j, offset, offseti, nb_syms, sym_index, ret;
    unsigned char *strsec, *strtab;
    int *old_to_new_syms;
    char *sh_name, *name;
    SectionMergeInfo *sm_table, *sm;
    Elf32_Sym *sym, *symtab;
    Elf32_Rel *rel;
    Section *s;
    lseek(fd, file_offset, 0);
    if (tcc_object_type(fd, &ehdr) != 1)
        goto fail1;
    if (ehdr.e_ident[5] != 1 ||
        ehdr.e_machine != 3) {
    fail1:
        tcc_error_noabort("invalid object file");
        return -1;
    }
    shdr = load_data(fd, file_offset + ehdr.e_shoff,
                     sizeof(Elf32_Shdr) * ehdr.e_shnum);
    sm_table = tcc_mallocz(sizeof(SectionMergeInfo) * ehdr.e_shnum);
    sh = &shdr[ehdr.e_shstrndx];
    strsec = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
    old_to_new_syms = ((void*)0);
    symtab = ((void*)0);
    strtab = ((void*)0);
    nb_syms = 0;
    for(i = 1; i < ehdr.e_shnum; i++) {
        sh = &shdr[i];
        if (sh->sh_type == 2) {
            if (symtab) {
                tcc_error_noabort("object must contain only one symtab");
            fail:
                ret = -1;
                goto the_end;
            }
            nb_syms = sh->sh_size / sizeof(Elf32_Sym);
            symtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
            sm_table[i].s = symtab_section;
            sh = &shdr[sh->sh_link];
            strtab = load_data(fd, file_offset + sh->sh_offset, sh->sh_size);
        }
    }
    for(i = 1; i < ehdr.e_shnum; i++) {
        if (i == ehdr.e_shstrndx)
            continue;
        sh = &shdr[i];
        sh_name = (char *) strsec + sh->sh_name;
        if (sh->sh_type != 1 &&
            sh->sh_type != 9 &&
            sh->sh_type != 8 &&
            sh->sh_type != 16 &&
            sh->sh_type != 14 &&
            sh->sh_type != 15 &&
	    strcmp(sh_name, ".stabstr")
            )
            continue;
        if (sh->sh_addralign < 1)
            sh->sh_addralign = 1;
        for(j = 1; j < s1->nb_sections;j++) {
            s = s1->sections[j];
            if (!strcmp(s->name, sh_name)) {
                goto found;
            }
        }
        s = new_section(s1, sh_name, sh->sh_type, sh->sh_flags & ~(1 << 9));
        s->sh_addralign = sh->sh_addralign;
        s->sh_entsize = sh->sh_entsize;
        sm_table[i].new_section = 1;
    found:
        if (sh->sh_type != s->sh_type) {
            tcc_error_noabort("invalid section type");
            goto fail;
        }
        offset = s->data_offset;
        size = sh->sh_addralign - 1;
        offset = (offset + size) & ~size;
        if (sh->sh_addralign > s->sh_addralign)
            s->sh_addralign = sh->sh_addralign;
        s->data_offset = offset;
        sm_table[i].offset = offset;
        sm_table[i].s = s;
        size = sh->sh_size;
        if (sh->sh_type != 8) {
            unsigned char *ptr;
            lseek(fd, file_offset + sh->sh_offset, 0);
            ptr = section_ptr_add(s, size);
            read(fd, ptr, size);
        } else {
            s->data_offset += size;
        }
    }
    for(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        if (!s || !sm_table[i].new_section)
            continue;
        sh = &shdr[i];
        if (sh->sh_link > 0)
            s->link = sm_table[sh->sh_link].s;
        if (sh->sh_type == 9) {
            s->sh_info = sm_table[sh->sh_info].s->sh_num;
            s1->sections[s->sh_info]->reloc = s;
        }
    }
    sm = sm_table;
    old_to_new_syms = tcc_mallocz(nb_syms * sizeof(int));
    sym = symtab + 1;
    for(i = 1; i < nb_syms; i++, sym++) {
        if (sym->st_shndx != 0 &&
            sym->st_shndx < 0xff00) {
            sm = &sm_table[sym->st_shndx];
            if (!sm->s)
                continue;
            sym->st_shndx = sm->s->sh_num;
            sym->st_value += sm->offset;
        }
        name = (char *) strtab + sym->st_name;
        sym_index = set_elf_sym(symtab_section, sym->st_value, sym->st_size,
                                sym->st_info, sym->st_other,
                                sym->st_shndx, name);
        old_to_new_syms[i] = sym_index;
    }
    for(i = 1; i < ehdr.e_shnum; i++) {
        s = sm_table[i].s;
        if (!s)
            continue;
        sh = &shdr[i];
        offset = sm_table[i].offset;
        switch(s->sh_type) {
        case 9:
            offseti = sm_table[sh->sh_info].offset;
            for (rel = (Elf32_Rel *) s->data + (offset / sizeof(*rel)); rel < (Elf32_Rel *) (s->data + s->data_offset); rel++) {
                int type;
                unsigned sym_index;
                type = ((rel->r_info) & 0xff);
                sym_index = ((rel->r_info) >> 8);
                if (sym_index >= nb_syms)
                    goto invalid_reloc;
                sym_index = old_to_new_syms[sym_index];
                if (!sym_index) {
                invalid_reloc:
                    tcc_error_noabort("Invalid relocation entry [%2d] '%s' @ %.8x",
                        i, strsec + sh->sh_name, rel->r_offset);
                    goto fail;
                }
                rel->r_info = (((sym_index) << 8) + ((type) & 0xff));
                rel->r_offset += offseti;
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
static const int reg_classes[4] = {
      0x0001 | 0x0004,
      0x0001 | 0x0010,
      0x0001 | 0x0020,
      (0x0001 | 0x0040) * 0,
};
static unsigned long func_sub_sp_offset;
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
    fc = sv->c.i;
    ft &= ~(0x0200 | 0x0100);
    v = fr & 0x003f;
    if (fr & 0x0100) {
        if (v == 0x0031) {
            v1.type.t = 3;
            v1.r = 0x0032 | 0x0100;
            v1.c.i = fc;
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
    fc = v->c.i;
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
        oad(0xe8 + is_jmp, vtop->c.i - 4);
    } else {
        r = gv(0x0001);
        o(0xff);
        o(0xd0 + r + (is_jmp << 4));
    }
    if (!is_jmp) {
        int rt;
        rt = vtop->type.ref->type.t;
        switch (rt & 0x000f) {
            case 1:
                if (rt & 0x0010) {
                    o(0xc0b60f);
                }
                else {
                    o(0xc0be0f);
                }
                break;
            case 2:
                if (rt & 0x0010) {
                    o(0xc0b70f);
                }
                else {
                    o(0xc0bf0f);
                }
                break;
            default:
                break;
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
static void gtst_addr(int inv, int a)
{
    int v = vtop->r & 0x003f;
    if (v == 0x0033) {
	inv ^= (vtop--)->c.i;
	a -= ind + 2;
	if (a == (char)a) {
	    g(inv - 32);
	    g(a);
	} else {
	    g(0x0f);
	    oad(inv - 16, a - 4);
	}
    } else if ((v & ~1) == 0x0034) {
	if ((v & 1) != inv) {
	    gjmp_addr(a);
	    gsym(vtop->c.i);
	} else {
	    gsym(vtop->c.i);
	    o(0x05eb);
	    gjmp_addr(a);
	}
	vtop--;
    }
}
static int gtst(int inv, int t)
{
    int v = vtop->r & 0x003f;
    if (nocode_wanted) {
        ;
    } else if (v == 0x0033) {
        g(0x0f);
        t = oad((vtop->c.i - 16) ^ inv,t);
    } else if (v == 0x0034 || v == 0x0035) {
        if ((v & 1) == inv) {
            uint32_t n1, n = vtop->c.i;
            if (n) {
                while ((n1 = read32le(cur_text_section->data + n)))
                    n = n1;
                write32le(cur_text_section->data + n, t);
                t = vtop->c.i;
            }
        } else {
            t = gjmp(t);
            gsym(vtop->c.i);
        }
    }
    vtop--;
    return t;
}
static void gen_opi(int op)
{
    int r, fr, opc, c;
    switch(op) {
    case '+':
    case 0xc3:
        opc = 0;
    gen_op8:
        if ((vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030) {
            vswap();
            r = gv(0x0001);
            vswap();
            c = vtop->c.i;
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
            vtop->c.i = op;
        }
        break;
    case '-':
    case 0xc5:
        opc = 5;
        goto gen_op8;
    case 0xc4:
        opc = 2;
        goto gen_op8;
    case 0xc6:
        opc = 3;
        goto gen_op8;
    case '&':
        opc = 4;
        goto gen_op8;
    case '^':
        opc = 6;
        goto gen_op8;
    case '|':
        opc = 1;
        goto gen_op8;
    case '*':
        gv2(0x0001, 0x0001);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        o(0xaf0f);
        o(0xc0 + fr + r * 8);
        break;
    case 0x01:
        opc = 4;
        goto gen_shift;
    case 0xc9:
        opc = 5;
        goto gen_shift;
    case 0x02:
        opc = 7;
    gen_shift:
        opc = 0xc0 | (opc << 3);
        if ((vtop->r & (0x003f | 0x0100 | 0x0200)) == 0x0030) {
            vswap();
            r = gv(0x0001);
            vswap();
            c = vtop->c.i & 0x1f;
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
        break;
    case '/':
    case 0xb0:
    case 0xb2:
    case '%':
    case 0xb1:
    case 0xc2:
        gv2(0x0004, 0x0010);
        r = vtop[-1].r;
        fr = vtop[0].r;
        vtop--;
        save_reg(TREG_EDX);
        save_reg_upstack(TREG_EAX, 1);
        if (op == 0xc2) {
            o(0xf7);
            o(0xe0 + fr);
            r = TREG_EAX;
        } else {
            if (op == 0xb0 || op == 0xb1) {
                o(0xf7d231);
                o(0xf0 + fr);
            } else {
                o(0xf799);
                o(0xf8 + fr);
            }
            if (op == '%' || op == 0xb1)
                r = TREG_EDX;
            else
                r = TREG_EAX;
        }
        vtop->r = r;
        break;
    default:
        opc = 7;
        goto gen_op8;
    }
}
int code_reloc (int reloc_type)
{
    switch (reloc_type) {
	case 8:
	case 20:
        case 1:
	case 10:
	case 9:
	case 3:
	case 43:
	case 6:
	case 5:
            return 0;
	case 21:
	case 2:
	case 4:
	case 7:
            return 1;
    }
    tcc_error ("Unknown relocation type: %d", reloc_type);
    return -1;
}
int gotplt_entry_type (int reloc_type)
{
    switch (reloc_type) {
	case 8:
	case 20:
	case 6:
	case 7:
	case 5:
            return NO_GOTPLT_ENTRY;
        case 1:
            return AUTO_GOTPLT_ENTRY;
	case 21:
	case 2:
            return AUTO_GOTPLT_ENTRY;
	case 10:
	case 9:
            return BUILD_GOT_ONLY;
	case 3:
	case 43:
	case 4:
            return ALWAYS_GOTPLT_ENTRY;
    }
    tcc_error ("Unknown relocation type: %d", reloc_type);
    return -1;
}
static unsigned create_plt_entry(TCCState *s1, unsigned got_offset, struct sym_attr *attr)
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
    sym_index = ((rel->r_info) >> 8);
    switch (type) {
        case 1:
            add32le(ptr, val);
            return;
        case 2:
            add32le(ptr, val - addr);
            return;
        case 4:
            add32le(ptr, val - addr);
            return;
        case 6:
        case 7:
            write32le(ptr, val);
            return;
        case 10:
            add32le(ptr, s1->got->sh_addr - addr);
            return;
        case 9:
            add32le(ptr, val - s1->got->sh_addr);
            return;
        case 3:
        case 43:
            add32le(ptr, s1->sym_attrs[sym_index].got_offset);
            return;
        case 20:
            tcc_error("16-bit binary output is not supported");
            write16le(ptr, read16le(ptr) + val);
            return;
        case 21:
            tcc_error("16-bit binary output is not supported");
            write16le(ptr, read16le(ptr) + val - addr);
            return;
        case 8:
            return;
        case 5:
            return;
        default:
            fprintf(stderr,"FIXME: handle reloc type %d at %x [%p] to %x\n",
                type, (unsigned)addr, ptr, (unsigned)val);
            return;
    }
}
static char *pstrcpy(char *buf, int buf_size, const char *s)
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
 char *tcc_basename(const char *name)
{
    char *p = strchr(name, 0);
    while (p > name && !(p[-1] == '/'))
        --p;
    return p;
}
 char *tcc_fileextension (const char *name)
{
    char *b = tcc_basename(name);
    char *e = strrchr(b, '.');
    return e ? e : strchr(b, 0);
}
 void tcc_free(void *ptr)
{
    free(ptr);
}
 void *tcc_malloc(unsigned long size)
{
    void *ptr;
    ptr = malloc(size);
    if (!ptr && size)
        tcc_error("memory full (malloc)");
    return ptr;
}
 void *tcc_mallocz(unsigned long size)
{
    void *ptr;
    ptr = tcc_malloc(size);
    memset(ptr, 0, size);
    return ptr;
}
 void *tcc_realloc(void *ptr, unsigned long size)
{
    void *ptr1;
    ptr1 = realloc(ptr, size);
    if (!ptr1 && size)
        tcc_error("memory full (realloc)");
    return ptr1;
}
 char *tcc_strdup(const char *str)
{
    char *ptr;
    ptr = tcc_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    return ptr;
}
 void tcc_memcheck(void)
{
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
static void dynarray_reset(void *pp, int *n)
{
    void **p;
    for (p = *(void***)pp; *n; ++p, --*n)
        if (*p)
            tcc_free(*p);
    tcc_free(*(void**)pp);
    *(void**)pp = ((void*)0);
}
static void tcc_split_path(TCCState *s, void *p_ary, int *p_nb_ary, const char *in)
{
    const char *p;
    for (;;) {
        int c;
        CString str;
        cstr_new(&str);
        for (p = in; c = *p, c != '\0' && c != ":"[0]; ++p) {
            cstr_ccat(&str, c);
        }
        if (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, tcc_strdup(str.data));
        }
        cstr_free(&str);
        if (!*p)
            break;
        in = p+1;
    }
}
static void strcat_vprintf(char *buf, int buf_size, const char *fmt, va_list ap)
{
    int len;
    len = strlen(buf);
    vsnprintf(buf + len, buf_size - len, fmt, ap);
}
static void strcat_printf(char *buf, int buf_size, const char *fmt, ...)
{
    va_list ap;
    ap = ((char *)&(fmt)) + ((sizeof(fmt)+3)&~3);
    strcat_vprintf(buf, buf_size, fmt, ap);
    ;
}
static void error1(TCCState *s1, const char *fmt, va_list ap)
{
    char buf[2048];
    BufferedFile *f;
    buf[0] = '\0';
    for (f = file; f && f->filename[0] == ':'; f = f->prev)
     ;
    if (f) {
        strcat_printf(buf, sizeof(buf), "%s:%d: ",
            f->filename, f->line_num - !!(tok_flags & 0x0001));
    } else {
        strcat_printf(buf, sizeof(buf), "tcc: ");
    }
    strcat_printf(buf, sizeof(buf), "error: ");
    strcat_vprintf(buf, sizeof(buf), fmt, ap);
    fflush(stdout);
    fprintf(stderr, "%s\n", buf);
    fflush(stderr);
}
 void tcc_error_noabort(const char *fmt, ...)
{
    TCCState *s1 = tcc_state;
    va_list ap;
    ap = ((char *)&(fmt)) + ((sizeof(fmt)+3)&~3);
    error1(s1, fmt, ap);
    ;
    exit(1);
}
 void tcc_error(const char *fmt, ...)
{
    TCCState *s1 = tcc_state;
    va_list ap;
    ap = ((char *)&(fmt)) + ((sizeof(fmt)+3)&~3);
    error1(s1, fmt, ap);
    ;
    exit(1);
}
static void tcc_open_bf(TCCState *s1, const char *filename, int initlen)
{
    BufferedFile *bf;
    int buflen = initlen ? initlen : 8192;
    bf = tcc_mallocz(sizeof(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = '\\';
    pstrcpy(bf->filename, sizeof(bf->filename), filename);
    bf->line_num = 1;
    bf->fd = -1;
    bf->prev = file;
    file = bf;
    tok_flags = 0x0001 | 0x0002;
}
static void tcc_close(void)
{
    BufferedFile *bf = file;
    if (bf->fd > 0) {
        close(bf->fd);
        total_lines += bf->line_num;
    }
    file = bf->prev;
    tcc_free(bf);
}
static int tcc_open(TCCState *s1, const char *filename)
{
    int fd;
    if (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    else
        fd = open(filename, 00 | 0);
    if (fd < 0)
        return -1;
    tcc_open_bf(s1, filename, 0);
    file->fd = fd;
    return fd;
}
static int tcc_compile(TCCState *s1)
{
    tccelf_begin_file(s1);
    preprocess_start(s1);
    tccgen_compile(s1);
    preprocess_end(s1);
    sym_pop(&global_stack, ((void*)0), 0);
    sym_pop(&local_stack, ((void*)0), 0);
    tccelf_end_file(s1);
    return 0;
}
static void tcc_cleanup(void)
{
    if (((void*)0) == tcc_state)
        return;
    while (file)
        tcc_close();
    tccpp_delete(tcc_state);
    tcc_state = ((void*)0);
    dynarray_reset(&sym_pools, &nb_sym_pools);
    sym_free_first = ((void*)0);
}
 TCCState *tcc_new(void)
{
    TCCState *s;
    tcc_cleanup();
    s = tcc_mallocz(sizeof(TCCState));
    if (!s)
        return ((void*)0);
    tcc_state = s;
    ++nb_states;
    s->seg_size = 32;
    tccelf_new(s);
    tccpp_new(s);
    return s;
}
 void tcc_delete(TCCState *s1)
{
    tcc_cleanup();
    tccelf_delete(s1);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);
    tcc_free(s1->outfile);
    dynarray_reset(&s1->files, &s1->nb_files);
    tcc_free(s1);
    if (0 == --nb_states)
        tcc_memcheck();
}
static int tcc_add_file_internal(TCCState *s1, const char *filename, int flags)
{
    int ret;
    ret = tcc_open(s1, filename);
    if (ret < 0) {
        if (flags & 0x10)
            tcc_error_noabort("file '%s' not found", filename);
        return ret;
    }
    if (flags & 0x40) {
        Elf32_Ehdr ehdr;
        int fd, obj_type;
        fd = file->fd;
        obj_type = tcc_object_type(fd, &ehdr);
        lseek(fd, 0, 0);
        switch (obj_type) {
        case 1:
            ret = tcc_load_object_file(s1, fd, 0);
            break;
        case 2:
            ret = 0;
            break;
        default:
            tcc_error_noabort("unrecognized file type");
            ret = -1;
            break;
        }
    } else {
        ret = tcc_compile(s1);
    }
    tcc_close();
    return ret;
}
 int tcc_add_file(TCCState *s, const char *filename)
{
    int filetype = s->filetype;
    int flags = 0x10;
    if (filetype == 0) {
        const char *ext = tcc_fileextension(filename);
        if (ext[0]) {
            ext++;
            if (!strcmp(ext, "c") || !strcmp(ext, "i"))
                filetype = 1;
            else
                flags |= 0x40;
        } else {
            filetype = 1;
        }
        s->filetype = filetype;
    }
    return tcc_add_file_internal(s, filename, flags);
}
static int tcc_add_library_internal(TCCState *s, const char *fmt,
    const char *filename, int flags, char **paths, int nb_paths)
{
    char buf[1024];
    int i;
    for(i = 0; i < nb_paths; i++) {
        snprintf(buf, sizeof(buf), fmt, paths[i], filename);
        if (tcc_add_file_internal(s, buf, flags | 0x40) == 0)
            return 0;
    }
    return -1;
}
static int tcc_add_crt(TCCState *s, const char *filename)
{
    if (-1 == tcc_add_library_internal(s, "%s/%s",
        filename, 0, s->crt_paths, s->nb_crt_paths))
        tcc_error_noabort("file '%s' not found", filename);
    return 0;
}
static int tcc_add_needed_dll(TCCState *s, const char *soname)
{
    int i;
    DLLReference *dllref;
    for(i = 0; i < s->nb_loaded_dlls; i++) {
        dllref = s->loaded_dlls[i];
        if (!strcmp(soname, dllref->name))
            return 0;
    }
    dllref = tcc_mallocz(sizeof(DLLReference) + strlen(soname));
    strcpy(dllref->name, soname);
    dynarray_add(&s->loaded_dlls, &s->nb_loaded_dlls, dllref);
    return 0;
}
int tcc_add_library(TCCState *s, const char *libraryname)
{
    if (!strcmp(libraryname, "c"))
        return tcc_add_needed_dll(s, "libc.so.6");
    if (!strcmp(libraryname, "m"))
        return tcc_add_needed_dll(s, "libm.so.6");
    if (!strcmp(libraryname, "dl"))
        return tcc_add_needed_dll(s, "libdl.so.2");
    return tcc_add_needed_dll(s, libraryname);
}
 int tcc_add_library_err(TCCState *s, const char *libname)
{
    int ret = tcc_add_library(s, libname);
    if (ret < 0)
        tcc_error_noabort("library '%s' not found", libname);
    return ret;
}
static void args_parser_add_file(TCCState *s, const char* filename, int filetype)
{
    struct filespec *f = tcc_malloc(sizeof *f + strlen(filename));
    f->type = filetype;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
}
static const char *take_arg(int argc, char **argv, int *optind,
                            const char *r, int prefix_len)
{
    if (r[prefix_len])
        return r + prefix_len;
    if (*optind >= argc)
        tcc_error("argument to '%s' is missing", r);
    return argv[(*optind)++];
}
static int tcc_parse_args(TCCState *s, int argc, char **argv)
{
    const char *r, *optarg;
    int action = 0, optind = 1;
    while (optind < argc) {
        r = argv[optind++];
        if (r[0] != '-' || r[1] == '\0') {
            args_parser_add_file(s, r, s->filetype);
            action = 1;
            continue;
        }
        if (!strcmp(r, "-c")) {
            s->output_type = 4;
        } else if (!strcmp(r, "-v")) {
            printf("tcc_27_alt i386 Linux\n");
            exit(0);
        } else if (!strcmp(r, "-nostdlib")) {
            s->nostdlib = 1;
        } else if (!strcmp(r, "-nostdinc")) {
        } else if (!strncmp(r, "-B", 2)) {
            (void)take_arg(argc, argv, &optind, r, 2);
        } else if (!strncmp(r, "-I", 2)) {
            (void)take_arg(argc, argv, &optind, r, 2);
        } else if (!strncmp(r, "-l", 2)) {
            optarg = take_arg(argc, argv, &optind, r, 2);
            args_parser_add_file(s, optarg, 4);
        } else if (!strcmp(r, "-o")) {
            optarg = take_arg(argc, argv, &optind, r, 2);
            tcc_free(s->outfile);
            s->outfile = tcc_strdup(optarg);
        } else if (!strncmp(r, "-o", 2)) {
            tcc_free(s->outfile);
            s->outfile = tcc_strdup(r + 2);
        } else if (!strcmp(r, "-m32")) {
        } else if (!strcmp(r, "-m64")) {
            tcc_error("tcc_27_alt only supports i386");
        } else {
            tcc_error("unsupported option '%s'", r);
        }
    }
    if (action)
        return 0;
    return 1;
}
static char *default_outputfile(TCCState *s, const char *first_file)
{
    char buf[1024];
    char *ext;
    const char *name = "a";
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
    int ret, opt, n = 0;
    const char *first_file;
redo:
    s = tcc_new();
    opt = tcc_parse_args(s, argc0, argv0);
    if (n == 0) {
        if (opt == 1)
            tcc_error("no input files\n");
        n = s->nb_files;
        if (n == 0)
            tcc_error("no input files\n");
        if (s->output_type == 4) {
            if (n > 1 && s->outfile)
                tcc_error("cannot specify output file with -c many files");
        }
    }
    if (s->output_type == 0)
        s->output_type = 2;
    tcc_split_path(s, &s->crt_paths, &s->nb_crt_paths, "/usr/lib/i386-linux-gnu:/lib/i386-linux-gnu:/usr/lib32:/lib32");
    if (s->output_type == 2 && !s->nostdlib) {
        tcc_add_crt(s, "crt1.o");
        tcc_add_crt(s, "crti.o");
    }
    for (first_file = ((void*)0), ret = 0;;) {
        struct filespec *f = s->files[s->nb_files - n];
        s->filetype = f->type;
        if (f->type == 4) {
            if (tcc_add_library_err(s, f->name) < 0)
                ret = 1;
        } else {
            if (!first_file)
                first_file = f->name;
            if (tcc_add_file(s, f->name) < 0)
                ret = 1;
        }
        s->filetype = 0;
        if (--n == 0 || ret
            || s->output_type == 4)
            break;
    }
    if (0 == ret) {
        if (!s->outfile)
            s->outfile = default_outputfile(s, first_file);
        if (tcc_output_file(s, s->outfile))
            ret = 1;
    }
    tcc_delete(s);
    if (ret == 0 && n)
        goto redo;
    return ret;
}
