#include "dll_node_structure.h"
#include <stdio.h>
#include <stdlib.h>

// Function to insert a node at the beginning of the list.
// Based on Section 6.4.1, "Inserting a Node at the Beginning of a Doubly Linked List".
struct Node* insert_beg(struct Node* start) {
    struct Node* new_node;
    int num;

    printf("\n Enter the data to be inserted at the beginning: ");
    scanf("%d", &num);

    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("\n OVERFLOW: Memory allocation failed!");
        return start;
    }
    new_node->data = num;
    new_node->prev = NULL;
    new_node->next = start;

    if (start != NULL) {
        start->prev = new_node;
    }
    start = new_node;
    
    return start;
}

struct Node* insert_end(struct Node* start) {
    struct Node *new_node, *ptr;
    int num;

    printf("\n Enter the data to be inserted at the end: ");
    scanf("%d", &num);

    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("\n OVERFLOW: Memory allocation failed!");
        return start;
    }
    new_node->data = num;
    new_node->next = NULL;
    
    if (start == NULL) {
        new_node->prev = NULL;
        start = new_node;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
    }
    
    return start;
}

// Function to insert a node before a given value.
// Based on Section 6.4.1, "Inserting a Node Before a Given Node".
struct Node* insert_before(struct Node* start, int val) {
    struct Node *new_node, *ptr;
    int num;

    printf("\n Enter the data for the new node: ");
    scanf("%d", &num);

    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("\n OVERFLOW: Memory allocation failed!");
        return start;
    }
    new_node->data = num;
    
    if (start == NULL) {
        printf("\n List is empty. Cannot insert before %d.\n", val);
        free(new_node);
        return start;
    }
    
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("\n Value %d not found. Node not inserted.\n", val);
        free(new_node);
    } else {
        new_node->next = ptr;
        new_node->prev = ptr->prev;
        if (ptr->prev != NULL) {
            ptr->prev->next = new_node;
        } else {
            start = new_node;
        }
        ptr->prev = new_node;
    }
    return start;
}

// Function to insert a node after a given value.
// Based on Section 6.4.1, "Inserting a Node After a Given Node".
struct Node* insert_after(struct Node* start, int val) {
    struct Node *new_node, *ptr;
    int num;

    printf("\n Enter the data for the new node: ");
    scanf("%d", &num);

    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("\n OVERFLOW: Memory allocation failed!");
        return start;
    }
    new_node->data = num;
    
    if (start == NULL) {
        printf("\n List is empty. Cannot insert after %d.\n", val);
        free(new_node);
        return start;
    }
    
    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("\n Value %d not found. Node not inserted.\n", val);
        free(new_node);
    } else {
        new_node->prev = ptr;
        new_node->next = ptr->next;
        if (ptr->next != NULL) {
            ptr->next->prev = new_node;
        }
        ptr->next = new_node;
    }
    return start;
}
