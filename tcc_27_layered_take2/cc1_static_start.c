/* Static layer-one startup initializes both libc layers before main. */
function _start(argc, argv)
{
    var status;

    cc0_static_syscalls_init();
    cc0_libc_init();
    cc0_libc_set_environment_from_arguments(argc, argv);
    cc1_libc_init();
    status = main(argc, argv);
    cc1_libc_finish();
    cc0_libc_finish();
    cc0_runtime_exit(status);
    return 0;
}
