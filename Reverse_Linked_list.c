#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void travesre_list(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

// Function to reverse a Linked list
struct Node *reverse_list(struct Node *head)
{
    struct Node *prev_ptr=NULL;
    struct Node *curr_ptr=head;
    struct Node *next_ptr;

    while(curr_ptr!=NULL)
    {
        next_ptr=curr_ptr->next;
        curr_ptr->next=prev_ptr;

        prev_ptr=curr_ptr;
        curr_ptr=next_ptr;
    }
    return prev_ptr;
}

int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocating the memory
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head=first;
    
    int element;
    printf("Input First Element of the List: ");
    scanf("%d",&element);
    first->data=element;
    first->next=second;

    printf("Input Second Element of the List: ");
    scanf("%d",&element);
    second->data=element;
    second->next=third;

    printf("Input Third Element of the List: ");
    scanf("%d",&element);
    third->data=element;
    third->next=fourth;
    
    printf("Input Fourth Element of the List: ");
    scanf("%d",&element);
    fourth->data=element;
    fourth->next=NULL;


    printf("The elements of your Linked List are: ");
    travesre_list(head);

    printf("\nThe elements of your Linked List after reversal are: ");
    head=reverse_list(head);
    travesre_list(head);

    //deallocating the memory
    struct Node *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }

    return 0;
}