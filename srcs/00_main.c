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

int handle_file(const char *file_path, int *numbers_per_thread, int *thread_num)
{
    FILE *file = fopen(file_path, "r");


    if (!file)
    {
        fprintf(stderr, "Error: Could not open file '%s'.\n", file_path);
        return 1;
    }

    read_file(file, numbers_per_thread, thread_num);
    fclose(file);
    return 0;
}

int main(int argc, char **argv)
{
    int numbers_per_thread = -1;
    int thread_num = -1;


    if (handle_args(argc, argv) == 1)
        return 1;

    if (handle_file(argv[2], &numbers_per_thread, &thread_num) == 1)
        return 1;
    
    printf(""
           "Configuration:\n"
           "  numbers_per_thread = %d\n"
           "  thread_num = %d\n",
           numbers_per_thread, thread_num);
    return 0;
}