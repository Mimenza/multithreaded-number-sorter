#ifndef MNS_UTILS_H
#define MNS_UTILS_H

#include <stdbool.h>
#include <pthread.h>
#include "mns_list.h" // For t_list

// Forward declaration of t_data
typedef struct s_data t_data;

// Utility functions
bool is_unique(int *array, int size, int number);
void generate_unique_numbers(int *unique_numbers, int total_numbers);
bool allocate_memory(pthread_t **threads, int **unique_numbers, int thread_num, int total_numbers);
int *assign_numbers_to_thread(int *unique_numbers, t_data data, int offset);
void free_list(t_node *head);

#endif