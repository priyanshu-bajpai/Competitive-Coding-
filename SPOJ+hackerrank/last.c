#include<stdio.h>


void merge(long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    long int L[n1], R[n2];
 
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
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
 
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(long int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r-l)/2; 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


int main()
{
int num,i,diff =90000000,index;

scanf("%d",&num);

long int arr[num];

for(i=0;i<num;i++)
 scanf("%ld",&arr[i]);

mergeSort(arr,0,num-1);

for(i=0;i<num;i++)
{
if((arr[i+1])-(arr[i])<diff)
diff = arr[i+1]-arr[i];
}

for(i=0;i<num;i++)
{
if((arr[i+1])-(arr[i])==diff)
printf("%ld %ld ",arr[i],arr[i+1]);
}
printf("\n");
return 0;
}

