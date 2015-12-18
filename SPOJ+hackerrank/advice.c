#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
	float num;
	scanf("%f",&num);
	float sum=0;
	float i;
	for(i=1;i<num;i++)
		sum =sum +num/i;
	sum = sum +1;

	printf("%.2lf\n",sum);
	}
	return 0;
}