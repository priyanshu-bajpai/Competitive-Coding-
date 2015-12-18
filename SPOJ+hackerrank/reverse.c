#include<stdio.h>

int main()
{
int test,i;


scanf("%d",&test);	

for(i=0;i<test;i++)
{
int num1=0,num2=0,rev1=0,rev2=0,result=0,reverse=0;	
scanf("%d",&num1);
scanf("%d",&num2);

while(num1>0)
{
	rev1=rev1+num1%10;
	rev1*=10;
	num1=num1/10;	
	
}	

while(num2>0)
{
	rev2=rev2+num2%10;
	rev2*=10;
	num2=num2/10;	
	
}
rev2/=10;
rev1/=10;
result=rev1+rev2;

while(result>0)
{
reverse=reverse+result%10;	
reverse*=10;	
result/=10;	
}	
reverse/=10;

while(reverse%10==0)
{
if(reverse%10==0)
reverse/=10;		
}	
printf("%d\n",reverse);
}

return 0;
}
