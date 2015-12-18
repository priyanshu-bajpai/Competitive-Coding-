#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
return a>b?a:b ;	
}

int main()
{

int j, m, n;

int score = 0;	
scanf("%d",&m);
scanf("%d",&n);

int str2[n],str1[m]; 	

for(j=0;j<m;j++)
scanf("%d",&str1[j]);

for(j=0;j<n;j++)
scanf("%d",&str2[j]);

int dp[m+1][n+1], i;
j=0;
for(i=0;i<=m;i++)
dp[i][j] = 0;
i=0;	
for(j=0;j<=n;j++)
dp[i][j]=0;

for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
{
 if(str1[i-1]==str2[j-1])
  dp[i][j] = dp[i-1][j-1] + 1 ;	
 else
 dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
}
	
int arr[dp[m][n]];

i=m;
j=n;
while(i>0&&j>0)
{	
if((dp[i][j]>dp[i-1][j])&& (dp[i][j]>dp[i][j-1]))
{
arr[score] = str1[i-1];
score++;
i--;
j--;
}
else if(dp[i][j]==dp[i-1][j])
i--;
else 
j--;
}

for(i=dp[m][n]-1;i>=0;i--)
printf("%d ",arr[i]);	

printf("\n");

return 0 ;	
}