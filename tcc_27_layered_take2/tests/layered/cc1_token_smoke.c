int cc0_init();
int cc1_tokenize();
int cc1_token_peek();
int cc1_token_consume();
int cc1_preprocess();
int cc1_preprocessed_peek();
int ri32();

extern int CC1_TOKEN_KIND_OFFSET;
extern int CC1_TOKEN_NUMBER_OFFSET;
extern int CC1_TOKEN_FILE_OFFSET;
extern int CC1_TOKEN_LINE_OFFSET;
extern int CC1_TOKEN_COLUMN_OFFSET;

int main()
{
    char source[] =
        "var first;\n"
        "/* layout belongs to the following token */\n"
        "function second() { return 42; }\n";
    char file[] = "token-smoke.c";
    char macro_source[] =
        "#define VALUE 42\n"
        "#define ANSWER VALUE\n"
        "function answer() { return ANSWER; }\n";
    int token;
    int index;
    int found_number;

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
    return 0;
}
