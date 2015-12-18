#include <stdio.h>
#include 	<stdlib.h>

long long int area(int num,long long int hist[num])
{
int i, top;
long long int max_area = 0, area_with_stacktop;
int *stack = (int *) malloc(sizeof(int)*(num+10));
int stacktop = -1;

i=0;
while(i<num)
{	
	if(stacktop == -1 || hist[i]>=hist[stack[stacktop]])
	{
		stacktop++;
		stack[stacktop] = i;
		i=i+1;
	}
	else
	{
		top = stack[stacktop];
		//stack[stacktop] = -1;
		stacktop--;

		//finding the area with the rectangle at stacktop as the smallest rectangle....
		area_with_stacktop = hist[top] *  ((stacktop==-1)?i+1:i-1-stack[stacktop]);

		if(max_area < area_with_stacktop)
			max_area = area_with_stacktop;
	}
}
	i--;
	while(stacktop!=-1)
	{
	top = stack[stacktop];
	//stack[stacktop] = -1;
	stacktop--;

	//finding the area with the rectangle at stacktop as the smallest rectangle....
	area_with_stacktop = hist[top] *  ((stacktop==-1)?i+1:i-1-stack[stacktop]);

	if(max_area < area_with_stacktop)
		max_area = area_with_stacktop;
	}

return max_area;
}



int main()
{
int num;

while(1)	
{	
	scanf("%d",&num);
	if(num==0)
		break;

	long long int *hist=(long long int *)malloc(sizeof(long long int)*num);
	int i=0;
	
	for(i=0;i<num;i++)
		scanf("%lld",&hist[i]);
	
	printf("%lld\n",area(num,hist));
}

return 0;

}

