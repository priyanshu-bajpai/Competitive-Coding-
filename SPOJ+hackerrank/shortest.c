#include<stdio.h>
#include<string.h>

int cities ;

void merge(int arr[2][cities], int l, int m, int r)
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
        if (R[1][j]<=L[1][i])
        {
           arr[0][k] = L[0][j];
           arr[1][k] = L[1][i];
            i++;
        }
        else
        {
           arr[0][k] = R[0][j];
           arr[1][k] = R[1][j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
    	arr[0][k] = L[0][j];
        arr[1][k] = L[1][i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
    	arr[0][k] = R[0][j];
        arr[1][k] = R[1][j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(int arr[2][cities], int l, int r)
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

int test, city, queries, cities ;

int i , j , k, l, source, dest, connected ; 

scanf("%d", &test);

while(test--)
{

scanf("%d", &cities);

int arr[cities][cities], connected, index, queries;
char city[cities][10], arr1[10];

for(i=0;i<cities;i++)
{

scanf("%s", &city[i]);
scanf("%d", &connected);

for(j=0;j<connected;j++)
{
scanf("%d", &index );
scanf("%d", &arr[i][index-1]);
}
}//scannin data for cities.

scanf("%d", &queries);

for(i=0;i<queries;i++)
{
scanf("%s", arr1);

for(j=0;j<cities;j++)
{
if(strcmp(arr1,city[j])==0)
{
source = j;
break;	
}
}
scanf("%s", arr1);

for(k=0;k<cities;k++)
{
if(strcmp(arr1,city[k])==0)
dest = k;
break;	
}
/////
int heap[2][10], boolean[10] = {0}; 
int point=0, tail=0, cost;

 heap[0][point] = source ;
 heap[1][point] = 0 ;
 boolean[source] = 1 ;

while((point<=tail)&&heap[0][point]!=dest)
{
for(l=0;l<10;l++)
{
if(arr[heap[0][point]][l]!=0)
if(boolean[l] ==0)
{	
tail++;	
cost = heap[1][heap[0][point]] + arr[heap[0][point]][l] ; 

heap[0][tail] = l ;
heap[1][tail] = cost ;
}
}

mergeSort(heap, point+1, tail);    //apply merge sort from point till to the tail .

point++;

boolean[heap[0][point]] = 1;


}
////

printf("%d\n", heap[1][dest]);
}



}//test cases loop


return 0 ;	
}
