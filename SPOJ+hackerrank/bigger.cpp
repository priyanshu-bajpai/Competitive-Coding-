 #include <iostream>
 # include <cstdio>
# include <string>
# include <algorithm>
using namespace std;
/*base = arr[0];
	int index;
	int val = 10000;

	for(i=1;i<length;i++)
		if(arr[i]>base&& arr[i]<val)
		{
			val = arr[i];
			index = i;
		}

	if(val==10000)
	{
		cout<<"no answer";	
		continue;
	}

	else
	{
		arr[0]= arr[index];
		arr[index] = base;

		sort(arr+1,arr+length);
		
			
	}*/
int main()
{
	int test, i, j;
	cin>>test;
	char str[1000];
	int base;
	int smallest;
	char ch;
	int *arr = (int *)malloc(sizeof(int)*1000);
	while(test--)
	{

	scanf("%s",str);
	int length = strlen(str);//str.length();
	

	for(i=0;i<length;i++)
		arr[i] = str[i];

	for(i=0;i<length;i++)
		cout<<arr[i]<<" ";

	int flag =1;
	int noanswer = 0;

	for(i=length-1;i>=0;i--)
	{

		if(i==0)
		{
			cout<<"no answer";
			noanswer=1;
			break;
		}
			
		else
		{
			for(j=i-1;j>=0;j--)
			{
				if(arr[j]<arr[i])
				{
					flag = 0;
					break;
				}
			}
		}

		if(flag==0)
			break;

	}	
			
	if(noanswer)
		continue;

	else
	{
		int temp = arr[i];

		arr[i] =arr[j];
		arr[j] = temp;

		sort(arr+j+1,arr+ i);
		for(i=0;i<length;i++)
		{
			ch = arr[i];
			cout<<ch;
		}
		cout<<endl;
	}
	
	}
	
	return 0;
}