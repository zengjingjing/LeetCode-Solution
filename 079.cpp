#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	bool HasWord(vector<vector<char>>& board, bool** visited, int rows, int cols, const string& word, int start, int row, int col)
	{
		bool ans = false;
		if(start == word.size() - 1)
			return true;

		if(row == 0 && col == 3)
		{
			int a = 3;
		}
		if(row - 1 >= 0 && visited[row - 1][col] == false && board[row - 1][col] == word[start + 1])
		{
			visited[row - 1][col] = true;
			ans = ans || HasWord(board, visited, rows, cols, word, start + 1, row - 1, col);
			visited[row - 1][col] = false;
		}
		if(row + 1 < rows && visited[row + 1][col] == false && board[row + 1][col] == word[start + 1])
		{
			visited[row + 1][col] = true;
			ans = ans || HasWord(board, visited, rows, cols, word, start + 1, row + 1, col); 
			visited[row + 1][col] = false;
		}
		if(col - 1 >= 0 && visited[row][col - 1] == false && board[row][col - 1] == word[start + 1])
		{
			visited[row][col - 1] = true;
			ans = ans || HasWord(board, visited, rows, cols, word, start + 1, row, col - 1); 
			visited[row][col - 1] = false;
		}
		if(col + 1 < cols && visited[row][col + 1] == false && board[row][col + 1] == word[start + 1]) 
		{
			visited[row][col + 1] = true;
			ans = ans || HasWord(board, visited, rows, cols, word, start + 1, row, col + 1); 
			visited[row][col + 1] = false;
		}
		return ans;

	}


	bool exist(vector<vector<char>>& board, string word) 
	{
		if(word.size() == 0)
			return false;
		int rows = board.size();
		if(rows == 0)return false;
		int cols = board[0].size();
		bool**	visited = new bool*[rows];
		for(int i = 0; i < rows; i++)
		{
			visited[i] = new bool[cols];
			for(int j = 0; j < cols; j++)
				visited[i][j] = false;
		}

		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(board[i][j] != word[0])
					continue;
				InitVisited(visited, rows, cols);
				visited[i][j] = true;
				if(HasWord(board, visited, rows, cols ,word, 0, i, j))
					return true;
			}
		}
		return false;
	}


	void InitVisited(bool** visited, int rows, int cols)
	{
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
				visited[i][j] = false;
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

	sub[0] = 's';
	sub[1] = 'f';
	sub[2] = 'e';
	sub[3] = 's';
	board.push_back(sub);

	sub[0] = 'a';
	sub[1] = 'd';
	sub[2] = 'e';
	sub[3] = 'e';
	board.push_back(sub);


	if(s.exist(board, "abceseeefs"))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
