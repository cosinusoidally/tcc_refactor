load("../tcc_27_layered/cc0.c");
load("../tcc_27_layered/cc0_support.js");

var cc0_test_string;
var cc0_test_cells;

if (cc0_add(2, 3) !== 5)
    throw new Error("cc0_add failed");

if (cc0_select(1, 7, 9) !== 7)
    throw new Error("cc0_select true branch failed");

if (cc0_select(0, 7, 9) !== 9)
    throw new Error("cc0_select false branch failed");

if (cc0_not(0) !== 1 || cc0_not(4) !== 0)
    throw new Error("cc0_not failed");

if (mkc('A') !== CC0_CH_A)
    throw new Error("cc0 mkc failed");

cc0_test_string = mks("Az");
if (cc0_heap_get(cc0_test_string, 0) !== CC0_CH_A ||
    cc0_heap_get(cc0_test_string, 1) !== CC0_CH_z ||
    cc0_heap_get(cc0_test_string, 2) !== CC0_CH_NUL)
    throw new Error("cc0 mks heap failed");

if (!cc0_heap_is_string(mks("var"), CC0_CH_v, CC0_CH_a, CC0_CH_r, CC0_CH_NUL))
    throw new Error("cc0 heap string check failed");

cc0_test_cells = cc0_cell_alloc(3);
if (cc0_cell_set(cc0_test_cells, 0, 12345) !== 12345 ||
    cc0_cell_set(cc0_test_cells, 1, 6789) !== 6789 ||
    cc0_cell_get(cc0_test_cells, 0) !== 12345 ||
    cc0_cell_get(cc0_test_cells, 1) !== 6789)
    throw new Error("cc0 cell heap failed");

if (!cc0_is_word_function_chars(mkc('f'), mkc('u'), mkc('n'), mkc('c'), mkc('t'), mkc('i'), mkc('o'), mkc('n'), 0) ||
    cc0_is_word_function_chars(mkc('f'), mkc('u'), mkc('n'), mkc('c'), mkc('t'), mkc('i'), mkc('o'), 0, 0))
    throw new Error("cc0 function word failed");

if (!cc0_is_word_var_chars(mkc('v'), mkc('a'), mkc('r'), 0) ||
    cc0_is_word_var_chars(mkc('v'), mkc('a'), mkc('r'), mkc('s')))
    throw new Error("cc0 var word failed");

if (!cc0_is_dialect_type_chars(mkc('f'), mkc('u'), mkc('n'), mkc('c'), mkc('t'), mkc('i'), mkc('o'), mkc('n'), 0) ||
    !cc0_is_dialect_type_chars(mkc('v'), mkc('a'), mkc('r'), 0, 0, 0, 0, 0, 0) ||
    cc0_is_dialect_type_chars(mkc('i'), mkc('n'), mkc('t'), 0, 0, 0, 0, 0, 0))
    throw new Error("cc0 type word failed");

if (!cc0_is_word_return_chars(mkc('r'), mkc('e'), mkc('t'), mkc('u'), mkc('r'), mkc('n'), 0) ||
    cc0_is_word_return_chars(mkc('r'), mkc('e'), mkc('t'), mkc('u'), mkc('r'), mkc('n'), mkc('s')))
    throw new Error("cc0 return word failed");

if (!cc0_is_word_if_chars(mkc('i'), mkc('f'), 0) ||
    cc0_is_word_if_chars(mkc('i'), mkc('f'), mkc('s')))
    throw new Error("cc0 if word failed");

if (!cc0_is_digit(48) || !cc0_is_digit(57) || cc0_is_digit(58))
    throw new Error("cc0_is_digit failed");

if (!cc0_is_oct_digit(48) || !cc0_is_oct_digit(55) || cc0_is_oct_digit(56))
    throw new Error("cc0_is_oct_digit failed");

if (!cc0_is_name_start(95) || !cc0_is_name_start(65))
    throw new Error("cc0_is_name_start failed");

if (cc0_to_upper(97) !== 65 || cc0_to_upper(65) !== 65 || cc0_to_upper(48) !== 48)
    throw new Error("cc0_to_upper failed");

if (!cc0_is_name_continue(57) || cc0_is_name_continue(45))
    throw new Error("cc0_is_name_continue failed");

if (!cc0_is_space(32) || !cc0_is_space(10) || !cc0_is_space(12) || cc0_is_space(65))
    throw new Error("cc0_is_space failed");

if (cc0_tccpp_char_flags(32) !== 1 || cc0_tccpp_char_flags(10) !== 0 || cc0_tccpp_char_flags(65) !== 2 || cc0_tccpp_char_flags(48) !== 4)
    throw new Error("cc0 tccpp char flags failed");

if (!cc0_tccpp_is_space(32) || cc0_tccpp_is_space(10) || cc0_tccpp_is_space(65))
    throw new Error("cc0 tccpp space failed");

if (cc0_token_class(-1) !== 0)
    throw new Error("cc0 eof token failed");

if (cc0_token_class(65) !== 1)
    throw new Error("cc0 name token failed");

if (cc0_token_class(52) !== 2)
    throw new Error("cc0 number token failed");

if (cc0_token_class(32) !== 3)
    throw new Error("cc0 space token failed");

if (cc0_token_class(43) !== 4)
    throw new Error("cc0 punct token failed");

if (cc0_token_class(33) !== 4)
    throw new Error("cc0 bang punct token failed");

if (cc0_token_class(45) !== 4 || cc0_token_class(60) !== 4 || cc0_token_class(62) !== 4)
    throw new Error("cc0 comparison punct token failed");

cc0_source_set8(32, 97, 98, 49, 32, 50, 51, -1);

if (cc0_scan_next() !== 1)
    throw new Error("cc0 scanner name class failed");

if (cc0_get_tok_start() !== 1 || cc0_get_tok_len() !== 3)
    throw new Error("cc0 scanner name span failed");

if (cc0_scan_next() !== 2)
    throw new Error("cc0 scanner number class failed");

if (cc0_get_tok_start() !== 5 || cc0_get_tok_len() !== 2)
    throw new Error("cc0 scanner number span failed");

if (cc0_get_tok_value() !== 23)
    throw new Error("cc0 scanner number value failed");

if (cc0_scan_next() !== 0)
    throw new Error("cc0 scanner eof failed");

cc0_source_set16(32, 32, 32, 32, 32, 32, 32, 32, 52, -1, -1, -1, -1, -1, -1, -1);

if (cc0_scan_next() !== 2)
    throw new Error("cc0 scanner 16-byte window class failed");

if (cc0_get_tok_start() !== 8 || cc0_get_tok_value() !== 4)
    throw new Error("cc0 scanner 16-byte window value failed");

cc0_source_set_string(mks("  abc1 23"));

if (cc0_scan_next() !== CC0_TOK_NAME)
    throw new Error("cc0 string scanner name class failed");

if (cc0_get_tok_start() !== 2 || cc0_get_tok_len() !== 4)
    throw new Error("cc0 string scanner name span failed");

if (cc0_scan_next() !== CC0_TOK_NUMBER)
    throw new Error("cc0 string scanner number class failed");

if (cc0_get_tok_value() !== 23)
    throw new Error("cc0 string scanner number value failed");

if (cc0_scan_next() !== CC0_TOK_EOF)
    throw new Error("cc0 string scanner eof failed");

cc0_source_set_string(mks("function var return if"));

if (cc0_scan_next() !== CC0_TOK_NAME || !cc0_tok_is_word_function())
    throw new Error("cc0 token function word failed");

if (cc0_scan_next() !== CC0_TOK_NAME || !cc0_tok_is_word_var())
    throw new Error("cc0 token var word failed");

if (cc0_scan_next() !== CC0_TOK_NAME || !cc0_tok_is_word_return())
    throw new Error("cc0 token return word failed");

if (cc0_scan_next() !== CC0_TOK_NAME || !cc0_tok_is_word_if())
    throw new Error("cc0 token if word failed");

cc0_source_set_string(mks("mkc('A') mks(\"Az\")"));

if (cc0_scan_next() !== CC0_TOK_NAME || !cc0_tok_is_word_mkc())
    throw new Error("cc0 token mkc word failed");

if (cc0_scan_next() !== CC0_TOK_PUNCT || cc0_scan_next() !== CC0_TOK_CHAR)
    throw new Error("cc0 char literal token failed");

if (cc0_get_tok_value() !== mkc('A'))
    throw new Error("cc0 char literal value failed");

if (cc0_scan_next() !== CC0_TOK_PUNCT || cc0_scan_next() !== CC0_TOK_NAME || !cc0_tok_is_word_mks())
    throw new Error("cc0 token mks word failed");

if (cc0_scan_next() !== CC0_TOK_PUNCT || cc0_scan_next() !== CC0_TOK_STRING)
    throw new Error("cc0 string literal token failed");

cc0_test_string = cc0_get_tok_value();
if (cc0_heap_get(cc0_test_string, 0) !== mkc('A') ||
    cc0_heap_get(cc0_test_string, 1) !== mkc('z') ||
    cc0_heap_get(cc0_test_string, 2) !== 0)
    throw new Error("cc0 string literal value failed");

if (cc0_scan_next() !== CC0_TOK_PUNCT || cc0_scan_next() !== CC0_TOK_EOF)
    throw new Error("cc0 wrapper literal eof failed");

load("../tcc_27_layered/cc1.c");
load("../tcc_27_layered/cc2.c");

if (cc1_compile_unit(0) !== 1)
    throw new Error("cc1 stub compile failed");

if (cc1_has_real_parser() !== 1)
    throw new Error("cc1 parser marker failed");

if (cc1_parse_sum8(49, 50, 43, 51, 32, -1, -1, -1) !== 1)
    throw new Error("cc1 sum parse failed");

if (cc1_get_last_value() !== 15)
    throw new Error("cc1 sum value failed");

if (cc1_parse_sum8(50, 43, 51, 42, 52, -1, -1, -1) !== 1)
    throw new Error("cc1 precedence parse failed");

if (cc1_get_last_value() !== 14)
    throw new Error("cc1 precedence value failed");

if (cc1_parse_sum8(40, 50, 43, 51, 41, 42, 52, -1) !== 1)
    throw new Error("cc1 parenthesized parse failed");

if (cc1_get_last_value() !== 20)
    throw new Error("cc1 parenthesized value failed");

if (cc1_bind_name_value(97, 4) !== 1)
    throw new Error("cc1 name bind failed");

if (cc1_parse_expr8(97, 42, 51, 43, 50, -1, -1, -1) !== 1)
    throw new Error("cc1 name expression parse failed");

if (cc1_get_last_value() !== 14)
    throw new Error("cc1 name expression value failed");

if (cc1_parse_assignment8(98, 61, 50, 43, 51, 42, 52, -1) !== 1)
    throw new Error("cc1 assignment parse failed");

if (cc1_get_last_name() !== 98 || cc1_get_last_value() !== 14)
    throw new Error("cc1 assignment state failed");

if (cc1_parse_expr8(98, 43, 49, -1, -1, -1, -1, -1) !== 1)
    throw new Error("cc1 assigned name parse failed");

if (cc1_get_last_value() !== 15)
    throw new Error("cc1 assigned name value failed");

if (cc1_parse_program16(97, 61, 49, 59, 98, 61, 97, 43, 50, -1, -1, -1, -1, -1, -1, -1) !== 1)
    throw new Error("cc1 program parse failed");

if (cc1_get_last_name() !== 98 || cc1_get_last_value() !== 3)
    throw new Error("cc1 program final state failed");

if (cc1_parse_expr8(98, 42, 52, -1, -1, -1, -1, -1) !== 1)
    throw new Error("cc1 program binding parse failed");

if (cc1_get_last_value() !== 12)
    throw new Error("cc1 program binding value failed");

if (cc1_parse_assignment_string(mks("c=7+8*2")) !== 1)
    throw new Error("cc1 string assignment parse failed");

if (cc1_get_last_name() !== mkc('c') || cc1_get_last_value() !== 23)
    throw new Error("cc1 string assignment state failed");

if (cc1_parse_program_string(mks("a=1;b=a+2;c=(b+3)*4")) !== 1)
    throw new Error("cc1 string program parse failed");

if (cc1_get_last_name() !== mkc('c') || cc1_get_last_value() !== 24)
    throw new Error("cc1 string program final state failed");

if (cc1_parse_expr_string(mks("c+1")) !== 1)
    throw new Error("cc1 string expression parse failed");

if (cc1_get_last_value() !== 25)
    throw new Error("cc1 string expression value failed");

if (cc1_parse_expr_string(mks("2+3==5")) !== 1)
    throw new Error("cc1 equality expression parse failed");

if (cc1_get_last_value() !== 1)
    throw new Error("cc1 equality expression value failed");

if (cc1_parse_expr_string(mks("2+3!=5")) !== 1)
    throw new Error("cc1 inequality expression parse failed");

if (cc1_get_last_value() !== 0)
    throw new Error("cc1 inequality expression value failed");

if (cc1_parse_expr_string(mks("7-2*3")) !== 1)
    throw new Error("cc1 subtraction expression parse failed");

if (cc1_get_last_value() !== 1)
    throw new Error("cc1 subtraction expression value failed");

if (cc1_parse_expr_string(mks("7>=5")) !== 1)
    throw new Error("cc1 greater-equal expression parse failed");

if (cc1_get_last_value() !== 1)
    throw new Error("cc1 greater-equal expression value failed");

if (cc1_parse_expr_string(mks("7<=5")) !== 1)
    throw new Error("cc1 less-equal expression parse failed");

if (cc1_get_last_value() !== 0)
    throw new Error("cc1 less-equal expression value failed");

if (cc1_parse_function_return_string(mks("function main(){return 7+8*2;}")) !== 1)
    throw new Error("cc1 function return parse failed");

if (cc1_get_last_name() !== mkc('m') || cc1_get_last_value() !== 23)
    throw new Error("cc1 function return state failed");

if (cc1_parse_function_return_string(mks("function main(){var a=7;var b=a*2;return b+3;}")) !== 1)
    throw new Error("cc1 function vars parse failed");

if (cc1_get_last_name() !== mkc('m') || cc1_get_last_value() !== 17)
    throw new Error("cc1 function vars state failed");

if (cc1_parse_function2_string(mks("function add(a,b){var c=a+b;return c*2;}"), 5, 6) !== 1)
    throw new Error("cc1 function params parse failed");

if (cc1_get_last_name() !== mkc('a') || cc1_get_last_value() !== 22)
    throw new Error("cc1 function params state failed");

if (cc1_parse_function2_string(mks("function pick(a,b){if(a)return b;return 3;}"), 1, 9) !== 1)
    throw new Error("cc1 function true if parse failed");

if (cc1_get_last_name() !== mkc('p') || cc1_get_last_value() !== 9)
    throw new Error("cc1 function true if state failed");

if (cc1_parse_function2_string(mks("function pick(a,b){if(a)return b;return 3;}"), 0, 9) !== 1)
    throw new Error("cc1 function false if parse failed");

if (cc1_get_last_name() !== mkc('p') || cc1_get_last_value() !== 3)
    throw new Error("cc1 function false if state failed");

if (cc1_parse_function2_string(mks("function ne(a,b){if(a!=b)return a;return b;}"), 4, 9) !== 1)
    throw new Error("cc1 function inequality if parse failed");

if (cc1_get_last_name() !== mkc('n') || cc1_get_last_value() !== 4)
    throw new Error("cc1 function inequality if state failed");

if (cc1_parse_function2_string(mks("function eq(a,b){if(a==b)return a+1;return b;}"), 4, 4) !== 1)
    throw new Error("cc1 function equality if parse failed");

if (cc1_get_last_name() !== mkc('e') || cc1_get_last_value() !== 5)
    throw new Error("cc1 function equality if state failed");

if (cc1_parse_function2_string(mks("function ch(a,b){if(a==0)return 7;if(b!=0)return b;return 3;}"), 0, 9) !== 1)
    throw new Error("cc1 function first chained if parse failed");

if (cc1_get_last_name() !== mkc('c') || cc1_get_last_value() !== 7)
    throw new Error("cc1 function first chained if state failed");

if (cc1_parse_function2_string(mks("function ch(a,b){if(a==0)return 7;if(b!=0)return b;return 3;}"), 1, 9) !== 1)
    throw new Error("cc1 function second chained if parse failed");

if (cc1_get_last_name() !== mkc('c') || cc1_get_last_value() !== 9)
    throw new Error("cc1 function second chained if state failed");

if (cc1_parse_function2_string(mks("function ch(a,b){if(a==0)return 7;if(b!=0)return b;return 3;}"), 1, 0) !== 1)
    throw new Error("cc1 function chained fallback parse failed");

if (cc1_get_last_name() !== mkc('c') || cc1_get_last_value() !== 3)
    throw new Error("cc1 function chained fallback state failed");

if (cc1_parse_function2_string(mks("function dg(c){if(c<48)return 0;if(c<=57)return 1;return 0;}"), 52, 0) !== 1)
    throw new Error("cc1 function less-equal guard parse failed");

if (cc1_get_last_name() !== mkc('d') || cc1_get_last_value() !== 1)
    throw new Error("cc1 function less-equal guard state failed");

if (cc1_parse_function2_string(mks("function dg(c){if(c<48)return 0;if(c<=57)return 1;return 0;}"), 58, 0) !== 1)
    throw new Error("cc1 function less-equal fallback parse failed");

if (cc1_get_last_name() !== mkc('d') || cc1_get_last_value() !== 0)
    throw new Error("cc1 function less-equal fallback state failed");

if (cc1_parse_function2_string(mks("function nd(c){if(c>=48)if(c<=57)return 1;return 0;}"), 52, 0) !== 1)
    throw new Error("cc1 nested if digit parse failed");

if (cc1_get_last_name() !== mkc('n') || cc1_get_last_value() !== 1)
    throw new Error("cc1 nested if digit state failed");

if (cc1_parse_function2_string(mks("function nd(c){if(c>=48)if(c<=57)return 1;return 0;}"), 47, 0) !== 1)
    throw new Error("cc1 nested if low fallback parse failed");

if (cc1_get_last_name() !== mkc('n') || cc1_get_last_value() !== 0)
    throw new Error("cc1 nested if low fallback state failed");

if (cc1_parse_function2_string(mks("function nd(c){if(c>=48)if(c<=57)return 1;return 0;}"), 58, 0) !== 1)
    throw new Error("cc1 nested if high fallback parse failed");

if (cc1_get_last_name() !== mkc('n') || cc1_get_last_value() !== 0)
    throw new Error("cc1 nested if high fallback state failed");

if (cc1_parse_function2_string(mks("function dc(c){if(c>=CC0_CH_0)if(c<=CC0_CH_9)return 1;return 0;}"), 52, 0) !== 1)
    throw new Error("cc1 named constant digit parse failed");

if (cc1_get_last_name() !== mkc('d') || cc1_get_last_value() !== 1)
    throw new Error("cc1 named constant digit state failed");

if (cc1_parse_function2_string(mks("function dc(c){if(c>=CC0_CH_0)if(c<=CC0_CH_9)return 1;return 0;}"), 58, 0) !== 1)
    throw new Error("cc1 named constant digit fallback parse failed");

if (cc1_get_last_name() !== mkc('d') || cc1_get_last_value() !== 0)
    throw new Error("cc1 named constant digit fallback state failed");

if (cc1_parse_function2_string(mks("function cd(c){if(cc0_is_digit(c))return 1;return 0;}"), 52, 0) !== 1)
    throw new Error("cc1 cc0_is_digit call parse failed");

if (cc1_get_last_name() !== mkc('c') || cc1_get_last_value() !== 1)
    throw new Error("cc1 cc0_is_digit call state failed");

if (cc1_parse_function2_string(mks("function cd(c){if(cc0_is_digit(c))return 1;return 0;}"), 65, 0) !== 1)
    throw new Error("cc1 cc0_is_digit call fallback parse failed");

if (cc1_get_last_name() !== mkc('c') || cc1_get_last_value() !== 0)
    throw new Error("cc1 cc0_is_digit call fallback state failed");

if (cc1_parse_expr_string(mks("mkc('A')")) !== 1)
    throw new Error("cc1 mkc call parse failed");

if (cc1_get_last_value() !== mkc('A'))
    throw new Error("cc1 mkc call state failed");

if (cc1_parse_expr_string(mks("cc0_heap_get(mks(\"Az\"),1)")) !== 1)
    throw new Error("cc1 mks heap_get parse failed");

if (cc1_get_last_value() !== mkc('z'))
    throw new Error("cc1 mks heap_get state failed");

if (cc1_parse_function_return_string(mks("function ch(){return mkc('C');}")) !== 1)
    throw new Error("cc1 mkc function parse failed");

if (cc1_get_last_name() !== mkc('c') || cc1_get_last_value() !== mkc('C'))
    throw new Error("cc1 mkc function state failed");

if (cc1_parse_function_return_string(mks("function st(){return cc0_heap_get(mks(\"Hi\"),0);}")) !== 1)
    throw new Error("cc1 mks function parse failed");

if (cc1_get_last_name() !== mkc('s') || cc1_get_last_value() !== mkc('H'))
    throw new Error("cc1 mks function state failed");

if (cc1_parse_expr_string(mks("!0")) !== 1)
    throw new Error("cc1 unary not zero parse failed");

if (cc1_get_last_value() !== 1)
    throw new Error("cc1 unary not zero state failed");

if (cc1_parse_expr_string(mks("!7")) !== 1)
    throw new Error("cc1 unary not nonzero parse failed");

if (cc1_get_last_value() !== 0)
    throw new Error("cc1 unary not nonzero state failed");

if (cc1_parse_function2_string(mks("function nz(a,b){if(!a)return b;return a;}"), 0, 8) !== 1)
    throw new Error("cc1 unary not function true parse failed");

if (cc1_get_last_name() !== mkc('n') || cc1_get_last_value() !== 8)
    throw new Error("cc1 unary not function true state failed");

if (cc1_parse_function2_string(mks("function nz(a,b){if(!a)return b;return a;}"), 5, 8) !== 1)
    throw new Error("cc1 unary not function false parse failed");

if (cc1_get_last_name() !== mkc('n') || cc1_get_last_value() !== 5)
    throw new Error("cc1 unary not function false state failed");

if (cc1_parse_cc0_source_string(mks("/*comment*/var a;a=1;function f(x){if(x)return 1;return 0;}function w(x){var y=0;while(x)y=y+1;return y;}")) !== 1)
    throw new Error("cc1 cc0 source shell parse failed");

if (cc1_get_function_count() !== 2)
    throw new Error("cc1 cc0 source shell function count failed");

if (cc1_get_top_decl_count() !== 2)
    throw new Error("cc1 cc0 source shell top count failed");

if (cc1_get_return_count() !== 3)
    throw new Error("cc1 cc0 source shell return count failed");

if (cc1_get_if_count() !== 1)
    throw new Error("cc1 cc0 source shell if count failed");

if (cc1_get_while_count() !== 1)
    throw new Error("cc1 cc0 source shell while count failed");

if (cc1_get_local_decl_count() !== 1)
    throw new Error("cc1 cc0 source shell local count failed");

if (cc1_get_body_semi_count() !== 5)
    throw new Error("cc1 cc0 source shell semicolon count failed");

if (cc1_get_max_body_depth() !== 1)
    throw new Error("cc1 cc0 source shell body depth failed");

if (cc1_get_param_count() !== 2)
    throw new Error("cc1 cc0 source shell param count failed");

if (cc1_get_max_param_count() !== 1)
    throw new Error("cc1 cc0 source shell max param count failed");

if (cc1_get_body_call_count() !== 0)
    throw new Error("cc1 cc0 source shell body call count failed");

if (cc1_get_max_body_call_arg_count() !== 0)
    throw new Error("cc1 cc0 source shell max body call arg count failed");

if (cc1_get_body_assignment_count() !== 2)
    throw new Error("cc1 cc0 source shell assignment count failed");

if (cc1_get_max_body_expr_depth() !== 1)
    throw new Error("cc1 cc0 source shell expression depth failed");

if (cc1_get_max_function_statement_count() !== 4)
    throw new Error("cc1 cc0 source shell max function statement count failed");

if (cc1_get_max_function_local_count() !== 1)
    throw new Error("cc1 cc0 source shell max function local count failed");

if (cc1_get_body_expr_statement_count() !== 1)
    throw new Error("cc1 cc0 source shell expr statement count failed");

if (cc1_get_body_call_statement_count() !== 0)
    throw new Error("cc1 cc0 source shell call statement count failed");

if (cc1_get_body_return_call_count() !== 0)
    throw new Error("cc1 cc0 source shell return call count failed");

if (cc1_get_body_local_init_count() !== 1)
    throw new Error("cc1 cc0 source shell local init count failed");

if (cc1_get_body_name_assignment_count() !== 1)
    throw new Error("cc1 cc0 source shell name assignment count failed");

if (cc1_get_body_plus_op_count() !== 1)
    throw new Error("cc1 cc0 source shell plus op count failed");

if (cc1_get_body_minus_op_count() !== 0)
    throw new Error("cc1 cc0 source shell minus op count failed");

if (cc1_get_body_star_op_count() !== 0)
    throw new Error("cc1 cc0 source shell star op count failed");

if (cc1_get_body_compare_op_count() !== 0)
    throw new Error("cc1 cc0 source shell compare op count failed");

if (cc1_get_body_not_op_count() !== 0)
    throw new Error("cc1 cc0 source shell not op count failed");

if (cc1_get_function_name_char_count() !== 2)
    throw new Error("cc1 cc0 source shell function name char count failed");

if (cc1_get_max_function_name_len() !== 1)
    throw new Error("cc1 cc0 source shell max function name length failed");

if (cc1_get_function_name_hash() !== 3485)
    throw new Error("cc1 cc0 source shell function name hash failed");

if (cc1_get_global_name_char_count() !== 2)
    throw new Error("cc1 cc0 source shell global name char count failed");

if (cc1_get_max_global_name_len() !== 1)
    throw new Error("cc1 cc0 source shell max global name length failed");

if (cc1_get_global_name_hash() !== 3298)
    throw new Error("cc1 cc0 source shell global name hash failed");

if (cc1_get_max_function_source_span() !== 46)
    throw new Error("cc1 cc0 source shell max function source span failed");

if (cc1_get_function_slot_hash(0) !== 102 || cc1_get_function_slot_len(0) !== 1)
    throw new Error("cc1 cc0 source shell function slot 0 failed");

if (cc1_get_function_slot_hash(1) !== 119 || cc1_get_function_slot_len(1) !== 1)
    throw new Error("cc1 cc0 source shell function slot 1 failed");

if (cc1_get_global_slot_hash(0) !== 97 || cc1_get_global_slot_len(0) !== 1)
    throw new Error("cc1 cc0 source shell global slot 0 failed");

if (cc1_get_global_slot_hash(1) !== 97 || cc1_get_global_slot_len(1) !== 1)
    throw new Error("cc1 cc0 source shell global slot 1 failed");

if (cc1_get_symbol_table_count() !== 4)
    throw new Error("cc1 cc0 source shell symbol table count failed");

if (cc1_get_symbol_table_overflow() !== 0)
    throw new Error("cc1 cc0 source shell symbol table overflow failed");

if (cc1_get_symbol_table_cell(0, 0) !== 2 ||
    cc1_get_symbol_table_cell(0, 1) !== 97 ||
    cc1_get_symbol_table_cell(0, 2) !== 1 ||
    cc1_get_symbol_table_cell(0, 3) !== 0)
    throw new Error("cc1 cc0 source shell symbol 0 failed");

if (cc1_get_symbol_table_cell(3, 0) !== 1 ||
    cc1_get_symbol_table_cell(3, 1) !== 119 ||
    cc1_get_symbol_table_cell(3, 2) !== 1 ||
    cc1_get_symbol_table_cell(3, 3) !== 1)
    throw new Error("cc1 cc0 source shell symbol 3 failed");

if (cc1_get_function_table_count() !== 2)
    throw new Error("cc1 cc0 source shell function table count failed");

if (cc1_get_function_table_overflow() !== 0)
    throw new Error("cc1 cc0 source shell function table overflow failed");

if (cc1_get_function_table_cell(0, 0) !== 102 ||
    cc1_get_function_table_cell(0, 1) !== 1 ||
    cc1_get_function_table_cell(0, 2) !== 1 ||
    cc1_get_function_table_cell(0, 3) !== 21 ||
    cc1_get_function_table_cell(0, 4) !== 38 ||
    cc1_get_function_table_cell(0, 5) !== 0)
    throw new Error("cc1 cc0 source shell function record 0 failed");

if (cc1_get_function_table_cell(1, 0) !== 119 ||
    cc1_get_function_table_cell(1, 1) !== 1 ||
    cc1_get_function_table_cell(1, 2) !== 1 ||
    cc1_get_function_table_cell(1, 3) !== 59 ||
    cc1_get_function_table_cell(1, 4) !== 46 ||
    cc1_get_function_table_cell(1, 5) !== 1)
    throw new Error("cc1 cc0 source shell function record 1 failed");

if (cc1_get_statement_table_count() !== 7)
    throw new Error("cc1 cc0 source shell statement table count failed");

if (cc1_get_statement_table_overflow() !== 0)
    throw new Error("cc1 cc0 source shell statement table overflow failed");

if (cc1_get_statement_table_cell(0, 0) !== 2 ||
    cc1_get_statement_table_cell(0, 1) !== 1 ||
    cc1_get_statement_table_cell(0, 2) !== 35 ||
    cc1_get_statement_table_cell(0, 3) !== 0)
    throw new Error("cc1 cc0 source shell statement record 0 failed");

if (cc1_get_statement_table_cell(6, 0) !== 1 ||
    cc1_get_statement_table_cell(6, 1) !== 1 ||
    cc1_get_statement_table_cell(6, 2) !== 95 ||
    cc1_get_statement_table_cell(6, 3) !== 1)
    throw new Error("cc1 cc0 source shell statement record 6 failed");

if (cc1_get_param_table_count() !== 2 || cc1_get_param_table_overflow() !== 0)
    throw new Error("cc1 cc0 source shell param table bounds failed");

if (cc1_get_param_table_cell(0, 0) !== 120 ||
    cc1_get_param_table_cell(0, 1) !== 1 ||
    cc1_get_param_table_cell(0, 2) !== 0 ||
    cc1_get_param_table_cell(0, 3) !== 0)
    throw new Error("cc1 cc0 source shell param record 0 failed");

if (cc1_get_param_table_cell(1, 0) !== 120 ||
    cc1_get_param_table_cell(1, 1) !== 1 ||
    cc1_get_param_table_cell(1, 2) !== 0 ||
    cc1_get_param_table_cell(1, 3) !== 1)
    throw new Error("cc1 cc0 source shell param record 1 failed");

if (cc1_get_local_table_count() !== 1 || cc1_get_local_table_overflow() !== 0)
    throw new Error("cc1 cc0 source shell local table bounds failed");

if (cc1_get_local_table_cell(0, 0) !== 121 ||
    cc1_get_local_table_cell(0, 1) !== 1 ||
    cc1_get_local_table_cell(0, 2) !== 0 ||
    cc1_get_local_table_cell(0, 3) !== 1)
    throw new Error("cc1 cc0 source shell local record 0 failed");

if (cc1_parse_cc0_source_string(mks("function bad(x){return 1}")) !== 0)
    throw new Error("cc1 accepted body return without semicolon");

if (cc1_get_error() === 0)
    throw new Error("cc1 missing semicolon did not report error");

if (cc1_parse_cc0_source_string(mks("function bad(x){if((x)return 1;}")) !== 0)
    throw new Error("cc1 accepted unbalanced if condition");

if (cc1_get_error() === 0)
    throw new Error("cc1 unbalanced if condition did not report error");

if (cc1_parse_cc0_source_string(mks(read("../tcc_27_layered/cc0.c"))) !== 1)
    throw new Error("cc1 cc0.c parse failed: " + cc1_get_error());

if (cc1_get_function_count() !== 41)
    throw new Error("cc1 cc0.c function count failed");

if (cc1_get_top_decl_count() !== 174)
    throw new Error("cc1 cc0.c top count failed");

if (cc1_get_return_count() !== 148)
    throw new Error("cc1 cc0.c return count failed");

if (cc1_get_if_count() !== 115)
    throw new Error("cc1 cc0.c if count failed");

if (cc1_get_while_count() !== 7)
    throw new Error("cc1 cc0.c while count failed");

if (cc1_get_local_decl_count() !== 4)
    throw new Error("cc1 cc0.c local count failed");

if (cc1_get_body_semi_count() !== 247)
    throw new Error("cc1 cc0.c semicolon count failed");

if (cc1_get_max_body_depth() !== 5)
    throw new Error("cc1 cc0.c body depth failed");

if (cc1_get_param_count() !== 90)
    throw new Error("cc1 cc0.c param count failed");

if (cc1_get_max_param_count() !== 16)
    throw new Error("cc1 cc0.c max param count failed");

if (cc1_get_body_call_count() !== 89)
    throw new Error("cc1 cc0.c body call count failed");

if (cc1_get_max_body_call_arg_count() !== 9)
    throw new Error("cc1 cc0.c max body call arg count failed");

if (cc1_get_body_assignment_count() !== 94)
    throw new Error("cc1 cc0.c assignment count failed");

if (cc1_get_max_body_expr_depth() !== 2)
    throw new Error("cc1 cc0.c expression depth failed");

if (cc1_get_max_function_statement_count() !== 54)
    throw new Error("cc1 cc0.c max function statement count failed");

if (cc1_get_max_function_local_count() !== 2)
    throw new Error("cc1 cc0.c max function local count failed");

if (cc1_get_body_expr_statement_count() !== 95)
    throw new Error("cc1 cc0.c expr statement count failed");

if (cc1_get_body_call_statement_count() !== 16)
    throw new Error("cc1 cc0.c call statement count failed");

if (cc1_get_body_return_call_count() !== 8)
    throw new Error("cc1 cc0.c return call count failed");

if (cc1_get_body_local_init_count() !== 0)
    throw new Error("cc1 cc0.c local init count failed");

if (cc1_get_body_name_assignment_count() !== 94)
    throw new Error("cc1 cc0.c name assignment count failed");

if (cc1_get_body_plus_op_count() !== 44)
    throw new Error("cc1 cc0.c plus op count failed");

if (cc1_get_body_minus_op_count() !== 12)
    throw new Error("cc1 cc0.c minus op count failed");

if (cc1_get_body_star_op_count() !== 1)
    throw new Error("cc1 cc0.c star op count failed");

if (cc1_get_body_compare_op_count() !== 102)
    throw new Error("cc1 cc0.c compare op count failed");

if (cc1_get_body_not_op_count() !== 0)
    throw new Error("cc1 cc0.c not op count failed");

if (cc1_get_function_name_char_count() !== 705)
    throw new Error("cc1 cc0.c function name char count failed");

if (cc1_get_max_function_name_len() !== 26)
    throw new Error("cc1 cc0.c max function name length failed");

if (cc1_get_function_name_hash() !== 12867)
    throw new Error("cc1 cc0.c function name hash failed");

if (cc1_get_global_name_char_count() !== 1836)
    throw new Error("cc1 cc0.c global name char count failed");

if (cc1_get_max_global_name_len() !== 24)
    throw new Error("cc1 cc0.c max global name length failed");

if (cc1_get_global_name_hash() !== 22993)
    throw new Error("cc1 cc0.c global name hash failed");

if (cc1_get_max_function_source_span() !== 1888)
    throw new Error("cc1 cc0.c max function source span failed");

if (cc1_get_function_slot_hash(0) !== 16844 || cc1_get_function_slot_len(0) !== 7)
    throw new Error("cc1 cc0.c function slot 0 failed");

if (cc1_get_function_slot_hash(1) !== 11233 || cc1_get_function_slot_len(1) !== 10)
    throw new Error("cc1 cc0.c function slot 1 failed");

if (cc1_get_function_slot_hash(2) !== 31380 || cc1_get_function_slot_len(2) !== 7)
    throw new Error("cc1 cc0.c function slot 2 failed");

if (cc1_get_function_slot_hash(3) !== 12434 || cc1_get_function_slot_len(3) !== 26)
    throw new Error("cc1 cc0.c function slot 3 failed");

if (cc1_get_global_slot_hash(0) !== 14563 || cc1_get_global_slot_len(0) !== 19)
    throw new Error("cc1 cc0.c global slot 0 failed");

if (cc1_get_global_slot_hash(1) !== 19311 || cc1_get_global_slot_len(1) !== 11)
    throw new Error("cc1 cc0.c global slot 1 failed");

if (cc1_get_global_slot_hash(2) !== 28778 || cc1_get_global_slot_len(2) !== 12)
    throw new Error("cc1 cc0.c global slot 2 failed");

if (cc1_get_global_slot_hash(3) !== 5685 || cc1_get_global_slot_len(3) !== 14)
    throw new Error("cc1 cc0.c global slot 3 failed");

if (cc1_get_symbol_table_count() !== 8)
    throw new Error("cc1 cc0.c symbol table count failed");

if (cc1_get_symbol_table_overflow() !== 1)
    throw new Error("cc1 cc0.c symbol table overflow failed");

if (cc1_get_symbol_table_cell(0, 0) !== 2 ||
    cc1_get_symbol_table_cell(0, 1) !== 14563 ||
    cc1_get_symbol_table_cell(0, 2) !== 19 ||
    cc1_get_symbol_table_cell(0, 3) !== 0)
    throw new Error("cc1 cc0.c symbol 0 failed");

if (cc1_get_symbol_table_cell(3, 0) !== 2 ||
    cc1_get_symbol_table_cell(3, 1) !== 5685 ||
    cc1_get_symbol_table_cell(3, 2) !== 14 ||
    cc1_get_symbol_table_cell(3, 3) !== 3)
    throw new Error("cc1 cc0.c symbol 3 failed");

if (cc1_get_function_table_count() !== 8)
    throw new Error("cc1 cc0.c function table count failed");

if (cc1_get_function_table_overflow() !== 1)
    throw new Error("cc1 cc0.c function table overflow failed");

if (cc1_get_function_table_cell(0, 0) !== 16844 ||
    cc1_get_function_table_cell(0, 1) !== 7 ||
    cc1_get_function_table_cell(0, 2) !== 2 ||
    cc1_get_function_table_cell(0, 3) !== 3227 ||
    cc1_get_function_table_cell(0, 4) !== 46 ||
    cc1_get_function_table_cell(0, 5) !== 0)
    throw new Error("cc1 cc0.c function record 0 failed");

if (cc1_get_function_table_cell(7, 0) !== 30345 ||
    cc1_get_function_table_cell(7, 1) !== 20 ||
    cc1_get_function_table_cell(7, 2) !== 3 ||
    cc1_get_function_table_cell(7, 3) !== 4795 ||
    cc1_get_function_table_cell(7, 4) !== 189 ||
    cc1_get_function_table_cell(7, 5) !== 7)
    throw new Error("cc1 cc0.c function record 7 failed");

if (cc1_get_statement_table_count() !== 16)
    throw new Error("cc1 cc0.c statement table count failed");

if (cc1_get_statement_table_overflow() !== 1)
    throw new Error("cc1 cc0.c statement table overflow failed");

if (cc1_get_statement_table_cell(0, 0) !== 1 ||
    cc1_get_statement_table_cell(0, 1) !== 1 ||
    cc1_get_statement_table_cell(0, 2) !== 3256 ||
    cc1_get_statement_table_cell(0, 3) !== 0)
    throw new Error("cc1 cc0.c statement record 0 failed");

if (cc1_get_statement_table_cell(15, 0) !== 2 ||
    cc1_get_statement_table_cell(15, 1) !== 1 ||
    cc1_get_statement_table_cell(15, 2) !== 3712 ||
    cc1_get_statement_table_cell(15, 3) !== 3)
    throw new Error("cc1 cc0.c statement record 15 failed");

if (cc1_get_param_table_count() !== 16 || cc1_get_param_table_overflow() !== 1)
    throw new Error("cc1 cc0.c param table bounds failed");

if (cc1_get_param_table_cell(0, 0) !== 97 ||
    cc1_get_param_table_cell(0, 1) !== 1 ||
    cc1_get_param_table_cell(0, 2) !== 0 ||
    cc1_get_param_table_cell(0, 3) !== 0)
    throw new Error("cc1 cc0.c param record 0 failed");

if (cc1_get_param_table_cell(15, 0) !== 3315 ||
    cc1_get_param_table_cell(15, 1) !== 2 ||
    cc1_get_param_table_cell(15, 2) !== 0 ||
    cc1_get_param_table_cell(15, 3) !== 4)
    throw new Error("cc1 cc0.c param record 15 failed");

if (cc1_get_local_table_count() !== 4 || cc1_get_local_table_overflow() !== 0)
    throw new Error("cc1 cc0.c local table bounds failed");

if (cc1_get_local_table_cell(0, 0) !== 99 ||
    cc1_get_local_table_cell(0, 1) !== 1 ||
    cc1_get_local_table_cell(0, 2) !== 0 ||
    cc1_get_local_table_cell(0, 3) !== 26)
    throw new Error("cc1 cc0.c local record 0 failed");

if (cc1_get_local_table_cell(3, 0) !== 99 ||
    cc1_get_local_table_cell(3, 1) !== 1 ||
    cc1_get_local_table_cell(3, 2) !== 0 ||
    cc1_get_local_table_cell(3, 3) !== 28)
    throw new Error("cc1 cc0.c local record 3 failed");

if (cc1_parse_sum8(49, 43, 43, 50, -1, -1, -1, -1) !== 0)
    throw new Error("cc1 bad sum accepted");

if (cc1_get_error() === 0)
    throw new Error("cc1 bad sum did not report error");

if (cc2_ar_is_conflict_option(97) !== 1)
    throw new Error("cc2 ar conflict option failed");

if (cc2_ar_is_conflict_option(114) !== 0)
    throw new Error("cc2 ar allowed option failed");

if (cc2_ar_is_verbose_option(118) !== 1)
    throw new Error("cc2 ar verbose option failed");

if (cc2_ar_be32(1) !== 16777216)
    throw new Error("cc2 ar byte swap failed");

if (cc2_ar_is_exported_symbol(16) !== 1 || cc2_ar_is_exported_symbol(19) !== 0)
    throw new Error("cc2 ar exported symbol failed");
