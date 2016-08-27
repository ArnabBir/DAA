#include <stdio.h>
#include <malloc.h>

int i,l;
int a[2000];
int heap[2000];
int filled=1;

int lchild(int k){int h=2*k  ;return h;}
int rchild(int k){int h=2*k+1;return h;}
int parent(int k){int h=k/2;  return h;}

void swap(int a[],int i,int j){int temp=a[i];a[i]=a[j];a[j]=temp; }


void adjustup(int k){int par=parent(k);int parval=heap[par];
                     while(parval>heap[k] && k>1)
                     {swap(heap,k,k/2); k=k/2;par=parent(k); parval=heap[par];  }
 }

void adjustdown(int k){int lch=lchild(k);lch=heap[lch];int rch=rchild(k);rch=heap[rch];int me=heap[k]; int flag=1;


                     while(me>lch || me >rch )
                     { if(lch<rch)flag=1;else flag=2;
                       if(flag==1){swap(heap,k,(lchild(k)));k=lchild(k);}
                       else       {swap(heap,k,(rchild(k)));k=rchild(k);}
                       lch=lchild(k);lch=heap[lch];  rch=rchild(k);rch=heap[rch];   me=heap[k];
                     }

 }

void insertkey(int k)
{
   heap[filled]=k;             // now we filled the nth thing with k and then we adjust
   adjustup(filled);
   filled++;
}

void increasekey(int m,int k)
{
    heap[m]=k;
    adjustdown(m);
}

void decreasekey(int m,int k)
{
    heap[m]=k;
    adjustup(m);
}

int deletemin()
{
    int min=heap[1];
    swap(heap,1,filled);
    heap[filled]=1000;   // we swap and fill the end with dummy
    adjustdown(1);
    filled--;
    return min;

}
int heapsort(int n)   // here n is the size of the heap
{
   for(i=1;i<=n;i++){int min=deletemin();printf("%d ",min);};printf("\n");
}

void heapify(int n)
{
  int j,m;filled=n;
  for(m=2;m<n/2+1;m++){j=n/2+1-m;
                     int lch=lchild(j);lch=heap[lch];int rch=rchild(j);rch=heap[rch];int me=heap[j];
                     if(me>lch || me >rch)adjustdown(j);}
 // for(i=1;i<21;i++)printf("%d ",heap[i]);

}

int main()
{
    int size;
    printf("insert the size of the array\n"); scanf("%d",&size);
    for(i=0;i<size;i++)a[i]=rand()%555;
    for(i=0;i<size;i++)printf("%d ",a[i]);printf("\n");
    for(i=0;i<size*5;i++)heap[i]=1000;                      // the initial dummy value
//  line 85 and 84 are two ways of making a heap
//  for(i=0;i<size;i++)insertkey(a[i]);                    // n(logn)
    for(i=1;i<size+1;i++)heap[i]=a[i-1];heapify(size);         // n


    printf("This is the heap formed after insert operation\n");
    for(i=1;i<size;i++)printf("%d ",heap[i]);printf("\n");
  //  for(l=1;l<5;l++) {int n,m;scanf("%d %d",&n,&m);increasekey(n,m);}      Queries for increase key
  //  for(i=1;i<5;i++){int min=deletemin();printf("%d\n",min);};             Queries for delete min
    printf("This is the heap sort result\n");
    heapsort(size);

}
