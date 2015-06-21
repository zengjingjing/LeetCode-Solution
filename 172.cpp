/****************************************************************************************************
Solution:
这道题要注意溢出，如果是int temp，那么在最后*5的时候可能溢出，导致结果不对。
解决方法有两种：用long long ； 用n / 5 代替  temp * 5
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
