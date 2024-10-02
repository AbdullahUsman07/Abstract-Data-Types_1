#include<stdio.h>
#include<stdlib.h>


// Parenthesis Matching Problem
// if opening brace '(' is found push it into the stack
// if closing brace ')' is found pop it out of the stack

// Conditions for Balanced Parenthesis
// 1-While Poping stack must not overflow
// 2-At the End of Expression ('\0') stack must be empty

struct Node{
    char data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *pop(struct Node *top)
{
    if(!isEmpty(top))
    {
        struct Node *temp=top;
        top=top->next;
        free(temp);
        return top;
    }
    return top;
}

struct Node *push(struct Node *top,char ch)
{
    struct Node *new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=ch;
    new_node->next=top;
    return new_node;
}

void dealloc(struct Node *top)
{
    struct Node *temp;
    while(top!=NULL)
    {
        temp=top;
        top=top->next;
        free(temp);
    }
}

char stack_top(struct Node *top)
{
    return top->data;
}

int match(char c1,char c2)
{
    if(c1=='(' && c2==')')
    {
        return 1;
    }
    if(c1=='[' && c2==']')
    {
        return 1;
    }
    if(c1=='{' && c2=='}')
    {
        return 1;
    }
    return 0;
}

int check_parenthesis(char *exp)
{
    // Creating a new Stack
    struct Node *stack=NULL;

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            stack=push(stack,exp[i]);
        }
        else if(exp[i]==')' ||exp[i]=='}' ||exp[i]==']')
        {
            if(!isEmpty(stack) && match(stack->data,exp[i]) )
            // Make sure that stack underlfow does not occur
                stack=pop(stack);
            else
            {
                dealloc(stack);
                return 0;
            }
        }
    }
    // at the end if the stack is empty then braces are balenced
    int result=(isEmpty(stack));
    dealloc(stack);
    return result;
}

int main()
{
    char *expression;
    expression="{(a+b)+[[[(8+9)]]}";
    if(check_parenthesis(expression)==1)
    {
        printf("%s\n",expression);
        printf("Parenthesis are balaned in this expression!");
    }
    else
    {
        printf("%s\n",expression);
        printf("Parenthesis are not balaned in this expression!");
    }
    return 0;
}