/* Exercise the libc surface without depending on compiler implementation data. */
function libc_smoke_text_equal_(left, right, left_byte, right_byte)
{
    while (1) {
        left_byte = ri8(left);
        right_byte = ri8(right);
        if (not(eq(left_byte, right_byte))) {
            return 0;
        }
        if (eq(left_byte, 0)) {
            return 1;
        }
        left = add(left, 1);
        right = add(right, 1);
    }
}

function libc_smoke_text_equal(left, right)
{
    return libc_smoke_text_equal_(left, right, 0, 0);
}

function libc_smoke_allocation_mask()
{
    return 7;
}

function libc_smoke_word_bytes()
{
    return 4;
}

function libc_smoke_standard_output()
{
    return 1;
}

function libc_smoke_write_message()
{
    return mks("write smoke ok\n");
}

function libc_smoke_write_message_bytes()
{
    return 15;
}

function libc_smoke_source_path()
{
    return mks("tcc_27_layered_take2/tests/layered/libc_smoke.c");
}

function libc_smoke_read_only()
{
    return 0;
}

function main_(argc, argv, first, second, first_argument, second_argument,
    descriptor)
{
    if (not(eq(argc, 3))) {
        return 1;
    }
    if (eq(argv, 0)) {
        return 2;
    }
    if (eq(ri8(ri32(argv)), 0)) {
        return 3;
    }
    first_argument = ri32(add(argv, libc_smoke_word_bytes()));
    second_argument = ri32(add(argv,
        mul(2, libc_smoke_word_bytes())));
    if (not(libc_smoke_text_equal(first_argument, mks("first")))) {
        return 4;
    }
    if (not(libc_smoke_text_equal(second_argument, mks("second")))) {
        return 5;
    }
    if (not(eq(ri32(add(argv,
        mul(argc, libc_smoke_word_bytes()))), 0))) {
        return 6;
    }
    descriptor = open(libc_smoke_source_path(), libc_smoke_read_only(), 0);
    if (lt(descriptor, 0)) {
        return 7;
    }

    first = malloc(1);
    second = malloc(9);
    if (or(eq(first, 0), eq(second, 0))) {
        return 8;
    }
    if (or(not(eq(and(first, libc_smoke_allocation_mask()), 0)),
        not(eq(and(second, libc_smoke_allocation_mask()), 0)))) {
        return 9;
    }
    if (eq(first, second)) {
        return 10;
    }
    wi8(first, mkC("A"));
    wi8(second, mkC("B"));
    wi8(add(second, 8), mkC("C"));
    if (not(eq(ri8(first), mkC("A")))) {
        return 11;
    }
    if (not(eq(ri8(second), mkC("B")))) {
        return 12;
    }
    if (not(eq(ri8(add(second, 8)), mkC("C")))) {
        return 13;
    }
    if (not(eq(write(libc_smoke_standard_output(),
        libc_smoke_write_message(), libc_smoke_write_message_bytes()),
        libc_smoke_write_message_bytes()))) {
        return 14;
    }
    if (not(eq(puts(mks("libc smoke ok")), 0))) {
        return 15;
    }
    return 0;
}

function main(argc, argv)
{
    return main_(argc, argv, 0, 0, 0, 0, 0);
}
