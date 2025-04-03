#include "../incs/mns.h"

void *thread_routine(void *arg)
{
    t_thread_data *data = (t_thread_data *)arg;
    int i = 1;
 
    while (i <= data->numbers[0])
    {
        if (data->numbers[i] % 2 == 0)
        {
            pthread_mutex_lock(&data->even->mutex);
            append_node(data->even, data->numbers[i]);
            pthread_mutex_unlock(&data->even->mutex);
        }
        else
        {
            pthread_mutex_lock(&data->odd->mutex);
            append_node(data->odd, data->numbers[i]);
            pthread_mutex_unlock(&data->odd->mutex);
        }
        i++;
    }
    free(data->numbers);
    free(data);
}

void create_thread_data(t_thread_data **thread_data, int *unique_numbers, int thread_id, t_data data, t_list *odd, t_list *even)
{
    *thread_data = malloc(sizeof(t_thread_data));

    if (!(*thread_data))
    {
        fprintf(stderr, "Error: Malloc for thread data failed.\n");
        return;
    }
    (*thread_data)->numbers = assign_numbers_to_thread(unique_numbers, data, thread_id);
    (*thread_data)->odd = odd;
    (*thread_data)->even = even;
    (*thread_data)->thread_id = thread_id;
}

t_list *create_and_init_list()
{
    t_list *list = malloc(sizeof(t_list));
    if (!list)
    {
        fprintf(stderr, "Error: Malloc for list failed.\n");
        return NULL;
    }
    list->head = NULL;
    pthread_mutex_init(&list->mutex, NULL);
    return list;
}

void create_threads(pthread_t *threads, int *unique_numbers, t_data data, t_list *odd, t_list *even)
{
    int i = 0;
    while (i < data.thread_num)
    {
        t_thread_data *thread_data;
        create_thread_data(&thread_data, unique_numbers, i, data, odd, even);
        pthread_create(&threads[i], NULL, thread_routine, thread_data);
        i++;
    }
}

void join_threads(pthread_t *threads, int thread_num)
{
    int i = 0;
    while (i < thread_num)
    {
        pthread_join(threads[i], NULL);
        i++;
    }
}

void init_program(t_data data)
{
    pthread_t *threads;

    int *unique_numbers;
    int total_numbers = data.thread_num * data.numbers_per_thread;

    t_list *odd = create_and_init_list();
    t_list *even = create_and_init_list();

    if (!odd || !even)
    {
        free(odd);
        free(even);
        return;
    }

    if (!allocate_memory(&threads, &unique_numbers, data.thread_num, total_numbers))
        return;

    generate_unique_numbers(unique_numbers, total_numbers);

    create_threads(threads, unique_numbers, data, odd, even);
    join_threads(threads, data.thread_num);

    print_config(data);
    print_result(odd, even);

    free_all(odd, even, threads, unique_numbers);
}