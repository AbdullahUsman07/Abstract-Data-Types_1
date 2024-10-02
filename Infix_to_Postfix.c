#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int size;
    int top;
    char *arr;
};

int stack_top(struct Stack *stack)
{
    return stack->arr[stack->top];
}

int isEmpty(struct Stack *stack)
{
    if(stack->top<0)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *stack)
{
    if(stack->top == stack->size-1)
    {
        return 1;
    }
    return 0;
}

void push(struct Stack *stack,int data)
{
    if(!isFull(stack)){
       stack->top++;
       stack->arr[stack->top]=data;
       return;
    }
    printf("Stack Overflow!");
}

int pop(struct Stack *stack)
{
    if(!isEmpty(stack))
    {
        int temp=stack->top;
        stack->top--;
        return stack->arr[temp];
    }
    printf("Stack Underflow!");
    return -1;
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    return 0;
}

int precedence(char op)
{
    if(op=='+' || op=='-')
    {
        return 2;
    }
    if(op=='/' || op=='*')
    {
        return 3;
    }
    return 0;
}

char *InfixToPostfix(char *infix)
{
    char *postfix=(char *)malloc((strlen(infix)+1)*sizeof(char));
    struct Stack *stack=(struct Stack*)malloc(sizeof(struct Stack));
    stack->top=-1;
    // We are assuming the max size would be equal to size of infix expression
    stack->size=strlen(infix);
    stack->arr=(char*)malloc(stack->size*sizeof(char));

    // two counters 1 will traverse through infinix and 2 will help in the creation of postfix
    int i=0,j=0;
    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else
        {
            while(!isEmpty(stack) && precedence(stack_top(stack))>=precedence(infix[i]))
            {
                postfix[j]=pop(stack);
                j++;
            }
        
            push(stack,infix[i]);
            i++;

        }
    }
    // now write all the operators in front of the postfix expression present in the Stack
    while(!isEmpty(stack))
    {
        postfix[j]=pop(stack);
        j++;
    }
    postfix[j]='\0';

    free(stack->arr);
    free(stack);
    return postfix;
}

int main()
{
    char *infix="a+b*p/q";
    printf("The Infix Form of Expression is %s\n",infix);
    printf("The Postfix Form of Expressio  is %s",InfixToPostfix(infix));
    return 0;
}