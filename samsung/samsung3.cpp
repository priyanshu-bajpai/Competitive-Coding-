# include <iostream>
# include <string>
using namespace std;

int calculate(char * string, int i)
{
int index = i;	
if(index==strlen(string))
	return 0;							

while(string[index]!='1')
{
	index++;
if(index==strlen(string))
	return 0;
}

index++;
while(string[index]=='0')
{	
	index++;
if(index==strlen(string))
	return 0;
}

if(index<strlen(string))
	if((string[index]=='1')&&string[index-1]=='0')
		return (1 + calculate(string, index));

return calculate(string, index);

}


int main()
{
	int test;
	cin>>test;
	char string[10000];
	while(test--)
	{
		scanf("%s",string);
		int number = calculate(string,0);
	
		printf("%d\n",number);
	}
	return 0;
}