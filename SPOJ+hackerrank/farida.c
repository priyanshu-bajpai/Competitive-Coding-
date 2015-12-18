#include <stdio.h>


unsigned long long int max(unsigned long long int a, unsigned long long int b)
{
	if(a>b)
		return a;
	return b;
}

int main()
{
	int test, j=1;
	scanf("%d",&test);

	while(test--)
	{
		int beasts;
		scanf("%d",&beasts);
		int i, arr[beasts];

		for(i=0;i<beasts;i++)
			scanf("%d",&arr[i]);
		unsigned long long int dp[beasts+1];
		dp[0]=0;
		dp[1] =arr[0];
		
		for(i=2;i<=beasts;i++)
		    dp[i] = max(dp[i-1], arr[i-1]+dp[i-2]);
		printf("Case %d: %llu\n",j,dp[beasts]);
		j++;

	}
return 0;
}