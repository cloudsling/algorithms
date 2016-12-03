#include "Linked_List.h"

#define TRUE 1
#define FALSE 0
#define LSIZE_T sizeof(Linked_List)

int linked_list_insert(Linked_List **nextp, int const new_value) {
    Linked_List *current;
    Linked_List *new_node;

    while ((current = *nextp) != NULL && current->value < new_value)
        nextp = &current->next;

    new_node = (Linked_List *) malloc(LSIZE_T);
    if (new_node == NULL) {
        printf("No More Memory To Allocation");
        return FALSE;
    }

    new_node->value = new_value;
    new_node->next = current;

    *nextp = new_node;

    return TRUE;
}

void print_list(Linked_List const *list) {

    while((list = list->next) != NULL)
        printf("%d\t", list->value);
}

Linked_List *create_list() {

    Linked_List *new_node;

    new_node = (Linked_List *)malloc(LSIZE_T);

    return new_node == NULL ? NULL : new_node;
}
