# include <iostream>
# include <string>

using namespace std;

int main()
{

int n1, n2;
cin>>n1;
cin>>n2;

n1 = n1^n2;
int count =0;
while(n1>0)
{

if(n1%2==0)
	n1 = n1/2;

else
{
	count++;
	n1 = n1-1;
	continue;
}
}

cout<<count<<'\n';
return 0; 
}