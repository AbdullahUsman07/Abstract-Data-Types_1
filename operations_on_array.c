//   These Operations will invlove Deleteing and Inserting an element in array

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void display(int arr[], int sz)
{
    for(int i=0;i<sz;i++)
    {
        printf("%d ",arr[i]);
    }
}

void input(int arr[],int sz)
{
    for(int i=0;i<(sz);i++)
    {
        printf("Input element no: ",i+1);
        scanf("%d",&arr[i]);
    }
}

void insert(int arr[],int *sz,int val,int index)
{
   for(int i=(*sz);i>=index;i--)
   {
      arr[i+1]=arr[i];
   }
   arr[index]=val;
   (*sz)++;
}

void delet(int arr[],int *sz,int index)
{
    for(int i=index;i<(*sz);i++)
    {
        arr[i]=arr[i+1];
    }
    (*sz)--;
}

int main()
{
    const int SIZE=10;

    int arry[SIZE], sz,index,val;
    char choice;
    do{
    printf("Input the size of array(1-10): ");
    scanf("%d",&sz);
    }while(sz>10&&sz<1);

    printf("Input Elements in Your Array: \n");
    input(arry,sz);

    printf("\nYour Array is: \n");
    display(arry,sz);

    printf("Do You Want to Insert or Delete an Element From the Array [Y/N] \n");
    getchar();
    scanf("%c",&choice);
    if(choice=='Y'||choice=='y')
    {
        printf("For Insert Input [I/i]:\nFor Delete Input [D/d]: ");
        scanf("%c",&choice);
        if(choice=='I'||choice=='i')
        {
            printf("Input the index where do you wanna insert the element: ");
            scanf("%d",&index);
            printf("Input value that you wanna insert: ");
            scanf("%d",&val);
            insert(arry,&sz,val,index);
        }
        else if(choice=='D'||choice=='d')
        {
            printf("Input index that you wanna delete: ");
            scanf("%d",&index);
            delet(arry,&sz,index);
        }
        else
        {
            printf("You entered wrong key.");
        }
    }

    printf("\nArray after modifiction will be:\n ");
    display(arry,sz);
    return 0;
}

