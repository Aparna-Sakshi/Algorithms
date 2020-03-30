//quick sort
//heap sort
//bst sort
//radix sort



#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
	int temp;
	temp=(*a);
	(*a)=(*b);
	(*b)=temp;
}

//quick sort
int find_pivot_index(int pivot,int *a,int start,int end)
{
	int i;
	for(i=start;i<=end;i++)
	{
		if(a[i]==pivot)
		{
			return i;
		}
	}
	printf("Error!");
	return 0;
}
int partition(int *a,int start,int end)
{
	
	//int pivot_index=find_pivot_index(a[start],a,start,end);
	//swap(&a[pivot_index],&a[start]);
	int pivot=a[start];
	int i=start,j;
	for(j=i+1;j<=end;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			swap(&a[i],&a[j]);
			
		}
	}
	swap(&a[start],&a[i]);
	return i;
	
}

void quick_sort(int *a,int start,int end)
{
	if(start>=end)
	{
		return;
	}
	int r=partition(a,start,end);
	
	quick_sort(a,start,r-1);
	quick_sort(a,r+1,end);
}

//heap_sort
void max_heapify(int *a,int n,int i)
{
	if((2*i+1)>=n||(2*i+2)>=n)
	{
		return;
	}
	int max_index=(a[2*i+1]>a[2*i+2])?(2*i+1):(2*i+2);
	if(a[max_index]>a[i])
	{
		swap(&a[i],&a[max_index]);
		max_heapify(a,n,max_index);
		
	}
}
void build_max_heap(int *a,int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	{
		max_heapify(a,n,i);
	}
}
void heap_sort(int *a,int n)
{
	int i;
	build_max_heap(a,n);
	for(i=n-1;i>0;i--)
	{
		swap(&a[0],&a[i]);
		max_heapify(a,i,0);
	}
	
}

//bst sort
struct node
{
	int value;
	struct node *right,*left;
	
};
struct node *tree_root=NULL;
void bst_insert(int value)
{
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->value=value;
	new->left=NULL;
	new->right=NULL;
	struct node *curr,*prev;
	if(tree_root==NULL)
	{
		tree_root=new;
		return;
	}
	for(curr=tree_root;curr!=NULL;)
	{
		
		prev=curr;
		if(value>curr->value)
		{
			
			curr=curr->right;
			
		}
		else
		{
			
			curr=curr->left;
			
		}
	}
	if(prev->value>value)
	{
		prev->left=new;
	}
	else
	{
		prev->right=new;
	}
	
	
}
void in_order_traversal(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	in_order_traversal(root->left);
	printf("%d ",root->value);
	in_order_traversal(root->right);
	
}
void bst_sort(int *a,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		bst_insert(a[i]);
	}
	in_order_traversal(tree_root);
	
}


//radix sort
int max_digit(int *a,int n)
{
	int i,k;
	int max=a[0];
	for(i=1;i<n;i++)
	{
		max=(a[i]>max)?a[i]:max;
		
	}
	for(i=0,k=max;k>0;k=k/10,i++);
	return i;
}
void radix_sort(int *a,int n)
{
	int digi=max_digit(a,n);
	printf("****%d****",digi);//number of digits
	//int b[]={0,0,0,0,0,0,0,0,0,0};
	int c[]={0,0,0,0,0,0,0,0,0,0};
	int a_digi[n];
	int a_new[n];
	int digit;
	int i,j,k;
	for(i=0,k=1;i<digi;i++,k*=10)
	{
		for(j=0;j<10;j++)
		{
			c[j]=0;
		}
		for(j=0;j<n;j++)
		{
			int digit=(a[j]/k)%10;
			c[digit]++;
			a_digi[j]=digit;
		}
		
		for(j=1;j<10;j++)
		{
			c[j]=c[j]+c[j-1];
		}
		for(j=n-1;j>=0;j--)
		{
			a_new[c[a_digi[j]]-1]=a[j];
			c[a_digi[j]]--;
		}
		for(j=0;j<n;j++)
		{
			a[j]=a_new[j];
			printf("-%d-",a[j]);
		}
		printf("\n");
	}
	
}
void print_arr(int *arr,int n)
{
	int i;
	printf("\narray: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main()
{
	int a[]={124,546,176,222,322};
	int b[]={124,546,176,222,322};
	int c[]={124,546,176,222,322};
	int d[]={124,546,176,222,322};
	quick_sort(a,0,4);
	heap_sort(b,5);
	radix_sort(d,5);
	bst_sort(c,5);
	print_arr(a,5);
	print_arr(b,5);
	print_arr(d,5);
	
	
}









































