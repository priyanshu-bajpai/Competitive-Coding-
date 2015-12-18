#include<stdio.h>

int p,q,val_p,val_q,arr[800000],dist=0,i=0,k,m;


int main()
{
int testcase=0,index;	
arr[0]=2;

scanf("%d",&p);
scanf("%d",&q);	
while(p!=0||q!=0)
{
index =0;	
dist =0;
while(p>1||q>1)
{
val_p=0;
val_q=0;
while(p%arr[i]==0)	
{
p/=arr[i];	
val_p++;
}
while(q%arr[i]==0)
{
q/=arr[i];	
val_q++;
}
if(val_p>val_q)
dist+=val_p-val_q;
else
dist+=val_q-val_p;
if(p>1||q>1)
{		
int temp = index+1;	
m=arr[index]+1;
while(index!=temp)
{
for(k=0;k<=index;k++)	
{
if(m%arr[k]==0)
break;
else if(k==index)
 {
	arr[k+1]=m;
	index++;
	break;	
  }
}
m++;		
}
}
i++;
}
testcase++;
printf("%d. %d:%d\n",testcase,index,dist);
scanf("%d",&p);
scanf("%d",&q);	
}
return 0;
}