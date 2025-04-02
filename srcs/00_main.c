#include "../incs/mns.h"

int handle_args(int argc, char **argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Error: Missing parameters.\n");
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        print_help();
        return 1;
    }
    else if (strcmp(argv[1], "-f") == 0 || strcmp(argv[1], "--file") == 0)
    {
        handle_file_option(argc, argv);
        return 0;
    }
    else
    {
        handle_invalid_option(argv[1]);
        return 1;
    }
}

int main(int argc, char **argv)
{
    if (handle_args(argc, argv) == 1)
        return 1;

    printf("All parameters are valid.\n");
    return 0;
}