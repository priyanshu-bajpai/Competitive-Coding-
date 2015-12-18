# include <iostream>
# include <stack>
# include <algorithm>
# include <string>

using namespace std;
int n, m;

bool is_safe(int **	board, int row, int col)
{
	int i,j;

	if(board[row][col]==1)
		return false;

	//checking the possibility on the upper diagonal
	for(i=row-1,j=col-1;i>=0&&j>=0;i--,j--)
	{
	if(board[i][j]==2)
		return false;
	if(board[i][j]==1)
		break;
	}

	//checking the possibility on the upper right diagonal
	for(i=row-1,j=col+1;i>=0&&j<=m;i--,j++)
	{
	if(board[i][j]==2)
		return false;
	if(board[i][j]==1)
		break;
	}

	return true;

}

void Nqueen(int **board, int row,int *count)
{
	if(row>=n)
	{
		(*count) = (*count)+1;
		return ;
	}
		
	int i,j;

	for(i=0;i<m;i++)
	{
	if(is_safe(board,row,i))
	{
		int temp = board[row][i];
		board[row][i]=2;
		Nqueen(board,row+1,count);
		board[row][i] = temp;
	}
		
	else 
		continue;
	}

	return;

}


int main()
{
	cin>>n>>m;
	int i, j;
	int **board = (int **)malloc(sizeof(int*)*n);
	string s1;
	for(i=0;i<n;i++)
		board[i] = (int*)malloc(sizeof(int)*m);

	for(i=0;i<n;i++)
	{
		cin>>s1;
		for(j=0;j<s1.length();j++)
		{
			if(s1[j]=='.')
				board[i][j] = 0;
			else
				board[i][j] = 1;
		}
	}
			
	int count = 0;
	Nqueen(board,0,&count);
	cout<<count<<endl;

return 0;
}