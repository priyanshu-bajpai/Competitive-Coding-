#include<stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] >= R[j])
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
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        merge(arr,l,m,r);
	}
}	


int main()
{
int test,i=0;

scanf("%d",&test);

while(i<test)
{
int trees,progress=0;
int answer=0;

scanf("%d",&trees);

int arr[trees],k;

for(k=0;k<trees;k++)
scanf("%d",&arr[k]);

mergesort(arr,0,trees-1);
/////implement merge sort here.....decreasing order
int j=0,diff;
int n1, n2=arr[0];

while(progress<trees)	
  {  
  n1 = arr[progress];
  diff = 0;	  	  
  while(diff == 0)	
	{			
	progress++;
	n2 = arr[progress];
	diff = n1-n2;	
    }
	
  for(j=0;j<progress;j++)
  arr[j]-=diff;
  	
  answer++;	  
  }	
 
printf("%d\n",answer); 
i++; 	 
}
return 0;		
}	