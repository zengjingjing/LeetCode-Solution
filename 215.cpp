/****************************************************************************************************
Solution:
这道题是很简单的经典题（分治的思想）。我花了很长时间来做。一是因为很少写快排了，partition操作不是很熟悉，不过还是根据我的理解一次写出来了。
像这种最基本的问题以后要记在脑中，信手拈来。

这里要注意一个写代码时候的问题：
while(start <= end && nums[start] <= temp)
	start++;
第一个判断是防止循环导致越界，第二个是要找出符合条件的点。
这里跳出循环后可能出现两种情况： start>end(start=end+1)  或者nums[start] > temp。也就是说我不一定能够找到后者，有可能在前面一个判断上就已经
不满足而跳出循环了，而我经常在跳出循环后以为找到了这样的点，而直接进行后续的操作。这是不对的。需要先判断一下到底是找到了没有。通过if(start>end)就可以判断出来了。


这是思维的一个误区，需要注意的。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int findKthLargest(vector<int>& nums, int k) 
	{
		int size = nums.size();
		if(size == 0)return 0;
		return FindK(nums, k, 0, size - 1);

	}

	int FindK(vector<int>&nums, int k , int start, int end)
	{
		int index = QuickPivot(nums, start, end);
		int temp = end - index + 1;
		if(k == temp)
			return nums[index];
		else if(temp > k)
		{
			return FindK(nums, k, index + 1, end);
		}
		else
		{
			return FindK(nums, k - temp, start, index - 1);
		}
	}

	int QuickPivot(vector<int>&nums, int start, int end)
	{
		bool flag = true;
		int temp = nums[start];
		int index = start;
		while(start <= end)
		{
			if(flag)
			{
				while(end >= start && nums[end] >= temp)
					end--;
				if(start > end)
					continue;
				nums[index] = nums[end];
				index = end;
				flag = false;
			}
			else
			{
				while(start <= end && nums[start] <= temp)
					start++;
				if(start > end)
					continue;
				nums[index] = nums[start];
				index = start;
				flag = true;
			}
		}
		nums[index] = temp;
		return index;
	}

};


void test()
{
	Solution s;
	vector<int> nums;
	int k = 2;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(4);

	cout << s.findKthLargest(nums, k) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
