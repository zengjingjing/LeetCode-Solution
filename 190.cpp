#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


class Solution
{
public:
	unsigned int reverseBits(unsigned int n)
	{
		stack<int> myStack;
		int count = 0;
		while(n > 0)
		{
			myStack.push(n % 2);
			n /= 2;
			count++;
		}
		while(count < 32)
		{
			myStack.push(0);
			count++;
		}
		stack<int> otherStack;
		while(!myStack.empty())
		{
			otherStack.push(myStack.top());
			myStack.pop();
		}
		unsigned int ans = 0;
		while(!otherStack.empty())
		{   
			count--;
			int val = otherStack.top();
			if(val == 1)
				ans += pow(2.0, count);
			otherStack.pop();
		}
		return ans;

	}
};


void test()
{
	Solution s;
	cout << s.reverseBits(1) << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}
