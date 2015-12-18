#include<stdio.h>

int arr[20][20],ond[20],s,students,smallest=0;

int main()
{
	int cases,i,j,k,number;
	
	scanf("%d",&cases);
	
	for(i=0;i<cases;i++)
	{
	scanf("%d",&students);
	
	for(j=0;j<students;j++)
	{
	number =0;
	for(j=0;j<students;j++)
	{
	scanf("%d",&arr[i][j]);		
    if(arr[i][j]==1)
	number++;	
	}
	oned[j]=number;
	}
	//sort the ond
	
	recursion(arr,ond);	
	printf("%d",s);
	}

	
return 0;	
}

void recursion(int arr[20][20];int ond[20] )
{
int arr1[20][20];
int cases,i,j,k,number;

for(i=0;i<cases;i++)
for(j=0;j<students;j++)	
arr1[i][j]=arr[i][j];

