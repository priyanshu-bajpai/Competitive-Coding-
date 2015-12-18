# include <iostream>
# include <cstdio>
# include <string>
using namespace std;
int main()
{
	string str;
	int length;
	int arr[26];
	int count=0, i;
	int index ;

		count=0;
		for(i=0;i<26;i++)
			arr[i]=0;
		int flag =1;
		cin>>str;
		length = str.length();

		for(i=0;i<length;i++)
			arr[str[i]-97]++;

		for(i=0;i<26;i++)
			if(arr[i]%2!=0)
			{
				if(count)
					{
						flag=0;
						break;
					}
				else
					count++;
			}

			if(!flag)
				cout<<"NO\n";
			else
				cout<<"YES\n";


		

	
	return 0;
}