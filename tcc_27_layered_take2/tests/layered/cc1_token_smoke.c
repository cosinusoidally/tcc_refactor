int cc0_init();
int cc1_tokenize();
int cc1_token_peek();
int cc1_token_consume();
int cc1_preprocess();
int cc1_preprocessed_peek();
int cc1_types_init();
int cc1_symbols_init();
int cc1_type_pointer();
int cc1_type_array();
int cc1_symbol_define();
int cc1_symbol_lookup();
int cc1_scope_push();
int cc1_scope_pop();
int ri32();

extern int CC1_TOKEN_KIND_OFFSET;
extern int CC1_TOKEN_NUMBER_OFFSET;
extern int CC1_TOKEN_FILE_OFFSET;
extern int CC1_TOKEN_LINE_OFFSET;
extern int CC1_TOKEN_COLUMN_OFFSET;
extern int CC1_TYPE_SIZE_OFFSET;
extern int CC1_INT_TYPE;
extern int CC1_SYMBOL_TYPE_OFFSET;

int main()
{
    char source[] =
        "var first;\n"
        "/* layout belongs to the following token */\n"
        "function second() { return 42; }\n";
    char file[] = "token-smoke.c";
    char macro_source[] =
        "#define VALUE 42\n"
        "#ifdef VALUE\n"
        "#define ANSWER VALUE\n"
        "#else\n"
        "#define ANSWER 0\n"
        "#endif\n"
        "function answer() { return ANSWER; }\n";
    int token;
    int index;
    int found_number;
    int pointer_type;
    int array_type;
    int global_symbol;
    int local_symbol;

    cc0_init();
    if (cc1_tokenize((int)source, sizeof(source) - 1, (int)file)) {
        return 1;
    }
    token = cc1_token_peek(0);
    if (!token || ri32(token + CC1_TOKEN_KIND_OFFSET) != 6) {
        return 2;
    }
    if (ri32(token + CC1_TOKEN_LINE_OFFSET) != 1 ||
        ri32(token + CC1_TOKEN_COLUMN_OFFSET) != 1) {
        return 3;
    }
    token = cc1_token_peek(3);
    if (!token || ri32(token + CC1_TOKEN_KIND_OFFSET) != 5) {
        return 4;
    }
    if (ri32(token + CC1_TOKEN_FILE_OFFSET) != (int)file ||
        ri32(token + CC1_TOKEN_LINE_OFFSET) != 3 ||
        ri32(token + CC1_TOKEN_COLUMN_OFFSET) != 1) {
        return 5;
    }
    token = cc1_token_peek(0);
    if (cc1_token_consume() != token || cc1_token_peek(0) == token) {
        return 6;
    }
    if (!cc1_token_peek(8)) {
        return 7;
    }
    if (cc1_preprocess((int)macro_source, sizeof(macro_source) - 1,
        (int)file)) {
        return 8;
    }
    index = 0;
    found_number = 0;
    while ((token = cc1_preprocessed_peek(index)) != 0) {
        if (ri32(token + CC1_TOKEN_KIND_OFFSET) == 3 &&
            ri32(token + CC1_TOKEN_NUMBER_OFFSET) == 42) {
            found_number = 1;
        }
        index++;
    }
    if (!found_number) {
        return 9;
    }
    if (cc1_types_init() || cc1_symbols_init()) {
        return 10;
    }
    pointer_type = cc1_type_pointer(CC1_INT_TYPE);
    array_type = cc1_type_array(CC1_INT_TYPE, 3);
    if (!pointer_type || !array_type ||
        ri32(array_type + CC1_TYPE_SIZE_OFFSET) != 12) {
        return 11;
    }
    global_symbol = cc1_symbol_define((int)file, 5, CC1_INT_TYPE, 0);
    if (!global_symbol || cc1_scope_push()) {
        return 12;
    }
    local_symbol = cc1_symbol_define((int)file, 5, pointer_type, 0);
    if (!local_symbol || cc1_symbol_lookup((int)file, 5) != local_symbol) {
        return 13;
    }
    if (ri32(local_symbol + CC1_SYMBOL_TYPE_OFFSET) != pointer_type) {
        return 14;
    }
    if (cc1_scope_pop() || cc1_symbol_lookup((int)file, 5) != global_symbol) {
        return 15;
    }
    return 0;
}
