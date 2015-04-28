#include <iostream>
#include <vector>
#include <string>
using namespace std;


int GetMax(const int& left, const int& right)
{
	return left >= right ? left : right;	
}
class Solution
{
public:
	int rob(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0)return 0;
		
		int *maxArr = new int[size];
		maxArr[0] = nums[0];
		if(size < 1)return maxArr[0];
		maxArr[1] = GetMax(nums[0], nums[1]);
		for(int i = 2; i < size; i++)
		{
			maxArr[i] = GetMax(maxArr[i - 1], (maxArr[i - 2] + nums[i]));
		}

		int ans = maxArr[size - 1];
		delete maxArr;
		return ans;
	}
};



void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(5);
	cout << s.rob(nums) << endl; 
}

int main()
{
	test();	
	system("pause");
	return 1;
}
