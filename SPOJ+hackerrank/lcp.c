#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
return a>b? a:b;	
}
int main()
{
char str1[50000], str2[50000] ;
scanf("%s",str1);
scanf("%s",str2);

int m = strlen(str1), n = strlen(str2);
int length = (m<n)? m:n ;
int count = m>n? m:n ;
int dp[length+1], i=0, j, temp1=0, temp2;

for(i=0;i<=length;i++)
dp[i] = 0 ;

i=0;

while(i<count)
{
for(j=1;j<=length;j++)
{
if(str1[i]==str2[j-1])
{
temp2 = temp1 ;
temp1 = dp[j] ;
dp[j] = temp2 + 1;
}	
else
dp[j] = max(dp[j-1],dp[j]) ;
}
i++;	
}

printf("%d\n",dp[length]);
return 0 ;	
}