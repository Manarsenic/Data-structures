#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list.
// It consists of three parts: data, a pointer to the next node, and a pointer to the previous node.
struct Node {
    struct Node* prev;  // Pointer to the previous node
    int data;           // Data to be stored in the node
    struct Node* next;  // Pointer to the next node
};

// Global head pointer for the list.
struct Node* head = NULL;

// Function to insert a new node at the end of the list.
void insert_end(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;
    
    if (head == NULL) {
        new_node->prev = NULL;
        head = new_node;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

// Function to print the list from head to tail.
void print_list() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    printf("Doubly Linked List project started.\n\n");
    
    // Inserting some nodes into the list.
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(40);
    
    // Printing the list to confirm insertions.
    print_list();
    
    return 0;
}
