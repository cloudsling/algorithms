#ifndef DATA_STRUCTURE_LINKED_LIST_H
#define DATA_STRUCTURE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    struct NODE *next;
    int value;
} Linked_List;

extern int linked_list_insert(Linked_List **nextp, int const new_value);

void print_list(Linked_List const *);

Linked_List *create_list();

#endif //DATA_STRUCTURE_LINKED_LIST_H
