/****************************************************************************************************
Solution:
这道题是桶排序的思想，这种类型我也是第一次遇到。我发现一般遇到一类题目只要我毫无办法的，那一般就是我没遇到过的题型，
需要用一种新的套路来解。

桶排序中每个桶可以用set来表示链表以及自动排序，所以非常方便。这里要注意的是set是集合，如果有相同元素的话，那么只能算一个。
最后排序得到的数组中重复元素是消去的。可以用vetor来代替。（最后vector一次排序即可）


******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
using namespace std;

class Solution
{
public:
	int maximumGap(vector<int>& nums) 
	{
		int size = nums.size();
		if(size < 2)return 0;
		set<int> *mySet = new set<int>[size + 1];
		int minVal, maxVal;
		minVal= maxVal = nums[0];
		for(int i = 1; i < size; i++)
		{
			if(nums[i] > maxVal)
				maxVal = nums[i];
			if(nums[i] < minVal)
				minVal = nums[i];			
		}

		int len = ceil(double(maxVal - minVal) / size);
		if(len == 0)return 0;
		for(int i = 0; i < size; i++)
		{
			int binIndex = (nums[i] - minVal) / len;
			mySet[binIndex].insert(nums[i]);
		}

		// don't need to sort the bucket(set)
		int count = 0;
		for(int i = 0; i <= size; i++)
		{
			for(set<int>::const_iterator it = mySet[i].begin(); it != mySet[i].end(); it++)
				nums[count++] = *it;		
		}

		int ans = 0;
		for(int i = 1; i < count; i++)   //note: we cannot use "size" here to instead of "count" , because "set" delete the duplicate element, so count <= size
		{
			if(nums[i] - nums[i - 1] > ans)
				ans = nums[i] - nums[i - 1];
		}
		return ans;


	}
};


void test()
{
	Solution s;
	vector<int> nums;
	srand((int)time(0));

	nums.push_back(10);
	nums.push_back(10);
	nums.push_back(12);

	cout << s.maximumGap(nums) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}