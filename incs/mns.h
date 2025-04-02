#ifndef MNS_H
#define MNS_H

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;

typedef struct s_list
{
    t_node *head;
    pthread_mutex_t mutex;
} t_list;


typedef struct s_data
{
    int numbers_per_thread;
    int thread_num;
} t_data;


//struct to pass data to threads
typedef struct s_thread_data {
    int *numbers;
    t_list *odd;
    t_list *even;
    int thread_id;
} t_thread_data;


// 00_main.c
int main(int argc, char **argv);
int handle_args(int argc, char **argv);
int handle_file(const char *file_path, t_data *data);


// 01_verification.c
void print_help();
int file_exists(const char *path);
int validate_file(const char *file_path);
void handle_file_option(int argc, char *argv[]);
void handle_invalid_option(const char *option);

// 02_handleFile.c
void read_file(FILE *file, t_data *data);

//03_thread.c
void init_program(t_data data);
void *thread_routine(void *arg);

//04_utils.c
bool is_unique(int *array, int size, int number);
void generate_unique_numbers(int *unique_numbers, int total_numbers);
bool allocate_memory(pthread_t **threads, int **unique_numbers, int thread_num, int total_numbers);
int * assign_numbers_to_thread(int *unique_numbers, t_data data, int offset);

// 05_list.c
void append_node(t_list *list, int nbr);
#endif