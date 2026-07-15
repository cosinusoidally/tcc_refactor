/* Exercise memset semantics without depending on compiler-owned data. */
function main_(argc, argv, buffer, result)
{
    buffer = malloc(6);
    if (eq(buffer, 0)) {
        return 1;
    }

    wi8(buffer, mkC("L"));
    wi8(add(buffer, 5), mkC("R"));
    result = memset(add(buffer, 1), mkC("x"), 4);
    if (not(eq(result, add(buffer, 1)))) {
        return 2;
    }
    if (not(eq(ri8(buffer), mkC("L")))) {
        return 3;
    }
    if (not(eq(ri8(add(buffer, 1)), mkC("x")))) {
        return 4;
    }
    if (not(eq(ri8(add(buffer, 2)), mkC("x")))) {
        return 5;
    }
    if (not(eq(ri8(add(buffer, 3)), mkC("x")))) {
        return 6;
    }
    if (not(eq(ri8(add(buffer, 4)), mkC("x")))) {
        return 7;
    }
    if (not(eq(ri8(add(buffer, 5)), mkC("R")))) {
        return 8;
    }

    result = memset(add(buffer, 5), mkC("z"), 0);
    if (not(eq(result, add(buffer, 5)))) {
        return 9;
    }
    if (not(eq(ri8(add(buffer, 5)), mkC("R")))) {
        return 10;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
