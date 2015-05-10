#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target)
	{
		int m = matrix.size();
		if(m  == 0)return false;
		int n = matrix[0].size();
		int l = 0;
		int r = m - 1;
		int middle;
		while(l <= r)
		{
			middle = (l + r) / 2;
			if(matrix[middle][0] == target)return true;
			else if(matrix[middle][0] < target)
				l = middle + 1;
			else
				r = middle - 1;
		}
		int index;
		if(matrix[middle][0] < target)   //  if current element less than target ,means it should be in current(middle) row
			index  = middle;
		else 
			index = r;
		l = 0;
		r = n - 1;
		if(index < 0)return false;
		while(l <= r)
		{
			middle = (l + r) / 2;
			if(matrix[index][middle] == target)
				return true;
			else if(matrix[index][middle] > target)
				r = middle - 1;
			else l = middle + 1;

		}
		return false;
	}
};




int main()
{
	Solution s ;
	vector<vector<int>> matrix;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	
	v2.push_back(10);
	v2.push_back(11);
	v2.push_back(16);
	v2.push_back(20);

	v3.push_back(23);
	v3.push_back(30);
	v3.push_back(34);
	v3.push_back(50);

	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);

	if(s.searchMatrix(matrix, 9))
		cout << "true" << endl;
	else cout << "false" << endl;

	system("pause");
	return 1;

}