# include <stdio.h>

int max(int a, int b)
{
	if(a>b)
		return a;
		return b;
}

//for building the rows in the dp
int candy(int m, int n, int arr[m][n])
{
	int row[m]; //for storing the values after the row value has been calculated...
	int i=0,j;

	for(i=0;i<m;i++)
	{
	int dp[n+1];
	dp[0]=0;	
	dp[1]=arr[i][0];
	
		for(j=2;j<n+1;j++)
			dp[j] = max(dp[j-2] + arr[i][j-1], dp[j-1]);
	
	row[i] = dp[n]; 
	}

	//max values for the rows have been calculated, applying same concept of dp on this array
	int dp1[m+1];
	dp1[0]=0;
	dp1[1]=row[0];

	for(i=2;i<m+1;i++)
		dp1[i] = max(dp1[i-1], row[i-1] + dp1[i-2]);
	


	return dp1[m];
}

int main()
{
	
	int i,j;
	int m,n;

	while(1)
	{
		scanf("%d %d",&m,&n);

		if(m==0&&n==0)
			break;
		int arr[m][n];
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				scanf("%d",&arr[i][j]);
				
		int answer = candy(m,n,arr);	
			printf("%d\n",answer);
		}
	return 0;
}