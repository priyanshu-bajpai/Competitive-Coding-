#include <stdio.h>


int main()
{
int test;

scanf("%d",&test);

int  num2;

long int answer;

char ch;

while(test--)
 {

  scanf("%c",&ch);

  while(scanf("%c",&ch) != '=')
  {
   answer = ch -'0' ;
   
   //scanf("%c",&ch);

   scanf("%c",&ch);
   
   scanf("%d",&num2);

   if(ch == '+')
   answer = answer + num2 ;
   
   else if(ch =='-')
   answer = answer - num2 ;

   else if(ch =='*')
   answer = answer * num2;

   else if(ch =='/')
   answer = answer/num2;
  
   scanf("%c",&ch);

  }

  printf("%ld\n",answer);
 }

 return 0;
}