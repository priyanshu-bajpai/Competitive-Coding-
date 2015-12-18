#include<stdio.h>

long int num=0;
long int recur(long int n,long int m)
{if(m>=0&&n>=0)
	{
	if(n<m)
	num=0;
	else if(m==0&&n>0)
	num= 0;
	else if(m==0&&n==0)
	num= 1;
	else if(m==n)
	num=1;	
	else if(m%2==0)
	num = (recur(n-1,m-1))%2;
    else
	num = (1 + recur(n-1,m-1))%2;	
}

	return num;
}
int main()
{
	int d;
    long int m,n,j;
	scanf("%d",&d);
	int i;

	for(i=0;i<d;i++)
	{
		scanf("%ld",&n);
		scanf("%ld",&m);
		j=recur(n,m);

		printf("%ld\n",(j));
		num=0;
	}

	return 0;
}
