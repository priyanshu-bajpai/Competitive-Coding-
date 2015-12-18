#include<stdio.h>

int arr[1000][1000]={0},lowestprice,price=999999,p,q;


void find_shortest(int j,int cost)
{
int temp_price=1000000,k,temp;	
if(arr[j][0]!=0)
{
temp_price=cost+arr[j][0];
if(temp_price<price)
price=temp_price;
}
for(k=1;k<p;k++)
if(arr[j][k]!=0)
{		
temp = arr[k][j];
arr[k][j]=0;
find_shortest(k,cost+arr[j][k]);
arr[k][j]=temp;
}
}	

int main()
{
	int i,j,row,col,end=1,index=0,temp,maxval;
	int price,test,que=1;
    int marked[1000]={0},queue[1000],dist[1000];
    long int total=0;
	queue[0]=0;
	dist[0]=0;
	marked[0]=1;
	scanf("%d",&test);
	
while(test>0)
{
			scanf("%d",&p);
			scanf("%d",&q);
			for(i=0;i<q;i++)
			{
				scanf("%d",&row);
				scanf("%d",&col);
				scanf("%d",&price);
				arr[row-1][col-1]=price;
			}
			
						
while(index!=end)
{
	
for(col=0;col<p;col++)
{
	temp = arr[col][index];
	arr[col][index]=0;
	 if(arr[index][col]!=0)
{
		if(marked[col]==0)	  
		{
		queue[end]=j;
		dist[col]=dist[index]+arr[index][j];
	    end++;
		marked[col]=1;
		}
		   
	 else
		{
		 maxval= dist[index]+arr[index][col];
		 if(maxval<dist[col])
		 dist[col]=maxval;	
	    } 
}
      arr[col][index]=temp;	
	  				
}	
index++;			
}	
/*abhi tak ka paisa*/
for(i=0;i<row;i++)
total +=dist[i];

/*shortest path price between every node and the ccs vertex..*/
for(i=1;i<p;i++)
{
lowestprice=1000000;	
if(arr[i][0]!=0)	
lowestprice=arr[i][0];

for(j=1;j<p;j++)
if(arr[i][j]!=0)
{		
temp = arr[j][i];
arr[j][i]=0;
find_shortest(j,arr[i][j]);
arr[j][i]=temp;
}

if(price<lowestprice)
lowestprice=price;		

total=total+lowestprice;
}
printf("%ld",total);	
test--; 	
}	

}