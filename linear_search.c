#include<stdio.h>
#define MAX 50
int main()
{
	int n,i,A[MAX],x,result=0;
	printf("Enter the value of n:\n");
	scanf("%d", &n);

	printf("Enter the array:\n");
	for(i=0;i<n;++i)
		scanf("%d", &A[i]);

	printf("Enter x:\n");
	scanf("%d", &x);

	for(i=0;i<n;++i)
		{
			if(A[i]==x)
				result=1;
		}
	printf("\n%d\n", result);
	
	return 0;
}

		
