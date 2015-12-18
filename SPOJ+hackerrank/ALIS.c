# include<stdio.h>

int LIS(long int arr[][100010], int n)
{
	int i,j,max=0;

	int val[n];
	for(i=0;i<n;i++)
		val[i]=1;

	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(val[i] < val[j]+1 && arr[0][i]>arr[0][j] && arr[1][i] > arr[1][j])
				val[i] = val[j]+1;

		for(i=0;i<n;i++)
		if(max < val[i])
		max = val[i];	

	return max;
}


int main()
{
	int n;
	scanf("%d",&n);

	long int arr[2][100010];
	int i;
	for(i=0;i<n;i++)
		scanf("%ld %ld",&arr[0][i], &arr[1][i]);

	printf("%d\n",LIS(arr,n));	

return 0;
}