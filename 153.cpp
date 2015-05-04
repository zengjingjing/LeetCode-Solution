/*********************************************
Note: 当只有两个元素的时候，或者最后收缩到只有nums[0-1]时，一定要注意循环跳出的判断
*******************************************/



#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int findMin(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 1)return nums[0];
		if(size == 2)return nums[0] < nums[1] ? nums[0] : nums[1];
		int minVal = nums[0];
		int left = 0;
		int right = size - 1;
		int middle;
		while(left < right)
		{
			middle = (left + right) / 2;
			if(nums[middle] > minVal)
				left = middle + 1;
			else if(nums[middle] < minVal)
				right = middle;
			else 
				return nums[0] < nums[1] ? nums[0] : nums[1];
		}

		if(nums[left] > minVal)return minVal;
		else return nums[left];
	}
};



void test()
{
	Solution s;
	vector<int> nums;
	
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	cout << s.findMin(nums) << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}

