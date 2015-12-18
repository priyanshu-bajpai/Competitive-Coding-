#include<stdio.h>

int max(int a, int b)
{
return (a>b)? a:b ;	
}


int main()
{
int test, i, j, k;
int count ;
scanf("%d",&test);
int numbers, capacity ;
while(test--)
{
 count =0; 	
 scanf("%d", &numbers);
 scanf("%d", &capacity);

 int arr[numbers];

 for(i=0;i<numbers;i++)
 scanf("%d", &arr[i]);

 int dp[2000][capacity+1];

 for(j=0;j<2000;j++)
 for(i=0;i<capacity+1;i++)
 dp[j][i] = 0;

 for(i=1;i<2000;i++)
	for(j=1;j<capacity+1;j++)
	{
     //while(arr[count]<=j)
     	//count++;
     for(k=0;k<numbers;k++)
     	if(j>=arr[k])
         dp[i][j] = max(dp[i][j], arr[k]+ dp[i-1][j-arr[k]]);
        else
         break;	
    }
	printf("%d\n", dp[1999][capacity]);
}


return 0;	
}