# include <iostream>
# include <cstdio>
# include <string>

using namespace std;

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

node*reverse(node *curr, node *prev)
{

if(!curr)
	return prev;
node *temp = curr->next;
curr->next = prev;

return reverse(temp, curr);
}



int main(int argc, char *argv[])
{
node *head = (node*)malloc(sizeof(node));
head->data = 12;
cout<<head->data<<endl;
head->next = (node*)malloc(sizeof(node));
node *temp = head->next;
temp->data = 34;
cout<<temp->data<<endl;
temp->next = (node*)malloc(sizeof(node));
temp = temp->next;
temp->data = 65;
temp->next=NULL;
cout<<temp->data<<endl;
temp = head;
while(temp)
{	
	cout<<temp->data<<" ";
	temp = temp->next;
}
	cout<<endl;
head = reverse(head,NULL);

temp = head;

while(temp){
	int data = temp->data;
	cout<<data<<" ";
	temp = temp->next;
}
	cout<<endl;
return 0;
}