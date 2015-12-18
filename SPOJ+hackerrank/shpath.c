#include <stdio.h>

int main()
{
	int test;
	scanf("%d"<&test);

	while(test--)
	{
		int cities, i;
		scanf("%d",&cities);
		char cityname[cities][12];
		int matrix[cities][cities]= 1000000;

		for(i=0;i<cities;i++)
		{
			scanf("%s",&cityname[i]);
			int j,neigbours, index,cost;
			scanf("%d",&neigbours);
			for(j=0;j<neigbours;j++)
			{
				scanf("%d %d", &index, &cost);
				matrix[i][index-1] = cost;
			}

		}
		printf("input successfully taken\n");
		int *queue = (int *)malloc(sizeof(int)*10000000);
		int queries;
		int front,end;
		int visited[cities] = {0};
		int cost[cities] = {1000000};
		scanf("%d",&queries);
		for(i=0;i<queries;i++)
		{
		
		}


	}
	return 0;
}