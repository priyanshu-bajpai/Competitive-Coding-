#include <stdio.h>
#include <string.h>

int getmax(int a, int b)
{
	return a>b ? a:b;
}

int LCS(char *str1, char *str2,int m, int n)
{
	int arr[m][n], i, j;

	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			if(i==0||j==0)
				arr[i][j]=0;
			else if(str1[i]==str2[j])
				arr[i][j] = arr[i-1][j-1] + 1;
			else 
				arr[i][j] = getmax(arr[i-1][j], )
		}

		return arr[m][n];
}

int main(int argc, char * argv[])
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
	char str1[1010], str2[1010];
	int m,n;
	scanf("%d %s",&m,str1);
	scanf("%d %s",&n,str2);

	printf("%d\n",LCS(str1,str2,m,n));
	}
	return 0;
}