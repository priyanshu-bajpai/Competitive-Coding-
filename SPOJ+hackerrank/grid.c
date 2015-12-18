#include<stdio.h>
#include<string.h>

int main()
{
int test,row1,row2,column1,column2;
scanf("%d",&test);
while(test--)
{
int count=0;	
scanf("%d",&row1);
scanf("%d",&column1);

char arr[row1][column1];
int i,j;
for(i=0;i<row1;i++)
 scanf("%s",arr[i]);

scanf("%d",&row2);
scanf("%d",&column2);

char arr1[row2][column2];

for(i=0;i<row2;i++)
 scanf("%s",arr1[i]);

int k,l;
for(i=0;i<row1;i++)
for(j=0;j<column1;j++)
{
 l=0;
 k=0;	
 if(arr1[k][l]==arr[i][j])
 {
   count=0;	
    for(k=0;k<row2;k++)
     {
  	  for(l=0;l<column2;l++)
      {
      if((j+l<=column1)&&(k+i<=row1))
       {	
       if(arr[k+i][j+l]!=arr1[k][l])
        break;
       count++;
      }
      }
     if(count!=(k+1)*column2) 
      break;	
     }
  if(count==(row2*column2))
  break;    
 }
  if(count==(row2*column2))
  break; 	
}

if(count==(row2*column2))
 printf("YES\n");
else
 printf("NO\n");	
}

return 0;
}