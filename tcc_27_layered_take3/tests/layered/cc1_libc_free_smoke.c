/* Verify that free makes a suitable allocation available for reuse. */
function main_(argc, argv, first, guard, reused, grown)
{
    free(0);
    first = malloc(16);
    guard = malloc(16);
    if (or(eq(first, 0), eq(guard, 0))) {
        return 1;
    }
    wi8(guard, mkC("g"));
    free(first);
    reused = malloc(8);
    if (not(eq(reused, first))) {
        return 2;
    }
    if (not(eq(ri8(guard), mkC("g")))) {
        return 3;
    }
    wi8(reused, mkC("r"));
    grown = realloc(reused, 32);
    if (eq(grown, 0)) {
        return 4;
    }
    if (not(eq(ri8(grown), mkC("r")))) {
        return 5;
    }
    if (not(eq(malloc(8), reused))) {
        return 6;
    }
    if (not(eq(realloc(guard, 0), 0))) {
        return 7;
    }
    if (not(eq(malloc(8), guard))) {
        return 8;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0, 0);
}
