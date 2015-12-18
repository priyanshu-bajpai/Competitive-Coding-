#include<stdio.h>
#include<string.h>


int main()
{

int testcases,i,j,k;


scanf("%d",&testcases);

for(i=0; i<testcases; i++)
{
int cities;
scanf("%d",&cities);

char a[cities][15];
int arr[cities][cities];

for(j=0; j<cities; j++)	
{
scanf("%s",&a[j]);	
		
int connected;

scanf("%d",&connected);

int ind,cost;

for(k=0; k<connected; k++)
{
scanf("%d",&ind);
scanf("%d",&cost);
	
arr[j][ind -1] = cost;
}	
		
}		

int cost[10100]={2100000},visited[10100]={0},queue[100000];

int paths,l;
scanf("%d",&paths);


for(l=0;l<paths;l++)
{
int source , dest ;
char name[10];

scanf("%s",name);

for(j=0;j<cities;j++)
if(strcmp(name,a[j])==0)
source = j;	

scanf("%s",name);
	
for(j=0;j<cities;j++)
if(strcmp(name,a[j])==0)
dest = j;	

		
queue[0]=source;
cost[source]=0;
visited[source]=1;


	
int current,n;
int advance=0, current_end=0;

while(advance<=current_end)
{
current = queue[advance];
int value;
   for(n=0; n<cities; n++)
     {
     value = cost[current] + arr[current][n];
	
    if(arr[current][n]!=0)
    if((visited[n]==0)||(value<cost[n]))
	{
	//try to check the value given to current_end and advance.
	visited[n]=1;	
	cost[n] = value; 	
	current_end++;			
	queue[current_end] = n ; 
	}
     }
    advance++;		
}	

printf("%d\n",cost[dest]);
}
	
}//testcasess...		
return 0;	
}	