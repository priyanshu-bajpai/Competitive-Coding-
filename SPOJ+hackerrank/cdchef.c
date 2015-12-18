#include <stdio.h>
#include <string.h>

int main()
{
int test;
scanf("%d",&test);

char str[110];
while(test--)
{
scanf("%s",str);
//cnt =0;
int cnt=0,i;
for(i=0;i<strlen(str);i++)
	{
	 if(str[i]=='A'||str[i]=='D'||str[i]=='O'||str[i]=='P'||str[i]=='Q'||str[i]=='R')
	 	cnt++;
	 else if (str[i]=='B')
	  cnt = cnt+2;
	}

printf("%d\n",cnt);	
}

return 0;	
}