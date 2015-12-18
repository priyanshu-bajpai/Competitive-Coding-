#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	char string[10];
	int i;
	int a;
	int b;
	int c;
	while(1)
	{
	scanf("%s",string);
	
	if(string[0]-'0'==0&&string[1]-'0'==0&&string[3]-'0'==0)
		break;
	a = string[0]-'0';
	b = string[1] - '0';

	a = a*10+b;
	c = string[3]-'0';

	a = a * pow(10,c);
	
	int expo = log(a)/log(2);
	int nearest = pow(2,expo);
	//printf("%d\n",nearest);
	int answer=1;
	while(nearest<a)
	{
		answer+=2;
		nearest+=1;
	}
	printf("%d\n",answer);
	}
	return 0;
}