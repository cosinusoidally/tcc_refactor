/* The cc1 executable selects its own frontend through the cc2 service slot. */
function cc2_compile(source, length, file)
{
    return cc1_compile_base(source, length, file);
}
