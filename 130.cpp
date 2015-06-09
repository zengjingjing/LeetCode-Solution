/****************************************************************************************************
Solution:
注意BFS的时候，如果是在弹栈出来的时候才访问节点，那么可能会把相同的节点多次放入队列中（在不同的循环中）；
要么就在压栈的时候就访问，要么就在弹栈出来的时候加个判断，判断是否访问，否则相同元素加入过多，会TLE.
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
typedef struct INFO 
{
	int row;
	int col;
	INFO(int x, int y){row = x; col = y;}
}INFO;
class Solution
{
public:
	void solve(vector<vector<char>>& board) 
	{
		int rows = board.size();
		if(rows == 0)return ;
		int cols = board[0].size();
		bool **visited = new bool*[rows];
		for(int i = 0; i < rows; i++)
		{
			visited[i] = new bool[cols];
			for(int j = 0; j < cols; j++)
			{
				if(board[i][j] == 'X')
					visited[i][j] = true;
				else
					visited[i][j] = false;
			}
		}

		for(int i = 0; i < cols; i++)
		{
			if(board[0][i] == 'O' && visited[0][i] == false)
			{
				//visited[0][i] = true;
				BFS(0, i, board, visited, rows, cols);
			}
			if(board[rows - 1][i] == 'O' && visited[rows - 1][i] == false)
			{
				//	visited[rows - 1][i] = true;
				BFS(rows - 1, i, board, visited, rows, cols);
			}
		}

		for(int i = 1; i < rows - 1; i++)
		{
			if(board[i][0] == 'O' && visited[i][0] == false)
			{
				//visited[i][0] = true;
				BFS(i, 0, board, visited, rows, cols);
			}
			if(board[i][cols - 1] == 'O' && visited[i][cols - 1] == false)
			{
				//visited[i][cols - 1] = true;
				BFS(i, cols - 1, board, visited, rows, cols);
			}
		}

		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
			{
				if(visited[i][j] == false)
					board[i][j] = 'X';
			}
			return ;
	}

	void BFS(int row, int col, vector<vector<char>>& board, bool** visited, int rows, int cols)
	{
		queue<INFO> myQueue;
		INFO start(row, col);
		myQueue.push(start);
		while(!myQueue.empty())
		{
			INFO f = myQueue.front();
			if(visited[f.row][f.col] == false)
			{
				visited[f.row][f.col] = true;
				// upper
				if(f.row - 1 > 0 && board[f.row - 1][f.col] == 'O' && visited[f.row - 1][f.col] == false)
				{
					INFO up(f.row - 1, f.col);
					myQueue.push(up);
				//	visited[f.row - 1][f.col] = true;
				}

				//down
				if(f.row + 1 < rows && board[f.row + 1][f.col] == 'O' && visited[f.row + 1][f.col] == false)
				{
					INFO down(f.row + 1, f.col);
					myQueue.push(down);
				//	visited[f.row + 1][f.col] = true;
				}

				//left
				if(f.col - 1 > 0 && board[f.row][f.col - 1] == 'O' && visited[f.row][f.col - 1] == false)
				{
					INFO left(f.row, f.col - 1);
					myQueue.push(left);
					//visited[f.row][f.col - 1] = true;
				}

				//right
				if(f.col + 1 < cols && board[f.row][f.col + 1] == 'O' && visited[f.row][f.col + 1] == false)
				{
					INFO right(f.row, f.col + 1);
					myQueue.push(right);
					//visited[f.row][f.col + 1] = true;
				}
			}
			myQueue.pop();
		}
	}
};

void test()
{
	Solution s;
	vector<vector<char>> board;
	vector<char> temp;
	ifstream infile("a.txt");
	string str;
	while(infile >> str)
	{
		temp.clear();
		for(int i = 0; i < str.size(); i++)
			temp.push_back(str[i]);
		board.push_back(temp);
	}

	s.solve(board);
	int rows = board.size();
	int cols = board[0].size();
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0 ;j < cols; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 1;
}
