#ifndef MNS_THREADS_H
#define MNS_THREADS_H

#include <pthread.h>
#include "mns_list.h" // For t_list
#include "mns_utils.h" // For utility functions

// Forward declaration of t_data
typedef struct s_data t_data;

// Struct to pass data to threads
typedef struct s_thread_data {
    int *numbers;
    t_list *odd;
    t_list *even;
    int thread_id;
} t_thread_data;

// Thread-related functions
void init_program(t_data data);
void *thread_routine(void *arg);
void create_thread_data(t_thread_data **thread_data, int *unique_numbers, int thread_id, t_data data, t_list *odd, t_list *even);
void create_threads(pthread_t *threads, int *unique_numbers, t_data data, t_list *odd, t_list *even);
void join_threads(pthread_t *threads, int thread_num);

#endif