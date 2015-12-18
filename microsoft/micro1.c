# include <stdio.h>

int max(int a, int b)
{
	if (a>b)
	return a;
return b;
}

int find_common(int arr1[], int arr2[], int arr3[], int size)
{
	int i= 0, j=0, k= 0;
	int common = 0;
	while(i<size&&j<size&&k<size)
	{	
		//printf("loop i = %d, j= %d,k= %d\n",i,j,k);

		if(arr1[i]==arr2[j]&&arr2[j]==arr3[k])
			{
				printf("%d\n",arr1[i]);
				i++;
				j++;
				k++;
				common++;
			}

		else{
			int largest = max(max(arr1[i], arr2[j]),arr3[k]);
			//printf("%d\n",largest);	
			while(arr1[i]<largest)
				i++;
			while(arr2[j]<largest)
				j++;
			while(arr3[k]<largest)
				k++;
		}
	}
	if(common==0)
	return -1;

	return 1;
}
int main()
{
	int arr1[]= {1,3,5,6,10,100,101,200}, arr2[]= {2,4,8,10,101,150,151,200}, arr3[]= {4,8,9,11,101,200,301,302}; 
	int size = sizeof(arr1)/sizeof(arr1[0]);
	//printf("started\n");

	if(find_common(arr1,arr2,arr3,size)==1)
		printf("These are the common elements...\n"); 
	else
		printf("No  common elements found\n");

	return 0;
}