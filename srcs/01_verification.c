#include "../incs/mns.h"


void print_help()
{
    printf("Usage:\n");
    printf("  -h, --help       Show this help message\n");
    printf("  -f, --file PATH  Specify the configuration file (must be .txt)\n");
}

int file_exists(const char *path)
{
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

int validate_file(const char *file_path)
{
    const char *extension = strrchr(file_path, '.');
    if (!extension || strcmp(extension, ".txt") != 0)
    {
        fprintf(stderr, "Error: Configuration file must have a .txt extension.\n");
        return 0;
    }

    if (!file_exists(file_path))
    {
        fprintf(stderr, "Error: Configuration file does not exist.\n");
        return 0;
    }
    return 1;
}

void handle_file_option(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Error: Missing configuration file path.\n");
        exit(1);
    }

    const char *file_path = argv[2];
    if (!validate_file(file_path))
        exit(1);
}

void handle_invalid_option(const char *option)
{
    fprintf(stderr, "Error: Invalid parameter '%s'.\n", option);
    exit(1);
}
