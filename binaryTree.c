#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return(node);
}

void inOrder(struct Node* node) {
    if(node == NULL)
        return;
    inOrder(node -> left);
    printf("%d ", node -> data);
    inOrder(node -> right);
}

int main() {
    struct Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    inOrder(root);
    return 0;
}