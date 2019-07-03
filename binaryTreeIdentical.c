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

int identicalTrees(struct Node* a, struct Node* b) {
    if(a == NULL && b == NULL) 
        return 1;
    
    if(a != NULL && b != NULL) {
        return(a -> data == b -> data && 
        identicalTrees(a -> left, b-> left) &&
        identicalTrees(a -> right, b -> right));
    }
    return 0;
}

int main() {
    struct Node* root1 = newNode(1);
    struct Node* root2 = newNode(1);

    root1 -> left = newNode(2);
    root1 -> right = newNode(3);
    root1 -> left -> left = newNode(4);
    root1 -> left -> right = newNode(5);

    root2 -> left = newNode(2);
    root2 -> right = newNode(3);
    root2 -> left -> left = newNode(4);
    root2 -> left -> right = newNode(5);

    if(identicalTrees(root1, root2))
        printf("Trees are identical");
    else
        printf("Trees are not identical");
    
    return 0;
}