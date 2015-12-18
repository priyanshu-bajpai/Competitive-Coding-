# include <stdio.h>


int main()
{
	int size, i;

	while(1)
	{
		scanf("%d",&size);
		if(size==0)
			break;
		int arr[size+1];
		for(i=1;i<=size;i++)
			scanf("%d",&arr[i]);

		int temp, flag=1;
		for(i=1;i<=size;i++)
			{
				temp = arr[i];
				if(arr[temp]==i)
					continue;
				printf("not ambiguous\n");
				flag = 0;
					break;
			}
			if(flag==1)
			printf("ambiguous\n");
	}
	return 0;
}
	