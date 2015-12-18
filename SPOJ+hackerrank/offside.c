#include <stdio.h>


int main()
{
	int attackers, defenders;

	while(1)
	{
		scanf("%d %d",&attackers,&defenders);

		if(attackers==0&&defenders==0)
			break;
		else if(attackers==0)
			printf("N\n");
		else 
		{
			int min_def=10000, second_min_def=10000;
			int min_attacker=100000, temp;
			int i;
			for(i=0;i<attackers;i++){
				scanf("%d",&temp);
				if(temp<min_attacker)
					min_attacker = temp;	
			}

			for (i=0;i<defenders;i++)
			{
				scanf("%d",&temp);
				if(temp<min_def)
				{
					second_min_def = min_def;
					min_def = temp;
				}
				else {
					if(temp<second_min_def)
						second_min_def = temp;
				}
			}

			if(min_attacker<second_min_def)
				printf("Y\n");
			else
				printf("N\n");
				
		}

	}

	return 0;
}