#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct Stack *s)
{
    if(s->top==s->size-1)
    {
      return 1;
    }
    return 0;
}

int isEmpty(struct Stack *s)
{
    if(s->top<0)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *s,int val)
{
    if(isFull(s))
    {
        printf("Stack Overflow!");
        return;
    }
    s->top++;
    s->arr[s->top]=val;
}

int pop(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow!");
        return -1;
    }
    int val=s->arr[s->top];
    s->top--;
    return val;
}

int peek(struct Stack *s,int i)
{
    int arrIndex= s->top-i+1;
    if(arrIndex<0)
    {
        printf("Invalid Position!");
        return -1;
    }
    else
      return s->arr[arrIndex];
}

int stackTop(struct Stack *s)
{
    return s->arr[s->top];
}

int stackBottom(struct Stack *s)
{
    return s->arr[0];
}

int main()
{
    struct Stack *s=(struct Stack*)malloc(sizeof(struct Stack));
    int element;
    printf("input the Size of Your Stack: ");
    scanf("%d",&s->size);
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    
    for(int i=0;i<s->size;i++)
    {
    printf("Input element that you want to push in Stack: ");
    scanf("%d",&element);
    push(s,element);
    }

    if(isFull(s))
    {
        printf("Your Stack is Full.\n");
    }

    for(int i=1;i<=s->top+1;i++)
    {
        printf("The element of stack at %d is %d\n",i,peek(s,i));
    }
    free(s->arr);
    free(s);
    return 0;
}