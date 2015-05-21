/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetMin(const int& a, const int& b)
{
	return a < b ? a : b;
}
class Solution 
{
public:
	int minPathSum(vector<vector<int>>& grid) 
	{
		int rows = grid.size();
		if(rows == 0)return 0;
		int cols = grid[0].size();
		int **curMin = new int*[rows];
		for(int i = 0; i < rows; i++)
			curMin[i] = new int[cols];
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(i - 1 < 0 && j - 1 < 0)
					curMin[i][j] = grid[i][j];
				else if(i - 1 < 0 && j - 1 >= 0)
					curMin[i][j] = curMin[i][ j - 1] + grid[i][j];
				else if(i - 1 >= 0 && j - 1 < 0)
					curMin[i][j] = curMin[i - 1][j] + grid[i][j];
				else if(i - 1 >= 0 && j - 1 >= 0)
					curMin[i][j] = GetMin(curMin[i - 1][j], curMin[i][j - 1]) + grid[i][j];
	
			}
		}
		return curMin[rows - 1][cols - 1];
	}
};

void test()
{
	Solution s;
	vector<vector<int>> nums;
	vector<int> sub_nums;

	sub_nums.resize(2);
	sub_nums[0] = 1;
	sub_nums[1] = 2;
	nums.push_back(sub_nums);

	sub_nums[0] = 1;
	sub_nums[1] = 1;
	nums.push_back(sub_nums);

	cout << s.minPathSum(nums) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}

