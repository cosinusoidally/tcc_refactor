function cc1_link(argc, argv)
{
    return cc0_link(argc, argv);
}

/* cc0.exe selects the base frontend until cc1.c replaces this object. */
function cc1_compile(source, length, file)
{
    return cc0_compile(source, length);
}

/* Lower stages retain cc0's small command surface until cc2 is linked. */
function cc2_driver(argc, argv)
{
    return main_(argc, argv, 0, 0, 0, 0, 0, 0, 0);
}
