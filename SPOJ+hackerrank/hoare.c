#include<stdio.h>



int partition(int arr[], int p, int r)
{
int x = arr[p], temp;

int j = r+1, i = p-1;

while(true)
{
do
{
j--;	
}	
while(arr[j]>=x)

do
{
i++;	
}	
while(arr[i]<=x)

if(i<j)
{
temp = arr[i];

arr[i] = arr[j];

arr[j] = temp;
	
}
else	
return j;		
}

}