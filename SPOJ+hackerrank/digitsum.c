#include <stdio.h>
#include <stdlib.h>


long int max(long int a,long int b)
{	if(a>b)
		return a; 	
			return b;}

long int min(long int a,long int b)
{	if(a<b)
		return a; 	
			return b;}


int main(int argc, char *argv[])
{	
	long int a,b;
	long long int *dp = (long long int*)malloc(sizeof(long long int)*(1000000010));
	long int max_in = 1;
	dp[0] = 0;
	long int i;
	while(1)
	{
	scanf("%ld %ld",&a,&b);
	if(a==-1&&b==-1)
		break;
	long int size = max(a,b);
	unsigned int temp;
	unsigned long long int answer = 0;

	for(i=max_in;i<=size;i++)
	{
		temp = i%10;
		dp[i] = temp + dp[i/10];
	}
	max_in = size;
	i = min(a,b);
	while(i<size+1)
	{
		answer = answer + dp[i]; 
		i++;
	}

	printf("%lld\n",answer);	
	}
	return 0;
}