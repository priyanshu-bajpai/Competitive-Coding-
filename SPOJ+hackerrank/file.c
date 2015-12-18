#include <stdlib.h>
#include <stdio.h>

int main()
{

FILE *fp ; 

int temp, arr[300][3], i =0, j, sum =0;

char c;

if((fp=fopen("input.txt","r"))==NULL)
{
	printf("cannot open the file\n");
	exit(1);
}
else
{
	while((c=fgetc(fp))!=EOF)
    {
    	if(c !='\n'&&c !=' ')
    	{
    		temp = c - '0';
    		sum = sum + temp;
            printf("%d",temp);
            arr[i][j] = temp;
    	} 

    	if(c == '\n' )
    	i++;

        j++;
        if(j>2)
        	j=0;
    }
}

fclose(fp);
getchar();
return 0;	
}