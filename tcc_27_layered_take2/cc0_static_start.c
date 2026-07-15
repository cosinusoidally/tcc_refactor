/* cc0's entry adapter presents the kernel argument vector as C parameters. */
function _start(argc, argv)
{
    cc0_static_syscalls_init();
    cc0_runtime_exit(main(argc, argv));
    return 0;
}
