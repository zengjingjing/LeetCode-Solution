/****************************************************************************************************
Solution:
My solution is poor and low.¡¡I use a array to record the max profit start from left, and another array to
record the max profit start from the right. So the problem can be divided into 2 sub problems. The left region and right region.

Great Solution: http://blog.csdn.net/linhuanmars/article/details/23236995
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
		int * arrLeft = new int[size];
		int * arrRight = new int[size];
		int minStart = prices[0];
		int maxP = 0;
		arrLeft[0] = maxP;
		for(int i = 1; i < size; i++)
		{
			if(prices[i] > minStart)
				maxP = (prices[i] - minStart) > maxP ? (prices[i] - minStart) : maxP;
			else
				minStart = prices[i];
			arrLeft[i] = maxP;
		}
		int maxStart = prices[size - 1];
		maxP = 0;
		arrRight[size - 1] = maxP; 
		for(int i = size - 2; i >= 0; i--)
		{
			if(prices[i] < maxStart)
				maxP = (maxStart - prices[i]) > maxP ? (maxStart - prices[i]) : maxP;
			else
				maxStart = prices[i];
			arrRight[i] = maxP;
		}
		maxP = 0;
		for(int i = 0; i < size; i++)
		{
			if(arrLeft[i] + arrRight[i] > maxP)
				maxP = arrLeft[i] + arrRight[i];
		}
		delete arrLeft;
		delete arrRight;
		return maxP;
	}
};

void test()
{
	Solution s;
	vector<int> prices;
	prices.push_back(4);
	prices.push_back(2);
	prices.push_back(1);
//	prices.push_back(5);
//	prices.push_back(6);
//	prices.push_back(3);
	cout << s.maxProfit(prices) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}