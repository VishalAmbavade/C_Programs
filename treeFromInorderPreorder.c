#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

int search(char arr[], int strt, int end, char value);
struct Node* newNode(char data);

struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd) {
    static int preIndex = 0;

    if(inStrt > inEnd)
        return NULL;

    struct Node* tNode = newNode(pre[preIndex++]);
    if(inStrt == inEnd)
        return tNode;
    int inIndex = search(in, inStrt, inEnd, tNode -> data);

    tNode -> left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode -> right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

int search(char arr[], int strt, int end, char value) {
    int i;
    for(i = strt; i <= end; i++) {
        if(arr[i] == value)
            return i;
    }
}

struct Node* newNode(char data) {
    struct Node* node = (struct Node*) malloc (sizeof(struct Node));
    node -> data = data;
    node -> left = NULL;
    node -> right = NULL;
    return(node);
}

void printInOrder(struct Node* node) {
    if(node == NULL) 
        return;
    printInOrder(node -> left);
    printf("%c ", node -> data);
    printInOrder(node -> right);
}

int main() {
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len = sizeof(in) / sizeof(in[0]);

    struct Node* root = buildTree(in, pre, 0, len - 1);
    printf("Inorder traversal of tree: \n");
    printInOrder(root);
    return 0;
}