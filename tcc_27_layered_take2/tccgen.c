/*
 *  TCC - Tiny C Compiler
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

/********************************************************/
/* global variables */

/* loc : local variable index
   ind : output code index
   rsym: return symbol
   anon_sym: anonymous symbol index
*/
#define NODATA_WANTED (nocode_wanted > 0) /* no static data output wanted either */
#define STATIC_DATA_WANTED (nocode_wanted & 0xC0000000) /* only static data output */
CType func_vt; /* current function return type (used by return instruction) */

/* ------------------------------------------------------------------------- */

void gen_cast(CType *type);
void gen_cast_s(int t);
int parse_btype(CType *type, AttributeDef *ad);
CType *type_decl(CType *type, AttributeDef *ad, int *v, int td);
void parse_expr_type(CType *type);
void parse_init_elem(int expr_type);
void init_putz(Section *sec, unsigned long c, int size);
void block_return(void);
void block_break(int *break_symbol);
void block_continue(int *continue_symbol);
void block_if(int *break_symbol, int *continue_symbol);
void block_while(void);
void block_do(void);
void block_for(void);
void block_case(void);
void block_default(void);
void block_goto(void);
void block_expression(int is_expression);
void block_switch(int *continue_symbol);
void block_after_label(int *break_symbol, int *continue_symbol,
                       int is_expression);
void block_label(int label, int *break_symbol, int *continue_symbol,
                 int is_expression);
void block_compound(int *break_symbol, int *continue_symbol,
                    int is_expression);
void unary_identifier(int token);
void parse_type(CType *type);
void parse_builtin_params(int nc, const char *args);
void parse_attribute(AttributeDef *ad);
void init_putv(CType *type, Section *sec, unsigned long c);
static void decl_initializer(CType *type, Section *sec, unsigned long c, int first, int size_only);
void block(int *bsym, int *csym, int is_expr);
static void decl_initializer_alloc(CType *type, AttributeDef *ad, int r, int has_init, int v, int scope);
void decl(int l);
int decl0(int l, int is_for_loop_init, Sym *);
void expr_eq(void);
static inline int64_t expr_const64(void);
static void vpush64(int ty, unsigned long long v);
int gvtst(int inv, int t);
static void gen_inline_functions(TCCState *s);
void skip_or_save_block(TokenString **str);

/* we use our own 'finite' function to avoid potential problems with
   non standard math libs */
/* XXX: endianness dependent */
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

/* ------------------------------------------------------------------------- */
/* vstack debugging aid */

#if 0
void pv (const char *lbl, int a, int b)
{
    int i;
    for (i = a; i < a + b; ++i) {
        SValue *p = &vtop[-i];
        printf("%s vtop[-%d] : type.t:%04x  r:%04x  r2:%04x  c.i:%d\n",
            lbl, i, p->type.t, p->r, p->r2, (int)p->c.i);
    }
}
#endif

/* ------------------------------------------------------------------------- */
/* start of translation unit info */
ST_FUNC void tcc_debug_start(TCCState *s1)
{
    if (s1->do_debug) {
        char buf[512];

        /* file info: full path + filename */
        section_sym = put_elf_sym(symtab_section, 0, 0,
                                  ELFW(ST_INFO)(STB_LOCAL, STT_SECTION), 0,
                                  text_section->sh_num, NULL);
        getcwd(buf, sizeof(buf));
#ifdef _WIN32
        normalize_slashes(buf);
#endif
        pstrcat(buf, sizeof(buf), "/");
        put_stabs_r(buf, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
        put_stabs_r(file->filename, N_SO, 0, 0,
                    text_section->data_offset, text_section, section_sym);
        last_ind = 0;
        last_line_num = 0;
    }

    /* an elf symbol of type STT_FILE must be put so that STB_LOCAL
       symbols can be safely used */
    put_elf_sym(symtab_section, 0, 0,
                ELFW(ST_INFO)(STB_LOCAL, STT_FILE), 0,
                SHN_ABS, file->filename);
}

/* put end of translation unit info */
ST_FUNC void tcc_debug_end(TCCState *s1)
{
    if (!s1->do_debug)
        return;
    put_stabs_r(NULL, N_SO, 0, 0,
        text_section->data_offset, text_section, section_sym);

}

/* generate line number info */
void tcc_debug_line(TCCState *s1)
{
    if (!s1->do_debug)
        return;
    if ((last_line_num != file->line_num || last_ind != ind)) {
        put_stabn(N_SLINE, 0, file->line_num, ind - func_ind);
        last_ind = ind;
        last_line_num = file->line_num;
    }
}

/* put function symbol */
ST_FUNC void tcc_debug_funcstart(TCCState *s1, Sym *sym)
{
    char buf[512];

    if (!s1->do_debug)
        return;

    /* stabs info */
    /* XXX: we put here a dummy type */
    snprintf(buf, sizeof(buf), "%s:%c1",
             funcname, sym->type.t & VT_STATIC ? 'f' : 'F');
    put_stabs_r(buf, N_FUN, 0, file->line_num, 0,
                cur_text_section, sym->c);
    /* //gr gdb wants a line at the function */
    put_stabn(N_SLINE, 0, file->line_num, 0);

    last_ind = 0;
    last_line_num = 0;
}

/* put function size */
ST_FUNC void tcc_debug_funcend(TCCState *s1, int size)
{
    if (!s1->do_debug)
        return;
    put_stabn(N_FUN, 0, 0, size);
}

/* ------------------------------------------------------------------------- */
ST_FUNC int tccgen_compile(TCCState *s1)
{
    cur_text_section = NULL;
    funcname = "";
    anon_sym = SYM_FIRST_ANOM;
    section_sym = 0;
    const_wanted = 0;
    nocode_wanted = 0x80000000;

    /* define some often used types */
    int_type.t = VT_INT;
    char_pointer_type.t = VT_BYTE;
    mk_pointer(&char_pointer_type);
#if PTR_SIZE == 4
    size_type.t = VT_INT | VT_UNSIGNED;
    ptrdiff_type.t = VT_INT;
#elif LONG_SIZE == 4
    size_type.t = VT_LLONG | VT_UNSIGNED;
    ptrdiff_type.t = VT_LLONG;
#else
    size_type.t = VT_LONG | VT_LLONG | VT_UNSIGNED;
    ptrdiff_type.t = VT_LONG | VT_LLONG;
#endif
    func_old_type.t = VT_FUNC;
    func_old_type.ref = sym_push(SYM_FIELD, &int_type, 0, 0);
    func_old_type.ref->f.func_call = FUNC_CDECL;
    func_old_type.ref->f.func_type = FUNC_OLD;

    tcc_debug_start(s1);

#ifdef TCC_TARGET_ARM
    arm_init(s1);
#endif

#ifdef INC_DEBUG
    printf("%s: **** new file\n", file->filename);
#endif

    parse_flags = PARSE_FLAG_PREPROCESS | PARSE_FLAG_TOK_NUM | PARSE_FLAG_TOK_STR;
    next();
    decl(VT_CONST);
    gen_inline_functions(s1);
    check_vstack();
    /* end of translation unit info */
    tcc_debug_end(s1);
    return 0;
}

/* ------------------------------------------------------------------------- */
ElfSym *elfsym(Sym *s)
{
  if (!s || !s->c)
    return NULL;
  return &((ElfSym *)symtab_section->data)[s->c];
}

/* apply storage attributes to Elf symbol */

/* ------------------------------------------------------------------------- */
/* update sym->c so that it points to an external symbol in section
   'section' with value 'value' */

ST_FUNC void put_extern_sym2(Sym *sym, int sh_num,
                            addr_t value, unsigned long size,
                            int can_add_underscore)
{
    int sym_type, sym_bind, info, other, t;
    ElfSym *esym;
    const char *name;
    char buf1[256];
#ifdef CONFIG_TCC_BCHECK
    char buf[32];
#endif

    if (!sym->c) {
        name = get_tok_str(sym->v, NULL);
#ifdef CONFIG_TCC_BCHECK
        if (tcc_state->do_bounds_check) {
            /* XXX: avoid doing that for statics ? */
            /* if bound checking is activated, we change some function
               names by adding the "__bound" prefix */
            switch(sym->v) {
#ifdef TCC_TARGET_PE
            /* XXX: we rely only on malloc hooks */
            case TOK_malloc:
            case TOK_free:
            case TOK_realloc:
            case TOK_memalign:
            case TOK_calloc:
#endif
            case TOK_memcpy:
            case TOK_memmove:
            case TOK_memset:
            case TOK_strlen:
            case TOK_strcpy:
            case TOK_alloca:
                strcpy(buf, "__bound_");
                strcat(buf, name);
                name = buf;
                break;
            }
        }
#endif
        t = sym->type.t;
        if ((t & VT_BTYPE) == VT_FUNC) {
            sym_type = STT_FUNC;
        } else if ((t & VT_BTYPE) == VT_VOID) {
            sym_type = STT_NOTYPE;
        } else {
            sym_type = STT_OBJECT;
        }
        if (t & VT_STATIC)
            sym_bind = STB_LOCAL;
        else
            sym_bind = STB_GLOBAL;
        other = 0;
#ifdef TCC_TARGET_PE
        if (sym_type == STT_FUNC && sym->type.ref) {
            Sym *ref = sym->type.ref;
            if (ref->f.func_call == FUNC_STDCALL && can_add_underscore) {
                sprintf(buf1, "_%s@%d", name, ref->f.func_args * PTR_SIZE);
                name = buf1;
                other |= ST_PE_STDCALL;
                can_add_underscore = 0;
            }
        }
#endif
        if (tcc_state->leading_underscore && can_add_underscore) {
            buf1[0] = '_';
            pstrcpy(buf1 + 1, sizeof(buf1) - 1, name);
            name = buf1;
        }
        if (sym->asm_label)
            name = get_tok_str(sym->asm_label, NULL);
        info = ELFW(ST_INFO)(sym_bind, sym_type);
        sym->c = put_elf_sym(symtab_section, value, size, info, other, sh_num, name);
    } else {
        esym = elfsym(sym);
        esym->st_value = value;
        esym->st_size = size;
        esym->st_shndx = sh_num;
    }
    update_storage(sym);
}

void put_extern_sym(Sym *sym, Section *section,
                           addr_t value, unsigned long size)
{
    int sh_num = section ? section->sh_num : SHN_UNDEF;
    put_extern_sym2(sym, sh_num, value, size, 1);
}

/* add a new relocation entry to symbol 'sym' in section 's' */
ST_FUNC void greloca(Section *s, Sym *sym, unsigned long offset, int type,
                     addr_t addend)
{
    int c = 0;

    if (nocode_wanted && s == cur_text_section)
        return;

    if (sym) {
        if (0 == sym->c)
            put_extern_sym(sym, NULL, 0, 0);
        c = sym->c;
    }

    /* now we can add ELF relocation info */
    put_elf_reloca(symtab_section, s, offset, type, c, addend);
}

#if PTR_SIZE == 4
ST_FUNC void greloc(Section *s, Sym *sym, unsigned long offset, int type)
{
    greloca(s, sym, offset, type, 0);
}
#endif

/* ------------------------------------------------------------------------- */

/* push arbitrary 64bit constant */
ST_FUNC void vpush64(int ty, unsigned long long v)
{
    CValue cval;
    CType ctype;
    ctype.t = ty;
    ctype.ref = NULL;
    cval.i = v;
    vsetc(&ctype, VT_CONST, &cval);
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


#ifdef TCC_TARGET_ARM
/* find a register of class 'rc2' with at most one reference on stack.
 * If none, call get_reg(rc) */
ST_FUNC int get_reg_ex(int rc, int rc2)
{
    int r;
    SValue *p;
    
    for(r=0;r<NB_REGS;r++) {
        if (reg_classes[r] & rc2) {
            int n;
            n=0;
            for(p = vstack; p <= vtop; p++) {
                if ((p->r & VT_VALMASK) == r ||
                    (p->r2 & VT_VALMASK) == r)
                    n++;
            }
            if (n <= 1)
                return r;
        }
    }
    return get_reg(rc);
}
#endif

/* move register 's' (of type 't') to 'r', and flush previous value of r to memory
   if needed */
#ifdef CONFIG_TCC_BCHECK
/* generate lvalue bound code */
static void gbound(void)
{
    int lval_type;
    CType type1;

    vtop->r &= ~VT_MUSTBOUND;
    /* if lvalue, then use checking code before dereferencing */
    if (vtop->r & VT_LVAL) {
        /* if not VT_BOUNDED value, then make one */
        if (!(vtop->r & VT_BOUNDED)) {
            lval_type = vtop->r & (VT_LVAL_TYPE | VT_LVAL);
            /* must save type because we must set it to int to get pointer */
            type1 = vtop->type;
            vtop->type.t = VT_PTR;
            gaddrof();
            vpushi(0);
            gen_bounded_ptr_add();
            vtop->r |= lval_type;
            vtop->type = type1;
        }
        /* then check for dereferencing */
        gen_bounded_ptr_deref();
    }
}
#endif


/* single-byte load mode for packed or otherwise unaligned bitfields */

/* single-byte store mode for packed or otherwise unaligned bitfields */


/* store vtop a register belonging to class 'rc'. lvalues are
   converted to values. Cannot be used if cannot be converted to
   register value (such as structures). */


#if PTR_SIZE == 4
/* expand 64bit on stack in two ints */
#endif

#ifdef TCC_TARGET_ARM
/* expand long long on stack */
ST_FUNC void lexpand_nr(void)
{
    int u,v;

    u = vtop->type.t & (VT_DEFSIGN | VT_UNSIGNED);
    vdup();
    vtop->r2 = VT_CONST;
    vtop->type.t = VT_INT | u;
    v=vtop[-1].r & (VT_VALMASK | VT_LVAL);
    if (v == VT_CONST) {
      vtop[-1].c.i = vtop->c.i;
      vtop->c.i = vtop->c.i >> 32;
      vtop->r = VT_CONST;
    } else if (v == (VT_LVAL|VT_CONST) || v == (VT_LVAL|VT_LOCAL)) {
      vtop->c.i += 4;
      vtop->r = vtop[-1].r;
    } else if (v > VT_CONST) {
      vtop--;
      lexpand();
    } else
      vtop->r = vtop[-1].r2;
    vtop[-1].r2 = VT_CONST;
    vtop[-1].type.t = VT_INT | u;
}
#endif

#if PTR_SIZE == 4
/* build a long long from two ints */
#endif

/* convert stack entry to register and duplicate its value in another
   register */

/* Generate value test
 *
 * Generate a test for any value (jump, comparison and integers) */


static uint64_t gen_opic_sdiv(uint64_t a, uint64_t b)
{
    uint64_t x = (a >> 63 ? -a : a) / (b >> 63 ? -b : b);
    return (a ^ b) >> 63 ? -x : x;
}

static int gen_opic_lt(uint64_t a, uint64_t b)
{
    return (a ^ (uint64_t)1 << 63) < (b ^ (uint64_t)1 << 63);
}

/* handle integer constant optimizations and various machine
   independent opt */
void gen_opic(int op)
{
    SValue *v1 = vtop - 1;
    SValue *v2 = vtop;
    int t1 = v1->type.t & VT_BTYPE;
    int t2 = v2->type.t & VT_BTYPE;
    int c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    int c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    uint64_t l1 = c1 ? v1->c.i : 0;
    uint64_t l2 = c2 ? v2->c.i : 0;
    int shm = (t1 == VT_LLONG) ? 63 : 31;

    if (t1 != VT_LLONG && (PTR_SIZE != 8 || t1 != VT_PTR))
        l1 = ((uint32_t)l1 |
              (v1->type.t & VT_UNSIGNED ? 0 : -(l1 & 0x80000000)));
    if (t2 != VT_LLONG && (PTR_SIZE != 8 || t2 != VT_PTR))
        l2 = ((uint32_t)l2 |
              (v2->type.t & VT_UNSIGNED ? 0 : -(l2 & 0x80000000)));

    if (c1 && c2) {
        switch(op) {
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
            /* if division by zero, generate explicit division */
            if (l2 == 0) {
                if (const_wanted)
                    tcc_error("division by zero in constant");
                goto general_case;
            }
            switch(op) {
            default: l1 = gen_opic_sdiv(l1, l2); break;
            case '%': l1 = l1 - l2 * gen_opic_sdiv(l1, l2); break;
            case TOK_UDIV: l1 = l1 / l2; break;
            case TOK_UMOD: l1 = l1 % l2; break;
            }
            break;
        case TOK_SHL: l1 <<= (l2 & shm); break;
        case TOK_SHR: l1 >>= (l2 & shm); break;
        case TOK_SAR:
            l1 = (l1 >> 63) ? ~(~l1 >> (l2 & shm)) : l1 >> (l2 & shm);
            break;
            /* tests */
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
            /* logical */
        case TOK_LAND: l1 = l1 && l2; break;
        case TOK_LOR: l1 = l1 || l2; break;
        default:
            goto general_case;
        }
	if (t1 != VT_LLONG && (PTR_SIZE != 8 || t1 != VT_PTR))
	    l1 = ((uint32_t)l1 |
		(v1->type.t & VT_UNSIGNED ? 0 : -(l1 & 0x80000000)));
        v1->c.i = l1;
        vtop--;
    } else {
        /* if commutative ops, put c2 as constant */
        if (c1 && (op == '+' || op == '&' || op == '^' || 
                   op == '|' || op == '*')) {
            vswap();
            c2 = c1; //c = c1, c1 = c2, c2 = c;
            l2 = l1; //l = l1, l1 = l2, l2 = l;
        }
        if (!const_wanted &&
            c1 && ((l1 == 0 &&
                    (op == TOK_SHL || op == TOK_SHR || op == TOK_SAR)) ||
                   (l1 == -1 && op == TOK_SAR))) {
            /* treat (0 << x), (0 >> x) and (-1 >> x) as constant */
            vtop--;
        } else if (!const_wanted &&
                   c2 && ((l2 == 0 && (op == '&' || op == '*')) ||
                          (op == '|' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))) ||
                          (l2 == 1 && (op == '%' || op == TOK_UMOD)))) {
            /* treat (x & 0), (x * 0), (x | -1) and (x % 1) as constant */
            if (l2 == 1)
                vtop->c.i = 0;
            vswap();
            vtop--;
        } else if (c2 && (((op == '*' || op == '/' || op == TOK_UDIV ||
                          op == TOK_PDIV) &&
                           l2 == 1) ||
                          ((op == '+' || op == '-' || op == '|' || op == '^' ||
                            op == TOK_SHL || op == TOK_SHR || op == TOK_SAR) &&
                           l2 == 0) ||
                          (op == '&' &&
                            (l2 == -1 || (l2 == 0xFFFFFFFF && t2 != VT_LLONG))))) {
            /* filter out NOP operations like x*1, x-0, x&-1... */
            vtop--;
        } else if (c2 && (op == '*' || op == TOK_PDIV || op == TOK_UDIV)) {
            /* try to use shifts instead of muls or divs */
            if (l2 > 0 && (l2 & (l2 - 1)) == 0) {
                int n = -1;
                while (l2) {
                    l2 >>= 1;
                    n++;
                }
                vtop->c.i = n;
                if (op == '*')
                    op = TOK_SHL;
                else if (op == TOK_PDIV)
                    op = TOK_SAR;
                else
                    op = TOK_SHR;
            }
            goto general_case;
        } else if (c2 && (op == '+' || op == '-') &&
                   (((vtop[-1].r & (VT_VALMASK | VT_LVAL | VT_SYM)) == (VT_CONST | VT_SYM))
                    || (vtop[-1].r & (VT_VALMASK | VT_LVAL)) == VT_LOCAL)) {
            /* symbol + constant case */
            if (op == '-')
                l2 = -l2;
	    l2 += vtop[-1].c.i;
	    /* The backends can't always deal with addends to symbols
	       larger than +-1<<31.  Don't construct such.  */
	    if ((int)l2 != l2)
	        goto general_case;
            vtop--;
            vtop->c.i = l2;
        } else {
        general_case:
                /* call low level op generator */
                if (t1 == VT_LLONG || t2 == VT_LLONG ||
                    (PTR_SIZE == 8 && (t1 == VT_PTR || t2 == VT_PTR)))
                    gen_opl(op);
                else
                    gen_opi(op);
        }
    }
}

/* generate a floating point operation with constant propagation */
void gen_opif(int op)
{
    int c1, c2;
    SValue *v1, *v2;
#if defined _MSC_VER && defined _AMD64_
    /* avoid bad optimization with f1 -= f2 for f1:-0.0, f2:0.0 */
    volatile
#endif
    long double f1, f2;

    v1 = vtop - 1;
    v2 = vtop;
    /* currently, we cannot do computations with forward symbols */
    c1 = (v1->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    c2 = (v2->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
    if (c1 && c2) {
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

        /* NOTE: we only do constant propagation if finite number (not
           NaN or infinity) (ANSI spec) */
        if (!ieee_finite(f1) || !ieee_finite(f2))
            goto general_case;

        switch(op) {
        case '+': f1 += f2; break;
        case '-': f1 -= f2; break;
        case '*': f1 *= f2; break;
        case '/': 
            if (f2 == 0.0) {
                if (const_wanted)
                    tcc_error("division by zero in constant");
                goto general_case;
            }
            f1 /= f2; 
            break;
            /* XXX: also handles tests ? */
        default:
            goto general_case;
        }
        /* XXX: overflow test ? */
        if (v1->type.t == VT_FLOAT) {
            v1->c.f = f1;
        } else if (v1->type.t == VT_DOUBLE) {
            v1->c.d = f1;
        } else {
            v1->c.ld = f1;
        }
        vtop--;
    } else {
    general_case:
        gen_opf(op);
    }
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

/* print a type. If 'varstr' is not NULL, then the variable is also
   printed in the type */
/* XXX: union */
/* XXX: add array and function pointers */
void type_to_str(char *buf, int buf_size,
                 CType *type, const char *varstr)
{
    int bt, v, t;
    Sym *s, *sa;
    char buf1[256];
    const char *tstr;

    t = type->t;
    bt = t & VT_BTYPE;
    buf[0] = '\0';

    if (t & VT_EXTERN)
        pstrcat(buf, buf_size, "extern ");
    if (t & VT_STATIC)
        pstrcat(buf, buf_size, "static ");
    if (t & VT_TYPEDEF)
        pstrcat(buf, buf_size, "typedef ");
    if (t & VT_INLINE)
        pstrcat(buf, buf_size, "inline ");
    if (t & VT_VOLATILE)
        pstrcat(buf, buf_size, "volatile ");
    if (t & VT_CONSTANT)
        pstrcat(buf, buf_size, "const ");

    if (((t & VT_DEFSIGN) && bt == VT_BYTE)
        || ((t & VT_UNSIGNED)
            && (bt == VT_SHORT || bt == VT_INT || bt == VT_LLONG)
            && !IS_ENUM(t)
            ))
        pstrcat(buf, buf_size, (t & VT_UNSIGNED) ? "unsigned " : "signed ");

    buf_size -= strlen(buf);
    buf += strlen(buf);

    switch(bt) {
    case VT_VOID:
        tstr = "void";
        goto add_tstr;
    case VT_BOOL:
        tstr = "_Bool";
        goto add_tstr;
    case VT_BYTE:
        tstr = "char";
        goto add_tstr;
    case VT_SHORT:
        tstr = "short";
        goto add_tstr;
    case VT_INT:
        tstr = "int";
        goto maybe_long;
    case VT_LLONG:
        tstr = "long long";
    maybe_long:
        if (t & VT_LONG)
            tstr = "long";
        if (!IS_ENUM(t))
            goto add_tstr;
        tstr = "enum ";
        goto tstruct;
    case VT_FLOAT:
        tstr = "float";
        goto add_tstr;
    case VT_DOUBLE:
        tstr = "double";
        goto add_tstr;
    case VT_LDOUBLE:
        tstr = "long double";
    add_tstr:
        pstrcat(buf, buf_size, tstr);
        break;
    case VT_STRUCT:
        tstr = "struct ";
        if (IS_UNION(t))
            tstr = "union ";
    tstruct:
        pstrcat(buf, buf_size, tstr);
        v = type->ref->v & ~SYM_STRUCT;
        if (v >= SYM_FIRST_ANOM)
            pstrcat(buf, buf_size, "<anonymous>");
        else
            pstrcat(buf, buf_size, get_tok_str(v, NULL));
        break;
    case VT_FUNC:
        s = type->ref;
        type_to_str(buf, buf_size, &s->type, varstr);
        pstrcat(buf, buf_size, "(");
        sa = s->next;
        while (sa != NULL) {
            type_to_str(buf1, sizeof(buf1), &sa->type, NULL);
            pstrcat(buf, buf_size, buf1);
            sa = sa->next;
            if (sa)
                pstrcat(buf, buf_size, ", ");
        }
        pstrcat(buf, buf_size, ")");
        goto no_var;
    case VT_PTR:
        s = type->ref;
        if (t & VT_ARRAY) {
            snprintf(buf1, sizeof(buf1), "%s[%d]", varstr ? varstr : "", s->c);
            type_to_str(buf, buf_size, &s->type, buf1);
            goto no_var;
        }
        pstrcpy(buf1, sizeof(buf1), "*");
        if (t & VT_CONSTANT)
            pstrcat(buf1, buf_size, "const ");
        if (t & VT_VOLATILE)
            pstrcat(buf1, buf_size, "volatile ");
        if (varstr)
            pstrcat(buf1, sizeof(buf1), varstr);
        type_to_str(buf, buf_size, &s->type, buf1);
        goto no_var;
    }
    if (varstr) {
        pstrcat(buf, buf_size, " ");
        pstrcat(buf, buf_size, varstr);
    }
 no_var: ;
}

void tcc_error_type_pair(CType *source_type, CType *destination_type)
{
    char source[256], destination[256];

    type_to_str(source, sizeof(source), source_type, NULL);
    type_to_str(destination, sizeof(destination), destination_type, NULL);
    tcc_error("cannot cast '%s' to '%s'", source, destination);
}

/* verify type compatibility to store vtop in 'dt' type, and generate
   casts if needed. */

/* store vtop in lvalue pushed on stack */

/* post defines POST/PRE add. c is the token ++ or -- */

void parse_mult_str (CString *astr, const char *msg)
{
    /* read the string */
    if (tok != TOK_STR)
        expect(msg);
    cstr_new(astr);
    while (tok == TOK_STR) {
        /* XXX: add \0 handling too ? */
        cstr_cat(astr, tokc.str.data, -1);
        next();
    }
    cstr_ccat(astr, '\0');
}

/* Parse __attribute__((...)) GNUC extension. */
/* Parse a type declarator (except basic type), and return the type
   in 'type'. 'td' is a bitmask indicating which kind of type decl is
   expected. 'type' should contain the basic type. 'ad' is the
   attribute definition of the basic type. It can be modified by
   type_decl().  If this (possibly abstract) declarator is a pointer chain
   it returns the innermost pointed to type (equals *type, but is a different
   pointer), otherwise returns type itself, that's used for recursive calls.  */
/* indirection with full error checking and bound check */

/* pass a parameter to a function and do type checking and casting */
/* parse an expression and return its type without any side effect. */

void unary(void)
{
    int n, t, align, size, r, sizeof_caller;
    CType type;
    Sym *s;
    AttributeDef ad;

    sizeof_caller = in_sizeof;
    in_sizeof = 0;
    type.ref = NULL;
    /* XXX: GCC 2.95.3 does not generate a table although it should be
       better here */
 tok_next:
    switch(tok) {
    case TOK_EXTENSION:
        next();
        goto tok_next;
    case TOK_LCHAR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT|VT_UNSIGNED;
        goto push_tokc;
#endif
    case TOK_CINT:
    case TOK_CCHAR: 
	t = VT_INT;
 push_tokc:
	type.t = t;
	vsetc(&type, VT_CONST, &tokc);
        next();
        break;
    case TOK_CUINT:
        t = VT_INT | VT_UNSIGNED;
        goto push_tokc;
    case TOK_CLLONG:
        t = VT_LLONG;
	goto push_tokc;
    case TOK_CULLONG:
        t = VT_LLONG | VT_UNSIGNED;
	goto push_tokc;
    case TOK_CFLOAT:
        t = VT_FLOAT;
	goto push_tokc;
    case TOK_CDOUBLE:
        t = VT_DOUBLE;
	goto push_tokc;
    case TOK_CLDOUBLE:
        t = VT_LDOUBLE;
	goto push_tokc;
    case TOK_CLONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG;
	goto push_tokc;
    case TOK_CULONG:
        t = (LONG_SIZE == 8 ? VT_LLONG : VT_INT) | VT_LONG | VT_UNSIGNED;
	goto push_tokc;
    case TOK___FUNCTION__:
        if (!gnu_ext)
            goto tok_identifier;
        /* fall thru */
    case TOK___FUNC__:
        {
            void *ptr;
            int len;
            /* special function name identifier */
            len = strlen(funcname) + 1;
            /* generate char[len] type */
            type.t = VT_BYTE;
            mk_pointer(&type);
            type.t |= VT_ARRAY;
            type.ref->c = len;
            vpush_ref(&type, data_section, data_section->data_offset, len);
            if (!NODATA_WANTED) {
                ptr = section_ptr_add(data_section, len);
                memcpy(ptr, funcname, len);
            }
            next();
        }
        break;
    case TOK_LSTR:
#ifdef TCC_TARGET_PE
        t = VT_SHORT | VT_UNSIGNED;
#else
        t = VT_INT;
#endif
        goto str_init;
    case TOK_STR:
        /* string parsing */
        t = VT_BYTE;
        if (tcc_state->char_is_unsigned)
            t = VT_BYTE | VT_UNSIGNED;
    str_init:
        if (tcc_state->warn_write_strings)
            t |= VT_CONSTANT;
        type.t = t;
        mk_pointer(&type);
        type.t |= VT_ARRAY;
        memset(&ad, 0, sizeof(AttributeDef));
        decl_initializer_alloc(&type, &ad, VT_CONST, 2, 0, 0);
        break;
    case '(':
        next();
        /* cast ? */
        if (parse_btype(&type, &ad)) {
            type_decl(&type, &ad, &n, TYPE_ABSTRACT);
            skip(')');
            /* check ISOC99 compound literal */
            if (tok == '{') {
                    /* data is allocated locally by default */
                if (global_expr)
                    r = VT_CONST;
                else
                    r = VT_LOCAL;
                /* all except arrays are lvalues */
                if (!(type.t & VT_ARRAY))
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
        } else if (tok == '{') {
	    int saved_nocode_wanted = nocode_wanted;
            if (const_wanted)
                tcc_error("expected constant");
            /* save all registers */
            save_regs(0);
            /* statement expression : we do not accept break/continue
               inside as GCC does.  We do retain the nocode_wanted state,
	       as statement expressions can't ever be entered from the
	       outside, so any reactivation of code emission (from labels
	       or loop heads) can be disabled again after the end of it. */
            block(NULL, NULL, 1);
	    nocode_wanted = saved_nocode_wanted;
            skip(')');
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
        /* functions names must be treated as function pointers,
           except for unary '&' and sizeof. Since we consider that
           functions are not lvalues, we only have to handle it
           there and in function calls. */
        /* arrays can also be used although they are not lvalues */
        if ((vtop->type.t & VT_BTYPE) != VT_FUNC &&
            !(vtop->type.t & VT_ARRAY))
            test_lvalue();
        mk_pointer(&vtop->type);
        gaddrof();
        break;
    case '!':
        next();
        unary();
        if ((vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST) {
            gen_cast_s(VT_BOOL);
            vtop->c.i = !vtop->c.i;
        } else if ((vtop->r & VT_VALMASK) == VT_CMP)
            vtop->c.i ^= 1;
        else {
            save_regs(1);
            vseti(VT_JMP, gvtst(1, 0));
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
        if ((vtop->type.t & VT_BTYPE) == VT_PTR)
            tcc_error("pointer not accepted for unary plus");
        /* In order to force cast, we add zero, except for floating point
	   where we really need an noop (otherwise -0.0 will be transformed
	   into +0.0).  */
	if (!is_float(vtop->type.t)) {
	    vpushi(0);
	    gen_op('+');
	}
        break;
    case TOK_SIZEOF:
    case TOK_ALIGNOF1:
    case TOK_ALIGNOF2:
        t = tok;
        next();
        in_sizeof++;
        expr_type(&type, 1); /* Perform a in_sizeof = 0; */
        s = vtop[1].sym; /* hack: accessing previous vtop */
        size = type_size(&type, &align);
        if (s && s->a.aligned)
            align = 1 << (s->a.aligned - 1);
        if (t == TOK_SIZEOF) {
            if (!(type.t & VT_VLA)) {
                if (size < 0)
                    tcc_error("sizeof applied to an incomplete type");
                vpushs(size);
            } else {
                vla_runtime_type_size(&type, &align);
            }
        } else {
            vpushs(align);
        }
        vtop->type.t |= VT_UNSIGNED;
        break;

    case TOK_builtin_expect:
	/* __builtin_expect is a no-op for now */
	parse_builtin_params(0, "ee");
	vpop();
        break;
    case TOK_builtin_types_compatible_p:
	parse_builtin_params(0, "tt");
	vtop[-1].type.t &= ~(VT_CONSTANT | VT_VOLATILE);
	vtop[0].type.t &= ~(VT_CONSTANT | VT_VOLATILE);
	n = is_compatible_types(&vtop[-1].type, &vtop[0].type);
	vtop -= 2;
	vpushi(n);
        break;
    case TOK_builtin_choose_expr:
	{
	    int64_t c;
	    next();
	    skip('(');
	    c = expr_const64();
	    skip(',');
	    if (!c) {
		nocode_wanted++;
	    }
	    expr_eq();
	    if (!c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(',');
	    if (c) {
		nocode_wanted++;
	    }
	    expr_eq();
	    if (c) {
		vpop();
		nocode_wanted--;
	    }
	    skip(')');
	}
        break;
    case TOK_builtin_constant_p:
	parse_builtin_params(1, "e");
	n = (vtop->r & (VT_VALMASK | VT_LVAL | VT_SYM)) == VT_CONST;
	vtop--;
	vpushi(n);
        break;
    case TOK_builtin_frame_address:
    case TOK_builtin_return_address:
        {
            int tok1 = tok;
            int level;
            next();
            skip('(');
            if (tok != TOK_CINT) {
                tcc_error("%s only takes positive integers",
                          tok1 == TOK_builtin_return_address ?
                          "__builtin_return_address" :
                          "__builtin_frame_address");
            }
            level = (uint32_t)tokc.i;
            next();
            skip(')');
            type.t = VT_VOID;
            mk_pointer(&type);
            vset(&type, VT_LOCAL, 0);       /* local frame */
            while (level--) {
                mk_pointer(&vtop->type);
                indir();                    /* -> parent frame */
            }
            if (tok1 == TOK_builtin_return_address) {
                // assume return address is just above frame pointer on stack
                vpushi(PTR_SIZE);
                gen_op('+');
                mk_pointer(&vtop->type);
                indir();
            }
        }
        break;
#ifdef TCC_TARGET_X86_64
#ifdef TCC_TARGET_PE
    case TOK_builtin_va_start:
	parse_builtin_params(0, "ee");
        r = vtop->r & VT_VALMASK;
        if (r == VT_LLOCAL)
            r = VT_LOCAL;
        if (r != VT_LOCAL)
            tcc_error("__builtin_va_start expects a local variable");
        vtop->r = r;
	vtop->type = char_pointer_type;
	vtop->c.i += 8;
	vstore();
        break;
#else
    case TOK_builtin_va_arg_types:
	parse_builtin_params(0, "t");
	vpushi(classify_x86_64_va_arg(&vtop->type));
	vswap();
	vpop();
        break;
#endif
#endif

#ifdef TCC_TARGET_ARM64
    case TOK___va_start: {
	parse_builtin_params(0, "ee");
        //xx check types
        gen_va_start();
        vpushi(0);
        vtop->type.t = VT_VOID;
        break;
    }
    case TOK___va_arg: {
	parse_builtin_params(0, "et");
	type = vtop->type;
	vpop();
        //xx check types
        gen_va_arg(&type);
        vtop->type = type;
        break;
    }
    case TOK___arm64_clear_cache: {
	parse_builtin_params(0, "ee");
        gen_clear_cache();
        vpushi(0);
        vtop->type.t = VT_VOID;
        break;
    }
#endif
    /* pre operations */
    case TOK_INC:
    case TOK_DEC:
        t = tok;
        next();
        unary();
        inc(0, t);
        break;
    case '-':
        next();
        unary();
        t = vtop->type.t & VT_BTYPE;
	if (is_float(t)) {
            /* In IEEE negate(x) isn't subtract(0,x), but rather
	       subtract(-0, x).  */
	    vpush(&vtop->type);
	    if (t == VT_FLOAT)
	        vtop->c.f = -1.0 * 0.0;
	    else if (t == VT_DOUBLE)
	        vtop->c.d = -1.0 * 0.0;
	    else
	        vtop->c.ld = -1.0 * 0.0;
	} else
	    vpushi(0);
	vswap();
	gen_op('-');
        break;
    case TOK_LAND:
        if (!gnu_ext)
            goto tok_identifier;
        next();
        /* allow to take the address of a label */
        if (tok < TOK_UIDENT)
            expect("label identifier");
        s = label_find(tok);
        if (!s) {
            s = label_push(&global_label_stack, tok, LABEL_FORWARD);
        } else {
            if (s->r == LABEL_DECLARED)
                s->r = LABEL_FORWARD;
        }
        if (!s->type.t) {
            s->type.t = VT_VOID;
            mk_pointer(&s->type);
            s->type.t |= VT_STATIC;
        }
        vpushsym(&s->type, s);
        next();
        break;

    case TOK_GENERIC:
    {
	CType controlling_type;
	int has_default = 0;
	int has_match = 0;
	int learn = 0;
	TokenString *str = NULL;

	next();
	skip('(');
	expr_type(&controlling_type, 2);
	controlling_type.t &= ~(VT_CONSTANT | VT_VOLATILE | VT_ARRAY);
	for (;;) {
	    learn = 0;
	    skip(',');
	    if (tok == TOK_DEFAULT) {
		if (has_default)
		    tcc_error("too many 'default'");
		has_default = 1;
		if (!has_match)
		    learn = 1;
		next();
	    } else {
	        AttributeDef ad_tmp;
		int itmp;
	        CType cur_type;
		parse_btype(&cur_type, &ad_tmp);
		type_decl(&cur_type, &ad_tmp, &itmp, TYPE_ABSTRACT);
		if (compare_types(&controlling_type, &cur_type, 0)) {
		    if (has_match) {
		      tcc_error("type match twice");
		    }
		    has_match = 1;
		    learn = 1;
		}
	    }
	    skip(':');
	    if (learn) {
		if (str)
		    tok_str_free(str);
		skip_or_save_block(&str);
	    } else {
		skip_or_save_block(NULL);
	    }
	    if (tok == ')')
		break;
	}
	if (!str) {
	    char buf[60];
	    type_to_str(buf, sizeof buf, &controlling_type, NULL);
	    tcc_error("type '%s' does not match any association", buf);
	}
	begin_macro(str, 1);
	next();
	expr_eq();
	if (tok != TOK_EOF)
	    expect(",");
	end_macro();
        next();
	break;
    }
    // special qnan , snan and infinity values
    case TOK___NAN__:
        vpush64(VT_DOUBLE, 0x7ff8000000000000ULL);
        next();
        break;
    case TOK___SNAN__:
        vpush64(VT_DOUBLE, 0x7ff0000000000001ULL);
        next();
        break;
    case TOK___INF__:
        vpush64(VT_DOUBLE, 0x7ff0000000000000ULL);
        next();
        break;

    default:
    tok_identifier:
        t = tok;
        unary_identifier(t);
        break;
    }
    
    /* post operations */
    while (1) {
        if (tok == TOK_INC || tok == TOK_DEC) {
            inc(1, tok);
            next();
        } else if (tok == '.' || tok == TOK_ARROW || tok == TOK_CDOUBLE) {
            int qualifiers;
            /* field */ 
            if (tok == TOK_ARROW) 
                indir();
            qualifiers = vtop->type.t & (VT_CONSTANT | VT_VOLATILE);
            test_lvalue();
            gaddrof();
            /* expect pointer on structure */
            if ((vtop->type.t & VT_BTYPE) != VT_STRUCT)
                expect("struct or union");
            if (tok == TOK_CDOUBLE)
                expect("field name");
            next();
            if (tok == TOK_CINT || tok == TOK_CUINT)
                expect("field name");
	    s = find_field(&vtop->type, tok);
            if (!s)
                tcc_error("field not found: %s",  get_tok_str(tok & ~SYM_FIELD, &tokc));
            /* add field offset to pointer */
            vtop->type = char_pointer_type; /* change type to 'char *' */
            vpushi(s->c);
            gen_op('+');
            /* change type to field type, and set to lvalue */
            vtop->type = s->type;
            vtop->type.t |= qualifiers;
            /* an array is never an lvalue */
            if (!(vtop->type.t & VT_ARRAY)) {
                vtop->r |= lvalue_type(vtop->type.t);
#ifdef CONFIG_TCC_BCHECK
                /* if bound checking, the referenced pointer must be checked */
                if (tcc_state->do_bounds_check && (vtop->r & VT_VALMASK) != VT_LOCAL)
                    vtop->r |= VT_MUSTBOUND;
#endif
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
            int nb_args, ret_nregs, ret_align, regsize, variadic;

            /* function call  */
            if ((vtop->type.t & VT_BTYPE) != VT_FUNC) {
                /* pointer test (no array accepted) */
                if ((vtop->type.t & (VT_BTYPE | VT_ARRAY)) == VT_PTR) {
                    vtop->type = *pointed_type(&vtop->type);
                    if ((vtop->type.t & VT_BTYPE) != VT_FUNC)
                        goto error_func;
                } else {
                error_func:
                    expect("function pointer");
                }
            } else {
                vtop->r &= ~VT_LVAL; /* no lvalue */
            }
            /* get return type */
            s = vtop->type.ref;
            next();
            sa = s->next; /* first parameter */
            nb_args = regsize = 0;
            ret.r2 = VT_CONST;
            /* compute first implicit argument if a structure is returned */
            if ((s->type.t & VT_BTYPE) == VT_STRUCT) {
                variadic = (s->f.func_type == FUNC_ELLIPSIS);
                ret_nregs = gfunc_sret(&s->type, variadic, &ret.type,
                                       &ret_align, &regsize);
                if (!ret_nregs) {
                    /* get some space for the returned structure */
                    size = type_size(&s->type, &align);
#ifdef TCC_TARGET_ARM64
                /* On arm64, a small struct is return in registers.
                   It is much easier to write it to memory if we know
                   that we are allowed to write some extra bytes, so
                   round the allocated space up to a power of 2: */
                if (size < 16)
                    while (size & (size - 1))
                        size = (size | (size - 1)) + 1;
#endif
                    loc = (loc - size) & -align;
                    ret.type = s->type;
                    ret.r = VT_LOCAL | VT_LVAL;
                    /* pass it as 'int' to avoid structure arg passing
                       problems */
                    vseti(VT_LOCAL, loc);
                    ret.c = vtop->c;
                    nb_args++;
                }
            } else {
                ret_nregs = 1;
                ret.type = s->type;
            }

            if (ret_nregs) {
                /* return in register */
                if (is_float(ret.type.t)) {
                    ret.r = reg_fret(ret.type.t);
#ifdef TCC_TARGET_X86_64
                    if ((ret.type.t & VT_BTYPE) == VT_QFLOAT)
                      ret.r2 = REG_QRET;
#endif
                } else {
#ifndef TCC_TARGET_ARM64
#ifdef TCC_TARGET_X86_64
                    if ((ret.type.t & VT_BTYPE) == VT_QLONG)
#else
                    if ((ret.type.t & VT_BTYPE) == VT_LLONG)
#endif
                        ret.r2 = REG_LRET;
#endif
                    ret.r = REG_IRET;
                }
                ret.c.i = 0;
            }
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

            /* return value */
            for (r = ret.r + ret_nregs + !ret_nregs; r-- > ret.r;) {
                vsetc(&ret.type, r, &ret.c);
                vtop->r2 = ret.r2; /* Loop only happens when r2 is VT_CONST */
            }

            /* handle packed struct return */
            if (((s->type.t & VT_BTYPE) == VT_STRUCT) && ret_nregs) {
                int addr, offset;

                size = type_size(&s->type, &align);
		/* We're writing whole regs often, make sure there's enough
		   space.  Assume register size is power of 2.  */
		if (regsize > align)
		  align = regsize;
                loc = (loc - size) & -align;
                addr = loc;
                offset = 0;
                for (;;) {
                    vset(&ret.type, VT_LOCAL | VT_LVAL, addr + offset);
                    vswap();
                    vstore();
                    vtop--;
                    if (--ret_nregs == 0)
                        break;
                    offset += regsize;
                }
                vset(&s->type, VT_LOCAL | VT_LVAL, addr);
            }
        } else {
            break;
        }
    }
}

/* parse an integer constant and return its value. */
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

/* return the label token if current token is a label, otherwise
   return zero */


/* This skips over a stream of tokens containing balanced {} and ()
   pairs, stopping at outer ',' ';' and '}' (or matching '}' if we started
   with a '{').  If STR then allocates and stores the skipped tokens
   in *STR.  This doesn't check if () and {} are nested correctly,
   i.e. "({)}" is accepted.  */
#define EXPR_CONST 1
#define EXPR_ANY   2

/* put zeros for variable based init */
/* t is the array or struct type. c is the array or struct
   address. cur_field is the pointer to the current
   field, for arrays the 'c' member contains the current start
   index.  'size_only' is true if only size info is needed (only used
   in arrays).  al contains the already initialized length of the
   current container (starting at c).  This returns the new length of that.  */
static int decl_designator(CType *type, Section *sec, unsigned long c,
                           Sym **cur_field, int size_only, int al)
{
    Sym *s, *f;
    int index, index_last, align, l, nb_elems, elem_size;
    unsigned long corig = c;

    elem_size = 0;
    nb_elems = 1;
    if (gnu_ext && (l = is_label(TOK_UIDENT)) != 0)
        goto struct_field;
    /* NOTE: we only support ranges for last designator */
    while (nb_elems == 1 && (tok == '[' || tok == '.')) {
        if (tok == '[') {
            if (!(type->t & VT_ARRAY))
                expect("array type");
            next();
            index = index_last = expr_const();
            if (tok == TOK_DOTS && gnu_ext) {
                next();
                index_last = expr_const();
            }
            skip(']');
            s = type->ref;
	    if (index < 0 || (s->c >= 0 && index_last >= s->c) ||
		index_last < index)
	        tcc_error("invalid index");
            if (cur_field)
		(*cur_field)->c = index_last;
            type = pointed_type(type);
            elem_size = type_size(type, &align);
            c += index * elem_size;
            nb_elems = index_last - index + 1;
        } else {
            next();
            l = tok;
        struct_field:
            next();
            if ((type->t & VT_BTYPE) != VT_STRUCT)
                expect("struct/union type");
	    f = find_field(type, l);
            if (!f)
                expect("field");
            if (cur_field)
                *cur_field = f;
	    type = &f->type;
            c += f->c;
        }
        cur_field = NULL;
    }
    if (!cur_field) {
        if (tok == '=') {
            next();
        } else if (!gnu_ext) {
	    expect("=");
        }
    } else {
        if (type->t & VT_ARRAY) {
	    index = (*cur_field)->c;
	    if (type->ref->c >= 0 && index >= type->ref->c)
	        tcc_error("index too large");
            type = pointed_type(type);
            c += index * type_size(type, &align);
        } else {
            f = *cur_field;
	    while (f && (f->v & SYM_FIRST_ANOM) && (f->type.t & VT_BITFIELD))
	        *cur_field = f = f->next;
            if (!f)
                tcc_error("too many field init");
	    type = &f->type;
            c += f->c;
        }
    }
    /* must put zero in holes (note that doing it that way
       ensures that it even works with designators) */
    if (!size_only && c - corig > al)
	init_putz(sec, corig + al, c - corig - al);
    decl_initializer(type, sec, c, 0, size_only);

    /* XXX: make it more general */
    if (!size_only && nb_elems > 1) {
        unsigned long c_end;
        uint8_t *src, *dst;
        int i;

        if (!sec) {
	    vset(type, VT_LOCAL|VT_LVAL, c);
	    for (i = 1; i < nb_elems; i++) {
		vset(type, VT_LOCAL|VT_LVAL, c + elem_size * i);
		vswap();
		vstore();
	    }
	    vpop();
        } else if (!NODATA_WANTED) {
	    c_end = c + nb_elems * elem_size;
	    if (c_end > sec->data_allocated)
	        section_realloc(sec, c_end);
	    src = sec->data + c;
	    dst = src;
	    for(i = 1; i < nb_elems; i++) {
		dst += elem_size;
		memcpy(dst, src, elem_size);
	    }
	}
    }
    c += nb_elems * type_size(type, &align);
    if (c - corig > al)
      al = c - corig;
    return al;
}

/* store a value or an expression directly in global data or in local array */
void init_putv(CType *type, Section *sec, unsigned long c)
{
    int bt;
    void *ptr;
    CType dtype;

    dtype = *type;
    dtype.t &= ~VT_CONSTANT; /* need to do that to avoid false warning */

    if (sec) {
	int size, align;
        /* XXX: not portable */
        /* XXX: generate error if incorrect relocation */
        gen_assign_cast(&dtype);
        bt = type->t & VT_BTYPE;

        if ((vtop->r & VT_SYM)
            && bt != VT_PTR
            && bt != VT_FUNC
            && (bt != (PTR_SIZE == 8 ? VT_LLONG : VT_INT)
                || (type->t & VT_BITFIELD))
            && !((vtop->r & VT_CONST) && vtop->sym->v >= SYM_FIRST_ANOM)
            )
            tcc_error("initializer element is not computable at load time");

        if (NODATA_WANTED) {
            vtop--;
            return;
        }

	size = type_size(type, &align);
	section_reserve(sec, c + size);
        ptr = sec->data + c;

        /* XXX: make code faster ? */
	if ((vtop->r & (VT_SYM|VT_CONST)) == (VT_SYM|VT_CONST) &&
	    vtop->sym->v >= SYM_FIRST_ANOM &&
	    /* XXX This rejects compound literals like
	       '(void *){ptr}'.  The problem is that '&sym' is
	       represented the same way, which would be ruled out
	       by the SYM_FIRST_ANOM check above, but also '"string"'
	       in 'char *p = "string"' is represented the same
	       with the type being VT_PTR and the symbol being an
	       anonymous one.  That is, there's no difference in vtop
	       between '(void *){x}' and '&(void *){x}'.  Ignore
	       pointer typed entities here.  Hopefully no real code
	       will every use compound literals with scalar type.  */
	    (vtop->type.t & VT_BTYPE) != VT_PTR) {
	    /* These come from compound literals, memcpy stuff over.  */
	    Section *ssec;
	    ElfSym *esym;
	    ElfW_Rel *rel;
	    esym = elfsym(vtop->sym);
	    ssec = tcc_state->sections[esym->st_shndx];
	    memmove (ptr, ssec->data + esym->st_value, size);
	    if (ssec->reloc) {
		/* We need to copy over all memory contents, and that
		   includes relocations.  Use the fact that relocs are
		   created it order, so look from the end of relocs
		   until we hit one before the copied region.  */
		int num_relocs = ssec->reloc->data_offset / sizeof(*rel);
		rel = (ElfW_Rel*)(ssec->reloc->data + ssec->reloc->data_offset);
		while (num_relocs--) {
		    rel--;
		    if (rel->r_offset >= esym->st_value + size)
		      continue;
		    if (rel->r_offset < esym->st_value)
		      break;
		    /* Note: if the same fields are initialized multiple
		       times (possible with designators) then we possibly
		       add multiple relocations for the same offset here.
		       That would lead to wrong code, the last reloc needs
		       to win.  We clean this up later after the whole
		       initializer is parsed.  */
		    put_elf_reloca(symtab_section, sec,
				   c + rel->r_offset - esym->st_value,
				   ELFW(R_TYPE)(rel->r_info),
				   ELFW(R_SYM)(rel->r_info),
#if PTR_SIZE == 8
				   rel->r_addend
#else
				   0
#endif
				  );
		}
	    }
	} else {
            if (type->t & VT_BITFIELD) {
                int bit_pos, bit_size, bits, n;
                unsigned char *p, v, m;
                bit_pos = BIT_POS(vtop->type.t);
                bit_size = BIT_SIZE(vtop->type.t);
                p = (unsigned char*)ptr + (bit_pos >> 3);
                bit_pos &= 7, bits = 0;
                while (bit_size) {
                    n = 8 - bit_pos;
                    if (n > bit_size)
                        n = bit_size;
                    v = vtop->c.i >> bits << bit_pos;
                    m = ((1 << n) - 1) << bit_pos;
                    *p = (*p & ~m) | (v & m);
                    bits += n, bit_size -= n, bit_pos = 0, ++p;
                }
            } else
            switch(bt) {
		/* XXX: when cross-compiling we assume that each type has the
		   same representation on host and target, which is likely to
		   be wrong in the case of long double */
	    case VT_BOOL:
		vtop->c.i = vtop->c.i != 0;
	    case VT_BYTE:
		*(char *)ptr |= vtop->c.i;
		break;
	    case VT_SHORT:
		*(short *)ptr |= vtop->c.i;
		break;
	    case VT_FLOAT:
		*(float*)ptr = vtop->c.f;
		break;
	    case VT_DOUBLE:
		*(double *)ptr = vtop->c.d;
		break;
	    case VT_LDOUBLE:
#if defined TCC_IS_NATIVE_387
                if (sizeof (long double) >= 10) /* zero pad ten-byte LD */
                    memcpy(ptr, &vtop->c.ld, 10);
#ifdef __TINYC__
                else if (sizeof (long double) == sizeof (double))
                    __asm__("fldl %1\nfstpt %0\n" : "=m" (*ptr) : "m" (vtop->c.ld));
#endif
                else if (vtop->c.ld == 0.0)
                    ;
                else
#endif
                if (sizeof(long double) == LDOUBLE_SIZE)
		    *(long double*)ptr = vtop->c.ld;
                else if (sizeof(double) == LDOUBLE_SIZE)
		    *(double *)ptr = (double)vtop->c.ld;
                else
                    tcc_error("can't cross compile long double constants");
		break;
#if PTR_SIZE != 8
	    case VT_LLONG:
		*(long long *)ptr |= vtop->c.i;
		break;
#else
	    case VT_LLONG:
#endif
	    case VT_PTR:
		{
		    addr_t val = vtop->c.i;
#if PTR_SIZE == 8
		    if (vtop->r & VT_SYM)
		      greloca(sec, vtop->sym, c, R_DATA_PTR, val);
		    else
		      *(addr_t *)ptr |= val;
#else
		    if (vtop->r & VT_SYM)
		      greloc(sec, vtop->sym, c, R_DATA_PTR);
		    *(addr_t *)ptr |= val;
#endif
		    break;
		}
	    default:
		{
		    int val = vtop->c.i;
#if PTR_SIZE == 8
		    if (vtop->r & VT_SYM)
		      greloca(sec, vtop->sym, c, R_DATA_PTR, val);
		    else
		      *(int *)ptr |= val;
#else
		    if (vtop->r & VT_SYM)
		      greloc(sec, vtop->sym, c, R_DATA_PTR);
		    *(int *)ptr |= val;
#endif
		    break;
		}
	    }
	}
        vtop--;
    } else {
        vset(&dtype, VT_LOCAL|VT_LVAL, c);
        vswap();
        vstore();
        vpop();
    }
}

/* 't' contains the type and storage info. 'c' is the offset of the
   object in section 'sec'. If 'sec' is NULL, it means stack based
   allocation. 'first' is true if array '{' must be read (multi
   dimension implicit array init handling). 'size_only' is true if
   size only evaluation is wanted (only for arrays). */
static void decl_initializer(CType *type, Section *sec, unsigned long c, 
                             int first, int size_only)
{
    int len, n, no_oblock, nb, i;
    int size1, align1;
    int have_elem;
    Sym *s, *f;
    Sym indexsym;
    CType *t1;

    /* If we currently are at an '}' or ',' we have read an initializer
       element in one of our callers, and not yet consumed it.  */
    have_elem = tok == '}' || tok == ',';
    if (!have_elem && tok != '{' &&
	/* In case of strings we have special handling for arrays, so
	   don't consume them as initializer value (which would commit them
	   to some anonymous symbol).  */
	tok != TOK_LSTR && tok != TOK_STR &&
	!size_only) {
	parse_init_elem(!sec ? EXPR_ANY : EXPR_CONST);
	have_elem = 1;
    }

    if (have_elem &&
	!(type->t & VT_ARRAY) &&
	/* Use i_c_parameter_t, to strip toplevel qualifiers.
	   The source type might have VT_CONSTANT set, which is
	   of course assignable to non-const elements.  */
	is_compatible_unqualified_types(type, &vtop->type)) {
        init_putv(type, sec, c);
    } else if (type->t & VT_ARRAY) {
        s = type->ref;
        n = s->c;
        t1 = pointed_type(type);
        size1 = type_size(t1, &align1);

        no_oblock = 1;
        if ((first && tok != TOK_LSTR && tok != TOK_STR) || 
            tok == '{') {
            if (tok != '{')
                tcc_error("character array initializer must be a literal,"
                    " optionally enclosed in braces");
            skip('{');
            no_oblock = 0;
        }

        /* only parse strings here if correct type (otherwise: handle
           them as ((w)char *) expressions */
        if ((tok == TOK_LSTR && 
#ifdef TCC_TARGET_PE
             (t1->t & VT_BTYPE) == VT_SHORT && (t1->t & VT_UNSIGNED)
#else
             (t1->t & VT_BTYPE) == VT_INT
#endif
            ) || (tok == TOK_STR && (t1->t & VT_BTYPE) == VT_BYTE)) {
	    len = 0;
            while (tok == TOK_STR || tok == TOK_LSTR) {
                int cstr_len, ch;

                /* compute maximum number of chars wanted */
                if (tok == TOK_STR)
                    cstr_len = tokc.str.size;
                else
                    cstr_len = tokc.str.size / sizeof(nwchar_t);
                cstr_len--;
                nb = cstr_len;
                if (n >= 0 && nb > (n - len))
                    nb = n - len;
                if (!size_only) {
                    if (cstr_len > nb)
                        tcc_warning("initializer-string for array is too long");
                    /* in order to go faster for common case (char
                       string in global variable, we handle it
                       specifically */
                    if (sec && tok == TOK_STR && size1 == 1) {
                        if (!NODATA_WANTED)
                            memcpy(sec->data + c + len, tokc.str.data, nb);
                    } else {
                        for(i=0;i<nb;i++) {
                            if (tok == TOK_STR)
                                ch = ((unsigned char *)tokc.str.data)[i];
                            else
                                ch = ((nwchar_t *)tokc.str.data)[i];
			    vpushi(ch);
                            init_putv(t1, sec, c + (len + i) * size1);
                        }
                    }
                }
                len += nb;
                next();
            }
            /* only add trailing zero if enough storage (no
               warning in this case since it is standard) */
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
		if (type->t & VT_ARRAY) {
		    ++indexsym.c;
		    /* special test for multi dimensional arrays (may not
		       be strictly correct if designators are used at the
		       same time) */
		    if (no_oblock && len >= n*size1)
		        break;
		} else {
		    if (s->type.t == VT_UNION)
		        f = NULL;
		    else
		        f = f->next;
		    if (no_oblock && f == NULL)
		        break;
		}

		if (tok == '}')
		    break;
		skip(',');
	    }
        }
        /* put zeros at the end */
	if (!size_only && len < n*size1)
	    init_putz(sec, c + len, n*size1 - len);
        if (!no_oblock)
            skip('}');
        /* patch type size if needed, which happens only for array types */
        if (n < 0)
            s->c = size1 == 1 ? len : ((len + size1 - 1)/size1);
    } else if ((type->t & VT_BTYPE) == VT_STRUCT) {
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
	/* If we supported only ISO C we wouldn't have to accept calling
	   this on anything than an array size_only==1 (and even then
	   only on the outermost level, so no recursion would be needed),
	   because initializing a flex array member isn't supported.
	   But GNU C supports it, so we need to recurse even into
	   subfields of structs and arrays when size_only is set.  */
        /* just skip expression */
        skip_or_save_block(NULL);
    } else {
	if (!have_elem) {
	    /* This should happen only when we haven't parsed
	       the init element above for fear of committing a
	       string constant to memory too early.  */
	    if (tok != TOK_STR && tok != TOK_LSTR)
	      expect("string constant");
	    parse_init_elem(!sec ? EXPR_ANY : EXPR_CONST);
	}
        init_putv(type, sec, c);
    }
}

/* parse an initializer for type 't' if 'has_init' is non zero, and
   allocate space in local or global data space ('r' is either
   VT_LOCAL or VT_CONST). If 'v' is non zero, then an associated
   variable 'v' of scope 'scope' is declared before initializers
   are parsed. If 'v' is zero, then a reference to the new object
   is put in the value stack. If 'has_init' is 2, a special parsing
   is done to handle string constants. */
static void decl_initializer_alloc(CType *type, AttributeDef *ad, int r, 
                                   int has_init, int v, int scope)
{
    int size, align, addr;
    TokenString *init_str = NULL;

    Section *sec;
    Sym *flexible_array;
    Sym *sym = NULL;
    int saved_nocode_wanted = nocode_wanted;
#ifdef CONFIG_TCC_BCHECK
    int bcheck = tcc_state->do_bounds_check && !NODATA_WANTED;
#endif

    if (type->t & VT_STATIC)
        nocode_wanted |= NODATA_WANTED ? 0x40000000 : 0x80000000;

    flexible_array = NULL;
    if ((type->t & VT_BTYPE) == VT_STRUCT) {
        Sym *field = type->ref->next;
        if (field) {
            while (field->next)
                field = field->next;
            if (field->type.t & VT_ARRAY && field->type.ref->c < 0)
                flexible_array = field;
        }
    }

    size = type_size(type, &align);
    /* If unknown size, we must evaluate it before
       evaluating initializers because
       initializers can generate global data too
       (e.g. string pointers or ISOC99 compound
       literals). It also simplifies local
       initializers handling */
    if (size < 0 || (flexible_array && has_init)) {
        if (!has_init) 
            tcc_error("unknown type size");
        /* get all init string */
        if (has_init == 2) {
	    init_str = tok_str_alloc();
            /* only get strings */
            while (tok == TOK_STR || tok == TOK_LSTR) {
                tok_str_add_tok(init_str);
                next();
            }
	    tok_str_add(init_str, -1);
	    tok_str_add(init_str, 0);
        } else {
	    skip_or_save_block(&init_str);
        }
        unget_tok(0);

        /* compute size */
        begin_macro(init_str, 1);
        next();
        decl_initializer(type, NULL, 0, 1, 1);
        /* prepare second initializer parsing */
        macro_ptr = init_str->str;
        next();
        
        /* if still unknown size, error */
        size = type_size(type, &align);
        if (size < 0) 
            tcc_error("unknown type size");
    }
    /* If there's a flex member and it was used in the initializer
       adjust size.  */
    if (flexible_array &&
	flexible_array->type.ref->c > 0)
        size += flexible_array->type.ref->c
	        * pointed_size(&flexible_array->type);
    /* take into account specified alignment if bigger */
    if (ad->a.aligned) {
	int speca = 1 << (ad->a.aligned - 1);
        if (speca > align)
            align = speca;
    } else if (ad->a.packed) {
        align = 1;
    }

    if (NODATA_WANTED)
        size = 0, align = 1;

    if ((r & VT_VALMASK) == VT_LOCAL) {
        sec = NULL;
#ifdef CONFIG_TCC_BCHECK
        if (bcheck && (type->t & VT_ARRAY)) {
            loc--;
        }
#endif
        loc = (loc - size) & -align;
        addr = loc;
#ifdef CONFIG_TCC_BCHECK
        /* handles bounds */
        /* XXX: currently, since we do only one pass, we cannot track
           '&' operators, so we add only arrays */
        if (bcheck && (type->t & VT_ARRAY)) {
            addr_t *bounds_ptr;
            /* add padding between regions */
            loc--;
            /* then add local bound info */
            bounds_ptr = section_ptr_add(lbounds_section, 2 * sizeof(addr_t));
            bounds_ptr[0] = addr;
            bounds_ptr[1] = size;
        }
#endif
        if (v) {
            /* local variable */
#ifdef CONFIG_TCC_ASM
	    if (ad->asm_label) {
		int reg = asm_parse_regvar(ad->asm_label);
		if (reg >= 0)
		    r = (r & ~VT_VALMASK) | reg;
	    }
#endif
            sym = sym_push(v, type, r, addr);
            sym->a = ad->a;
        } else {
            /* push local reference */
            vset(type, r, addr);
        }
    } else {
        if (v && scope == VT_CONST) {
            /* see if the symbol was already defined */
            sym = sym_find(v);
            if (sym) {
                patch_storage(sym, ad, type);
                /* we accept several definitions of the same global variable. */
                if (!has_init && sym->c && elfsym(sym)->st_shndx != SHN_UNDEF)
                    goto no_alloc;
            }
        }

        /* allocate symbol in corresponding section */
        sec = ad->section;
        if (!sec) {
            if (has_init)
                sec = data_section;
            else if (tcc_state->nocommon)
                sec = bss_section;
        }

        if (sec) {
	    addr = section_add(sec, size, align);
#ifdef CONFIG_TCC_BCHECK
            /* add padding if bound check */
            if (bcheck)
                section_add(sec, 1, 1);
#endif
        } else {
            addr = align; /* SHN_COMMON is special, symbol value is align */
	    sec = common_section;
        }

        if (v) {
            if (!sym) {
                sym = sym_push(v, type, r | VT_SYM, 0);
                patch_storage(sym, ad, NULL);
            }
            /* Local statics have a scope until now (for
               warnings), remove it here.  */
            sym->sym_scope = 0;
            /* update symbol definition */
	    put_extern_sym(sym, sec, addr, size);
        } else {
            /* push global reference */
            sym = get_sym_ref(type, sec, addr, size);
	    vpushsym(type, sym);
	    vtop->r |= r;
        }

#ifdef CONFIG_TCC_BCHECK
        /* handles bounds now because the symbol must be defined
           before for the relocation */
        if (bcheck) {
            addr_t *bounds_ptr;

            greloca(bounds_section, sym, bounds_section->data_offset, R_DATA_PTR, 0);
            /* then add global bound info */
            bounds_ptr = section_ptr_add(bounds_section, 2 * sizeof(addr_t));
            bounds_ptr[0] = 0; /* relocated */
            bounds_ptr[1] = size;
        }
#endif
    }

    if (type->t & VT_VLA) {
        int a;

        if (NODATA_WANTED)
            goto no_alloc;

        /* save current stack pointer */
        if (vlas_in_scope == 0) {
            if (vla_sp_root_loc == -1)
                vla_sp_root_loc = (loc -= PTR_SIZE);
            gen_vla_sp_save(vla_sp_root_loc);
        }

        vla_runtime_type_size(type, &a);
        gen_vla_alloc(type, a);
#if defined TCC_TARGET_PE && defined TCC_TARGET_X86_64
        /* on _WIN64, because of the function args scratch area, the
           result of alloca differs from RSP and is returned in RAX.  */
        gen_vla_result(addr), addr = (loc -= PTR_SIZE);
#endif
        gen_vla_sp_save(addr);
        vla_sp_loc = addr;
        vlas_in_scope++;

    } else if (has_init) {
	size_t oldreloc_offset = 0;
	if (sec && sec->reloc)
	  oldreloc_offset = sec->reloc->data_offset;
        decl_initializer(type, sec, addr, 1, 0);
	if (sec && sec->reloc)
	  squeeze_multi_relocs(sec, oldreloc_offset);
        /* patch flexible array member size back to -1, */
        /* for possible subsequent similar declarations */
        if (flexible_array)
            flexible_array->type.ref->c = -1;
    }

 no_alloc:
    /* restore parse state if needed */
    if (init_str) {
        end_macro();
        next();
    }

    nocode_wanted = saved_nocode_wanted;
}

/* parse a function defined by symbol 'sym' and generate its code in
   'cur_text_section' */
static void gen_function(Sym *sym)
{
    nocode_wanted = 0;
    ind = cur_text_section->data_offset;
    /* NOTE: we patch the symbol size later */
    put_extern_sym(sym, cur_text_section, ind, 0);
    funcname = get_tok_str(sym->v, NULL);
    func_ind = ind;
    /* Initialize VLA state */
    vla_sp_loc = -1;
    vla_sp_root_loc = -1;
    /* put debug symbol */
    tcc_debug_funcstart(tcc_state, sym);
    /* push a dummy symbol to enable local sym storage */
    sym_push2(&local_stack, SYM_FIELD, 0, 0);
    local_scope = 1; /* for function parameters */
    gfunc_prolog(&sym->type);
    local_scope = 0;
    rsym = 0;
    block(NULL, NULL, 0);
    nocode_wanted = 0;
    gsym(rsym);
    gfunc_epilog();
    cur_text_section->data_offset = ind;
    label_pop(&global_label_stack, NULL, 0);
    /* reset local stack */
    local_scope = 0;
    sym_pop(&local_stack, NULL, 0);
    /* end of function */
    /* patch symbol size */
    elfsym(sym)->st_size = ind - func_ind;
    tcc_debug_funcend(tcc_state, ind - func_ind);
    /* It's better to crash than to generate wrong code */
    cur_text_section = NULL;
    funcname = ""; /* for safety */
    func_vt.t = VT_VOID; /* for safety */
    func_var = 0; /* for safety */
    ind = 0; /* for safety */
    nocode_wanted = 0x80000000;
    check_vstack();
}

static void gen_inline_functions(TCCState *s)
{
    Sym *sym;
    int inline_generated, i, ln;
    struct InlineFunc *fn;

    ln = file->line_num;
    /* iterate while inline function are referenced */
    do {
        inline_generated = 0;
        for (i = 0; i < s->nb_inline_fns; ++i) {
            fn = s->inline_fns[i];
            sym = fn->sym;
            if (sym && sym->c) {
                /* the function was used: generate its code and
                   convert it to a normal function */
                fn->sym = NULL;
                if (file)
                    pstrcpy(file->filename, sizeof file->filename, fn->filename);
                sym->type.t &= ~VT_INLINE;

                begin_macro(fn->func_str, 1);
                next();
                cur_text_section = text_section;
                gen_function(sym);
                end_macro();

                inline_generated = 1;
            }
        }
    } while (inline_generated);
    file->line_num = ln;
}

ST_FUNC void free_inline_functions(TCCState *s)
{
    int i;
    /* free tokens of unused inline functions */
    for (i = 0; i < s->nb_inline_fns; ++i) {
        struct InlineFunc *fn = s->inline_fns[i];
        if (fn->sym)
            tok_str_free(fn->func_str);
    }
    dynarray_reset(&s->inline_fns, &s->nb_inline_fns);
}

/* 'l' is VT_LOCAL or VT_CONST to define default storage type, or VT_CMP
   if parsing old style parameter decl list (and FUNC_SYM is set then) */
int decl0(int l, int is_for_loop_init, Sym *func_sym)
{
    int v, has_init, r;
    CType type, btype;
    Sym *sym;
    AttributeDef ad;

    while (1) {
        if (!parse_btype(&btype, &ad)) {
            if (is_for_loop_init)
                return 0;
            /* skip redundant ';' if not in old parameter decl scope */
            if (tok == ';' && l != VT_CMP) {
                next();
                continue;
            }
            if (l != VT_CONST)
                break;
            if (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3) {
                /* global asm block */
                asm_global_instr();
                continue;
            }
            if (tok >= TOK_UIDENT) {
               /* special test for old K&R protos without explicit int
                  type. Only accepted when defining global data */
                btype.t = VT_INT;
            } else {
                if (tok != TOK_EOF)
                    expect("declaration");
                break;
            }
        }
        if (tok == ';') {
	    if ((btype.t & VT_BTYPE) == VT_STRUCT) {
		int v = btype.ref->v;
		if (!(v & SYM_FIELD) && (v & ~SYM_STRUCT) >= SYM_FIRST_ANOM)
        	    tcc_warning("unnamed struct/union that defines no instances");
                next();
                continue;
	    }
            if (IS_ENUM(btype.t)) {
                next();
                continue;
            }
        }
        while (1) { /* iterate thru each declaration */
            type = btype;
	    /* If the base type itself was an array type of unspecified
	       size (like in 'typedef int arr[]; arr x = {1};') then
	       we will overwrite the unknown size by the real one for
	       this decl.  We need to unshare the ref symbol holding
	       that size.  */
	    if ((type.t & VT_ARRAY) && type.ref->c < 0) {
		type.ref = sym_push(SYM_FIELD, &type.ref->type, 0, type.ref->c);
	    }
            type_decl(&type, &ad, &v, TYPE_DIRECT);
#if 0
            {
                char buf[500];
                type_to_str(buf, sizeof(buf), &type, get_tok_str(v, NULL));
                printf("type = '%s'\n", buf);
            }
#endif
            if ((type.t & VT_BTYPE) == VT_FUNC) {
                if ((type.t & VT_STATIC) && (l == VT_LOCAL)) {
                    tcc_error("function without file scope cannot be static");
                }
                /* if old style function prototype, we accept a
                   declaration list */
                sym = type.ref;
                if (sym->f.func_type == FUNC_OLD && l == VT_CONST)
                    decl0(VT_CMP, 0, sym);
            }

            if (gnu_ext && (tok == TOK_ASM1 || tok == TOK_ASM2 || tok == TOK_ASM3)) {
                ad.asm_label = asm_label_instr();
                /* parse one last attribute list, after asm label */
                parse_attribute(&ad);
                if (tok == '{')
                    expect(";");
            }

#ifdef TCC_TARGET_PE
            if (ad.a.dllimport || ad.a.dllexport) {
                if (type.t & (VT_STATIC|VT_TYPEDEF))
                    tcc_error("cannot have dll linkage with static or typedef");
                if (ad.a.dllimport) {
                    if ((type.t & VT_BTYPE) == VT_FUNC)
                        ad.a.dllimport = 0;
                    else
                        type.t |= VT_EXTERN;
                }
            }
#endif
            if (tok == '{') {
                if (l != VT_CONST)
                    tcc_error("cannot use local functions");
                if ((type.t & VT_BTYPE) != VT_FUNC)
                    expect("function definition");

                /* reject abstract declarators in function definition
		   make old style params without decl have int type */
                sym = type.ref;
                while ((sym = sym->next) != NULL) {
                    if (!(sym->v & ~SYM_FIELD))
                        expect("identifier");
		    if (sym->type.t == VT_VOID)
		        sym->type = int_type;
		}
                
                /* XXX: cannot do better now: convert extern line to static inline */
                if ((type.t & (VT_EXTERN | VT_INLINE)) == (VT_EXTERN | VT_INLINE))
                    type.t = (type.t & ~VT_EXTERN) | VT_STATIC;

                /* put function symbol */
                sym = external_global_sym(v, &type, 0);
                type.t &= ~VT_EXTERN;
                patch_storage(sym, &ad, &type);

                /* static inline functions are just recorded as a kind
                   of macro. Their code will be emitted at the end of
                   the compilation unit only if they are used */
                if ((type.t & (VT_INLINE | VT_STATIC)) == 
                    (VT_INLINE | VT_STATIC)) {
                    struct InlineFunc *fn;
                    const char *filename;
                           
                    filename = file ? file->filename : "";
                    fn = tcc_malloc(sizeof *fn + strlen(filename));
                    strcpy(fn->filename, filename);
                    fn->sym = sym;
		    skip_or_save_block(&fn->func_str);
                    dynarray_add(&tcc_state->inline_fns,
				 &tcc_state->nb_inline_fns, fn);
                } else {
                    /* compute text section */
                    cur_text_section = ad.section;
                    if (!cur_text_section)
                        cur_text_section = text_section;
                    gen_function(sym);
                }
                break;
            } else {
		if (l == VT_CMP) {
		    /* find parameter in function parameter list */
		    for (sym = func_sym->next; sym; sym = sym->next)
			if ((sym->v & ~SYM_FIELD) == v)
			    goto found;
		    tcc_error("declaration for parameter '%s' but no such parameter",
			      get_tok_str(v, NULL));
found:
		    if (type.t & VT_STORAGE) /* 'register' is okay */
		        tcc_error("storage class specified for '%s'",
				  get_tok_str(v, NULL));
		    if (sym->type.t != VT_VOID)
		        tcc_error("redefinition of parameter '%s'",
				  get_tok_str(v, NULL));
		    convert_parameter_type(&type);
		    sym->type = type;
		} else if (type.t & VT_TYPEDEF) {
                    /* save typedefed type  */
                    /* XXX: test storage specifiers ? */
                    sym = sym_find(v);
                    if (sym && sym->sym_scope == local_scope) {
                        if (!is_compatible_types(&sym->type, &type)
                            || !(sym->type.t & VT_TYPEDEF))
                            tcc_error("incompatible redefinition of '%s'",
                                get_tok_str(v, NULL));
                        sym->type = type;
                    } else {
                        sym = sym_push(v, &type, 0, 0);
                    }
                    sym->a = ad.a;
                    sym->f = ad.f;
                } else {
                    r = 0;
                    if ((type.t & VT_BTYPE) == VT_FUNC) {
                        /* external function definition */
                        /* specific case for func_call attribute */
                        type.ref->f = ad.f;
                    } else if (!(type.t & VT_ARRAY)) {
                        /* not lvalue if array */
                        r |= lvalue_type(type.t);
                    }
                    has_init = (tok == '=');
                    if (has_init && (type.t & VT_VLA))
                        tcc_error("variable length array cannot be initialized");
                    if (((type.t & VT_EXTERN) && (!has_init || l != VT_CONST)) ||
			((type.t & VT_BTYPE) == VT_FUNC) ||
                        ((type.t & VT_ARRAY) && (type.t & VT_STATIC) &&
                         !has_init && l == VT_CONST && type.ref->c < 0)) {
                        /* external variable or function */
                        /* NOTE: as GCC, uninitialized global static
                           arrays of null size are considered as
                           extern */
                        type.t |= VT_EXTERN;
                        sym = external_sym(v, &type, r, &ad);
                        if (ad.alias_target) {
                            ElfSym *esym;
                            Sym *alias_target;
                            alias_target = sym_find(ad.alias_target);
                            esym = elfsym(alias_target);
                            if (!esym)
                                tcc_error("unsupported forward __alias__ attribute");
                            /* Local statics have a scope until now (for
                               warnings), remove it here.  */
                            sym->sym_scope = 0;
                            put_extern_sym2(sym, esym->st_shndx, esym->st_value, esym->st_size, 0);
                        }
                    } else {
                        if (type.t & VT_STATIC)
                            r |= VT_CONST;
                        else
                            r |= l;
                        if (has_init)
                            next();
                        else if (l == VT_CONST)
                            /* uninitialized global variables may be overridden */
                            type.t |= VT_EXTERN;
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
            ad.a.aligned = 0;
        }
    }
    return 0;
}

/* ------------------------------------------------------------------------- */
