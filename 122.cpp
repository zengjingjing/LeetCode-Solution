/****************************************************************************************************
Solution:
The thinking of the problem is amazing. 等价思维，转换的思路，这就是一道数学题，我高中的时候应该能做出来。
It is much different from I(DP).
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
		for(int i = 0; i < size - 1; i++)
		{
			prices[i] = prices[i + 1] - prices[i];
		}
		int ans = 0;
		for(int i = 0; i < size - 1; i++)
		{
			if(prices[i] > 0)
				ans += prices[i];
		}
		return ans;
	}
};

void test()
{

}
int main()
{
	test();
	system("pause");
	return 1;
}
