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
	int jump(vector<int>& nums) 
	{
		int size = nums.size();
		int ans = 0;
		if(size == 0)
			return ans;
		int left = 0;
		int right = 0;
		while(right < size - 1)
		{
			int maxRight = 0;
			for(int i = left; i <= right; i++)
			{
				if(i + nums[i] > maxRight)
					maxRight = nums[i] + i;
			}
			left = right + 1;
			right = maxRight;
			ans++;
		}
		return ans;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	cout << s.jump(nums) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
