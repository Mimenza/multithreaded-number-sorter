#ifndef MNS_H
#define MNS_H

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct s_node
{
    int value;
    pthread_mutex_t mutex;
} t_node;

// 00_main.c
int main(int argc, char **argv);
int handle_args(int argc, char **argv);

// 01_verification.c
void print_help();
int file_exists(const char *path);
int validate_file(const char *file_path);
void handle_file_option(int argc, char *argv[]);
void handle_invalid_option(const char *option);
#endif