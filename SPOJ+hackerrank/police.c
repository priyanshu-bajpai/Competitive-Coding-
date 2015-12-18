#include <stdio.h>

int main()
{
int test;

scanf("%d",&test);

while(test--)
{
int stations, time2;

scanf("%d %d",&stations,&time2);

int sarr[stations][stations], rarr[stations][stations], dist[110] = {9999999};

int heap[2][250], time1[110]= {99999999};
int i,j, value, tail = 0,head = 0, index;

dist[0] = 0;
time1[0] = 0;

for(i=0;i<stations;i++)
for(j=0;j<stations;j++)
scanf("%d",&sarr[i][j]);

for(i=0;i<stations;i++)
for(j=0;j<stations;j++)
scanf("%d",&rarr[i][j]);


index =0;

while(index!=(stations-1))
 {
//printf("%d  ",index);
 for(i=0;i<stations;i++) //taking all vertices which present node is connected to ,adding them to heap if they already have not been discovered.
{	
	if(rarr[index][i]!=0)
	{
		printf("%d ",rarr[index][i]);
     value = rarr[index][i] + dist[index];
     
     if(dist[i]>value)
      {
      	time1[i] = time1[index] + sarr[index][i] ;
      	dist[i] = value;
	    heap[0][tail] = i ;
	    heap[1][tail] = value;
	    tail++;
	  }
	}
}

//finding the minimum out of the heap and putting it at the head.
for(i=head+1;i<=tail;i++)
{
 if(heap[1][i]<heap[1][head])
 {
 value = heap[1][head];
 heap[1][head] = heap[1][i];
 heap[1][i] = value;
 index = heap[0][i];
 heap[0][i] = heap[0][head];
 heap[0][head] = index;	
 }
}	
//finally we have the minimum value at the head with its index in index;

head ++;
}
if(time1[stations-1]<=time2)
printf("%d %d\n",dist[stations-1],time1[stations-1]);

else 
printf("-1\n");
}

return 0;	
}