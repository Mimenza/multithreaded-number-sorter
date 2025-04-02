#include "../incs/mns.h"

bool is_unique(int *array, int size, int number)
{
    int i = 0;
    while (i < size)
    {
        if (array[i] == number)
        {
            return false;
        }
        i++;
    }
    return true;
}

void generate_unique_numbers(int *unique_numbers, int total_numbers)
{
    srand(time(NULL));
    int i = 0;

    while (i < total_numbers)
    {
        int num = rand();
        if (is_unique(unique_numbers, i, num))
        {
            unique_numbers[i] = num;
            i++;
        }
    }
}

bool allocate_memory(pthread_t **threads, int **unique_numbers, int thread_num, int total_numbers)
{
    *threads = malloc(thread_num * sizeof(pthread_t));
    if (!*threads)
    {
        fprintf(stderr, "Error: Malloc for the threads failed.\n");
        return false;
    }

    *unique_numbers = malloc(total_numbers * sizeof(int));
    if (!*unique_numbers)
    {
        fprintf(stderr, "Error: Malloc for unique numbers failed.\n");
        free(*threads);
        return false;
    }

    return true;
}

int *assign_numbers_to_thread(int *unique_numbers, t_data data, int offset)
{

    int *thread_numbers = malloc((data.numbers_per_thread + 1) * sizeof(int));
    
    if (!thread_numbers)
    {
        fprintf(stderr, "Error: Malloc for thread numbers failed.\n");
        return NULL;
    }

    thread_numbers[0] = data.numbers_per_thread;

    for (int i = 0; i < data.numbers_per_thread; i++)
    {
        thread_numbers[i + 1] = unique_numbers[offset * data.numbers_per_thread + i];
    }
    return thread_numbers;
}

void free_list(t_node *head)
{
    t_node *current = head;
    t_node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}