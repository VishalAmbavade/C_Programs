#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

void inOrder(struct Node* root) {
    if(root != NULL) {
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root -> right);
    }
}

struct Node* insert(struct Node* node, int data) {
    if(node == NULL)
        return newNode(data);
    if(data < node -> data)
        node -> left = insert(node -> left, data);
    else if (data > node -> data)
        node -> right = insert(node -> right, data);
    return node;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inOrder(root);
    return 0;
}