#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> permute(vector<int>& nums) 
	{
		vector<vector<int>> ans;
		int size = nums.size();
		if(size == 0)return ans;
		vector<int> sub_ans;
		sub_ans.push_back(nums[0]);
		ans.push_back(sub_ans);
		for(int i = 1; i < size; i++)
		{
			int sub_size = ans.size();
			for(int j = 0; j < sub_size; j++)
			{
				int insert_count = ans[j].size();
				for(int k = 0; k <= insert_count; k++)
				{
					vector<int> temp = ans[j];
					temp.insert(temp.begin() + k, nums[i]);
					ans.push_back(temp);
				}
			}
			ans.erase(ans.begin(), ans.begin() + sub_size);
		}
		return ans;
	}

};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int>> ans = s.permute(nums);
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

