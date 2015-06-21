/****************************************************************************************************
������������������
Solution 1:
��ֱ�ӵķ�����ÿ��Ԫ����rotate֮���й̶���λ�ã�ֱ�ӽ�Ԫ�طŵ���Ӧ��λ�ã���Ҫ�ö���Ŀռ䣩����ͨ������������˳��ʱ�临�ӶȾͲ���O(n)�ˣ���

Solution 2:
��reverse words in stringһ��������ת����string,Ȼ���پֲ���ת��
ע��std::reverse��#include <algorithm>��first = s.begin(), end = s.end(), ������ֻ��first��end��ת�ã����Ǵ�first ��end - 1ת�á�

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

