/*
 * Host representation primitives used by cc2's TCC integration.
 *
 * Selection and compiler policy live in cc2.c. This file contains only
 * operations unavailable in the operator-free scalar dialect.
 */

/* Typed storage stays in the C bridge so the shared cc2 source remains JS. */
CType func_vt;
CType char_pointer_type;
CType func_old_type;
CType int_type;
CType size_type;
CType ptrdiff_type;
SValue __vstack[1 + VSTACK_SIZE];

int tcc_driver_main(int argc, char **argv);
int cc2_bind_preprocess_types(TCCState *state);
int cc2_preprocess_start(TCCState *state, int is_assembler);
int cc2_tccpp_new(TCCState *state, const char *keywords);
int cc2_report_diagnostic(int state, int is_warning, int message);
int cc2_abort_diagnostic(int state);
int cc2_tcc_preprocess(int state);
int cc2_compile_body(int state, int is_assembler, int file_type);

/* Typed global storage; cc2 initializes its compiler policy. */
ST_DATA int gnu_ext;
ST_DATA int tcc_ext;
ST_DATA struct TCCState *tcc_state;
static int nb_states;

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

/* The full bridge exposes TCC's normal command-line policy. */
int cc2_driver_bridge(int argc, char **argv)
{
    return tcc_driver_main(argc, argv);
}

int cc2_storage_init(void)
{
    return 0;
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

static int cc2_ieee_finite(double d)
{
    int p[4];
    memcpy(p, &d, sizeof(double));
    return ((unsigned)((p[1] | 0x800fffff) + 1)) >> 31;
}

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
    memset(&vtop->c, 0, sizeof(vtop->c));
    if (basic_type == VT_FLOAT) {
        ((unsigned char *)&vtop->c)[3] = 128;
    } else if (basic_type == VT_DOUBLE) {
        ((unsigned char *)&vtop->c)[7] = 128;
    } else {
        ((unsigned char *)&vtop->c)[9] = 128;
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

int cc2_float_finite(int value, int basic_type)
{
    if (basic_type == VT_FLOAT)
        return cc2_ieee_finite(*(float *)value);
    if (basic_type == VT_DOUBLE)
        return cc2_ieee_finite(*(double *)value);
    return cc2_ieee_finite(*(long double *)value);
}

int cc2_float_zero(int value, int basic_type)
{
    if (basic_type == VT_FLOAT)
        return !*(float *)value;
    if (basic_type == VT_DOUBLE)
        return !*(double *)value;
    return !*(long double *)value;
}

int cc2_float_add(int left, int right, int basic_type)
{
    if (basic_type == VT_FLOAT)
        *(float *)left += *(float *)right;
    else if (basic_type == VT_DOUBLE)
        *(double *)left += *(double *)right;
    else
        *(long double *)left += *(long double *)right;
    return 0;
}

int cc2_float_subtract(int left, int right, int basic_type)
{
    if (basic_type == VT_FLOAT)
        *(float *)left -= *(float *)right;
    else if (basic_type == VT_DOUBLE)
        *(double *)left -= *(double *)right;
    else
        *(long double *)left -= *(long double *)right;
    return 0;
}

int cc2_float_multiply(int left, int right, int basic_type)
{
    if (basic_type == VT_FLOAT)
        *(float *)left *= *(float *)right;
    else if (basic_type == VT_DOUBLE)
        *(double *)left *= *(double *)right;
    else
        *(long double *)left *= *(long double *)right;
    return 0;
}

int cc2_float_divide(int left, int right, int basic_type)
{
    if (basic_type == VT_FLOAT)
        *(float *)left /= *(float *)right;
    else if (basic_type == VT_DOUBLE)
        *(double *)left /= *(double *)right;
    else
        *(long double *)left /= *(long double *)right;
    return 0;
}
int cc2_float_promote(int value, int source_basic)
{
    if (source_basic == VT_FLOAT)
        *(long double *)value = *(float *)value;
    else
        *(long double *)value = *(double *)value;
    return 0;
}

int cc2_integer64_to_long_double(int value, int is_unsigned)
{
    if (is_unsigned)
        *(long double *)value = *(unsigned long long *)value;
    else
        *(long double *)value = *(long long *)value;
    return 0;
}

int cc2_integer32_to_long_double(int value, int is_unsigned)
{
    if (is_unsigned)
        *(long double *)value = *(unsigned int *)value;
    else
        *(long double *)value = *(int *)value;
    return 0;
}

int cc2_float_narrow(int value, int destination_basic)
{
    if (destination_basic == VT_FLOAT)
        *(float *)value = *(long double *)value;
    else
        *(double *)value = *(long double *)value;
    return 0;
}

int cc2_long_double_to_unsigned64(int value)
{
    *(unsigned long long *)value = *(long double *)value;
    return 0;
}

int cc2_long_double_to_signed64(int value)
{
    *(long long *)value = *(long double *)value;
    return 0;
}

int cc2_long_double_nonzero(int value)
{
    return *(long double *)value != 0;
}

/* Bind legacy typed storage while cc2 owns its initialization policy. */
int cc2_bind_preprocessor_state(void)
{
    gnu_ext = 1;
    tcc_ext = 1;
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
    cc2_preprocess_start(state, is_asm);
    return 0;
}

int cc2_tccpp_new_bridge(TCCState *state)
{
    cc2_bind_preprocessor_state();
    cc2_preprocessor_set_stdout(state);
    cc2_tccpp_new(state, tcc_keywords);
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

int cc2_stderr(void)
{
    return (int)stderr;
}

int cc2_stdout(void)
{
    return (int)stdout;
}

int cc2_call_error_function(int callback, int opaque, const char *message)
{
    ((void (*)(void *, const char *))callback)((void *)opaque, message);
    return 0;
}

int cc2_longjmp_error(TCCState *state)
{
    longjmp(state->error_jmp_buf, 1);
    return 0;
}

int cc2_clock_ms(void)
{
    struct timeval value;
    gettimeofday(&value, NULL);
    return value.tv_sec * 1000 + (value.tv_usec + 500) / 1000;
}

static char *cc2_format_diagnostic(const char *format, va_list arguments)
{
    char *message;
    /* This retains TCC's existing diagnostic formatting capacity. */
    message = tcc_malloc(2048);
    vsnprintf(message, 2048, format, arguments);
    return message;
}

PUB_FUNC void tcc_error_noabort(const char *format, ...)
{
    va_list arguments;
    char *message;
    va_start(arguments, format);
    message = cc2_format_diagnostic(format, arguments);
    va_end(arguments);
    cc2_report_diagnostic((int)tcc_state, 0, (int)message);
    tcc_free(message);
}

PUB_FUNC void tcc_error(const char *format, ...)
{
    va_list arguments;
    char *message;
    va_start(arguments, format);
    message = cc2_format_diagnostic(format, arguments);
    va_end(arguments);
    cc2_report_diagnostic((int)tcc_state, 0, (int)message);
    tcc_free(message);
    cc2_abort_diagnostic((int)tcc_state);
}

PUB_FUNC void tcc_warning(const char *format, ...)
{
    va_list arguments;
    char *message;
    va_start(arguments, format);
    message = cc2_format_diagnostic(format, arguments);
    va_end(arguments);
    cc2_report_diagnostic((int)tcc_state, 1, (int)message);
    tcc_free(message);
}

int cc2_tcc_preprocess_bridge(TCCState *state)
{
    return cc2_tcc_preprocess((int)state);
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
    value = ldexp((double)words[1], 32) + (double)words[0];
    *(float *)destination = (float)ldexp(value, exponent);
    return 0;
}

int store_ldexp_double(void *destination, const unsigned *words, int exponent)
{
    double value;
    value = ldexp((double)words[1], 32) + (double)words[0];
    *(double *)destination = ldexp(value, exponent);
    return 0;
}

int store_ldexp_long_double(void *destination, const unsigned *words,
                            int exponent)
{
    double value;
    value = ldexp((double)words[1], 32) + (double)words[0];
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
