#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void traverse_list(struct Node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

// Case 1: Deleting the First Node  
struct Node* del_first(struct Node* head)
{
    struct Node*temp=head;
    head=head->next;
    free(temp);
    return head;
}

// Case 2: Deleting the Last Node
struct Node* del_end(struct Node* head)
{
    struct Node* p=head;
    struct Node* q=head->next;
    while(q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

// Case 3: Deleting a Key Value
struct Node* del_val(struct Node* head, int data)
{
    if(head->data==data)
    {
        head=del_first(head);
        return head;
    }
    struct Node* p=head;
    struct Node* q=head->next;

    while(q->data!=data&&q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    
    // check if the value exist at the last element
    if(q->data==data)
    {
        p->next=q->next;
        free(q);
    }
    return head;
}

// Case 4: Deleting the node at the given index
struct Node* del_index(struct Node*head,int index)
{
    struct Node* p=head;
    struct Node* q=head->next;
    int i=0;
    while(i!=index-1)
    {
        q=q->next;
        p=p->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}

int main()
{
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    head=first;

    int element;
    printf("Input First element that you want in your List: ");
    scanf("%d",&element);
    first->data=element;
    first->next=second; 

    printf("Input Second element that you want in your List: ");
    scanf("%d",&element);
    second->data=element;
    second->next=third; 

    printf("Input Third element that you want in your List: ");
    scanf("%d",&element);
    third->data=element;
    third->next=fourth;

    printf("Input Fourth element that you want in your List: ");
    scanf("%d",&element);
    fourth->data=element;
    fourth->next=NULL;

    printf("The Elements of Your List are: \n");
    traverse_list(head);

    // head=del_first(head);
    // head=del_end(head);
    // head=del_val(head,4);
    head=del_index(head,2);
    printf("\nThe Element of your After deletion List are: ");
    traverse_list(head);

    struct Node* temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }

    return 0;
}
