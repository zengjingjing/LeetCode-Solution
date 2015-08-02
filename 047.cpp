/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		vector<vector<int>> ans;
		vector<int> sub_ans;
		int size = nums.size();
		if(size == 0)
			return ans;
		bool * visited = new bool[size];
		for(int i = 0; i < size; i++)
			visited[i] = false;
		TraversePermutation(ans, sub_ans, nums, visited, 0);
		return ans;
	}

	void TraversePermutation(vector<vector<int>>& ans, vector<int>& sub_ans, vector<int>& nums, bool * visited,int level)
	{
		if(level == nums.size())
		{
			ans.push_back(sub_ans);
			return ;
		}
		unordered_set<int> set1;
		for(int i = 0; i < nums.size(); i++)
		{
			if(visited[i] == false && set1.find(nums[i]) == set1.end())
			{
				sub_ans.push_back(nums[i]);
				visited[i] = true;
				set1.insert(nums[i]);
				TraversePermutation(ans, sub_ans, nums, visited, level + 1);
				visited[i] = false;
				sub_ans.pop_back();
			}

		}
	}
};


void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
//	nums.push_back(2);
//	nums.push_back(3);
//	nums.push_back(3);
	vector<vector<int>> ans = s.permuteUnique(nums);
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
