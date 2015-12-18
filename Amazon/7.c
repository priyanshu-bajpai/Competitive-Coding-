#include<stdio.h>

int main()
{
int m,n,test, i, j, temp, bol=0; 

scanf("%d",&test);

while(test--)
{
scanf("%d",&m);	
scanf("%d",&n);

int arr[n];	

for(i=0;i<n;i++)
scanf("%d",&arr[i]);

for(i=0;i<n-1;i++)
{
   temp = m - arr[i];
	for(j=i+1;j<n;j++)
       if(arr[j]==temp)
       {	
       	printf("%d %d\n",i+1,j+1);
        bol=1;
       	break;
       }
       if(bol==1)
       	break;
}


}

return 0;	
}