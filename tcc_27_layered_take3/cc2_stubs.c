/* The cc1 executable selects the base frontend through the cc2 service slot. */
function cc2_compile(source, length, file)
{
    return cc0_compile(source, length);
}

/* cc1.exe uses the lower driver while it is compiling the real cc2 object. */
function cc2_driver(argc, argv)
{
    return main_(argc, argv, 0, 0, 0, 0, 0, 0, 0);
}
