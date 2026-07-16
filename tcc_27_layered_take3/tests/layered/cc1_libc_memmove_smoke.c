/* Exercise both overlap directions and the required destination return. */
function main_(argc, argv, buffer, result)
{
    buffer = malloc(7);
    if (eq(buffer, 0)) {
        return 1;
    }
    strcpy(buffer, mks("abcdef"));
    result = memmove(add(buffer, 2), buffer, 4);
    if (not(eq(result, add(buffer, 2)))) {
        return 2;
    }
    if (not(eq(ri8(add(buffer, 2)), mkC("a")))) {
        return 3;
    }
    if (not(eq(ri8(add(buffer, 3)), mkC("b")))) {
        return 4;
    }
    if (not(eq(ri8(add(buffer, 4)), mkC("c")))) {
        return 5;
    }
    if (not(eq(ri8(add(buffer, 5)), mkC("d")))) {
        return 6;
    }

    strcpy(buffer, mks("abcdef"));
    result = memmove(buffer, add(buffer, 2), 4);
    if (not(eq(result, buffer))) {
        return 7;
    }
    if (not(eq(ri8(buffer), mkC("c")))) {
        return 8;
    }
    if (not(eq(ri8(add(buffer, 1)), mkC("d")))) {
        return 9;
    }
    if (not(eq(ri8(add(buffer, 2)), mkC("e")))) {
        return 10;
    }
    if (not(eq(ri8(add(buffer, 3)), mkC("f")))) {
        return 11;
    }
    if (not(eq(memmove(buffer, buffer, 0), buffer))) {
        return 12;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
