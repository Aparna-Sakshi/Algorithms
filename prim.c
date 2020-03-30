//prim's MST
//heaps implementation
#include<stdio.h>
#include<stdlib.h>



//priority queue
void swap(int* a,int* b)
{
	int temp;
	temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}
void min_heapify(int* a,int i,int n)
{
	
	if((2*i+1)>=n)
	{
		return;
	}
	
	if(a[2*i+1]<a[2*i+2])
	{
		if(a[2*i+1]<a[i])
		{
			swap(&a[2*i+1],&a[i]);
			min_heapify(a,2*i+1,n);
		}
	}
	else
	{
		if(a[2*i+2]<a[i])
		{
			swap(&a[2*i+2],&a[i]);
			min_heapify(a,2*i+2,n);
		}
		
	}
	
	
}
void build_min_heap(int* a,int n)
{
	
	int i;
	for(i=n/2;i>=1;i--)
	{
		min_heapify(a,i,n);
		
	}
}

int extract_min(int *a,int n)
{
	int min=a[0];
	swap(&a[0],&a[n-1]);
	min_heapify(a,0,n-1);
	return min;
}



//adjacency list

struct adj
{
	int vertex;
	int weight;
	struct adj *next;
	
	
};
void insert_begin(int vertex, int weight,)
{
	int data;
	struct node *addr;
	printf("enter the value:\t");
	scanf("%d",&data);
	addr=(struct node*)malloc(sizeof(struct node));
	addr->value=data;
	addr->next=root;
	root=addr;
	print();
}
int** build_adj_list()
{
	int v,e,i,v1,v2,w;
	int **A;
	printf("enter no. of vertices: ");	
	scanf("%d",&v);
	A=(struct adj**)malloc(sizeof(struct adj*)*v);
	printf("enter no. of edges: ");
	scanf("%d",&e);
	printf("enter all %d edges [0 based indexing for vertices] along with weights (i.e) enter 3 integers, 1st two being from the vertex set\n",e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&v1,&v2,&w);
		
	}
}



int main()
{
	
}
