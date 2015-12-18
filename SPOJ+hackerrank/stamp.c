#include <stdio.h>
#include <string.h>


void insert(int *arr, int i, int value)
{
	if(i==0)
		arr[i] = value;

	else
	{
		int j = i-1;
		while(arr[j]<value && j>=0 )
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = value;
	}
	return ;
}

void calculate(int stamps, int *arr, int freinds)
{
	int sum =0, i=0;

	while((sum<stamps)&&i<freinds)
	{
		sum = sum + arr[i];
		i++;
	}

	if(i>=freinds)
		printf("impossible\n\n");
	else
	printf("%d\n\n",i);
	return;
}


int main()
{
	int test;
	int stamps, freinds;
	scanf("%d",&test);
	int j = 0;
	while(test--)
	{
		scanf("%d %d",&stamps,&freinds);
		int i, arr[freinds], temp;

		for(i=0;i<freinds;i++)
		{
			scanf("%d",&temp);
			insert(arr,i,temp);			
		}
		j++;
		printf("Scenario #%d:\n",j); 
		calculate(stamps,arr, freinds);
	}

return 0;
}

