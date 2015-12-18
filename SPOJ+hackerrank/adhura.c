#include<stdio.h>

typdef list linklist;

struct list
{
int data;
list * link;
};


int main()
{
FILE *ptr,*ptr2;

ptr = fopen("input.txt","r");
ptr2 = fopen("output.txt","w");
char c = 'a';


c=getc(ptr) ; 
linklist *head = (linklist*) malloc(sizeof(linklist));

linklist *pointer = head;

pointer->data = c-'0';
c=getc(ptr) ; 
while(c!=EOF)
{
pointer->link = (linklist*) malloc(sizeof(linklist));
pointer = pointer->link ;
pointer->data = c-'0';
c=getc(ptr) ; 	
}

pointer->link = NULL;
fclose(ptr);
mergeSort

return 0;	
}

