#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return(node);
}

bool isBSTUtil(struct Node* root, struct Node &*prev) {
    if(root) {
        if(!isBSTUtil(root -> left, prev))
            return false;
        
        if(prev != NULL && root -> data <= prev -> data) 
            return false;

        prev = root;
        return isBSTUtil(root -> right, prev);
    }
    return true;
}

bool isBST(struct Node *root) {
    struct Node *prev = NULL;
    return isBSTUtil(root, prev);
}

int main() {
    struct Node *root = newNode(3);
    root -> left = newNode(2);
    root -> right = newNode(5);
    root -> left -> left = newNode(1);
    root -> left -> right = newNode(4);

    if(isBST(root))
        printf("Tree is BST");
    else
        printf("Tree is not BST");
}