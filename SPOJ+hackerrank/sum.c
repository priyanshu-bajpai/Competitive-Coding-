#include <stdio.h>

int main()
{
	int num, j; 
	scanf("%d",&num);
	int arr[num][num];
	int i;
	for(i=0;i<num;i++)
		for(j=0;j<num;j++)
			scanf("%d",&arr[i][j]);
		int first, second, temp;

		//if(arr[0][2]>arr[1][2])
				first = (arr[0][1] + arr[0][2] - arr[1][2])/2;
				
		//else
				//first = (arr[0][1] + arr[0][2] - arr[1][2])/2;
	printf("%d ",first);
	for(i=1;i<num;i++)
		printf("%d ",arr[0][i]-first);	
	printf("\n");
	return 0;
}