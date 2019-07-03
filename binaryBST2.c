#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left, *right;
};

bool isBST(struct Node* root, struct Node* l, struct Node* r) {
    l = r = NULL;
    if(root == NULL)
        return false;
    if(l != NULL && root -> data < l -> data)
        return false;
    if(r != NULL && root -> data > r -> data)
        return false;
    return isBST(root -> left, l, root) && isBST(root -> right, root, r);
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = node -> right = NULL;
    return(node);
}

int main() {
    struct Node* root = newNode(10);
    root -> left = newNode(6);
    root -> right = newNode(18);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(8);
    root -> right -> left = newNode(15);
    root -> right -> right = newNode(21);

    if(isBST(root, NULL, NULL))
        printf("Tree is BST");
    else
        printf("Tree is not BST");

}