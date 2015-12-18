#include <stdio.h>

int main()
{
int g, b;

while(1)
{
scanf("%d %d",&g,&b);
if(g==-1 && b==-1)
	break;
else
{
	int max = g>b?g:b;
	int min = g<b?g:b;

	int integer;
	float decimal;

	integer = max/(min+1);
	decimal = (float)max/(float)(min+1);
	//printf("%d %f\n",integer,decimal);
	if(integer==decimal)
		printf("%d\n",integer);
	else
		printf("%d\n",integer+1);
}
}
return 0;
}