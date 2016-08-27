#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define WHITE 1
#define GREY 2
#define BLACK 3

#define INFINITY 994353

#define NIL -2

struct node
{
    int data;
    struct node * next;
};

struct node * array[MAX];


/*
struct stack
{
    int a[MAX];
    int top;
};*/
/*
void explore(int u, int f[], int size)
{
    int i,j,k=0,temp,max=f[0];
    printf("Order of visiting:\t");

    for(i=0;i<size;++i)
    {
        for(j=0;j<size;++j)
        {
            if(f[i]>max)
            {
                max=f[i];
                k=i;
            }
        }
        printf("%d  ", k+1);
        f[k]=-1;
    }
}*/

void DFS_VISIT(int u,int time, int color[],int pi[],int d[],int f[], int size)
{

    struct node * temp=malloc(sizeof(struct node));

    printf("%d ", u+1);
    color[u]=GREY;
    ++time;
    d[u]=time;
    temp=array[u];

        while(temp!=NULL)
        {
            if(color[temp->data-1]==WHITE)
            {
                pi[temp->data-1]=u+1;
                DFS_VISIT(temp->data-1,time,color,pi,d,f,size);
            }
            temp=temp->next;
        }

    color[u]=BLACK;

    ++time;
    f[u]=time;

}

void DFS(int size)
{
    int u,time,i=0;
    int d[MAX],f[MAX];
    int color[MAX], pi[MAX];


    for(u=0;u<size;++u)
    {
        color[u]=WHITE;
        pi[u]=NIL;
    }

    time=0;
    for(u=0;u<size;++u)
    {
        if(color[u]==WHITE)
            DFS_VISIT(u,time,color,pi,d,f,size);
    }

   /* for(u=0;u<size;++u)
            if(color[u]==BLACK)
                ++i;
       if(time==size)
        {
            printf("\nGraph is connected.\n");
            //explore(u,f,size);
        }
        else
            printf("\nGraph is not connected.\n");*/


}






struct node * init(int x)
{
    struct node * new_node;
    new_node=(struct node * )malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=NULL;
    return new_node;
}

void insert(int i, int j)
{
    struct node * temp;
    if(array[i-1]==NULL)
        array[i-1]=init(j);
    else
    {
        temp=array[i-1];
            while(temp->next!=NULL)
                temp=temp->next;
        temp->next=init(j);
    }
}

int main()
{
    int i,j,n,k,node,no_of_edges,vi,vj;
    struct node * temp;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    for(i=0;i<n;i++)
        array[i]=NULL;

    printf("\nEnter no of edges:\n");
    scanf("%d",&no_of_edges);

    for(i=0;i<no_of_edges;i++)
    {
        printf("\nEnter an edge (u,v):\n");
        scanf("%d%d",&vi,&vj);
        insert(vi,vj);
        insert(vj,vi);
    }

   /* printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    for(i=1;i<=n;++i)
    {
        printf("Enter the number of nodes connected to %d th node:\n", i);
        scanf("%d", &k);
        array[i-1]=(struct node * )malloc(k*sizeof(struct node));

        printf("Enter the indices of the nodes:\n");

        for(j=1;j<=k;++j)
        {
            scanf("%d", &node);
            insert(i,node);
            insert(node,i);
        }
    }*/


    printf("Adjacency list:\n");

    for(i=0;i<n;++i)
    {
        //array[i]=(struct node * )malloc(k*sizeof(struct node));
        temp=array[i];
        printf("Nodes connected to %d th node: ", i+1);
        while(temp!=NULL)
        {

            printf("%d  ", temp->data);
            temp=temp->next;
           // printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
    printf("Order of traversing:\n");

    DFS(n);

    return 0;
}
