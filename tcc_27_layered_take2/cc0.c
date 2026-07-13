/*
 * cc0 uses K&R-shaped functions so the same text is readable by C and JS.
 * C maps the two declaration words to int; JavaScript uses them directly.
 * Operators are primitive calls supplied by the current host. The cc0
 * compiler will also recognize these calls and emit their i386 operations,
 * which removes the host support from the eventual self-hosted path.
 */
var CC0_FALSE;
var CC0_TRUE;
var CC0_CHARACTER_EOF;
var CC0_BYTE_VALUE_COUNT;
var CC0_CHARACTER_SPACE_FLAG;
var CC0_TOKEN_HASH_INITIAL;
var CC0_TOKEN_HASH_LEFT_SHIFT;
var CC0_TOKEN_HASH_RIGHT_SHIFT;
var CC0_TOKEN_HASH_BUCKET_MASK;
var CC0_WORD_ADDRESS_SHIFT;
var CC0_WORD_BYTES;
var CC0_WORD_BITS;
var CC0_NUMBER_WORD_COUNT;

/* Named ASCII values keep character classification independent of literals. */
var CC0_ASCII_TAB;
var CC0_ASCII_VERTICAL_TAB;
var CC0_ASCII_LINE_FEED;
var CC0_ASCII_FORM_FEED;
var CC0_ASCII_CARRIAGE_RETURN;
var CC0_ASCII_SPACE;
var CC0_ASCII_ZERO;
var CC0_ASCII_SEVEN;
var CC0_ASCII_NINE;
var CC0_ASCII_UPPER_A;
var CC0_ASCII_UPPER_Z;
var CC0_ASCII_UNDERSCORE;
var CC0_ASCII_LOWER_A;
var CC0_ASCII_LOWER_Z;
var CC0_ASCII_SLASH;
var CC0_ASCII_STAR;
var CC0_ASCII_BACKSLASH;
var CC0_ASCII_QUOTE;
var CC0_ASCII_APOSTROPHE;
var CC0_ASCII_UPPER_X;
var CC0_ASCII_LOWER_X;
var CC0_ASCII_UPPER_L;
var CC0_ASCII_LOWER_L;
var CC0_ASCII_UPPER_U;
var CC0_ASCII_LOWER_U;
var CC0_ASCII_LOWER_N;
var CC0_ASCII_LOWER_R;
var CC0_ASCII_LOWER_T;

/* Standalone compiler lexer state and its deliberately small token set. */
var CC0_SOURCE;
var CC0_SOURCE_LENGTH;
var CC0_SOURCE_POSITION;
var CC0_TOKEN;
var CC0_TOKEN_START;
var CC0_TOKEN_LENGTH;
var CC0_TOKEN_NUMBER;
var CC0_TOKEN_EOF;
var CC0_TOKEN_ERROR;
var CC0_TOKEN_IDENTIFIER;
var CC0_TOKEN_NUMBER_LITERAL;
var CC0_TOKEN_STRING_LITERAL;
var CC0_TOKEN_FUNCTION;
var CC0_TOKEN_VAR;
var CC0_TOKEN_RETURN;
var CC0_TOKEN_IF;
var CC0_TOKEN_ELSE;
var CC0_TOKEN_WHILE;
var CC0_TOKEN_BREAK;
var CC0_TOKEN_FOR;
var CC0_TOKEN_DO;
var CC0_TOKEN_CONTINUE;
var CC0_COMPILER_ERROR;
var CC0_LEXER_FIELD_KIND;
var CC0_LEXER_FIELD_TEXT;
var CC0_LEXER_FIELD_LENGTH;
var CC0_LEXER_FIELD_NUMBER;
var CC0_COMPILER_ERROR_POSITION;
var CC0_COMPILER_ERROR_FILE;
var CC0_COMPILER_ERROR_LINE;
var CC0_COMPILER_ERROR_COLUMN;
var CC0_DECIMAL_MAX_PLACE;
var CC0_PUNCTUATION_LEFT_PARENTHESIS;
var CC0_PUNCTUATION_RIGHT_PARENTHESIS;
var CC0_PUNCTUATION_LEFT_BRACE;
var CC0_PUNCTUATION_RIGHT_BRACE;
var CC0_PUNCTUATION_SEMICOLON;
var CC0_PUNCTUATION_COMMA;
var CC0_PUNCTUATION_ASSIGN;
var CC0_PUNCTUATION_LEFT_BRACKET;
var CC0_PUNCTUATION_RIGHT_BRACKET;
var CC0_SYMBOL_ENTRY_ADDRESS_SHIFT;
var CC0_INITIAL_ALLOCATION_BYTES;
var CC0_GLOBAL_SYMBOL_CAPACITY;
var CC0_FUNCTION_SYMBOL_CAPACITY;
var CC0_PARAMETER_SYMBOL_CAPACITY;
var CC0_LOCAL_SYMBOL_CAPACITY;
var CC0_CALL_RECORD_CAPACITY;
var CC0_RELOCATION_RECORD_CAPACITY;
var CC0_LOOP_STACK_CAPACITY;
var CC0_BREAK_RECORD_CAPACITY;
var CC0_CONTINUE_RECORD_CAPACITY;
var CC0_SYMBOL_NAME_OFFSET;
var CC0_SYMBOL_LENGTH_OFFSET;
var CC0_SYMBOL_VALUE_OFFSET;
var CC0_SYMBOL_CODE_OFFSET;
var CC0_GLOBAL_SYMBOLS;
var CC0_GLOBAL_COUNT;
var CC0_FUNCTION_SYMBOLS;
var CC0_FUNCTION_COUNT;
var CC0_PARAMETER_SYMBOLS;
var CC0_PARAMETER_COUNT;
var CC0_LOCAL_SYMBOLS;
var CC0_LOCAL_COUNT;
var CC0_CURRENT_NAME_START;
var CC0_CURRENT_NAME_LENGTH;
var CC0_COMPILER_PHASE;
var CC0_COMPILER_PHASE_COLLECT;
var CC0_COMPILER_PHASE_RESOLVE;
var CC0_COMPILER_PHASE_EMIT;
var CC0_CODE_CAPACITY;
var CC0_CODE;
var CC0_CODE_LENGTH;
var CC0_X86_PUSH_EBP;
var CC0_X86_MOV_REGISTER_OPCODE;
var CC0_X86_MOV_EBP_ESP;
var CC0_X86_PUSH_EBX;
var CC0_X86_SUB_ESP_IMMEDIATE;
var CC0_X86_LOAD_REGISTER_OPCODE;
var CC0_X86_LOAD_EBX_FROM_FRAME;
var CC0_X86_SAVED_EBX_DISPLACEMENT;
var CC0_X86_MOV_ESP_EBP;
var CC0_X86_POP_EBP;
var CC0_X86_RETURN;
var CC0_X86_MOV_EAX_IMMEDIATE;
var CC0_X86_PUSH_EAX;
var CC0_X86_POP_EBX;
var CC0_X86_LOAD_EAX_FROM_FRAME;
var CC0_X86_STORE_REGISTER_OPCODE;
var CC0_X86_STORE_EAX_TO_FRAME;
var CC0_X86_LOAD_EAX_FROM_FRAME_WORD;
var CC0_X86_STORE_EAX_TO_FRAME_WORD;
var CC0_X86_LOAD_ADDRESS_OPCODE;
var CC0_X86_LOAD_ADDRESS_FRAME_WORD;
var CC0_X86_TEST_OPCODE;
var CC0_X86_TEST_EAX_EAX;
var CC0_X86_TWO_BYTE_OPCODE;
var CC0_X86_JUMP_IF_ZERO;
var CC0_X86_JUMP_RELATIVE;
var CC0_X86_CALL_RELATIVE;
var CC0_X86_ADD_IMMEDIATE_OPCODE;
var CC0_X86_ADD_ESP_IMMEDIATE;
var CC0_X86_MOV_ECX_EAX;
var CC0_X86_MOV_EAX_EBX;
var CC0_X86_ADD_REGISTER_OPCODE;
var CC0_X86_ADD_EAX_EBX;
var CC0_X86_SUB_REGISTER_OPCODE;
var CC0_X86_SUB_EAX_ECX;
var CC0_X86_SIGNED_MULTIPLY_OPCODE;
var CC0_X86_MULTIPLY_EAX_EBX;
var CC0_X86_SIGN_EXTEND_EAX;
var CC0_X86_DIVIDE_OPCODE;
var CC0_X86_DIVIDE_BY_ECX;
var CC0_X86_MOV_EAX_EDX;
var CC0_X86_AND_REGISTER_OPCODE;
var CC0_X86_AND_EAX_EBX;
var CC0_X86_OR_REGISTER_OPCODE;
var CC0_X86_OR_EAX_EBX;
var CC0_X86_XOR_REGISTER_OPCODE;
var CC0_X86_XOR_EAX_EBX;
var CC0_X86_COMPLEMENT_EAX;
var CC0_X86_SHIFT_BY_CL_OPCODE;
var CC0_X86_SHIFT_LEFT_EBX;
var CC0_X86_SHIFT_RIGHT_EBX;
var CC0_X86_SHIFT_RIGHT_SIGNED_EBX;
var CC0_X86_COMPARE_OPCODE;
var CC0_X86_COMPARE_EBX_EAX;
var CC0_X86_SET_EQUAL;
var CC0_X86_SET_LESS;
var CC0_X86_SET_LESS_EQUAL;
var CC0_X86_SET_EAX_BYTE;
var CC0_X86_ZERO_EXTEND_OPCODE;
var CC0_X86_ZERO_EXTEND_EAX_BYTE;
var CC0_X86_LOAD_EAX_ADDRESS;
var CC0_X86_LOAD_EAX_BYTE_ADDRESS;
var CC0_X86_STORE_EAX_ADDRESS;
var CC0_X86_STORE_EAX_BYTE_ADDRESS_OPCODE;
var CC0_X86_STORE_EAX_BYTE_ADDRESS;
var CC0_X86_LOAD_EAX_ABSOLUTE;
var CC0_X86_STORE_EAX_ABSOLUTE;
var CC0_DATA_CAPACITY;
var CC0_DATA;
var CC0_DATA_LENGTH;
var CC0_CALL_RECORDS;
var CC0_CALL_COUNT;
var CC0_RELOCATION_RECORDS;
var CC0_RELOCATION_COUNT;
var CC0_X86_STACK_ADDRESS_SUFFIX;
var CC0_X86_LOAD_EAX_STACK;
var CC0_X86_LOAD_EBX_STACK;
var CC0_X86_STORE_EBX_STACK;
var CC0_X86_STORE_EAX_STACK;
var CC0_PARAMETER_FIRST_OFFSET;
var CC0_LOOP_STACK;
var CC0_LOOP_DEPTH;
var CC0_NEXT_LOOP_ID;
var CC0_BREAK_RECORDS;
var CC0_BREAK_COUNT;
var CC0_CONTINUE_RECORDS;
var CC0_CONTINUE_COUNT;
var CC0_X86_JUMP_IF_NOT_ZERO;
var CC0_MAIN_USAGE_ERROR;
var CC0_MAIN_INPUT_ERROR;
var CC0_MAIN_COMPILE_ERROR;
var CC0_MAIN_OUTPUT_ERROR;
var CC0_MAIN_LINK_ERROR;
var CC0_STANDARD_OUTPUT;
var CC0_STANDARD_ERROR;
var CC0_SECTION_ENTRY_ADDRESS_SHIFT;
var CC0_SECTION_CAPACITY;
var CC0_SECTIONS;
var CC0_SECTION_COUNT;
var CC0_SECTION_NAME_OFFSET;
var CC0_SECTION_NAME_LENGTH_OFFSET;
var CC0_SECTION_TYPE_OFFSET;
var CC0_SECTION_FLAGS_OFFSET;
var CC0_SECTION_ALIGNMENT_OFFSET;
var CC0_SECTION_ENTRY_SIZE_OFFSET;
var CC0_SECTION_LINK_OFFSET;
var CC0_SECTION_INFO_OFFSET;
var CC0_SECTION_DATA_OFFSET;
var CC0_SECTION_CAPACITY_OFFSET;
var CC0_SECTION_SIZE_OFFSET;
var CC0_SECTION_FILE_OFFSET;
var CC0_SECTION_NUMBER_OFFSET;
var CC0_SECTION_INITIAL_DATA_CAPACITY;
var CC0_ELF_SECTION_PROGBITS;
var CC0_ELF_SECTION_SYMTAB;
var CC0_ELF_SECTION_STRTAB;
var CC0_ELF_SECTION_NOBITS;
var CC0_ELF_SECTION_REL;
var CC0_ELF_FLAG_WRITE;
var CC0_ELF_FLAG_ALLOC;
var CC0_ELF_FLAG_EXECUTE;
var CC0_ELF_SYMBOL_BYTES;
var CC0_ELF_SYMBOL_ADDRESS_SHIFT;
var CC0_ELF_RELOCATION_BYTES;
var CC0_ELF_SYMBOL_NAME_OFFSET;
var CC0_ELF_SYMBOL_VALUE_OFFSET;
var CC0_ELF_SYMBOL_SIZE_OFFSET;
var CC0_ELF_SYMBOL_INFO_OFFSET;
var CC0_ELF_SYMBOL_OTHER_OFFSET;
var CC0_ELF_SYMBOL_SECTION_OFFSET;
var CC0_ELF_TEXT_SECTION;
var CC0_ELF_DATA_SECTION;
var CC0_ELF_BSS_SECTION;
var CC0_ELF_SYMTAB_SECTION;
var CC0_ELF_STRTAB_SECTION;
var CC0_ELF_REL_TEXT_SECTION;
var CC0_ELF_SHSTRTAB_SECTION;
var CC0_ELF_FUNCTION_SYMBOL_INDICES;
var CC0_ELF_GLOBAL_SYMBOL_INDICES;
var CC0_ELF_DATA_SYMBOL_INDEX;
var CC0_ELF_SYMBOL_LOCAL_SECTION;
var CC0_ELF_SYMBOL_GLOBAL_OBJECT;
var CC0_ELF_SYMBOL_GLOBAL_FUNCTION;
var CC0_ELF_SYMBOL_WEAK_FUNCTION;
var CC0_ELF_RELOCATION_ABSOLUTE;
var CC0_ELF_RELOCATION_PC_RELATIVE;
var CC0_ELF_MALLOC_SYMBOL;
var CC0_ELF_OPEN_SYMBOL;
var CC0_ELF_LSEEK_SYMBOL;
var CC0_ELF_READ_SYMBOL;
var CC0_ELF_WRITE_SYMBOL;
var CC0_ELF_CLOSE_SYMBOL;
var CC0_ELF_SYSTEM_SYMBOL;
var CC0_ELF_CC1_LINK_SYMBOL;
var CC0_ELF_CHMOD_SYMBOL;
var CC0_ELF_LEXER_START_SYMBOL;
var CC0_ELF_LEXER_ADVANCE_SYMBOL;
var CC0_ELF_LEXER_FIELD_SYMBOL;
var CC0_ELF_CC0_COMPILE_SYMBOL;
var CC0_ELF_CC1_COMPILE_SYMBOL;
var CC0_ELF_CC1_COMPILE_BASE_SYMBOL;
var CC0_ELF_CC2_COMPILE_SYMBOL;
var CC0_ELF_REMAP_ERROR_SYMBOL;
var CC0_ELF_REMAP_LOCATION_SYMBOL;
var CC0_FILE_READ_ONLY;
var CC0_FILE_WRITE_FLAGS;
var CC0_FILE_CREATE_MODE;
var CC0_FILE_SEEK_START;
var CC0_FILE_SEEK_END;
var CC0_FILE_BYTE;
var CC0_ELF_OUTPUT;
var CC0_ELF_OUTPUT_LENGTH;
var CC0_ELF_HEADER_BYTES;
var CC0_ELF_SECTION_HEADER_BYTES;
var CC0_ELF_TYPE_RELOCATABLE;
var CC0_ELF_MACHINE_I386;
var CC0_ELF_CURRENT_VERSION;
var CC0_ELF_MAGIC_DELETE;
var CC0_ELF_MAGIC_E;
var CC0_ELF_MAGIC_L;
var CC0_ELF_MAGIC_F;
var CC0_ELF_CLASS_32;
var CC0_ELF_DATA_LITTLE_ENDIAN;

function cc0_init()
{
    CC0_FALSE = 0;
    CC0_TRUE = 1;
    CC0_CHARACTER_EOF = sub(0, 1);
    CC0_BYTE_VALUE_COUNT = 256;
    CC0_CHARACTER_SPACE_FLAG = 1;
    CC0_TOKEN_HASH_INITIAL = 1;
    CC0_TOKEN_HASH_LEFT_SHIFT = 5;
    CC0_TOKEN_HASH_RIGHT_SHIFT = 27;
    CC0_TOKEN_HASH_BUCKET_MASK = 16383;
    CC0_WORD_ADDRESS_SHIFT = 2;
    CC0_WORD_BYTES = 4;
    CC0_WORD_BITS = 32;
    CC0_NUMBER_WORD_COUNT = 2;
    CC0_ASCII_TAB = 9;
    CC0_ASCII_LINE_FEED = 10;
    CC0_ASCII_VERTICAL_TAB = 11;
    CC0_ASCII_FORM_FEED = 12;
    CC0_ASCII_CARRIAGE_RETURN = 13;
    CC0_ASCII_SPACE = 32;
    CC0_ASCII_ZERO = 48;
    CC0_ASCII_SEVEN = 55;
    CC0_ASCII_NINE = 57;
    CC0_ASCII_UPPER_A = 65;
    CC0_ASCII_UPPER_Z = 90;
    CC0_ASCII_UNDERSCORE = 95;
    CC0_ASCII_LOWER_A = 97;
    CC0_ASCII_LOWER_Z = 122;
    CC0_ASCII_SLASH = 47;
    CC0_ASCII_STAR = 42;
    CC0_ASCII_BACKSLASH = 92;
    CC0_ASCII_QUOTE = 34;
    CC0_ASCII_APOSTROPHE = 39;
    CC0_ASCII_UPPER_X = 88;
    CC0_ASCII_LOWER_X = 120;
    CC0_ASCII_UPPER_L = 76;
    CC0_ASCII_LOWER_L = 108;
    CC0_ASCII_UPPER_U = 85;
    CC0_ASCII_LOWER_U = 117;
    CC0_ASCII_LOWER_N = 110;
    CC0_ASCII_LOWER_R = 114;
    CC0_ASCII_LOWER_T = 116;
    CC0_TOKEN_EOF = 0;
    CC0_TOKEN_ERROR = 1;
    CC0_TOKEN_IDENTIFIER = 2;
    CC0_TOKEN_NUMBER_LITERAL = 3;
    CC0_TOKEN_STRING_LITERAL = 4;
    CC0_TOKEN_FUNCTION = 5;
    CC0_TOKEN_VAR = 6;
    CC0_TOKEN_RETURN = 7;
    CC0_TOKEN_IF = 8;
    CC0_TOKEN_ELSE = 9;
    CC0_TOKEN_WHILE = 10;
    CC0_TOKEN_BREAK = 11;
    CC0_TOKEN_FOR = 12;
    CC0_TOKEN_DO = 13;
    CC0_TOKEN_CONTINUE = 14;
    CC0_COMPILER_ERROR = CC0_FALSE;
    CC0_LEXER_FIELD_KIND = 0;
    CC0_LEXER_FIELD_TEXT = 1;
    CC0_LEXER_FIELD_LENGTH = 2;
    CC0_LEXER_FIELD_NUMBER = 3;
    CC0_COMPILER_ERROR_POSITION = sub(0, 1);
    CC0_COMPILER_ERROR_FILE = 0;
    CC0_COMPILER_ERROR_LINE = 0;
    CC0_COMPILER_ERROR_COLUMN = 0;
    CC0_DECIMAL_MAX_PLACE = 1000000000;
    CC0_PUNCTUATION_LEFT_PARENTHESIS = 40;
    CC0_PUNCTUATION_RIGHT_PARENTHESIS = 41;
    CC0_PUNCTUATION_LEFT_BRACE = 123;
    CC0_PUNCTUATION_RIGHT_BRACE = 125;
    CC0_PUNCTUATION_SEMICOLON = 59;
    CC0_PUNCTUATION_COMMA = 44;
    CC0_PUNCTUATION_ASSIGN = 61;
    CC0_PUNCTUATION_LEFT_BRACKET = 91;
    CC0_PUNCTUATION_RIGHT_BRACKET = 93;
    CC0_SYMBOL_ENTRY_ADDRESS_SHIFT = 4;
    CC0_INITIAL_ALLOCATION_BYTES = 256;
    CC0_GLOBAL_SYMBOL_CAPACITY = 0;
    CC0_FUNCTION_SYMBOL_CAPACITY = 0;
    CC0_PARAMETER_SYMBOL_CAPACITY = 0;
    CC0_LOCAL_SYMBOL_CAPACITY = 0;
    CC0_CALL_RECORD_CAPACITY = 0;
    CC0_RELOCATION_RECORD_CAPACITY = 0;
    CC0_LOOP_STACK_CAPACITY = 0;
    CC0_BREAK_RECORD_CAPACITY = 0;
    CC0_CONTINUE_RECORD_CAPACITY = 0;
    CC0_SYMBOL_NAME_OFFSET = 0;
    CC0_SYMBOL_LENGTH_OFFSET = 4;
    CC0_SYMBOL_VALUE_OFFSET = 8;
    CC0_SYMBOL_CODE_OFFSET = 12;
    CC0_GLOBAL_SYMBOLS = 0;
    CC0_GLOBAL_COUNT = 0;
    CC0_FUNCTION_SYMBOLS = 0;
    CC0_FUNCTION_COUNT = 0;
    CC0_PARAMETER_SYMBOLS = 0;
    CC0_PARAMETER_COUNT = 0;
    CC0_LOCAL_SYMBOLS = 0;
    CC0_LOCAL_COUNT = 0;
    CC0_CURRENT_NAME_START = 0;
    CC0_CURRENT_NAME_LENGTH = 0;
    CC0_COMPILER_PHASE_COLLECT = 0;
    CC0_COMPILER_PHASE_RESOLVE = 1;
    CC0_COMPILER_PHASE_EMIT = 2;
    CC0_COMPILER_PHASE = CC0_COMPILER_PHASE_COLLECT;
    CC0_CODE_CAPACITY = 0;
    CC0_CODE = 0;
    CC0_CODE_LENGTH = 0;
    CC0_X86_PUSH_EBP = 85;
    CC0_X86_MOV_REGISTER_OPCODE = 137;
    CC0_X86_MOV_EBP_ESP = 229;
    CC0_X86_PUSH_EBX = 83;
    CC0_X86_SUB_ESP_IMMEDIATE = 236;
    CC0_X86_LOAD_REGISTER_OPCODE = 139;
    CC0_X86_LOAD_EBX_FROM_FRAME = 93;
    CC0_X86_SAVED_EBX_DISPLACEMENT = 252;
    CC0_X86_MOV_ESP_EBP = 236;
    CC0_X86_POP_EBP = 93;
    CC0_X86_RETURN = 195;
    CC0_X86_MOV_EAX_IMMEDIATE = 184;
    CC0_X86_PUSH_EAX = 80;
    CC0_X86_POP_EBX = 91;
    CC0_X86_LOAD_EAX_FROM_FRAME = 69;
    CC0_X86_STORE_REGISTER_OPCODE = 137;
    CC0_X86_STORE_EAX_TO_FRAME = 69;
    CC0_X86_LOAD_EAX_FROM_FRAME_WORD = 133;
    CC0_X86_STORE_EAX_TO_FRAME_WORD = 133;
    CC0_X86_LOAD_ADDRESS_OPCODE = 141;
    CC0_X86_LOAD_ADDRESS_FRAME_WORD = 133;
    CC0_X86_TEST_OPCODE = 133;
    CC0_X86_TEST_EAX_EAX = 192;
    CC0_X86_TWO_BYTE_OPCODE = 15;
    CC0_X86_JUMP_IF_ZERO = 132;
    CC0_X86_JUMP_RELATIVE = 233;
    CC0_X86_CALL_RELATIVE = 232;
    CC0_X86_ADD_IMMEDIATE_OPCODE = 129;
    CC0_X86_ADD_ESP_IMMEDIATE = 196;
    CC0_X86_MOV_ECX_EAX = 193;
    CC0_X86_MOV_EAX_EBX = 216;
    CC0_X86_ADD_REGISTER_OPCODE = 1;
    CC0_X86_ADD_EAX_EBX = 216;
    CC0_X86_SUB_REGISTER_OPCODE = 41;
    CC0_X86_SUB_EAX_ECX = 200;
    CC0_X86_SIGNED_MULTIPLY_OPCODE = 175;
    CC0_X86_MULTIPLY_EAX_EBX = 195;
    CC0_X86_SIGN_EXTEND_EAX = 153;
    CC0_X86_DIVIDE_OPCODE = 247;
    CC0_X86_DIVIDE_BY_ECX = 249;
    CC0_X86_MOV_EAX_EDX = 208;
    CC0_X86_AND_REGISTER_OPCODE = 33;
    CC0_X86_AND_EAX_EBX = 216;
    CC0_X86_OR_REGISTER_OPCODE = 9;
    CC0_X86_OR_EAX_EBX = 216;
    CC0_X86_XOR_REGISTER_OPCODE = 49;
    CC0_X86_XOR_EAX_EBX = 216;
    CC0_X86_COMPLEMENT_EAX = 208;
    CC0_X86_SHIFT_BY_CL_OPCODE = 211;
    CC0_X86_SHIFT_LEFT_EBX = 227;
    CC0_X86_SHIFT_RIGHT_EBX = 235;
    CC0_X86_SHIFT_RIGHT_SIGNED_EBX = 251;
    CC0_X86_COMPARE_OPCODE = 57;
    CC0_X86_COMPARE_EBX_EAX = 195;
    CC0_X86_SET_EQUAL = 148;
    CC0_X86_SET_LESS = 156;
    CC0_X86_SET_LESS_EQUAL = 158;
    CC0_X86_SET_EAX_BYTE = 192;
    CC0_X86_ZERO_EXTEND_OPCODE = 182;
    CC0_X86_ZERO_EXTEND_EAX_BYTE = 192;
    CC0_X86_LOAD_EAX_ADDRESS = 0;
    CC0_X86_LOAD_EAX_BYTE_ADDRESS = 0;
    CC0_X86_STORE_EAX_ADDRESS = 3;
    CC0_X86_STORE_EAX_BYTE_ADDRESS_OPCODE = 136;
    CC0_X86_STORE_EAX_BYTE_ADDRESS = 3;
    CC0_X86_LOAD_EAX_ABSOLUTE = 161;
    CC0_X86_STORE_EAX_ABSOLUTE = 163;
    CC0_DATA_CAPACITY = 0;
    CC0_DATA = 0;
    CC0_DATA_LENGTH = 0;
    CC0_CALL_RECORDS = 0;
    CC0_CALL_COUNT = 0;
    CC0_RELOCATION_RECORDS = 0;
    CC0_RELOCATION_COUNT = 0;
    CC0_X86_STACK_ADDRESS_SUFFIX = 36;
    CC0_X86_LOAD_EAX_STACK = 132;
    CC0_X86_LOAD_EBX_STACK = 156;
    CC0_X86_STORE_EBX_STACK = 156;
    CC0_X86_STORE_EAX_STACK = 132;
    CC0_PARAMETER_FIRST_OFFSET = 8;
    CC0_LOOP_STACK = 0;
    CC0_LOOP_DEPTH = 0;
    CC0_NEXT_LOOP_ID = 0;
    CC0_BREAK_RECORDS = 0;
    CC0_BREAK_COUNT = 0;
    CC0_CONTINUE_RECORDS = 0;
    CC0_CONTINUE_COUNT = 0;
    CC0_X86_JUMP_IF_NOT_ZERO = 133;
    CC0_MAIN_USAGE_ERROR = 2;
    CC0_MAIN_INPUT_ERROR = 3;
    CC0_MAIN_COMPILE_ERROR = 5;
    CC0_MAIN_OUTPUT_ERROR = 6;
    CC0_MAIN_LINK_ERROR = 7;
    CC0_STANDARD_OUTPUT = 1;
    CC0_STANDARD_ERROR = 2;
    CC0_SECTION_ENTRY_ADDRESS_SHIFT = 6;
    CC0_SECTION_CAPACITY = 0;
    CC0_SECTIONS = 0;
    CC0_SECTION_COUNT = 0;
    CC0_SECTION_NAME_OFFSET = 0;
    CC0_SECTION_NAME_LENGTH_OFFSET = 4;
    CC0_SECTION_TYPE_OFFSET = 8;
    CC0_SECTION_FLAGS_OFFSET = 12;
    CC0_SECTION_ALIGNMENT_OFFSET = 16;
    CC0_SECTION_ENTRY_SIZE_OFFSET = 20;
    CC0_SECTION_LINK_OFFSET = 24;
    CC0_SECTION_INFO_OFFSET = 28;
    CC0_SECTION_DATA_OFFSET = 32;
    CC0_SECTION_CAPACITY_OFFSET = 36;
    CC0_SECTION_SIZE_OFFSET = 40;
    CC0_SECTION_FILE_OFFSET = 44;
    CC0_SECTION_NUMBER_OFFSET = 48;
    CC0_SECTION_INITIAL_DATA_CAPACITY = 256;
    CC0_ELF_SECTION_PROGBITS = 1;
    CC0_ELF_SECTION_SYMTAB = 2;
    CC0_ELF_SECTION_STRTAB = 3;
    CC0_ELF_SECTION_NOBITS = 8;
    CC0_ELF_SECTION_REL = 9;
    CC0_ELF_FLAG_WRITE = 1;
    CC0_ELF_FLAG_ALLOC = 2;
    CC0_ELF_FLAG_EXECUTE = 4;
    CC0_ELF_SYMBOL_BYTES = 16;
    CC0_ELF_SYMBOL_ADDRESS_SHIFT = 4;
    CC0_ELF_RELOCATION_BYTES = 8;
    CC0_ELF_SYMBOL_NAME_OFFSET = 0;
    CC0_ELF_SYMBOL_VALUE_OFFSET = 4;
    CC0_ELF_SYMBOL_SIZE_OFFSET = 8;
    CC0_ELF_SYMBOL_INFO_OFFSET = 12;
    CC0_ELF_SYMBOL_OTHER_OFFSET = 13;
    CC0_ELF_SYMBOL_SECTION_OFFSET = 14;
    CC0_ELF_TEXT_SECTION = 0;
    CC0_ELF_DATA_SECTION = 0;
    CC0_ELF_BSS_SECTION = 0;
    CC0_ELF_SYMTAB_SECTION = 0;
    CC0_ELF_STRTAB_SECTION = 0;
    CC0_ELF_REL_TEXT_SECTION = 0;
    CC0_ELF_SHSTRTAB_SECTION = 0;
    CC0_ELF_FUNCTION_SYMBOL_INDICES = 0;
    CC0_ELF_GLOBAL_SYMBOL_INDICES = 0;
    CC0_ELF_DATA_SYMBOL_INDEX = 0;
    CC0_ELF_SYMBOL_LOCAL_SECTION = 3;
    CC0_ELF_SYMBOL_GLOBAL_OBJECT = 17;
    CC0_ELF_SYMBOL_GLOBAL_FUNCTION = 18;
    CC0_ELF_SYMBOL_WEAK_FUNCTION = 34;
    CC0_ELF_RELOCATION_ABSOLUTE = 1;
    CC0_ELF_RELOCATION_PC_RELATIVE = 2;
    CC0_ELF_MALLOC_SYMBOL = 0;
    CC0_ELF_OPEN_SYMBOL = 0;
    CC0_ELF_LSEEK_SYMBOL = 0;
    CC0_ELF_READ_SYMBOL = 0;
    CC0_ELF_WRITE_SYMBOL = 0;
    CC0_ELF_CLOSE_SYMBOL = 0;
    CC0_ELF_SYSTEM_SYMBOL = 0;
    CC0_ELF_CC1_LINK_SYMBOL = 0;
    CC0_ELF_CHMOD_SYMBOL = 0;
    CC0_ELF_LEXER_START_SYMBOL = 0;
    CC0_ELF_LEXER_ADVANCE_SYMBOL = 0;
    CC0_ELF_LEXER_FIELD_SYMBOL = 0;
    CC0_ELF_CC0_COMPILE_SYMBOL = 0;
    CC0_ELF_CC1_COMPILE_SYMBOL = 0;
    CC0_ELF_CC1_COMPILE_BASE_SYMBOL = 0;
    CC0_ELF_CC2_COMPILE_SYMBOL = 0;
    CC0_ELF_REMAP_ERROR_SYMBOL = 0;
    CC0_ELF_REMAP_LOCATION_SYMBOL = 0;
    CC0_FILE_READ_ONLY = 0;
    CC0_FILE_WRITE_FLAGS = 577;
    CC0_FILE_CREATE_MODE = 438;
    CC0_FILE_SEEK_START = 0;
    CC0_FILE_SEEK_END = 2;
    CC0_FILE_BYTE = 0;
    CC0_ELF_OUTPUT = 0;
    CC0_ELF_OUTPUT_LENGTH = 0;
    CC0_ELF_HEADER_BYTES = 52;
    CC0_ELF_SECTION_HEADER_BYTES = 40;
    CC0_ELF_TYPE_RELOCATABLE = 1;
    CC0_ELF_MACHINE_I386 = 3;
    CC0_ELF_CURRENT_VERSION = 1;
    CC0_ELF_MAGIC_DELETE = 127;
    CC0_ELF_MAGIC_E = 69;
    CC0_ELF_MAGIC_L = 76;
    CC0_ELF_MAGIC_F = 70;
    CC0_ELF_CLASS_32 = 1;
    CC0_ELF_DATA_LITTLE_ENDIAN = 1;
    CC0_FILE_BYTE = malloc(1);
    return CC0_FALSE;
}

/* Flat section records mirror the fields cc0 needs from TCC's Section. */
function cc0_elf_section_entry(index)
{
    return add(CC0_SECTIONS, shl(index, CC0_SECTION_ENTRY_ADDRESS_SHIFT));
}

function cc0_compiler_grown_capacity_(capacity, needed, grown)
{
    grown = capacity;
    if (eq(grown, 0)) {
        grown = CC0_INITIAL_ALLOCATION_BYTES;
    }
    while (lt(grown, needed)) {
        grown = shl(grown, 1);
    }
    return grown;
}

function cc0_compiler_grown_capacity(capacity, needed)
{
    return cc0_compiler_grown_capacity_(capacity, needed, 0);
}

/* cc0's bump allocator cannot resize, so growing storage is copied forward. */
function cc0_compiler_grow_memory_(memory, used, capacity, needed,
    new_capacity, new_memory)
{
    if (le(needed, capacity)) {
        return memory;
    }
    new_capacity = cc0_compiler_grown_capacity(capacity, needed);
    new_memory = alloc(new_capacity);
    if (eq(new_memory, 0)) {
        return 0;
    }
    if (not(eq(memory, 0))) {
        cc0_compiler_copy_bytes(new_memory, memory, used);
    }
    return new_memory;
}

function cc0_compiler_grow_memory(memory, used, capacity, needed)
{
    return cc0_compiler_grow_memory_(memory, used, capacity, needed, 0, 0);
}

function cc0_compiler_copy_bytes_(destination, source, count, index)
{
    index = 0;
    while (lt(index, count)) {
        wi8(add(destination, index), ri8(add(source, index)));
        index = add(index, 1);
    }
    return destination;
}

function cc0_compiler_copy_bytes(destination, source, count)
{
    return cc0_compiler_copy_bytes_(destination, source, count, 0);
}

function cc0_elf_prepare_sections()
{
    CC0_SECTION_COUNT = 1;
    return CC0_FALSE;
}

function cc0_elf_reserve_section_entries_(needed, needed_bytes, old_bytes,
    new_bytes, sections)
{
    if (le(needed, CC0_SECTION_CAPACITY)) {
        return CC0_FALSE;
    }
    needed_bytes = shl(needed, CC0_SECTION_ENTRY_ADDRESS_SHIFT);
    old_bytes = shl(CC0_SECTION_CAPACITY,
        CC0_SECTION_ENTRY_ADDRESS_SHIFT);
    new_bytes = cc0_compiler_grown_capacity(old_bytes, needed_bytes);
    sections = cc0_compiler_grow_memory(CC0_SECTIONS, old_bytes, old_bytes,
        needed_bytes);
    if (eq(sections, 0)) {
        return cc0_compiler_fail();
    }
    CC0_SECTIONS = sections;
    CC0_SECTION_CAPACITY = ushr(new_bytes,
        CC0_SECTION_ENTRY_ADDRESS_SHIFT);
    return CC0_FALSE;
}

function cc0_elf_reserve_section_entries(needed)
{
    return cc0_elf_reserve_section_entries_(needed, 0, 0, 0, 0);
}

function cc0_elf_new_section_(name, length, type, flags, section, alignment)
{
    if (cc0_elf_reserve_section_entries(add(CC0_SECTION_COUNT, 1))) {
        return 0;
    }
    section = cc0_elf_section_entry(CC0_SECTION_COUNT);
    alignment = CC0_WORD_BYTES;
    if (eq(type, CC0_ELF_SECTION_STRTAB)) {
        alignment = 1;
    }
    wi32(add(section, CC0_SECTION_NAME_OFFSET), name);
    wi32(add(section, CC0_SECTION_NAME_LENGTH_OFFSET), length);
    wi32(add(section, CC0_SECTION_TYPE_OFFSET), type);
    wi32(add(section, CC0_SECTION_FLAGS_OFFSET), flags);
    wi32(add(section, CC0_SECTION_ALIGNMENT_OFFSET), alignment);
    wi32(add(section, CC0_SECTION_ENTRY_SIZE_OFFSET), 0);
    wi32(add(section, CC0_SECTION_LINK_OFFSET), 0);
    wi32(add(section, CC0_SECTION_INFO_OFFSET), 0);
    wi32(add(section, CC0_SECTION_DATA_OFFSET), 0);
    wi32(add(section, CC0_SECTION_CAPACITY_OFFSET), 0);
    wi32(add(section, CC0_SECTION_SIZE_OFFSET), 0);
    wi32(add(section, CC0_SECTION_FILE_OFFSET), 0);
    wi32(add(section, CC0_SECTION_NUMBER_OFFSET), CC0_SECTION_COUNT);
    CC0_SECTION_COUNT = add(CC0_SECTION_COUNT, 1);
    return section;
}

function cc0_elf_new_section(name, length, type, flags)
{
    return cc0_elf_new_section_(name, length, type, flags, 0, 0);
}

/* TCC's section_realloc grows payload storage geometrically. */
function cc0_elf_section_reserve_(section, needed, capacity, new_capacity,
    old_data, new_data)
{
    capacity = ri32(add(section, CC0_SECTION_CAPACITY_OFFSET));
    if (le(needed, capacity)) {
        return CC0_FALSE;
    }
    new_capacity = capacity;
    if (eq(new_capacity, 0)) {
        new_capacity = CC0_SECTION_INITIAL_DATA_CAPACITY;
    }
    while (lt(new_capacity, needed)) {
        new_capacity = shl(new_capacity, 1);
    }
    new_data = alloc(new_capacity);
    if (eq(new_data, 0)) {
        return cc0_compiler_fail();
    }
    old_data = ri32(add(section, CC0_SECTION_DATA_OFFSET));
    if (not(eq(old_data, 0))) {
        cc0_compiler_copy_bytes(new_data, old_data,
            ri32(add(section, CC0_SECTION_SIZE_OFFSET)));
    }
    wi32(add(section, CC0_SECTION_DATA_OFFSET), new_data);
    wi32(add(section, CC0_SECTION_CAPACITY_OFFSET), new_capacity);
    return CC0_FALSE;
}

function cc0_elf_section_reserve(section, needed)
{
    return cc0_elf_section_reserve_(section, needed, 0, 0, 0, 0);
}

/* This is the cc0 form of TCC's section_ptr_add. */
function cc0_elf_section_ptr_add_(section, size, old_size, new_size, pointer)
{
    old_size = ri32(add(section, CC0_SECTION_SIZE_OFFSET));
    new_size = add(old_size, size);
    if (not(eq(ri32(add(section, CC0_SECTION_TYPE_OFFSET)),
        CC0_ELF_SECTION_NOBITS))) {
        if (cc0_elf_section_reserve(section, new_size)) {
            return 0;
        }
    }
    wi32(add(section, CC0_SECTION_SIZE_OFFSET), new_size);
    pointer = ri32(add(section, CC0_SECTION_DATA_OFFSET));
    if (eq(pointer, 0)) {
        return 0;
    }
    return add(pointer, old_size);
}

function cc0_elf_section_ptr_add(section, size)
{
    return cc0_elf_section_ptr_add_(section, size, 0, 0, 0);
}

function cc0_elf_put_string_(section, value, length, offset, destination)
{
    offset = ri32(add(section, CC0_SECTION_SIZE_OFFSET));
    destination = cc0_elf_section_ptr_add(section, add(length, 1));
    if (eq(destination, 0)) {
        return sub(0, 1);
    }
    cc0_compiler_copy_bytes(destination, value, length);
    wi8(add(destination, length), 0);
    return offset;
}

function cc0_elf_put_string(section, value, length)
{
    return cc0_elf_put_string_(section, value, length, 0, 0);
}

/* Emit the Elf32_Sym byte layout used by TCC's put_elf_sym. */
function cc0_elf_put_symbol_(symtab, strtab, name, length, value, size, info,
    other, section_number, symbol, name_offset, symbol_offset)
{
    name_offset = 0;
    if (not(eq(length, 0))) {
        name_offset = cc0_elf_put_string(strtab, name, length);
        if (lt(name_offset, 0)) {
            return sub(0, 1);
        }
    }
    symbol_offset = ri32(add(symtab, CC0_SECTION_SIZE_OFFSET));
    symbol = cc0_elf_section_ptr_add(symtab, CC0_ELF_SYMBOL_BYTES);
    if (eq(symbol, 0)) {
        return sub(0, 1);
    }
    wi32(add(symbol, CC0_ELF_SYMBOL_NAME_OFFSET), name_offset);
    wi32(add(symbol, CC0_ELF_SYMBOL_VALUE_OFFSET), value);
    wi32(add(symbol, CC0_ELF_SYMBOL_SIZE_OFFSET), size);
    wi8(add(symbol, CC0_ELF_SYMBOL_INFO_OFFSET), info);
    wi8(add(symbol, CC0_ELF_SYMBOL_OTHER_OFFSET), other);
    wi8(add(symbol, CC0_ELF_SYMBOL_SECTION_OFFSET), and(section_number, 255));
    wi8(add(add(symbol, CC0_ELF_SYMBOL_SECTION_OFFSET), 1),
        ushr(section_number, 8));
    return ushr(symbol_offset, CC0_ELF_SYMBOL_ADDRESS_SHIFT);
}

function cc0_elf_put_symbol(symtab, strtab, name, length, value, size, info,
    other, section_number)
{
    return cc0_elf_put_symbol_(symtab, strtab, name, length, value, size,
        info, other, section_number, 0, 0, 0);
}

/* i386 ET_REL objects use Elf32_Rel, with the addend stored in .text. */
function cc0_elf_put_relocation_(section, offset, symbol, type, record, info)
{
    record = cc0_elf_section_ptr_add(section, CC0_ELF_RELOCATION_BYTES);
    if (eq(record, 0)) {
        return cc0_compiler_fail();
    }
    info = add(shl(symbol, 8), type);
    wi32(record, offset);
    wi32(add(record, CC0_WORD_BYTES), info);
    return CC0_FALSE;
}

function cc0_elf_put_relocation(section, offset, symbol, type)
{
    return cc0_elf_put_relocation_(section, offset, symbol, type, 0, 0);
}

function cc0_elf_section_number(section)
{
    return ri32(add(section, CC0_SECTION_NUMBER_OFFSET));
}

function cc0_elf_copy_section_(section, source, size, destination)
{
    destination = cc0_elf_section_ptr_add(section, size);
    if (eq(destination, 0)) {
        return cc0_compiler_fail();
    }
    cc0_compiler_copy_bytes(destination, source, size);
    return CC0_FALSE;
}

function cc0_elf_copy_section(section, source, size)
{
    return cc0_elf_copy_section_(section, source, size, 0);
}

/* Create the standard sections in the same order as TCC's tccelf_new. */
function cc0_elf_prepare_object_sections()
{
    if (cc0_elf_prepare_sections()) {
        return CC0_TRUE;
    }
    /* Reserve the complete standard set so record addresses stay stable. */
    if (cc0_elf_reserve_section_entries(8)) {
        return CC0_TRUE;
    }
    CC0_ELF_TEXT_SECTION = cc0_elf_new_section(mks(".text"), 5,
        CC0_ELF_SECTION_PROGBITS,
        add(CC0_ELF_FLAG_ALLOC, CC0_ELF_FLAG_EXECUTE));
    CC0_ELF_DATA_SECTION = cc0_elf_new_section(mks(".data"), 5,
        CC0_ELF_SECTION_PROGBITS,
        add(CC0_ELF_FLAG_ALLOC, CC0_ELF_FLAG_WRITE));
    CC0_ELF_BSS_SECTION = cc0_elf_new_section(mks(".bss"), 4,
        CC0_ELF_SECTION_NOBITS,
        add(CC0_ELF_FLAG_ALLOC, CC0_ELF_FLAG_WRITE));
    CC0_ELF_SYMTAB_SECTION = cc0_elf_new_section(mks(".symtab"), 7,
        CC0_ELF_SECTION_SYMTAB, 0);
    CC0_ELF_STRTAB_SECTION = cc0_elf_new_section(mks(".strtab"), 7,
        CC0_ELF_SECTION_STRTAB, 0);
    CC0_ELF_REL_TEXT_SECTION = cc0_elf_new_section(mks(".rel.text"), 9,
        CC0_ELF_SECTION_REL, 0);
    if (eq(CC0_ELF_REL_TEXT_SECTION, 0)) {
        return cc0_compiler_fail();
    }
    wi32(add(CC0_ELF_SYMTAB_SECTION, CC0_SECTION_ENTRY_SIZE_OFFSET),
        CC0_ELF_SYMBOL_BYTES);
    wi32(add(CC0_ELF_SYMTAB_SECTION, CC0_SECTION_LINK_OFFSET),
        cc0_elf_section_number(CC0_ELF_STRTAB_SECTION));
    wi32(add(CC0_ELF_REL_TEXT_SECTION, CC0_SECTION_ENTRY_SIZE_OFFSET),
        CC0_ELF_RELOCATION_BYTES);
    wi32(add(CC0_ELF_REL_TEXT_SECTION, CC0_SECTION_LINK_OFFSET),
        cc0_elf_section_number(CC0_ELF_SYMTAB_SECTION));
    wi32(add(CC0_ELF_REL_TEXT_SECTION, CC0_SECTION_INFO_OFFSET),
        cc0_elf_section_number(CC0_ELF_TEXT_SECTION));
    return CC0_FALSE;
}

function cc0_elf_prepare_symbol_indices()
{
    CC0_ELF_FUNCTION_SYMBOL_INDICES = alloc(shl(add(CC0_FUNCTION_COUNT, 1),
        CC0_WORD_ADDRESS_SHIFT));
    CC0_ELF_GLOBAL_SYMBOL_INDICES = alloc(shl(add(CC0_GLOBAL_COUNT, 1),
        CC0_WORD_ADDRESS_SHIFT));
    if (eq(CC0_ELF_FUNCTION_SYMBOL_INDICES, 0)) {
        return cc0_compiler_fail();
    }
    if (eq(CC0_ELF_GLOBAL_SYMBOL_INDICES, 0)) {
        return cc0_compiler_fail();
    }
    return CC0_FALSE;
}

function cc0_elf_emit_function_symbols_(index, entry, next_entry, offset,
    size, symbol, info)
{
    index = 0;
    while (lt(index, CC0_FUNCTION_COUNT)) {
        entry = cc0_compiler_symbol_entry(CC0_FUNCTION_SYMBOLS, index);
        offset = ri32(add(entry, CC0_SYMBOL_CODE_OFFSET));
        size = sub(CC0_CODE_LENGTH, offset);
        if (lt(add(index, 1), CC0_FUNCTION_COUNT)) {
            next_entry = cc0_compiler_symbol_entry(CC0_FUNCTION_SYMBOLS,
                add(index, 1));
            size = sub(ri32(add(next_entry, CC0_SYMBOL_CODE_OFFSET)), offset);
        }
        info = CC0_ELF_SYMBOL_GLOBAL_FUNCTION;
        /* A final layered executable supplies its own strong driver. */
        if (cc0_compiler_slice_equal(
            ri32(add(entry, CC0_SYMBOL_NAME_OFFSET)),
            ri32(add(entry, CC0_SYMBOL_LENGTH_OFFSET)), mks("main"), 4)) {
            info = CC0_ELF_SYMBOL_WEAK_FUNCTION;
        }
        symbol = cc0_elf_put_symbol(CC0_ELF_SYMTAB_SECTION,
            CC0_ELF_STRTAB_SECTION,
            ri32(add(entry, CC0_SYMBOL_NAME_OFFSET)),
            ri32(add(entry, CC0_SYMBOL_LENGTH_OFFSET)), offset, size,
            info, 0,
            cc0_elf_section_number(CC0_ELF_TEXT_SECTION));
        if (lt(symbol, 0)) {
            return cc0_compiler_fail();
        }
        wi32(add(CC0_ELF_FUNCTION_SYMBOL_INDICES,
            shl(index, CC0_WORD_ADDRESS_SHIFT)), symbol);
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_elf_emit_function_symbols()
{
    return cc0_elf_emit_function_symbols_(0, 0, 0, 0, 0, 0, 0);
}

function cc0_elf_emit_global_symbols_(index, entry, symbol, offset, section,
    size)
{
    index = 0;
    while (lt(index, CC0_GLOBAL_COUNT)) {
        entry = cc0_compiler_symbol_entry(CC0_GLOBAL_SYMBOLS, index);
        offset = ri32(add(entry, CC0_SYMBOL_CODE_OFFSET));
        section = CC0_ELF_DATA_SECTION;
        size = CC0_WORD_BYTES;
        if (lt(offset, 0)) {
            /* Negative offsets encode -(bss offset + 1). */
            offset = sub(sub(0, offset), 1);
            section = CC0_ELF_BSS_SECTION;
            size = ri32(add(entry, CC0_SYMBOL_VALUE_OFFSET));
        }
        symbol = cc0_elf_put_symbol(CC0_ELF_SYMTAB_SECTION,
            CC0_ELF_STRTAB_SECTION,
            ri32(add(entry, CC0_SYMBOL_NAME_OFFSET)),
            ri32(add(entry, CC0_SYMBOL_LENGTH_OFFSET)), offset,
            size, CC0_ELF_SYMBOL_GLOBAL_OBJECT, 0,
            cc0_elf_section_number(section));
        if (lt(symbol, 0)) {
            return cc0_compiler_fail();
        }
        wi32(add(CC0_ELF_GLOBAL_SYMBOL_INDICES,
            shl(index, CC0_WORD_ADDRESS_SHIFT)), symbol);
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_elf_emit_global_symbols()
{
    return cc0_elf_emit_global_symbols_(0, 0, 0, 0, 0, 0);
}

/* Assign storage after strings have been emitted, so their offsets stay stable. */
function cc0_elf_layout_globals_(index, entry, offset, bss_bytes)
{
    index = 0;
    bss_bytes = 0;
    while (lt(index, CC0_GLOBAL_COUNT)) {
        entry = cc0_compiler_symbol_entry(CC0_GLOBAL_SYMBOLS, index);
        if (ri32(add(entry, CC0_SYMBOL_CODE_OFFSET))) {
            offset = CC0_DATA_LENGTH;
            if (cc0_compiler_ensure_data(add(offset, CC0_WORD_BYTES))) {
                return sub(0, 1);
            }
            wi32(add(CC0_DATA, offset),
                ri32(add(entry, CC0_SYMBOL_VALUE_OFFSET)));
            CC0_DATA_LENGTH = add(CC0_DATA_LENGTH, CC0_WORD_BYTES);
            wi32(add(entry, CC0_SYMBOL_CODE_OFFSET), offset);
        } else {
            wi32(add(entry, CC0_SYMBOL_CODE_OFFSET),
                sub(0, add(bss_bytes, 1)));
            bss_bytes = add(bss_bytes,
                ri32(add(entry, CC0_SYMBOL_VALUE_OFFSET)));
        }
        index = add(index, 1);
    }
    return bss_bytes;
}

function cc0_elf_layout_globals()
{
    return cc0_elf_layout_globals_(0, 0, 0, 0);
}

function cc0_elf_put_undefined_function(name, length)
{
    return cc0_elf_put_symbol(CC0_ELF_SYMTAB_SECTION,
        CC0_ELF_STRTAB_SECTION, name, length, 0, 0,
        CC0_ELF_SYMBOL_GLOBAL_FUNCTION, 0, 0);
}

/* External symbols are created lazily when a relocation actually uses them. */
function cc0_elf_emit_external_symbols()
{
    CC0_ELF_MALLOC_SYMBOL = 0;
    CC0_ELF_OPEN_SYMBOL = 0;
    CC0_ELF_LSEEK_SYMBOL = 0;
    CC0_ELF_READ_SYMBOL = 0;
    CC0_ELF_WRITE_SYMBOL = 0;
    CC0_ELF_CLOSE_SYMBOL = 0;
    CC0_ELF_SYSTEM_SYMBOL = 0;
    CC0_ELF_CC1_LINK_SYMBOL = 0;
    CC0_ELF_CHMOD_SYMBOL = 0;
    CC0_ELF_LEXER_START_SYMBOL = 0;
    CC0_ELF_LEXER_ADVANCE_SYMBOL = 0;
    CC0_ELF_LEXER_FIELD_SYMBOL = 0;
    CC0_ELF_CC0_COMPILE_SYMBOL = 0;
    CC0_ELF_CC1_COMPILE_SYMBOL = 0;
    CC0_ELF_CC1_COMPILE_BASE_SYMBOL = 0;
    CC0_ELF_CC2_COMPILE_SYMBOL = 0;
    CC0_ELF_REMAP_ERROR_SYMBOL = 0;
    CC0_ELF_REMAP_LOCATION_SYMBOL = 0;
    return CC0_FALSE;
}

function cc0_elf_external_symbol(name, length)
{
    if (cc0_compiler_slice_equal(name, length, mks("malloc"), 6)) {
        if (eq(CC0_ELF_MALLOC_SYMBOL, 0)) {
            CC0_ELF_MALLOC_SYMBOL = cc0_elf_put_undefined_function(
                mks("malloc"), 6);
        }
        return CC0_ELF_MALLOC_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("realloc"), 7)) {
        return cc0_elf_put_undefined_function(mks("realloc"), 7);
    }
    if (cc0_compiler_slice_equal(name, length, mks("alloc"), 5)) {
        return cc0_elf_put_undefined_function(mks("alloc"), 5);
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("gen_vla_sp_restore"), 18)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("sym_redeclaration_error"), 23)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("vstack_overflow_error"), 21)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("gv"), 2)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("o"), 1)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("gsym"), 4)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("put_extern_sym"), 14)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("update_storage"), 14)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("save_reg_upstack"), 16)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("store"), 5)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("load"), 4)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("get_tok_str"), 11)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("tcc_error"), 9)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("tcc_warning"), 11)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("next"), 4)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("unary"), 5)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("gen_op"), 6)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("gen_cast_s"), 10)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("gvtst"), 5)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("gen_cast"), 8)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("gen_assign_cast"), 15)) {
        return cc0_elf_put_undefined_function(name, length);
    }
    if (cc0_compiler_slice_equal(name, length, mks("open"), 4)) {
        if (eq(CC0_ELF_OPEN_SYMBOL, 0)) {
            CC0_ELF_OPEN_SYMBOL = cc0_elf_put_undefined_function(
                mks("open"), 4);
        }
        return CC0_ELF_OPEN_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("lseek"), 5)) {
        if (eq(CC0_ELF_LSEEK_SYMBOL, 0)) {
            CC0_ELF_LSEEK_SYMBOL = cc0_elf_put_undefined_function(
                mks("lseek"), 5);
        }
        return CC0_ELF_LSEEK_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("read"), 4)) {
        if (eq(CC0_ELF_READ_SYMBOL, 0)) {
            CC0_ELF_READ_SYMBOL = cc0_elf_put_undefined_function(
                mks("read"), 4);
        }
        return CC0_ELF_READ_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("write"), 5)) {
        if (eq(CC0_ELF_WRITE_SYMBOL, 0)) {
            CC0_ELF_WRITE_SYMBOL = cc0_elf_put_undefined_function(
                mks("write"), 5);
        }
        return CC0_ELF_WRITE_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("close"), 5)) {
        if (eq(CC0_ELF_CLOSE_SYMBOL, 0)) {
            CC0_ELF_CLOSE_SYMBOL = cc0_elf_put_undefined_function(
                mks("close"), 5);
        }
        return CC0_ELF_CLOSE_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("system"), 6)) {
        if (eq(CC0_ELF_SYSTEM_SYMBOL, 0)) {
            CC0_ELF_SYSTEM_SYMBOL = cc0_elf_put_undefined_function(
                mks("system"), 6);
        }
        return CC0_ELF_SYSTEM_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("cc1_link"), 8)) {
        if (eq(CC0_ELF_CC1_LINK_SYMBOL, 0)) {
            CC0_ELF_CC1_LINK_SYMBOL = cc0_elf_put_undefined_function(
                mks("cc1_link"), 8);
        }
        return CC0_ELF_CC1_LINK_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("chmod"), 5)) {
        if (eq(CC0_ELF_CHMOD_SYMBOL, 0)) {
            CC0_ELF_CHMOD_SYMBOL = cc0_elf_put_undefined_function(
                mks("chmod"), 5);
        }
        return CC0_ELF_CHMOD_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("cc0_lexer_start"), 15)) {
        if (eq(CC0_ELF_LEXER_START_SYMBOL, 0)) {
            CC0_ELF_LEXER_START_SYMBOL = cc0_elf_put_undefined_function(
                mks("cc0_lexer_start"), 15);
        }
        return CC0_ELF_LEXER_START_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("cc0_lexer_advance"), 17)) {
        if (eq(CC0_ELF_LEXER_ADVANCE_SYMBOL, 0)) {
            CC0_ELF_LEXER_ADVANCE_SYMBOL = cc0_elf_put_undefined_function(
                mks("cc0_lexer_advance"), 17);
        }
        return CC0_ELF_LEXER_ADVANCE_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("cc0_lexer_field"), 15)) {
        if (eq(CC0_ELF_LEXER_FIELD_SYMBOL, 0)) {
            CC0_ELF_LEXER_FIELD_SYMBOL = cc0_elf_put_undefined_function(
                mks("cc0_lexer_field"), 15);
        }
        return CC0_ELF_LEXER_FIELD_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("cc0_compile"), 11)) {
        if (eq(CC0_ELF_CC0_COMPILE_SYMBOL, 0)) {
            CC0_ELF_CC0_COMPILE_SYMBOL = cc0_elf_put_undefined_function(
                mks("cc0_compile"), 11);
        }
        return CC0_ELF_CC0_COMPILE_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("cc1_compile"), 11)) {
        if (eq(CC0_ELF_CC1_COMPILE_SYMBOL, 0)) {
            CC0_ELF_CC1_COMPILE_SYMBOL = cc0_elf_put_undefined_function(
                mks("cc1_compile"), 11);
        }
        return CC0_ELF_CC1_COMPILE_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("cc1_compile_base"), 16)) {
        if (eq(CC0_ELF_CC1_COMPILE_BASE_SYMBOL, 0)) {
            CC0_ELF_CC1_COMPILE_BASE_SYMBOL =
                cc0_elf_put_undefined_function(mks("cc1_compile_base"), 16);
        }
        return CC0_ELF_CC1_COMPILE_BASE_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length, mks("cc2_compile"), 11)) {
        if (eq(CC0_ELF_CC2_COMPILE_SYMBOL, 0)) {
            CC0_ELF_CC2_COMPILE_SYMBOL = cc0_elf_put_undefined_function(
                mks("cc2_compile"), 11);
        }
        return CC0_ELF_CC2_COMPILE_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("cc0_remap_error"), 15)) {
        if (eq(CC0_ELF_REMAP_ERROR_SYMBOL, 0)) {
            CC0_ELF_REMAP_ERROR_SYMBOL = cc0_elf_put_undefined_function(
                mks("cc0_remap_error"), 15);
        }
        return CC0_ELF_REMAP_ERROR_SYMBOL;
    }
    if (cc0_compiler_slice_equal(name, length,
        mks("cc0_remap_error_location"), 24)) {
        if (eq(CC0_ELF_REMAP_LOCATION_SYMBOL, 0)) {
            CC0_ELF_REMAP_LOCATION_SYMBOL = cc0_elf_put_undefined_function(
                mks("cc0_remap_error_location"), 24);
        }
        return CC0_ELF_REMAP_LOCATION_SYMBOL;
    }
    /* Layer APIs are explicit unresolved calls supplied by the cc1 object. */
    if (not(lt(length, 10))) {
        if (cc0_compiler_slice_equal(name, 10, mks("cc1_layer_"), 10)) {
            return cc0_elf_put_undefined_function(name, length);
        }
    }
    return sub(0, 1);
}

function cc0_elf_relocation_symbol_(entry, name, length, global_index)
{
    name = ri32(add(entry, CC0_SYMBOL_NAME_OFFSET));
    length = ri32(add(entry, CC0_SYMBOL_LENGTH_OFFSET));
    if (cc0_compiler_slice_equal(name, length, mks(".data"), 5)) {
        return CC0_ELF_DATA_SYMBOL_INDEX;
    }
    global_index = cc0_compiler_find_symbol(CC0_GLOBAL_SYMBOLS,
        CC0_GLOBAL_COUNT, name, length);
    if (lt(global_index, 0)) {
        return cc0_elf_external_symbol(name, length);
    }
    return ri32(add(CC0_ELF_GLOBAL_SYMBOL_INDICES,
        shl(global_index, CC0_WORD_ADDRESS_SHIFT)));
}

function cc0_elf_relocation_symbol(entry)
{
    return cc0_elf_relocation_symbol_(entry, 0, 0, 0);
}

function cc0_elf_emit_relocations_(index, entry, symbol, type)
{
    index = 0;
    while (lt(index, CC0_RELOCATION_COUNT)) {
        entry = cc0_compiler_symbol_entry(CC0_RELOCATION_RECORDS, index);
        symbol = cc0_elf_relocation_symbol(entry);
        if (lt(symbol, 0)) {
            return cc0_compiler_fail();
        }
        type = CC0_ELF_RELOCATION_ABSOLUTE;
        if (eq(ri32(add(entry, CC0_SYMBOL_CODE_OFFSET)), sub(0, 4))) {
            type = CC0_ELF_RELOCATION_PC_RELATIVE;
        }
        if (cc0_elf_put_relocation(CC0_ELF_REL_TEXT_SECTION,
            ri32(add(entry, CC0_SYMBOL_VALUE_OFFSET)), symbol, type)) {
            return CC0_TRUE;
        }
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_elf_emit_relocations()
{
    return cc0_elf_emit_relocations_(0, 0, 0, 0);
}

/* Turn the compiler buffers into TCC-style sections before file layout. */
function cc0_elf_build_object_sections()
{
    var bss_bytes;
    if (cc0_elf_prepare_object_sections()) {
        return CC0_TRUE;
    }
    if (cc0_elf_prepare_symbol_indices()) {
        return CC0_TRUE;
    }
    bss_bytes = cc0_elf_layout_globals();
    if (lt(bss_bytes, 0)) {
        return CC0_TRUE;
    }
    if (cc0_elf_copy_section(CC0_ELF_TEXT_SECTION, CC0_CODE,
        CC0_CODE_LENGTH)) {
        return CC0_TRUE;
    }
    if (cc0_elf_copy_section(CC0_ELF_DATA_SECTION, CC0_DATA,
        CC0_DATA_LENGTH)) {
        return CC0_TRUE;
    }
    wi32(add(CC0_ELF_BSS_SECTION, CC0_SECTION_SIZE_OFFSET),
        bss_bytes);
    if (lt(cc0_elf_put_string(CC0_ELF_STRTAB_SECTION, mks(""), 0), 0)) {
        return CC0_TRUE;
    }
    if (lt(cc0_elf_put_symbol(CC0_ELF_SYMTAB_SECTION,
        CC0_ELF_STRTAB_SECTION, mks(""), 0, 0, 0, 0, 0, 0), 0)) {
        return CC0_TRUE;
    }
    CC0_ELF_DATA_SYMBOL_INDEX = cc0_elf_put_symbol(
        CC0_ELF_SYMTAB_SECTION, CC0_ELF_STRTAB_SECTION, mks(""), 0, 0, 0,
        CC0_ELF_SYMBOL_LOCAL_SECTION, 0,
        cc0_elf_section_number(CC0_ELF_DATA_SECTION));
    if (lt(CC0_ELF_DATA_SYMBOL_INDEX, 0)) {
        return CC0_TRUE;
    }
    wi32(add(CC0_ELF_SYMTAB_SECTION, CC0_SECTION_INFO_OFFSET),
        add(CC0_ELF_DATA_SYMBOL_INDEX, 1));
    if (cc0_elf_emit_function_symbols()) {
        return CC0_TRUE;
    }
    if (cc0_elf_emit_global_symbols()) {
        return CC0_TRUE;
    }
    if (cc0_elf_emit_external_symbols()) {
        return CC0_TRUE;
    }
    return cc0_elf_emit_relocations();
}

function cc0_compiler_product_(left, right, result, index)
{
    result = 0;
    index = 0;
    while (lt(index, right)) {
        result = add(result, left);
        index = add(index, 1);
    }
    return result;
}

function cc0_compiler_product(left, right)
{
    return cc0_compiler_product_(left, right, 0, 0);
}

function cc0_elf_align(value, alignment)
{
    return and(add(value, sub(alignment, 1)), sub(0, alignment));
}

function cc0_elf_write_half(address, value)
{
    wi8(address, and(value, 255));
    wi8(add(address, 1), ushr(value, 8));
    return value;
}

function cc0_compiler_clear_bytes_(memory, length, index)
{
    index = 0;
    while (lt(index, length)) {
        wi8(add(memory, index), 0);
        index = add(index, 1);
    }
    return memory;
}

function cc0_compiler_clear_bytes(memory, length)
{
    return cc0_compiler_clear_bytes_(memory, length, 0);
}

/* TCC stores each emitted section name in the final .shstrtab section. */
function cc0_elf_add_section_names_(index, section, name, length, offset)
{
    CC0_ELF_SHSTRTAB_SECTION = cc0_elf_new_section(mks(".shstrtab"), 9,
        CC0_ELF_SECTION_STRTAB, 0);
    if (eq(CC0_ELF_SHSTRTAB_SECTION, 0)) {
        return cc0_compiler_fail();
    }
    if (lt(cc0_elf_put_string(CC0_ELF_SHSTRTAB_SECTION, mks(""), 0), 0)) {
        return CC0_TRUE;
    }
    index = 1;
    while (lt(index, CC0_SECTION_COUNT)) {
        section = cc0_elf_section_entry(index);
        name = ri32(add(section, CC0_SECTION_NAME_OFFSET));
        length = ri32(add(section, CC0_SECTION_NAME_LENGTH_OFFSET));
        offset = cc0_elf_put_string(CC0_ELF_SHSTRTAB_SECTION, name, length);
        if (lt(offset, 0)) {
            return CC0_TRUE;
        }
        wi32(add(section, CC0_SECTION_NAME_OFFSET), offset);
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_elf_add_section_names()
{
    return cc0_elf_add_section_names_(0, 0, 0, 0, 0);
}

/* This is layout_sections for TCC_OUTPUT_OBJ, where phnum is zero. */
function cc0_elf_layout_sections_(index, section, file_offset, alignment,
    section_bytes)
{
    file_offset = CC0_ELF_HEADER_BYTES;
    index = 1;
    while (lt(index, CC0_SECTION_COUNT)) {
        section = cc0_elf_section_entry(index);
        alignment = ri32(add(section, CC0_SECTION_ALIGNMENT_OFFSET));
        file_offset = cc0_elf_align(file_offset, alignment);
        wi32(add(section, CC0_SECTION_FILE_OFFSET), file_offset);
        if (not(eq(ri32(add(section, CC0_SECTION_TYPE_OFFSET)),
            CC0_ELF_SECTION_NOBITS))) {
            file_offset = add(file_offset,
                ri32(add(section, CC0_SECTION_SIZE_OFFSET)));
        }
        index = add(index, 1);
    }
    file_offset = cc0_elf_align(file_offset, CC0_WORD_BYTES);
    section_bytes = cc0_compiler_product(CC0_SECTION_COUNT,
        CC0_ELF_SECTION_HEADER_BYTES);
    CC0_ELF_OUTPUT_LENGTH = add(file_offset, section_bytes);
    return file_offset;
}

function cc0_elf_layout_sections()
{
    return cc0_elf_layout_sections_(0, 0, 0, 0, 0);
}

function cc0_elf_write_header_(section_header_offset, header)
{
    header = CC0_ELF_OUTPUT;
    wi8(header, CC0_ELF_MAGIC_DELETE);
    wi8(add(header, 1), CC0_ELF_MAGIC_E);
    wi8(add(header, 2), CC0_ELF_MAGIC_L);
    wi8(add(header, 3), CC0_ELF_MAGIC_F);
    wi8(add(header, 4), CC0_ELF_CLASS_32);
    wi8(add(header, 5), CC0_ELF_DATA_LITTLE_ENDIAN);
    wi8(add(header, 6), CC0_ELF_CURRENT_VERSION);
    cc0_elf_write_half(add(header, 16), CC0_ELF_TYPE_RELOCATABLE);
    cc0_elf_write_half(add(header, 18), CC0_ELF_MACHINE_I386);
    wi32(add(header, 20), CC0_ELF_CURRENT_VERSION);
    wi32(add(header, 32), section_header_offset);
    cc0_elf_write_half(add(header, 40), CC0_ELF_HEADER_BYTES);
    cc0_elf_write_half(add(header, 46), CC0_ELF_SECTION_HEADER_BYTES);
    cc0_elf_write_half(add(header, 48), CC0_SECTION_COUNT);
    cc0_elf_write_half(add(header, 50), sub(CC0_SECTION_COUNT, 1));
    return CC0_FALSE;
}

function cc0_elf_write_header(section_header_offset)
{
    return cc0_elf_write_header_(section_header_offset, 0);
}

function cc0_elf_write_section_header_(section, output, link)
{
    wi32(output, ri32(add(section, CC0_SECTION_NAME_OFFSET)));
    wi32(add(output, 4), ri32(add(section, CC0_SECTION_TYPE_OFFSET)));
    wi32(add(output, 8), ri32(add(section, CC0_SECTION_FLAGS_OFFSET)));
    wi32(add(output, 16), ri32(add(section, CC0_SECTION_FILE_OFFSET)));
    wi32(add(output, 20), ri32(add(section, CC0_SECTION_SIZE_OFFSET)));
    link = ri32(add(section, CC0_SECTION_LINK_OFFSET));
    wi32(add(output, 24), link);
    wi32(add(output, 28), ri32(add(section, CC0_SECTION_INFO_OFFSET)));
    wi32(add(output, 32), ri32(add(section, CC0_SECTION_ALIGNMENT_OFFSET)));
    wi32(add(output, 36), ri32(add(section,
        CC0_SECTION_ENTRY_SIZE_OFFSET)));
    return CC0_FALSE;
}

function cc0_elf_write_section_header(section, output)
{
    return cc0_elf_write_section_header_(section, output, 0);
}

function cc0_elf_serialize_object_(section_header_offset, index, section,
    output, data, size)
{
    CC0_ELF_OUTPUT = alloc(CC0_ELF_OUTPUT_LENGTH);
    if (eq(CC0_ELF_OUTPUT, 0)) {
        return cc0_compiler_fail();
    }
    cc0_compiler_clear_bytes(CC0_ELF_OUTPUT, CC0_ELF_OUTPUT_LENGTH);
    cc0_elf_write_header(section_header_offset);
    index = 1;
    while (lt(index, CC0_SECTION_COUNT)) {
        section = cc0_elf_section_entry(index);
        if (not(eq(ri32(add(section, CC0_SECTION_TYPE_OFFSET)),
            CC0_ELF_SECTION_NOBITS))) {
            data = ri32(add(section, CC0_SECTION_DATA_OFFSET));
            size = ri32(add(section, CC0_SECTION_SIZE_OFFSET));
            cc0_compiler_copy_bytes(add(CC0_ELF_OUTPUT,
                ri32(add(section, CC0_SECTION_FILE_OFFSET))), data, size);
        }
        output = add(CC0_ELF_OUTPUT, add(section_header_offset,
            cc0_compiler_product(index, CC0_ELF_SECTION_HEADER_BYTES)));
        cc0_elf_write_section_header(section, output);
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_elf_serialize_object(section_header_offset)
{
    return cc0_elf_serialize_object_(section_header_offset, 0, 0, 0, 0, 0);
}

function cc0_compiler_build_object(source, length)
{
    CC0_COMPILER_ERROR_POSITION = sub(0, 1);
    CC0_COMPILER_ERROR_FILE = 0;
    CC0_COMPILER_ERROR_LINE = 0;
    CC0_COMPILER_ERROR_COLUMN = 0;
    if (cc0_compiler_compile_program(source, length)) {
        return CC0_TRUE;
    }
    if (cc0_elf_build_object_sections()) {
        return CC0_TRUE;
    }
    if (cc0_elf_add_section_names()) {
        return CC0_TRUE;
    }
    return cc0_elf_serialize_object(cc0_elf_layout_sections());
}

function cc0_compile(source, length)
{
    return cc0_compiler_build_object(source, length);
}

function cc0_remap_error(source, length, position)
{
    CC0_SOURCE = source;
    CC0_SOURCE_LENGTH = length;
    CC0_COMPILER_ERROR_POSITION = position;
    return 0;
}

function cc0_remap_error_location(source, length, position, file, line,
    column)
{
    cc0_remap_error(source, length, position);
    CC0_COMPILER_ERROR_FILE = file;
    CC0_COMPILER_ERROR_LINE = line;
    CC0_COMPILER_ERROR_COLUMN = column;
    return 0;
}

function cc0_is_decimal_digit(value)
{
    if (lt(value, CC0_ASCII_ZERO)) {
        return CC0_FALSE;
    }
    return le(value, CC0_ASCII_NINE);
}

function cc0_is_octal_digit(value)
{
    if (lt(value, CC0_ASCII_ZERO)) {
        return CC0_FALSE;
    }
    return le(value, CC0_ASCII_SEVEN);
}

function cc0_is_uppercase(value)
{
    if (lt(value, CC0_ASCII_UPPER_A)) {
        return CC0_FALSE;
    }
    return le(value, CC0_ASCII_UPPER_Z);
}

function cc0_is_lowercase(value)
{
    if (lt(value, CC0_ASCII_LOWER_A)) {
        return CC0_FALSE;
    }
    return le(value, CC0_ASCII_LOWER_Z);
}

function cc0_is_name_start(value)
{
    if (cc0_is_uppercase(value)) {
        return CC0_TRUE;
    }
    if (cc0_is_lowercase(value)) {
        return CC0_TRUE;
    }
    return eq(value, CC0_ASCII_UNDERSCORE);
}

function cc0_is_name_continue(value)
{
    if (cc0_is_name_start(value)) {
        return CC0_TRUE;
    }
    return cc0_is_decimal_digit(value);
}

function cc0_is_horizontal_space(value)
{
    if (eq(value, CC0_ASCII_SPACE)) {
        return CC0_TRUE;
    }
    return eq(value, CC0_ASCII_TAB);
}

function cc0_is_line_space(value)
{
    if (eq(value, CC0_ASCII_LINE_FEED)) {
        return CC0_TRUE;
    }
    if (eq(value, CC0_ASCII_CARRIAGE_RETURN)) {
        return CC0_TRUE;
    }
    return eq(value, CC0_ASCII_FORM_FEED);
}

/* Match TCC's preprocessing-space class, which deliberately excludes LF. */
function cc0_is_space(value)
{
    if (cc0_is_horizontal_space(value)) {
        return CC0_TRUE;
    }
    if (eq(value, CC0_ASCII_VERTICAL_TAB)) {
        return CC0_TRUE;
    }
    if (eq(value, CC0_ASCII_FORM_FEED)) {
        return CC0_TRUE;
    }
    return eq(value, CC0_ASCII_CARRIAGE_RETURN);
}

function cc0_to_upper(value)
{
    if (cc0_is_lowercase(value)) {
        return add(sub(value, CC0_ASCII_LOWER_A), CC0_ASCII_UPPER_A);
    }
    return value;
}

/* The table starts at the EOF entry, followed by all byte values. */
function cc0_set_idnum_(table, character, flags, address, previous)
{
    address = add(table, sub(character, CC0_CHARACTER_EOF));
    previous = ri8(address);
    wi8(address, flags);
    return previous;
}

function cc0_set_idnum(table, character, flags)
{
    return cc0_set_idnum_(table, character, flags, 0, 0);
}

/* Preserve TCC's rule that a second adjacent space reports one token. */
function cc0_check_space_(table, token, space_pointer, address, flags)
{
    if (lt(token, CC0_BYTE_VALUE_COUNT)) {
        address = add(table, sub(token, CC0_CHARACTER_EOF));
        flags = ri8(address);
        if (and(flags, CC0_CHARACTER_SPACE_FLAG)) {
            if (ri32(space_pointer)) {
                return CC0_TRUE;
            }
            wi32(space_pointer, CC0_TRUE);
            return CC0_FALSE;
        }
    }
    wi32(space_pointer, CC0_FALSE);
    return CC0_FALSE;
}

function cc0_check_space(table, token, space_pointer)
{
    return cc0_check_space_(table, token, space_pointer, 0, 0);
}

/* This is TCC's identifier hash with explicit 32-bit wrapping primitives. */
function cc0_token_hash_(text, length, index, hash, character, left_part, right_part)
{
    index = 0;
    hash = CC0_TOKEN_HASH_INITIAL;
    while (lt(index, length)) {
        character = ri8(add(text, index));
        left_part = shl(hash, CC0_TOKEN_HASH_LEFT_SHIFT);
        right_part = ushr(hash, CC0_TOKEN_HASH_RIGHT_SHIFT);
        hash = add(hash, left_part);
        hash = add(hash, right_part);
        hash = add(hash, character);
        index = add(index, 1);
    }
    return and(hash, CC0_TOKEN_HASH_BUCKET_MASK);
}

function cc0_token_hash(text, length)
{
    return cc0_token_hash_(text, length, 0, 0, 0, 0, 0);
}

/* Scan a TCC identifier and retain the hash used by its symbol table. */
function cc0_scan_identifier_(table, text, continuation_mask, hash_pointer, position, hash, character, flags, left_part, right_part)
{
    position = text;
    hash = CC0_TOKEN_HASH_INITIAL;
    character = ri8(position);
    flags = ri8(add(table, sub(character, CC0_CHARACTER_EOF)));
    while (and(flags, continuation_mask)) {
        left_part = shl(hash, CC0_TOKEN_HASH_LEFT_SHIFT);
        right_part = ushr(hash, CC0_TOKEN_HASH_RIGHT_SHIFT);
        hash = add(hash, left_part);
        hash = add(hash, right_part);
        hash = add(hash, character);
        position = add(position, 1);
        character = ri8(position);
        flags = ri8(add(table, sub(character, CC0_CHARACTER_EOF)));
    }
    wi32(hash_pointer, and(hash, CC0_TOKEN_HASH_BUCKET_MASK));
    return position;
}

function cc0_scan_identifier(table, text, continuation_mask, hash_pointer)
{
    return cc0_scan_identifier_(table, text, continuation_mask, hash_pointer,
        0, 0, 0, 0, 0, 0);
}

/* TCC accumulates hexadecimal and binary floating literals in two words. */
function cc0_number_zero_(number, index, address)
{
    index = 0;
    while (lt(index, CC0_NUMBER_WORD_COUNT)) {
        address = add(number, shl(index, CC0_WORD_ADDRESS_SHIFT));
        wi32(address, 0);
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_number_zero(number)
{
    return cc0_number_zero_(number, 0, 0);
}

function cc0_number_lshift_(number, shift, low_bits, index, address, value)
{
    index = 0;
    while (lt(index, CC0_NUMBER_WORD_COUNT)) {
        address = add(number, shl(index, CC0_WORD_ADDRESS_SHIFT));
        value = ri32(address);
        /* low_bits occupies positions cleared by the shift, so add acts as OR. */
        wi32(address, add(shl(value, shift), low_bits));
        low_bits = ushr(value, sub(CC0_WORD_BITS, shift));
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_number_lshift(number, shift, low_bits)
{
    return cc0_number_lshift_(number, shift, low_bits, 0, 0, 0);
}

function cc0_text_equal_(source, length, text, index, left, right)
{
    index = 0;
    while (lt(index, length)) {
        left = ri8(add(source, index));
        right = ri8(add(text, index));
        if (not(eq(left, right))) {
            return CC0_FALSE;
        }
        index = add(index, 1);
    }
    return eq(ri8(add(text, length)), 0);
}

function cc0_text_equal(source, length, text)
{
    return cc0_text_equal_(source, length, text, 0, 0, 0);
}

function cc0_compiler_set_source(source, length)
{
    CC0_SOURCE = source;
    CC0_SOURCE_LENGTH = length;
    CC0_SOURCE_POSITION = 0;
    CC0_TOKEN = CC0_TOKEN_EOF;
    CC0_TOKEN_START = source;
    CC0_TOKEN_LENGTH = 0;
    CC0_TOKEN_NUMBER = 0;
    return CC0_FALSE;
}

function cc0_compiler_skip_layout_(character, next_character, closed)
{
    while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        if (cc0_is_horizontal_space(character)) {
            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
        } else if (cc0_is_line_space(character)) {
            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
        } else if (eq(character, CC0_ASCII_VERTICAL_TAB)) {
            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
        } else if (eq(character, CC0_ASCII_SLASH)) {
            if (not(lt(add(CC0_SOURCE_POSITION, 1), CC0_SOURCE_LENGTH))) {
                return CC0_TRUE;
            }
            next_character = ri8(add(CC0_SOURCE, add(CC0_SOURCE_POSITION, 1)));
            if (eq(next_character, CC0_ASCII_SLASH)) {
                CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 2);
                while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
                    character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
                    if (eq(character, CC0_ASCII_LINE_FEED)) {
                        break;
                    }
                    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
                }
            } else if (eq(next_character, CC0_ASCII_STAR)) {
                CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 2);
                closed = CC0_FALSE;
                while (lt(add(CC0_SOURCE_POSITION, 1), CC0_SOURCE_LENGTH)) {
                    character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
                    next_character = ri8(add(CC0_SOURCE, add(CC0_SOURCE_POSITION, 1)));
                    if (eq(character, CC0_ASCII_STAR)) {
                        if (eq(next_character, CC0_ASCII_SLASH)) {
                            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 2);
                            closed = CC0_TRUE;
                            break;
                        }
                    }
                    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
                }
                if (not(closed)) {
                    CC0_TOKEN = CC0_TOKEN_ERROR;
                    return CC0_FALSE;
                }
            } else {
                return CC0_TRUE;
            }
        } else {
            return CC0_TRUE;
        }
    }
    return CC0_TRUE;
}

function cc0_compiler_skip_layout()
{
    return cc0_compiler_skip_layout_(0, 0, 0);
}

function cc0_compiler_keyword_(text, length)
{
    if (cc0_text_equal(text, length, mks("function"))) {
        return CC0_TOKEN_FUNCTION;
    }
    if (cc0_text_equal(text, length, mks("var"))) {
        return CC0_TOKEN_VAR;
    }
    if (cc0_text_equal(text, length, mks("return"))) {
        return CC0_TOKEN_RETURN;
    }
    if (cc0_text_equal(text, length, mks("if"))) {
        return CC0_TOKEN_IF;
    }
    if (cc0_text_equal(text, length, mks("else"))) {
        return CC0_TOKEN_ELSE;
    }
    if (cc0_text_equal(text, length, mks("while"))) {
        return CC0_TOKEN_WHILE;
    }
    if (cc0_text_equal(text, length, mks("break"))) {
        return CC0_TOKEN_BREAK;
    }
    if (cc0_text_equal(text, length, mks("for"))) {
        return CC0_TOKEN_FOR;
    }
    if (cc0_text_equal(text, length, mks("do"))) {
        return CC0_TOKEN_DO;
    }
    if (cc0_text_equal(text, length, mks("continue"))) {
        return CC0_TOKEN_CONTINUE;
    }
    return CC0_TOKEN_IDENTIFIER;
}

function cc0_compiler_scan_name_(character)
{
    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        if (not(cc0_is_name_continue(character))) {
            break;
        }
        CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    }
    CC0_TOKEN_LENGTH = sub(add(CC0_SOURCE, CC0_SOURCE_POSITION), CC0_TOKEN_START);
    CC0_TOKEN = cc0_compiler_keyword_(CC0_TOKEN_START, CC0_TOKEN_LENGTH);
    return CC0_TOKEN;
}

function cc0_hexadecimal_digit_(character, digit)
{
    if (cc0_is_decimal_digit(character)) {
        return sub(character, CC0_ASCII_ZERO);
    }
    if (cc0_is_uppercase(character)) {
        digit = sub(character, CC0_ASCII_UPPER_A);
        if (le(digit, 5)) {
            return add(digit, 10);
        }
    }
    if (cc0_is_lowercase(character)) {
        digit = sub(character, CC0_ASCII_LOWER_A);
        if (le(digit, 5)) {
            return add(digit, 10);
        }
    }
    return sub(0, 1);
}

function cc0_hexadecimal_digit(character)
{
    return cc0_hexadecimal_digit_(character, 0);
}

function cc0_compiler_number_suffix(character)
{
    if (eq(character, CC0_ASCII_UPPER_L)) {
        return CC0_TRUE;
    }
    if (eq(character, CC0_ASCII_LOWER_L)) {
        return CC0_TRUE;
    }
    if (eq(character, CC0_ASCII_UPPER_U)) {
        return CC0_TRUE;
    }
    return eq(character, CC0_ASCII_LOWER_U);
}

function cc0_compiler_scan_number_(character, digit, base)
{
    CC0_TOKEN_NUMBER = 0;
    base = 10;
    if (eq(ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION)), CC0_ASCII_ZERO)) {
        base = 8;
        CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
        if (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
            character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
            if (eq(character, CC0_ASCII_UPPER_X)) {
                base = 16;
                CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
            } else if (eq(character, CC0_ASCII_LOWER_X)) {
                base = 16;
                CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
            }
        }
    }
    while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        digit = cc0_hexadecimal_digit(character);
        if (lt(digit, 0)) {
            break;
        }
        if (not(lt(digit, base))) {
            break;
        }
        if (eq(base, 16)) {
            CC0_TOKEN_NUMBER = add(shl(CC0_TOKEN_NUMBER, 4), digit);
        } else if (eq(base, 8)) {
            CC0_TOKEN_NUMBER = add(shl(CC0_TOKEN_NUMBER, 3), digit);
        } else {
            CC0_TOKEN_NUMBER = add(shl(CC0_TOKEN_NUMBER, 3),
                add(shl(CC0_TOKEN_NUMBER, 1), digit));
        }
        CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    }
    while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        if (not(cc0_compiler_number_suffix(character))) {
            break;
        }
        CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    }
    CC0_TOKEN_LENGTH = sub(add(CC0_SOURCE, CC0_SOURCE_POSITION), CC0_TOKEN_START);
    CC0_TOKEN = CC0_TOKEN_NUMBER_LITERAL;
    return CC0_TOKEN;
}

function cc0_compiler_scan_character_(character, value)
{
    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    if (not(lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH))) {
        CC0_TOKEN = CC0_TOKEN_ERROR;
        return CC0_TOKEN;
    }
    character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
    value = character;
    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    if (eq(character, CC0_ASCII_BACKSLASH)) {
        if (not(lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH))) {
            CC0_TOKEN = CC0_TOKEN_ERROR;
            return CC0_TOKEN;
        }
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
        value = character;
        if (eq(character, CC0_ASCII_LOWER_N)) {
            value = CC0_ASCII_LINE_FEED;
        } else if (eq(character, CC0_ASCII_LOWER_R)) {
            value = CC0_ASCII_CARRIAGE_RETURN;
        } else if (eq(character, CC0_ASCII_LOWER_T)) {
            value = CC0_ASCII_TAB;
        } else if (eq(character, CC0_ASCII_ZERO)) {
            value = 0;
        }
    }
    if (not(lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH))) {
        CC0_TOKEN = CC0_TOKEN_ERROR;
        return CC0_TOKEN;
    }
    if (not(eq(ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION)),
        CC0_ASCII_APOSTROPHE))) {
        CC0_TOKEN = CC0_TOKEN_ERROR;
        return CC0_TOKEN;
    }
    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    CC0_TOKEN_LENGTH = sub(add(CC0_SOURCE, CC0_SOURCE_POSITION),
        CC0_TOKEN_START);
    CC0_TOKEN_NUMBER = value;
    CC0_TOKEN = CC0_TOKEN_NUMBER_LITERAL;
    return CC0_TOKEN;
}

function cc0_compiler_scan_character()
{
    return cc0_compiler_scan_character_(0, 0);
}

function cc0_compiler_scan_string_(character, escaped)
{
    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    CC0_TOKEN_START = add(CC0_SOURCE, CC0_SOURCE_POSITION);
    escaped = CC0_FALSE;
    while (lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH)) {
        character = ri8(add(CC0_SOURCE, CC0_SOURCE_POSITION));
        if (escaped) {
            escaped = CC0_FALSE;
        } else if (eq(character, CC0_ASCII_BACKSLASH)) {
            escaped = CC0_TRUE;
        } else if (eq(character, CC0_ASCII_QUOTE)) {
            CC0_TOKEN_LENGTH = sub(add(CC0_SOURCE, CC0_SOURCE_POSITION), CC0_TOKEN_START);
            CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
            CC0_TOKEN = CC0_TOKEN_STRING_LITERAL;
            return CC0_TOKEN;
        }
        CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    }
    CC0_TOKEN = CC0_TOKEN_ERROR;
    return CC0_TOKEN;
}

function cc0_compiler_next_token_(character)
{
    cc0_compiler_skip_layout();
    if (eq(CC0_TOKEN, CC0_TOKEN_ERROR)) {
        return CC0_TOKEN;
    }
    CC0_TOKEN_START = add(CC0_SOURCE, CC0_SOURCE_POSITION);
    CC0_TOKEN_LENGTH = 1;
    if (not(lt(CC0_SOURCE_POSITION, CC0_SOURCE_LENGTH))) {
        CC0_TOKEN_LENGTH = 0;
        CC0_TOKEN = CC0_TOKEN_EOF;
        return CC0_TOKEN;
    }
    character = ri8(CC0_TOKEN_START);
    if (cc0_is_name_start(character)) {
        return cc0_compiler_scan_name_(0);
    }
    if (cc0_is_decimal_digit(character)) {
        return cc0_compiler_scan_number_(0, 0, 0);
    }
    if (eq(character, CC0_ASCII_QUOTE)) {
        return cc0_compiler_scan_string_(0, 0);
    }
    if (eq(character, CC0_ASCII_APOSTROPHE)) {
        return cc0_compiler_scan_character();
    }
    CC0_SOURCE_POSITION = add(CC0_SOURCE_POSITION, 1);
    CC0_TOKEN = character;
    return CC0_TOKEN;
}

function cc0_compiler_next_token()
{
    return cc0_compiler_next_token_(0);
}

/* cc1 buffers tokens without sharing or duplicating the cc0 lexer state. */
function cc0_lexer_start(source, length)
{
    cc0_compiler_set_source(source, length);
    return cc0_compiler_next_token();
}

function cc0_lexer_advance()
{
    return cc0_compiler_next_token();
}

function cc0_lexer_field(field)
{
    if (eq(field, CC0_LEXER_FIELD_KIND)) {
        return CC0_TOKEN;
    }
    if (eq(field, CC0_LEXER_FIELD_TEXT)) {
        return CC0_TOKEN_START;
    }
    if (eq(field, CC0_LEXER_FIELD_LENGTH)) {
        return CC0_TOKEN_LENGTH;
    }
    if (eq(field, CC0_LEXER_FIELD_NUMBER)) {
        return CC0_TOKEN_NUMBER;
    }
    return 0;
}

function cc0_compiler_fail()
{
    if (lt(CC0_COMPILER_ERROR_POSITION, 0)) {
        CC0_COMPILER_ERROR_POSITION = sub(CC0_TOKEN_START, CC0_SOURCE);
    }
    CC0_COMPILER_ERROR = CC0_TRUE;
    return CC0_TRUE;
}

function cc0_compiler_symbol_entry(table, index)
{
    return add(table, shl(index, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT));
}

function cc0_compiler_slice_equal_(left, left_length, right, right_length, index)
{
    if (not(eq(left_length, right_length))) {
        return CC0_FALSE;
    }
    index = 0;
    while (lt(index, left_length)) {
        if (not(eq(ri8(add(left, index)), ri8(add(right, index))))) {
            return CC0_FALSE;
        }
        index = add(index, 1);
    }
    return CC0_TRUE;
}

function cc0_compiler_slice_equal(left, left_length, right, right_length)
{
    return cc0_compiler_slice_equal_(left, left_length, right, right_length, 0);
}

function cc0_compiler_find_symbol_(table, count, name, length, index, entry)
{
    index = 0;
    while (lt(index, count)) {
        entry = cc0_compiler_symbol_entry(table, index);
        if (cc0_compiler_slice_equal(
            ri32(add(entry, CC0_SYMBOL_NAME_OFFSET)),
            ri32(add(entry, CC0_SYMBOL_LENGTH_OFFSET)), name, length)) {
            return index;
        }
        index = add(index, 1);
    }
    return sub(0, 1);
}

function cc0_compiler_find_symbol(table, count, name, length)
{
    return cc0_compiler_find_symbol_(table, count, name, length, 0, 0);
}

function cc0_compiler_add_symbol_(table, count, name, length, value, entry)
{
    entry = cc0_compiler_symbol_entry(table, count);
    wi32(add(entry, CC0_SYMBOL_NAME_OFFSET), name);
    wi32(add(entry, CC0_SYMBOL_LENGTH_OFFSET), length);
    wi32(add(entry, CC0_SYMBOL_VALUE_OFFSET), value);
    wi32(add(entry, CC0_SYMBOL_CODE_OFFSET), 0);
    return CC0_FALSE;
}

function cc0_compiler_ensure_global_symbols_(needed, memory)
{
    needed = shl(add(CC0_GLOBAL_COUNT, 1),
        CC0_SYMBOL_ENTRY_ADDRESS_SHIFT);
    memory = cc0_compiler_grow_memory(CC0_GLOBAL_SYMBOLS,
        shl(CC0_GLOBAL_COUNT, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT),
        CC0_GLOBAL_SYMBOL_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_GLOBAL_SYMBOLS = memory;
    CC0_GLOBAL_SYMBOL_CAPACITY = cc0_compiler_grown_capacity(
        CC0_GLOBAL_SYMBOL_CAPACITY, needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_global_symbols()
{
    return cc0_compiler_ensure_global_symbols_(0, 0);
}

function cc0_compiler_ensure_function_symbols_(needed, memory)
{
    needed = shl(add(CC0_FUNCTION_COUNT, 1),
        CC0_SYMBOL_ENTRY_ADDRESS_SHIFT);
    memory = cc0_compiler_grow_memory(CC0_FUNCTION_SYMBOLS,
        shl(CC0_FUNCTION_COUNT, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT),
        CC0_FUNCTION_SYMBOL_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_FUNCTION_SYMBOLS = memory;
    CC0_FUNCTION_SYMBOL_CAPACITY = cc0_compiler_grown_capacity(
        CC0_FUNCTION_SYMBOL_CAPACITY, needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_function_symbols()
{
    return cc0_compiler_ensure_function_symbols_(0, 0);
}

function cc0_compiler_ensure_parameter_symbols_(needed, memory)
{
    needed = shl(add(CC0_PARAMETER_COUNT, 1),
        CC0_SYMBOL_ENTRY_ADDRESS_SHIFT);
    memory = cc0_compiler_grow_memory(CC0_PARAMETER_SYMBOLS,
        shl(CC0_PARAMETER_COUNT, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT),
        CC0_PARAMETER_SYMBOL_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_PARAMETER_SYMBOLS = memory;
    CC0_PARAMETER_SYMBOL_CAPACITY = cc0_compiler_grown_capacity(
        CC0_PARAMETER_SYMBOL_CAPACITY, needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_parameter_symbols()
{
    return cc0_compiler_ensure_parameter_symbols_(0, 0);
}

function cc0_compiler_ensure_local_symbols_(needed, memory)
{
    needed = shl(add(CC0_LOCAL_COUNT, 1),
        CC0_SYMBOL_ENTRY_ADDRESS_SHIFT);
    memory = cc0_compiler_grow_memory(CC0_LOCAL_SYMBOLS,
        shl(CC0_LOCAL_COUNT, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT),
        CC0_LOCAL_SYMBOL_CAPACITY, needed);
    if (eq(memory, 0)) {
        return CC0_TRUE;
    }
    CC0_LOCAL_SYMBOLS = memory;
    CC0_LOCAL_SYMBOL_CAPACITY = cc0_compiler_grown_capacity(
        CC0_LOCAL_SYMBOL_CAPACITY, needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_local_symbols()
{
    return cc0_compiler_ensure_local_symbols_(0, 0);
}

function cc0_compiler_ensure_call_records_(needed, memory)
{
    needed = shl(add(CC0_CALL_COUNT, 1),
        CC0_SYMBOL_ENTRY_ADDRESS_SHIFT);
    memory = cc0_compiler_grow_memory(CC0_CALL_RECORDS,
        shl(CC0_CALL_COUNT, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT),
        CC0_CALL_RECORD_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_CALL_RECORDS = memory;
    CC0_CALL_RECORD_CAPACITY = cc0_compiler_grown_capacity(
        CC0_CALL_RECORD_CAPACITY, needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_call_records()
{
    return cc0_compiler_ensure_call_records_(0, 0);
}

function cc0_compiler_ensure_relocation_records_(needed, memory)
{
    needed = shl(add(CC0_RELOCATION_COUNT, 1),
        CC0_SYMBOL_ENTRY_ADDRESS_SHIFT);
    memory = cc0_compiler_grow_memory(CC0_RELOCATION_RECORDS,
        shl(CC0_RELOCATION_COUNT, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT),
        CC0_RELOCATION_RECORD_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_RELOCATION_RECORDS = memory;
    CC0_RELOCATION_RECORD_CAPACITY = cc0_compiler_grown_capacity(
        CC0_RELOCATION_RECORD_CAPACITY, needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_relocation_records()
{
    return cc0_compiler_ensure_relocation_records_(0, 0);
}

function cc0_compiler_ensure_break_records_(needed, memory)
{
    needed = shl(add(CC0_BREAK_COUNT, 1),
        CC0_SYMBOL_ENTRY_ADDRESS_SHIFT);
    memory = cc0_compiler_grow_memory(CC0_BREAK_RECORDS,
        shl(CC0_BREAK_COUNT, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT),
        CC0_BREAK_RECORD_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_BREAK_RECORDS = memory;
    CC0_BREAK_RECORD_CAPACITY = cc0_compiler_grown_capacity(
        CC0_BREAK_RECORD_CAPACITY, needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_break_records()
{
    return cc0_compiler_ensure_break_records_(0, 0);
}

function cc0_compiler_ensure_continue_records_(needed, memory)
{
    needed = shl(add(CC0_CONTINUE_COUNT, 1),
        CC0_SYMBOL_ENTRY_ADDRESS_SHIFT);
    memory = cc0_compiler_grow_memory(CC0_CONTINUE_RECORDS,
        shl(CC0_CONTINUE_COUNT, CC0_SYMBOL_ENTRY_ADDRESS_SHIFT),
        CC0_CONTINUE_RECORD_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_CONTINUE_RECORDS = memory;
    CC0_CONTINUE_RECORD_CAPACITY = cc0_compiler_grown_capacity(
        CC0_CONTINUE_RECORD_CAPACITY, needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_continue_records()
{
    return cc0_compiler_ensure_continue_records_(0, 0);
}

function cc0_compiler_ensure_loop_stack_(needed, used, memory)
{
    needed = shl(add(CC0_LOOP_DEPTH, 1), CC0_WORD_ADDRESS_SHIFT);
    used = shl(CC0_LOOP_DEPTH, CC0_WORD_ADDRESS_SHIFT);
    memory = cc0_compiler_grow_memory(CC0_LOOP_STACK, used,
        CC0_LOOP_STACK_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_LOOP_STACK = memory;
    CC0_LOOP_STACK_CAPACITY = cc0_compiler_grown_capacity(
        CC0_LOOP_STACK_CAPACITY, needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_loop_stack()
{
    return cc0_compiler_ensure_loop_stack_(0, 0, 0);
}

function cc0_compiler_add_symbol(table, count, name, length, value)
{
    return cc0_compiler_add_symbol_(table, count, name, length, value, 0);
}

function cc0_compiler_prepare_symbols()
{
    CC0_GLOBAL_COUNT = 0;
    CC0_FUNCTION_COUNT = 0;
    CC0_PARAMETER_COUNT = 0;
    return CC0_FALSE;
}

function cc0_compiler_ensure_code_(needed, memory)
{
    memory = cc0_compiler_grow_memory(CC0_CODE, CC0_CODE_LENGTH,
        CC0_CODE_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_CODE = memory;
    CC0_CODE_CAPACITY = cc0_compiler_grown_capacity(CC0_CODE_CAPACITY,
        needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_code(needed)
{
    return cc0_compiler_ensure_code_(needed, 0);
}

function cc0_compiler_ensure_data_(needed, memory)
{
    memory = cc0_compiler_grow_memory(CC0_DATA, CC0_DATA_LENGTH,
        CC0_DATA_CAPACITY, needed);
    if (eq(memory, 0)) {
        return cc0_compiler_fail();
    }
    CC0_DATA = memory;
    CC0_DATA_CAPACITY = cc0_compiler_grown_capacity(CC0_DATA_CAPACITY,
        needed);
    return CC0_FALSE;
}

function cc0_compiler_ensure_data(needed)
{
    return cc0_compiler_ensure_data_(needed, 0);
}

function cc0_compiler_prepare_code()
{
    CC0_CODE_LENGTH = 0;
    CC0_DATA_LENGTH = 0;
    CC0_CALL_COUNT = 0;
    CC0_RELOCATION_COUNT = 0;
    CC0_LOOP_DEPTH = 0;
    CC0_NEXT_LOOP_ID = 0;
    CC0_BREAK_COUNT = 0;
    if (cc0_compiler_ensure_data(CC0_WORD_BYTES)) {
        return CC0_TRUE;
    }
    wi32(CC0_DATA, 0);
    CC0_DATA_LENGTH = CC0_WORD_BYTES;
    return CC0_FALSE;
}

function cc0_compiler_emit_byte(value)
{
    if (cc0_compiler_ensure_code(add(CC0_CODE_LENGTH, 1))) {
        return CC0_TRUE;
    }
    wi8(add(CC0_CODE, CC0_CODE_LENGTH), value);
    CC0_CODE_LENGTH = add(CC0_CODE_LENGTH, 1);
    return CC0_FALSE;
}

function cc0_compiler_emit_word(value)
{
    if (cc0_compiler_ensure_code(add(CC0_CODE_LENGTH, CC0_WORD_BYTES))) {
        return CC0_TRUE;
    }
    wi32(add(CC0_CODE, CC0_CODE_LENGTH), value);
    CC0_CODE_LENGTH = add(CC0_CODE_LENGTH, CC0_WORD_BYTES);
    return CC0_FALSE;
}

function cc0_compiler_patch_word(position, value)
{
    if (not(le(add(position, CC0_WORD_BYTES), CC0_CODE_LENGTH))) {
        return cc0_compiler_fail();
    }
    wi32(add(CC0_CODE, position), value);
    return CC0_FALSE;
}

function cc0_compiler_emit_data_byte(value)
{
    if (cc0_compiler_ensure_data(add(CC0_DATA_LENGTH, 1))) {
        return CC0_TRUE;
    }
    wi8(add(CC0_DATA, CC0_DATA_LENGTH), value);
    CC0_DATA_LENGTH = add(CC0_DATA_LENGTH, 1);
    return CC0_FALSE;
}

function cc0_compiler_record_call(name, length, position, argument_count)
{
    if (cc0_compiler_ensure_call_records()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_add_symbol(CC0_CALL_RECORDS, CC0_CALL_COUNT,
        name, length, position)) {
        return CC0_TRUE;
    }
    wi32(add(cc0_compiler_symbol_entry(CC0_CALL_RECORDS, CC0_CALL_COUNT),
        CC0_SYMBOL_CODE_OFFSET), argument_count);
    CC0_CALL_COUNT = add(CC0_CALL_COUNT, 1);
    return CC0_FALSE;
}

function cc0_compiler_record_relocation(name, length, position, addend)
{
    if (cc0_compiler_ensure_relocation_records()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_add_symbol(CC0_RELOCATION_RECORDS,
        CC0_RELOCATION_COUNT, name, length, position)) {
        return CC0_TRUE;
    }
    wi32(add(cc0_compiler_symbol_entry(CC0_RELOCATION_RECORDS,
        CC0_RELOCATION_COUNT), CC0_SYMBOL_CODE_OFFSET), addend);
    CC0_RELOCATION_COUNT = add(CC0_RELOCATION_COUNT, 1);
    return CC0_FALSE;
}

function cc0_compiler_register_string_(text, length, start, index)
{
    start = CC0_DATA_LENGTH;
    index = 0;
    while (lt(index, length)) {
        cc0_compiler_emit_data_byte(ri8(add(text, index)));
        index = add(index, 1);
    }
    cc0_compiler_emit_data_byte(0);
    return start;
}

function cc0_compiler_register_string(text, length)
{
    return cc0_compiler_register_string_(text, length, 0, 0);
}

function cc0_compiler_emit_data_address_(text, length, addend, position)
{
    addend = cc0_compiler_register_string(text, length);
    cc0_compiler_emit_byte(CC0_X86_MOV_EAX_IMMEDIATE);
    position = CC0_CODE_LENGTH;
    cc0_compiler_emit_word(addend);
    cc0_compiler_record_relocation(mks(".data"), 5, position, addend);
    return CC0_FALSE;
}

function cc0_compiler_emit_data_address(text, length)
{
    return cc0_compiler_emit_data_address_(text, length, 0, 0);
}

function cc0_compiler_emit_load_global(name, length)
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_EAX_ABSOLUTE);
    cc0_compiler_record_relocation(name, length, CC0_CODE_LENGTH, 0);
    return cc0_compiler_emit_word(0);
}

function cc0_compiler_emit_store_global(name, length)
{
    cc0_compiler_emit_byte(CC0_X86_STORE_EAX_ABSOLUTE);
    cc0_compiler_record_relocation(name, length, CC0_CODE_LENGTH, 0);
    return cc0_compiler_emit_word(0);
}

function cc0_compiler_emit_prologue(local_count)
{
    cc0_compiler_emit_byte(CC0_X86_PUSH_EBP);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_EBP_ESP);
    cc0_compiler_emit_byte(CC0_X86_PUSH_EBX);
    if (not(eq(local_count, 0))) {
        cc0_compiler_emit_byte(CC0_X86_ADD_IMMEDIATE_OPCODE);
        cc0_compiler_emit_byte(CC0_X86_SUB_ESP_IMMEDIATE);
        cc0_compiler_emit_word(shl(local_count, CC0_WORD_ADDRESS_SHIFT));
    }
    return CC0_FALSE;
}

function cc0_compiler_emit_epilogue()
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_LOAD_EBX_FROM_FRAME);
    cc0_compiler_emit_byte(CC0_X86_SAVED_EBX_DISPLACEMENT);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ESP_EBP);
    cc0_compiler_emit_byte(CC0_X86_POP_EBP);
    cc0_compiler_emit_byte(CC0_X86_RETURN);
    return CC0_FALSE;
}

function cc0_compiler_emit_immediate(value)
{
    cc0_compiler_emit_byte(CC0_X86_MOV_EAX_IMMEDIATE);
    return cc0_compiler_emit_word(value);
}

function cc0_compiler_emit_push_result()
{
    return cc0_compiler_emit_byte(CC0_X86_PUSH_EAX);
}

function cc0_compiler_emit_pop_left_operand()
{
    return cc0_compiler_emit_byte(CC0_X86_POP_EBX);
}

function cc0_compiler_emit_load_parameter(offset)
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_LOAD_EAX_FROM_FRAME);
    return cc0_compiler_emit_byte(offset);
}

function cc0_compiler_emit_store_parameter(offset)
{
    cc0_compiler_emit_byte(CC0_X86_STORE_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_STORE_EAX_TO_FRAME);
    return cc0_compiler_emit_byte(offset);
}

/* Locals use a full displacement so frame size is not constrained to 127
 * bytes by i386's compact frame-addressing form. */
function cc0_compiler_emit_load_local(offset)
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_LOAD_EAX_FROM_FRAME_WORD);
    return cc0_compiler_emit_word(offset);
}

function cc0_compiler_emit_store_local(offset)
{
    cc0_compiler_emit_byte(CC0_X86_STORE_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_STORE_EAX_TO_FRAME_WORD);
    return cc0_compiler_emit_word(offset);
}

function cc0_compiler_emit_frame_address(offset)
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_ADDRESS_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_LOAD_ADDRESS_FRAME_WORD);
    return cc0_compiler_emit_word(offset);
}

function cc0_compiler_emit_test_result()
{
    cc0_compiler_emit_byte(CC0_X86_TEST_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_TEST_EAX_EAX);
}

function cc0_compiler_emit_zero_jump_(position)
{
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_JUMP_IF_ZERO);
    position = CC0_CODE_LENGTH;
    cc0_compiler_emit_word(0);
    return position;
}

function cc0_compiler_emit_zero_jump()
{
    return cc0_compiler_emit_zero_jump_(0);
}

function cc0_compiler_emit_nonzero_jump_(position)
{
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_JUMP_IF_NOT_ZERO);
    position = CC0_CODE_LENGTH;
    cc0_compiler_emit_word(0);
    return position;
}

function cc0_compiler_emit_nonzero_jump()
{
    return cc0_compiler_emit_nonzero_jump_(0);
}

function cc0_compiler_emit_jump_(position)
{
    cc0_compiler_emit_byte(CC0_X86_JUMP_RELATIVE);
    position = CC0_CODE_LENGTH;
    cc0_compiler_emit_word(0);
    return position;
}

function cc0_compiler_emit_jump()
{
    return cc0_compiler_emit_jump_(0);
}

function cc0_compiler_patch_relative(position, target)
{
    return cc0_compiler_patch_word(position,
        sub(target, add(position, CC0_WORD_BYTES)));
}

function cc0_compiler_emit_jump_to_(target, position)
{
    position = cc0_compiler_emit_jump();
    return cc0_compiler_patch_relative(position, target);
}

function cc0_compiler_emit_jump_to(target)
{
    return cc0_compiler_emit_jump_to_(target, 0);
}

function cc0_compiler_emit_call_placeholder_(position)
{
    cc0_compiler_emit_byte(CC0_X86_CALL_RELATIVE);
    position = CC0_CODE_LENGTH;
    cc0_compiler_emit_word(0);
    return position;
}

function cc0_compiler_emit_call_placeholder()
{
    return cc0_compiler_emit_call_placeholder_(0);
}

function cc0_compiler_patch_calls_(index, call_entry, function_index, function_entry, position, target)
{
    index = 0;
    while (lt(index, CC0_CALL_COUNT)) {
        call_entry = cc0_compiler_symbol_entry(CC0_CALL_RECORDS, index);
        function_index = cc0_compiler_find_symbol(CC0_FUNCTION_SYMBOLS,
            CC0_FUNCTION_COUNT,
            ri32(add(call_entry, CC0_SYMBOL_NAME_OFFSET)),
            ri32(add(call_entry, CC0_SYMBOL_LENGTH_OFFSET)));
        if (lt(function_index, 0)) {
            return cc0_compiler_fail();
        }
        function_entry = cc0_compiler_symbol_entry(CC0_FUNCTION_SYMBOLS,
            function_index);
        position = ri32(add(call_entry, CC0_SYMBOL_VALUE_OFFSET));
        target = ri32(add(function_entry, CC0_SYMBOL_CODE_OFFSET));
        cc0_compiler_patch_relative(position, target);
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_compiler_patch_calls()
{
    return cc0_compiler_patch_calls_(0, 0, 0, 0, 0, 0);
}

function cc0_compiler_push_loop_(loop_id)
{
    if (cc0_compiler_ensure_loop_stack()) {
        return CC0_TRUE;
    }
    loop_id = add(CC0_NEXT_LOOP_ID, 1);
    CC0_NEXT_LOOP_ID = loop_id;
    wi32(add(CC0_LOOP_STACK,
        shl(CC0_LOOP_DEPTH, CC0_WORD_ADDRESS_SHIFT)), loop_id);
    CC0_LOOP_DEPTH = add(CC0_LOOP_DEPTH, 1);
    return loop_id;
}

function cc0_compiler_push_loop()
{
    return cc0_compiler_push_loop_(0);
}

function cc0_compiler_current_loop()
{
    if (lt(CC0_LOOP_DEPTH, 1)) {
        return sub(0, 1);
    }
    return ri32(add(CC0_LOOP_STACK, shl(sub(CC0_LOOP_DEPTH, 1),
        CC0_WORD_ADDRESS_SHIFT)));
}

function cc0_compiler_pop_loop()
{
    if (lt(CC0_LOOP_DEPTH, 1)) {
        return cc0_compiler_fail();
    }
    CC0_LOOP_DEPTH = sub(CC0_LOOP_DEPTH, 1);
    return CC0_FALSE;
}

function cc0_compiler_record_break(loop_id, position)
{
    if (cc0_compiler_ensure_break_records()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_add_symbol(CC0_BREAK_RECORDS, CC0_BREAK_COUNT,
        0, 0, loop_id)) {
        return CC0_TRUE;
    }
    wi32(add(cc0_compiler_symbol_entry(CC0_BREAK_RECORDS,
        CC0_BREAK_COUNT), CC0_SYMBOL_CODE_OFFSET), position);
    CC0_BREAK_COUNT = add(CC0_BREAK_COUNT, 1);
    return CC0_FALSE;
}

function cc0_compiler_patch_breaks_(loop_id, target, index, entry)
{
    index = 0;
    while (lt(index, CC0_BREAK_COUNT)) {
        entry = cc0_compiler_symbol_entry(CC0_BREAK_RECORDS, index);
        if (eq(ri32(add(entry, CC0_SYMBOL_VALUE_OFFSET)), loop_id)) {
            cc0_compiler_patch_relative(
                ri32(add(entry, CC0_SYMBOL_CODE_OFFSET)), target);
        }
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_compiler_patch_breaks(loop_id, target)
{
    return cc0_compiler_patch_breaks_(loop_id, target, 0, 0);
}

function cc0_compiler_record_continue(loop_id, position)
{
    if (cc0_compiler_ensure_continue_records()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_add_symbol(CC0_CONTINUE_RECORDS, CC0_CONTINUE_COUNT,
        0, 0, loop_id)) {
        return CC0_TRUE;
    }
    wi32(add(cc0_compiler_symbol_entry(CC0_CONTINUE_RECORDS,
        CC0_CONTINUE_COUNT), CC0_SYMBOL_CODE_OFFSET), position);
    CC0_CONTINUE_COUNT = add(CC0_CONTINUE_COUNT, 1);
    return CC0_FALSE;
}

function cc0_compiler_patch_continues_(loop_id, target, index, entry)
{
    index = 0;
    while (lt(index, CC0_CONTINUE_COUNT)) {
        entry = cc0_compiler_symbol_entry(CC0_CONTINUE_RECORDS, index);
        if (eq(ri32(add(entry, CC0_SYMBOL_VALUE_OFFSET)), loop_id)) {
            cc0_compiler_patch_relative(
                ri32(add(entry, CC0_SYMBOL_CODE_OFFSET)), target);
        }
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_compiler_patch_continues(loop_id, target)
{
    return cc0_compiler_patch_continues_(loop_id, target, 0, 0);
}

function cc0_compiler_emit_drop_arguments(argument_bytes)
{
    if (eq(argument_bytes, 0)) {
        return CC0_FALSE;
    }
    cc0_compiler_emit_byte(CC0_X86_ADD_IMMEDIATE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ADD_ESP_IMMEDIATE);
    return cc0_compiler_emit_word(argument_bytes);
}

function cc0_compiler_emit_load_eax_stack(displacement)
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_LOAD_EAX_STACK);
    cc0_compiler_emit_byte(CC0_X86_STACK_ADDRESS_SUFFIX);
    return cc0_compiler_emit_word(displacement);
}

function cc0_compiler_emit_load_ebx_stack(displacement)
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_LOAD_EBX_STACK);
    cc0_compiler_emit_byte(CC0_X86_STACK_ADDRESS_SUFFIX);
    return cc0_compiler_emit_word(displacement);
}

function cc0_compiler_emit_store_ebx_stack(displacement)
{
    cc0_compiler_emit_byte(CC0_X86_STORE_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_STORE_EBX_STACK);
    cc0_compiler_emit_byte(CC0_X86_STACK_ADDRESS_SUFFIX);
    return cc0_compiler_emit_word(displacement);
}

function cc0_compiler_emit_store_eax_stack(displacement)
{
    cc0_compiler_emit_byte(CC0_X86_STORE_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_STORE_EAX_STACK);
    cc0_compiler_emit_byte(CC0_X86_STACK_ADDRESS_SUFFIX);
    return cc0_compiler_emit_word(displacement);
}

function cc0_compiler_reverse_arguments_(argument_count, index, low, high)
{
    index = 0;
    while (lt(shl(index, 1), argument_count)) {
        low = shl(index, CC0_WORD_ADDRESS_SHIFT);
        high = shl(sub(sub(argument_count, 1), index),
            CC0_WORD_ADDRESS_SHIFT);
        cc0_compiler_emit_load_eax_stack(low);
        cc0_compiler_emit_load_ebx_stack(high);
        cc0_compiler_emit_store_ebx_stack(low);
        cc0_compiler_emit_store_eax_stack(high);
        index = add(index, 1);
    }
    return CC0_FALSE;
}

function cc0_compiler_reverse_arguments(argument_count)
{
    return cc0_compiler_reverse_arguments_(argument_count, 0, 0, 0);
}

function cc0_compiler_parameter_offset_(name, length, index)
{
    index = cc0_compiler_find_symbol(CC0_PARAMETER_SYMBOLS,
        CC0_PARAMETER_COUNT, name, length);
    if (lt(index, 0)) {
        return index;
    }
    return add(CC0_PARAMETER_FIRST_OFFSET,
        shl(index, CC0_WORD_ADDRESS_SHIFT));
}

function cc0_compiler_parameter_offset(name, length)
{
    return cc0_compiler_parameter_offset_(name, length, 0);
}

function cc0_compiler_local_offset_(name, length, index)
{
    index = cc0_compiler_find_symbol(CC0_LOCAL_SYMBOLS,
        CC0_LOCAL_COUNT, name, length);
    if (lt(index, 0)) {
        return index;
    }
    return sub(0, shl(add(index, 2), CC0_WORD_ADDRESS_SHIFT));
}

function cc0_compiler_local_offset(name, length)
{
    return cc0_compiler_local_offset_(name, length, 0);
}

function cc0_compiler_emit_load_variable_(name, length, offset, local_offset)
{
    local_offset = cc0_compiler_local_offset(name, length);
    if (lt(local_offset, sub(0, 1))) {
        return cc0_compiler_emit_load_local(local_offset);
    }
    offset = cc0_compiler_parameter_offset(name, length);
    if (not(lt(offset, 0))) {
        return cc0_compiler_emit_load_parameter(offset);
    }
    return cc0_compiler_emit_load_global(name, length);
}

function cc0_compiler_emit_load_variable(name, length)
{
    return cc0_compiler_emit_load_variable_(name, length, 0, 0);
}

function cc0_compiler_emit_store_variable_(name, length, offset,
    local_offset)
{
    local_offset = cc0_compiler_local_offset(name, length);
    if (lt(local_offset, sub(0, 1))) {
        return cc0_compiler_emit_store_local(local_offset);
    }
    offset = cc0_compiler_parameter_offset(name, length);
    if (not(lt(offset, 0))) {
        return cc0_compiler_emit_store_parameter(offset);
    }
    return cc0_compiler_emit_store_global(name, length);
}

function cc0_compiler_emit_store_variable(name, length)
{
    return cc0_compiler_emit_store_variable_(name, length, 0, 0);
}

function cc0_compiler_emit_address_variable_(name, length, offset)
{
    offset = cc0_compiler_local_offset(name, length);
    if (lt(offset, sub(0, 1))) {
        return cc0_compiler_emit_frame_address(offset);
    }
    offset = cc0_compiler_parameter_offset(name, length);
    if (not(lt(offset, 0))) {
        return cc0_compiler_emit_frame_address(offset);
    }
    cc0_compiler_emit_byte(CC0_X86_MOV_EAX_IMMEDIATE);
    cc0_compiler_record_relocation(name, length, CC0_CODE_LENGTH, 0);
    return cc0_compiler_emit_word(0);
}

function cc0_compiler_emit_address_variable(name, length)
{
    return cc0_compiler_emit_address_variable_(name, length, 0);
}

function cc0_compiler_emit_user_call_(name, length, argument_count, position)
{
    cc0_compiler_reverse_arguments(argument_count);
    position = cc0_compiler_emit_call_placeholder();
    cc0_compiler_record_call(name, length, position, argument_count);
    return cc0_compiler_emit_drop_arguments(
        shl(argument_count, CC0_WORD_ADDRESS_SHIFT));
}

function cc0_compiler_emit_user_call(name, length, argument_count)
{
    return cc0_compiler_emit_user_call_(name, length, argument_count, 0);
}

function cc0_compiler_emit_external_call_(name, length, argument_count,
    position, addend)
{
    cc0_compiler_reverse_arguments(argument_count);
    cc0_compiler_emit_byte(CC0_X86_CALL_RELATIVE);
    position = CC0_CODE_LENGTH;
    addend = sub(0, CC0_WORD_BYTES);
    cc0_compiler_emit_word(addend);
    cc0_compiler_record_relocation(name, length, position, addend);
    return cc0_compiler_emit_drop_arguments(
        shl(argument_count, CC0_WORD_ADDRESS_SHIFT));
}

function cc0_compiler_emit_external_call(name, length, argument_count)
{
    return cc0_compiler_emit_external_call_(name, length, argument_count,
        0, 0);
}

function cc0_compiler_emit_compare(condition)
{
    cc0_compiler_emit_byte(CC0_X86_COMPARE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_COMPARE_EBX_EAX);
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(condition);
    cc0_compiler_emit_byte(CC0_X86_SET_EAX_BYTE);
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_EAX_BYTE);
}

function cc0_compiler_emit_not()
{
    cc0_compiler_emit_test_result();
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_SET_EQUAL);
    cc0_compiler_emit_byte(CC0_X86_SET_EAX_BYTE);
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_EAX_BYTE);
}

function cc0_compiler_emit_add()
{
    cc0_compiler_emit_byte(CC0_X86_ADD_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_ADD_EAX_EBX);
}

function cc0_compiler_emit_subtract()
{
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ECX_EAX);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_EAX_EBX);
    cc0_compiler_emit_byte(CC0_X86_SUB_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_SUB_EAX_ECX);
}

function cc0_compiler_emit_multiply()
{
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_SIGNED_MULTIPLY_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_MULTIPLY_EAX_EBX);
}

function cc0_compiler_emit_division_()
{
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ECX_EAX);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_EAX_EBX);
    cc0_compiler_emit_byte(CC0_X86_SIGN_EXTEND_EAX);
    cc0_compiler_emit_byte(CC0_X86_DIVIDE_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_DIVIDE_BY_ECX);
}

function cc0_compiler_emit_division()
{
    return cc0_compiler_emit_division_();
}

function cc0_compiler_emit_remainder()
{
    cc0_compiler_emit_division_();
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_MOV_EAX_EDX);
}

function cc0_compiler_emit_and()
{
    cc0_compiler_emit_byte(CC0_X86_AND_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_AND_EAX_EBX);
}

function cc0_compiler_emit_or()
{
    cc0_compiler_emit_byte(CC0_X86_OR_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_OR_EAX_EBX);
}

function cc0_compiler_emit_xor()
{
    cc0_compiler_emit_byte(CC0_X86_XOR_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_XOR_EAX_EBX);
}

function cc0_compiler_emit_complement()
{
    cc0_compiler_emit_byte(CC0_X86_DIVIDE_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_COMPLEMENT_EAX);
}

function cc0_compiler_emit_shift_left()
{
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ECX_EAX);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_BY_CL_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_LEFT_EBX);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_MOV_EAX_EBX);
}

function cc0_compiler_emit_shift_right()
{
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ECX_EAX);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_BY_CL_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_RIGHT_EBX);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_MOV_EAX_EBX);
}

function cc0_compiler_emit_shift_right_signed()
{
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_MOV_ECX_EAX);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_BY_CL_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_SHIFT_RIGHT_SIGNED_EBX);
    cc0_compiler_emit_byte(CC0_X86_MOV_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_MOV_EAX_EBX);
}

function cc0_compiler_emit_read_word()
{
    cc0_compiler_emit_byte(CC0_X86_LOAD_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_LOAD_EAX_ADDRESS);
}

function cc0_compiler_emit_read_byte()
{
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_LOAD_EAX_BYTE_ADDRESS);
}

function cc0_compiler_emit_write_word()
{
    cc0_compiler_emit_byte(CC0_X86_STORE_REGISTER_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_STORE_EAX_ADDRESS);
}

function cc0_compiler_emit_write_byte()
{
    cc0_compiler_emit_byte(CC0_X86_STORE_EAX_BYTE_ADDRESS_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_STORE_EAX_BYTE_ADDRESS);
    cc0_compiler_emit_byte(CC0_X86_TWO_BYTE_OPCODE);
    cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_OPCODE);
    return cc0_compiler_emit_byte(CC0_X86_ZERO_EXTEND_EAX_BYTE);
}

function cc0_compiler_emit_builtin(name, length)
{
    if (cc0_text_equal(name, length, mks("comma"))) {
        return CC0_FALSE;
    }
    if (cc0_text_equal(name, length, mks("not"))) {
        return cc0_compiler_emit_not();
    }
    if (cc0_text_equal(name, length, mks("ri8"))) {
        return cc0_compiler_emit_read_byte();
    }
    if (cc0_text_equal(name, length, mks("ri32"))) {
        return cc0_compiler_emit_read_word();
    }
    if (cc0_text_equal(name, length, mks("add"))) {
        return cc0_compiler_emit_add();
    }
    if (cc0_text_equal(name, length, mks("sub"))) {
        return cc0_compiler_emit_subtract();
    }
    if (cc0_text_equal(name, length, mks("mul"))) {
        return cc0_compiler_emit_multiply();
    }
    if (cc0_text_equal(name, length, mks("sdiv"))) {
        return cc0_compiler_emit_division();
    }
    if (cc0_text_equal(name, length, mks("mod"))) {
        return cc0_compiler_emit_remainder();
    }
    if (cc0_text_equal(name, length, mks("eq"))) {
        return cc0_compiler_emit_compare(CC0_X86_SET_EQUAL);
    }
    if (cc0_text_equal(name, length, mks("lt"))) {
        return cc0_compiler_emit_compare(CC0_X86_SET_LESS);
    }
    if (cc0_text_equal(name, length, mks("le"))) {
        return cc0_compiler_emit_compare(CC0_X86_SET_LESS_EQUAL);
    }
    if (cc0_text_equal(name, length, mks("and"))) {
        return cc0_compiler_emit_and();
    }
    if (cc0_text_equal(name, length, mks("or"))) {
        return cc0_compiler_emit_or();
    }
    if (cc0_text_equal(name, length, mks("xor"))) {
        return cc0_compiler_emit_xor();
    }
    if (cc0_text_equal(name, length, mks("bnot"))) {
        return cc0_compiler_emit_complement();
    }
    if (cc0_text_equal(name, length, mks("shl"))) {
        return cc0_compiler_emit_shift_left();
    }
    if (cc0_text_equal(name, length, mks("ushr"))) {
        return cc0_compiler_emit_shift_right();
    }
    if (cc0_text_equal(name, length, mks("shr"))) {
        return cc0_compiler_emit_shift_right_signed();
    }
    if (cc0_text_equal(name, length, mks("wi8"))) {
        return cc0_compiler_emit_write_byte();
    }
    if (cc0_text_equal(name, length, mks("wi32"))) {
        return cc0_compiler_emit_write_word();
    }
    return cc0_compiler_fail();
}

function cc0_compiler_name_exists(name, length)
{
    if (not(lt(cc0_compiler_find_symbol(CC0_GLOBAL_SYMBOLS,
        CC0_GLOBAL_COUNT, name, length), 0))) {
        return CC0_TRUE;
    }
    return not(lt(cc0_compiler_find_symbol(CC0_FUNCTION_SYMBOLS,
        CC0_FUNCTION_COUNT, name, length), 0));
}

function cc0_compiler_variable_exists(name, length)
{
    if (not(lt(cc0_compiler_find_symbol(CC0_LOCAL_SYMBOLS,
        CC0_LOCAL_COUNT, name, length), 0))) {
        return CC0_TRUE;
    }
    if (not(lt(cc0_compiler_find_symbol(CC0_PARAMETER_SYMBOLS,
        CC0_PARAMETER_COUNT, name, length), 0))) {
        return CC0_TRUE;
    }
    return not(lt(cc0_compiler_find_symbol(CC0_GLOBAL_SYMBOLS,
        CC0_GLOBAL_COUNT, name, length), 0));
}

function cc0_compiler_builtin_arity(name, length)
{
    if (cc0_text_equal(name, length, mks("malloc"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("realloc"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("close"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("alloc"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("system"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("cc0_lexer_field"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("cc0_lexer_advance"))) {
        return 0;
    }
    if (cc0_text_equal(name, length, mks("not"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("mks"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("ri8"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("ri32"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("add"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("sub"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("mul"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("sdiv"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("mod"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("eq"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("lt"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("le"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("and"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("or"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("xor"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("bnot"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("shl"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("ushr"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("shr"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("wi8"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("wi32"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("comma"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("open"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("lseek"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("read"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("write"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc1_link"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("chmod"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc0_lexer_start"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc0_compile"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_compile"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc1_compile_base"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc2_compile"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc0_remap_error"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc0_remap_error_location"))) {
        return 6;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_begin"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_finish"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_fail"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_token_count"))) {
        return 0;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_token_at"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_replace_tokens"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_token_field"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_token_new"))) {
        return 5;
    }
    if (cc0_text_equal(name, length, mks("gen_vla_sp_restore"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("sym_redeclaration_error"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("vstack_overflow_error"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("gv"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("o"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("gsym"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("put_extern_sym"))) {
        return 4;
    }
    if (cc0_text_equal(name, length, mks("update_storage"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("save_reg_upstack"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("store"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("load"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("get_tok_str"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("tcc_error"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("tcc_warning"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("next"))) {
        return 0;
    }
    if (cc0_text_equal(name, length, mks("unary"))) {
        return 0;
    }
    if (cc0_text_equal(name, length, mks("gen_op"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("gen_cast_s"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("gvtst"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("gen_cast"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("gen_assign_cast"))) {
        return 1;
    }
    return sub(0, 1);
}

function cc0_compiler_external_arity(name, length)
{
    if (cc0_text_equal(name, length, mks("malloc"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("realloc"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("close"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("alloc"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("system"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("cc0_lexer_field"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("cc0_lexer_advance"))) {
        return 0;
    }
    if (cc0_text_equal(name, length, mks("open"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("lseek"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("read"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("write"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc1_link"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("chmod"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc0_lexer_start"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc0_compile"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_compile"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc1_compile_base"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc2_compile"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc0_remap_error"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc0_remap_error_location"))) {
        return 6;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_begin"))) {
        return 3;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_finish"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_fail"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_token_count"))) {
        return 0;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_token_at"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_replace_tokens"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_token_field"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("cc1_layer_token_new"))) {
        return 5;
    }
    if (cc0_text_equal(name, length, mks("gen_vla_sp_restore"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("sym_redeclaration_error"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("vstack_overflow_error"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("gv"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("o"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("gsym"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("put_extern_sym"))) {
        return 4;
    }
    if (cc0_text_equal(name, length, mks("update_storage"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("save_reg_upstack"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("store"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("load"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("get_tok_str"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("tcc_error"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("tcc_warning"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("next"))) {
        return 0;
    }
    if (cc0_text_equal(name, length, mks("unary"))) {
        return 0;
    }
    if (cc0_text_equal(name, length, mks("gen_op"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("gen_cast_s"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("gvtst"))) {
        return 2;
    }
    if (cc0_text_equal(name, length, mks("gen_cast"))) {
        return 1;
    }
    if (cc0_text_equal(name, length, mks("gen_assign_cast"))) {
        return 1;
    }
    return sub(0, 1);
}

function cc0_compiler_function_arity_(name, length, index, entry)
{
    index = cc0_compiler_find_symbol(CC0_FUNCTION_SYMBOLS,
        CC0_FUNCTION_COUNT, name, length);
    if (lt(index, 0)) {
        return cc0_compiler_builtin_arity(name, length);
    }
    entry = cc0_compiler_symbol_entry(CC0_FUNCTION_SYMBOLS, index);
    return ri32(add(entry, CC0_SYMBOL_VALUE_OFFSET));
}

function cc0_compiler_function_arity(name, length)
{
    return cc0_compiler_function_arity_(name, length, 0, 0);
}

function cc0_compiler_set_function_code_(name, length, index, entry)
{
    index = cc0_compiler_find_symbol(CC0_FUNCTION_SYMBOLS,
        CC0_FUNCTION_COUNT, name, length);
    if (lt(index, 0)) {
        return cc0_compiler_fail();
    }
    entry = cc0_compiler_symbol_entry(CC0_FUNCTION_SYMBOLS, index);
    wi32(add(entry, CC0_SYMBOL_CODE_OFFSET), CC0_CODE_LENGTH);
    return CC0_FALSE;
}

function cc0_compiler_set_function_code(name, length)
{
    return cc0_compiler_set_function_code_(name, length, 0, 0);
}

function cc0_compiler_function_local_count_(name, length, index, entry)
{
    index = cc0_compiler_find_symbol(CC0_FUNCTION_SYMBOLS,
        CC0_FUNCTION_COUNT, name, length);
    if (lt(index, 0)) {
        return 0;
    }
    entry = cc0_compiler_symbol_entry(CC0_FUNCTION_SYMBOLS, index);
    return ri32(add(entry, CC0_SYMBOL_CODE_OFFSET));
}

function cc0_compiler_function_local_count(name, length)
{
    return cc0_compiler_function_local_count_(name, length, 0, 0);
}

function cc0_compiler_set_function_local_count_(name, length, count,
    index, entry)
{
    index = cc0_compiler_find_symbol(CC0_FUNCTION_SYMBOLS,
        CC0_FUNCTION_COUNT, name, length);
    if (lt(index, 0)) {
        return cc0_compiler_fail();
    }
    entry = cc0_compiler_symbol_entry(CC0_FUNCTION_SYMBOLS, index);
    wi32(add(entry, CC0_SYMBOL_CODE_OFFSET), count);
    return CC0_FALSE;
}

function cc0_compiler_set_function_local_count(name, length, count)
{
    return cc0_compiler_set_function_local_count_(name, length, count,
        0, 0);
}

function cc0_compiler_expect(token)
{
    if (not(eq(CC0_TOKEN, token))) {
        return cc0_compiler_fail();
    }
    cc0_compiler_next_token();
    return CC0_FALSE;
}

function cc0_compiler_parse_call_(name, length, argument_count, arity,
    builtin_arity, external_arity)
{
    builtin_arity = cc0_compiler_builtin_arity(name, length);
    external_arity = cc0_compiler_external_arity(name, length);
    if (not(lt(cc0_compiler_find_symbol(CC0_FUNCTION_SYMBOLS,
        CC0_FUNCTION_COUNT, name, length), 0))) {
        external_arity = sub(0, 1);
        builtin_arity = sub(0, 1);
    }
    cc0_compiler_next_token();
    argument_count = 0;
    if (not(eq(CC0_TOKEN, CC0_PUNCTUATION_RIGHT_PARENTHESIS))) {
        while (CC0_TRUE) {
            if (cc0_compiler_parse_expression()) {
                return CC0_TRUE;
            }
            if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
                if (not(lt(external_arity, 0))) {
                    cc0_compiler_emit_push_result();
                } else if (lt(builtin_arity, 0)) {
                    cc0_compiler_emit_push_result();
                } else if (eq(builtin_arity, 2)) {
                    if (eq(argument_count, 0)) {
                        cc0_compiler_emit_push_result();
                    }
                }
            }
            argument_count = add(argument_count, 1);
            if (not(eq(CC0_TOKEN, CC0_PUNCTUATION_COMMA))) {
                break;
            }
            cc0_compiler_next_token();
        }
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (not(eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT))) {
        arity = cc0_compiler_function_arity(name, length);
        if (lt(arity, 0)) {
            return cc0_compiler_fail();
        }
        if (not(eq(arity, argument_count))) {
            return cc0_compiler_fail();
        }
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        if (not(lt(external_arity, 0))) {
            return cc0_compiler_emit_external_call(name, length,
                argument_count);
        }
        if (lt(builtin_arity, 0)) {
            return cc0_compiler_emit_user_call(name, length, argument_count);
        }
        if (eq(builtin_arity, 2)) {
            cc0_compiler_emit_pop_left_operand();
        }
        if (cc0_text_equal(name, length, mks("mks"))) {
            return CC0_FALSE;
        }
        return cc0_compiler_emit_builtin(name, length);
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_address_(name, length)
{
    cc0_compiler_next_token();
    if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
        return cc0_compiler_fail();
    }
    name = CC0_TOKEN_START;
    length = CC0_TOKEN_LENGTH;
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_RESOLVE)) {
        if (not(cc0_compiler_variable_exists(name, length))) {
            return cc0_compiler_fail();
        }
    }
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        return cc0_compiler_emit_address_variable(name, length);
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_address()
{
    return cc0_compiler_parse_address_(0, 0);
}

function cc0_compiler_parse_logical_(is_or, branch_position,
    end_position)
{
    cc0_compiler_next_token();
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_emit_test_result();
        if (is_or) {
            branch_position = cc0_compiler_emit_nonzero_jump();
        } else {
            branch_position = cc0_compiler_emit_zero_jump();
        }
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_COMMA)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_emit_not();
        cc0_compiler_emit_not();
        end_position = cc0_compiler_emit_jump();
        cc0_compiler_patch_relative(branch_position, CC0_CODE_LENGTH);
        if (is_or) {
            cc0_compiler_emit_immediate(1);
        } else {
            cc0_compiler_emit_immediate(0);
        }
        return cc0_compiler_patch_relative(end_position, CC0_CODE_LENGTH);
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_logical(is_or)
{
    return cc0_compiler_parse_logical_(is_or, 0, 0);
}

function cc0_compiler_parse_select_(false_position, end_position)
{
    cc0_compiler_next_token();
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_emit_test_result();
        false_position = cc0_compiler_emit_zero_jump();
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_COMMA)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_COMMA)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        end_position = cc0_compiler_emit_jump();
        cc0_compiler_patch_relative(false_position, CC0_CODE_LENGTH);
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        return cc0_compiler_patch_relative(end_position, CC0_CODE_LENGTH);
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_select()
{
    return cc0_compiler_parse_select_(0, 0);
}

function cc0_compiler_parse_expression_(name, length)
{
    if (eq(CC0_TOKEN, CC0_TOKEN_NUMBER_LITERAL)) {
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
            cc0_compiler_emit_immediate(CC0_TOKEN_NUMBER);
        }
        cc0_compiler_next_token();
        return CC0_FALSE;
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_STRING_LITERAL)) {
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
            cc0_compiler_emit_data_address(CC0_TOKEN_START,
                CC0_TOKEN_LENGTH);
        }
        cc0_compiler_next_token();
        return CC0_FALSE;
    }
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        cc0_compiler_next_token();
        cc0_compiler_parse_expression_(0, 0);
        return cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS);
    }
    if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
        return cc0_compiler_fail();
    }
    name = CC0_TOKEN_START;
    length = CC0_TOKEN_LENGTH;
    cc0_compiler_next_token();
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_ASSIGN)) {
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_RESOLVE)) {
            if (not(cc0_compiler_variable_exists(name, length))) {
                return cc0_compiler_fail();
            }
        }
        cc0_compiler_next_token();
        if (cc0_compiler_parse_expression_(0, 0)) {
            return CC0_TRUE;
        }
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
            return cc0_compiler_emit_store_variable(name, length);
        }
        return CC0_FALSE;
    }
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        if (cc0_text_equal(name, length, mks("addr"))) {
            return cc0_compiler_parse_address();
        }
        if (cc0_text_equal(name, length, mks("land"))) {
            return cc0_compiler_parse_logical(0);
        }
        if (cc0_text_equal(name, length, mks("lor"))) {
            return cc0_compiler_parse_logical(1);
        }
        if (cc0_text_equal(name, length, mks("select"))) {
            return cc0_compiler_parse_select();
        }
        return cc0_compiler_parse_call_(name, length, 0, 0, 0, 0);
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_RESOLVE)) {
        if (not(cc0_compiler_variable_exists(name, length))) {
            return cc0_compiler_fail();
        }
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        return cc0_compiler_emit_load_variable(name, length);
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_expression()
{
    if (CC0_COMPILER_ERROR) {
        return CC0_TRUE;
    }
    return cc0_compiler_parse_expression_(0, 0);
}

function cc0_compiler_parse_block_()
{
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_BRACE)) {
        return CC0_TRUE;
    }
    while (not(eq(CC0_TOKEN, CC0_PUNCTUATION_RIGHT_BRACE))) {
        if (eq(CC0_TOKEN, CC0_TOKEN_EOF)) {
            return cc0_compiler_fail();
        }
        if (cc0_compiler_parse_statement()) {
            return CC0_TRUE;
        }
    }
    return cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_BRACE);
}

function cc0_compiler_parse_if_(false_position, end_position)
{
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_emit_test_result();
        false_position = cc0_compiler_emit_zero_jump();
    }
    if (cc0_compiler_parse_statement()) {
        return CC0_TRUE;
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_ELSE)) {
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
            end_position = cc0_compiler_emit_jump();
            cc0_compiler_patch_relative(false_position, CC0_CODE_LENGTH);
        }
        cc0_compiler_next_token();
        if (cc0_compiler_parse_statement()) {
            return CC0_TRUE;
        }
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
            return cc0_compiler_patch_relative(end_position,
                CC0_CODE_LENGTH);
        }
        return CC0_FALSE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        return cc0_compiler_patch_relative(false_position,
            CC0_CODE_LENGTH);
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_if()
{
    return cc0_compiler_parse_if_(0, 0);
}

function cc0_compiler_parse_while_(loop_start, exit_position, loop_id)
{
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        loop_start = CC0_CODE_LENGTH;
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_emit_test_result();
        exit_position = cc0_compiler_emit_zero_jump();
        loop_id = cc0_compiler_push_loop();
    } else {
        CC0_LOOP_DEPTH = add(CC0_LOOP_DEPTH, 1);
    }
    if (cc0_compiler_parse_statement()) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_patch_continues(loop_id, loop_start);
        cc0_compiler_emit_jump_to(loop_start);
        cc0_compiler_patch_relative(exit_position, CC0_CODE_LENGTH);
        cc0_compiler_patch_breaks(loop_id, CC0_CODE_LENGTH);
        return cc0_compiler_pop_loop();
    }
    CC0_LOOP_DEPTH = sub(CC0_LOOP_DEPTH, 1);
    return CC0_FALSE;
}

function cc0_compiler_parse_while()
{
    return cc0_compiler_parse_while_(0, 0, 0);
}

function cc0_compiler_parse_deferred_expression_(start, end,
    saved_source_length, saved_source_position, saved_token,
    saved_token_start, saved_token_length, saved_token_number, result)
{
    if (eq(start, end)) {
        return CC0_FALSE;
    }
    saved_source_length = CC0_SOURCE_LENGTH;
    saved_source_position = CC0_SOURCE_POSITION;
    saved_token = CC0_TOKEN;
    saved_token_start = CC0_TOKEN_START;
    saved_token_length = CC0_TOKEN_LENGTH;
    saved_token_number = CC0_TOKEN_NUMBER;
    CC0_SOURCE_LENGTH = end;
    CC0_SOURCE_POSITION = start;
    CC0_TOKEN = CC0_TOKEN_EOF;
    cc0_compiler_next_token();
    result = cc0_compiler_parse_expression();
    if (not(eq(CC0_TOKEN, CC0_TOKEN_EOF))) {
        result = cc0_compiler_fail();
    }
    CC0_SOURCE_LENGTH = saved_source_length;
    CC0_SOURCE_POSITION = saved_source_position;
    CC0_TOKEN = saved_token;
    CC0_TOKEN_START = saved_token_start;
    CC0_TOKEN_LENGTH = saved_token_length;
    CC0_TOKEN_NUMBER = saved_token_number;
    return result;
}

function cc0_compiler_parse_deferred_expression(start, end)
{
    return cc0_compiler_parse_deferred_expression_(start, end, 0, 0, 0,
        0, 0, 0, 0);
}

function cc0_compiler_parse_for_(loop_start, exit_position, loop_id,
    step_start, step_end, depth, continue_target)
{
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (not(eq(CC0_TOKEN, CC0_PUNCTUATION_SEMICOLON))) {
        if (cc0_compiler_parse_expression()) {
            return CC0_TRUE;
        }
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        loop_start = CC0_CODE_LENGTH;
    }
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_SEMICOLON)) {
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
            cc0_compiler_emit_immediate(1);
        }
    } else {
        if (cc0_compiler_parse_expression()) {
            return CC0_TRUE;
        }
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_emit_test_result();
        exit_position = cc0_compiler_emit_zero_jump();
        loop_id = cc0_compiler_push_loop();
    } else {
        CC0_LOOP_DEPTH = add(CC0_LOOP_DEPTH, 1);
    }
    step_start = sub(CC0_TOKEN_START, CC0_SOURCE);
    depth = 0;
    while (CC0_TRUE) {
        if (eq(CC0_TOKEN, CC0_TOKEN_EOF)) {
            return cc0_compiler_fail();
        }
        if (eq(CC0_TOKEN, CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
            depth = add(depth, 1);
        } else if (eq(CC0_TOKEN, CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
            if (eq(depth, 0)) {
                break;
            }
            depth = sub(depth, 1);
        }
        cc0_compiler_next_token();
    }
    step_end = sub(CC0_TOKEN_START, CC0_SOURCE);
    cc0_compiler_next_token();
    if (cc0_compiler_parse_statement()) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        continue_target = CC0_CODE_LENGTH;
        cc0_compiler_patch_continues(loop_id, continue_target);
    }
    if (cc0_compiler_parse_deferred_expression(step_start, step_end)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_emit_jump_to(loop_start);
        cc0_compiler_patch_relative(exit_position, CC0_CODE_LENGTH);
        cc0_compiler_patch_breaks(loop_id, CC0_CODE_LENGTH);
        return cc0_compiler_pop_loop();
    }
    CC0_LOOP_DEPTH = sub(CC0_LOOP_DEPTH, 1);
    return CC0_FALSE;
}

function cc0_compiler_parse_for()
{
    return cc0_compiler_parse_for_(0, 0, 0, 0, 0, 0, 0);
}

function cc0_compiler_parse_do_(loop_start, loop_id, jump_position,
    continue_target)
{
    cc0_compiler_next_token();
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        loop_start = CC0_CODE_LENGTH;
        loop_id = cc0_compiler_push_loop();
    } else {
        CC0_LOOP_DEPTH = add(CC0_LOOP_DEPTH, 1);
    }
    if (cc0_compiler_parse_statement()) {
        return CC0_TRUE;
    }
    if (not(eq(CC0_TOKEN, CC0_TOKEN_WHILE))) {
        return cc0_compiler_fail();
    }
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        continue_target = CC0_CODE_LENGTH;
        cc0_compiler_patch_continues(loop_id, continue_target);
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_emit_test_result();
        jump_position = cc0_compiler_emit_nonzero_jump();
        cc0_compiler_patch_relative(jump_position, loop_start);
        cc0_compiler_patch_breaks(loop_id, CC0_CODE_LENGTH);
        return cc0_compiler_pop_loop();
    }
    CC0_LOOP_DEPTH = sub(CC0_LOOP_DEPTH, 1);
    return CC0_FALSE;
}

function cc0_compiler_parse_do()
{
    return cc0_compiler_parse_do_(0, 0, 0, 0);
}

function cc0_compiler_parse_break_(position, loop_id)
{
    if (lt(CC0_LOOP_DEPTH, 1)) {
        return cc0_compiler_fail();
    }
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        loop_id = cc0_compiler_current_loop();
        position = cc0_compiler_emit_jump();
        return cc0_compiler_record_break(loop_id, position);
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_break()
{
    return cc0_compiler_parse_break_(0, 0);
}

function cc0_compiler_parse_continue_(position, loop_id)
{
    if (lt(CC0_LOOP_DEPTH, 1)) {
        return cc0_compiler_fail();
    }
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        loop_id = cc0_compiler_current_loop();
        position = cc0_compiler_emit_jump();
        return cc0_compiler_record_continue(loop_id, position);
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_continue()
{
    return cc0_compiler_parse_continue_(0, 0);
}

function cc0_compiler_parse_local_(name, length, initialized)
{
    cc0_compiler_next_token();
    if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
        return cc0_compiler_fail();
    }
    name = CC0_TOKEN_START;
    length = CC0_TOKEN_LENGTH;
    if (not(lt(cc0_compiler_find_symbol(CC0_LOCAL_SYMBOLS,
        CC0_LOCAL_COUNT, name, length), 0))) {
        return cc0_compiler_fail();
    }
    if (not(lt(cc0_compiler_find_symbol(CC0_PARAMETER_SYMBOLS,
        CC0_PARAMETER_COUNT, name, length), 0))) {
        return cc0_compiler_fail();
    }
    if (cc0_compiler_ensure_local_symbols()) {
        return CC0_TRUE;
    }
    cc0_compiler_add_symbol(CC0_LOCAL_SYMBOLS, CC0_LOCAL_COUNT,
        name, length, CC0_LOCAL_COUNT);
    CC0_LOCAL_COUNT = add(CC0_LOCAL_COUNT, 1);
    cc0_compiler_next_token();
    initialized = eq(CC0_TOKEN, CC0_PUNCTUATION_ASSIGN);
    if (initialized) {
        cc0_compiler_next_token();
        if (cc0_compiler_parse_expression()) {
            return CC0_TRUE;
        }
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
            cc0_compiler_emit_store_variable(name, length);
        }
    }
    return cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON);
}

function cc0_compiler_parse_local()
{
    return cc0_compiler_parse_local_(0, 0, 0);
}

function cc0_compiler_parse_statement()
{
    if (CC0_COMPILER_ERROR) {
        return CC0_TRUE;
    }
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_LEFT_BRACE)) {
        return cc0_compiler_parse_block_();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_RETURN)) {
        cc0_compiler_next_token();
        if (cc0_compiler_parse_expression()) {
            return CC0_TRUE;
        }
        if (cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON)) {
            return CC0_TRUE;
        }
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
            return cc0_compiler_emit_epilogue();
        }
        return CC0_FALSE;
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_IF)) {
        return cc0_compiler_parse_if();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_WHILE)) {
        return cc0_compiler_parse_while();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_FOR)) {
        return cc0_compiler_parse_for();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_DO)) {
        return cc0_compiler_parse_do();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_BREAK)) {
        return cc0_compiler_parse_break();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_CONTINUE)) {
        return cc0_compiler_parse_continue();
    }
    if (eq(CC0_TOKEN, CC0_TOKEN_VAR)) {
        return cc0_compiler_parse_local();
    }
    if (cc0_compiler_parse_expression()) {
        return CC0_TRUE;
    }
    return cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON);
}

function cc0_compiler_parse_parameters_()
{
    CC0_PARAMETER_COUNT = 0;
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_FALSE;
    }
    while (CC0_TRUE) {
        if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
            return cc0_compiler_fail();
        }
        if (not(lt(cc0_compiler_find_symbol(CC0_PARAMETER_SYMBOLS,
            CC0_PARAMETER_COUNT, CC0_TOKEN_START, CC0_TOKEN_LENGTH), 0))) {
            return cc0_compiler_fail();
        }
        if (cc0_compiler_ensure_parameter_symbols()) {
            return CC0_TRUE;
        }
        cc0_compiler_add_symbol(CC0_PARAMETER_SYMBOLS, CC0_PARAMETER_COUNT,
            CC0_TOKEN_START, CC0_TOKEN_LENGTH, CC0_PARAMETER_COUNT);
        CC0_PARAMETER_COUNT = add(CC0_PARAMETER_COUNT, 1);
        cc0_compiler_next_token();
        if (not(eq(CC0_TOKEN, CC0_PUNCTUATION_COMMA))) {
            return CC0_FALSE;
        }
        cc0_compiler_next_token();
    }
}

function cc0_compiler_parse_function_(local_count)
{
    CC0_LOCAL_COUNT = 0;
    cc0_compiler_next_token();
    if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
        return cc0_compiler_fail();
    }
    CC0_CURRENT_NAME_START = CC0_TOKEN_START;
    CC0_CURRENT_NAME_LENGTH = CC0_TOKEN_LENGTH;
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT)) {
        if (cc0_compiler_name_exists(CC0_CURRENT_NAME_START,
            CC0_CURRENT_NAME_LENGTH)) {
            return cc0_compiler_fail();
        }
    }
    cc0_compiler_next_token();
    if (cc0_compiler_expect(CC0_PUNCTUATION_LEFT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_parse_parameters_()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_PARENTHESIS)) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT)) {
        if (cc0_compiler_ensure_function_symbols()) {
            return CC0_TRUE;
        }
        if (cc0_compiler_add_symbol(CC0_FUNCTION_SYMBOLS, CC0_FUNCTION_COUNT,
            CC0_CURRENT_NAME_START, CC0_CURRENT_NAME_LENGTH,
            CC0_PARAMETER_COUNT)) {
            return CC0_TRUE;
        }
        CC0_FUNCTION_COUNT = add(CC0_FUNCTION_COUNT, 1);
    } else if (not(eq(cc0_compiler_function_arity(CC0_CURRENT_NAME_START,
        CC0_CURRENT_NAME_LENGTH), CC0_PARAMETER_COUNT))) {
        return cc0_compiler_fail();
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        local_count = cc0_compiler_function_local_count(
            CC0_CURRENT_NAME_START, CC0_CURRENT_NAME_LENGTH);
        cc0_compiler_set_function_code(CC0_CURRENT_NAME_START,
            CC0_CURRENT_NAME_LENGTH);
        cc0_compiler_emit_prologue(local_count);
    }
    if (cc0_compiler_parse_block_()) {
        return CC0_TRUE;
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT)) {
        cc0_compiler_set_function_local_count(CC0_CURRENT_NAME_START,
            CC0_CURRENT_NAME_LENGTH, CC0_LOCAL_COUNT);
    }
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_EMIT)) {
        cc0_compiler_emit_immediate(0);
        return cc0_compiler_emit_epilogue();
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_function()
{
    return cc0_compiler_parse_function_(0);
}

function cc0_compiler_parse_global_(global_index, entry, size)
{
    cc0_compiler_next_token();
    if (not(eq(CC0_TOKEN, CC0_TOKEN_IDENTIFIER))) {
        return cc0_compiler_fail();
    }
    global_index = cc0_compiler_find_symbol(CC0_GLOBAL_SYMBOLS,
        CC0_GLOBAL_COUNT, CC0_TOKEN_START, CC0_TOKEN_LENGTH);
    if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT)) {
        if (not(lt(global_index, 0))) {
            return cc0_compiler_fail();
        }
        if (cc0_compiler_name_exists(CC0_TOKEN_START, CC0_TOKEN_LENGTH)) {
            return cc0_compiler_fail();
        }
        if (cc0_compiler_ensure_global_symbols()) {
            return CC0_TRUE;
        }
        cc0_compiler_add_symbol(CC0_GLOBAL_SYMBOLS, CC0_GLOBAL_COUNT,
            CC0_TOKEN_START, CC0_TOKEN_LENGTH, CC0_WORD_BYTES);
        global_index = CC0_GLOBAL_COUNT;
        CC0_GLOBAL_COUNT = add(CC0_GLOBAL_COUNT, 1);
    } else if (lt(global_index, 0)) {
        return cc0_compiler_fail();
    }
    cc0_compiler_next_token();
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_LEFT_BRACKET)) {
        cc0_compiler_next_token();
        if (not(eq(CC0_TOKEN, CC0_TOKEN_NUMBER_LITERAL))) {
            return cc0_compiler_fail();
        }
        size = mul(CC0_TOKEN_NUMBER, CC0_WORD_BYTES);
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT)) {
            entry = cc0_compiler_symbol_entry(CC0_GLOBAL_SYMBOLS,
                global_index);
            wi32(add(entry, CC0_SYMBOL_VALUE_OFFSET), size);
        }
        cc0_compiler_next_token();
        if (cc0_compiler_expect(CC0_PUNCTUATION_RIGHT_BRACKET)) {
            return CC0_TRUE;
        }
    }
    if (eq(CC0_TOKEN, CC0_PUNCTUATION_ASSIGN)) {
        cc0_compiler_next_token();
        if (not(eq(CC0_TOKEN, CC0_TOKEN_NUMBER_LITERAL))) {
            return cc0_compiler_fail();
        }
        if (eq(CC0_COMPILER_PHASE, CC0_COMPILER_PHASE_COLLECT)) {
            entry = cc0_compiler_symbol_entry(CC0_GLOBAL_SYMBOLS,
                global_index);
            wi32(add(entry, CC0_SYMBOL_VALUE_OFFSET), CC0_TOKEN_NUMBER);
            /* A nonzero code field records that even a zero value is explicit. */
            wi32(add(entry, CC0_SYMBOL_CODE_OFFSET), 1);
        }
        cc0_compiler_next_token();
    }
    return cc0_compiler_expect(CC0_PUNCTUATION_SEMICOLON);
}

function cc0_compiler_parse_global()
{
    return cc0_compiler_parse_global_(0, 0, 0);
}

function cc0_compiler_parse_program_(source, length, phase)
{
    CC0_COMPILER_ERROR = CC0_FALSE;
    CC0_COMPILER_PHASE = phase;
    CC0_LOOP_DEPTH = 0;
    CC0_NEXT_LOOP_ID = 0;
    cc0_compiler_set_source(source, length);
    cc0_compiler_next_token();
    while (not(eq(CC0_TOKEN, CC0_TOKEN_EOF))) {
        if (eq(CC0_TOKEN, CC0_TOKEN_VAR)) {
            cc0_compiler_parse_global();
        } else if (eq(CC0_TOKEN, CC0_TOKEN_FUNCTION)) {
            cc0_compiler_parse_function();
        } else {
            return cc0_compiler_fail();
        }
        if (CC0_COMPILER_ERROR) {
            return CC0_TRUE;
        }
    }
    return CC0_FALSE;
}

function cc0_compiler_parse_program(source, length)
{
    cc0_compiler_prepare_symbols();
    if (cc0_compiler_parse_program_(source, length,
        CC0_COMPILER_PHASE_COLLECT)) {
        return CC0_TRUE;
    }
    return cc0_compiler_parse_program_(source, length,
        CC0_COMPILER_PHASE_RESOLVE);
}

function cc0_compiler_compile_program(source, length)
{
    if (cc0_compiler_parse_program(source, length)) {
        return CC0_TRUE;
    }
    if (cc0_compiler_prepare_code()) {
        return CC0_TRUE;
    }
    if (cc0_compiler_parse_program_(source, length,
        CC0_COMPILER_PHASE_EMIT)) {
        return CC0_TRUE;
    }
    return cc0_compiler_patch_calls();
}

/* libc-backed services are ordinary cc0 code, not bootstrap primitives. */
function alloc(size)
{
    if (lt(size, 0)) {
        return 0;
    }
    return malloc(size);
}

function file_open_read(path)
{
    return open(path, CC0_FILE_READ_ONLY, 0);
}

function file_open_write(path)
{
    return open(path, CC0_FILE_WRITE_FLAGS, CC0_FILE_CREATE_MODE);
}

function file_size_(descriptor, size)
{
    size = lseek(descriptor, 0, CC0_FILE_SEEK_END);
    if (not(lt(size, 0))) {
        lseek(descriptor, 0, CC0_FILE_SEEK_START);
    }
    return size;
}

function file_size(descriptor)
{
    return file_size_(descriptor, 0);
}

function file_read_byte(descriptor)
{
    if (not(eq(read(descriptor, CC0_FILE_BYTE, 1), 1))) {
        return sub(0, 1);
    }
    return ri8(CC0_FILE_BYTE);
}

function file_write_byte(descriptor, value)
{
    wi8(CC0_FILE_BYTE, value);
    return write(descriptor, CC0_FILE_BYTE, 1);
}

function file_close(descriptor)
{
    return close(descriptor);
}

function cc0_c_string_equal_(left, right, left_value, right_value)
{
    while (CC0_TRUE) {
        left_value = ri8(left);
        right_value = ri8(right);
        if (not(eq(left_value, right_value))) {
            return CC0_FALSE;
        }
        if (eq(left_value, 0)) {
            return CC0_TRUE;
        }
        left = add(left, 1);
        right = add(right, 1);
    }
}

function cc0_c_string_equal(left, right)
{
    return cc0_c_string_equal_(left, right, 0, 0);
}

function cc0_c_string_length_(value, length)
{
    length = 0;
    while (not(eq(ri8(add(value, length)), 0))) {
        length = add(length, 1);
    }
    return length;
}

function cc0_c_string_length(value)
{
    return cc0_c_string_length_(value, 0);
}

function cc0_write_text(descriptor, text)
{
    return write(descriptor, text, cc0_c_string_length(text));
}

function cc0_print_usage_(descriptor, argv, program)
{
    program = ri32(argv);
    cc0_write_text(descriptor, mks("Usage: "));
    cc0_write_text(descriptor, program);
    cc0_write_text(descriptor, mks(" -c input.c -o output.o"));
    file_write_byte(descriptor, CC0_ASCII_LINE_FEED);
    cc0_write_text(descriptor, mks("       "));
    cc0_write_text(descriptor, program);
    cc0_write_text(descriptor, mks(" input.o ... -o output"));
    file_write_byte(descriptor, CC0_ASCII_LINE_FEED);
    cc0_write_text(descriptor, mks("Options:"));
    file_write_byte(descriptor, CC0_ASCII_LINE_FEED);
    cc0_write_text(descriptor, mks("  -c          Compile one source file"));
    file_write_byte(descriptor, CC0_ASCII_LINE_FEED);
    cc0_write_text(descriptor, mks("  -o FILE     Set the output file"));
    file_write_byte(descriptor, CC0_ASCII_LINE_FEED);
    cc0_write_text(descriptor, mks("  -h, --help  Display this help"));
    file_write_byte(descriptor, CC0_ASCII_LINE_FEED);
    return CC0_FALSE;
}

function cc0_print_usage(descriptor, argv)
{
    return cc0_print_usage_(descriptor, argv, 0);
}

function cc0_report_error(argv, message, name)
{
    cc0_write_text(CC0_STANDARD_ERROR, ri32(argv));
    cc0_write_text(CC0_STANDARD_ERROR, mks(": "));
    cc0_write_text(CC0_STANDARD_ERROR, message);
    if (not(eq(name, 0))) {
        cc0_write_text(CC0_STANDARD_ERROR, name);
    }
    file_write_byte(CC0_STANDARD_ERROR, CC0_ASCII_LINE_FEED);
    return CC0_FALSE;
}

/* Decimal formatting stays in the dialect; each place subtracts at most nine times. */
function cc0_write_decimal_place_(descriptor, value, place, next_place,
    digit)
{
    next_place = add(shl(place, 3), shl(place, 1));
    if (le(next_place, CC0_DECIMAL_MAX_PLACE)) {
        if (le(next_place, value)) {
            value = cc0_write_decimal_place_(descriptor, value, next_place,
                0, 0);
        }
    }
    digit = 0;
    while (le(place, value)) {
        value = sub(value, place);
        digit = add(digit, 1);
    }
    file_write_byte(descriptor, add(CC0_ASCII_ZERO, digit));
    return value;
}

function cc0_write_decimal(descriptor, value)
{
    return cc0_write_decimal_place_(descriptor, value, 1, 0, 0);
}

function cc0_report_compile_error_(name, position, line, column, index,
    character)
{
    if (not(eq(CC0_COMPILER_ERROR_FILE, 0))) {
        name = CC0_COMPILER_ERROR_FILE;
        line = CC0_COMPILER_ERROR_LINE;
        column = CC0_COMPILER_ERROR_COLUMN;
    } else {
        line = 1;
        column = 1;
    }
    index = 0;
    if (lt(position, 0)) {
        position = 0;
    }
    if (eq(CC0_COMPILER_ERROR_FILE, 0)) {
        while (lt(index, position)) {
            character = ri8(add(CC0_SOURCE, index));
            if (eq(character, CC0_ASCII_LINE_FEED)) {
                line = add(line, 1);
                column = 1;
            } else {
                column = add(column, 1);
            }
            index = add(index, 1);
        }
    }
    cc0_write_text(CC0_STANDARD_ERROR, name);
    file_write_byte(CC0_STANDARD_ERROR, 58);
    cc0_write_decimal(CC0_STANDARD_ERROR, line);
    file_write_byte(CC0_STANDARD_ERROR, 58);
    cc0_write_decimal(CC0_STANDARD_ERROR, column);
    cc0_write_text(CC0_STANDARD_ERROR, mks(": error: compilation failed"));
    file_write_byte(CC0_STANDARD_ERROR, CC0_ASCII_LINE_FEED);
    return CC0_FALSE;
}

function cc0_report_compile_error(name)
{
    return cc0_report_compile_error_(name, CC0_COMPILER_ERROR_POSITION,
        0, 0, 0, 0);
}

function cc0_read_source_(name, size_pointer, descriptor, size, source,
    index, value)
{
    descriptor = file_open_read(name);
    if (lt(descriptor, 0)) {
        return 0;
    }
    size = file_size(descriptor);
    if (lt(size, 1)) {
        file_close(descriptor);
        return 0;
    }
    source = alloc(size);
    if (eq(source, 0)) {
        file_close(descriptor);
        return 0;
    }
    index = 0;
    while (lt(index, size)) {
        value = file_read_byte(descriptor);
        if (lt(value, 0)) {
            file_close(descriptor);
            return 0;
        }
        wi8(add(source, index), value);
        index = add(index, 1);
    }
    file_close(descriptor);
    wi32(size_pointer, size);
    return source;
}

function cc0_read_source(name, size_pointer)
{
    return cc0_read_source_(name, size_pointer, 0, 0, 0, 0, 0);
}

function cc0_write_object_(name, descriptor, index)
{
    descriptor = file_open_write(name);
    if (lt(descriptor, 0)) {
        return CC0_TRUE;
    }
    index = 0;
    while (lt(index, CC0_ELF_OUTPUT_LENGTH)) {
        if (not(eq(file_write_byte(descriptor,
            ri8(add(CC0_ELF_OUTPUT, index))), 1))) {
            file_close(descriptor);
            return CC0_TRUE;
        }
        index = add(index, 1);
    }
    file_close(descriptor);
    return CC0_FALSE;
}

function cc0_write_object(name)
{
    return cc0_write_object_(name, 0, 0);
}

/* Standalone policy and diagnostics are shared by every layered executable. */
function main_(argc, argv, input_name, output_name, source_size_pointer,
    source, source_size, first_argument, result)
{
    cc0_init();
    input_name = 0;
    output_name = 0;
    if (eq(argc, 2)) {
        first_argument = ri32(add(argv, CC0_WORD_BYTES));
        if (cc0_c_string_equal(first_argument, mks("-h"))) {
            cc0_print_usage(CC0_STANDARD_OUTPUT, argv);
            return CC0_FALSE;
        }
        if (cc0_c_string_equal(first_argument, mks("--help"))) {
            cc0_print_usage(CC0_STANDARD_OUTPUT, argv);
            return CC0_FALSE;
        }
    }
    if (eq(argc, 3)) {
        input_name = ri32(add(argv, CC0_WORD_BYTES));
        output_name = ri32(add(argv, shl(2, CC0_WORD_ADDRESS_SHIFT)));
    } else if (eq(argc, 5)) {
        if (cc0_c_string_equal(
            ri32(add(argv, CC0_WORD_BYTES)), mks("-c"))) {
            if (cc0_c_string_equal(ri32(add(argv,
                shl(3, CC0_WORD_ADDRESS_SHIFT))), mks("-o"))) {
                input_name = ri32(add(argv,
                    shl(2, CC0_WORD_ADDRESS_SHIFT)));
                output_name = ri32(add(argv,
                    shl(4, CC0_WORD_ADDRESS_SHIFT)));
            }
        }
    }
    if (eq(input_name, 0)) {
        if (not(lt(argc, 4))) {
            result = cc1_link(argc, argv);
            if (not(eq(result, 0))) {
                cc0_report_error(argv, mks("link failed"), 0);
                return CC0_MAIN_LINK_ERROR;
            }
            return CC0_FALSE;
        }
        cc0_print_usage(CC0_STANDARD_ERROR, argv);
        return CC0_MAIN_USAGE_ERROR;
    }
    source_size_pointer = alloc(CC0_WORD_BYTES);
    if (eq(source_size_pointer, 0)) {
        cc0_report_error(argv, mks("out of memory while reading "),
            input_name);
        return CC0_MAIN_INPUT_ERROR;
    }
    source = cc0_read_source(input_name, source_size_pointer);
    if (eq(source, 0)) {
        cc0_report_error(argv, mks("cannot read input "), input_name);
        return CC0_MAIN_INPUT_ERROR;
    }
    source_size = ri32(source_size_pointer);
    if (cc1_compile(source, source_size, input_name)) {
        cc0_report_compile_error(input_name);
        return CC0_MAIN_COMPILE_ERROR;
    }
    if (cc0_write_object(output_name)) {
        cc0_report_error(argv, mks("cannot write output "), output_name);
        return CC0_MAIN_OUTPUT_ERROR;
    }
    return CC0_FALSE;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0, 0, 0, 0, 0);
}
