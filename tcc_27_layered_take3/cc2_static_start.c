/* Full-compiler static entry; libc initialization precedes every libc call. */
void _start(void)
{
    int argc;
    int argv;
    int status;

    argc = cc2_process_argc();
    argv = cc2_process_argv();
    cc0_static_syscalls_init();
    cc1_libc_init();
    cc0_libc_set_environment_from_arguments(argc, argv);
    status = main(argc, argv);
    cc1_libc_finish();
    cc0_runtime_exit(status);
}
