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
	bool search(vector<int>& nums, int target)
	{
		int size = nums.size();
		if(size == 0)
			return false;
		int left = 0;
		int right = size - 1;
		while(left <= right)
		{
			int middle = (left + right) / 2;
			if(nums[middle] == target)
				return true;
			else if(nums[middle] > nums[left])
			{
				if(target >= nums[left] && target < nums[middle])
					right = middle - 1;
				else
					left = middle + 1;
			}
			else if(nums[middle] < nums[left])
			{
				if(target <= nums[right] && target > nums[middle])
					left = middle + 1;
				else
					right = middle - 1;
			}
			else
				left++;
		}
		return false;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
//	nums.push_back(3);
//	nums.push_back(3);
//	nums.push_back(3);
//	nums.push_back(3);
	if(s.search(nums, 5))
		cout << "true" << endl;
	else
	{
		cout << "false" << endl;
	}
}

int main()
{
	test();
	system("pause");
	return 1;
}

