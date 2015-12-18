#include <stdio.h>

int calculate(int health, int armor)
{
	int flag =1;
	int time = 1;

	while(flag!=0)
	{
		health = health +3;
		armor = armor +2 ;
		
		if(health>5 && armor>10)
		{
			time = time + 2 ;
			health -=5;
			armor-=10;
		}
		else if(health>20)
		{
			time +=2;
			health-=20;
			armor+=5;
		}
		else
		flag=0;	
	}

	return time;
}
	
int main(int argc, char *argv[])
{
	int health, armor;
	int test;

	scanf("%d",&test);

	while(test--)
	{
		scanf("%d %d", &health, &armor);
		printf("%d\n", calculate(health, armor));
	}

	return 0;
}