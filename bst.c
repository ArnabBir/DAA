#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
};


struct node * init()
{
    struct node * temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}

void insert(struct node * root, struct node * new_node)
{
    if(new_node->data < root->data)
    {
        if(root->lchild==NULL)
            root->lchild=new_node;
        else
            insert(root->lchild, new_node);
    }

    if(new_node->data > root->data)
    {
        if(root->rchild==NULL)
            root->rchild=new_node;
        else
            insert(root->rchild, new_node);
    }
}

void search(struct node * root, int key)
{
    struct node * temp;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data==key)
            break;
        if(temp->data > key && temp->lchild!=NULL)
                temp=temp->lchild;
        if(temp->data < key && temp->rchild!=NULL)
                temp=temp->rchild;
    }
    if(temp->data==key)
        printf("The element %d is found.", key);
    else
        printf("Not found!");
}

int main() {
   int i;
   int key;
   struct node * root, * new_node;
   root = NULL;

   printf("\nProgram For Binary Search Tree ");
   do {
      printf("\n1.Insert");
      printf("\n2.Search");
      printf("\n3.Exit");
      printf("\nEnter your choice :");
      scanf("%d", &i);

      switch (i) {
      case 1:
            new_node =init();
            printf("\nEnter The Element: ");
            scanf("%d", &new_node->data);

            if (root == NULL)
               root = new_node;
            else
               insert(root, new_node);
         break;

      case 2:
         printf("\nEnter Element to be searched :");
         scanf("%d", &key);

         search(root, key);
         break;
      }
   } while (i!= 3);
return 0;
}

