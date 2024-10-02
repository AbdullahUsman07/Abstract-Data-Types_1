#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node*next;
};


// Method to Traverse in the Linked List
void travesre_list(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    struct Node*head;
    struct Node*first;
    struct Node*second;
    struct Node*third;

    // Allocating the memory
    first=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));

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
    third->next=NULL;

    printf("The elements of your Linked List are: ");
    travesre_list(head);

    //deallocating the memory
    free(first);
    free(second);
    free(third);

    return 0;
}