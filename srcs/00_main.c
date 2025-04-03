#include "../incs/mns.h"

// Handles command-line arguments and options.
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

// Opens the specified file and reads its content into the data structure.
int handle_file(const char *file_path, t_data *data)
{
    FILE *file = fopen(file_path, "r");

    if (!file)
    {
        fprintf(stderr, "Error: Could not open file '%s'.\n", file_path);
        return 1;
    }

    read_file(file, data);
    fclose(file);
    return 0;
}

// Initializes the data structure with default values.
int init_data(t_data *data)
{
    data->numbers_per_thread = -1;
    data->thread_num = -1;
    return 0;
}

// Entry point of the program.
int main(int argc, char **argv)
{
    t_data data;

    init_data(&data);

    if (handle_args(argc, argv) == 1)
        return 1;

    if (handle_file(argv[2], &data) == 1)
        return 1;

   init_program(data);
    return 0;
}