/*#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void sortList(struct Node *head){
    int count[3] = {0, 0, 0};
    struct Node* ptr = head;

    while(ptr != NULL){
        count[ptr -> data] += 1;
        ptr = ptr -> next;
    }

    int i = 0;
    ptr = head;

    while(ptr != NULL){
        if(count[i] == 0) {
            i++;
        } else {
            ptr -> data = i;
            count[i]--;
            ptr = ptr -> next;
        }
    }
}

void push (struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));

    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node -> data);
        node = node -> next;
    }
    printf("\n");
}

int main(void) {
    struct Node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);

    printf("Linked List before Sorting: ");
    printList(head);

    sortList(head);

    printf("Linked List after Sorting: ");
    printList(head);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void sortList(struct Node *head) {
    int count[3] = {0, 0 ,0};
    struct Node* ptr = head;

    while(ptr != NULL){
        count[ptr -> data] += 1;
        ptr = ptr -> next;
    }
    int i = 0;
    ptr = head;

    while(ptr != NULL){
        if(count[i] == 0) {
            i++;
        } else {
            ptr -> data = i;
            count[i]--;
            ptr = ptr -> next;
        }
    }    
}

void push(struct Node** head_href, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node -> data = new_data;
    new_node -> next = (*head_href);
    (*head_href) = new_node;
}

void printList(struct Node* node) {
    while(node != NULL) {
        printf("%d ", node -> data);
        node = node -> next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);

    printList(head);
    sortList(head);
    printList(head);
    return 0;
}