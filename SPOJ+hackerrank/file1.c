#include<stdio.h>

int length;

int partition(int arr[],int p, int r)
{
int j, i, temp, x;

i= p-1;
x= arr[r];

for(j=p;j<r;j++)
{
  if(arr[j]<=x)
  {
  i+=1;
  temp = arr[i];
  arr[i] = arr[j];
  arr[j]=temp;	
  }
}
 temp = arr[i+1];
 arr[i+1] = arr[r];
 arr[r] = temp;
 return i+1;
}

void quickSort(int arr[], int p, int r)
{
	int q,j ;
	if(p<r)
	{
	 q = partition(arr,p,r);
	 for(j=0;j<length;j++)
     printf("%d ",arr[j]);

     printf("\n");
	 quickSort(arr, p, q-1);
	 quickSort(arr, q+1, r);
	}
}

int main()
{
int size;

scanf("%d",&size);

length = size ;
int arr[size];
int i;

for(i=0;i<size;i++)
scanf("%d",&arr[i]);

quickSort(arr,0,size-1);

return 0;	
}