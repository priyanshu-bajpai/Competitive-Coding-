#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
int test,i,j,count,value=0;

scanf("%d",&test);

int rows,columns,si,sj,di,dj,wands,masti;

while(test--)
{
scanf("%d",&rows);
scanf("%d",&columns);

char forest[rows][columns+1],gbg;

for(i=0;i<rows;i++)
{
scanf("%c",&gbg);
scanf("%s",forest[i]);
}

for(i=0;i<rows;i++)
{
for (j=0;j<columns;j++)
{ 
if(forest[i][j]=='M')
  {
    si = i;
    sj=j;	
	}
   if(forest[i][j]=='*')
  {
	di = i;
  dj = j;	
  }
}
}
int right,up,answer;
int curr_row =si,curr_col = sj;
int arr[4],last_col,last_row;

//printf("%d %d\n",curr_row,curr_col );
//printf("%d %d\n",di,dj);
while(!((curr_col==dj)&&(curr_row==di)))
{
 last_row = curr_row;
 last_col = curr_col; 
 count=0; 

 right = dj>curr_col?1:-1;
 if(dj==curr_col)
  right =0;
//printf("%d\n",right);
 up = di>curr_row?1:-1;
 if(di==curr_row)
  up = 0; 
//printf("%d\n",up);

if((curr_row!=0)&&(forest[curr_row-1][curr_col]!='X'))
 arr[2]=1;
else
  arr[2]=0;

if((curr_row!=rows-1)&&(forest[curr_row+1][curr_col]!='X'))
 arr[3]=1;
else
  arr[3]=0;
if((curr_col!=0)&&(forest[curr_row][curr_col-1]!='X'))
 arr[0]=1;
else
arr[0]=0;
if((curr_col!=columns-1)&&(forest[curr_row][curr_col+1]!='X'))
 arr[1]=1;
else
  arr[1]=0;

for(masti=0;masti<4;masti++)
{
  if(arr[masti]==1)
    count++;
}
if(count>1)
answer++;
 
if(right>0)
 {
  if(arr[1]==1)
  curr_col++;
 }
else if(right<0) 
{ 
if(arr[0]==1)  
curr_col--;
}

if(up>0)
 {
  if(arr[2]==1)
  curr_row++;
 } 
else if(up<0)
{
 if(arr[3]==1)
 curr_row--; 
} 
if((curr_col==last_col)&&(curr_row==last_row))
{
if(arr[0]==1)
  curr_col--;
else if(arr[1]==1)
  curr_col++;
else if(arr[2]==1)
 curr_row--; 
else
  curr_row++;
}
printf("%d %d\n",curr_row,curr_col );

}
scanf("%d",&wands);

if(wands==answer)
  printf("impressed!\n");
else
  printf("Oops!!\n");
}
return 0;
}



