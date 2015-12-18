#include<stdio.h>
#include<string.h>

int main()
{
int num ,length,times,i,j; 

char word[100];

scanf("%s",word);

while(strlen(word)!=1)
{	

num = strlen(word);

scanf("%d",&times);

length = times*num ; 

char arr[num][length];

int k = 0;

for(i=0;i<times;i++)
{	

 for(j=0;j<num;j++)
 {
  arr[0][k] = word[j];	
  k++;
 }

}

for(i=1;i<num;i++)
 for(j=0;j<length;j++)
 {	
   arr[i][j] = arr[i-1][j+1];	
   if(j==length -1)
   	arr[i][j] = arr[i-1][0];
 }
for(i=0;i<num;i++)
{	
for(j=0;j<length;j++)
printf("%c",arr[i][j]);
printf("\n");
}

scanf("%s",word);


}
return 0;	
}