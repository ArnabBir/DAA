#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define new_node (struct node*)malloc(sizeof(struct node))
#define max 1000

struct node
{
    int vertex;
    struct node *next;
};

struct stack
{
    int a[max];
    int top;
};
struct stack *s;

void push(struct stack *s,int i)
{
    if(s->top < max -1)
    {
        s->top = s->top + 1;
        s->a[s->top] = i;
    }
}

int pop(struct stack *s)
{

    if(s->top != -1)
    {
        s->top = s->top - 1;
        return(s->a[s->top+1]);
    }
}

int top(struct stack *s)
{
    return s->a[s->top];
}

int isempty(struct stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    else return 0;
}

void dfs(struct node* a[],int vertex)
{
    int v , count , x, y, temp;
    struct node *p;
    int dfn[max] , visited[max] ,parent[max] ;
    for(v  = 1;v <= vertex;v++)
    {
        dfn[v] = 0;
        visited[v] = 0;
        parent[v] = -1;
    }
    count = 1;
    push(s,1);
    visited[1] = 1;
    dfn[1] = count++;
    parent[1] = 1;
    printf("1 ");
    while(isempty(s) != 1)
    {
        x = top(s);
        p = a[x];
        while(p != NULL)
        {
            y = p->vertex;
            if(visited[y] == 0)
            {
                printf("%d ",y);
                dfn[y] = count++ ;
                visited[y] = 1;
                parent[y] = x;
                push(s,y);
            }
            else temp = pop(s);
            p = p->next ;
        }

    }
}

int main()
{
    int vertex,i,j,key;
    s = (struct stack*) malloc (sizeof(struct stack));
    s->top = -1;
    printf("Enter the number of vertex.\n");
    scanf("%d",&vertex);
    struct node* a[max] , *p ,*c;
    for(i = 0 ;i <= vertex;i++)
    {
        a[i] = NULL;
    }
    for(i = 1;i <= vertex;i++)
    {
        printf("Enter the number of vertexes adjacent to %d \n",i );
        scanf("%d",&j);
        while(j != 0)
        {
            printf("Enter the adjacent edges.\n");
            scanf("%d",&key);
            c = new_node;
            c -> vertex = key;
            c -> next = NULL;
            if(a[i] == NULL)
            {
                a[i]= c;
            }
            else
            {
                p = a[i];
                while ( p -> next != NULL )
                {
                    p = p -> next;
                }
                p -> next = c;
            }
            j = j-1;
        }
    }
    for(i = 1;i <= vertex;i++)
    {
        printf("%d", i);
        p = a[i];
        while ( p != NULL )
            {
                printf("->%d",p->vertex);
                p = p -> next;
            }
        printf("\n");
    }
    dfs(a,vertex);
    return 0;
}
