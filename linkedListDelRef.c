#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *head) {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

void deleteNode(struct Node* node_ptr) {
    struct Node* temp = node_ptr -> next;
    node_ptr -> data = temp -> data;
    node_ptr -> next = temp -> next;
    free(temp);
}

int main() {
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);

    printf("Before deleting: ");
    printList(head);

    deleteNode(head);

    printf("\nAfter deleting: ");
    printList(head);
    return 0;
}