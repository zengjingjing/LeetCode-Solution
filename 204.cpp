/****************************************************************************************************
Solution:
Naive方法O（N*N）是TLE的。

厄拉多塞筛法(Sieve of Eeatosthese).
如果一个数是prime,那么它的倍数（！=1）都不是prime。也就是说，每遇到一个prime，都可以往后扫描，将其倍数都剔除出去。
这样就是线性时间，空间复杂度O（N）
纯数学题了。
很多题本质都是数学问题，发现规律，找到解法，都是数学思维。

******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int countPrimes(int n)
	{
		int ans = 0;
		if(n < 2)
			return ans;
		bool *flag = new bool[n];
		for(int i = 0; i < n; i++)
			flag[i] = true;
		for(int i = 2; i < n; i++)
		{
			if(flag[i])
			{
				int temp = i * 2;
				while(temp < n)
				{
					flag[temp] = false;
					temp += i;
				}
			}
		}
		for(int i = 2; i < n; i++)
		{
			if(flag[i] == true)
				ans++;
		}
		return ans;
	}

};

void test()
{
	Solution s;
	cout << s.countPrimes(499979) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
