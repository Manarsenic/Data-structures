// sll_main.c
#include "sll_node_structure.h" // For Node structure and global 'start' pointer
#include <stdio.h> // For printf, scanf
#include <stdlib.h> 

struct Node* start = NULL;

struct Node* create_ll(struct Node*);
struct Node* display(struct Node*);
struct Node* insert_beg(struct Node*);
struct Node* insert_end(struct Node*);
struct Node* insert_before(struct Node*);
struct Node* insert_after(struct Node*);
struct Node* delete_beg(struct Node*);
struct Node* delete_end(struct Node*);
struct Node* delete_node(struct Node*, int);
struct Node* delete_after(struct Node*, int);
struct Node* delete_list(struct Node*);
struct Node* sort_list(struct Node*);
int count_nodes(struct Node*);


// Main function to drive the linked list operations
int main() {
    int option, num, val; // For menu options, data values, and search values

    do {
        printf("\n\n ***** SINGLY LINKED LIST MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Count nodes");
        printf("\n 4: Insert at the beginning");
        printf("\n 5: Insert at the end");
        printf("\n 6: Insert before a given node's value");
        printf("\n 7: Insert after a given node's value");
        printf("\n 8: Delete from the beginning");
        printf("\n 9: Delete from the end");
        printf("\n 10: Delete a specific node (by value)");
        printf("\n 11: Delete node after a given node's value");
        printf("\n 12: Sort the list");
        printf("\n 13: Delete the entire list");
        printf("\n 14: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        // Optional: Clear screen after each option selection
        // #ifdef _WIN32
        //     system("cls");
        // #else
        //     system("clear");
        // #endif

        switch(option) {
            case 1:
                start = create_ll(start);
                printf("\n LINKED LIST CREATED");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                printf("\n Total nodes in the list: %d", count_nodes(start));
                break;
            case 4:
                start = insert_beg(start);
                break;
            case 5:
                start = insert_end(start);
                break;
            case 6:
                start = insert_before(start);
                break;
            case 7:
                start = insert_after(start);
                break;
            case 8:
                start = delete_beg(start);
                break;
            case 9:
                start = delete_end(start);
                break;
            case 10:
                printf("\n Enter the value of the node to be deleted: ");
                scanf("%d", &val);
                start = delete_node(start, val);
                break;
            case 11:
                printf("\n Enter the value after which the node has to be deleted: ");
                scanf("%d", &val);
                start = delete_after(start, val);
                break;
            case 12:
                start = sort_list(start);
                printf("\n List sorted.");
                break;
            case 13:
                start = delete_list(start);
                printf("\n LINKED LIST DELETED");
                break;
            case 14:
                // Exit
                break;
            default:
                printf("\n Invalid option. Please try again.");
        }
    } while (option != 14);

    return 0;
}
