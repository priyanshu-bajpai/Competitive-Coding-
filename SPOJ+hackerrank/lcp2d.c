#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
return a>b?a:b ;	
}

int main()
{

int test , l, len1, len2, x;
scanf("%d",&test);
for(l=1;l<=test;l++)
{
int score = 0;	
scanf("%d",&len1);
char str1[len1]; 
scanf("%s",str1);
scanf("%d",&len2);
char str2[len2] ;	
scanf("%s",str2);

int m = strlen(str1), n = strlen(str2);

int dp[m+1][n+1], i, j=0;
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

if(dp[m][n]>1)
{	
char arr[dp[m][n]];
int arr1[dp[m][n]][2];	

printf("case %d Y\n",l);

printf("%d\n",dp[m][n]);	
i=m;
j=n;
while(i>0&&j>0)
{	
if((dp[i][j]>dp[i-1][j])&& (dp[i][j]>dp[i][j-1]))
{
arr[score] = str1[i-1];
arr1[score][0] = i;
arr1[score][1] = j;	
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
printf("%c %d %d\n",arr[i],arr1[i][0],arr1[i][1]);	

}
else
printf("case %d N\n",l);	
}
return 0 ;	
}