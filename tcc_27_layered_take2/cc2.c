/* Layer two is the permanent typed frontend selected by cc1's dispatch point.
 * It initially preserves cc1 behavior while typed parsing migrates below. */
function cc2_compile(source, length, file)
{
    return cc1_compile_base(source, length, file);
}
