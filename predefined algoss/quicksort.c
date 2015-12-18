#include<stdio.h>

int partition(int arr[],int p, int r)
{
int j, i, temp, x;

i= p;
x= arr[r];

for(j=p;j<r;j++)
{
  if(arr[j]<=x)
  {
  temp = arr[i];
  arr[i] = arr[j];
  arr[j]=temp;
  i+=1;	
  }
}
 temp = arr[i];
 arr[i] = arr[r];
 arr[r] = temp;
 return i;
}

void quickSort(int arr[], int p, int r)
{
	int q ;
	if(p<r)
	{
	 q = partition(arr,p,r);
	 quickSort(arr, p, q-1);
	 quickSort(arr, q+1, r);
	}
}

int main()
{
int arr[10] = {1,4,7,8,3,4,6,33,2,10};
int i;

quickSort(arr,0,9);

for(i=0;i<10;i++)
printf("%d ",arr[i]);

printf("\n");

return 0;	
}