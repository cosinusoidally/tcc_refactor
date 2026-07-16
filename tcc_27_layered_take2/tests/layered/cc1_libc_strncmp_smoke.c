/* Verify bounded comparison, unsigned bytes, and early NUL termination. */
function main(argc, argv)
{
    cc1_libc_init();
    if (not(eq(strncmp(mks("abc"), mks("abd"), 2), 0))) {
        return 1;
    }
    if (not(lt(strncmp(mks("abc"), mks("abd"), 3), 0))) {
        return 2;
    }
    if (not(lt(0, strncmp(mks("abd"), mks("abc"), 3)))) {
        return 3;
    }
    if (not(eq(strncmp(mks("a"), mks("a"), 20), 0))) {
        return 4;
    }
    if (not(eq(strncmp(mks("a"), mks("b"), 0), 0))) {
        return 5;
    }
    return 0;
}
