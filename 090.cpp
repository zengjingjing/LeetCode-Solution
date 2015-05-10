#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct NUM
{
	int val;
	int times;
}NUM;
bool cmp(const int& left, const int& right)
{
	return left < right;
}
vector<vector<int>> GetSubsets(vector<NUM>& vec, int index)
{
	vector<vector<int>> ans;
	vector<int> sub_ans;
	if(index == vec.size() - 1)
	{
		ans.push_back(sub_ans);
		for(int i = 0; i < vec[index].times; i++)
		{
			sub_ans.push_back(vec[index].val);
			ans.push_back(sub_ans);
		}
		return ans;
	}
	vector<vector<int>> temp = GetSubsets(vec, index + 1);
	ans = temp;
	for(int i = 0; i < vec[index].times; i++)
	{
		sub_ans.push_back(vec[index].val);
		for(int j = 0; j < temp.size(); j++)
		{
			vector<int> temp_sub_ans = sub_ans;
			for(int k = 0; k < temp[j].size(); k++)
			{
				
				temp_sub_ans.push_back(temp[j][k]);
			}
			ans.push_back(temp_sub_ans);
		}

	}
	return ans;

}

class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
        vector<vector<int>> ans;
		if(nums.size() == 0)return ans;
		sort(nums.begin(), nums.end(), cmp);
		int size = nums.size();
		vector<NUM> vec;
		NUM temp;
		temp.val = nums[0];
		temp.times = 1;
		vec.push_back(temp);
		for(int i = 1; i < size; i++)
		{
			if(nums[i] != vec.back().val)
			{
				NUM temp;
				temp.val = nums[i];
				temp.times = 1;
				vec.push_back(temp);
			}
			else
				vec.back().times++;
		}
		ans = GetSubsets(vec, 0);
		return ans;
    }
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	//nums.push_back(3);
	vector<vector<int>> ans;
	ans = s.subsetsWithDup(nums);
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
