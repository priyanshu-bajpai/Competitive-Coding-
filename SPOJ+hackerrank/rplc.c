#include <stdio.h>
#include <stdlib.h>


int main()
{
	 int test, number=0;
	 int n;
	 scanf("%d",&test);

	 while(test--)
	 {
	 	scanf("%d",&n);
	 	int i,temp1;
	 	long long int answer = 0, temp2 =0;

	 	for(i=0;i<n;i++)
	 	{
	 		scanf("%d",&temp1);
	 		temp2 = temp1+temp2;
	 		if(temp2<answer)
	 			answer = temp2;
	 	}
	 	number++;
	 	if(answer<0)
	 		{answer = answer*(-1);
	 		printf("Scenario #%d: %lld\n",number,answer+1);}
	 	else
	 		printf("Scenario #%d: 1\n",number);	
	 	
	 }
}