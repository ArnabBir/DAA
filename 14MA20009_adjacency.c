// Adjacency matrix

#include<stdio.h>
#define MAX 100

int main()
{
    int a[MAX][MAX]={0};
    int i,j,n,k,node,index,degree=0,response,u,v,edges=0;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    for(i=1;i<=n;++i)
    {
        printf("Enter the number of nodes connected to %d th node:\n", i);
        scanf("%d", &k);

        printf("Enter the indices of the nodes:\n");

        for(j=1;j<=k;++j)
        {
            scanf("%d", &node);
            a[i-1][node-1]=1;
            //printf("\n%d\n",a[i-1][node-1]);
            a[node-1][i-1]=1;
        }
    }

    /*for(i=0;i<n;++i)
    //{
        for(j=0;j<n;++j);
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    //}*/
    do
    {
    printf("Enter the index of the node to find degree:\n");
    scanf("%d", &index);


    for(i=1;i<=MAX;++i)
        degree+=a[index-1][i-1];
    printf("Degree of %d th index: %d", index,degree);
    degree=0;
    printf("\nWant to repeat?(1/0)\n");
    scanf("%d", &response);
    }
    while(response);


   do
   {
    printf("Enter the indices u and v:\n");
    scanf("%d", &u);
    scanf("%d", &v);

        if(a[u-1][v-1])
            printf("Yes, it is an edge.");
        else
            printf("No, it is not an edge.");
        printf("\nWant to repeat?(1/0)\n");
        scanf("%d", &response);
   }while(response);

   printf("Number of edges of G:\n");
   for(i=0;i<n;++i)
   {
       for(j=0;j<n;++j)
       {
           if(a[i][j])
                ++edges;
       }
   }
   edges/=2;
   printf("%d\n", edges);

    return 0;
}
