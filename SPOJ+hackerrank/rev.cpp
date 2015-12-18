# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;

int cnt = -1;
int value;

struct node
{
	int data;
	struct node *right, *left;
};

typedef struct node node;

node* newNode(int data)
{
	cout<<"creating new node with value: "<<data<<endl;
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right =  NULL;
    return temp;
}


void deepest_node(node *root, int child, int depth)
{
	if((root->left==NULL)&&(root->right==NULL)&&child)
	{
		if(child==-1)
			cout<<"root is the deepest";

		if(depth>cnt)
		{
		cnt=depth;
		value = root->data;
		}
		return ;
	}
	cout<<"yo";
	deepest_node(root->left,1,depth+1);
	deepest_node(root->right,0,depth+1);
}


int main()
{
	node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);

    cout<<"too";
    deepest_node(root,-1,0);

    cout<<"depth = "<<cnt<<" value = "<<value<<endl;
	return 0;
}
