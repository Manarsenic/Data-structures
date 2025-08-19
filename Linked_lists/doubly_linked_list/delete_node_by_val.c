#include "dll_node_structure.h"
#include <stdio.h>
#include <stdlib.h>

// Function to delete a specific node by its value.
struct Node* delete_node_by_val(struct Node* start, int val) {
    struct Node* ptr;
    if (start == NULL) {
        printf("\nUNDERFLOW: List is empty.");
        return start;
    }
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("\nValue %d not found. Deletion failed.", val);
    } else {
        if (ptr->prev != NULL) {
            ptr->prev->next = ptr->next;
        } else {
            start = ptr->next;
        }
        if (ptr->next != NULL) {
            ptr->next->prev = ptr->prev;
        }
        free(ptr);
        printf("\nNode with value %d deleted.", val);
    }
    return start;
}
