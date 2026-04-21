/*
 * cc3: parser helpers split from historical tccgen.c.
 *
 * This file is included after tcc.h and before tccgen.c. The helpers here are
 * deliberately small while the real TCC parser is migrated into layers.
 */

static int cc3_tccgen_is_cc0_type_token(int token)
{
    const char *name;

    if (!tcc_state->cc0_dialect)
        return 0;
    if (token < TOK_IDENT)
        return 0;
    if (token >= tok_ident)
        return 0;
    name = get_tok_str(token, NULL);
    return cc0_is_dialect_type_chars(name[0], name[1], name[2], name[3],
                                     name[4], name[5], name[6], name[7],
                                     name[8]);
}

static int cc3_tccgen_is_assignment_token(int token)
{
    if (token == '=')
        return 1;
    if (token >= TOK_A_MOD)
        if (token <= TOK_A_DIV)
            return 1;
    if (token == TOK_A_XOR)
        return 1;
    if (token == TOK_A_OR)
        return 1;
    if (token == TOK_A_SHL)
        return 1;
    if (token == TOK_A_SAR)
        return 1;
    return 0;
}

static int cc3_tccgen_is_shift_token(int token)
{
    if (token == TOK_SHL)
        return 1;
    if (token == TOK_SAR)
        return 1;
    return 0;
}

static int cc3_tccgen_is_compare_token(int token)
{
    if (token >= TOK_ULE)
        if (token <= TOK_GT)
            return 1;
    if (token == TOK_ULT)
        return 1;
    if (token == TOK_UGE)
        return 1;
    return 0;
}

static int cc3_tccgen_is_equality_token(int token)
{
    if (token == TOK_EQ)
        return 1;
    if (token == TOK_NE)
        return 1;
    return 0;
}

static int cc3_tccgen_assignment_base_token(int token)
{
    if (token == '=')
        return token;
    return token & 0x7f;
}

ST_FUNC void expr_prod(void)
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

ST_FUNC void expr_sum(void)
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
    while (cc3_tccgen_is_shift_token(tok)) {
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
    while (cc3_tccgen_is_compare_token(tok)) {
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
    while (cc3_tccgen_is_equality_token(tok)) {
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
