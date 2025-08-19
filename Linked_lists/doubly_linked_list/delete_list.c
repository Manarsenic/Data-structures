#include "dll_node_structure.h"
#include <stdio.h>
#include <stdlib.h>

// Function to delete the entire list.
struct Node* delete_list(struct Node* start) {
    struct Node* ptr;
    if (start == NULL) {
        printf("\nList is already empty.");
        return NULL;
    }
    while (start != NULL) {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    printf("\nEntire Doubly Linked List deleted.");
    return NULL;
}
