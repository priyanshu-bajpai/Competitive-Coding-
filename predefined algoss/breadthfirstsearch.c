
void bfs(int source, int arr[][cities], int cost[], int visited[], int queue[])
{
int current,i;
int advance=0, current_end=0;

while(advance<=current_end)
{
current = queue[advance];
int value;
for(i=0; i<cities, i++)
{
value = cost[current] + arr[current][i];
	
if(arr[current][i]!=0)
if((visited[i]==0)||(value<cost[i]))
{
visited[i]=1;	
cost[i] = value; 	
current_end++;			
queue[current_end] = i ; 
}
}
advance++;		
}		
}	