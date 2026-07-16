/* Verify strcpy return value, contents, and terminating null byte. */
function main_(argc, argv, destination, result)
{
    destination = malloc(8);
    if (eq(destination, 0)) {
        return 1;
    }
    memset(destination, mkC("x"), 8);
    result = strcpy(destination, mks("copy"));
    if (not(eq(result, destination))) {
        return 2;
    }
    if (not(eq(ri8(destination), mkC("c")))) {
        return 3;
    }
    if (not(eq(ri8(add(destination, 3)), mkC("y")))) {
        return 4;
    }
    if (not(eq(ri8(add(destination, 4)), 0))) {
        return 5;
    }
    if (not(eq(ri8(add(destination, 5)), mkC("x")))) {
        return 6;
    }
    result = strcpy(destination, mks(""));
    if (not(eq(result, destination))) {
        return 7;
    }
    if (not(eq(ri8(destination), 0))) {
        return 8;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
