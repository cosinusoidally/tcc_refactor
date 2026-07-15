/* Raw five-argument i386 Linux syscall with an EBP-based stack frame. */
function linux_i386_syscall5(number, first, second, third, fourth, fifth)
{
    asm (
        "pushl %ebx\n\t"
        "pushl %esi\n\t"
        "pushl %edi\n\t"
        "movl 8(%ebp), %eax\n\t"
        "movl 12(%ebp), %ebx\n\t"
        "movl 16(%ebp), %ecx\n\t"
        "movl 20(%ebp), %edx\n\t"
        "movl 24(%ebp), %esi\n\t"
        "movl 28(%ebp), %edi\n\t"
        "int $0x80\n\t"
        "popl %edi\n\t"
        "popl %esi\n\t"
        "popl %ebx\n\t"
        "leave\n\t"
        "ret"
    );
}
