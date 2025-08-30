#include <stdio.h>
// Node structure for a binary tree.
// It contains data, and pointers to the left and right children.
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a new node.
struct Node* create_node(int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
int main() {
    printf("Bin Tree.");
    return 0;
}
