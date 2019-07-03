#include <stdio.h>
#include <stdlib.h>
#define bool int

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

bool isBalanced(struct Node* root, int* height) {
    int lh = 0, rh = 0;
    int l = 0, r = 0;

    if(root == NULL) {
        *height = 0;
        return 1;
    }

    l = isBalanced(root -> left, &lh);
    r = isBalanced(root -> right, &rh);

    *height = (lh > rh? lh : rh) + 1;

    if((lh - rh >= 2) || (rh - lh >= 2))
        return 0;
    else
        return l && r;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return(node);
}

int main() {
    int height = 0;
    struct Node* root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    //root -> right -> left = newNode(6);
    //root -> right -> right = newNode(7);
    root -> left -> left -> left = newNode(8);
    root -> left -> left -> right = newNode(9);
    root -> left -> left -> left -> left = newNode(10);
    root -> left -> left -> left -> right = newNode(11);

    if(isBalanced(root, &height))
        printf("Tree is balanced");
    else
        printf("Tree is not balanced");
    return 0;
}
