#include "dll_node_structure.h"
#include <stdio.h>
#include <stdlib.h>

// Function to sort the doubly linked list.
struct Node* sort_list(struct Node* start) {
    struct Node *ptr1, *ptr2;
    int temp_data;
    if (start == NULL || start->next == NULL) {
        return start;
    }
    ptr1 = start;
    while (ptr1->next != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->data > ptr2->data) {
                temp_data = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp_data;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
