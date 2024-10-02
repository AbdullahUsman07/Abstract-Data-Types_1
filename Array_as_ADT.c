#include<stdio.h>
#include<stdlib.h>

struct MyArray{
    int *arr;
    int used_size;
    int total_size;
};

void display(struct MyArray* arry)
{
    for(int i=0;i<arry->used_size;i++)
    {
        printf("%d ",arry->arr[i]);
    }
}

void createArray(struct MyArray* arry,int t_size,int u_size)
{
    arry->arr=(int*)malloc(t_size*sizeof(int));
    arry->used_size=u_size;
    arry->total_size=t_size;
}

void input(struct MyArray* arry)
{
    for(int i=0;i<arry->used_size;i++)
    {
        printf("Input element no %d ",i+1);
        scanf("%d",&arry->arr[i]);
    }
}



int main()
{
    struct MyArray marks;
    int t_size,u_size;
    printf("Input The Size of your Array: ");
    scanf("%d",&t_size);
    printf("Input how many elements you want to input: ");
    scanf("%d",&u_size);
    createArray(&marks,t_size,u_size);
    input(&marks);
    printf("Your Array Is: \n");
    display(&marks);
    free(marks.arr);
    return 0;
}