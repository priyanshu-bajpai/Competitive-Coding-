#include <stdio.h>
#include <stdlib.h>

//quickSort algorithm.
struct node
{
int data;   
struct node *next;  
};

struct node * get_tail(struct node *head)
{
struct node *tail=head;

while((tail->next!=NULL)&&tail!=NULL)
tail=tail->next;

return tail;	
}


struct node * partition(struct node *head,struct node *tail,struct node **newhead, struct node **newend)
{

struct node *pivot = tail;
struct node *prev =NULL , *curr = head , *end = tail; 

while(curr!=pivot)
{

if(curr->data <= pivot->data)
{

	if(*newhead == NULL)
	  (*newhead) = curr;


 prev = curr;
 curr = curr->next;

}

else
{
if(prev!=NULL)	
prev->next = curr->next ;

struct node *temp = curr->next;

end->next = curr;
end = end->next;
end->next =NULL;

curr = temp;
}	
}

if((*newhead)==NULL)
	(*newhead)=pivot;


(*newend) = end;

return pivot;	
}


struct node* quickSortRec(struct node *head,struct node *tail)
{
if((head==NULL)||(head->next)==NULL)
return head;

//struct node *newhead = NULL;//,newend =NULL;

struct node *pivot = partition(head,tail,&head,&tail);

if(head!=pivot)
{
struct node *temp = head; 

while(temp->next!=pivot)
temp = temp->next;

temp->next = NULL;	

head = quickSortRec(head,temp);

temp->next = pivot;
}

pivot->next = quickSortRec(pivot->next,tail);

return head;
}

void quickSort(struct node **head)
{
(*head) = quickSortRec(head,get_tail(*(head)));
return ;	
}


int main()
{

struct node *head = (struct node*)malloc(sizeof(struct node));

struct node *point = head;

int choice=1;

while(choice==1)
{
 printf("please enter the data in the linked list: ");

 scanf("%d",&(point->data));

 printf("do you want to add more data?[1/0]");
 scanf("%d",&choice);

 if(choice==1)
 {
  point->next = (struct node*) malloc(sizeof(struct node)); 
  point = point->next;
  point->next = NULL;
 }
}

struct node *tail = point;

quickSort(head);
point = head;

while(point!=NULL)
{
printf("%d ",point->data);
point = point->next;   
}
printf("\n");
return 0;
}










































