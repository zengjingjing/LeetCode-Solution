#include <iostream>
using namespace std;

class Solution 
{
public:
	int search(int A[], int n, int target)
	{
		int val = A[0];
		int left = 0;
		int right = n - 1;
		int middle;
		bool flag = false;
		while(left < right)
		{
			middle = (left + right)/2;
			if(A[middle] < val)
				right = middle;
			else if(A[middle] >= val)
				left = middle + 1;
		}
		if(A[right] < val)
			flag = true;
		else
		{
			left = 0;
			right = n - 1;
		}
		if(flag)
		{
			if(target == A[left])return left;
			if(target >= val)
			{
				left = 0;
				right--;
			}
			else
			{
				right = n - 1;
			}
		}

		while(left <= right)
		{
			middle =(left + right) / 2;
			if(A[middle] == target)
				return middle;
			else if(A[middle] > target)
				right = middle - 1;
			else
				left = middle + 1;

		}
		return -1;

	}
};

int main()
{
	Solution s;
	int arr[] = {3, 1};
	cout << s.search(arr, 2, 1) << endl;
	system("pause");
	return 1;
}