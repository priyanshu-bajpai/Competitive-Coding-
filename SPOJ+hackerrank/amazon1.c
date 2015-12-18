#include <stdio.h>
#include <stdlib.h>

struct node
{
	char id;
	//char parent;
	//int level;
	struct node *next;
};

typedef struct node node;

void traverse(node *buckets[], int person_id)
{
 int queue[100000];
 int boolean[26] = {0};
 int front=0, end= 0;

 queue[end] = person_id;
 
 int friend_id, i;

  while(front<=end)
  {
  	printf("%c\n",queue[front]+65);
  	node *pointer = buckets[queue[front]];

    while(pointer!=NULL)
	{
		printf("%c ",pointer->id);		
		friend_id = pointer->id - 65;

		if(boolean[friend_id]==0)
		{
		end++;
		queue[end] = friend_id;
		}
		pointer = pointer->next;
	}

	front++;
  }

  return ;
}



int main(int argc, char *argv[])
{
 node *buckets[26];

 int i, person_id, friend_id;

 for(i=0;i<26;i++)
 	buckets[i] = NULL;

 char pid, fid;
 int j=0;
 for(i=0;i<3;i++) 		
 {
 	scanf("%c",&pid);	
 	person_id = pid - 65; 
 	node *pointer;
 	char temp = 'a';
 	scanf("%c",&temp);

 	while(temp!='\n')
 	{
 		scanf("%c",&fid);
 		if(buckets[person_id]==NULL)
 		{
 			buckets[person_id] = (node*)malloc(sizeof(node));
 			buckets[person_id]->id = fid;
 			printf("%c\n",buckets[person_id]->id);
 			pointer = buckets[person_id];

 		}
 		else
 		{
 			pointer->next = (node*)malloc(sizeof(node));
 			pointer->id = fid;
 			printf("%c\n",pointer->id);
 			pointer = pointer->next;
 		}	
 		scanf("%c",&temp);
 	}
 }
 	printf("input successfully taken\n\n enter the person for whom details required: ");

 	scanf("%c", &pid);
 	person_id =pid - 65;
 	printf("%d\n",person_id);
	traverse(buckets,person_id);

return 0;	
}



