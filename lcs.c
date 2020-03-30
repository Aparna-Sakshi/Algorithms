//longest common subsequence
#include<stdio.h>
#include<stdlib.h>
#define max(x,y) (x>y)?x:y



int** init_M(int len_x,int len_y)
{
	int i,j;
	int **M;
	M=(int **)malloc(sizeof(int *)*len_x);
	for(i=0;i<len_x;i++)
	{
		M[i]=(int *)malloc(sizeof(int)*len_y);
	}
	for(i=0;i<len_x;i++)
	{
		for(j=0;j<len_y;j++)
		{
			M[i][j]=-1;
		}
	}
	return M;
}

int llcs(int **M,char *x,char *y,int i,int j)
{
	int return_val;
	if(i<0||j<0)
		return 0;
	if(M[i][j]!=-1)
		return M[i][j];
	if(x[i]==y[j])
	{
		
		return_val=llcs(M,x,y,i-1,j-1)+1;
	}
	else
	{
		return_val=max(llcs(M,x,y,i-1,j),llcs(M,x,y,i,j-1));
	}
	M[i][j]=return_val;
	return return_val;
}
void lcs(int **M,char *x,char *y,int i,int j, char *lcs_ij)
{
 	if(i<0||j<0)
		return;
	if(M[i][j]<1)
	{
		printf("error");
		return;
	}
  	if(x[i]==y[j])
  	{
  		lcs_ij[M[i][j]-1]=x[i];
  		lcs(M,x,y,i-1,j-1,lcs_ij);
	}
	else if(M[i][j-1]>M[i-1][j])
	{
		lcs(M,x,y,i,j-1,lcs_ij);
	}
	else
	{
		lcs(M,x,y,i-1,j,lcs_ij);
	}
	
}

int main()
{
	int t,iter,i;
	int **M;
	char *x;
	char *y;
	char *a_lcs;
	int len_x,len_y,len_lcs;
	printf("Enter the number of test cases: ");
	scanf("%d",&t);
	for(iter=0;iter<t;iter++)
	{
		//input and initialize
		printf("Enter the length of string x: ");
		scanf("%d",&len_x);
		printf("Enter the length of string y: ");
		scanf("%d",&len_y);
		
		M=init_M(len_x,len_y);
		
		
		x=(char *)malloc(sizeof(char)*(len_x+1));
		y=(char *)malloc(sizeof(char)*(len_y+1));
		
		printf("enter string x: ");
		scanf("%s",x);
		printf("enter string y: ");
		scanf("%s",y);
		
		
		//call lcs and print a lcs
		len_lcs=llcs(M,x,y,len_x-1,len_y-1);
		a_lcs=(char *)malloc(sizeof(char)*(len_lcs+1));		
		a_lcs[len_lcs]='\0';
		lcs(M,x,y,len_x-1,len_y-1,a_lcs);		
		printf("\nlength of longest common subsequence is %d and a longest common subsequence is %s\n",len_lcs,a_lcs);
		
		
		
		
		
		
		//free memory
		for(i=0;i<len_x;i++)
		{
			free(M[i]);
		}
		free(M);
		free(x);
		free(y);
		free(a_lcs);
	}
	
}
