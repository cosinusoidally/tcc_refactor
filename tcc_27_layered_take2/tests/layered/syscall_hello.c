var LINUX_I386_SYSCALL_EXIT;
var LINUX_I386_SYSCALL_WRITE;
var LINUX_STANDARD_OUTPUT;
var SYSCALL_HELLO_MESSAGE_BYTES;
var syscall_hello_message;

function syscall_hello_init()
{
    LINUX_I386_SYSCALL_EXIT = 1;
    LINUX_I386_SYSCALL_WRITE = 4;
    LINUX_STANDARD_OUTPUT = 1;
    SYSCALL_HELLO_MESSAGE_BYTES = 12;
    syscall_hello_message = mks("hello world\n");
}

function _start()
{
    syscall_hello_init();
    linux_i386_syscall5(LINUX_I386_SYSCALL_WRITE, LINUX_STANDARD_OUTPUT,
        syscall_hello_message, SYSCALL_HELLO_MESSAGE_BYTES, 0, 0);
    linux_i386_syscall5(LINUX_I386_SYSCALL_EXIT, 0, 0, 0, 0, 0);
}
