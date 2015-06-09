/****************************************************************************************************
Solution:
http://blog.csdn.net/linhuanmars/article/details/21424783
思路是参考这上面的思路的，左右扫描，在README里面我也写下了我对这个算法的理解。
Leetcode上面将这个分类为：greedy
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int candy(vector<int>& ratings) 
	{
		int ans = 0;
		int size = ratings.size();
		if(size == 0)return ans;
		int *candyNum = new int[size];
		candyNum[0] = 1;
		for(int i = 1; i < size; i++)
		{
			if(ratings[i] > ratings[i - 1])
				candyNum[i] = candyNum[i - 1] + 1;
			else
				candyNum[i] = 1;			
		}
		for(int i = size - 1; i > 0; i--)
		{
			if(ratings[i - 1] > ratings[i] && candyNum[i - 1] <= candyNum[i])
				candyNum[i - 1] = candyNum[i] + 1;
		}
		for(int i = 0; i < size; i++)
			ans += candyNum[i];
		return ans;

	}
};

void test()
{
	Solution s;
	vector<int> ratings;
	ratings.push_back(3);
	ratings.push_back(5);
	ratings.push_back(1);
	ratings.push_back(2);
	ratings.push_back(4);
	ratings.push_back(6);

	cout << s.candy(ratings) << endl;

}
int main()
{
	test();
	system("pause");
	return 1;
}
