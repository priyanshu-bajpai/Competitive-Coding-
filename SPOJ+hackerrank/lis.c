#include<stdio.h>

int Lis(int arr[], int n)
{
	int i,j,result[n];

	for(i=0;i<n;i++)
		result[i] =1;

	int max =0;

	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(arr[i] > arr[j] && result[i] < result[j]+1)
				result[i] = result[j] +1;
		
		for(i=0;i<n;i++)
			if(max<result[i])
				max = result[i];

return max;			

}

int main()
{
int arr[100];
int n,i;
scanf("%d",&n);

for(i=0;i<n;i++)
	scanf("%d",&arr[i]);

printf("%d\n",Lis(arr,n));

return 0;
}