/*
 * Link-time import metadata for the dynamic cc2 executable.
 *
 * These bodies are never linked into cc2 or used as a libc implementation.
 * The generated shared object supplies only symbol names and the libc.so.6
 * SONAME, allowing the ELF linker to run without a host i386 glibc file.
 */
int stdout;
int stderr;

void _setjmp(void) {}
void __udivdi3(void) {}
void atoi(void) {}
void calloc(void) {}
void close(void) {}
void exit(void) {}
void fclose(void) {}
void fflush(void) {}
void fopen(void) {}
void fprintf(void) {}
void fputc(void) {}
void fputs(void) {}
void fread(void) {}
void free(void) {}
void fseek(void) {}
void ftell(void) {}
void fwrite(void) {}
void getcwd(void) {}
void getenv(void) {}
void gettimeofday(void) {}
void localtime(void) {}
void longjmp(void) {}
void lseek(void) {}
void malloc(void) {}
void memcmp(void) {}
void memcpy(void) {}
void memmove(void) {}
void memset(void) {}
void open(void) {}
void printf(void) {}
void puts(void) {}
void read(void) {}
void realloc(void) {}
void remove(void) {}
void snprintf(void) {}
void sprintf(void) {}
void strcat(void) {}
void strchr(void) {}
void strcmp(void) {}
void strcpy(void) {}
void strlen(void) {}
void strncmp(void) {}
void strpbrk(void) {}
void strstr(void) {}
void strtod(void) {}
void strtof(void) {}
void strtol(void) {}
void strtold(void) {}
void strtoul(void) {}
void time(void) {}
void unlink(void) {}
void vsnprintf(void) {}
