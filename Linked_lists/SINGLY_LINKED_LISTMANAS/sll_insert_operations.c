// sll_insert_operations.c
#include "sll_node_structure.h" // Include your node definition

// Function to insert a new node at the beginning of the list.
// Algorithm for Inserting a Node at the Beginning:
// Step 1: If memory allocation fails (OVERFLOW), display message and exit.
// Step 2: Allocate memory for NEW_NODE.
// Step 3: Set NEW_NODE->DATA = data_to_insert.
// Step 4: Set NEW_NODE->NEXT = START.
// Step 5: Set START = NEW_NODE.
// Step 6: EXIT.
struct Node* insert_beg(struct Node* start) {
    struct Node* new_node;
    int num;

    printf("\n Enter the data to be inserted at the beginning: ");
    scanf("%d", &num);

    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed (OVERFLOW)!\n");
        return start;
    }
    new_node->data = num;
    new_node->next = start;
    start = new_node;

    printf("Node %d inserted at the beginning.\n", num);
    return start;
}

// Function to insert a new node at the end of the list.
// Algorithm for Inserting a Node at the End:
// Step 1: If memory allocation fails (OVERFLOW), display message and exit.
// Step 2: Allocate memory for NEW_NODE.
// Step 3: Set NEW_NODE->DATA = data_to_insert.
// Step 4: Set NEW_NODE->NEXT = NULL.
// Step 5: If START is NULL (empty list), set START = NEW_NODE.
// Step 6: Else, traverse PTR from START until PTR->NEXT is NULL.
// Step 7: Set PTR->NEXT = NEW_NODE.
// Step 8: EXIT.
struct Node* insert_end(struct Node* start) {
    struct Node *new_node, *ptr;
    int num;

    printf("\n Enter the data to be inserted at the end: ");
    scanf("%d", &num);

    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed (OVERFLOW)!\n");
        return start;
    }
    new_node->data = num;
    new_node->next = NULL;

    if (start == NULL) {
        start = new_node;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }

    printf("Node %d inserted at the end.\n", num);
    return start;
}

// Function to insert a new node before a node with a specific value.
// Algorithm for Inserting a Node Before a Given Node:
// Step 1: If memory allocation fails (OVERFLOW), display message and exit.
// Step 2: Allocate memory for NEW_NODE.
// Step 3: Set NEW_NODE->DATA = data_to_insert.
// Step 4: If list is empty or target_value is at START, insert NEW_NODE at beginning.
// Step 5: Else, traverse PTR and PREPTR from START until PTR->DATA = target_value or PTR is NULL.
// Step 6: If target_value is not found, display message.
// Step 7: Else, set PREPTR->NEXT = NEW_NODE and NEW_NODE->NEXT = PTR.
// Step 8: EXIT.
struct Node* insert_before(struct Node* start) {
    struct Node *new_node, *ptr, *preptr;
    int num, val;

    printf("\n Enter the data to be inserted: ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted: ");
    scanf("%d", &val);

    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed (OVERFLOW)!\n");
        return start;
    }
    new_node->data = num;

    if (start == NULL) {
        printf("List is empty. Cannot insert before %d.\n", val);
        free(new_node);
        return start;
    }

    if (start->data == val) {
        new_node->next = start;
        start = new_node;
        printf("Node %d inserted before %d.\n", num, val);
        return start;
    }

    ptr = start;
    preptr = NULL;
    while (ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value %d not found in the list. Node not inserted.\n", val);
        free(new_node);
    } else {
        preptr->next = new_node;
        new_node->next = ptr;
        printf("Node %d inserted before %d.\n", num, val);
    }
    return start;
}

// Function to insert a new node after a node with a specific value.
// Algorithm for Inserting a Node After a Given Node:
// Step 1: If memory allocation fails (OVERFLOW), display message and exit.
// Step 2: Allocate memory for NEW_NODE.
// Step 3: Set NEW_NODE->DATA = data_to_insert.
// Step 4: Traverse PTR from START until PTR->DATA = target_value or PTR is NULL.
// Step 5: If target_value is not found, display message.
// Step 6: Else, set NEW_NODE->NEXT = PTR->NEXT and PTR->NEXT = NEW_NODE.
// Step 7: EXIT.
struct Node* insert_after(struct Node* start) {
    struct Node *new_node, *ptr;
    int num, val;

    printf("\n Enter the data to be inserted: ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted: ");
    scanf("%d", &val);

    new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed (OVERFLOW)!\n");
        return start;
    }
    new_node->data = num;

    if (start == NULL) {
        printf("List is empty. Cannot insert after %d.\n", val);
        free(new_node);
        return start;
    }

    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value %d not found in the list. Node not inserted.\n", val);
        free(new_node);
    } else {
        new_node->next = ptr->next;
        ptr->next = new_node;
        printf("Node %d inserted after %d.\n", num, val);
    }
    return start;
}
