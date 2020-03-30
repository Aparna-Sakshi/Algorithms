#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int div_hash(int k,int m)//division hashing
{
	return k%m;
}
typedef unsigned uint;
int mult_hash(float a,int k,int m)
{
	float prod=k*a;
	float frac=prod-floor(prod);
	return floor(m*frac);
}
int universal_hash(uint a,uint k,uint r)
{
	//a,k has total sizeof(int) bits and in every iteration r bits are extracted, 0<=a<=m-1, where m is 2**r-1
	int i;
	printf("k:%d \n",k);
	uint ai,ki;
	uint aim,kim,r_bits=(1<<r)-1;
	uint sum=0,m=1<<r;
	for(i=sizeof(int)*8,ai=a,ki=k;i>=0;i-=r,ai=ai>>r,ki=ki>>r)
	{
		printf("ai:%u ki:%u aim:%u kim:%u r_bits:%u sum:%u\n",ai,ki,aim,kim,r_bits,sum);
		aim=ai&r_bits;
		kim=ki&r_bits;
		sum+=aim*kim;
		
	}
	return sum%m;
}
void open_addressing(int k, int *arr, int m)
{
	int choice,r;
	int index,i;
	float a;
	int a_u;
	printf("enter choice of ur hash function\n");
	printf("1.div_hash\n");
	printf("2.mult_hash\n");
	printf("3.universal_hash\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: index=div_hash(k,m);break;
		
		case 2: printf("enter hash code[0<a<1]: ");
				scanf("%f",&a);
				index=mult_hash(a,k,m);break;
				
		case 3: printf("enter hash code[int]: ");
				scanf("%d",&a_u);
				r=(int)(log10((double)m)/log10(2.0));
				index=universal_hash((uint)a_u,(uint)k,(uint)r);break;
	}
	
	for(i=0;i<m;i++)
	{
		
		if(arr[index+i]==0)
		{
			arr[index+i]=k;
			break;
		}
	}
	if(i>=m)
	{
		printf("Sorry!Can't accomodate ur number\n");
	}
}
int main()
{
	int m,n,i,k;
	int *arr;
	printf("enter size hash table: ");
	scanf("%d",&m);
	arr=(int *)malloc(sizeof(int)*m);
	for(i=0;i<m;i++)
	{
		arr[i]=0;
	}
	printf("enter #keys: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter key: ");
		scanf("%d",&k);
		open_addressing(k,arr,m);
	}
	printf("arr is:\n");
	for(i=0;i<m;i++)
	{
		printf("%d ",arr[i]);
	}
}














