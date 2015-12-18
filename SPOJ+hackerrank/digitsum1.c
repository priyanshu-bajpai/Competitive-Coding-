#include <stdio.h>
#include <math.h>

long long int sum(long long int N)
{
	if(N/10==0)
		return N*(N+1)/2;

	long long int n = N;
	int i=0;
	while(n/10!=0)
	{
		i++;
		n=n/10;
	}
    int p = pow(10,i);

	//assumption -- N=7655, n=7,i=3,p=1000...
	long long int answer = (n*45*p*i/10 + n*(n-1)*p/2 + n*(N%p + 1) +sum(N%p));
	
	return answer;
}

int main()
{
	while(1)
	{
	long int a,b;

	scanf("%ld %ld",&a,&b);
	if(a==-1&&b==-1)
		break;
	printf("%lld\n",sum(b)-sum(a-1));
	}

  return 0;
}