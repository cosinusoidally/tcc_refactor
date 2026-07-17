/* Temporary scalar storage bindings used until cc2 builds the typed bridge. */
var CC2_BOOT_STATE_SLOT;
var CC2_BOOT_STATE_COUNT_SLOT;
var CC2_BOOT_STORAGE_READY;
var CC2_BOOT_TOKEN_PAIRS;
var CC2_BOOT_TOKEN_PAIR_POSITION;
var CC2_BOOT_KEYWORDS;
var CC2_BOOT_KEYWORD_POSITION;
var CC2_BOOT_VALUE_STACK;
var CC2_BOOT_TOKEN_STRING_BYTES;
var CC2_BOOT_FIRST_DYNAMIC_IDENTIFIER;

function cc2_storage_init()
{
    CC2_BOOT_STATE_SLOT = 0;
    CC2_BOOT_STATE_COUNT_SLOT = 0;
    CC2_BOOT_STORAGE_READY = 0;
    CC2_BOOT_TOKEN_PAIRS = 0;
    CC2_BOOT_TOKEN_PAIR_POSITION = 0;
    CC2_BOOT_KEYWORDS = 0;
    CC2_BOOT_KEYWORD_POSITION = 0;
    CC2_BOOT_VALUE_STACK = 0;
    /* TokenString has eight i386 words followed by its allocation byte. */
    CC2_BOOT_TOKEN_STRING_BYTES = 36;
    /* i386 assembler tokens occupy the reserved range below this token. */
    CC2_BOOT_FIRST_DYNAMIC_IDENTIFIER = 1152;
    return 0;
}

function cc2_boot_slot()
{
    return calloc(1, 4);
}

function cc2_boot_add_token_pair(first, second, token)
{
    wi8(add(CC2_BOOT_TOKEN_PAIRS, CC2_BOOT_TOKEN_PAIR_POSITION), first);
    CC2_BOOT_TOKEN_PAIR_POSITION = add(CC2_BOOT_TOKEN_PAIR_POSITION, 1);
    wi8(add(CC2_BOOT_TOKEN_PAIRS, CC2_BOOT_TOKEN_PAIR_POSITION), second);
    CC2_BOOT_TOKEN_PAIR_POSITION = add(CC2_BOOT_TOKEN_PAIR_POSITION, 1);
    wi8(add(CC2_BOOT_TOKEN_PAIRS, CC2_BOOT_TOKEN_PAIR_POSITION), token);
    CC2_BOOT_TOKEN_PAIR_POSITION = add(CC2_BOOT_TOKEN_PAIR_POSITION, 1);
    return 0;
}

function cc2_boot_init_token_pairs()
{
    CC2_BOOT_TOKEN_PAIRS = calloc(1, 73);
    CC2_BOOT_TOKEN_PAIR_POSITION = 0;
    cc2_boot_add_token_pair(mkC("<"), mkC("="), CC2_TOKEN_LESS_EQUAL);
    cc2_boot_add_token_pair(mkC(">"), mkC("="), CC2_TOKEN_GREATER_EQUAL);
    cc2_boot_add_token_pair(mkC("!"), mkC("="), CC2_TOKEN_NOT_EQUAL);
    cc2_boot_add_token_pair(mkC("&"), mkC("&"), CC2_TOKEN_LOGICAL_AND);
    cc2_boot_add_token_pair(mkC("|"), mkC("|"), CC2_TOKEN_LOGICAL_OR);
    cc2_boot_add_token_pair(mkC("+"), mkC("+"), CC2_TOKEN_INCREMENT);
    cc2_boot_add_token_pair(mkC("-"), mkC("-"), CC2_TOKEN_DECREMENT);
    cc2_boot_add_token_pair(mkC("="), mkC("="), CC2_TOKEN_EQUAL);
    cc2_boot_add_token_pair(mkC("<"), mkC("<"), CC2_TOKEN_SHIFT_LEFT);
    cc2_boot_add_token_pair(mkC(">"), mkC(">"), CC2_TOKEN_SHIFT_RIGHT);
    cc2_boot_add_token_pair(mkC("+"), mkC("="), CC2_ASSIGNMENT_ADD);
    cc2_boot_add_token_pair(mkC("-"), mkC("="), CC2_ASSIGNMENT_SUBTRACT);
    cc2_boot_add_token_pair(mkC("*"), mkC("="), CC2_ASSIGNMENT_MULTIPLY);
    cc2_boot_add_token_pair(mkC("/"), mkC("="), CC2_ASSIGNMENT_DIVIDE);
    cc2_boot_add_token_pair(mkC("%"), mkC("="), CC2_ASSIGNMENT_MODULO);
    cc2_boot_add_token_pair(mkC("&"), mkC("="), CC2_ASSIGNMENT_AND);
    cc2_boot_add_token_pair(mkC("^"), mkC("="), CC2_ASSIGNMENT_XOR);
    cc2_boot_add_token_pair(mkC("|"), mkC("="), CC2_ASSIGNMENT_OR);
    cc2_boot_add_token_pair(mkC("-"), mkC(">"), CC2_TOKEN_ARROW);
    cc2_boot_add_token_pair(mkC("."), mkC("."), 168);
    cc2_boot_add_token_pair(mkC("#"), mkC("#"), CC2_TOKEN_TWO_SHARPS);
    wi8(add(CC2_BOOT_TOKEN_PAIRS, CC2_BOOT_TOKEN_PAIR_POSITION), 0);
    tok_two_chars_address = CC2_BOOT_TOKEN_PAIRS;
    return 0;
}

function cc2_boot_bind_preprocessor_state()
{
    if (CC2_BOOT_STORAGE_READY) {
        return 0;
    }
    CC2_BOOT_STORAGE_READY = 1;
    define_stack_address = cc2_boot_slot();
    file_address = cc2_boot_slot();
    parse_flags_address = cc2_boot_slot();
    tok_address = cc2_boot_slot();
    tokc_address = calloc(1, 12);
    gnu_ext_address = cc2_boot_slot();
    tcc_ext_address = cc2_boot_slot();
    wi32(gnu_ext_address, 1);
    wi32(tcc_ext_address, 1);
    tokstr_buf_address = calloc(1, CC2_BOOT_TOKEN_STRING_BYTES);
    isidnum_table_address = calloc(1, 257);
    pp_debug_tok_address = cc2_boot_slot();
    pp_debug_symv_address = cc2_boot_slot();
    pp_once_address = cc2_boot_slot();
    tok_flags_address = cc2_boot_slot();
    total_lines_address = cc2_boot_slot();
    tokcstr_address = calloc(1, 12);
    hash_ident_address = calloc(1, mul(CC2_TOKEN_HASH_BUCKETS, 4));
    cstr_buf_address = calloc(1, 12);
    cc2_boot_init_token_pairs();
    return 0;
}

function cc2_bind_tcc_globals(state)
{
    if (eq(symtab_section_address, 0)) {
        symtab_section_address = cc2_boot_slot();
        data_section_address = cc2_boot_slot();
        cur_text_section_address = cc2_boot_slot();
        bss_section_address = cc2_boot_slot();
        common_section_address = cc2_boot_slot();
        text_section_address = cc2_boot_slot();
        last_text_section_address = cc2_boot_slot();
        stab_section_address = cc2_boot_slot();
        stabstr_section_address = cc2_boot_slot();
    }
    tcc_state_address = state;
    return 0;
}

function elfsym(symbol)
{
    var index;
    var section;
    if (eq(symbol, 0)) {
        return 0;
    }
    index = ri32(add(symbol, CC2_SYM_CONSTANT_OFFSET));
    if (eq(index, 0)) {
        return 0;
    }
    section = ri32(symtab_section_address);
    return add(ri32(add(section, CC2_SECTION_DATA_POINTER_OFFSET)),
        mul(index, CC2_ELF_SYMBOL_BYTES));
}

/* Parse an unsigned 64-bit integer using four little-endian 16-bit limbs. */
function u64_mul_add(words, base, digit)
{
    var low;
    var high;
    var limb0;
    var limb1;
    var limb2;
    var limb3;
    var carry;
    var next_low;
    var next_high;
    var overflow;
    low = ri32(words);
    high = ri32(add(words, CC2_I386_WORD_BYTES));
    limb0 = add(mul(and(low, 65535), base), digit);
    limb1 = add(mul(ushr(low, 16), base), ushr(limb0, 16));
    limb2 = add(mul(and(high, 65535), base), ushr(limb1, 16));
    limb3 = add(mul(ushr(high, 16), base), ushr(limb2, 16));
    overflow = not(eq(ushr(limb3, 16), 0));
    next_low = or(and(limb0, 65535), shl(limb1, 16));
    next_high = or(and(limb2, 65535), shl(limb3, 16));
    wi32(words, next_low);
    wi32(add(words, CC2_I386_WORD_BYTES), next_high);
    return overflow;
}

function u64_ge(words, low, high)
{
    var value_low;
    var value_high;
    value_low = ri32(words);
    value_high = ri32(add(words, CC2_I386_WORD_BYTES));
    if (not(eq(value_high, high))) {
        return not(cc2_u32_less(value_high, high));
    }
    return not(cc2_u32_less(value_low, low));
}

function vpush64_words(type, low_word, high_word)
{
    var type_record;
    var constant;
    type_record = calloc(1, 8);
    constant = calloc(1, 12);
    wi32(type_record, type);
    wi32(constant, low_word);
    wi32(add(constant, CC2_I386_WORD_BYTES), high_word);
    vsetc(type_record, CC2_VALUE_CONSTANT, constant);
    free(constant);
    free(type_record);
    return 0;
}

function cc2_bind_preprocess_types(state)
{
    if (eq(CC2_BOOT_VALUE_STACK, 0)) {
        CC2_BOOT_VALUE_STACK = calloc(257, 28);
        int_type_address = calloc(1, 8);
        size_type_address = calloc(1, 8);
        func_old_type_address = calloc(1, 8);
        char_pointer_type_address = calloc(1, 8);
        ptrdiff_type_address = calloc(1, 8);
    }
    vstack_base = add(CC2_BOOT_VALUE_STACK, 28);
    vtop = CC2_BOOT_VALUE_STACK;
    pvtop = vtop;
    if (eq(func_vt_address, 0)) {
        func_vt_address = calloc(1, 8);
        local_stack_address = cc2_boot_slot();
        global_label_stack_address = cc2_boot_slot();
        local_label_stack_address = cc2_boot_slot();
    }
    return cc2_bind_tcc_globals(state);
}

function cc2_tcc_state_slot()
{
    if (eq(CC2_BOOT_STATE_SLOT, 0)) {
        CC2_BOOT_STATE_SLOT = cc2_boot_slot();
    }
    return CC2_BOOT_STATE_SLOT;
}

function cc2_tcc_state_count_slot()
{
    if (eq(CC2_BOOT_STATE_COUNT_SLOT, 0)) {
        CC2_BOOT_STATE_COUNT_SLOT = cc2_boot_slot();
    }
    return CC2_BOOT_STATE_COUNT_SLOT;
}

function cc2_boot_add_keyword(text)
{
    var character;
    character = ri8(text);
    while (character) {
        wi8(add(CC2_BOOT_KEYWORDS, CC2_BOOT_KEYWORD_POSITION), character);
        CC2_BOOT_KEYWORD_POSITION = add(CC2_BOOT_KEYWORD_POSITION, 1);
        text = add(text, 1);
        character = ri8(text);
    }
    wi8(add(CC2_BOOT_KEYWORDS, CC2_BOOT_KEYWORD_POSITION), 0);
    CC2_BOOT_KEYWORD_POSITION = add(CC2_BOOT_KEYWORD_POSITION, 1);
    return 0;
}

function cc2_boot_add_keyword_parts(first, second)
{
    var character;
    character = ri8(first);
    while (character) {
        wi8(add(CC2_BOOT_KEYWORDS, CC2_BOOT_KEYWORD_POSITION), character);
        CC2_BOOT_KEYWORD_POSITION = add(CC2_BOOT_KEYWORD_POSITION, 1);
        first = add(first, 1);
        character = ri8(first);
    }
    return cc2_boot_add_keyword(second);
}

function cc2_boot_init_keywords()
{
    CC2_BOOT_KEYWORDS = calloc(1, 4096);
    CC2_BOOT_KEYWORD_POSITION = 0;
    cc2_boot_add_keyword(mks("int"));
    cc2_boot_add_keyword(mks("void"));
    cc2_boot_add_keyword(mks("char"));
    cc2_boot_add_keyword(mks("if"));
    cc2_boot_add_keyword(mks("else"));
    cc2_boot_add_keyword(mks("while"));
    cc2_boot_add_keyword(mks("break"));
    cc2_boot_add_keyword(mks("return"));
    cc2_boot_add_keyword(mks("for"));
    cc2_boot_add_keyword(mks("extern"));
    cc2_boot_add_keyword(mks("static"));
    cc2_boot_add_keyword(mks("unsigned"));
    cc2_boot_add_keyword(mks("goto"));
    cc2_boot_add_keyword(mks("do"));
    cc2_boot_add_keyword(mks("continue"));
    cc2_boot_add_keyword(mks("switch"));
    cc2_boot_add_keyword(mks("case"));
    cc2_boot_add_keyword(mks("const"));
    cc2_boot_add_keyword(mks("__const"));
    cc2_boot_add_keyword(mks("__const__"));
    cc2_boot_add_keyword(mks("volatile"));
    cc2_boot_add_keyword(mks("__volatile"));
    cc2_boot_add_keyword(mks("__volatile__"));
    cc2_boot_add_keyword(mks("long"));
    cc2_boot_add_keyword(mks("register"));
    cc2_boot_add_keyword(mks("signed"));
    cc2_boot_add_keyword(mks("__signed"));
    cc2_boot_add_keyword(mks("__signed__"));
    cc2_boot_add_keyword(mks("auto"));
    cc2_boot_add_keyword(mks("inline"));
    cc2_boot_add_keyword(mks("__inline"));
    cc2_boot_add_keyword(mks("__inline__"));
    cc2_boot_add_keyword(mks("restrict"));
    cc2_boot_add_keyword(mks("__restrict"));
    cc2_boot_add_keyword(mks("__restrict__"));
    cc2_boot_add_keyword(mks("__extension__"));
    cc2_boot_add_keyword(mks("_Generic"));
    cc2_boot_add_keyword(mks("float"));
    cc2_boot_add_keyword(mks("double"));
    cc2_boot_add_keyword(mks("_Bool"));
    cc2_boot_add_keyword(mks("short"));
    cc2_boot_add_keyword(mks("struct"));
    cc2_boot_add_keyword(mks("union"));
    cc2_boot_add_keyword(mks("typedef"));
    cc2_boot_add_keyword(mks("default"));
    cc2_boot_add_keyword(mks("enum"));
    cc2_boot_add_keyword_parts(mks("size"), mks("of"));
    cc2_boot_add_keyword(mks("__attribute"));
    cc2_boot_add_keyword(mks("__attribute__"));
    cc2_boot_add_keyword(mks("__alignof"));
    cc2_boot_add_keyword(mks("__alignof__"));
    cc2_boot_add_keyword(mks("typeof"));
    cc2_boot_add_keyword(mks("__typeof"));
    cc2_boot_add_keyword(mks("__typeof__"));
    cc2_boot_add_keyword(mks("__label__"));
    cc2_boot_add_keyword(mks("asm"));
    cc2_boot_add_keyword(mks("__asm"));
    cc2_boot_add_keyword(mks("__asm__"));
    cc2_boot_add_keyword(mks("define"));
    cc2_boot_add_keyword(mks("include"));
    cc2_boot_add_keyword(mks("include_next"));
    cc2_boot_add_keyword(mks("ifdef"));
    cc2_boot_add_keyword(mks("ifndef"));
    cc2_boot_add_keyword(mks("elif"));
    cc2_boot_add_keyword(mks("endif"));
    cc2_boot_add_keyword(mks("defined"));
    cc2_boot_add_keyword(mks("undef"));
    cc2_boot_add_keyword(mks("error"));
    cc2_boot_add_keyword(mks("warning"));
    cc2_boot_add_keyword(mks("line"));
    cc2_boot_add_keyword(mks("pragma"));
    cc2_boot_add_keyword(mks("__LINE__"));
    cc2_boot_add_keyword(mks("__FILE__"));
    cc2_boot_add_keyword(mks("__DATE__"));
    cc2_boot_add_keyword(mks("__TIME__"));
    cc2_boot_add_keyword(mks("__FUNCTION__"));
    cc2_boot_add_keyword(mks("__VA_ARGS__"));
    cc2_boot_add_keyword(mks("__COUNTER__"));
    cc2_boot_add_keyword(mks("__func__"));
    cc2_boot_add_keyword(mks("__nan__"));
    cc2_boot_add_keyword(mks("__snan__"));
    cc2_boot_add_keyword(mks("__inf__"));
    cc2_boot_add_keyword(mks("section"));
    cc2_boot_add_keyword(mks("__section__"));
    cc2_boot_add_keyword(mks("aligned"));
    cc2_boot_add_keyword(mks("__aligned__"));
    cc2_boot_add_keyword(mks("packed"));
    cc2_boot_add_keyword(mks("__packed__"));
    cc2_boot_add_keyword(mks("weak"));
    cc2_boot_add_keyword(mks("__weak__"));
    cc2_boot_add_keyword(mks("alias"));
    cc2_boot_add_keyword(mks("__alias__"));
    cc2_boot_add_keyword(mks("unused"));
    cc2_boot_add_keyword(mks("__unused__"));
    cc2_boot_add_keyword(mks("cdecl"));
    cc2_boot_add_keyword(mks("__cdecl"));
    cc2_boot_add_keyword(mks("__cdecl__"));
    cc2_boot_add_keyword(mks("stdcall"));
    cc2_boot_add_keyword(mks("__stdcall"));
    cc2_boot_add_keyword(mks("__stdcall__"));
    cc2_boot_add_keyword(mks("fastcall"));
    cc2_boot_add_keyword(mks("__fastcall"));
    cc2_boot_add_keyword(mks("__fastcall__"));
    cc2_boot_add_keyword(mks("regparm"));
    cc2_boot_add_keyword(mks("__regparm__"));
    cc2_boot_add_keyword(mks("__mode__"));
    cc2_boot_add_keyword(mks("__QI__"));
    cc2_boot_add_keyword(mks("__DI__"));
    cc2_boot_add_keyword(mks("__HI__"));
    cc2_boot_add_keyword(mks("__SI__"));
    cc2_boot_add_keyword(mks("__word__"));
    cc2_boot_add_keyword(mks("dllexport"));
    cc2_boot_add_keyword(mks("dllimport"));
    cc2_boot_add_keyword(mks("noreturn"));
    cc2_boot_add_keyword(mks("__noreturn__"));
    cc2_boot_add_keyword(mks("visibility"));
    cc2_boot_add_keyword(mks("__visibility__"));
    cc2_boot_add_keyword(mks("__builtin_types_compatible_p"));
    cc2_boot_add_keyword(mks("__builtin_choose_expr"));
    cc2_boot_add_keyword(mks("__builtin_constant_p"));
    cc2_boot_add_keyword(mks("__builtin_frame_address"));
    cc2_boot_add_keyword(mks("__builtin_return_address"));
    cc2_boot_add_keyword(mks("__builtin_expect"));
    cc2_boot_add_keyword(mks("pack"));
    cc2_boot_add_keyword(mks("comment"));
    cc2_boot_add_keyword(mks("lib"));
    cc2_boot_add_keyword(mks("push_macro"));
    cc2_boot_add_keyword(mks("pop_macro"));
    cc2_boot_add_keyword(mks("once"));
    cc2_boot_add_keyword(mks("option"));
    cc2_boot_add_keyword(mks("memcpy"));
    cc2_boot_add_keyword(mks("memmove"));
    cc2_boot_add_keyword(mks("memset"));
    cc2_boot_add_keyword(mks("__divdi3"));
    cc2_boot_add_keyword(mks("__moddi3"));
    cc2_boot_add_keyword(mks("__udivdi3"));
    cc2_boot_add_keyword(mks("__umoddi3"));
    cc2_boot_add_keyword(mks("__ashrdi3"));
    cc2_boot_add_keyword(mks("__lshrdi3"));
    cc2_boot_add_keyword(mks("__ashldi3"));
    cc2_boot_add_keyword(mks("__floatundisf"));
    cc2_boot_add_keyword(mks("__floatundidf"));
    cc2_boot_add_keyword(mks("__floatundixf"));
    cc2_boot_add_keyword(mks("__fixunsxfdi"));
    cc2_boot_add_keyword(mks("__fixunssfdi"));
    cc2_boot_add_keyword(mks("__fixunsdfdi"));
    cc2_boot_add_keyword(mks("__fixsfdi"));
    cc2_boot_add_keyword(mks("__fixdfdi"));
    cc2_boot_add_keyword(mks("__fixxfdi"));
    cc2_boot_add_keyword(mks("alloca"));
    /* The bootstrap assembler needs only the auditable raw-byte directive. */
    cc2_boot_add_keyword(mks(".byte"));
    wi8(add(CC2_BOOT_KEYWORDS, CC2_BOOT_KEYWORD_POSITION), 0);
    return CC2_BOOT_KEYWORDS;
}

function cc2_tccpp_new_bridge(state)
{
    var used;
    var required;
    var capacity;
    cc2_boot_bind_preprocessor_state();
    cc2_tccpp_new(state, cc2_boot_init_keywords());
    used = sub(tok_ident, CC2_TOKEN_IDENTIFIER_BASE);
    required = sub(CC2_BOOT_FIRST_DYNAMIC_IDENTIFIER,
        CC2_TOKEN_IDENTIFIER_BASE);
    capacity = CC2_TOKEN_ALLOC_INCREMENT;
    while (not(lt(required, capacity))) {
        capacity = add(capacity, CC2_TOKEN_ALLOC_INCREMENT);
    }
    table_ident = tcc_realloc(table_ident,
        mul(capacity, CC2_I386_WORD_BYTES));
    memset(add(table_ident, mul(used, CC2_I386_WORD_BYTES)), 0,
        mul(sub(capacity, used), CC2_I386_WORD_BYTES));
    tok_ident = CC2_BOOT_FIRST_DYNAMIC_IDENTIFIER;
    return 0;
}

function cc2_preprocess_start_bridge(state, is_assembler)
{
    cc2_bind_preprocess_types(state);
    return cc2_preprocess_start(state, is_assembler);
}

function cc2_tcc_preprocess_bridge(state)
{
    return cc2_tcc_preprocess(state);
}

function cc2_error_scope(state, is_assembler, file_type)
{
    return cc2_compile_body(state, is_assembler, file_type);
}

function cc2_driver_bridge(argc, argv)
{
    return tcc_driver_main(argc, argv);
}
