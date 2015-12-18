#include <stdio.h>
#include <string.h>

int dp[2010][2010];
char string1[2010], string2[2010];

int min(int a, int b)
{
	if(a<b)
		return a;
	return b;
}

int minimum(int a, int b, int c)
{
	return min(min(a,b),c);
}


int edist(char *string1, char *string2)
{
	int length1 =strlen(string1) + 1;
	int length2 =strlen(string2)+ 1;

	int i,j;
	for(i=1;i<length1;i++)
		for(j=1;j<length2;j++)
		{
			if(string1[i-1]!=string2[j-1])
			dp[i][j] = minimum(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1 ;
			else
				dp[i][j] = dp[i-1][j-1];
		}
		return dp[length1-1][length2-1];
}


int main()
{
	int i,j;
	for(i=0;i<2010;i++)
		dp[i][0] = i;
	for(j=0;j<2010;j++)
		dp[0][j] = j;

	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",string1);
		scanf("%s",string2);
		printf("%d\n",edist(string1,string2));
	}
	return 0;
}