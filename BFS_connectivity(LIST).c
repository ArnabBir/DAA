#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define WHITE 1
#define GREY 2
#define BLACK 3

#define INFINITY 994353

#define NIL -2


struct queue
{
    int a[MAX];
    int start;
    int end;
};

struct node
{
    int data;
    struct node * next;
};

struct node * array[MAX];
struct queue * q;
//q->start=-1;
//q->end=-1;
/*
void enque(struct queue * q,int x)
{
    q->a[q->end++]=x;
}

int dequeue(struct queue * q)
{
    return q->a[q->start++];
}*/

int isempty(struct queue * q)
{
    if(q->end==-1)
        return 1;
    else
        return 0;
}

int isfull(struct queue * q)
{
    return (q->end==MAX-1);
}

void enqueue(struct queue * q, int x)
{
    if(isfull(q))
    {
        printf("Error:Queue is full\n");
        return;
    }

    if(q->end==-1)
    {
        q->start=0;
        q->end=0;
        q->a[q->end]=x;

    }
    else
        q->end=q->end+1;
        q->a[q->end]=x;
}

int dequeue(struct queue * q)
{
    int x;
    if(isempty(q))
    {
        printf("Error: Queue is empty\n");
        return;
    }
    if(q->start==q->end)
    {

        --q->start;
        x=q->a[q->end--];
    }
    else
    {
        x=q->a[q->end--];
    }
    return x;
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

void BFS(int s, int size)
{
    q=malloc(sizeof(struct queue));

    struct node * temp=malloc(sizeof(struct node));

    int d[MAX];
    int pi[MAX];
    int color[MAX];
    int u,v, node=0;

    for(u=1;u<=size;++u)
    {
        d[u]=INFINITY;
        color[u]=WHITE;
        pi[u]=NIL;
        //printf("%d ", d[u]);
    }

    q->start=-1;
    q->end=-1;

    d[s]=0;
    color[s]=GREY;

    enqueue(q,s);
    q->start=0;
    q->end=0;
    printf("\nq->end=%d\n\n", q->end);

    printf("\n   %d   \n", isempty(q));

    while(!isempty(q))
    {
        printf("\n\n%d\n", isempty(q));
        u=dequeue(q);
        for(temp=array[u-1];temp!=NULL;temp=temp->next)
        {
            color[temp->data-1]=GREY;
            v=temp->data;
            if(color[v]==WHITE)
            {
                color[v]=GREY;
                d[v]=d[u]+1;
                enqueue(q,v);
                pi[v]=u;
                ++node;
            }
        }
        color[u]=BLACK;


    }

    /*for(node=0;node<size;++node)
        if(d[node]==INFINITY)
            break;*/

    for(u=1;u<=size;++u)
    {
        //d[u]=INFINITY;
        //color[u]=WHITE;
        printf("%d ", d[u]);
        printf("%d ", color[u]);
    }

    if(node==size-1)
        printf("Graph is connected.");
    else
        printf("Graph is not connected.");
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
    printf("\nEnter the index to check connectivity:");
    scanf("%d", &i);
    BFS(i,n);

    return 0;
}
