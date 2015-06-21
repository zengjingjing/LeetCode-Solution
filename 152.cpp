/****************************************************************************************************
Solution:
Maximum  Subarray的变种
因为是乘法，所以需要保存一个最大，一个最小
******************************************************************************************************/



#include <iostream>
#include <vector>
#include <string>
using namespace std;


typedef struct INFO
{
	int cur_max;
	int cur_min;
}INFO;




class Solution 
{
public:
	int maxProduct(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 1)return nums[0];
		INFO * arr = new INFO[size];
		memset(arr, 0, sizeof(int) * size);
		arr[0].cur_max = nums[0];
		arr[0].cur_min = nums[0];
		for(int i = 1; i < size; i++)
		{
			arr[i].cur_max = GetMax3(nums[i], nums[i] * arr[i - 1].cur_min, nums[i] * arr[i - 1].cur_max);
			arr[i].cur_min = GetMin3(nums[i], nums[i] * arr[i - 1].cur_min, nums[i] * arr[i - 1].cur_max);
			
		}
		int ans = arr[0].cur_max;
		for(int i = 0; i < size; i++)
		{
			if(arr[i].cur_max > ans)
				ans = arr[i].cur_max;
		}
		return ans;
	}

	int GetMax3(const int& a, const int& b, const int& c)
	{
		int temp = a > b ? a : b;
		return temp > c ? temp : c;
	}

	int GetMin3(const int& a, const int& b, const int& c)
	{
		int temp = a < b ? a : b;
		return temp < c ? temp : c;
	}

};


void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(-3);
	nums.push_back(-2);
	nums.push_back(4);
	cout << s.maxProduct(nums) << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}

