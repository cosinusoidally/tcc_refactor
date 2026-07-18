/* Verify formatted standard output and the number of bytes reported. */
function main(argc, argv)
{
    cc1_libc_init();
    if (not(eq(printf(mks("printf:%02x:%d\n"), 10, sub(0, 3)), 13))) {
        return 1;
    }
    return 0;
}
