/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
	int countDigitOne(int n)
	{
		int ans = 0;
		if(n <= 0)
			return ans;
		int count = 0;
		int temp = n;
		while(temp > 0)
		{
			temp /= 10;
			count++;
		}

		int index = 1;
		for(int i = 0; i < count; i++)
		{
			int a = n / index;
			int b = n - a * index;
			ans += (a + 8) / 10 * index + (a % 10 == 1) * (b + 1);
			index *= 10;
		}
		return ans;
	}
};

void test()
{
	Solution s;
	cout << s.countDigitOne(-10) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
