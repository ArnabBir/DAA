#include<stdio.h>
#include<stdlib.h>

#define WHITE 1
#define GREY 2
#define BLACK 3

#define INFINITY 994353

#define NIL -2

#define MAX 100

struct queue
{
    int a[MAX];
    int start;
    int end;
};

void enque(struct queue * q,int x)
{
    q->a[q->end++]=x;
}

int dequeue(struct queue * q)
{
    return q->a[q->start++];
}

void BST(int a[MAX][MAX], int s,int size)
{
    int u,v;
    int color[MAX],d[MAX],pi[MAX];
    struct queue * q;
    q=(struct queue * )malloc(sizeof(struct queue));
    q->start=0;
    q->end=0;

    for(u=0;u<size;++u)
        {
            color[u]=WHITE;
            pi[u]=NIL;
            d[u]=INFINITY;
        }

    color[s-1]=GREY;
    pi[s-1]=NIL;
    d[s-1]=0;

    enque(q,s);

    while(q->start<q->end)
    {
        u=dequeue(q);
        for(v=0;v<size;++v)
        {
            if(a[u-1][v]==1)
                if(color[v]==WHITE)
                {
                    pi[v]=u-1;
                    color[v]=GREY;
                    d[v]=d[u-1]+1;
                    printf("%d\t", d[v]);
                    enque(q,v);
                }
        }
        color[u-1]=BLACK;
    }

    for(u=0;u<size;++u)
    {
        if(d[u]==INFINITY)
            break;
    }

    if(u==size)
    {
        printf("\nGraph is connected.\nDistances with respect to %d th node:\n", s);
        for(u=0;u<size;++u)
        {
                printf("%d\t", d[u]);
        }
    }
    else
        printf("\nGraph is not connected.\n");

}

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
            a[node-1][i-1]=1;
        }
    }

    BST(a,1,n);

    return 0;
}
