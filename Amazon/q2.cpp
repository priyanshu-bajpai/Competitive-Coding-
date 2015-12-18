# include <iostream>
# include <stack>
# include <algorithm>

using namespace std;


int main()
{
	int test;
	cin>>test;
	int n, i;
	int components;
	while(test--)
	{
		
		cin>>n;
		int *arr = (int *)malloc(sizeof(int)*n);
		int *visited = (int *)malloc(sizeof(int)*n);

		for(i=0;i<n;i++)
		{
			cin>>arr[i];
			arr[i]--;
			visited[i]=0;
		}
		int source;
		components = 0;

		while(1)	
		{
			for(i=0;i<n;i++)
				if(visited[i]==0)
				{
					source = i;
					break;
				}
			if(i==n)
				break;		

			while(visited[source]!=1)
			{
				visited[source]=1;
				source = arr[source];
			}
			components++;
		}
		
			
		int answer = components-1;
			cout<<answer<<endl;
	}

return 0;
}