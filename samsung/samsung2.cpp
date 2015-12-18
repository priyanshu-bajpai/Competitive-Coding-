# include <iostream>
# include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while((cin>>n)!=0)
	{
		while(n>0)
		{
			char c = n%26 + 96; 
			cout<<c<<"/n";
			n = n/26;                                                                                                                                  
		}
	}
	return 0; 
}