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
        if (R[j]>=L[i])
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
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r-l)/2; //Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
 









int main()
{


int test, i, j, k = 0 ;

scanf("%d", &test);

for(i=0;i<test;i++)
{

int size , left, right;

scanf("%d", &size);

int arr[size] , arr1[size] ; 

for(j=0;j<size;j++)
{
scanf("%d", &arr[j]);	

arr1[j] = arr[j] ; 
}

mergeSort(arr1 , 0 , size-1);

//for(k=0;k<size;k++)

//printf("%d ", arr1[k]);

scanf("%d", &left);
scanf("%d", &right);

int val1 , val2 ; 

val1 = arr1[left -1];

val2 = arr1[right -1] ; 

long int code , number; 

k=0; 

number = arr[k];
while(number != val1)
{
k++;	
number = arr[k];	
}	

code = number ; 



while(number!= val2)
{
k++;	
number = arr[k];	
code = code*number ; 

}

printf("%ld\n",code);
long int  divide = 1000000000 + 9 ;

int answer = code % divide;

printf("%d", answer);

}	

return 0 ; 	
}