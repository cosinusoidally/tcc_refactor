/* Read argc from the process-entry frame made by the ordinary C prologue. */
int cc2_process_argc(void)
{
    asm(
        ".byte 0x8b, 0x45, 0x00\n\t" /* movl 0(%ebp), %eax */
        ".byte 0x8b, 0x40, 0x04\n\t" /* movl 4(%eax), %eax */
        ".byte 0xc9\n\t"             /* leave */
        ".byte 0xc3"                  /* ret */
    );
}

/* Return the address immediately after argc in that same kernel stack. */
int cc2_process_argv(void)
{
    asm(
        ".byte 0x8b, 0x45, 0x00\n\t" /* movl 0(%ebp), %eax */
        ".byte 0x83, 0xc0, 0x08\n\t" /* addl $8, %eax */
        ".byte 0xc9\n\t"             /* leave */
        ".byte 0xc3"                  /* ret */
    );
}
