/* Raw Linux services used by the freestanding cc0 runtime. */
var CC0_STATIC_SYSCALL_EXIT;
var CC0_STATIC_SYSCALL_READ;
var CC0_STATIC_SYSCALL_WRITE;
var CC0_STATIC_SYSCALL_OPEN;
var CC0_STATIC_SYSCALL_CLOSE;
var CC0_STATIC_SYSCALL_LSEEK;
var CC0_STATIC_SYSCALL_BRK;
var CC0_STATIC_SYSCALL_UNLINK;

function cc0_static_syscalls_init()
{
    CC0_STATIC_SYSCALL_EXIT = 1;
    CC0_STATIC_SYSCALL_READ = 3;
    CC0_STATIC_SYSCALL_WRITE = 4;
    CC0_STATIC_SYSCALL_OPEN = 5;
    CC0_STATIC_SYSCALL_CLOSE = 6;
    CC0_STATIC_SYSCALL_LSEEK = 19;
    CC0_STATIC_SYSCALL_BRK = 45;
    CC0_STATIC_SYSCALL_UNLINK = 10;
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

function cc0_runtime_close(descriptor)
{
    return linux_i386_syscall5(CC0_STATIC_SYSCALL_CLOSE, descriptor, 0, 0,
        0, 0);
}

function cc0_runtime_lseek(descriptor, offset, whence)
{
    return linux_i386_syscall5(CC0_STATIC_SYSCALL_LSEEK, descriptor,
        offset, whence, 0, 0);
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

function cc0_runtime_unlink(path)
{
    return linux_i386_syscall5(CC0_STATIC_SYSCALL_UNLINK, path,
        0, 0, 0, 0);
}
