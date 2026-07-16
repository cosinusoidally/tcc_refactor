/* Verify an exact non-overlapping byte copy and destination return value. */
function main_(argc, argv, source, destination, result)
{
    source = malloc(4);
    destination = malloc(6);
    if (or(eq(source, 0), eq(destination, 0))) {
        return 1;
    }
    wi8(source, mkC("a"));
    wi8(add(source, 1), mkC("b"));
    wi8(add(source, 2), mkC("c"));
    wi8(add(source, 3), mkC("d"));
    memset(destination, mkC("x"), 6);
    result = memcpy(add(destination, 1), source, 4);
    if (not(eq(result, add(destination, 1)))) {
        return 2;
    }
    if (not(eq(ri8(destination), mkC("x")))) {
        return 3;
    }
    if (not(eq(ri8(add(destination, 1)), mkC("a")))) {
        return 4;
    }
    if (not(eq(ri8(add(destination, 4)), mkC("d")))) {
        return 5;
    }
    if (not(eq(ri8(add(destination, 5)), mkC("x")))) {
        return 6;
    }
    if (not(eq(memcpy(destination, source, 0), destination))) {
        return 7;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0);
}
