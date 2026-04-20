/*
 * cc2 scaffold for archive-tool argument classification.
 *
 * This remains in the JavaScript/C intersection. The full archive writer still
 * lives in the legacy TCC tool path, but the first option-character checks are
 * now in the staged layers so the active -ar path can start moving out of
 * tcctools.c.
 */

var cc2_version;

cc2_version = 1;

function cc2_ar_is_conflict_option(c)
{
    if (c == 104)
        return 1;
    if (c == 97)
        return 1;
    if (c == 98)
        return 1;
    if (c == 100)
        return 1;
    if (c == 105)
        return 1;
    if (c == 111)
        return 1;
    if (c == 112)
        return 1;
    if (c == 116)
        return 1;
    if (c == 120)
        return 1;
    if (c == 78)
        return 1;
    return 0;
}

function cc2_ar_is_verbose_option(c)
{
    if (c == 118)
        return 1;
    return 0;
}

function cc2_ar_be32(value)
{
    return ((value & 16711680) >> 8) +
        ((value & -16777216) >> 24) +
        ((value & 255) << 24) +
        ((value & 65280) << 8);
}

function cc2_ar_is_exported_symbol(info)
{
    if (info == 16)
        return 1;
    if (info == 17)
        return 1;
    if (info == 18)
        return 1;
    return 0;
}
