#include <stdio.h>

int arr[10000010] = {0} ;
int max = 0;

void dp(int start, int end)
{
int i;

	for(i=start;i<=end;i++)
	{
	arr[i]++;
	if(arr[i]>max)
	max = arr[i];
	}

	return ;
}

int main()
{
	int test;
	int records;
	int i, in_time, exit_time;
	int largest_end_time;
	scanf("%d",&test);

	while(test--)
	{
		scanf("%d",&records);
		int i;
		for(i=0;i<records;i++)
		{
			scanf("%d %d",&in_time,&exit_time);
			if(exit_time>largest_end_time)
				largest_end_time = exit_time;
			dp(in_time, exit_time);
		}

		printf("%d\n",max);
		max = 0;

		for(i=1;i<=largest_end_time;i++)
			arr[i] = 0;

		largest_end_time = 0;
	}
	return 0;
}


