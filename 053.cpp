/****************************************************************************************************
Solution:

It is a classic problem. But i do it wrong several times....
WHAT£Á FUCK!
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0)return 0;
		if(size == 1)return nums[0];
		int start,end,maxVal = nums[0];
		int prevVal = nums[0];
		start = end = 0;
		for(int i = 1; i < size; i++)
		{
			if(prevVal <= 0)
			{
				prevVal = nums[i];
				if(prevVal > maxVal)
					maxVal = prevVal;
				start = i;
				end = i;
			}
			else
			{
				prevVal += nums[i];
				if(prevVal > maxVal)
				{
					maxVal = prevVal;
					end = i;
				}
			}
		}
		return maxVal;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(-2);
	nums.push_back(1);
	nums.push_back(-3);
	nums.push_back(4);
	nums.push_back(-1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(-5);
	nums.push_back(4);
	cout << s.maxSubArray(nums) << endl;
	
}
int main()
{
	test();
	system("pause");
	return 1;
}
