/****************************************************************************************************
Solution:
暴力搜索，啥也不说了。。。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum3(int k, int n) 
	{
		vector<vector<int>> ans;
		vector<int> sub_ans;
		int sum = 0;
		int start = 9;
		int cur_k = 0;
		GetAllPossible(ans, sub_ans, k, n, sum, cur_k, start);
		for(int i = 0; i < ans.size(); i++)
			std::reverse(ans[i].begin(), ans[i].end());
		return ans;
	}

	void GetAllPossible(vector<vector<int>>& ans, vector<int>& sub_ans, int k, int n, int sum, int cur_k, int start)
	{
		if(sum > n)
			return ;
		if(cur_k > k)
			return;		
		if(sum == n && cur_k == k)
		{
			ans.push_back(sub_ans);
			return ;
		}
		for(int i = start; i > 0; i--)
		{
			sub_ans.push_back(i);
			GetAllPossible(ans, sub_ans, k, n, sum + i, cur_k + 1, i - 1);
			sub_ans.pop_back();
		}
		return ;
	}
};

void test()
{
	Solution s;
	vector<vector<int>> ans = s.combinationSum3(3, 9);
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
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
