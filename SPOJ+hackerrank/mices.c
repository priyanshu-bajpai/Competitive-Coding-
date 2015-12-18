#include <stdio.h>


int main()
{
int test;

scanf("%d",&test);

int mices ,answer;


while(test--)
{
    answer = 0;

	scanf("%d",&mices);

	while(mices/2>=3)
	{
     answer = answer + 2;
     
     mices = mices/2;
	}

answer = answer + 2;

printf("%d\n",answer);

}

return 0;	
}