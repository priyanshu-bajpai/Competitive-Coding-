#include<stdio.h>
#include<string.h>

int main()
{
int column;
scanf("%d",&column);
while(column)
{
char arr[300];
scanf("%s",arr);

int row = strlen(arr)/column;
int ans[row][column],i,j,t=0;

for(i=0;i<row;i++)
{
if(i%2==0)		
for(j=0;j<column;j++)
{
ans[i][j]=arr[t];
t++;	
}	
else
for(j=column-1;j>=0;j--)
{
ans[i][j] = arr[t];
t++;		
}
}
for(i=0;i<column;i++)
for(j=0;j<row;j++)
printf("%c",ans[j][i]);	
printf("\n");
scanf("%d",&column);
}		
return 0;				
}	