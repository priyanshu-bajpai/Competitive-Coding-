#include <stdio.h>
#include <string.h>


void merge(int arr[2][100010], int start, int mid, int end)
{
	int m = mid-start+1;
	int n = end -mid;
	//printf("%d %d\n", m,n);
	int L[2][m], R[2][n];

	int i,j;

	for(i=0;i<m;i++)
	{
		L[0][i]=arr[0][start+i];
		L[1][i]=arr[1][start+i];
	}

	for(j=0;j<n;j++)
	{
		R[0][j]=arr[0][mid+1+j];
		R[1][j]=arr[1][mid+1+j];
	}

	i=0;j=0;
	int k=start;
	while(i<m && j<n)
	{
		if(R[1][j]<=L[1][i])
		{
		arr[0][k] = R[0][j];
		arr[1][k] = R[1][j];
		j++;
		}

		else if(R[1][j]==L[1][i])
		{
		if(R[0][j]<=L[0][i])
			{
			arr[0][k] = R[0][j];
			arr[1][k] = R[1][j];
			j++;
			}

		else
			{
			arr[0][k] = L[0][i];
			arr[1][k] = L[1][i];
			i++;
			}
				
		}


		else 
		{
		arr[0][k] = L[0][i];
		arr[1][k] = L[1][i];
		i++;
		}

		k++;
	}

	while(i<m)
	{
		arr[0][k] = L[0][i];
		arr[1][k] = L[1][i];
		i++;
		k++;
	}

	while(j<n)
	{
		arr[0][k] = R[0][j];
		arr[1][k] = R[1][j];
		j++;
		k++;
	}

return ;
}


void mergeSort(int arr[2][100010], int start, int end)
{
   if(start<end)
	{
	int mid = start+ (end -start)/2;

	mergeSort(arr,start,mid);
	mergeSort(arr,mid+1,end);
	merge(arr, start,mid,end);
	}

return ;
}



int main()
{
int test, n, i;
int activities, endtime;
int arr[2][100010];

scanf("%d",&test);

while(test--)
{
	activities = 1;
	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d %d",&arr[0][i],&arr[1][i]);

	mergeSort(arr,0,n-1);

	//for(i=0;i<n;i++)
	//	printf("%d %d\n",arr[0][i],arr[1][i]);
	
	endtime = arr[1][0];

	for(i=1;i<n;i++)
	{
		//printf("current endtime:%d\n",endtime);
		if(arr[0][i]<endtime)
			continue;
		else
		{
			activities++;
			endtime = arr[1][i];
		}
	}

	printf("%d\n",activities);
}
return 0;
}