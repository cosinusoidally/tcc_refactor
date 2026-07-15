/* Raw five-argument i386 Linux syscall with an EBP-based stack frame. */
function linux_i386_syscall5(number, first, second, third, fourth, fifth)
{
    /*
     * Original mnemonic form, retained as the readable instruction reference:
     *
     * asm (
     *     "pushl %ebx\n\t"
     *     "pushl %esi\n\t"
     *     "pushl %edi\n\t"
     *     "movl 8(%ebp), %eax\n\t"
     *     "movl 12(%ebp), %ebx\n\t"
     *     "movl 16(%ebp), %ecx\n\t"
     *     "movl 20(%ebp), %edx\n\t"
     *     "movl 24(%ebp), %esi\n\t"
     *     "movl 28(%ebp), %edi\n\t"
     *     "int $0x80\n\t"
     *     "popl %edi\n\t"
     *     "popl %esi\n\t"
     *     "popl %ebx\n\t"
     *     "leave\n\t"
     *     "ret"
     * );
     */
    asm (
        ".byte 0x53, 0x56, 0x57\n\t"             /* push ebx, esi, edi */
        ".byte 0x8b, 0x45, 0x08\n\t"             /* mov 8(ebp), eax */
        ".byte 0x8b, 0x5d, 0x0c\n\t"             /* mov 12(ebp), ebx */
        ".byte 0x8b, 0x4d, 0x10\n\t"             /* mov 16(ebp), ecx */
        ".byte 0x8b, 0x55, 0x14\n\t"             /* mov 20(ebp), edx */
        ".byte 0x8b, 0x75, 0x18\n\t"             /* mov 24(ebp), esi */
        ".byte 0x8b, 0x7d, 0x1c\n\t"             /* mov 28(ebp), edi */
        ".byte 0xcd, 0x80\n\t"                   /* int 0x80 */
        ".byte 0x5f, 0x5e, 0x5b, 0xc9, 0xc3"    /* restore and return */
    );
}
