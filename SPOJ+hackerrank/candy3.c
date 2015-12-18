# include <stdio.h>


int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		unsigned long long int number, temp;
		unsigned long long int sum = 0;
		scanf("%d",&number);
		long int i;
		for(i=0;i<number;i++)
		{
			scanf("%llu",&temp);
			sum = sum +temp;
		}

		if(sum%number==0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}