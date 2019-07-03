#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

bool isCircular(struct Node *head) {
    if(head == NULL)
        return true;

    struct Node* node = head -> next;
    while(node != NULL && node != head)
        node = node -> next;

    return (node == head);
}

struct Node *newNode(int data) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    return temp;
}

int main() {
    struct Node* head = newNode(1);
    head -> next = newNode(2);
    head -> next -> next = newNode(3);
    head -> next -> next -> next = newNode(4);

    isCircular(head)? printf("\nYes") : printf("\nNo");

    head -> next -> next -> next -> next = head;

    isCircular(head)? printf("\nYes") : printf("\nNo");

    return 0;
}