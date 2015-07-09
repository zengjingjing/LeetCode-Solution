/****************************************************************************************************
Solution:
简单的一维DP
要注意输入非法的情况，比如‘0’。不能认为输入都是1-9

******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
	int numDecodings(string s)
	{
		int ans = 0;
		set<string> set1;
		for(int i = 0; i < 26; i++)
		{
			
			string str = std::to_string(i + 1);
			set1.insert(str);
		}

		int size = s.size();
		if(size == 0)
			return ans;
		int *arr = new int[size + 1];
		string str = s.substr(size - 1, 1);
		if(set1.find(str) != set1.end())
			arr[size - 1] = 1;
		else
		{
			arr[size - 1] = 0;
		}

		arr[size] = 1;
		for(int i = size - 2; i >= 0; i--)
		{
			int temp = 0;
			int val;
			string str1 = s.substr(i, 1);
			string str2 = s.substr(i, 2);
			if(set1.find(str1) != set1.end())
				temp += arr[i + 1];
			if(set1.find(str2) != set1.end())
				temp += arr[i + 2];

			arr[i] = temp;
	
		}
		ans = arr[0];
		delete[] arr;
		return ans;
	}
};


void test()
{
	Solution s;
	string str = "0";
	cout << s.numDecodings(str) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
