/* Temporary services needed only while cc1 constructs cc2_boot. */

function qsort(base, count, size, compare)
{
    return cc1_libc_unimplemented(mks("qsort"));
}

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
