/****************************************************************************************************
Solution 1:
��һ��map����洢ÿ��Ԫ�س��ֵĸ�������Ȼ���ǲ�������ĿҪ��ģ�����Ҳ����AC��������generalize֮�������һ�㻯�Ľⷨ��Ҳ����˵���Ԫ�س��ֵĸ�����Ϊ2��Ϊ3Ϊ4�����߲��ȣ�

Solution 2:
����1�е�С�������
�����������������λͼ����������Ԫ�ض������Σ� ���Կ���int arr[32]���飬��ŵ�������Ԫ��ÿһλ�ĺ͡�����2�ε�Ԫ��֮�ͣ�1�������϶���2�ı�����������������%2�� ʣ�µľ���
�Ǹ���һ��Ԫ�����Ĺ����ˡ�

����˼��ǳ��������ǰ��δ������

Solution 3:
��ͬԪ����� = 0��a1 ^ a2 ^ a3... ���Խ��������Կ��԰�����Ԫ��������Ľ�����ǵ�һ��Ԫ�ء�

137��ͬsolution 2��

******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums) 
	{

		int size = nums.size();
		if(size == 0)return 0;
		int arr[32];
		memset(arr, 0, sizeof(int) * 32);
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = 0; j < 32; j++)
			{
				arr[31 - j] += (nums[i] >> j) & 1;
			}
		}
		int ans = 0;
		int temp = 1;
		for(int i = 31; i >= 0; i--)
		{
			
			ans += (arr[i] % 2) * temp;
			temp *= 2;
		}
		return ans;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
//	nums.push_back(2);
//	nums.push_back(3);
//	nums.push_back(2);
//	nums.push_back(1);
	cout << s.singleNumber(nums) << endl; 
}
int main()
{
	test();
	system("pause");
	return 1;
}
