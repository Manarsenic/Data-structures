#include "dll_node_structure.h"
#include <stdio.h>
#include <stdlib.h>

// Function to delete the node from the beginning of the list.
// Based on Section 6.4.2, "Deleting the First Node from a Doubly Linked List".
struct Node* delete_beg(struct Node* start) {
    struct Node* ptr;

    if (start == NULL) {
        printf("\n UNDERFLOW: List is empty.");
        return start;
    }

    ptr = start;
    start = start->next;
    if (start != NULL) {
        start->prev = NULL;
    }
    free(ptr);
    return start;
}

// Function to delete the node from the end of the list.
// Based on Section 6.4.2, "Deleting the Last Node from a Doubly Linked List".
struct Node* delete_end(struct Node* start) {
    struct Node* ptr;

    if (start == NULL) {
        printf("\n UNDERFLOW: List is empty.");
        return start;
    }
    
    ptr = start;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    if (ptr->prev != NULL) {
        ptr->prev->next = NULL;
    } else { // It was the only node
        start = NULL;
    }
    free(ptr);
    
    return start;
}

// Function to delete the node before a given value.
// Based on Section 6.4.2, "Deleting the Node Before a Given Node".
struct Node* delete_before(struct Node* start, int val) {
    struct Node* ptr;

    if (start == NULL) {
        printf("\n UNDERFLOW: List is empty.");
        return start;
    }
    
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("\n Value %d not found. Deletion failed.\n", val);
    } else if (ptr->prev == NULL) {
        printf("\n Value %d is the first node. Cannot delete a node before it.\n", val);
    } else {
        struct Node* temp = ptr->prev;
        if (temp->prev != NULL) {
            temp->prev->next = ptr;
        } else {
            start = ptr;
        }
        ptr->prev = temp->prev;
        free(temp);
    }
    return start;
}

// Function to delete the node after a given value.
// Based on Section 6.4.2, "Deleting the Node After a Given Node".
struct Node* delete_after(struct Node* start, int val) {
    struct Node* ptr;

    if (start == NULL) {
        printf("\n UNDERFLOW: List is empty.");
        return start;
    }
    
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("\n Value %d not found. Deletion failed.\n", val);
    } else if (ptr->next == NULL) {
        printf("\n Node %d is the last node. Cannot delete after it.\n", val);
    } else {
        struct Node* temp = ptr->next;
        ptr->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = ptr;
        }
        free(temp);
    }
    return start;
}

// Function to delete a specific node by value.
// Note: This is an additional useful operation not in the book's base example.
struct Node* delete_node_by_val(struct Node* start, int val) {
    struct Node* ptr;

    if (start == NULL) {
        printf("\n UNDERFLOW: List is empty.");
        return start;
    }
    
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("\n Value %d not found. Deletion failed.\n", val);
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
    }
    return start;
}
