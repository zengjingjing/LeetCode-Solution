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

vector<vector<int>> twoSum(vector<int> &numbers, int target, int left, int right, int val) 
{
	int i = left;
	int j = right;
	vector<vector<int>> result;

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
			temp_result.push_back(val);
			temp_result.push_back(numbers[i]);
			temp_result.push_back(numbers[j]);				
			result.push_back(temp_result);
			i++;
			j--;
		}
		else if(numbers[i] + numbers[j] > target)
			j--;
		else if(numbers[i] + numbers[j] < target)
			i++;
		
	}
	return result;
}

class Solution 
{
public:
	vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int>> result;
		if(num.size() < 3)return result;
		sort(num.begin(), num.end(), less<int>()); 
	/*	vector<int> tempNum;
		tempNum.push_back(num[0]);
		for(int i = 1; i < num.size(); i++)
		{
			if(num[i] != num[i - 1])
				tempNum.push_back(num[i]);
		}
		num = tempNum;*/
		int i;
		int size = num.size();
		int zero_index;
		for(i = 0; i < size - 1; i++)
		{
			if(num[i] <= 0 && num[i + 1] > 0)break;
		}
		zero_index = i + 1;
		for(i = 0; i < zero_index; i++)
		{
			if(i > 0 && num[i] == num[i-1])continue;
			int sum2 = -num[i];
			// add result is negative, find right through zero_index
			vector<vector<int>> sub_result = twoSum(num, sum2, i + 1, size - 1, num[i]);
			if(sub_result.size() > 0)
			{
				int j;
				int sub_size = sub_result.size();
				for(j = 0; j < sub_size; j++)
				{
					result.push_back(sub_result[j]);
				}
				
			}
		}
		return result;
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

	vector<vector<int>> result = s.threeSum(test);
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