/****************************************************************************************************
Solution:
First i want to do it as I do,  compare the middle and the first element. Then i can judge the range binaryly.

When i confront duplicate elements, i cannot handle when middle == element, because i don't know whether to search the left or the right.

Now, i can compare the middle and the right. Such compare can also judge the search direction and handle the duplicate case.
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{

public:
	int findMin(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0)return 0;
//		if(nums[size - 1] > nums[0])return nums[0];
		int left = 0;
		int right = size - 1;
		int middle;
		int val = nums[0];
		while(left < right)
		{
			middle = (left + right) / 2;
			if(nums[middle] > nums[right])
				left = middle + 1;
			else if(nums[middle] < nums[right])
				right = middle;
			else
				right--;
		}
		return nums[left];
	}
};

void test()
{
	Solution s;
	vector<int> nums;
//	nums.push_back(4);
//	nums.push_back(5);
//	nums.push_back(6);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	cout << s.findMin(nums) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
