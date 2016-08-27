#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node * next;
};
struct node * head, * var;

void insert_at_begning(int x)//number would be added at the beginning  of the list
{
     var=(struct node *)malloc(sizeof (struct node));
     var->data=x;
     if(head==NULL)
     {
         head=var;
         head->next=NULL;
     }
     else
     {
        var->next=head;
        head=var;

     }
}

void insert_at_end(int x)//number would be added at the end of the list
{
      struct node *temp;
      temp=head;
      var=(struct node *)malloc(sizeof (struct node));
      var->data=x;
      if(head==NULL)
      {
          head=var;
          head->next=NULL;
      }
      else
      {
          while(temp->next!=NULL)
          {
               temp=temp->next;
          }
          var->next=NULL;
          temp->next=var;
      }
}

int search(int key)
{
	struct node * temp1;
	int i=1;
	temp1=head;
	while(temp1!=NULL)
	{
		if(temp1->data==key)
			return i;
		++i;
		temp1=temp1->next;
	}
	return 0;
}

int main()
{
	int n,i,p,k=1;
	head=NULL;

	while(k)
	{
	printf("Enter your choice:\n1:Insert at begining\n2:Insert at end\n3:search\n4:End\n");
	scanf("%d", &n);

	switch(n)

	{	case 1:
		printf("Enter the integer:\n");
		scanf("%d", &i);
		insert_at_begning(i);
		break;

		case 2:
		printf("Enter the integer:\n");
		scanf("%d", &i);
		insert_at_end(i);
		break;

		case 3:
		printf("Enter the integer:\n");
		scanf("%d", &i);
		p=search(i);
		if(p)
			printf("Position of the integer:%d\n",p);

		else
		printf("Not found\n");
		break;

		case 4:
		k=0;
		break;

		default:
		printf("Invalid input\n");
	}
	}
return 0;
}






