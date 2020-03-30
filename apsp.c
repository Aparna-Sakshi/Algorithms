//all pair shortest path
#include<stdio.h>
#include<stdlib.h>


int** allocate_memory(int size)
{
	int **A;
	
	A=(int**)malloc(sizeof(int*)*size);
	for(i=0;i<v;i++)
	{
		A[i]=(int*)malloc(sizeof(int)*size);
	}
	return A;
}
//building adjacency matrix
int** build_adj_matrix(int v)
{
	int e,i,j,v1,v2,w;//v-#vertices, e-#edges
	int **A;
	A=allocate_memory(v)
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i==j)
			{
				A[i][j]=0;
			}
			else
			{
				A[i][j]=10000;
			}
		}
	}
	
	printf("enter no. of edges: ");
	scanf("%d",&e);
	printf("enter all %d edges [0 based indexing for vertices] along with weights (i.e) enter 3 integers, 1st two being from the vertex set\n",e);
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&v1,&v2,&w);
		A[v1][v2]=w;
		
	}
	return A;
}

/*
//strassen's multiplication
//mat1 and mat2 are input martix and mat3 is final matrix
int** mat_add(int** mat1,int** mat2,int mat1_start,int mat1_end,int mat2_start,int mat2_end)
{
	int** ans=allocate_memory()
	for(i=mat1_start;i<=mat1_end;i++)
	{
		for(j=mat2_start;j<=mat2_end;j++)
		{
			
		}
		
	}
	return ans;
}
void strassen(int** mat1,int** mat2,int mat1_start,int mat1_end,int mat2_start,int mat2_end)
{
	//base case
	
	
	
}
*/

void print_mat(int** mat,int )


int** cross(int** mat1,int** mat2,int v)
{
	int** ans=allocate_memory(v);
	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			if(i!=j)
			{
				ans[i][j]=10000;
			}
			else
			{
				ans[i][j]=0;
			}
			
			for(k=0;k<v;k++)
			{
				int sum=mat1[i][k]+mat2[k][j];
				ans[i][j]=(ans[i][j]>sum)?sum:ans[i][j];
			}
		}
	}
	return ans;
}

int** fast_expo(int** mat,int size,int power)
{
	if(power<1)
	{
		printf("\nerror:undefined power\n");
		return NULL;
	}
	if(power==1)
	{
		return mat;
	}
	int** A;
	if(power%2==0)
	{
		A=fast_expo(mat,size,power/2);
		return cross(A,A,size);
	}
	else
	{
		A=fast_expo(mat,size,(power-1)/2);
		return cross(A,mat_mult(A,mat,size));
		
	}
}
int** 
int main()
{
	
}
