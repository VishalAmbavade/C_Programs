#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

struct Node* minValue(struct Node* node);

struct Node* inOrderSuccesor(struct Node* root, struct Node* n) {
    if(n -> right != NULL)
        return minValue(n -> right);
    
    struct Node* p = n -> parent;
    while(p != NULL && n == p -> right) {
        n = p;
        p = p -> parent;
    }
    return p;
}

struct Node* minValue(struct Node* node) {
    struct Node* current = node;
    while(current -> left != NULL) {
        current = current -> left;
    }
    return current;
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    node -> parent = NULL;
    return(node);
}

struct Node* insert(struct Node* node, int data) {
    if(node == NULL)
        return(newNode(data));
    else {
        struct Node* temp;
        if(data <= node -> data) {
            temp = insert(node -> left, data);
            node -> left = temp;
            temp -> parent = node;
        } else {
            temp = insert(node -> right, data);
            node -> right = temp;
            temp -> parent = node;
        }
        return node;
    }
}

int main() {
    struct Node* root = NULL, *temp, *succ, *min;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root -> left -> right -> right;
    
    succ = inOrderSuccesor(root, temp);
    if(succ != NULL)
        printf("Inorder successor of %d is %d ", temp -> data, succ -> data);
    else
        printf("Doesn't exist");
    return 0;
}