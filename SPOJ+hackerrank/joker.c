/*


enter case 1 only if v > u

if t1 < t2 then t1 else t2. 

if the joker travels one round of the tunnel in the time that batman catches him , and this is less then time2  still prefer time2

if the joker travels the tunnel length before batman entering it o/p =-1;
*/

#include<stdio.h>


	int main()
{

long int test , joker, batman, radius, gap ; 
long int i , j , k; 

double time1= 2010 , time2 = 2010, pi = 3.14 ;

double relative , distance;

scanf("%ld", &test);

for(i=0;i<test;i++)
{

time1= 2010 ;

time2 = 2010;


scanf("%ld", &radius);

scanf("%ld", &joker);

scanf("%ld", &batman);

scanf("%ld", &gap);

if(batman > joker)
{
	distance = joker*gap ;

	relative = batman - joker ; 


	time1 =  distance/relative ; 

  double num1 = 2*3.14*radius - joker*gap ; 

	if((time1*joker) > num1)
		time1 = 2015 ;
}

relative = batman + joker ; 

distance = 2*3.14*radius - joker*gap ; 

time2 = distance / relative ; 

double x = (2 *3.14*radius) / joker ; 

if(x < gap)
printf("%d\n", -1);	

else if(time1 < time2)

printf("%lf\n", time1);

else
printf("%lf\n", time2);	



}

return 0;	
}