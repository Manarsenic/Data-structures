// sll_node_structure.h
#ifndef SLL_NODE_STRUCTURE_H
#define SLL_NODE_STRUCTURE_H

#include <stdio.h>   // For NULL
#include <stdlib.h>  // For malloc, free

// Define the structure for a node in the singly linked list
struct Node {
    int data;          
    struct Node* next;  
};


extern struct Node* start; // 'extern' declares that 'start' is defined elsewhere

#endif // SLL_NODE_STRUCTURE_H
