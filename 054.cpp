#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void PrintMatrix(int row_start, int row_end, int col_start, int col_end, vector<int>& result, const vector<vector<int>>&matrix)
{
	for(int i = col_start; i <= col_end; i++)
	{
		result.push_back(matrix[row_start][i]);
	}
	for(int i = row_start + 1; i <= row_end; i++)
	{
		result.push_back(matrix[i][col_end]);
	}
	if(row_end > row_start)
	for(int i = col_end - 1; i >= col_start; i--)
	{
		result.push_back(matrix[row_end][i]);
	}
	if(col_end > col_start)
	for(int i = row_end - 1; i > row_start; i--)
	{
		result.push_back(matrix[i][col_start]);
	}
}

class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix)
	{
		vector<int> result;
		int m = matrix.size();
		if(m == 0 )return result;
		int n = matrix[0].size();
		int i,j;
		int loopTime;
		if(m == 1 || n == 1)loopTime = 1;
		else 
			loopTime = ceil((m < n ? m : n) / 2.0) ; 
		for(i = 0; i < loopTime; i++)
		{
			int row_start  = i;
			int row_end = (m - 1 - i);
			int col_start = i;
			int col_end  = (n - i - 1);
			PrintMatrix(row_start, row_end, col_start, col_end, result, matrix);
		}
		return result;
	}
};


int main()
{
	vector<vector<int>> matrix;
	for(int i = 0; i < 2; i++)
	{
		vector<int> temp;
		for(int j = 0; j < 10; j++)
		{
			temp.push_back(i * 10 + j + 1);
		}
		matrix.push_back(temp);
	}
	Solution s;
	vector<int> result = s.spiralOrder(matrix);
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	system("pause");
	return 1;
}