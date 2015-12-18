#include<stdio.h>


int main()
{
int test , number;
int i,j,k;

scanf("%d",&test);

for(i=0;i<test;i++)
{
long long int answer,totalsum=0,sum;
	
scanf("%d",&number);

/*if(number%2==0)
{
for(j=1;j<=number/2;j++)
{
sum=0;

for(k=1;k<j;k++)
sum += j-k;
	
 for(k=j+1;k<=number;k++)
 sum += k-j ;
   
totalsum+=sum;		
}
answer = 2*totalsum;	}	
else
{
   for(j=1;j<=number/2;j++)
   {
    sum=0;
    for(k=1;k<j;k++)
    sum += j-k;
	
   for(k=j+1;k<=number;k++)
   sum += k-j ;
   		
   totalsum+=sum;	
   }  
   
   totalsum*=2;
   sum=0;
   j = number/2 + 1;
   
   for(k=1;k<=number;k++)
   {
   if(j<=k)	
   sum+=(k-j);
   else
   sum+=(j-k);		
   }
   totalsum+=sum;
   
   answer = totalsum;	
}	
*/
answer = number*(number-1)*(number+1)/3;

for(j=number-1;j>1;j--)
answer*=j;	
	

if(answer>=(1000000000+7))
{	
 long int ans = answer%1000000000 ;
 ans+=7;

printf("%ld\n",ans);	
}
else
printf("%lld\n",answer);	

}
return 0;		
}	