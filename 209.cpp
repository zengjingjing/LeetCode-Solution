/****************************************************************************************************
Solution:
这道题属于two pointers,滑动窗口。跟two sum一样的思想。
注意在判断滑动窗口的界时最好先判断right,再判断left。如果先判断left,再判断right,会有很多临界值需要if else.判断太多。

naive方法：O（N*N），但是这种计算是有冗余的，说明肯定可以改进。那么如何改进来去掉这种冗余呢？通过很多题目可以得出结论：
有时候需要用额外的数据结构来存储，比如max points on a line；
不需要额外的数据结构，需要巧妙地设计算法，来避开这种冗余，这道题就是这种思路。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int minSubArrayLen(int s, vector<int>& nums) 
	{
		int ans = 0;
		int size = nums.size();
		if(size == 0)return ans;
		int left, right;
		left = right = 0;
		int sum = 0;
		 ans = size - 1;
		while(right < size)
		{
			while(right < size && sum < s)
			{				
				sum += nums[right];
				right++;
			}
			if(sum < s)
			{
				if(ans == size - 1)
					return 0;
				else
					return ans;
			}

			while(left < right && sum >= s)
			{
				sum -= nums[left];
				left++;
			}
			
			int len = right - left + 1;
			if(len < ans)
				ans = len;						
		}
		return ans;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(4);


	cout << s.minSubArrayLen(4, nums) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}