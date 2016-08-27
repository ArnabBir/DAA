#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void adjust_down(int a[],int i,int maxsize)
{
    int t,temp,x;

    if(2*i>maxsize)
    return;

    if(a[2*i]<a[2*i+1])
    {
        x=a[2*i];
        t=2*i;
    }

    else
    {
        x=a[2*i+1];
        t=2*i+1;
    }

    if(x<a[i])
    {
        temp=a[t];
        a[t]=a[i];
        a[i]=temp;
    }

    adjust_down(a,t,maxsize);

}
void heapify(int a[],int maxsize)
{
    int i;
    for(i=maxsize/2;i>0;--i)
        adjust_down(a,i,maxsize);
}


int main()
{
    int * arr,n,i;
    printf("Enter the number of inputs:\n");
    scanf("%d", &n);
    arr =(int *)malloc((n+1)*sizeof( int ));
    printf("Enter the integers:\n");

    for(i=1;i<=n;++i)
    {
        scanf("%d", &arr[i]);
    }

    heapify(arr,n);

    printf("After heap formation:\n");

    for(i=1;i<=n;++i)
    printf("%d  ", arr[i]);
    printf("\n");

    return 0;
}
