#include<stdio.h>

int count1=0, count2=0;

//sorting using insertionSort..!!!
void insert(int arr[], int l, int r, int element)
{
int i=l,j;

while(element>arr[i])
i++	;

for(j=r;j>=i;j--)
{
arr[j+1] = arr[j];
count1++;
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


//sorting using quickSort...!!!
int partition(int arr[], int p, int r)
{
int i = p-1, j=p, temp;

int x = arr[r];

for(j=p;j<r;j++)
{
if(arr[j]<=x)
{
i = i+1 ;
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
count2++;
}	
}
arr[r] = arr[i+1];
arr[i+1] = x ;
count2++;
return i+1;
}

void quickSort(int arr[],int l, int r)
{
if(r>l)
{
int q = partition(arr,l,r);

quickSort(arr,l,q-1);
quickSort(arr,q+1,r);	
}	
}


int main()
{
int i, length;
scanf("%d",&length);

int arr[length],arr1[length];

for(i=0;i<length;i++)
{
scanf("%d",&arr[i]);
arr1[i]= arr[i] ;
}

insertionSort(arr,0,length-1,arr[length-1]);
quickSort(arr1,0,length-1);
printf("%d\n",count1-count2);

return 0;	
}