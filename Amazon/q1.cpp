# include <iostream>
# include <stack>
# include <algorithm>

using namespace std;

bool func(int i, int j)
{
	return i>j;
}

int main()
{
	int arr[10];

for(int i=0;i<10;i++)
	cin>>arr[i];

	sort(begin(arr),end(arr),func);
	int sum =0;

	sum = arr[0]+arr[4]+arr[2]; 
	cout<<sum;

return 0;
}