/****************************************************************************************************
Solution:
这道题跟2sum一样的思路，对每一个元素都做2sum即可。
要注意的地方就是对重复元素的处理，千万不能直接在输入数组中把重复元素去掉。否则就把[0,0,0],[-1,-1,2]这样的组合就过滤掉了。
应该在面对重复元素的时候（num[i]==num[i-1]）,直接跳过即可。因为这个元素之前在i-1肯定已经处理过了，如果i-1满足要求，那么i满足要求
也是冗余的，如果i-1不满足要求，那么i肯定也不满足要求。
******************************************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <functional>
using namespace std;

vector<vector<int>> twoSum(vector<int> &numbers, int target, int left, int right, const int& val1, const int& val2) 
{
	int i = left;
	int j = right;
	vector<vector<int>> ans;

	while(i < j)
	{
		if(i > left && numbers[i] == numbers[i - 1])
		{
			i++;
			continue;
		}
		if(j < right && numbers[j] == numbers[j + 1])
		{
			j--;
			continue;
		}
		if(numbers[i] + numbers[j] == target)
		{
			vector<int> temp_result;
			temp_result.push_back(val1);
			temp_result.push_back(val2);
			temp_result.push_back(numbers[i]);
			temp_result.push_back(numbers[j]);				
			ans.push_back(temp_result);
			i++;
			j--;
		}
		else if(numbers[i] + numbers[j] > target)
			j--;
		else if(numbers[i] + numbers[j] < target)
			i++;

	}
	return ans;
}

class Solution 
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> ans;
		if(nums.size() < 4)return ans;
		sort(nums.begin(), nums.end(), less<int>()); 
		int i;
		int size = nums.size();
		for(i = 0; i < size - 3; i++)
		{
			if(i > 0 && nums[i] == nums[i - 1])
				continue;
			for(int j = i + 1; j < size - 2; j++)
			{
				if(j > i + 1 && nums[j] == nums[j - 1])continue;
				int sum = target - nums[i] - nums[j];
				vector<vector<int>> sub_result = twoSum(nums, sum, j + 1, size - 1, nums[i], nums[j]);
				if(sub_result.size() > 0)
				{
					int sub_size = sub_result.size();
					for(int k = 0; k < sub_size; k++)
					{
						ans.push_back(sub_result[k]);
					}

				}
			}

		}
		return ans;
	}

};


int main()
{
	Solution s;
	vector<int> test;
	ifstream infile("test.txt");
	string str;
	infile >> str;
	while(!str.empty())
	{
		int index = str.find_first_of(',');
		int val = atoi(str.substr(0, index).c_str());
		test.push_back(val);
		str.erase(0, index + 1);

	}

	vector<vector<int>> result = s.fourSum(test, 1);
	int i;
	int size = result.size();
	for(i = 0; i < size; i++)
	{
		int j;
		int sub_size = result[i].size();
		for(j = 0; j < sub_size; j++)
		{
			cout<< result[i][j];
			if(j < sub_size - 1)cout<<" ";
			else cout<<endl;
		}
	}
	system("pause");
	return 1;
}