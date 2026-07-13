/* Host file adapter for the self-hosted cc0 compiler core. */
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

extern int CC0_ELF_OUTPUT;
extern int CC0_ELF_OUTPUT_LENGTH;
int cc0_init(void);
int cc0_compiler_build_object(int source, int length);

static int write_all(int descriptor, const unsigned char *data, int length)
{
    int written;

    while (length > 0) {
        written = write(descriptor, data, length);
        if (written <= 0) {
            return 1;
        }
        data += written;
        length -= written;
    }
    return 0;
}

int main(int argc, char **argv)
{
    struct stat status;
    unsigned char *source;
    const char *input_name;
    const char *output_name;
    int input;
    int output;
    int result;

    if (argc == 3) {
        input_name = argv[1];
        output_name = argv[2];
    } else if (argc == 5 && strcmp(argv[1], "-c") == 0 &&
        strcmp(argv[3], "-o") == 0) {
        input_name = argv[2];
        output_name = argv[4];
    } else {
        return 2;
    }
    input = open(input_name, O_RDONLY);
    if (input < 0 || fstat(input, &status) != 0 || status.st_size <= 0) {
        return 3;
    }
    source = mmap(0, status.st_size, PROT_READ, MAP_PRIVATE, input, 0);
    close(input);
    if (source == MAP_FAILED) {
        return 4;
    }
    cc0_init();
    result = cc0_compiler_build_object((int)source, (int)status.st_size);
    if (result != 0) {
        munmap(source, status.st_size);
        return 5;
    }
    output = open(output_name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (output < 0) {
        munmap(source, status.st_size);
        return 6;
    }
    result = write_all(output, (unsigned char *)CC0_ELF_OUTPUT,
        CC0_ELF_OUTPUT_LENGTH);
    close(output);
    munmap(source, status.st_size);
    return result;
}
