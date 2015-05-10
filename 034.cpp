#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	vector<int> searchRange(int A[], int n, int target) 
	{
		vector<int> result;
		int left = 0;
		int right = n - 1;
		int middle;
		int left1 = -1;
		int right1 = -1;
		int left2 = -1;
		int right2 = -1;
		while(left <= right)
		{
			middle = (left + right ) / 2;
			if(A[middle] < target)
				left = middle + 1;
			else if(A[middle] > target)
				right = middle - 1;
			else 
			{
				left1 = left;
				right1 = middle;
				left2 = middle;
				right2 = right;
				break;
			}
		}
		if(left > right)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		while(left1 < right1)
		{
			int middle1 = (left1 + right1) /2;
			if(A[middle1] < target)
				left1 = middle1 + 1;
			else 
				right1 = middle1;
		}
		result.push_back(right1);
		while(left2 <= right2)
		{
			int middle2 = (left2 + right2) /2;
			if(A[middle2] > target)
				right2 = middle2 - 1;
			else 
				left2 = middle2 + 1;
		}
		result.push_back(right2);
		return result;

	}

};


int main()
{
	Solution s;
	int arr[] = {5, 7, 7, 8, 8, 8};
	vector<int> result = s.searchRange(arr, 6, 8);
	for(int i = 0; i < result.size(); i++)
	{
		cout<< result[i] <<endl;
	}
	system("pause");
	return 1;
}