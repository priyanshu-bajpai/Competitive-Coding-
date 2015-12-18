#include <stdio.h>

#include <string.h>

int main()
{
char arr[5010];

int length,curr,prev,num;

int i,j, next;

while(1)
{
scanf("%s",arr);

length = strlen(arr);

if(strcmp(arr,"0")==0)
	break ;
int dp[length];

dp[0] = 1;

curr = arr[0] - '0' ; 

next = arr[1] - '0' ;

for(i=1;i<length;i++)
 {
   prev = curr ;

   curr = arr[i] - '0' ;
   
   if((arr[i+1]-'0')==0)
   next = arr[i+1] - '0' ;

   
    dp[i] =dp[i-1];
   

   if((next!=0)&&(curr!=0)&&(prev!=0))
   {
     num = 10*prev + curr ;
 

    if(num<=26)
    {
   	 if(i==1)
   	 dp[i] = dp[i-1] + 1 ;
   	 else	
   	 dp[i] = dp[i] +dp[i-2] ;
    }
   }

   next = 1;
 }

printf("%d \n",dp[length-1]);
}

return 0;	
}