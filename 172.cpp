/****************************************************************************************************
Solution:
�����Ҫע������������int temp����ô�����*5��ʱ�������������½�����ԡ�
������������֣���long long �� ��n / 5 ����  temp * 5
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int trailingZeroes(int n) 
	{
		int ans = 0;
		long long  temp = 5;
		while(temp <= n)
		{
			ans += n / temp;
			temp *= 5;
		}
		return ans;
	}
};

void test()
{
	Solution s;
	cout << s.trailingZeroes(1808548329) << endl;
	                         
}
int main()
{
	test();
	system("pause");
	return 1;
}
