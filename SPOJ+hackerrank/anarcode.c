#include<stdio.h>

int prime(int num)
{

}

int main()
{
	
int i=2,j=0,m,n,count=0,count1=0,t;

scanf("%d",&m);
scanf("%d",&n);
t=m;

int arr1[10]={0};
count=-1;  /*i=2;j=0;t=m;*/
while(t!=1)
{
if((prime(i)==1)&&(j==0))
	count++;
j=0;

if(t%i==0&&prime(i)==1)	 
{
t=t/i;
arr1[count]++;
}
if((t%i)!=0)
i++;
else j++;	
}

int arr2[10]={0};
count1=-1;i=2;j=0;t=n;
while(t!=1)
{
if((prime(i)==1)&&(j==0))
	count1++;
j=0;

if(t%i==0&&prime(i)==1)	 
{
t=t/i;
arr2[count1]++;
}
if((t%i)!=0)
i++;
else j++;	
}

m=0;n=0;
for(i=0;i<count;i++)
if(arr1[i]!=0)
	m++	;
for(i=0;i<count1;i++)
if(arr2[i]!=0)
	n++	;
t=m>n?m:n;

int distance=0,mod;
for(i=0;i<t;i++)
{
mod = (arr1[i]-arr[i])?	(arr1[i]-arr[i]):(arr[i]-arr1[i]);
distance = distance+mod;	
}

}