#include "../incs/mns.h"

int handle_line(char *line, int *numbers_per_thread, int *thread_num)
{
    if (sscanf(line, "numbers_per_thread = %d", numbers_per_thread) == 1)
    {
        if (*numbers_per_thread <= 0)
        {
            fprintf(stderr, "Error: Invalid value for numbers_per_thread: %d\n", *numbers_per_thread);
            exit(1);
        }
    }

    if (sscanf(line, "thread_num = %d", thread_num) == 1)
    {
        if (*thread_num <= 0)
        {
            fprintf(stderr, "Error: Invalid value for thread_num: %d\n", *thread_num);
            exit(1);
        }
    }

    return 0;
}

void read_file(FILE *file, int *numbers_per_thread, int *thread_num)
{
    char line[256];
    int non_empty_lines = 0;


    while (fgets(line, sizeof(line), file))
    {
        int is_empty = 1;
        int i = 0;

        while (line[i] != '\0')
        {
            if (!isspace((unsigned char)line[i]))
            {
                is_empty = 0;
                break;
            }
            i++;
        }

        if (!is_empty)
        {
            non_empty_lines++;
            if (non_empty_lines > 2)
            {
                fprintf(stderr, "Error: More than 2 non-empty lines found.\n");
                exit(1);
            }
            handle_line(line, numbers_per_thread, thread_num);
        }
    }

    if (*numbers_per_thread == -1 || *thread_num == -1)
    {
        fprintf(stderr, "Error: Missing required parameters in the configuration file.\n");
        exit(1);
    }

    if (non_empty_lines == 0)
    {
        fprintf(stderr, "Error: The file is empty or contains only empty lines.\n");
        exit(1);
    }

    // printf("Found thread_num: %d\n", *thread_num);
    // printf("Found numbers_per_thread: %d\n", *numbers_per_thread);
}