/****************************************************************************************************
我这里想了两个方法
Solution 1:
最直接的方法，每个元素在rotate之后有固定的位置，直接将元素放到对应的位置（需要用额外的空间）或者通过插入来调整顺序（时间复杂度就不是O(n)了）。

Solution 2:
和reverse words in string一样。先旋转整个string,然后再局部旋转。
注意std::reverse是#include <algorithm>，first = s.begin(), end = s.end(), 并不是只从first到end都转置，而是从first 到end - 1转置。

******************************************************************************************************/




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void Rotate1(vector<int>&nums, int k)
{
	int n = nums.size();
	k %= n;
	int *arr = new int[n];
	for(int i = 0; i < k; i++)
	{
		arr[i] = nums[n - k + i];

	}
	for(int i = k; i < n; i++)
	{
		arr[i] = nums[i - k];
	}

	for(int i = 0; i < n; i++)
		nums[i] = arr[i];
	delete arr;
}
void Rotate2(vector<int>&nums, int k)
{
	int n = nums.size();
	k %= n;
	reverse(nums.rbegin(), nums.rend());
	reverse(nums.begin(), nums.begin() + k);
	reverse(nums.begin() + k, nums.end());
}

void Rotate3(vector<int>&nums, int k);


class Solution
{
public:
	void rotate(vector<int>& nums, int k)
	{
		//Rotate1(nums, k);
		Rotate2(nums, k);
	}
};



void test()
{
	Solution s;
	vector<int> nums; 
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	s.rotate(nums, 3);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
}

int main()
{
	test();	
	system("pause");
	return 1;
}

