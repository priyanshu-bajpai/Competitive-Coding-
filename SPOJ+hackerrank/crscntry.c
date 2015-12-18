#include<stdio.h>

int max(int a,int b)
{
return a>b?a:b;	
}


int main()
{
int d;
scanf("%d",&d);

while(d--)
{

int tom[2010],agnes[2015];
int temp, i=0, j,k,m=0,n=0;

while(1)
{
scanf("%d",&temp);
if(temp==0)
break;	
agnes[i] = temp;
m++;
i++;
}

int answer=0;
i=1;
while(i>0)
{	

i=0;

while(1)
{
scanf("%d",&temp);
if(temp==0)
break;	
tom[i]=temp;	
i++;
}

n=i;

if(n>0)
{	
int dp[m+1][n+1];	
k=0;
for(j=0;j<=m;j++)
  dp[j][k] = 0;
for(j=0;j<=n;j++)
  dp[k][j]=0;

for(k=1;k<m+1;k++)
 for(j=1;j<n+1;j++)
  {
	if(agnes[k-1]==tom[j-1])
	dp[k][j] = dp[k-1][j-1]+1;
	else
	dp[k][j] = max(dp[k-1][j],dp[k][j-1]);	
  }
answer = max(dp[m][n],answer);	
}
 
}

printf("%d\n",answer);
}	
return 0;	
}