/* Verify unsigned byte ordering and size-limited equality. */
function main_(argc, argv, left, right)
{
    left = malloc(3);
    right = malloc(3);
    if (or(eq(left, 0), eq(right, 0))) {
        return 1;
    }
    wi8(left, mkC("a"));
    wi8(add(left, 1), mkC("b"));
    wi8(add(left, 2), mkC("c"));
    memcpy(right, left, 3);
    if (not(eq(memcmp(left, right, 3), 0))) {
        return 2;
    }
    wi8(add(right, 2), mkC("d"));
    if (not(lt(memcmp(left, right, 3), 0))) {
        return 3;
    }
    if (not(lt(0, memcmp(right, left, 3)))) {
        return 4;
    }
    if (not(eq(memcmp(left, right, 2), 0))) {
        return 5;
    }
    wi8(left, sub(0, 1));
    wi8(right, 1);
    if (not(lt(0, memcmp(left, right, 1)))) {
        return 6;
    }
    if (not(eq(memcmp(left, right, 0), 0))) {
        return 7;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
