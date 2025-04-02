#ifndef MNS_H
#define MNS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#include "mns_threads.h"
#include "mns_list.h"
#include "mns_utils.h"

// Data structure for program configuration
typedef struct s_data {
    int numbers_per_thread;
    int thread_num;
} t_data;

// Main program functions
int main(int argc, char **argv);
int handle_args(int argc, char **argv);
int handle_file(const char *file_path, t_data *data);

// Verification functions
void print_help();
int file_exists(const char *path);
int validate_file(const char *file_path);
void handle_file_option(int argc, char *argv[]);
void handle_invalid_option(const char *option);

// File handling functions
void read_file(FILE *file, t_data *data);
int handle_line(char *line, t_data *data);

#endif