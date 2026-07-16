/* Verify equality, prefix ordering, differing bytes, and unsigned ordering. */
function main_(argc, argv, high, low)
{
    if (not(eq(strcmp(mks("same"), mks("same")), 0))) {
        return 1;
    }
    if (not(lt(strcmp(mks("a"), mks("aa")), 0))) {
        return 2;
    }
    if (not(lt(0, strcmp(mks("aa"), mks("a"))))) {
        return 3;
    }
    if (not(lt(strcmp(mks("abc"), mks("abd")), 0))) {
        return 4;
    }
    high = malloc(2);
    low = malloc(2);
    if (or(eq(high, 0), eq(low, 0))) {
        return 5;
    }
    wi8(high, sub(0, 1));
    wi8(add(high, 1), 0);
    wi8(low, 1);
    wi8(add(low, 1), 0);
    if (not(lt(0, strcmp(high, low)))) {
        return 6;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
