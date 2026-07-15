/* The first static runtime does not yet expose the kernel argument vector. */
function _start()
{
    cc0_static_syscalls_init();
    cc0_runtime_exit(main(0, 0));
    return 0;
}
