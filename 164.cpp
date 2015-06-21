/****************************************************************************************************
Solution:
�������Ͱ�����˼�룬����������Ҳ�ǵ�һ���������ҷ���һ������һ����ĿֻҪ�Һ��ް취�ģ���һ�������û�����������ͣ�
��Ҫ��һ���µ���·���⡣

Ͱ������ÿ��Ͱ������set����ʾ�����Լ��Զ��������Էǳ����㡣����Ҫע�����set�Ǽ��ϣ��������ͬԪ�صĻ�����ôֻ����һ����
�������õ����������ظ�Ԫ������ȥ�ġ�������vetor�����档�����vectorһ�����򼴿ɣ�


******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <ctime>
using namespace std;

class Solution
{
public:
	int maximumGap(vector<int>& nums) 
	{
		int size = nums.size();
		if(size < 2)return 0;
		set<int> *mySet = new set<int>[size + 1];
		int minVal, maxVal;
		minVal= maxVal = nums[0];
		for(int i = 1; i < size; i++)
		{
			if(nums[i] > maxVal)
				maxVal = nums[i];
			if(nums[i] < minVal)
				minVal = nums[i];			
		}

		int len = ceil(double(maxVal - minVal) / size);
		if(len == 0)return 0;
		for(int i = 0; i < size; i++)
		{
			int binIndex = (nums[i] - minVal) / len;
			mySet[binIndex].insert(nums[i]);
		}

		// don't need to sort the bucket(set)
		int count = 0;
		for(int i = 0; i <= size; i++)
		{
			for(set<int>::const_iterator it = mySet[i].begin(); it != mySet[i].end(); it++)
				nums[count++] = *it;		
		}

		int ans = 0;
		for(int i = 1; i < count; i++)   //note: we cannot use "size" here to instead of "count" , because "set" delete the duplicate element, so count <= size
		{
			if(nums[i] - nums[i - 1] > ans)
				ans = nums[i] - nums[i - 1];
		}
		return ans;


	}
};


void test()
{
	Solution s;
	vector<int> nums;
	srand((int)time(0));

	nums.push_back(10);
	nums.push_back(10);
	nums.push_back(12);

	cout << s.maximumGap(nums) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}