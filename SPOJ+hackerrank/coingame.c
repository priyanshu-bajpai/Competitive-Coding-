#include <stdio.h>
#include <string.h>

int A[1000001];

int main( int argc, char *argv[])
{
	int k,l,m;

	scanf("%d %d %d",&k,&l,&m);
	
	int i, max = 0,a[m];

	for(i=0;i<m;i++)
	{

		scanf("%d",&a[i]);
		max = max>a[i]?max:a[i];
	}

	A[0] = -1;
	A[1] = 1;

	for(i=2;i<=max;i++)
	{
		A[i] = -1 * A[i-1];

		if(A[i-l]==-1)
			A[i] = 1;

		if(A[i-k]==-1)
			A[i] = 1; 
	}

	for(i=0;i<m;i++)
	{
		if(A[a[i]]==1)
			printf("A");
		else if(A[a[i]]==-1)
			printf("B");
	}
	
return 0;
}
