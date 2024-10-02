#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

void traverse_list(struct Node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}


int main()
{
    struct Node *head;
    struct Node *first=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node*)malloc(sizeof(struct Node));

    head=first;
    int element;
    printf("Input the element that you want to insert: ");
    scanf("%d",&element);
    first->prev=NULL;
    first->next=second;
    first->data=element;

    printf("Input the element that you want to insert: ");
    scanf("%d",&element);
    second->prev=first;
    second->next=third;
    second->data=element;

    printf("Input the element that you want to insert: ");
    scanf("%d",&element);
    third->prev=second;
    third->next=fourth;
    third->data=element;

    printf("Input the element that you want to insert: ");
    scanf("%d",&element);
    fourth->prev=third;
    fourth->next=NULL;
    fourth->data=element;

    printf("The elements of your list are: ");
    traverse_list(head);
    
    struct Node *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(head);
    }

    return 0;
}