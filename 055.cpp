#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:

	/*********method  1 *******/
/*	bool canJump(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0)return true;
		bool *canReach = new bool[size];
		for(int i = 0; i < size - 1; i++)
			canReach[i] = false;
		canReach[size - 1] = true;
		for(int i = size - 2; i >= 0; i--)
		{
			for(int j = i + 1; j < size && j < nums[i] + i + 1; j++)
			{
				if(canReach[j] == true)
				{
					canReach[i] = true;
					break;
				}
			}		
		}
		return canReach[0];
	}*/

	/*********method  2 *******/
	bool canJump(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0)return true;
		int curMax = nums[0];
		for(int i = 0; i < size - 1; i++)
		{
			if(nums[i] + i > curMax)
				curMax = nums[i] + i;
			if(curMax >= size - 1)return true;
			if(i == curMax && nums[i] == 0)return false;
		}
		return true;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(0);
		nums.push_back(1);
			nums.push_back(1);
	if(s.canJump(nums))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
}
int main()
{
	test();
	system("pause");
	return 1;
}
