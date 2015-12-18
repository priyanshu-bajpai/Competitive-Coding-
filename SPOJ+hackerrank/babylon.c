#include <stdio.h>

int getmax(int l, int m, int n)
{
if(l>m && l>n)
	return l;

if(m>l && m>n)
	return m;

if(n>m && n>l)
	return n;

if(l==m && m==n)
	return -1;

if(l==m || m==n || l==n)
	return 0;
}

int knapsack(int ht[], int width[], int length[], int blocks)
{
	
}

int main()
{
	int blocks, i;
	int ht[35],width[35], length[35];
	int info[3];

	info[]

	while(scanf("%d",&blocks)!=0)
	{
	for(i=0;i<blocks;i++)
	{
		scanf("%d %d %d",&ht[i],&width[i],&length[i]);

	}

	printf("%d\n",knapsack(ht,width,length,blocks));
	}
}