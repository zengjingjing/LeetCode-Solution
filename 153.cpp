/*********************************************
Note: ��ֻ������Ԫ�ص�ʱ�򣬻������������ֻ��nums[0-1]ʱ��һ��Ҫע��ѭ���������ж�
method 1 : �ʼ���뷨���ǳ�SB�������жϡ��Ҿ���ֻҪ���������ֺܶ��жϡ�����ģ������Ͼ�û��⵽����ľ��衣
method 2 : ���������������õķ�����


*******************************************/



#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	/************************method 1************************************************/ 
	/*int findMin(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 1)return nums[0];
		if(size == 2)return nums[0] < nums[1] ? nums[0] : nums[1];
		int minVal = nums[0];
		int left = 0;
		int right = size - 1;
		int middle;
		while(left < right)
		{
			middle = (left + right) / 2;
			if(nums[middle] > minVal)
				left = middle + 1;
			else if(nums[middle] < minVal)
				right = middle;
			else 
				return nums[0] < nums[1] ? nums[0] : nums[1];
		}

		if(nums[left] > minVal)return minVal;
		else return nums[left];
	}*/
	
	/************************method 2************************************************/ 
	int findMin(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0)return 0;
		if(nums[size - 1] >= nums[0])return nums[0];
		int left = 0;
		int right = size - 1;
		int middle;
		int val = nums[0];
		while(left < right)
		{
			middle = (left + right) / 2;
			if(nums[middle] >= val)
				left = middle + 1;
			else
				right = middle;
		}
		return nums[left];
	}
};



void test()
{
	Solution s;
	vector<int> nums;
	
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(2);
	cout << s.findMin(nums) << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}

