/* Verify append placement, termination, empty input, and return value. */
function main_(argc, argv, destination, result)
{
    destination = malloc(16);
    if (eq(destination, 0)) {
        return 1;
    }
    strcpy(destination, mks("left"));
    result = strcat(destination, mks("right"));
    if (not(eq(result, destination))) {
        return 2;
    }
    if (not(eq(strcmp(destination, mks("leftright")), 0))) {
        return 3;
    }
    if (not(eq(strcat(destination, mks("")), destination))) {
        return 4;
    }
    if (not(eq(strcmp(destination, mks("leftright")), 0))) {
        return 5;
    }
    strcpy(destination, mks(""));
    strcat(destination, mks("x"));
    if (not(eq(strcmp(destination, mks("x")), 0))) {
        return 6;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0);
}
