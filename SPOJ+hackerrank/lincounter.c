#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{
	FILE *fp = fopen(argv[1],"r");
	int isEOF = 0;
	int lineCounter = 0;
	char ch = '\n';
	while(ch!=EOF)
	{
		fscanf(fp,"%c",&ch);
		if(ch=='\n')
			continue;
		if(ch=='/')
		{
			if()
		}
	}

	return 0;
}