# include <stdio.h>

long long int procedure(int number, int n)
{
	if(n==1)
		return number;
	else if(n%2==0)
	{
		long long int answer =  procedure(number,n/2);
		return answer*answer;
	}
	else
	{
		return number*procedure(number,n-1);
	}
}

int main(int argc, char const *argv[])
{
	int n, number;

	scanf("%d %d",&number,&n);

	printf("%lld\n",procedure(number,n));

	return 0;
}