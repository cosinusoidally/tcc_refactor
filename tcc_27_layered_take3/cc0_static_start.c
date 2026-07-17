/* The linker entry adapter presents the kernel argument vector as C parameters. */
function _start(argc, argv)
{
    var status;

    cc0_static_syscalls_init();
    cc1_libc_init();
    cc0_libc_set_environment_from_arguments(argc, argv);
    status = main(argc, argv);
    cc1_libc_finish();
    cc0_runtime_exit(status);
    return 0;
}
