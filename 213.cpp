/****************************************************************************************************
Solution:
������ House Robberһ����˼·��ֻ������Ҫɨ��4�Σ�Iֻ��Ҫɨ��һ�εõ�DP�����Ž⣩��II�е����Ž�����4��DP�����Ž���ѡȡ���ţ�
������ô��⣺����DP��һ���ͺ���Ĳ���ͬ������Ҫ���⿼�ǡ�����ͬ�⿼�ǡ�

�����˼·��
��֮ǰ��ΪҪ�ö�άDP����ȡF(1,n) = max{F(3,n-1)+a[i], F(2,n), F(2,n-3)+a[n], F(1,n-1)}
��ʵ�����������������ĸ���Ⲣ��ͬ������һ��ĸ���������ô��⣬���Ժ����ĸ����ȴ���������Ľṹ����ΪF(m1,m2)��m1,m2����һ�����ڣ��������Žⲻ������4����
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

