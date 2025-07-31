#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list.
// It contains a data part and a pointer to the next node.
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer for the list, initialized to NULL for an empty list.
struct Node* start = NULL;

// Function Prototypes for all SLL operations
struct Node* create_ll(struct Node*);
struct Node* display(struct Node*);
struct Node* insert_beg(struct Node*);
struct Node* insert_end(struct Node*);
struct Node* insert_before(struct Node*, int);
struct Node* insert_after(struct Node*, int);
struct Node* delete_beg(struct Node*);
struct Node* delete_end(struct Node*);
struct Node* delete_node(struct Node*, int);
struct Node* delete_after_node(struct Node*, int);
struct Node* delete_list(struct Node*);
struct Node* sort_list(struct Node*);

int main() {
    int option, num, val;

    do {
        printf("\n\n ***** SINGLY LINKED LIST MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given value");
        printf("\n 6: Add a node after a given value");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node (by value)");
        printf("\n 10: Delete a node after a given value");
        printf("\n 11: Sort the list");
        printf("\n 12: Delete the entire list");
        printf("\n 13: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                start = create_ll(start);
                printf("\n LINKED LIST CREATED");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                printf("\n Enter the value before which to insert: ");
                scanf("%d", &val);
                start = insert_before(start, val);
                break;
            case 6:
                printf("\n Enter the value after which to insert: ");
                scanf("%d", &val);
                start = insert_after(start, val);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start);
                break;
            case 9:
                printf("\n Enter the value of the node to delete: ");
                scanf("%d", &val);
                start = delete_node(start, val);
                break;
            case 10:
                printf("\n Enter the value of the node after which to delete: ");
                scanf("%d", &val);
                start = delete_after_node(start, val);
                break;
            case 11:
                start = sort_list(start);
                printf("\n List sorted.");
                break;
            case 12:
                start = delete_list(start);
                printf("\n LINKED LIST DELETED");
                break;
            case 13:
                exit(0);
                break;
            default:
                printf("\n Invalid option. Please try again.");
        }
    } while (option != 13);
    return 0;
}

// Function implementations below
struct Node* create_ll(struct Node* start) {
    struct Node *new_node, *ptr;
    int num;

    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);

    while (num != -1) {
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
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}

struct Node* display(struct Node* start) {
    struct Node* ptr = start;
    if (start == NULL) {
        printf("\n Linked List is EMPTY.");
        return start;
    }
    printf("\n Linked List: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return start;
}

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
    return start;
}

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
    return start;
}

struct Node* insert_before(struct Node* start, int val) {
    struct Node *new_node, *ptr, *preptr;
    int num;

    printf("\n Enter the data for the new node: ");
    scanf("%d", &num);

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
        return start;
    }

    ptr = start;
    preptr = NULL;
    while (ptr != NULL && ptr->data != val) {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value %d not found. Node not inserted.\n", val);
        free(new_node);
    } else {
        preptr->next = new_node;
        new_node->next = ptr;
    }
    return start;
}

struct Node* insert_after(struct Node* start, int val) {
    struct Node *new_node, *ptr;
    int num;

    printf("\n Enter the data for the new node: ");
    scanf("%d", &num);

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
        printf("Value %d not found. Node not inserted.\n", val);
        free(new_node);
    } else {
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
    return start;
}

struct Node* delete_beg(struct Node* start) {
    struct Node* ptr;

    if (start == NULL) {
        printf("\n Linked List is EMPTY. Cannot delete.");
        return start;
    }

    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

struct Node* delete_end(struct Node* start) {
    struct Node *ptr, *preptr;

    if (start == NULL) {
        printf("\n Linked List is EMPTY. Cannot delete.");
        return start;
    }

    if (start->next == NULL) {
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
    free(ptr);
    return start;
}

struct Node* delete_node(struct Node* start, int val) {
    struct Node *ptr, *preptr;

    if (start == NULL) {
        printf("\n Linked List is EMPTY. Cannot delete.");
        return start;
    }

    if (start->data == val) {
        ptr = start;
        start = start->next;
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
        printf("Value %d not found. Cannot delete.\n", val);
    } else {
        preptr->next = ptr->next;
        free(ptr);
    }
    return start;
}

struct Node* delete_after_node(struct Node* start, int val) {
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
        printf("Value %d not found. Cannot delete node after it.\n", val);
    } else if (ptr->next == NULL) {
        printf("Node %d is the last node. No node to delete after it.\n", val);
    } else {
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
    }
    return start;
}

struct Node* delete_list(struct Node* start) {
    struct Node* ptr;
    if (start == NULL) {
        return NULL;
    }
    while (start != NULL) {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    return start;
}

struct Node* sort_list(struct Node* start) {
    struct Node *ptr1, *ptr2;
    int temp;

    if (start == NULL || start->next == NULL) {
        return start;
    }

    ptr1 = start;
    while (ptr1->next != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
