#include<stdio.h>
#include<stdlib.h>

// 4 Cases of insertion in Linked List
// Case 1: At the beginning
// Case 2: In Between
// Case 3: At the End
// Case 4: After a Node

struct Node{
    int data;
    struct Node* next;
};

void traverse_list(struct Node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

// 1-Inserting at the begining
struct Node* insert_begin(struct Node* head,int data)
{
    // Allocating memory for new node
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;

    return ptr;
}

// 2-Inserting between nodes
struct Node* insert_bw(struct Node* head,int data,int index)
{
    // Allocation memory for new node
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    // using a pointer to keep track
    struct Node*p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;

    return head;

}

// 3-At the End
struct Node* insert_end(struct Node*head,int data)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    //a pointer to keep track of nodes
    struct Node*p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;

    return head;
}

// 4-Insert After a Node
struct Node* insert_after(struct Node*head,struct Node* prev_node,int data)
{
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=prev_node->next;
    prev_node->next=ptr;

    return head;
}

int main()
{
    struct Node* head;
    struct Node* first;
    struct Node*second;
    struct Node*third;

    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

    head=first;
    int element;

    printf("Input  First Element you want to insert in List: ");
    scanf("%d",&element);
    first->data=element;
    first->next=second;

    printf("Input Second Element you want to insert in List: ");
    scanf("%d",&element);
    second->data=element;
    second->next=third;

    printf("Input Third Element you want to insert in List: ");
    scanf("%d",&element);
    third->data=element;
    third->next=NULL;

    printf("The Elements of Your Linked List are: ");
    traverse_list(head);

    // printf("\nInput Element that you want to insert at the begining: ");
    // scanf("%d",&element);
    // head=insert_begin(head,element);
    // printf("\nThe Elements of Your Linked List are: ");
    // traverse_list(head);

    // printf("\nInput Element that you want to insert: ");
    // scanf("%d",&element);
    // head=insert_bw(head,element,1);
    // printf("\nThe Elements of Your Linked List are: ");
    // traverse_list(head);
    
    // printf("Input Element That you want to insert at the End: ");
    // scanf("%d",&element);
    // head=insert_end(head,element);
    // printf("\nThe Elements of Your List are: ");
    // traverse_list(head);

    printf("Input Element That you want to insert: ");
    scanf("%d",&element);
    head=insert_after(head,second,element);
    printf("\nThe Elements of Your List are: ");
    traverse_list(head);
    // deallocating the memory
    struct Node* temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}



