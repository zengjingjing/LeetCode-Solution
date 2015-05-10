#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

vector<vector<int>> twoSum(vector<int> &numbers, int target, int left, int right, int val) 
	{
		int i = left;
	//	int size = numbers.size();
		int j = right;
		vector<vector<int>> result;

		while(i < j)
		{
			if(numbers[i] + numbers[j] == target)
			{
				vector<int> temp_result;
				temp_result.push_back(val);
				temp_result.push_back(numbers[i]);
				temp_result.push_back(numbers[j]);				
				result.push_back(temp_result);
				//break;
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

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num)
	{
		vector<vector<int>> result;
		if(num.size() < 3)return result;
		sort(num.begin(), num.end(), less<int>()); 
		int i;
		int size = num.size();
		int zero_index;
		for(i = 0; i < size; i++)
		{
			if(num[i] < 0 && num[i + 1] >= 0)break;
		}
		zero_index = i + 1;
		for(i = 0; i < zero_index; i++)
		{
			if(i > 0 && num[i] == num[i-1])continue;
			int sum2 = -num[i];
				// add result is negtive, find right through zero_index
				vector<vector<int>>sub_result = twoSum(num, sum2, i + 1, size - 1, num[i]);
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
	test.push_back(5);
	test.push_back(-1);
	test.push_back(-4);


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