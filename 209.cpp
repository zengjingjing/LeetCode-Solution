/****************************************************************************************************
Solution:
���������two pointers,�������ڡ���two sumһ����˼�롣
ע�����жϻ������ڵĽ�ʱ������ж�right,���ж�left��������ж�left,���ж�right,���кܶ��ٽ�ֵ��Ҫif else.�ж�̫�ࡣ

naive������O��N*N�����������ּ�����������ģ�˵���϶����ԸĽ�����ô��θĽ���ȥ�����������أ�ͨ���ܶ���Ŀ���Եó����ۣ�
��ʱ����Ҫ�ö�������ݽṹ���洢������max points on a line��
����Ҫ��������ݽṹ����Ҫ���������㷨�����ܿ��������࣬������������˼·��
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int minSubArrayLen(int s, vector<int>& nums) 
	{
		int ans = 0;
		int size = nums.size();
		if(size == 0)return ans;
		int left, right;
		left = right = 0;
		int sum = 0;
		 ans = size - 1;
		while(right < size)
		{
			while(right < size && sum < s)
			{				
				sum += nums[right];
				right++;
			}
			if(sum < s)
			{
				if(ans == size - 1)
					return 0;
				else
					return ans;
			}

			while(left < right && sum >= s)
			{
				sum -= nums[left];
				left++;
			}
			
			int len = right - left + 1;
			if(len < ans)
				ans = len;						
		}
		return ans;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(4);


	cout << s.minSubArrayLen(4, nums) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}