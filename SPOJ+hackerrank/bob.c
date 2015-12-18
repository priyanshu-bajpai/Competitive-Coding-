#include <stdio.h>
#include <math.h>

int main()
{
	long long int n, answer;
	long double answer1;

	scanf("%lld",&n);
	answer = log2(n);
	printf("%lld\n",answer);
	answer1 = log2(n);
	printf("%Lf\n",answer1);

	double margin = answer1 -answer;
	printf("%lf\n",margin);

	if(margin==0)
	printf("TAK\n");
	else
	printf("NIE\n"); 
	return 0;
}