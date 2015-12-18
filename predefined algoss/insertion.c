#include<stdio.h>


//sorting using insertionSort..!!!
void insert(int arr[], int l, int r, int element)
{
int i=l,j;

while(element>arr[i])
i++ ;

for(j=r;j>=i;j--)
{
arr[j+1] = arr[j];
//count1++;
}
arr[i] = element ;  
}

void insertionSort(int arr[], int l, int r,int element)
{
if(r>0)
{ 
insertionSort(arr,l,r-1,arr[r-1]);
insert(arr,l,r-1,arr[r]); 
}
}


int main()
{
	int arr[10] = {1,23,45,67,43,12,12,34,56,78};
    int i;

    insertionSort(arr,0,9,78);

    for(i=0;i<10;i++)
    printf("%d ", arr[i]);
    printf("\n");
   	return 0;
}