/* Raw Linux services used by the freestanding cc0 runtime. */
var CC0_STATIC_SYSCALL_EXIT;
var CC0_STATIC_SYSCALL_READ;
var CC0_STATIC_SYSCALL_WRITE;
var CC0_STATIC_SYSCALL_OPEN;
var CC0_STATIC_SYSCALL_BRK;

function cc0_static_syscalls_init()
{
    CC0_STATIC_SYSCALL_EXIT = 1;
    CC0_STATIC_SYSCALL_READ = 3;
    CC0_STATIC_SYSCALL_WRITE = 4;
    CC0_STATIC_SYSCALL_OPEN = 5;
    CC0_STATIC_SYSCALL_BRK = 45;
}

function cc0_runtime_read(descriptor, buffer, count)
{
    return linux_i386_syscall5(CC0_STATIC_SYSCALL_READ, descriptor,
        buffer, count, 0, 0);
}

function cc0_runtime_write(descriptor, buffer, count)
{
    return linux_i386_syscall5(CC0_STATIC_SYSCALL_WRITE, descriptor,
        buffer, count, 0, 0);
}

function cc0_runtime_open(path, flags, mode)
{
    return linux_i386_syscall5(CC0_STATIC_SYSCALL_OPEN, path, flags, mode,
        0, 0);
}

function cc0_runtime_exit(status)
{
    linux_i386_syscall5(CC0_STATIC_SYSCALL_EXIT, status, 0, 0, 0, 0);
    return 0;
}

/* Return the resulting break, including the unchanged break on failure. */
function cc0_runtime_brk(address)
{
    return linux_i386_syscall5(CC0_STATIC_SYSCALL_BRK, address,
        0, 0, 0, 0);
}
