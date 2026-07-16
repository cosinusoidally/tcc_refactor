/* Check exact bootstrap values without relying on compiler float literals. */

union double_words {
    double value;
    unsigned int words[2];
};

union float_word {
    float value;
    unsigned int word;
};

double strtod(const char *text, char **end_pointer);
float strtof(const char *text, char **end_pointer);
long double strtold(const char *text, char **end_pointer);

int main(int argc, char **argv)
{
    union double_words double_value;
    union float_word float_value;
    char *end;
    const char *invalid;

    double_value.value = strtod("4294967296.0", &end);
    if (double_value.words[0] != 0 || double_value.words[1] != 0x41f00000 ||
        *end != 0) {
        return 1;
    }

    double_value.value = strtod("0.001tail", &end);
    if (double_value.words[0] != 0xd2f1a9fc ||
        double_value.words[1] != 0x3f50624d || *end != 't') {
        return 2;
    }

    double_value.value = strtod(" \t-25e1!", &end);
    if (double_value.words[0] != 0 || double_value.words[1] != 0xc06f4000 ||
        *end != '!') {
        return 3;
    }

    float_value.value = strtof("1.5", &end);
    if (float_value.word != 0x3fc00000 || *end != 0) {
        return 4;
    }

    if ((int)strtold("12.75rest", &end) != 12 || *end != 'r') {
        return 5;
    }

    invalid = "  +x";
    double_value.value = strtod(invalid, &end);
    if (double_value.words[0] != 0 || double_value.words[1] != 0 ||
        end != invalid) {
        return 6;
    }
    return 0;
}
