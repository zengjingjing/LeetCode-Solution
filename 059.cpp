#include <iostream>
#include <vector>
using namespace std;
void SetMatrix(int row_start, int row_end, int col_start, int col_end,  vector<vector<int>>& result, int count)
{
	count++;
	if(row_start == row_end)
	{
			result[row_start][row_end] = count;
			return ;
	}
	for(int i = col_start; i <= col_end; i++)
	{
		result[row_start][i] = count++;
	}
	for(int i = row_start + 1; i <= row_end; i++)
	{
		
		result[i][col_end] = count++;
	}

	for(int i = col_end - 1; i >= col_start; i--)
	{
		result[row_end][i] = count++;
	}
	for(int i = row_end - 1; i > row_start; i--)
	{
		result[i][col_start] = count++;
	}
}


class Solution 
{
public:
    vector<vector<int> > generateMatrix(int n) 
	{
        vector<vector<int>> result;
		if(n == 0 )return result;
		result.resize(n);
		int i,j;
		for(i = 0; i < n; i++)
			result[i].resize(n);
		
		int loopTime = ceil(n / 2.0) ;
		int count = 0;
		for(i = 0; i < loopTime; i++)
		{
			int row_start  = i;
			int row_end = (n - 1 - i);
			int col_start = i;
			int col_end  = (n - i - 1);

			SetMatrix(row_start, row_end, col_start, col_end, result, count);
			count += 4 * (n - (2 * i + 1));

		}
		return result;
    }
};


int main()
{
	Solution s;
	int size = 4;
	vector<vector<int>> result = s.generateMatrix(size);
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
			cout << result[i][j] <<" ";
		cout << endl;
	}
	system("pause");
	return 1; 
}