int cc0_init();
int cc1_tokenize();
int cc1_token_peek();
int cc1_token_consume();
int ri32();

extern int CC1_TOKEN_KIND_OFFSET;
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
    int token;

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
    return 0;
}
