#include "../incs/mns.h"

// Checks if a number is unique in the given array.
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

// Generates an array of unique random numbers.
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

// Allocates memory for threads and unique numbers arrays.
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

// Assigns numbers to a thread based on its offset.
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

// Frees all nodes in a linked list.
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

// Prints all elements in a linked list.
void print_list(t_node *head)
{
    t_node *current = head;
    int i = 0;
    while (current != NULL)
    {
        printf("[%d] %d\n", i, current->value);
        current = current->next;
        i++;
    }
    printf("\n");
}

// Prints the configuration details of the program.
void print_config(t_data data)
{
    printf(""
           "Configuration:\n"
           "  numbers_per_thread = %d\n"
           "  thread_num = %d\n",
           data.numbers_per_thread, data.thread_num);
}

// Prints the results of the odd and even lists.
void print_result(t_list *odd, t_list *even)
{
    printf("\nOdd list:\n");
    print_list(odd->head);
    printf("Even list:\n");
    print_list(even->head);
}

// Frees all allocated resources used in the program.
void free_all(t_list *odd, t_list *even, pthread_t *threads, int *unique_numbers)
{
    if (odd)
    {
        free_list(odd->head);
        free(odd);
    }
    if (even)
    {
        free_list(even->head);
        free(even);
    }
    if (threads)
        free(threads);
    if (unique_numbers)
        free(unique_numbers);
}

// It initializes or retrieves the static data structure for the free.
t_free_data *static_data(t_list *odd, t_list *even, pthread_t *threads, int *unique_numbers, int mode)
{
    static t_free_data data;

    if (mode == 0)
    {
        data.odd = odd;
        data.even = even;
        data.threads = threads;
        data.unique_numbers = unique_numbers;
        return NULL;
    }
    else if (mode == 1)
        return &data;

    return NULL;
}

// Signal handler for SIGINT (Ctrl+C).
void sigint_handler(int sig)
{
    t_free_data *data = static_data(NULL, NULL, NULL, NULL, 1);
    if (data)
        free_all(data->odd, data->even, data->threads, data->unique_numbers);
    exit(0);
}