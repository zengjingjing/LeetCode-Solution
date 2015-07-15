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
	void setZeroes(vector<vector<int>>& matrix) 
	{
		int rows = matrix.size();
		if(rows == 0)
			return;
		int cols = matrix[0].size();
		int *arr1 = new int[rows];
		int *arr2 = new int[cols];
		memset(arr1, 0, sizeof(int) * rows);
		memset(arr2, 0, sizeof(int) * cols);
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				if(matrix[i][j] == 0)
				{
					arr1[i] = 1;
					arr2[j] = 1;								
				}
			}
		}

		for(int i = 0; i < rows; i++)
		{
			if(arr1[i] == 1)
			{
				for(int j = 0; j < cols; j++)
					matrix[i][j] = 0;
			}
		}

		for(int i = 0; i < cols; i++)
		{
			if(arr2[i] == 1)
			{
				for(int j = 0; j < rows; j++)
					matrix[j][i] = 0;
			}
		}



		delete[] arr1;
		delete[] arr2;
	}

	void SetRowAndCol(vector<vector<int>>& matrix, int row, int col, int rows, int cols)
	{
		for(int i = 0; i < cols; i++)
			matrix[row][i] = 0;

		for(int i = 0; i < rows; i++)
			matrix[i][col] = 0;
	}
};

void test()
{
	Solution s;
	vector<vector<int>> matrix;
	vector<int> sub_matrix;
	sub_matrix.push_back(0);
	sub_matrix.push_back(1);
	matrix.push_back(sub_matrix);
	s.setZeroes(matrix);
}

int main()
{
	test();
	system("pause");
	return 1;
}