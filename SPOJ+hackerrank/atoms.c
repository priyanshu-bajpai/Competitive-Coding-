# include <stdio.h>
# include <math.h>

int main()
{
int test;
long long int n,k,m;
float time;
scanf("%d",&test);

while(test--)
{

	scanf("%lld %lld %lld",&n,&k,&m);

	if(n>m)
		printf("0\n");
	else
	{
	long double val = m/n;
	time = log10(val)/log10(k);

	printf("%d\n",(int)time);
	}
}

return 0;
}