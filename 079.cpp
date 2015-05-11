#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef struct NODE
{
	int row;
	int col;
	char val;
	int curIndex;
	NODE(int r, int c, char ch, int index)
	{
		row = r;
		col = c;
		val = ch;
		curIndex = index;
	}
	NODE(){}

}NODE;

bool  visited[1000][1000];
int rows;
int cols;
queue<NODE> myQueue;

class Solution
{
public:
	bool HasWord(vector<vector<char>>& board, string word, int startRow, int startCol)
	{
		while(!myQueue.empty())
			myQueue.pop();
		NODE temp(startRow, startCol, board[startRow][startCol], 1);
		visited[startRow][startCol] = true;
		int size = word.size();
		if(size == 1)return true;
		myQueue.push(temp);
		while(!myQueue.empty())
		{
			NODE t = myQueue.front();
			int row = t.row;
			int col = t.col;
			visited[row][col] = true;
			int index = t.curIndex;
			myQueue.pop();
			NODE n;
			// upper
			if(row - 1 >= 0 && visited[row - 1][col] == false && board[row - 1][col] == word[index])
			{
				n.col = col;
				n.row = row - 1;
				n.curIndex = index + 1;
				n.val = board[row - 1][col];
			//	NODE upper(row - 1, col, board[row - 1][col], index + 1);
				if(index + 1 == size)return true;
				myQueue.push(n);
			}

			//down
			if(row + 1 < rows && visited[row + 1][col] == false && board[row + 1][col] == word[index])
			{
				n.col = col;
				n.row = row + 1;
				n.curIndex = index + 1;
				n.val = board[row + 1][col];
				//NODE down(row + 1, col, board[row + 1][col], index + 1);
				if(index + 1 == size)return true;
				myQueue.push(n);
			}

			//left
			if(col - 1 >= 0 && visited[row][col - 1] == false && board[row][col - 1] == word[index])
			{
				n.col = col - 1;
				n.row = row;
				n.curIndex = index + 1;
				n.val = board[row][col - 1];
				//NODE left(row, col - 1, board[row][col - 1], index + 1);
				if(index + 1 == size)return true;
				myQueue.push(n);
			}

			//right
			if(col + 1 < cols && visited[row][col + 1] == false && board[row][col + 1] == word[index])
			{
				n.col = col + 1;
				n.row = row;
				n.curIndex = index + 1;
				n.val = board[row][col + 1];
				//	NODE right(row, col + 1, board[row][col + 1], index + 1);
				if(index + 1 == size)return true;
				myQueue.push(n);
			}
		}
		return false;
	}

	void InitVisited()
	{
		for(int i = 0; i < 1000; i++)
			for(int j = 0; j < 1000; j++)
				visited[i][j] = false;
	}
	bool exist(vector<vector<char>>& board, string word) 
	{
		if(word.size() == 0)return false;
		rows = board.size();
		if(rows == 0)return false;
		cols = board[0].size();
	/*	visited = new bool*[rows];
		for(int i = 0; i < rows; i++)
		{
			visited[i] = new bool[cols];
		}*/
		InitVisited();
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(board[i][j] == word[0])
				{
					if(HasWord(board, word, i, j))return true;
					else continue;
				}
			}
		}
		return false;
	}
	
};

void test()
{
	Solution s;
	vector<vector<char>> board;
	vector<char> sub;
	sub.resize(4);
	sub[0] = 'a';
	sub[1] = 'b';
	sub[2] = 'c';
	sub[3] = 'e';
	board.push_back(sub);

/*	sub[0] = 's';
	sub[1] = 'f';
	sub[2] = 'c';
	sub[3] = 's';
	board.push_back(sub);

	sub[0] = 'a';
	sub[1] = 'd';
	sub[2] = 'e';
	sub[3] = 'e';
	board.push_back(sub);*/



	if(s.exist(board, "abe"))cout << "true" << endl;
	else
		cout << "false" << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
