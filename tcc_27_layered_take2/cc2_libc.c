/* Libc facilities which require typed C and therefore belong to cc2. */

static int cc2_strtod_space(unsigned char character)
{
    return character == ' ' || character == '\t' || character == '\n' ||
           character == '\r' || character == '\f' || character == '\v';
}

/* Decimal exponents beyond this point necessarily overflow or underflow an
 * i386 long double. Clamping also prevents signed integer wrap while scanning
 * an arbitrarily long exponent field. */
#define CC2_STRTOD_EXPONENT_SATURATION 10000

static long double cc2_strtold_finite(const char *text, char **end_pointer)
{
    const char *original;
    const char *cursor;
    const char *exponent_marker;
    long double value;
    long double factor;
    unsigned int exponent_magnitude;
    int negative;
    int converted;
    int decimal_exponent;
    int exponent_negative;
    int explicit_exponent;
    int digit;

    original = text;
    cursor = text;
    while (cc2_strtod_space((unsigned char)*cursor)) {
        ++cursor;
    }

    negative = 0;
    if (*cursor == '+' || *cursor == '-') {
        negative = *cursor == '-';
        ++cursor;
    }

    value = 0;
    converted = 0;
    decimal_exponent = 0;
    while (*cursor >= '0' && *cursor <= '9') {
        digit = *cursor - '0';
        value *= 10;
        value += digit;
        converted = 1;
        ++cursor;
    }
    if (*cursor == '.') {
        ++cursor;
        while (*cursor >= '0' && *cursor <= '9') {
            digit = *cursor - '0';
            value *= 10;
            value += digit;
            if (decimal_exponent > -CC2_STRTOD_EXPONENT_SATURATION) {
                --decimal_exponent;
            }
            converted = 1;
            ++cursor;
        }
    }

    if (!converted) {
        if (end_pointer != 0) {
            *end_pointer = (char *)original;
        }
        return value;
    }

    if (*cursor == 'e' || *cursor == 'E') {
        exponent_marker = cursor;
        ++cursor;
        exponent_negative = 0;
        if (*cursor == '+' || *cursor == '-') {
            exponent_negative = *cursor == '-';
            ++cursor;
        }
        if (*cursor < '0' || *cursor > '9') {
            cursor = exponent_marker;
        } else {
            explicit_exponent = 0;
            while (*cursor >= '0' && *cursor <= '9') {
                digit = *cursor - '0';
                if (explicit_exponent < CC2_STRTOD_EXPONENT_SATURATION) {
                    explicit_exponent = explicit_exponent * 10 + digit;
                    if (explicit_exponent >
                        CC2_STRTOD_EXPONENT_SATURATION) {
                        explicit_exponent =
                            CC2_STRTOD_EXPONENT_SATURATION;
                    }
                }
                ++cursor;
            }
            if (exponent_negative) {
                explicit_exponent = -explicit_exponent;
            }
            decimal_exponent += explicit_exponent;
            if (decimal_exponent > CC2_STRTOD_EXPONENT_SATURATION) {
                decimal_exponent = CC2_STRTOD_EXPONENT_SATURATION;
            }
            if (decimal_exponent < -CC2_STRTOD_EXPONENT_SATURATION) {
                decimal_exponent = -CC2_STRTOD_EXPONENT_SATURATION;
            }
        }
    }

    if (end_pointer != 0) {
        *end_pointer = (char *)cursor;
    }

    factor = 10;
    if (decimal_exponent < 0) {
        exponent_magnitude = 0 - (unsigned int)decimal_exponent;
        while (exponent_magnitude != 0) {
            if ((exponent_magnitude & 1) != 0) {
                value /= factor;
            }
            exponent_magnitude >>= 1;
            if (exponent_magnitude != 0) {
                factor *= factor;
            }
        }
    } else {
        exponent_magnitude = decimal_exponent;
        while (exponent_magnitude != 0) {
            if ((exponent_magnitude & 1) != 0) {
                value *= factor;
            }
            exponent_magnitude >>= 1;
            if (exponent_magnitude != 0) {
                factor *= factor;
            }
        }
    }
    if (negative) {
        value = 0 - value;
    }
    return value;
}

double strtod(const char *text, char **end_pointer)
{
    return (double)cc2_strtold_finite(text, end_pointer);
}

float strtof(const char *text, char **end_pointer)
{
    return (float)cc2_strtold_finite(text, end_pointer);
}

long double strtold(const char *text, char **end_pointer)
{
    return cc2_strtold_finite(text, end_pointer);
}
