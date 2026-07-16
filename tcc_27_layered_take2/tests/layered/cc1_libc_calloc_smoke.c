/* Exercise allocation, zero fill, and multiplication overflow handling. */
function main_(argc, argv, buffer, index)
{
    buffer = calloc(3, 4);
    if (eq(buffer, 0)) {
        return 1;
    }
    index = 0;
    while (lt(index, 12)) {
        if (not(eq(ri8(add(buffer, index)), 0))) {
            return 2;
        }
        index = add(index, 1);
    }
    wi8(add(buffer, 11), mkC("w"));
    if (not(eq(ri8(add(buffer, 11)), mkC("w")))) {
        return 3;
    }
    if (not(eq(calloc(0, 4), 0))) {
        return 4;
    }
    if (not(eq(calloc(1073741824, 4), 0))) {
        return 5;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
