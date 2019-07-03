#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void printGivenLevel(struct Node* root, int level, int itr);
int height(struct Node* node);
struct Node* newNode(int data);

void printSpirl(struct Node* root) {
    int h = height(root);
    int i;

    bool itr = false;
    for(i = 1; i <= h; i++) {
        printGivenLevel(root, i, itr);
        itr = !itr;
    }
}

void printGivenLevel(struct Node* root, int level, int itr) {
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root -> data);
    else if(level > 1) {
        if(itr) {
            printGivenLevel(root -> left, level - 1, itr);
            printGivenLevel(root -> right, level - 1, itr);
        } else {
            printGivenLevel(root -> right, level - 1, itr);
            printGivenLevel(root -> left, level - 1, itr);
        }
    }
}

int height(struct Node* node) {
    if(node == NULL)
        return 0;
    else
    {
        int lheight = height(node -> left);
        int rheight = height(node -> right);

        if(lheight > rheight)
            return (lheight + 1);
        else return (rheight + 1);
    }
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return (node);
}

int main() {
    struct Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(7);
    root -> left -> right = newNode(6);
    root -> right -> left = newNode(5);
    root -> right -> right = newNode(4);
    printf("Spiral traversal of a tree is: ");
    printSpirl(root);
    return 0;
}