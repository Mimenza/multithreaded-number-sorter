#ifndef MNS_UTILS_H
#define MNS_UTILS_H

#include <stdbool.h>
#include <pthread.h>
#include <signal.h>
#include "mns_list.h" // For t_list

// Forward declaration of t_data
typedef struct s_data t_data;

// Struct to hold data for each thread for the free
typedef struct s_free_data
{
    int *unique_numbers;
    t_list *odd;
    t_list *even;
    pthread_t *threads;

} t_free_data;

// Utility functions
bool is_unique(int *array, int size, int number);
void generate_unique_numbers(int *unique_numbers, int total_numbers);
bool allocate_memory(pthread_t **threads, int **unique_numbers, int thread_num, int total_numbers);
int *assign_numbers_to_thread(int *unique_numbers, t_data data, int offset);
void free_list(t_node *head);
void free_all(t_list *odd, t_list *even, pthread_t *threads, int *unique_numbers);
void print_list(t_node *head);
void print_config(t_data data);
void print_result(t_list *odd, t_list *even);
void sigint_handler(int sig);
t_free_data *static_data(t_list *odd, t_list *even, pthread_t *threads, int *unique_numbers, int mode);

#endif