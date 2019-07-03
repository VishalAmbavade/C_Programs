#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left, *right;
};

void printLeaves(struct Node* root) {
    if(root) {
        printLeaves(root -> left);
        if(!(root -> left) && !(root -> right))
            printf("%d ", root -> data);
        printLeaves(root -> right);
    }
}

void printBoundaryLeft(struct Node* root) {
    if(root) {
        if(root -> left) {
            printf("%d ", root -> data);
            printBoundaryLeft(root -> left);
        } else if (root -> right) {
            printf("%d ", root -> data);
            printBoundaryLeft (root -> right);
        }
    }
}

void printBoundaryRight(struct Node* root) {
    if(root) {
        if(root -> right) {
            printBoundaryRight(root -> right);
            printf("%d ", root -> data);
        } else if(root -> left) {
            printBoundaryRight (root -> left);
            printf("%d ", root -> data);
        }
    }
}

void printBoundary(struct Node* root) {
    if(root) {
        printf("%d ", root -> data);
        printBoundaryLeft(root -> left);
        printLeaves(root -> left);
        printLeaves(root -> right);
        printBoundaryRight(root -> right);
    }
}

struct Node* newNode(int data) {
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));

    new_node -> data = data;
    new_node -> left = new_node -> right = NULL;
    return new_node;
}

int main() {
    struct Node* root = newNode(20);
    root -> left = newNode(8);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(12);
    root -> left -> right -> left = newNode(10);
    root -> left -> right -> right = newNode(14);
    root -> right = newNode(22);
    root -> right -> right = newNode(25);

    printBoundary(root);
    return 0;
}