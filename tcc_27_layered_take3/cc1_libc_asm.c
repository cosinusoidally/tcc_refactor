/* Native i386 stack-address primitives used by the shared C/JS libc. */

/* Return the first unnamed i386 stack argument after one named argument. */
function cc1_libc_varargs_after_one(value)
{
    asm(
        ".byte 0x8b, 0x45, 0x00\n\t" /* movl 0(%ebp), %eax */
        ".byte 0x83, 0xc0, 0x0c\n\t" /* addl $12, %eax */
        ".byte 0xc9\n\t"             /* leave */
        ".byte 0xc3"                  /* ret */
    );
}

/* Return the first unnamed i386 stack argument after two named arguments. */
function cc1_libc_varargs_after_two(first, second)
{
    asm(
        ".byte 0x8b, 0x45, 0x00\n\t" /* movl 0(%ebp), %eax */
        ".byte 0x83, 0xc0, 0x10\n\t" /* addl $16, %eax */
        ".byte 0xc9\n\t"             /* leave */
        ".byte 0xc3"                  /* ret */
    );
}

/* Return the first unnamed i386 stack argument after three named arguments. */
function cc1_libc_varargs_after_three(first, second, third)
{
    asm(
        ".byte 0x8b, 0x45, 0x00\n\t" /* movl 0(%ebp), %eax */
        ".byte 0x83, 0xc0, 0x14\n\t" /* addl $20, %eax */
        ".byte 0xc9\n\t"             /* leave */
        ".byte 0xc3"                  /* ret */
    );
}
