#include <stdio.h>
#include <string.h>



int max(int a,int b)
{
return a>b ? a:b ;
}

// for an entry in this array, it represents the max value the array can have with (row) capacity of truck 
//and with column number of bags.

int knapsack(int W,int wt[], int val[], int n1)
{	
	int arr[n1+1][W+1];
	int w,n;

	for(n=0;n<=n1;n++)
		for(w=0;w<=W;w++)
		{	
			if(w==0||n==0)
				arr[n][w] = 0;
			else if(w < wt[n-1])
				arr[n][w] = arr[n-1][w];
			else 
				arr[n][w] = max( arr[n-1][w-wt[n-1]] + val[n-1], arr[n-1][w]);
		}
	return arr[n1][W];
}


int main()
{
	int test;
	scanf("%d",&test);
	int wt[100], val[100];
	
	while(test--)
	{
		int capacity,n,i;

		scanf("%d %d",&capacity,&n);
		
		for(i=0;i<n;i++)
			scanf("%d %d",&wt[i],&val[i]);
		
		printf("Hey stupid robber, you can get %d.\n",knapsack(capacity,wt,val,n));
	}

	return 0;

}