/*
 * Host representation primitives used by cc2's TCC integration.
 *
 * Selection and compiler policy live in cc2.c. This file contains only
 * operations unavailable in the operator-free scalar dialect.
 */

CType func_vt; /* C storage for cc2's current function return type. */

/* Typed storage retained at the boundary while cc2 owns all preprocessor
   algorithms and initialization. */
ST_DATA int tok_flags;
ST_DATA int parse_flags;
ST_DATA struct BufferedFile *file;
int tok;
CValue tokc;
ST_DATA CString tokcstr;
ST_DATA int total_lines;

static TokenSym *hash_ident[TOK_HASH_SIZE];
static CString cstr_buf;
static TokenString tokstr_buf;
static unsigned char isidnum_table[256 - CH_EOF];
static int pp_debug_tok, pp_debug_symv;
static int pp_once;

static const char tcc_keywords[] =
#define DEF(id, str) str "\0"
#include "tcctok.h"
#undef DEF
;

/* Token spellings use TCC's established compact three-byte records. */
static const unsigned char tok_two_chars[] = {
    '<','=', TOK_LE,
    '>','=', TOK_GE,
    '!','=', TOK_NE,
    '&','&', TOK_LAND,
    '|','|', TOK_LOR,
    '+','+', TOK_INC,
    '-','-', TOK_DEC,
    '=','=', TOK_EQ,
    '<','<', TOK_SHL,
    '>','>', TOK_SAR,
    '+','=', TOK_A_ADD,
    '-','=', TOK_A_SUB,
    '*','=', TOK_A_MUL,
    '/','=', TOK_A_DIV,
    '%','=', TOK_A_MOD,
    '&','=', TOK_A_AND,
    '^','=', TOK_A_XOR,
    '|','=', TOK_A_OR,
    '-','>', TOK_ARROW,
    '.','.', TOK_TWODOTS,
    '#','#', TOK_TWOSHARPS,
    0
};

extern int case_cmp(const void *first, const void *second);

int cc2_dlsym_default(const char *name)
{
    return (int)dlsym(RTLD_DEFAULT, name);
}

/* The cc2 dialect cannot pass its comparator as a C function pointer. */
void case_sort(void **base, int count)
{
    qsort(base, count, sizeof(void *), case_cmp);
}

/* Translate TCC's compact symbol-table index into its ELF record address. */
ElfSym *elfsym(Sym *s)
{
    if (!s || !s->c)
        return NULL;
    return &((ElfSym *)symtab_section->data)[s->c];
}

ST_FUNC int ieee_finite(double d)
{
    int p[4];
    memcpy(p, &d, sizeof(double));
    return ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

/* compiling intel long double natively */
#if (defined __i386__ || defined __x86_64__) \
    && (defined TCC_TARGET_I386 || defined TCC_TARGET_X86_64)
# define TCC_IS_NATIVE_387
#endif

ST_FUNC void vpush64(int ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = NULL;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
}

/* cc2 represents i386 constants as explicit little-endian 32-bit words. */
void vpush64_words(int type, unsigned int low_word, unsigned int high_word)
{
    unsigned long long value;

    value = low_word | ((unsigned long long)high_word << 32);
    vpush64(type, value);
}

/* cc2 selects unary negation; this primitive writes the target CValue union. */
void neg_zero(int basic_type)
{
    vpush(&vtop->type);
    if (basic_type == VT_FLOAT) {
        vtop->c.f = -1.0 * 0.0;
    } else if (basic_type == VT_DOUBLE) {
        vtop->c.d = -1.0 * 0.0;
    } else {
        vtop->c.ld = -1.0 * 0.0;
    }
}

/* push long long constant */
static inline void vpushll(long long v)
{
    vpush64(VT_LLONG, v);
}

/* cc2 cannot form a 64-bit scalar, so expose only mask construction. */
void vpush_bitfield_mask(int basic_type, int bit_size, int bit_pos, int invert)
{
    unsigned long long mask = (1ULL << bit_size) - 1;
    if (invert)
        mask = ~(mask << bit_pos);
    if (basic_type == VT_LLONG)
        vpushll(mask);
    else
        vpushi((unsigned)mask);
}

static uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    return (a ^ b) >> 63 ? -x : x;
}

static int gen_opic_lt(uint64_t a, uint64_t b)
{
    return (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* Evaluate one already-selected 64-bit operation for two constants. */
int gen_opic_fold_constant(int op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    int t1 = v1->type.t & VT_BTYPE;
    int t2 = v2->type.t & VT_BTYPE;
    uint64_t l1 = v1->c.i;
    uint64_t l2 = v2->c.i;
    int shm = t1 == VT_LLONG ? 63 : 31;

    if (t1 != VT_LLONG)
        l1 = (uint32_t)l1 | (v1->type.t & VT_UNSIGNED ? 0 : -(l1 & 0x80000000));
    if (t2 != VT_LLONG)
        l2 = (uint32_t)l2 | (v2->type.t & VT_UNSIGNED ? 0 : -(l2 & 0x80000000));
    switch (op) {
    case '+': l1 += l2; break;
    case '-': l1 -= l2; break;
    case '&': l1 &= l2; break;
    case '^': l1 ^= l2; break;
    case '|': l1 |= l2; break;
    case '*': l1 *= l2; break;
    case TOK_PDIV:
    case '/':
    case '%':
    case TOK_UDIV:
    case TOK_UMOD:
        if (l2 == 0) {
            if (const_wanted)
                tcc_error("division by zero in constant");
            return 0;
        }
        if (op == '%')
            l1 = l1 - l2 * gen_opic_sdiv(l1, l2);
        else if (op == TOK_UDIV)
            l1 = l1 / l2;
        else if (op == TOK_UMOD)
            l1 = l1 % l2;
        else
            l1 = gen_opic_sdiv(l1, l2);
        break;
    case TOK_SHL: l1 <<= (l2 & shm); break;
    case TOK_SHR: l1 >>= (l2 & shm); break;
    case TOK_SAR:
        l1 = l1 >> 63 ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
        break;
    case TOK_ULT: l1 = l1 < l2; break;
    case TOK_UGE: l1 = l1 >= l2; break;
    case TOK_EQ: l1 = l1 == l2; break;
    case TOK_NE: l1 = l1 != l2; break;
    case TOK_ULE: l1 = l1 <= l2; break;
    case TOK_UGT: l1 = l1 > l2; break;
    case TOK_LT: l1 = gen_opic_lt(l1, l2); break;
    case TOK_GE: l1 = !gen_opic_lt(l1, l2); break;
    case TOK_LE: l1 = !gen_opic_lt(l2, l1); break;
    case TOK_GT: l1 = gen_opic_lt(l2, l1); break;
    case TOK_LAND: l1 = l1 && l2; break;
    case TOK_LOR: l1 = l1 || l2; break;
    default: return 0;
    }
    if (t1 != VT_LLONG)
        l1 = (uint32_t)l1 | (v1->type.t & VT_UNSIGNED ? 0 : -(l1 & 0x80000000));
    v1->c.i = l1;
    vtop--;
    return 1;
}

/* Return the shift for a positive power-of-two vtop constant. */
int gen_opic_power_shift(void)
{
    uint64_t value = vtop->c.i;
    int type = vtop->type.t;
    int shift = -1;

    if ((type & VT_BTYPE) != VT_LLONG)
        value = (uint32_t)value | (type & VT_UNSIGNED ? 0 : -(value & 0x80000000));
    if ((int64_t)value <= 0 || (value & (value - 1)) != 0)
        return -1;
    while (value) {
        value >>= 1;
        shift++;
    }
    return shift;
}

/* Merge a selected plus/minus constant into a symbol or local addend. */
int gen_opic_merge_addend(int op)
{
    SValue *left = vtop - 1;
    uint64_t value = vtop->c.i;
    int type = vtop->type.t;

    if ((type & VT_BTYPE) != VT_LLONG)
        value = (uint32_t)value | (type & VT_UNSIGNED ? 0 : -(value & 0x80000000));
    if (op == '-')
        value = -value;
    value += left->c.i;
    if ((int)value != value)
        return 0;
    vtop--;
    vtop->c.i = value;
    return 1;
}

int gen_opif_fold_constant(int op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    long double f1, f2;

    if (v1->type.t == VT_FLOAT) {
        f1 = v1->c.f;
        f2 = v2->c.f;
    } else if (v1->type.t == VT_DOUBLE) {
        f1 = v1->c.d;
        f2 = v2->c.d;
    } else {
        f1 = v1->c.ld;
        f2 = v2->c.ld;
    }
    if (!ieee_finite(f1) || !ieee_finite(f2))
        return 0;
    switch (op) {
    case '+': f1 += f2; break;
    case '-': f1 -= f2; break;
    case '*': f1 *= f2; break;
    case '/':
        if (f2 == 0.0) {
            if (const_wanted)
                tcc_error("division by zero in constant");
            return 0;
        }
        f1 /= f2;
        break;
    default:
        return 0;
    }
    if (v1->type.t == VT_FLOAT)
        v1->c.f = f1;
    else if (v1->type.t == VT_DOUBLE)
        v1->c.d = f1;
    else
        v1->c.ld = f1;
    vtop--;
    return 1;
}
/* Convert an already-classified constant without generating target code.
   cc2 owns cast policy; this primitive only accesses C's 64-bit and floating
   representations, which the scalar cc0 dialect cannot express directly. */
void gen_cast_constant(CType *type)
{
    int sbt, dbt, sf, df;

    dbt = type->t & (VT_BTYPE | VT_UNSIGNED);
    sbt = vtop->type.t & (VT_BTYPE | VT_UNSIGNED);
    sf = is_float(sbt);
    df = is_float(dbt);
#if !defined TCC_IS_NATIVE && !defined TCC_IS_NATIVE_387
    if (dbt == VT_LDOUBLE)
        tcc_error("long double constant conversion is unavailable");
#endif
    if (sbt == VT_FLOAT)
        vtop->c.ld = vtop->c.f;
    else if (sbt == VT_DOUBLE)
        vtop->c.ld = vtop->c.d;

    if (df) {
        if ((sbt & VT_BTYPE) == VT_LLONG) {
            if ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 63))
                vtop->c.ld = vtop->c.i;
            else
                vtop->c.ld = -(long double)-vtop->c.i;
        } else if(!sf) {
            if ((sbt & VT_UNSIGNED) || !(vtop->c.i >> 31))
                vtop->c.ld = (uint32_t)vtop->c.i;
            else
                vtop->c.ld = -(long double)-(uint32_t)vtop->c.i;
        }

        if (dbt == VT_FLOAT)
            vtop->c.f = (float)vtop->c.ld;
        else if (dbt == VT_DOUBLE)
            vtop->c.d = (double)vtop->c.ld;
    } else if (sf && dbt == (VT_LLONG|VT_UNSIGNED)) {
        vtop->c.i = vtop->c.ld;
    } else if (sf && dbt == VT_BOOL) {
        vtop->c.i = (vtop->c.ld != 0);
    } else {
        if(sf)
            vtop->c.i = vtop->c.ld;
        else if (sbt == (VT_LLONG|VT_UNSIGNED))
            ;
        else if (sbt & VT_UNSIGNED)
            vtop->c.i = (uint32_t)vtop->c.i;
#if PTR_SIZE == 8
        else if (sbt == VT_PTR)
            ;
#endif
        else if (sbt != VT_LLONG)
            vtop->c.i = ((uint32_t)vtop->c.i |
                          -(vtop->c.i & 0x80000000));

        if (dbt == (VT_LLONG|VT_UNSIGNED))
            ;
        else if (dbt == VT_BOOL)
            vtop->c.i = (vtop->c.i != 0);
#if PTR_SIZE == 8
        else if (dbt == VT_PTR)
            ;
#endif
        else if (dbt != VT_LLONG) {
            uint32_t m = ((dbt & VT_BTYPE) == VT_BYTE ? 0xff :
                          (dbt & VT_BTYPE) == VT_SHORT ? 0xffff :
                          0xffffffff);
            vtop->c.i &= m;
            if (!(dbt & VT_UNSIGNED))
                vtop->c.i |= -(vtop->c.i & ((m >> 1) + 1));
        }
    }
}

static inline int64_t expr_const64(void)
{
    int64_t c;
    expr_const1();
    if ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) != VT_CONST)
        expect("constant expression");
    c = vtop->c.i;
    vpop();
    return c;
}

/* Expose the representation only; cc2 owns the 32-bit range policy. */
void expr_const64_words(int *words)
{
    int64_t wc = expr_const64();
    words[0] = wc;
    words[1] = wc >> 32;
}

void initializer_repeat(Section *sec, unsigned long c, int elem_size,
                        int nb_elems)
{
    unsigned long end = c + nb_elems * elem_size;
    unsigned char *src, *dst;
    int i;

    if (end > sec->data_allocated)
        section_realloc(sec, end);
    src = sec->data + c;
    dst = src;
    for (i = 1; i < nb_elems; i++) {
        dst += elem_size;
        memcpy(dst, src, elem_size);
    }
}

/* Copy tokenized narrow-string bytes into TCC's target section storage. */
void initializer_copy_string(Section *sec, unsigned long offset,
                             const void *source, int count)
{
    memcpy(sec->data + offset, source, count);
}

/* Bind legacy typed storage while cc2 owns its initialization policy. */
int cc2_bind_preprocessor_state(void)
{
    define_stack_address = &define_stack;
    file_address = &file;
    parse_flags_address = &parse_flags;
    tok_address = &tok;
    tokc_address = &tokc;
    gnu_ext_address = &gnu_ext;
    tcc_ext_address = &tcc_ext;
    tokstr_buf_address = &tokstr_buf;
    isidnum_table_address = isidnum_table;
    pp_debug_tok_address = &pp_debug_tok;
    pp_debug_symv_address = &pp_debug_symv;
    pp_once_address = &pp_once;
    tok_flags_address = &tok_flags;
    total_lines_address = &total_lines;
    tokcstr_address = &tokcstr;
    hash_ident_address = hash_ident;
    cstr_buf_address = &cstr_buf;
    tok_two_chars_address = tok_two_chars;
    return 0;
}

int cc2_preprocessor_set_stdout(TCCState *state)
{
    state->ppfp = stdout;
    return 0;
}

int cc2_preprocess_start_bridge(TCCState *state, int is_asm)
{
    cc2_bind_preprocess_types(state);
    cc2_preprocess_start((int)state, is_asm);
    return 0;
}

ST_FUNC void preprocess_start(TCCState *state, int is_asm)
{
    cc2_preprocess_start_bridge(state, is_asm);
}

ST_FUNC void tccpp_new(TCCState *state)
{
    cc2_tccpp_new_bridge(state);
}

int cc2_tccpp_new_bridge(TCCState *state)
{
    cc2_bind_preprocessor_state();
    cc2_preprocessor_set_stdout(state);
    cc2_tccpp_new((int)state, (int)tcc_keywords);
    return 0;
}

int cc2_tcc_state_slot(void)
{
    return (int)&tcc_state;
}

int cc2_tcc_state_count_slot(void)
{
    return (int)&nb_states;
}

int cc2_tcc_preprocess_bridge(TCCState *state)
{
    return cc2_tcc_preprocess((int)state);
}

ST_FUNC int tcc_preprocess(TCCState *state)
{
    return cc2_tcc_preprocess_bridge(state);
}

/* Address-taking for legacy typed globals is outside the cc0 dialect. */
int cc2_bind_tcc_globals(TCCState *state)
{
    symtab_section_address = &symtab_section;
    data_section_address = &data_section;
    cur_text_section_address = &cur_text_section;
    bss_section_address = &bss_section;
    common_section_address = &common_section;
    text_section_address = &text_section;
    last_text_section_address = &last_text_section;
    stab_section_address = &stab_section;
    stabstr_section_address = &stabstr_section;
    tcc_state_address = state;
    return 0;
}

int cc2_bind_preprocess_types(TCCState *state)
{
    pvtop = vtop = vstack - 1;
    vstack_base = vstack;
    vstack_limit = vstack + (VSTACK_SIZE - 1);
    int_type_address = &int_type;
    size_type_address = &size_type;
    func_old_type_address = &func_old_type;
    func_vt_address = &func_vt;
    char_pointer_type_address = &char_pointer_type;
    local_stack_address = &local_stack;
    global_label_stack_address = &global_label_stack;
    local_label_stack_address = &local_label_stack;
    ptrdiff_type_address = &ptrdiff_type;
    cc2_bind_tcc_globals(state);
    return 0;
}

int cc2_local_time(int *fields)
{
    time_t value;
    struct tm *local;
    time(&value);
    local = localtime(&value);
    fields[0] = local->tm_hour;
    fields[1] = local->tm_min;
    fields[2] = local->tm_sec;
    fields[3] = local->tm_mday;
    fields[4] = local->tm_mon;
    fields[5] = local->tm_year;
    return 0;
}

/* Keep the opaque setjmp frame alive while cc2 owns compilation policy. */
int cc2_error_scope(TCCState *state, int is_assembler, int file_type)
{
    if (setjmp(state->error_jmp_buf) == 0)
        return cc2_compile_body((int)state, is_assembler, file_type);
    return 0;
}

int cc2_dlopen_global(const char *filename)
{
    return (int)dlopen(filename, RTLD_GLOBAL | RTLD_LAZY);
}

/* These primitives expose representations that scalar cc2 code cannot
   express; all literal syntax, suffix, overflow, and type policy stays cc2. */
int u64_mul_add(unsigned *words, unsigned base, unsigned digit)
{
    unsigned long long old_value;
    unsigned long long value;
    old_value = ((unsigned long long)words[1] << 32) | words[0];
    value = old_value * base + digit;
    words[0] = value;
    words[1] = value >> 32;
    return old_value >= 0x1000000000000000ULL
        && value / base != old_value;
}

int u64_ge(const unsigned *words, unsigned low, unsigned high)
{
    unsigned long long value;
    unsigned long long limit;
    value = ((unsigned long long)words[1] << 32) | words[0];
    limit = ((unsigned long long)high << 32) | low;
    return value >= limit;
}

int store_strtof(void *destination, const char *text)
{
    *(float *)destination = strtof(text, NULL);
    return 0;
}

int store_strtod(void *destination, const char *text)
{
    *(double *)destination = strtod(text, NULL);
    return 0;
}

int store_strtold(void *destination, const char *text)
{
    *(long double *)destination = strtold(text, NULL);
    return 0;
}

int store_ldexp_float(void *destination, const unsigned *words, int exponent)
{
    double value;
    value = (double)words[1] * 4294967296.0 + (double)words[0];
    *(float *)destination = (float)ldexp(value, exponent);
    return 0;
}

int store_ldexp_double(void *destination, const unsigned *words, int exponent)
{
    double value;
    value = (double)words[1] * 4294967296.0 + (double)words[0];
    *(double *)destination = ldexp(value, exponent);
    return 0;
}

int store_ldexp_long_double(void *destination, const unsigned *words,
                            int exponent)
{
    double value;
    value = (double)words[1] * 4294967296.0 + (double)words[0];
    *(long double *)destination = (long double)ldexp(value, exponent);
    return 0;
}

void *cc2_toksym_alloc(int size)
{
    return tcc_malloc(size);
}

void cc2_format_token_integer(char *output, unsigned low, unsigned high)
{
    unsigned long long value = low | ((unsigned long long)high << 32);
    sprintf(output, "%llu", value);
}

/* Rewind a captured initializer through TCC's active macro stream. */
void initializer_rewind(TokenString *stream)
{
    macro_ptr = stream->str;
}

void decl_record_inline(Sym *sym)
{
    struct InlineFunc *fn;
    const char *filename = file ? file->filename : "";

    fn = tcc_malloc(sizeof *fn + strlen(filename));
    strcpy(fn->filename, filename);
    fn->sym = sym;
    skip_or_save_block(&fn->func_str);
    dynarray_add(&tcc_state->inline_fns, &tcc_state->nb_inline_fns, fn);
}
