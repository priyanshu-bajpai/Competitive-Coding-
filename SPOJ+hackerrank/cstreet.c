#include<stdio.h>

int roads ; 

void merge(int arr[3][roads], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[3][n1], R[3][n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
       {
        L[0][i] = arr[0][l + i];
         L[1][i] = arr[1][l + i];
          L[2][i] = arr[2][l + i];
       }

    for(j = 0; j < n2; j++)
     {	
        R[0][j] = arr[0][m + 1+ j];
        R[1][j] = arr[1][m + 1+ j];
        R[2][j] = arr[2][m + 1+ j];
 
     }
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (R[2][j]<=L[2][i])
        {
            arr[0][k] = L[0][i];
            arr[1][k] = L[1][i];
            arr[2][k] = L[2][i];
            i++;
        }
        else
        {
            arr[0][k] = R[0][i];
            arr[1][k] = R[1][i];
            arr[2][k] = R[2][i];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[0][k] = L[0][i];
        arr[1][k] = L[1][i];
        arr[2][k] = L[2][i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        
        arr[0][k] = R[0][i];
        arr[1][k] = R[1][i];
        arr[2][k] = R[2][i];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[3][roads], int l, int r)
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

int test , cost, building ;

int i, j, k;

/*1. input the data in 3*roads array;simultaneously 

  2. sort according to the length
  3.and change all three values of the rows simlutaneoulsy;

  4.take a boolean array,and mark the key of the nodes (equal) while   while adding their size feilds and changing them to the added values, 
  and making their keys equal. // initially the size feild =1 and key equa to the the respective node values. //

  5.each time adding a new edge to our tree add its value  to the result feild.

  answer =   total edge  size * cost

*/

scanf("%d", &test);

for(i=0;i<test;i++)
{

scanf("%d", &cost);

scanf("%d", &building);

scanf("%d", &roads);

int arr1[3][roads], arr2[2][building] ;

for(j=1;j<=building;j++)
{
	arr2[0][j-1] = j ; 
    arr2[1][j-1] = 1 ;
}

for(j=0;j<roads;j++)
	for(k=0;k<3;k++)
		scanf("%d",arr1[k][j]);

mergeSort(arr1, 0, roads -1);	






}
return 0;

}