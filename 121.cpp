/****************************************************************************************************
Solution:
This is a classical DP problem. I need to summerzie this kind of problem.  The brutal algorithm of this kind of problem is O(N * N).
We can use DP to decrease the time complexity. 
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int size = prices.size();
		if(size == 0)return 0;
		int maxP = 0;
		int minStart = prices[0];
		for(int i = 1; i < size; i++)
		{
			if(prices[i] > minStart)
			{
					maxP = (prices[i] - minStart) > maxP ?  (prices[i] - minStart) : maxP;			
			}
			else
				minStart = prices[i];
		}
		return maxP;
	}
};

void test()
{
	Solution s;
	vector<int> prices;
	prices.push_back(2);
	prices.push_back(4);
	prices.push_back(1);
	prices.push_back(5);
	prices.push_back(6);
	cout << s.maxProfit(prices) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
