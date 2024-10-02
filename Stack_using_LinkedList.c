#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};


void traverse(struct Node *top)
{
    while(top!=NULL)
    {
        printf(" %d ",top->data);
        top=top->next;
    }
}

int isEmpty(struct Node *top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}

int isFull()
{
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *top,int data)
{
    struct Node *n=(struct Node *)malloc(sizeof(struct Node));
    if(n==NULL)
    {
        printf("Stack Overflow!");
    }
    n->data=data;
    n->next=top;
    top=n;
    
    return top;
}

struct Node *pop(struct Node *top)
{
    if(isEmpty(top)!=1)
    {
    struct Node *ptr=top;
    top=top->next;
    free(ptr);
    return top;;
    }
    printf("Stack Underflow!");
    return top;
}

int peek(struct Node *top,int pos)
{
    for(int i=0;i<(pos-1)&&top!=NULL;i++)
    {
        top=top->next;
    }
    if(top!=NULL)
    {
        return top->data;
    }
    return -1;
}

int stack_top(struct Node *top)
{
    return top->data;
}

int stack_bottom(struct Node *top)
{
    
    while(top->next!=NULL)
    {
        top=top->next;
    }
    return top->data;
}

int main()
{
    struct Node *stack;
    stack=NULL;
    stack=push(stack,99);
    stack=push(stack,98);
    stack=push(stack,97);

    printf("The Elements of The Stack are: \n");
    traverse(stack);
    stack=pop(stack);
    printf("\nThe Elements of The Stack are: \n");
    traverse(stack);

    while(stack!=NULL)
    {
        struct Node *temp=stack;
        stack=stack->next;
        free(temp);
    }

    return 0;
}