/****************************************************************************************************
Solution:
BFS, 这道题和WAP的笔试题一样，注意在push queue之前要先访问，不要再弹出的时候在访问，这样防止相同的元素被重复push,导致TLE
可是WAP为什么要挂我？草
******************************************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


int rows;
int cols;
typedef struct POINT
{
	int row;
	int col;
	POINT(){}
	POINT(int x,int y){row = x; col = y;}
}POINT;

queue<POINT> myQueue;
POINT FindAvaliableIsland(vector<vector<char>> & grid, bool** visited)
{
	for(int i = 0; i < rows; i++)
	{	
		for(int j = 0; j < cols; j++)
		{
			if(grid[i][j] == '1' && visited[i][j] == false)
				return POINT(i,j);
		}
	}
	return POINT(-1, -1);

}

void Traverse(const POINT & island, vector<vector<char>> & grid, bool** visited)
{
	while(!myQueue.empty())
		myQueue.pop();	
	myQueue.push(island);
	while(!myQueue.empty())
	{
		POINT top = myQueue.front();
		int x = top.row;
		int y = top.col;
		myQueue.pop();
		// up
		if(x > 0 && grid[x - 1][y] == '1' && visited[x - 1][y] == false)
		{
			POINT temp(x - 1, y);
			visited[x - 1][y] = true;
			myQueue.push(temp);

		}
		// down
		if(x < rows - 1 && grid[x + 1][y] == '1' && visited[x + 1][y] == false)
		{
			POINT temp(x + 1, y);
			visited[x + 1][y] = true;
			myQueue.push(temp);
		}
		// left
		if(y > 0 && grid[x][y - 1] == '1' &&visited[x][y - 1] == false)
		{
			POINT temp(x, y - 1);
			visited[x][y - 1] = true;
			myQueue.push(temp);
		}
		// right
		if(y < cols - 1 && grid[x][y + 1] == '1' &&visited[x][y + 1] == false)
		{
			POINT temp(x, y + 1);
			visited[x][y + 1] = true;
			myQueue.push(temp);
		}
	}
}

class Solution
{
public:
	int numIslands(vector<vector<char>> &grid)
	{
		if(grid.size() == 0)return 0;
		POINT island;
		rows = grid.size();
		cols = grid[0].size();
		bool ** visited = new bool*[rows];
		for(int i = 0; i < rows; i++)
			visited[i] = new bool[cols];
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
				visited[i][j] = false;
		int ans = 0;
		while(island = FindAvaliableIsland(grid, visited), island.row != -1)
		{
			visited[island.row][island.col] = true;
			Traverse(island, grid, visited);
			ans++;
		}

		for(int i = 0; i < rows; i++)
			delete visited[i];
		return ans;
	}
};



void test()
{
	vector<vector<char>>  grid;
	grid.resize(4);
	vector<char> temp;
	temp.resize(5);


	temp[0] = '1';
	temp[1] = '1';
	temp[2] = '0';
	temp[3] = '0';
	temp[4] = '0';
	grid[0] = temp;

	temp[0] = '1';
	temp[1] = '1';
	temp[2] = '0';
	temp[3] = '0';
	temp[4] = '0';
	grid[1] = temp;

	temp[0] = '0';
	temp[1] = '0';
	temp[2] = '1';
	temp[3] = '0';
	temp[4] = '0';
	grid[2] = temp;

	temp[0] = '0';
	temp[1] = '0';
	temp[2] = '0';
	temp[3] = '1';
	temp[4] = '1';
	grid[3] = temp;

	Solution s;
	

	cout << s.numIslands(grid) << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}
