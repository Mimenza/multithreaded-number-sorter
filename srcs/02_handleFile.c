#include "../incs/mns.h"

int handle_line(char *line, t_data *data)
{
    if (sscanf(line, "numbers_per_thread = %d", &(*data).numbers_per_thread) == 1)
    {
        if ((*data).numbers_per_thread <= 0)
        {
            fprintf(stderr, "Error: Invalid value for numbers_per_thread: %d\n", (*data).numbers_per_thread);
            exit(1);
        }
    }

    if (sscanf(line, "thread_num = %d", &(*data).thread_num) == 1)
    {
        if ((*data).thread_num <= 0)
        {
            fprintf(stderr, "Error: Invalid value for thread_num: %d\n", (*data).thread_num);
            exit(1);
        }
    }
    return 0;
}

void read_file(FILE *file, t_data *data)
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
            handle_line(line, data);
        }
    }

    if ((*data).numbers_per_thread == -1 || (*data).thread_num == -1)
    {
        fprintf(stderr, "Error: Missing required parameters in the configuration file.\n");
        exit(1);
    }

    if (non_empty_lines == 0)
    {
        fprintf(stderr, "Error: The file is empty or contains only empty lines.\n");
        exit(1);
    }

}