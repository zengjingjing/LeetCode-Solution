/****************************************************************************************************
Solution:
这道题通过举例子可以发现规律：[m, n]按位来看的话，只要某一位变化了，那么这一位最终的结果肯定就是0。基于这样的规律，
我当时想出了这样的算法：对于每一位，判断 (n-m)/2, 这样迭代除2，如果某一位上有剩余，那么代表当前位在从m到n的过程中肯定会变化，这一位结果就为0.
但这种思路有问题，就是我这一位以1开始，它的后一位+1，它也可以变为0，结果还是0。例[3,4]。所以这种思路没有通用性， 虽然看到了问题的规律所在。

可以换个角度来想：某一位只要变化了，肯定就为0，那么哪些位是变化的呢？可以直接根据m,n的位来判断。从高到低比较，如果高位相等，那么从m到n的过程中肯定就是没有发生变化的，
如果变化了，那么后面的位肯定也在不断累加过程中也变化了，都为0。这样，只需要找出m,n最长的相同高位即可。
******************************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int rangeBitwiseAnd(int m, int n)
	{
		int ans = 0;
		if(m > n)return ans;
		unsigned int temp = 0x80000000;
		for(int i = 0; i < 32; i++)
		{
			int a = m & temp;
			int b = n & temp;
			if(a != b)
				break;
			else
			{
				ans += a;
				temp >>= 1;

			}
		}
		return ans;
	}
};


void test()
{
	Solution s;
	cout << s.rangeBitwiseAnd(2,3) << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}

