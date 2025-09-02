#include <stdio.h>
// Node structure for a binary tree.
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
// Function to insert a new node into the binary tree.
struct Node* insert_node(struct Node* root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    
    if (value < root->data) {
        root->left = insert_node(root->left, value);
    } else if (value > root->data) {
        root->right = insert_node(root->right, value);
    }
    return root;
}
int main() {
    struct Node* root = NULL;
    printf("Binary Tree project started.\n\n");
    // Building the tree
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    printf("Tree has been built.\n");
    return 0;
}
