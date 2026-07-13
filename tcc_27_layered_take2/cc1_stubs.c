/*
 * Layer-one bootstrap linker. This intentionally selects the repository's TCC
 * linker; it never falls back to the GNU linker. cc1.c replaces this stub.
 */
function cc1_c_string_length_(value, length)
{
    length = 0;
    while (not(eq(ri8(add(value, length)), 0))) {
        length = add(length, 1);
    }
    return length;
}

function cc1_c_string_length(value)
{
    return cc1_c_string_length_(value, 0);
}

function cc1_shell_argument_size_(value, index, size, character)
{
    index = 0;
    size = 3;
    while (not(eq(ri8(add(value, index)), 0))) {
        character = ri8(add(value, index));
        size = add(size, 1);
        if (eq(character, 39)) {
            size = add(size, 3);
        }
        index = add(index, 1);
    }
    return size;
}

function cc1_shell_argument_size(value)
{
    return cc1_shell_argument_size_(value, 0, 0, 0);
}

/* Single quotes preserve every byte; embedded quotes use the shell '\'' form. */
function cc1_append_shell_argument_(output, position, value, index, character)
{
    wi8(add(output, position), 39);
    position = add(position, 1);
    index = 0;
    while (not(eq(ri8(add(value, index)), 0))) {
        character = ri8(add(value, index));
        if (eq(character, 39)) {
            wi8(add(output, position), 39);
            wi8(add(output, add(position, 1)), 92);
            wi8(add(output, add(position, 2)), 39);
            wi8(add(output, add(position, 3)), 39);
            position = add(position, 4);
        } else {
            wi8(add(output, position), character);
            position = add(position, 1);
        }
        index = add(index, 1);
    }
    wi8(add(output, position), 39);
    return add(position, 1);
}

function cc1_append_shell_argument(output, position, value)
{
    return cc1_append_shell_argument_(output, position, value, 0, 0);
}

function cc1_copy_string_(output, position, value, index)
{
    index = 0;
    while (not(eq(ri8(add(value, index)), 0))) {
        wi8(add(output, position), ri8(add(value, index)));
        position = add(position, 1);
        index = add(index, 1);
    }
    return position;
}

function cc1_copy_string(output, position, value)
{
    return cc1_copy_string_(output, position, value, 0);
}

function cc1_find_output_(argc, argv, index, argument)
{
    index = 1;
    while (lt(add(index, 1), argc)) {
        argument = ri32(add(argv, shl(index, 2)));
        if (eq(ri8(argument), 45)) {
            if (eq(ri8(add(argument, 1)), 111)) {
                if (eq(ri8(add(argument, 2)), 0)) {
                    return ri32(add(argv, shl(add(index, 1), 2)));
                }
            }
        }
        index = add(index, 1);
    }
    return 0;
}

function cc1_find_output(argc, argv)
{
    return cc1_find_output_(argc, argv, 0, 0);
}

function cc1_link_(argc, argv, linker, runtime, capacity, index, argument,
    command, position, status, output)
{
    linker = mks("./tcc_27_layered_take2 -nostdlib crt1.o crti.o crtbegin.o");
    runtime = mks(" libc.so libgcc.a crtend.o crtn.o");
    capacity = add(cc1_c_string_length(linker),
        add(cc1_c_string_length(runtime), 1));
    index = 1;
    while (lt(index, argc)) {
        argument = ri32(add(argv, shl(index, 2)));
        capacity = add(capacity, cc1_shell_argument_size(argument));
        index = add(index, 1);
    }
    command = malloc(capacity);
    if (eq(command, 0)) {
        return 1;
    }
    position = cc1_copy_string(command, 0, linker);
    index = 1;
    while (lt(index, argc)) {
        wi8(add(command, position), 32);
        position = add(position, 1);
        argument = ri32(add(argv, shl(index, 2)));
        position = cc1_append_shell_argument(command, position, argument);
        index = add(index, 1);
    }
    position = cc1_copy_string(command, position, runtime);
    wi8(add(command, position), 0);
    status = system(command);
    if (not(eq(status, 0))) {
        return 1;
    }
    output = cc1_find_output(argc, argv);
    if (eq(output, 0)) {
        return 1;
    }
    status = chmod(output, 493);
    if (not(eq(status, 0))) {
        return 1;
    }
    return 0;
}

function cc1_link(argc, argv)
{
    return cc1_link_(argc, argv, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}
