#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;


void Swap(int& a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
bool Compare(const int& left, const int& right)
{
	string s1 = to_string((long long )left);
	string s2 = to_string((long long )right);
	int size1 = s1.size();
	int size2 = s2.size();
	int i = 0,j = 0;
	while(i < size1 && j < size2)
	{
		if(s1[i] - s2[j] > 0 )return true;
		else if(s1[i] - s2[j] < 0)return false;
		i++;
		j++;
	}
	if(i == size1 && j == size2)return false;
	string r1 = s1.substr(0, i);
	string r2; 
	string temp1;
	string temp2;
	if(size2 > size1)
	{
		r2 = s2.substr(j,s2.size() - j);
		temp1 = r1 + r2;
		temp2 = r2 + r1;
	}
	else
	{
		r2 = s1.substr(i, s1.size() - i);
		 temp1 = r2 + r1;
		 temp2 = r1 + r2;

	}
	for(int i = 0; i < temp1.size(); i++)
	{
		if(temp1[i] - temp2[i] > 0)return true;
		else if(temp1[i] - temp2[i] < 0)return false;
	}
	return false;

}


void SelectSort(vector<int>& nums)
{
	int size = nums.size();
	for(int i = 0; i < size - 1; i++)
	{
		int maxVal = nums[i];
		int maxIndex = i;
		for(int j = i; j < size; j++)
		{
			if(Compare(nums[j], nums[maxIndex]))
			{
				maxVal = nums[j];
				maxIndex = j;
			}
		}
		if(i != maxIndex)
			Swap(nums[maxIndex], nums[i]);
	}

}



class Solution 
{
public:
	string largestNumber(vector<int>& nums)
	{
		
		//sort(nums.begin(), nums.end(), Compare);
		SelectSort(nums);
		string ans = "";
		for(int i = 0; i < nums.size(); i++)
		{
			ans += to_string((long long )nums[i]);
		}
		while(ans.size() > 1 && ans[0] == '0')
			ans.erase(0, 1);
		return ans;
	}
};



void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	nums.push_back(0);
	cout << s.largestNumber(nums) << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}
