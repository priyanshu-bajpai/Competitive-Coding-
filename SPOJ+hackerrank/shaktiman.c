#include <stdio.h>

int main()
{
	int test;
	scanf("%d",&test);
	long int num;
	while(test--)
	{
		scanf("%ld",&num);
	if(num%2==0)
		printf("Thankyou Shaktiman\n");
	else
		printf("Sorry Shaktiman\n");
	}

	return 0;
}