# include <stdio.h>
# include <math.h>

int main()
{
int test, answer =0;

scanf("%d",&test);

while(test--)
{
	long long int walls;
	scanf("%lld",&walls);
	long long int levels = (long long int)sqrtl(walls+1)-1;
	answer++;
	printf("Case %d: %lld\n",answer,levels);
}

return 0;
}