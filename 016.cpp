/****************************************************************************************************
Solution:
这道题跟3sum一样的思路，只不过在2sum的过程中保存最接近的值即可。
******************************************************************************************************/
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <functional>
#include <cmath>
using namespace std;

typedef struct INFO
{
	int minGap;
	int sum;
}INFO;
INFO twoSum(vector<int> &numbers, const int& target, int left, int right, const int& val) 
{
	int i = left;
	int j = right;
	INFO ans;
	ans.minGap = 100000;
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
		int temp = numbers[i] + numbers[j] - target;
		if(fabs(double(temp)) < ans.minGap)
		{
			ans.minGap = fabs(double(temp));
			ans.sum = numbers[i] + numbers[j] + val;
			
		}
		if(temp == 0)
			return ans;
		else if(temp > 0)
			j--;
		else if(temp < 0)
			i++;
		
	}
	return ans;
}

class Solution 
{
public:
	int threeSumClosest(vector<int> &num, int target)
	{
		int minGap = 100000;
		int sum = 0;
		if(num.size() < 3)return sum;
		sort(num.begin(), num.end(), less<int>()); 
		int size = num.size();
		for(int i = 0; i < size - 2; i++)
		{
			if(i > 0 && num[i] == num[i-1])continue;
			int sum2 = target - num[i];
			INFO sub_ans = twoSum(num, sum2, i + 1, size - 1, num[i]);
			if(sub_ans.minGap < minGap)
			{
				sum = sub_ans.sum;
				minGap = sub_ans.minGap;
			}
		}
		return sum;
	}

};

void test()
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

	cout << s.threeSumClosest(test, -1000) << endl;
	return ;
}


int main()
{
	test();
	system("pause");
	return 1;
}