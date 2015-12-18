#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *read_f = fopen(argv[1],"r");

	int percentage = 0;
	char ch;
	long int stringlength =0;
	ch =getc(read_f);

	//getting the size of the file
	while(ch!=EOF)
	{
		ch = getc(read_f);
		if(ch=='\n')
			continue;
		stringlength++;
	}
	printf("size of the file = %lu Bytes\n",stringlength*sizeof(char));

	fclose(read_f);
	read_f = fopen(argv[1],"r");
	FILE *write_f = fopen(argv[2],"w");
	ch = getc(read_f);

	//logic for the percentage
	//I was not able to write the percentage dynamically at the same place though ;-)
	while(ch!=EOF)
	{
		ch = getc(read_f);
		fprintf(write_f,"%c",ch);
		if(ch=='\n')
			continue;
		percentage++;
		int x = ((float)percentage/(float)stringlength)*100;
		//x= x*100;
		printf("%d%%\n",x);
		clrscr();
	}


	fclose(write_f);
	fclose(read_f);
	printf("\n");
	return 0;
}