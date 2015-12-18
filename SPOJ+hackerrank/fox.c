#include<stdio.h>

int size ;

void merge(int arr[2][size], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[2][n1], R[2][n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
       { 
       	L[0][i] = arr[0][l + i];
       	L[1][i] = arr[1][l + i];

       }

       }
    for(j = 0; j < n2; j++)
     {
     R[0][j] = arr[0][m + 1+ j];
     R[1][j] = arr[1][m + 1+ j];
      }
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
 
   
    while (i < n1 && j < n2)
    {
        if ((R[0][j]+R[1][j])>=(L[0][i]+L[1][i])
        {
            arr[1][k] = L[1][i];
            arr[0][k] = L[0][i];

            i++;
        }
        else
        {
            arr[1][k] = R[1][i];
            arr[0][k] = R[0][i];

            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[1][k] = L[1][i];
        arr[0][k] = L[0][i];

        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[1][k] = R[1][i];
        arr[0][k] = R[0][i];

        j++;
        k++;
    }
}


void mergeSort(int arr[2][size], int l, int r)
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

int test ;

scanf("%d", &test);

int i, j, k;

for(i=0;i<test;i++)
{

scanf("%d", &size);


int c[2][size] ; 


for(j=0;j<size;j++)
      {
	 scanf("%d",&c[i][0]);
	 scanf("%d",&c[i][1]);
      }

mergeSort(c, 0, size -1);

double  max1 = c[0][0] -c[0][size-1] ;
double  max2 = c[1][0] -c[1][size-1] ;

double answer = (max1 + max2)/2;

printf("%lf\n", answer);

 }

return 0 ;	
}