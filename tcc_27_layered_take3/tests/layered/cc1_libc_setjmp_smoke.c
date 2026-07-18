/* Both public spellings currently enter the protected body directly. */
function main_(argc, argv, environment)
{
    cc1_libc_init();
    environment = malloc(24);
    if (eq(environment, 0)) {
        return 1;
    }
    if (not(eq(setjmp(environment), 0))) {
        return 2;
    }
    if (not(eq(_setjmp(environment), 0))) {
        return 3;
    }
    free(environment);
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0);
}
