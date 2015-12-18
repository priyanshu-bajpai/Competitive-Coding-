#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

char arr1[2010], arr2[2010];

int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}

int edit(int l1, int l2)
{
int dp[l1+1][l2+1];
int i,j;

i=0;
j=0;	
while(i<=l1)
{
	dp[i][0] = i;
	i++;
}
while(j<=l2)
{
	dp[0][j] = j;
	j++;
}

	i=1;
	
	while(i<=l1)
		{
			j=1;
			while(j<=l2)
			{
				dp[i][j]= min(dp[i-1][j]+1,dp[i][j-1]+1);
				if(arr1[i-1]==arr2[j-1])
				{
					int temp = dp[i-1][j-1];
					dp[i][j] = min(dp[i][j], temp);
				}
				j++;
			}
			i++;
		}

	for(i=0;i<=l1;i++)
		{
			for(j=0;j<=l2;j++)
				printf("%d ",dp[i][j]);
			printf("\n");
		}

return dp[l1-1][l2-1];
}


int main()
{
	int test;
	scanf("%d",&test);

	while(test--)
	{
		scanf("%s",arr1);
		scanf("%s",arr2);
		int l1 = strlen(arr1);
		int l2 = strlen(arr2);
		printf("%d %d\n",l1,l2);
		printf("%d\n",edit(l1,l2));
	}
}