# include <iostream>
# include <cstdio>
# include <string>
using namespace std;

int main()
{
	int n,i;
	cin>>n;

	int loop = n;
	int arr1[26], arr2[26];
	string str;
	int t = 0;

	for(i=0;i<26;i++)
	{
		arr2[i] =0;
		
	}
		

	while(loop--)
	{
	for(i=0;i<26;i++)
		arr1[i] =0;
		
		cin>>str;
		int length = str.length();

		for(i=0;i<length;i++)
		{
			arr1[str[i]-97]++;
		}
			

		for(i=0;i<26;i++)
			if(arr1[i]>0)
				arr2[i]++;
	}
	
	int count=0;
	for(i=0;i<26;i++)
		if(arr2[i]==n)
			count++;
	cout<<count<<endl;	

return 0;
}