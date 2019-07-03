#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteMid(struct Node* head) {
    if(head == NULL) 
        return NULL;
    if(head -> next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    struct Node* prev;
    while(fast_ptr != NULL && fast_ptr -> next != NULL) {
        fast_ptr = fast_ptr -> next -> next;
        prev = slow_ptr;
        slow_ptr = slow_ptr -> next;
    }
    prev -> next = slow_ptr -> next;
    free(slow_ptr);
    return head;
}

void printList(struct Node* ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
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

    printf("Gien Linked List: ");
    printList(head);

    head = deleteMid(head);

    printf("\nLinked List after deletion: ");
    printList(head);
    return 0;
}
