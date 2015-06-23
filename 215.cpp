/****************************************************************************************************
Solution:
������Ǻܼ򵥵ľ����⣨���ε�˼�룩���һ��˺ܳ�ʱ��������һ����Ϊ����д�����ˣ�partition�������Ǻ���Ϥ���������Ǹ����ҵ����һ��д�����ˡ�
������������������Ժ�Ҫ�������У�����������

����Ҫע��һ��д����ʱ������⣺
while(start <= end && nums[start] <= temp)
	start++;
��һ���ж��Ƿ�ֹѭ������Խ�磬�ڶ�����Ҫ�ҳ����������ĵ㡣
��������ѭ������ܳ������������ start>end(start=end+1)  ����nums[start] > temp��Ҳ����˵�Ҳ�һ���ܹ��ҵ����ߣ��п�����ǰ��һ���ж��Ͼ��Ѿ�
�����������ѭ���ˣ����Ҿ���������ѭ������Ϊ�ҵ��������ĵ㣬��ֱ�ӽ��к����Ĳ��������ǲ��Եġ���Ҫ���ж�һ�µ������ҵ���û�С�ͨ��if(start>end)�Ϳ����жϳ����ˡ�


����˼ά��һ����������Ҫע��ġ�
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int findKthLargest(vector<int>& nums, int k) 
	{
		int size = nums.size();
		if(size == 0)return 0;
		return FindK(nums, k, 0, size - 1);

	}

	int FindK(vector<int>&nums, int k , int start, int end)
	{
		int index = QuickPivot(nums, start, end);
		int temp = end - index + 1;
		if(k == temp)
			return nums[index];
		else if(temp > k)
		{
			return FindK(nums, k, index + 1, end);
		}
		else
		{
			return FindK(nums, k - temp, start, index - 1);
		}
	}

	int QuickPivot(vector<int>&nums, int start, int end)
	{
		bool flag = true;
		int temp = nums[start];
		int index = start;
		while(start <= end)
		{
			if(flag)
			{
				while(end >= start && nums[end] >= temp)
					end--;
				if(start > end)
					continue;
				nums[index] = nums[end];
				index = end;
				flag = false;
			}
			else
			{
				while(start <= end && nums[start] <= temp)
					start++;
				if(start > end)
					continue;
				nums[index] = nums[start];
				index = start;
				flag = true;
			}
		}
		nums[index] = temp;
		return index;
	}

};


void test()
{
	Solution s;
	vector<int> nums;
	int k = 2;
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(5);
	nums.push_back(4);

	cout << s.findKthLargest(nums, k) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
