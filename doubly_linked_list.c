#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
// It consists of three parts: data, a pointer to the next node, and a pointer to the previous node. 
struct Node {
    struct Node* prev;    // Pointer to the previous node 
    int data;
    struct Node* next;    // Pointer to the next node 
};

// Global head pointer for the list.
struct Node* start = NULL;

// A placeholder main function to create a valid C file.
int main() {
    printf("Doubly Linked List project started.\n");
    return 0;
}
