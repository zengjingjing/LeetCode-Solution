#include <iostream>
#include <stack>
#include <climits>
using namespace std;
int stackNum[33];
int stackCount[33];
stack<int >a;

class Solution 
{
public:
	int divide(int dividend, int divisor)
	{
		if(divisor == 0 )return INT_MAX;
		bool flag = false;
		if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))flag = true;
		if(dividend < 0) dividend = -dividend;
		if(divisor < 0) divisor = -divisor;
		if(dividend == 0 )return 0;

		long long  sum = divisor;
		int count = 1;
		int i = 0;
		a.
		while(sum < dividend)
		{
		//	stackNum.push(sum);
			stackNum[i] = sum;
		//	stackCount.push(count);
			stackCount[i] = count;
			
			sum += sum;
			count += count;
			i++;
		}
		//int size = stackNum.size();
		int size = i;
		int finalCount = 0;
		int finalSum = 0;
		for(int i = size - 1; i >= 0; i--)
		{

			//int val = stackNum.top();
			int val = stackNum[i];
			if(finalSum + val <= dividend)
			{
				//finalSum += stackNum.top();
				//finalCount += stackCount.top();
				finalSum += val;
				finalCount += stackCount[i];
			}



			//stackNum.pop();
			//stackCount.pop();
		}
		return finalCount;
	}
};

int main()
{
	Solution s;
	cout << s.divide(2147483647,1);
	system("pause");
	return 1;
}
