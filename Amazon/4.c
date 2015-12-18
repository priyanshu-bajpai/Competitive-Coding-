#include<stdio.h>
#include<string.h>

int main()
{
int alpha[26] = {0};
int asci, value, i, count=0;

char arr[1010];

scanf ("%[^\n]%*c", arr);

int copy[1010], length;

length = strlen(arr);

for(i=0;i<length;i++)
{
asci = arr[i];	

if(((asci>64)&&(asci<91))||((asci>96)&&(asci<123)))
{
count++;	
copy[count-1] = asci ;	
}
}

for(i=0;i<count;i++)
{
asci = copy[i];

if(asci>96)
{
value = asci -97 ;
alpha[value]=1;
}
else if(asci<91&&asci>64)
{
value =asci - 65 ;
alpha[value]=1;
}
}

for(i=0;i<26;i++)
{
if(alpha[i]==0)
{
	printf("not pangram\n");	
    return 0;
}
}

printf("pangram\n");
return 0;	
}