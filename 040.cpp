
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void GetAllCombination(vector<int>& input, int target, int start, vector<vector<int>>& ans, vector<int>& sub_ans)
{
	if(target < 0)
		return ;
	if(target == 0)
	{
		ans.push_back(sub_ans);
		return ;
	}
	for(int i = start; i < input.size(); i++)
	{
		if(i > start && input[i] == input[i - 1])continue; // 这一行一定要，不管是能不能重复使用数字，这可以避免duplicate solution.
		sub_ans.push_back(input[i]);
		GetAllCombination(input, target - input[i], i + 1, ans, sub_ans);
		sub_ans.pop_back();
	}
}

class Solution 
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> ans;
		int size = candidates.size();
		if(size == 0)return ans;
		sort(candidates.begin(), candidates.end());
		vector<int> sub_ans;
		GetAllCombination(candidates, target, 0, ans, sub_ans);
		return ans;
	}
};



void test()
{
	Solution s;
	vector<int> candidates;
	int target = 8;
	candidates.push_back(1);
	candidates.push_back(2);
	candidates.push_back(7);
	candidates.push_back(6);
	candidates.push_back(1);
	candidates.push_back(5);
	vector<vector<int>> ans = s.combinationSum(candidates, target);
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	test();
	system("pause");
	return 1;
}