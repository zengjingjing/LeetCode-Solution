#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
	int rangeBitwiseAnd(int m, int n)
	{
		stack<int> myStack;
		int c = m;
		if(n < m)return 0;
		while(c > 0)
		{
			myStack.push(c % 2);
			c /= 2;
		}
		int * bit;
		int size = myStack.size();
		bit = new int[size];
		for(int i = 0; i < size; i++)
		{
			bit[i] = myStack.top();
			myStack.pop();
		}
		int sub = n - m;
		int i = size - 1;
		while(sub > 0)
		{

					bit[i] = 0;
					sub /= 2;
					i--;
		}
		int ans = 0;
		for(int i = 0; i < size; i++)
		{
			if(bit[i] == 1)
				ans += pow(2.0, size - i - 1);
		}
		return ans;

	}
};


void test()
{
	Solution s;
	cout << s.rangeBitwiseAnd(0,2) << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}

