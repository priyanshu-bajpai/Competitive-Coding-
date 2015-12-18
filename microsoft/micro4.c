#include <stdio.h>
#include <stdlib.h>
int end= -1;
struct fresh{
int i,j;
struct fresh *next;
};

typedef struct fresh fresh ;
typedef struct 
{
int i,j;
int rotten_time;
}rotten;

fresh * populate(int m, int n,int matrix[m][n], rotten queue[m*n])
{
	int i,j;
	fresh * head =NULL;
	fresh *tail = head;
	for(i=0;i<m;++i)
		for(j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]); 	
			if(matrix[i][j]==2)
			{
				end++;
				queue[end].i = i;
				queue[end].j = j;
				queue[end].rotten_time = 0;			
			}

			else if(matrix[i][j]==1)
			{
				if(head==NULL)
				{
					head = (fresh*)malloc(sizeof(fresh));
					tail = head;
				}
				else
				{
					tail->next = (fresh*)malloc(sizeof(fresh));
					tail = tail->next ;
					tail->i = i;
					tail->j = j;
					tail->next =NULL;
				}
			}
		}
			
return head;
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	int matrix[m][n];
	rotten queue[m*n];
	fresh *head = populate(m,n,matrix,queue);
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++)
			printf("%d ",matrix[i][j]);
		printf("\n");			
			}

		for(i=0;i<=end;i++)
			printf("%d %d\n",queue[i].i, queue[i].j);
		fresh *pointer =head;
		printf("\n\n");
		while(pointer!=NULL)
		{
			printf("%d %d\n",pointer->i, pointer->j);
			pointer = pointer->next;
		}			


		//logic for the vrus spreading
	return 0;
}