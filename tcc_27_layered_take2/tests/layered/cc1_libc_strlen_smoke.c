/* Verify byte-string length and termination behavior. */
function main_(argc, argv, buffer)
{
    if (not(eq(strlen(mks("")), 0))) {
        return 1;
    }
    if (not(eq(strlen(mks("hello")), 5))) {
        return 2;
    }
    buffer = malloc(4);
    if (eq(buffer, 0)) {
        return 3;
    }
    wi8(buffer, mkC("a"));
    wi8(add(buffer, 1), mkC("b"));
    wi8(add(buffer, 2), 0);
    wi8(add(buffer, 3), mkC("c"));
    if (not(eq(strlen(buffer), 2))) {
        return 4;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0);
}
