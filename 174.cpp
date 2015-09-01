/****************************************************************************************************
Solution:
倒着DP，这道题比较经典，需要整理。不是正着DP，是从结果倒着DP
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Solution
{
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon)
	{
		int ans = 0;
		int rows = dungeon.size();
		if(rows == 0)return ans;
		int cols = dungeon[0].size();
		int ** arr = new int *[rows];
		for(int i = 0; i < rows; i++)
			arr[i] = new int[cols];

		for(int i = rows - 1; i >= 0; i--)
		{
			for(int j = cols - 1; j >= 0; j--)
			{
				if(i == rows - 1 && j == cols - 1)
				{
					arr[i][j] = GetMax(1, 1 - dungeon[i][j]);
				}
				else if(i == rows - 1 && j < cols - 1)
				{
					arr[i][j] = GetMax(1, arr[i][j + 1] - dungeon[i][j]);
				}
				else if(i < rows - 1 && j == cols - 1)
				{
					arr[i][j] = GetMax(1, arr[i + 1][j] - dungeon[i][j]);
				}
				else
					arr[i][j] = GetMax(1, GetMin(arr[i + 1][j], arr[i][j + 1]) - dungeon[i][j]);
			}
		}
		ans = arr[0][0];
		for(int i = 0; i < rows; i++)
			delete[] arr[i];
		return ans;
	}

	int GetMax(const int& a, const int& b)
	{
		return a > b ? a : b;
	}

	int GetMin(const int& a, const int& b)
	{
		return a < b ? a : b;
	}
};

void test()
{
	Solution s;
	vector<vector<int>> dungeon;
	ifstream infile("test.txt");
	int rows, cols;
	infile >> rows >> cols;
	dungeon.resize(rows);
	for(int i = 0; i < rows; i++)
	{
		dungeon[i].resize(cols);
		for(int j = 0; j < cols; j++)
		{
			infile >> dungeon[i][j];
		}
	}

	cout << s.calculateMinimumHP(dungeon) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}



