#include <stdio.h>

int main()
{
int tree[10000]={0};

int test,height, days;

int children, i, j, count;

scanf("%d",&test);
while(test--)
{
   tree[0] = 1;

  children = 1;

  count =0;

  scanf("%d",&height);
  scanf("%d",&days);

for(i=1;i<days;i++)       //each day we have to perform some changes.
{

  for(j=children-1;j>=0;j--)   //we initiate the values of children of a particular node
                            // right child incremented and left child decremented 
  {

   tree[j*2] = tree[j]+1;

   if(tree[j]==0)
   tree[(j*2)+1] = 0 ;

   else
   tree[(j*2)+1] = tree[j] - 1 ;
  } 

 //multiply j by 2 everytime
  children *= 2 ;
 }

// children/=2;

for(i=0;i<children;i++)
	printf("%d ",tree[i] );

for(i=0;i<children;i++)
{
if(tree[i]>=height)
	count++;
}

printf("%d\n",count);
}

return 0;	
}