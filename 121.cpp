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
		int min = prices[0];
		int max = prices[0];
		int minIndex = 0;
		int maxIndex = 0;
		for(int i = 1; i < size; i++)
		{
			if(prices[i] > max)
				{
					max = prices[i];
					maxIndex = i;
			}
			else if(prices[i] < min)
				{
					min = prices[i];
					minIndex = i;
			}
		}
		if(minIndex <= maxIndex)
			return (max - min);
		return 0;
    }
};

void test()
{
	string s;
	
}
int main()
{
	test();
	system("pause");
	return 1;
}


