#include <stdio.h>

int queue[1010], stack[1010], array[1010];
int stack_top =0;
int queue_front = 0;


int fortune_teller(int trucks)
{
stack_top =-1;
queue_front = -1;
int i;

for(i=0;i<trucks;i++)
{
	int element = array[i];

	if((queue_front==-1 && element==1) || element==(queue[queue_front]+1)) 
	{
		queue_front++;
		queue[queue_front] = element;
		//printf("queue_front = %d\n",queue[queue_front]);
	}
	else if(stack_top==-1 || stack[stack_top]>element)
	{		
		stack_top++;
		stack[stack_top]=element;
		//printf("stack_top = %d\n",stack[stack_top]);
	}
	else
	{
		while(stack_top>=0 && (stack[stack_top] < element))
		{
			//printf("while loop entered\n");
			int temp = queue[queue_front]+1;
			if(stack[stack_top]!=temp)	
				return 0;
			
			else 
			{
				queue_front++;
				queue[queue_front] = stack[stack_top];
				//printf("queue_front = %d\n",queue[queue_front]);
				stack_top--;
				
			}
		}

		stack_top++;
		stack[stack_top] = element;
		//printf("stack_top = %d\n",stack[stack_top]);
	}
		
}

return 1;
}


int main()
{
	int trucks;
	while(1)
	{
		scanf("%d",&trucks);
		if(trucks==0)
			break;
		int i;
		for(i=0;i<trucks;i++)
			scanf("%d",&array[i]);

		int answer = fortune_teller(trucks);
		//printf("%d\n",answer);
		if(answer==0)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}