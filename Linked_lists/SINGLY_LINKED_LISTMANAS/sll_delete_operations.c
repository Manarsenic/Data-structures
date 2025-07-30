// sll_delete_operations.c
#include "sll_node_structure.h" // Include your node definition

// Function to delete the node from the beginning of the list.
// Algorithm for Deleting the First Node from a Linked List:
// Step 1: If START is NULL (UNDERFLOW), display message and exit.
// Step 2: Set PTR = START (save the node to be deleted)
// Step 3: Set START = START->NEXT (move START to the next node)
// Step 4: FREE PTR (de-allocate memory)
// Step 5: EXIT
struct Node* delete_beg(struct Node* start) {
    struct Node* ptr;

    if (start == NULL) {
        printf("\n Linked List is EMPTY. Cannot delete.");
        return start;
    }

    ptr = start;
    start = start->next;
    printf("Node %d deleted from the beginning.\n", ptr->data);
    free(ptr);

    return start;
}

// Function to delete the node from the end of the list.
// Algorithm for Deleting the Last Node from a Linked List:
// Step 1: If START is NULL (UNDERFLOW), display message and exit.
// Step 2: Set PTR = START
// Step 3: Repeat Steps 4 and 5 while PTR->NEXT != NULL (traverse to find the last node)
// Step 4:   SET PREPTR = PTR
// Step 5:   SET PTR = PTR->NEXT
// [END OF LOOP]
// Step 6: If PREPTR is NULL (only one node in the list)
// Step 7:   SET START = NULL
// Step 8: Else (more than one node)
// Step 9:   SET PREPTR->NEXT = NULL (disconnect the last node)
// [END OF IF]
// Step 10: FREE PTR (de-allocate memory)
// Step 11: EXIT
struct Node* delete_end(struct Node* start) {
    struct Node *ptr, *preptr;

    if (start == NULL) {
        printf("\n Linked List is EMPTY. Cannot delete.");
        return start;
    }

    if (start->next == NULL) {
        printf("Node %d deleted from the end.\n", start->data);
        free(start);
        return NULL;
    }

    ptr = start;
    preptr = NULL;
    while (ptr->next != NULL) {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    printf("Node %d deleted from the end.\n", ptr->data);
    free(ptr);

    return start;
}

// Function to delete a node with a specific value.
// Algorithm for Deleting a Specific Node by Value:
// Step 1: If START is NULL (UNDERFLOW), display message and exit.
// Step 2: If START->DATA = VAL_TO_DELETE (if first node is target)
// Step 3:   SET PTR = START
// Step 4:   SET START = START->NEXT
// Step 5:   FREE PTR
// Step 6: Else
// Step 7:   SET PTR = START
// Step 8:   SET PREPTR = NULL
// Step 9:   Repeat while PTR != NULL AND PTR->DATA != VAL_TO_DELETE
// Step 10:    SET PREPTR = PTR
// Step 11:    SET PTR = PTR->NEXT
// [END OF LOOP]
// Step 12:  If PTR = NULL (value not found)
// Step 13:    Write "Value not found".
// Step 14:  Else (value found, PTR is target, PREPTR is its predecessor)
// Step 15:    SET PREPTR->NEXT = PTR->NEXT
// Step 16:    FREE PTR
// [END OF IF]
// Step 17: EXIT
struct Node* delete_node(struct Node* start, int val) {
    struct Node *ptr, *preptr;

    if (start == NULL) {
        printf("\n Linked List is EMPTY. Cannot delete.");
        return start;
    }

    if (start->data == val) {
        ptr = start;
        start = start->next;
        printf("Node %d deleted.\n", ptr->data);
        free(ptr);
        return start;
    }

    ptr = start;
    preptr = NULL;
    while (ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value %d not found in the list. Cannot delete.\n", val);
    } else {
        preptr->next = ptr->next;
        printf("Node %d deleted.\n", ptr->data);
        free(ptr);
    }
    return start;
}

// Function to delete the node after a node with a specific value.
// Algorithm for Deleting the Node After a Given Node:
// Step 1: If START is NULL (UNDERFLOW), display message and exit.
// Step 2: Set PTR = START
// Step 3: Repeat Step 4 while PTR != NULL AND PTR->DATA != TARGET_VAL
// Step 4:   SET PTR = PTR->NEXT
// [END OF LOOP]
// Step 5: If PTR = NULL OR PTR->NEXT = NULL (target not found OR target is last node)
// Step 6:   Write "Target not found or no node after target".
// Step 7: Else (target found and has a successor)
// Step 8:   SET TEMP = PTR->NEXT (node to be deleted)
// Step 9:   SET PTR->NEXT = TEMP->NEXT (unlink TEMP)
// Step 10:  FREE TEMP (de-allocate memory)
// [END OF IF]
// Step 11: EXIT
struct Node* delete_after(struct Node* start, int val) {
    struct Node *ptr, *temp;

    if (start == NULL) {
        printf("\n Linked List is EMPTY. Cannot delete.");
        return start;
    }

    ptr = start;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value %d not found in the list. Cannot delete node after it.\n", val);
    } else if (ptr->next == NULL) {
        printf("Node %d is the last node. No node to delete after it.\n", val);
    } else {
        temp = ptr->next;
        ptr->next = temp->next;
        printf("Node %d deleted after node %d.\n", temp->data, val);
        free(temp);
    }
    return start;
}
