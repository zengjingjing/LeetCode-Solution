/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void CopyArray(vector<int>&nums, int& tail, int start, int count)
{
	for(int i = start; i < count + start && i < 2 + start; i++, tail++)
	{
		nums[tail] = nums[i];
	}
}

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		int ans = 0;
		int size = nums.size();
		if(size == 0)return ans;
		int tail = 0;
		int start = 0;
		int i = 0;
		while(i < size)
		{
			int count = 0;
			while(i < size && nums[i] == nums[start])
			{
				count++;
				i++;
			}
			CopyArray(nums, tail, start, count);
			start = i;
		}
		return tail;
	}
	
};
void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
//	nums.push_back(2);

	cout << s.removeDuplicates(nums) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
