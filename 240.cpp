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
    bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int rows = matrix.size();
		if(rows == 0)
			return false;
		int clos = matrix[0].size();
		int col = clos - 1;
		int row = 0;
		bool turn = true;
		while(row < rows && col >= 0)
		{
			if(turn)
			{
				if(matrix[row][col] == target)
					return true;
				else if(matrix[row][col] > target)
					col--;
				else
					turn = false;
			}
			else
			{
				if(matrix[row][col] == target)
					return true;
				else if(matrix[row][col] < target)
					row++;
				else
					turn = true;
			}
		}
		return false;
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
