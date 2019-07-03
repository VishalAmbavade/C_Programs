#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *enque(struct node **p, int num, struct node **q)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    if (temp != NULL)
    {
        temp->data = num;
        temp->link = NULL;
        if (p == NULL && q == NULL)
        {
            *p = temp;
            *q = *p;
        }

        else
        {
            temp->data= num;
            *p=temp;
        }
    }
    return *p;
}

void main()
{
    struct node *rear = NULL;
    struct node *front = NULL;

    struct node *m = NULL;

    int n, num;
    do
    {
        printf("enter the value you want to enter in queue----");
        scanf("%d", &num);
        rear = enque(&rear, num, &front);
        printf("the element %d is enter in the queue\n", rear->data);

        printf("enter 1 for entering an element---");
        scanf("%d", &n);
    } while (n == 1);

    printf("the data in the queue is->");
    while (rear != NULL)
    {
        printf("%d\n", rear->data);
        rear = rear->link;
    }
}
