#include "../incs/mns.h"


t_node *create_node(int nbr)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        fprintf(stderr, "Error: Failed allocating memory for the new node.\n");
        return NULL;
    }
    new_node->value = nbr;
    new_node->next = NULL;
    return new_node;
}

void append_node(t_list *list, int nbr)
{
    t_node *new_node = create_node(nbr);
    
    if (!new_node)
        return;
        
    if (!list->head)
    {
        list->head = new_node;
        return;
    }

    if (list->head->value > nbr)
    {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }

    t_node *current = list->head;
    
    while (current->next && current->next->value < nbr)
        current = current->next;

    new_node->next = current->next;
    current->next = new_node;
}