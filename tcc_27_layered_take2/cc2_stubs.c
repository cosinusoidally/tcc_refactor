/* The cc1 executable selects its own frontend through the cc2 service slot. */
function cc2_compile(source, length, file)
{
    return cc1_compile_base(source, length, file);
}

/* cc1.exe uses the lower driver while it is compiling the real cc2 object. */
function cc2_driver(argc, argv)
{
    return main_(argc, argv, 0, 0, 0, 0, 0, 0, 0);
}
