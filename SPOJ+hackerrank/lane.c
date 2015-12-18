#include<stdio.h>

int main()
{
int length, test, i,j,k, temp;

scanf("%d",&length);
scanf("%d",&test);

int arr[length];

for(i=0;i<length;i++)
scanf("%d",&arr[i]);

while(test--)
{
scanf("%d",&i);
scanf("%d",&j);

temp=arr[i];

for(k=i+1;k<=j;k++)
{
if(arr[k]<temp)
temp = arr[k];
}	
printf("%d\n",temp);
}
return 0;
}