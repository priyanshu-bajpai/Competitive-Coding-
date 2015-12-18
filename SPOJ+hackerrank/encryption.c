#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
char s[81];
scanf("%s",s);	
int length=strlen(s);
float a = sqrt(length);
int b = sqrt(length),column,row,i,j,k,l;

if(a>b)
{
row = b;
column = b+1;
}
else
{
row = b;
column = b;
}
if(row*column<length)
row++;
char arr[row][column];
b=0;
i=0;

for(i=0;i<row;i++)
{	
for (j=0;j<column;j++)
  {
  if(b==length)
  break;
  arr[i][j] = s[b];
  b++;	
  }

}
i--;
j--;
for(k=0;k<column;k++)
{		
if(k<=j)
{	
for (l=0;l<=i;l++)  
printf("%c",arr[l][k]);
}
else
for (l=0;l<i;l++)  
printf("%c",arr[l][k]);	

printf(" ");
}
printf("\n");
 return 0;
}