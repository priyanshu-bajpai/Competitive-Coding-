#include <stdio.h>

void insert(int hotness, int *table)
{
	table[hotness]++;
}

long long int find_sum(int *table_m, int *table_w)
{
	long long int sum = 0 ;

	int i = 10, j = 10;

	while((i!=0)&&(j!=0))
	{
		while(table_m[i]!=0 && table_w[j]!=0)
		{
			sum = sum + i*j;
			table_w[j]--;
			table_m[i]--;
		}

		if(table_w[j]==0)
			j--;
		if (table_m[i]==0)
			i--;
	}

	return sum ;
}


int main()
{
	int test, i;
	int table_m[11];
	int table_w[11];

	scanf("%d",&test);

	while(test--)
	{
	for(i=0;i<11;i++)
		{
			table_m[i] = 0;
			table_w[i] = 0;
		}
	
	int n, hotness;

	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%d",&hotness);
		insert(hotness,table_m);
	}

	for(i=0;i<n;i++){
		scanf("%d",&hotness);
		insert(hotness,table_w);
	}

	printf("%lld\n",find_sum(table_w, table_m));
	}
	return 0;
}



