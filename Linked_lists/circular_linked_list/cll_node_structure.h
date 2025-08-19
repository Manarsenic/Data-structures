// cll_node_structure.h
#ifndef CLL_NODE_STRUCTURE_H
#define CLL_NODE_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

extern struct Node* start;

#endif 
