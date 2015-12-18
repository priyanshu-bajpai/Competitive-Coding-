#include<stdio.h>


int count=1,num1=100,num2=100,primes[1000000];

int nextprime()
{

int num,i;

for(num =(primes[count-1]+1);;num++)
{
for(i=0;i<count;i++)
{
if(num%primes[i]==0)
break;
}
if(i==count)
{
primes[count]=num;
count++;
break;
}
}
return num;
}
////////////////////////////////////////////////////
int division(int num)
{
if(num1%num==0||num2%num==0)
return 1;
return 0;
}


////////////////////////////////////////////////////
int main()
{
int i=1,ordnl=0;
primes[0]=2;

while((scanf("%d",&num1)!=0)&&
 (scanf("%d",&num2)!=0))
{

int diff,cnt1=0,cnt2=0;

if(num1%2==0||num2%2==0)
{
ordnl++;

while(num1%2==0&&num1>0)
{
 cnt1++;
 num1/=2;
}

while(num2%2==0&&num2>0)
{
 cnt2++;
 num2/=2;
}
}
printf("madarchod");
diff = cnt1>=cnt2? cnt1-cnt2:cnt2-cnt1;

while(num1>0||num2>0)
{
 int cont1=0,cont2=0;
 int num3 = nextprime();
 int boolean = division(num3);

if(boolean==1)
 {
  ordnl++;
  while(num1%num3==0&&num1>0)
  {
   cont1++;
   num1/=num3;
  }
  while(num2%num3==0&&num2>0)
  {
   cont2++;
   num2/=num3;
  }

 diff+=cont1>cont2?cont1-cont2:cont2-cont1;
  }	
}

printf("%d. %d:%d",i,ordnl,diff);
i++;
}
return 0;
}
