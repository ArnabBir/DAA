#include<stdio.h>
#include<stdlib.h>

#define MAX 100

struct node
{
    int data;
    struct node * next;
};

//struct node * array[MAX];

struct node * init(int x)
{
    struct node * new_node;
    new_node=(struct node * )malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=NULL;
    return new_node;
}
/*
void insert(struct node * list, int x)
{
    list->data=x;
    list->next=NULL;
}*/

int main()
{
    int n,k,i,j,node;
    struct node * array[MAX]={NULL}, * temp;

    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    //array=(struct node * )malloc(n*sizeof(struct node));
    //temp=(struct node * )malloc(sizeof(struct node));

    //for(i=0;i<n;++i)
      // array[i]=init(i+1);

    for(i=0;i<n;++i)
    {
        printf("Enter the number of nodes connected to %d th node:\n", i+1);
        scanf("%d", &k);
        array[i]=( struct node * )malloc((k+1)*sizeof(struct node));

        printf("Enter the indices of the nodes:\n");

        //temp=init(node);
        //temp=init(i+1);

        for(j=0;j<k;++j)
        {
            scanf("%d", &node);
            if(array[i]==NULL)
                array[i]=init(node);
            else
            {
                temp=array[i];

                while(temp->next!=NULL)
                    temp=temp->next;

                temp->next=init(node);
            }

            //insert(temp->next,node);
            //temp=temp->next;
        }
    }

      printf("Adjacency list:\n");

    for(i=1;i<=n;++i)
    {
        printf("\nNodes connected %d th node:", i+1);
        temp=array[i-1];

        for(j=1;j<=n;++j)
        {
            printf("%d  ", temp->data);
            temp=temp->next;
        }

        printf("\n");
    }

    return 0;
}
