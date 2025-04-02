#ifndef MNS_LIST_H
#define MNS_LIST_H

#include <pthread.h>
#include <stdbool.h>
#include "mns.h"

// Node structure
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// List structure
typedef struct s_list {
    t_node *head;
    pthread_mutex_t mutex;
} t_list;

// List-related functions
void append_node(t_list *list, int nbr);
t_node *create_node(int nbr);

#endif
