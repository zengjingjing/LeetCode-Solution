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
		sub_ans.push_back(input[i]);
		GetAllCombination(input, target - input[i], i, ans, sub_ans);
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
		vector<int> input;
		input.push_back(candidates[0]);
		int prev = candidates[0];
		for(int i = 1; i < size; i++)
		{
			if(prev == candidates[i])
				continue;
			else
			{
				input.push_back(candidates[i]);
				prev = candidates[i];
			}
		}
		vector<int> sub_ans;
		GetAllCombination(input, target, 0, ans, sub_ans);
		return ans;
	}
};



void test()
{
	Solution s;
	vector<int> candidates;
	int target = 11;
	candidates.push_back(8);
	candidates.push_back(7);
	candidates.push_back(4);
	candidates.push_back(3);
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