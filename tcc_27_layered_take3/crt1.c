/*
 * Minimal i386 Linux process startup for the layered bootstrap.  cc0 emits a
 * small ABI adapter for the specially named _start function, making argc and
 * argv ordinary parameters.  glibc remains responsible for process teardown.
 */
function _start(argc, argv)
{
    exit(main(argc, argv));
    return 0;
}
