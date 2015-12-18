
#include<stdio.h>

void merge(int arr[], int l, int m, int r)
{
int n1 =m-l+1 ;
int n2 =r-m ;

int L[n1], R[n2];

int i,j,k;

for(i=0;i<n1;i++)

L[i] = arr[l+i];

for(j=0;j<n2;j++)

R[j] = arr[m+1+j];	

i=0;
j=0;
k=l;

while(i<n1&&j<n2)
{
if(L[i]<R[j])
{	
arr[k] = L[i];
i++;
}

else
{
arr[k] = R[j];
j++;	
}
k++;
}

while(i<n1)
{
arr[k] = L[i];
i++;
k++;
}

while(j<n2)
{
arr[k] = R[j];	
j++;	
k++;	
}
}

void mergeSort(int arr[], int l, int r)
{
if(l<r)
{
int m = l + (r-l)/2 ; 

mergeSort(arr, l, m);
mergeSort(arr, m+1, r);
merge(arr, l, m, r);	
}	
}

int main()
{

int num, dollar;

scanf("%d%d", &num, &dollar);

int i, arr[num];

for(i=0;i<num;i++)
{
	scanf("%d", &arr[i]);
}

mergeSort(arr, 0, num-1);

int answer;

for(i=0;i<num;i++)
{
if(arr[i]<dollar)
{
answer++;
dollar -= arr[i];
}
else
break;
}

printf("%d\n",answer);
return 0;	
}