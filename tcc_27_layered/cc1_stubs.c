/*
 * cc1 stubs for the staged bootstrap scaffold.
 *
 * Like cc0.c, this file stays in the JavaScript/C intersection. The functions
 * are placeholders for the first layer above cc0; they fail closed until cc1
 * functionality is ported into this file.
 */

var cc1_stub_version;

cc1_stub_version = 1;

function cc1_compile_unit(source_id)
{
    return 1;
}

function cc1_has_real_parser()
{
    return 0;
}
