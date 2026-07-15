int linux_i386_syscall5(int number, int first, int second, int third,
    int fourth, int fifth);

#define LINUX_I386_SYSCALL_EXIT 1
#define LINUX_I386_SYSCALL_WRITE 4
#define LINUX_STANDARD_OUTPUT 1
#define SYSCALL_HELLO_MESSAGE_BYTES 12

char syscall_hello_message[] = "hello world\n";

void _start(void)
{
    linux_i386_syscall5(LINUX_I386_SYSCALL_WRITE, LINUX_STANDARD_OUTPUT,
        (int)syscall_hello_message, SYSCALL_HELLO_MESSAGE_BYTES, 0, 0);
    linux_i386_syscall5(LINUX_I386_SYSCALL_EXIT, 0, 0, 0, 0, 0);
}
