/****************************************************************************************************
Solution:
这道题和 House Robber一样的思路，只不过需要扫描4次（I只需要扫描一次得到DP的最优解）。II中的最优解是在4次DP的最优解中选取最优，
可以这么理解：它的DP第一步和后面的并不同构，需要额外考虑。不能同意考虑。

错误的思路：
我之前以为要用二维DP，求取F(1,n) = max{F(3,n-1)+a[i], F(2,n), F(2,n-3)+a[n], F(1,n-1)}
但实际上这样的子问题跟母问题并不同构，第一个母问题可以这么理解，可以后面的母问题却不是这样的结构，因为F(m1,m2)中m1,m2并不一定相邻，它的最优解不是求这4个。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int rob(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0)return 0;
		int * maxArr = new int[size];
		int a = nums[0] + GetMaxRob(nums, maxArr, 2, size - 2);
		int b = GetMaxRob(nums, maxArr, 1, size - 1);
		int c = nums[size - 1] + GetMaxRob(nums, maxArr, 1, size - 3);
		int d = GetMaxRob(nums, maxArr, 0, size - 2);
		int ans = GetMax4(a, b, c, d);
		delete maxArr;
		return ans;
	}


	int GetMaxRob(vector<int>&nums, int* maxArr, int start, int end)
	{
		int size = end - start + 1;
		if(size <= 0)return 0;
		if(size == 1)
			return nums[start];
		if(size == 2)
			return GetMax2(nums[start], nums[end]);
		maxArr[start] = nums[start];
		maxArr[start + 1] = nums[start + 1];
		for(int i = start + 2; i <= end; i++)
		{
			maxArr[i] = GetMax2(maxArr[i - 1], maxArr[i - 2] + nums[i]);
		}
		return maxArr[end];
	}

	int GetMax4(const int& a , const int& b, const int& c, const int& d)
	{
		int temp1 = a > b ? a : b;
		int temp2 = c > d ? c : d;
		return temp1 > temp2 ? temp1 : temp2; 
	}

	int GetMax2(const int& a , const int& b)
	{
		return  a > b ? a : b;
	}
};


void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(1);
//	nums.push_back(10);
	cout << s.rob(nums) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}

