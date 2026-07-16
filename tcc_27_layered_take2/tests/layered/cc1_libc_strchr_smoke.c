/* Verify first-match, missing-character, and terminating-NUL behavior. */
function main_(argc, argv, text)
{
    cc1_libc_init();
    text = mks("abca");
    if (not(eq(strchr(text, mkC("a")), text))) {
        return 1;
    }
    if (not(eq(strchr(text, mkC("c")), add(text, 2)))) {
        return 2;
    }
    if (not(eq(strchr(text, mkC("z")), 0))) {
        return 3;
    }
    if (not(eq(strchr(text, 0), add(text, 4)))) {
        return 4;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0);
}
