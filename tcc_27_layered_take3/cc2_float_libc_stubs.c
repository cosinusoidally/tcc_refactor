/* Fail-fast float conversions shared by the transitional cc2 executables. */

function strtod(text, end)
{
    return cc1_libc_unimplemented(mks("strtod"));
}

function strtof(text, end)
{
    return cc1_libc_unimplemented(mks("strtof"));
}

function strtold(text, end)
{
    return cc1_libc_unimplemented(mks("strtold"));
}
