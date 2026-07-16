/* Runtime operations emitted by the typed i386 backend but absent from cc0. */
#define CC2_WORD_BITS 32
#define CC2_LONG_BITS 64
#define CC2_LONG_HIGH_BIT 63
#define CC2_X87_EXPONENT_BIAS 16383
#define CC2_X87_EXPONENT_MASK 32767
#define CC2_X87_SIGN_BIT 32768
#define CC2_UNSIGNED_WORD_MAX 0xffffffffU

typedef union CC2LongWords {
    unsigned long long value;
    struct {
        unsigned int low;
        unsigned int high;
    } words;
} CC2LongWords;

typedef union CC2ExtendedWords {
    long double value;
    struct {
        unsigned int low;
        unsigned int high;
        unsigned short exponent;
    } words;
} CC2ExtendedWords;

static CC2LongWords cc2_shift_left_words(CC2LongWords input, int count)
{
    CC2LongWords output;
    if (count >= CC2_WORD_BITS) {
        output.words.high = input.words.low << (count - CC2_WORD_BITS);
        output.words.low = 0;
    } else if (count > 0) {
        output.words.high = (input.words.high << count) |
            (input.words.low >> (CC2_WORD_BITS - count));
        output.words.low = input.words.low << count;
    } else {
        output = input;
    }
    return output;
}

static CC2LongWords cc2_shift_right_words(CC2LongWords input, int count)
{
    CC2LongWords output;
    if (count >= CC2_LONG_BITS) {
        output.words.high = 0;
        output.words.low = 0;
    } else if (count >= CC2_WORD_BITS) {
        output.words.low = input.words.high >> (count - CC2_WORD_BITS);
        output.words.high = 0;
    } else if (count > 0) {
        output.words.low = (input.words.low >> count) |
            (input.words.high << (CC2_WORD_BITS - count));
        output.words.high = input.words.high >> count;
    } else {
        output = input;
    }
    return output;
}

/* Shift by words so compiling this helper cannot recursively request itself. */
long long __ashldi3(long long value, int count)
{
    CC2LongWords input;
    CC2LongWords output;
    input.value = value;
    output = cc2_shift_left_words(input, count);
    return output.value;
}

/* Straight binary division is small and sufficient for compiler execution. */
unsigned long long __udivdi3(unsigned long long dividend_value,
    unsigned long long divisor_value)
{
    CC2LongWords dividend;
    CC2LongWords divisor;
    CC2LongWords quotient;
    CC2LongWords remainder;
    unsigned int incoming;
    int bit;
    dividend.value = dividend_value;
    divisor.value = divisor_value;
    quotient.words.low = 0;
    quotient.words.high = 0;
    remainder.words.low = 0;
    remainder.words.high = 0;
    for (bit = CC2_LONG_HIGH_BIT; bit >= 0; --bit) {
        incoming = bit >= CC2_WORD_BITS ?
            ((dividend.words.high >> (bit - CC2_WORD_BITS)) & 1) :
            ((dividend.words.low >> bit) & 1);
        remainder.words.high = (remainder.words.high << 1) |
            (remainder.words.low >> (CC2_WORD_BITS - 1));
        remainder.words.low = (remainder.words.low << 1) | incoming;
        if (remainder.words.high > divisor.words.high ||
            (remainder.words.high == divisor.words.high &&
            remainder.words.low >= divisor.words.low)) {
            unsigned int old_low = remainder.words.low;
            remainder.words.low -= divisor.words.low;
            remainder.words.high -= divisor.words.high +
                (old_low < divisor.words.low);
            if (bit >= CC2_WORD_BITS) {
                quotient.words.high |= 1U << (bit - CC2_WORD_BITS);
            } else {
                quotient.words.low |= 1U << bit;
            }
        }
    }
    return quotient.value;
}

/* Construct the x87 value directly; no compiler-provided 64-bit cast exists. */
long double __floatundixf(unsigned long long value)
{
    CC2LongWords input;
    CC2LongWords significand;
    CC2ExtendedWords output;
    int leading;
    input.value = value;
    if (input.words.high == 0 && input.words.low == 0) {
        output.words.low = 0;
        output.words.high = 0;
        output.words.exponent = 0;
        return output.value;
    }
    leading = input.words.high != 0 ? CC2_LONG_HIGH_BIT :
        (CC2_WORD_BITS - 1);
    while (leading >= CC2_WORD_BITS &&
        ((input.words.high >> (leading - CC2_WORD_BITS)) & 1) == 0) {
        --leading;
    }
    while (leading < CC2_WORD_BITS &&
        ((input.words.low >> leading) & 1) == 0) {
        --leading;
    }
    significand = cc2_shift_left_words(input, CC2_LONG_HIGH_BIT - leading);
    output.words.low = significand.words.low;
    output.words.high = significand.words.high;
    output.words.exponent = (unsigned short)(CC2_X87_EXPONENT_BIAS + leading);
    return output.value;
}

unsigned long long __fixunsxfdi(long double value)
{
    CC2ExtendedWords input;
    CC2LongWords significand;
    CC2LongWords result;
    int exponent;
    input.value = value;
    exponent = (input.words.exponent & CC2_X87_EXPONENT_MASK) -
        CC2_X87_EXPONENT_BIAS;
    result.words.low = 0;
    result.words.high = 0;
    if (exponent < 0) {
        return result.value;
    }
    if (exponent > CC2_LONG_HIGH_BIT) {
        result.words.low = CC2_UNSIGNED_WORD_MAX;
        result.words.high = CC2_UNSIGNED_WORD_MAX;
        return result.value;
    }
    significand.words.low = input.words.low;
    significand.words.high = input.words.high;
    result = cc2_shift_right_words(significand,
        CC2_LONG_HIGH_BIT - exponent);
    return result.value;
}

long long __fixxfdi(long double value)
{
    CC2ExtendedWords input;
    CC2LongWords result;
    unsigned int old_low;
    int negative;
    input.value = value;
    negative = (input.words.exponent & CC2_X87_SIGN_BIT) != 0;
    input.words.exponent &= CC2_X87_EXPONENT_MASK;
    result.value = __fixunsxfdi(input.value);
    if (negative) {
        old_low = result.words.low;
        result.words.low = 0U - result.words.low;
        result.words.high = 0U - result.words.high - (old_low != 0);
    }
    return result.value;
}
