#include<stdio.h>
#include <stdlib.h>

#define MAX 100
#define white 0
#define grey 1
#define black 2
#define infinity 99685
#define nil 2*(-1)

struct que
{
    int a[MAX];
    int start;
    int end;
};

struct que * q1;

void enq(struct que *q,int c)
{
    if(q->end < 99)
    {
        q->end = q->end + 1;
        q->a[q->end] = c;
    }
}

int deq(struct que *q)
{
    if(q->start <= q->end)
    {
        q->start = q->start +1;
        return q->a[q->start-1];
    }
}



void BFS(int a[MAX][MAX],int s,int vertex)
{
    int u = 1;
    int v;
    int i;
    int d[MAX];
    int pi[MAX];
    int colour[MAX];

    while(u <= vertex)
    {
       if(u != s)
       {
       d[u]= infinity;
       pi[u]= nil;
       colour[u] = white;
       }
       u = u+1;
    }
    colour[s]=grey;
    d[s]=0;
    pi[s]=nil;
    enq(q1,s);
    while(q1->start <= q1->end)
    {
        u = deq(q1);
        for(i = 1;i <= vertex;i++)
        {
            if(a[i][u] == 1)
            {
                v = i;
                if(colour[v] == white)
                {
                    colour[v] = grey;
                    d[v] = d[u] + 1 ;
                    pi[v] = u;
                    enq(q1,v);
                }
            }
        }
        colour[u] = black;
    }
    if(s==1)
    {
        int chk ;
        chk = 0;
        for(i = 1; i <=vertex ;i++)
        {
            if(d[i] != infinity)chk++;
        }
        if(chk == vertex)
        {
            printf("The graph is connected.\n");
        }
        else
        {
            printf("The graph is not connected.\n");
        }
    }
    printf("Distances with respect to %d are : ",s);
    for(i = 1; i <=vertex ;i++)
        {
            printf("%d ",d[i]);
        }
    printf("\n");
}
/*void BFS(int a[MAX][MAX],int size)
{
    struct que * q;

    int x=1;
    int u,v,i,key=0;
    int color[MAX]={0},d[MAX],pi[MAX];

    q->start=0;
    q->end=0;

    for(u=1;u<size;++u)
    {
        color[u]=white;
        d[u]=infinity;
        pi[u]=null;
    }

    color[0]=gray;
    d[0]=0;
    pi[0]=null;

    enque(q,1);


    while(q->end>=q->start)
    {
        u=deque(q);
        for(v=0;v<size;++v)
        {
            if(a[u-1][v]!=0)
            {
                if(color[v]==white)
                    {
                        color[v]=gray;
                        d[v]=d[u-1]+1;
                        pi[v]=u-1;
                        enque(q,v);
                    }
            }

        }
        color[u-1]=black;
    }

        for(u=0;u<size;++u)
        {
            if(color[u]!=black)
            x=0;
            break;
        }

        for(i = 1; i <=size ;i++)
        {
            if(d[i]!=infinity)
                ++key;
        }
        if(key==size)
            printf("The graph is connected.\n");
        else
            printf("The graph is not connected.\n");

}*/


int main()
{
    int a[MAX][MAX]={0};
    int color[MAX],d[MAX];
    int i,j,n,k,node,index,u,v,result=0;

    q1 = (struct que*) malloc (sizeof(struct que));
    q1->start = 0;
    q1->end = -1;

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
            a[i][node]=1;
            a[node][i]=1;
        }
    }

    printf("Adjancency matrix:\n");

    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            printf("%d  ", a[i][j]);
           // printf("%d  ", a[i][j]);
        }
        printf("\n");
    }

   for(i=1;i<=n;++i)
        BFS(a,i,n);


    return 0;
    }
