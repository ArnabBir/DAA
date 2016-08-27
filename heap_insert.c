#include<stdio.h>
#define MAX 100

adjust_up(int a[],int index)
{
    int temp;

    if(index<2)
        return;

    if(a[index]<a[index/2])
    {
        temp=a[index];
        a[index]=a[index/2];
        a[index/2]=temp;
    }

    adjust_up(a,index/2);
}

void insert_key(int a[], int key)// a[0] stores the size of the array
{
    a[a[0]+1]=key;
    ++a[0];
    adjust_up(a,a[0]);
}

int main()
{
    int arr[MAX], i, x, k;
    arr[0]=0;
    do
    {
        printf("Enter your choice:\n1.Insert key:\n2.Print heap:\n3.End:\n");
        scanf("%d", &i);
        switch(i)
        {
        case 1:
            printf("Enter the key:\n");
            scanf("%d", &x);
            insert_key(arr,x);
            break;
        case 2:
            printf("The current heap:\n");
            for(k=1;k<=arr[0];++k)
                printf("%d\t", arr[k]);
            printf("\n");
            break;
        case 3:
            break;
        default:
            printf("Invalid input!\n");
        }
    }while(i!=3);

    return 0;
}
