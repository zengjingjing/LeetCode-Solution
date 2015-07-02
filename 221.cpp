/****************************************************************************************************
Solution:
二维DP，按行来构造中间结果即可。我觉得这种二维DP可以从局部最优解+全局最优解的角度来看待。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:

	int maximalSquare(vector<vector<char>>& matrix)
	{
		int rows = matrix.size();
		if(rows == 0)
			return 0;
		int cols = matrix[0].size();
		int** maxArr = new int*[rows];
		for(int i = 0; i < rows; i++)
		{
			maxArr[i] = new int[cols];
			memset(maxArr[i], 0, sizeof(int) * (cols));
		}

		for(int i = 0; i < cols; i++)
			maxArr[0][i] = matrix[0][i] - '0';

		for(int i = 0; i < rows; i++)
			maxArr[i][0] = matrix[i][0] - '0';

		for(int i = 1; i < rows; i++)
		{
			for(int j = 1; j < cols; j++)
			{
				if(matrix[i][j] == '1')
				{
					int curMax = maxArr[i - 1][j - 1];
					int count = 1;
					for(int k = 0; k < curMax; k++)
					{
						if(matrix[i - k - 1][j] == '1' && matrix[i][j - k - 1] == '1')
							count++;
						else
							break;
					}
					maxArr[i][j] = count;
				}
				else
					maxArr[i][j] = 0;
			}
		}

		int ans = -1;
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
				if(maxArr[i][j] > ans)
					ans = maxArr[i][j];

		return ans * ans;

	}
};


void test()
{
	vector<vector<char>> matrix;
	vector<char> sub_matrix;
	sub_matrix.resize(5);
	sub_matrix[0] = '1';
	sub_matrix[1] = '0';
	sub_matrix[2] = '1';
	sub_matrix[3] = '0';
	sub_matrix[4] = '0';
	matrix.push_back(sub_matrix);

	sub_matrix[0] = '1';
	sub_matrix[1] = '0';
	sub_matrix[2] = '1';
	sub_matrix[3] = '1';
	sub_matrix[4] = '1';
	matrix.push_back(sub_matrix);

	sub_matrix[0] = '1';
	sub_matrix[1] = '1';
	sub_matrix[2] = '1';
	sub_matrix[3] = '1';
	sub_matrix[4] = '1';
	matrix.push_back(sub_matrix);

	sub_matrix[0] = '1';
	sub_matrix[1] = '0';
	sub_matrix[2] = '1';
	sub_matrix[3] = '1';
	sub_matrix[4] = '1';
	matrix.push_back(sub_matrix);

	Solution s;
	cout << s.maximalSquare(matrix) << endl;

	
}

int main()
{
	test();
	system("pause");
	return 1;
}