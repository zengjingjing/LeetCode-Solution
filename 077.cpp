/****************************************************************************************************
Solution:

When combination, we need to consider the order, so we should place the next one bigger than the prev one.

This one is easy, but it takes me 30 mins...............




WHA£Ô¡¡¡¡¡¡£Á¡¡¡¡¡¡¡¡FUCK£¡£¡£¡
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GetAllCombination(vector<vector<int>>& ans, vector<int>& sub_ans, int k, int n ,int level)
{
	if(level > k)
	{
		vector<int> temp = sub_ans;
		temp.erase(temp.begin());
		ans.push_back(temp);
		return ;
	}
	int last = sub_ans.back();
	for(int i = 0; i < n - k + 1; i++)
	{
		int ele = level + i;
		if(ele > last)
		{
			sub_ans.push_back(ele);
			GetAllCombination(ans, sub_ans, k, n, level + 1);
			sub_ans.pop_back();
		}
	}
	return ;
}

class Solution 
{
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<int> sub_ans;
		vector<vector<int>> ans;
		sub_ans.push_back(0);
		if(n == 0)return ans;
		int level = 1;
		GetAllCombination(ans, sub_ans, k, n, level);
		return ans;
	}
};

void test()
{
	Solution s;
	vector<vector<int>> ans = s.combine(6,0);
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[0].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 1;
}
