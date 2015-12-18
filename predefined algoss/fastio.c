#include <stdio.h>
#include <stdlib.h>
#define SIZE 65536
 

 
int main(int argc, char **argv)
{
	unsigned long n, k, curNum = 0, count = 0;

	int i, strLength;

	char buffer[SIZE];
	
	scanf("%lu %lu\n", &n, &k);

	while( (strLength=fread(buffer, 1, SIZE, stdin)) > 0)
	{
	
		for (i = 0; i < strLength; i++)
		{
		
			if (buffer[i] == '\n')
			{
				if (curNum % k == 0)
					count++;

				curNum = 0;
			}

			else 
				curNum = curNum*10 + (buffer[i]-'0');
		}
	}
	printf("%lu\n", count);
	return 0;
} 