/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{

public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int rows = obstacleGrid.size();
		if(rows == 0)return 0;
		int cols = obstacleGrid[0].size();
		int ** curMax = new int*[rows];
		for(int i = 0; i < rows; i++)
			curMax[i] = new int[cols];
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(i - 1 < 0 && j - 1 < 0)
				{
					if(obstacleGrid[i][j] == 0)
						curMax[i][j] = 1;
					else
						curMax[i][j] = 0;
				}
				else if(i - 1 < 0 && j - 1 >= 0)
				{
					if(obstacleGrid[i][j] == 0)
						curMax[i][j] = curMax[i][j - 1];
					else
						curMax[i][j] = 0;	
				}				
				else if(i - 1 >= 0 && j - 1 < 0)
				{
					if(obstacleGrid[i][j] == 0)
						curMax[i][j] = curMax[i - 1][j];
					else
						curMax[i][j] = 0;
				}
				else
				{
					if(obstacleGrid[i][j] == 0)	
						curMax[i][j] = curMax[i - 1][j] + curMax[i][j -1];
					else
						curMax[i][j] = 0;
				}
					
					
			}
		}
		return curMax[rows - 1][cols - 1];
	}
};

void test()
{
}
int main()
{
	test();
	system("pause");
	return 1;
}
