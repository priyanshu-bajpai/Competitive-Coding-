#include<stdio.h>
#include<string.h>
	

int main()
{
	
char a[15];

scanf("%s",a);

int length = strlen(a),i,j;

printf("%d\n",length);
int arr[126]={0},c;

int denominator=1,numerator=1;
	
for(i=1;i<=length;i++)
{
c = a[i-1];
printf("%d ",c);
arr[c]= arr[c]+1;
numerator*=i;		
}		


printf("\n%d\n",numerator);

for(i=97; i<123; i++)
for(j=arr[i]; j>0; j--)
denominator *= j ;	
	

printf("%d\n",denominator);

int answer = numerator/denominator;

printf("%d\n",answer);	

return 0;	
}	