#include<stdio.h>
#include<stdlib.h>

// Insertion in a Circular Linked List
struct Node{
    int data;
    struct Node *next;
};

void traverse_list(struct Node *head)
{
     struct Node *temp=head;
     do
     {
        printf("%d ",temp->data);
        temp=temp->next;
     }while(temp!=head);
}

// -----------------------------Insertion--------------------------------
// Case no 1: Insertion at the Start
struct Node *insert_begin(struct Node *head,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    // p is at the end of the list
    p->next=ptr;
    ptr->next=head;
    // ptr becomes the new head
    return ptr;
}

// Case no 2: Insertion at the Index
struct Node *insert_index(struct Node *head,int data,int index)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    // A pointer to keep track of the list
    struct Node *p=head;
    ptr->data=data;
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

// Case no 3: Insertion at the End
struct Node *insert_end(struct Node *head, int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    // Now p is pointing to the head (we can also write head instead of p->next)
    ptr->next=head;
    p->next=ptr;
    return head;
}

// Case no 4: Insert After a Node
struct Node *insert_after(struct Node *head,struct Node *prev_node,int data)
{
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prev_node->next;
    prev_node->next=ptr;
    return head;
}

// --------------------Deletion-------------------------
// Case no 1: Deleting the First Node
struct Node *del_first(struct Node *head)
{
    struct Node *p1=head;
    // This will point at the second node
    struct Node *p2=head->next;
    // This will use for traversing
    struct Node *p3=head->next;
    while(p3->next!=head)
    {
        p3=p3->next;
    }
    // Now the last node is pointing at the second node
    p3->next=p2;
    free(p1);
    // returning the second node will automatically make it as head node
    return p2;
}

// Case no 2: Deleting the Last Node
struct Node *del_last(struct Node *head)
{
    struct Node *p1=head;
    struct Node *p2=head->next;
    while(p2->next!=head)
    {
        p2=p2->next;
        p1=p1->next;
    }
    // Now p1 is at the second last Node and p2 is at the last Node
    free(p2);
    p1->next=head;
    return head;
}

// Case no 3: Deleting by taking the key value as a parametre
struct Node *del_val(struct Node *head,int data)
{
    if(head->data==data)
    {
        head=del_first(head);
        return head;
    }
    struct Node *p1=head;
    struct Node *p2=head->next;
    while(p2->data!=data&&p2->next!=head)
    {
        p1=p1->next;
        p2=p2->next;
    }
    if(p2->data==data)
    {
        p1->next=p2->next;
        free(p2);
    }
    return head;
}

// Case no 4: Deleting when index is given
struct Node *del_index(struct Node *head,int index)
{
    int i=0;
    struct Node *p1=head;
    struct Node *p2=head->next;
    while(i!=index-1)
    {
        p2=p2->next;
        p1=p1->next;
        i++;
    }
    // Now p2 is at the index node which we want to delete
    p1->next=p2->next;
    free(p2);
    return head;
}

int main()
{
    struct Node *head;
    struct Node *first=(struct Node*)malloc(sizeof(struct Node));
    struct Node *second=(struct Node*)malloc(sizeof(struct Node));
    struct Node *third=(struct Node*)malloc(sizeof(struct Node));
    struct Node *fourth=(struct Node*)malloc(sizeof(struct Node));
    head=first;
    int element,index;
    printf("Input the element that you wamt to insert in the List: ");
    scanf("%d",&element);
    first->data=element;
    first->next=second;

    printf("Input the element that you wamt to insert in the List: ");
    scanf("%d",&element);
    second->data=element;
    second->next=third;

    printf("Input the element that you wamt to insert in the List: ");
    scanf("%d",&element);
    third->data=element;
    third->next=fourth;

    printf("Input the element that you wamt to insert in the List: ");
    scanf("%d",&element);
    fourth->data=element;
    fourth->next=head;

    printf("The elements of your Circular Linked List Before Deletion are: \n");
    traverse_list(head);

    printf("Input Index of the Node that you want to delete: ");
    scanf("%d",&index);
    head=del_index(head,index);
    printf("\nThe elements of your Circular Linked List After Deletion are: \n");
    traverse_list(head);

    struct Node *temp=head;
    struct Node *nxt;
    do{
        nxt=temp->next;
        free(temp);
        temp=nxt;
    }while(temp!=head);

    head=NULL;
    return 0;
}