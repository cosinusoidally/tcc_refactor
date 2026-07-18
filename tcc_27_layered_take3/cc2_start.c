/* Ordinary i386 process entry for cc2 and later full-compiler executables. */
void _start(void)
{
    exit(main(cc2_process_argc(), cc2_process_argv()));
}
