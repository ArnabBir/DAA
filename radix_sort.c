/* ARNAB BIR
   ROLL NO.-14MA20009
   DAA HOMEWORK
   RADIX_SORT
*/


#include<stdio.h>
#define MAX 100

void radix_sort(int a[], int size)
{
    int i, c[10],b[MAX]={0},max=a[0],exponent=1;
    for (i =1;i<size;++i)
    {
        if (a[i]>max)
            max=a[i];
    }

    while(max/exponent>0)
    {
        for(i=0;i<10;++i)
            c[i]=0;

        for(i=0;i<size; ++i)
            c[(a[i]/exponent)%10]=c[(a[i]/exponent)%10]+1;

        for(i=1;i<10;++i)
            c[i]+=c[i - 1];

        for(i=size-1;i>=0;--i)
        {
            b[c[(a[i]/exponent)%10]-1]=a[i];
            c[(a[i]/exponent)%10]=c[(a[i]/exponent)%10]-1;
        }

        for(i=0;i<size;++i)
            a[i]=b[i];
            exponent*=10;
    }
}

int main() {
    int arr[MAX]={0};;
    int i, n;

    printf("Enter total number of elements:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter %d th Elements:\n", (i+1));
        scanf("%d", &arr[i]);
    }

    radix_sort(&arr[0], n);

    printf("After radix sort\n:");

    for (i = 0; i < n;++i)
        printf("%d\t", arr[i]);
    return 0;
}
