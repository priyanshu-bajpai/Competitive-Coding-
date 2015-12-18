#include <stdio.h>

int main()
{
int number, answer, i;

int test;

scanf("%d",&test);

while(test--)
{
answer= 0;

i = 5;

scanf("%d",&number);

while(number/i!=0)
{
answer = answer + number/i;

i*=5;
}

printf("%d\n",answer);
}
return 0;	
}