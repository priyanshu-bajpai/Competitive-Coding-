#include<stdio.h>

int main()
{
int test,i,j;
scanf("%d",&test);
int num,sum1,sum2;
while(test--)
{
scanf("%d",&num);

int arr[num];
 sum1=0;
 sum2=0;

for(i=0;i<num;i++)
{
scanf("%d",&arr[i]);
sum1=sum1+arr[i];
}

for(j=0;j<num;j++)
{
if((sum1-arr[j])==sum2)
{
printf("YES\n");
break;
}
else if(j==num-1)
printf("NO\n");	
else
{
sum2 = sum2 + arr[j];
sum1 = sum1 -arr[j];
}
}
}
return 0;
}