/****************************************************************************************************
Solution:
老子真是日了狗了，这道题提交了估计有30次，越界的地方一定要注意。之前数组用int是不行的。
-2147483648 1  （不越界）
-2147483648 -1 （越界）

******************************************************************************************************/
#include <iostream>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;


class Solution 
{
public:
	int divide(int dividend, int divisor)
	{
		if(divisor == 0 )return INT_MAX;
		int neg = 1;
		if((double)dividend * divisor < 0)
			neg = -1;
		long long l_dividend = fabs(double(dividend));
		long long l_divisor = fabs(double(divisor));

		if(l_dividend == 0 )return 0;
		long long stackNum[33];
		long long stackCount[33];
		long long  sum = l_divisor;
		long long count = 1;
		int i = 0;
		if(l_dividend < l_divisor)
			return 0;
		while(sum <= l_dividend)
		{
			stackNum[i] = sum;
			stackCount[i] = count;
			sum += sum;
			count += count;
			i++;
		}
		int size = i;
		long long finalCount = 0;
		long long finalSum = 0;
		for(int i = size - 1; i >= 0; i--)
		{
			if(finalSum + stackNum[i] <= l_dividend)
			{
				finalSum += stackNum[i];
				finalCount += stackCount[i];
			}

		}
		if(finalCount > 2147483647)
		{
			if(neg == 1)
				return 2147483647;
			else
				return finalCount * neg;
		}

		return finalCount * neg;
	}
};

int main()
{
	Solution s;
	cout << s.divide(2147483647, 3);
	system("pause");
	return 1;
}
