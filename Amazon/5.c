#include<stdio.h>

int main()
{
int num, i, j;

scanf("%d",&num);

char arr[num][num];
int copy[num][num],num1,num2,num3,num4,num5 ;

for(i=0;i<num;i++)
{
scanf("%s",&arr[i]);
for(j=1;j<num-1;j++)
copy[i][j] = 1;
}

for(i=1;i<num-1;i++)
for(j=1;j<num-1;j++)
{
if(copy[i][j]==1)
{
	num1 = arr[i][j]-'0';
	num2 = arr[i-1][j]-'0';
	num3 = arr[i+1][j]-'0';
	num4 = arr[i][j-1]-'0';
    num5 = arr[i][j+1]-'0';
	if((num1>num2)&&(num1>num3)&&(num1>num4)&&(num1>num5))
	{
    copy[i][j+1] = 0;
    copy[i][j-1] = 0;
    copy[i-1][j] = 0;
    copy[i+1][j] = 0;
    arr[i][j] = 'X';
	}	
}
}
for(i=0;i<num;i++)
{
for(j=0;j<num;j++)
printf("%c",arr[i][j]);	
printf("\n");
}

return 0;	
}