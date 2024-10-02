#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traverse_list(struct Node* head)
{
    struct Node* ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

int main()
{
    struct Node* head;
    struct Node* first=(struct Node*)malloc(sizeof(struct Node));
    struct Node* second=(struct Node*)malloc(sizeof(struct Node));
    struct Node* third=(struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*)malloc(sizeof(struct Node));
    head=first;
    int element;
    printf("Input Element that you want Insert: ");
    scanf("%d",&element);
    first->data=element;
    first->next=second;

    printf("Input Element that you want Insert: ");
    scanf("%d",&element);
    second->data=element;
    second->next=third;

    printf("Input Element that you want Insert: ");
    scanf("%d",&element);
    third->data=element;
    third->next=fourth;

    printf("Input Element that you want Insert: ");
    scanf("%d",&element);
    fourth->data=element;
    fourth->next=head;

    printf("\nThe Elements of Your Circular List are: ");
    traverse_list(head);

    struct Node* temp=head;
    struct Node* nxt;
    do
    {
        nxt=temp->next;
        free(temp);
        temp=nxt;
    } while (temp!=head);
    
    head=NULL;
    return 0;
}