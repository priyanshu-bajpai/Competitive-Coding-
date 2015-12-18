#include <stdio.h>


int main()
{
	int n = 1;

	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
				
		int answer = n*(n+1)*(2*n +1); 
		printf("%d\n",answer/6);
	}

return 0;
}