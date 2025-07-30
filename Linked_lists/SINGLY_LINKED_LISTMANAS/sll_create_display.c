// sll_create_display.c
#include "sll_node_structure.h" // Include your node definition

// Function to create a new linked list by adding nodes until -1 is entered.
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

// Function to display (traverse) the linked list.
// Algorithm for Traversing a Linked List:
// Step 1: [INITIALIZE] SET PTR = START
// Step 2: Repeat Steps 3 and 4 while PTR != NULL
// Step 3: Apply Process to PTR->DATA (e.g., print data)
// Step 4: SET PTR = PTR->NEXT
// [END OF LOOP]
// Step 5: EXIT
struct Node* display(struct Node* start) {
    struct Node* ptr;
    ptr = start;

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

// Function to count the number of nodes in the linked list.
// Algorithm to Count the Number of Nodes in a Linked List:
// Step 1: [INITIALIZE] SET COUNT = 0
// Step 2: [INITIALIZE] SET PTR = START
// Step 3: Repeat Steps 4 and 5 while PTR != NULL
// Step 4: SET COUNT = COUNT + 1
// Step 5: SET PTR = PTR->NEXT
// [END OF LOOP]
// Step 6: Return COUNT
// Step 7: EXIT
int count_nodes(struct Node* start) {
    int count = 0;
    struct Node* ptr = start;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    return count;
}
