#include <stdio.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
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

// Function to perform an in-order traversal of the tree (Left -> Root -> Right).
void inorder_traversal(struct Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}
void preorder_traversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}
void postorder_traversal(struct Node* root) {
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}
// Function to search for a node with a given value.
struct Node* search_node(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
 
    if (value < root->data) {
        return search_node(root->left, value);
    }
    return search_node(root->right, value);
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
    printf("In-order traversal of the tree: ");
    inorder_traversal(root);
    printf("\n\n");
    printf("Pre-order traversal of the tree: ");
    preorder_traversal(root);    
    printf("Post-order traversal of the tree: ");
    postorder_traversal(root);
    struct Node* found_node = search_node(root, 40);
    if (found_node != NULL) {
        printf("Found node with value %d.\n", found_node->data);
    } else {
        printf("Node with value 40 not found.\n");
    }
    
    found_node = search_node(root, 99);
    if (found_node != NULL) {
        printf("Found node with value %d.\n", found_node->data);
    } else {
        printf("Node with value 99 not found.\n");
    }
    
    return 0;
}
