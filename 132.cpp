/****************************************************************************************************
Solution:
Method 1 : i use 2 "for iteration",  and a judge for each substring. It takes O(N * N * N). TLE

Method 2: first we can use extra space(2-dimensional array) to store the palindrome judge result.
Then the time complexity is O(N * N).

005: Longest Palindromic Substring can use  method 2. 


******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int minCut(string s)
	{
		int ans = 0;
		int size = s.size();
		if(size == 0)return ans;
		int start = 0;
		int * arr = new int[size + 1];
		bool ** judge = new bool*[size];
		for(int i = 0; i < size; i++)
		{
			judge[i] = new bool[size];
			for(int j = 0; j < size; j++)
				judge[i][j] = false;
		}
		JudgePalidrome(s, judge);
		memset(arr, -1, sizeof(int) * (size + 1));
		arr[size] = -1;         //  arr means the minCut of index to the last element.
		for(int i = size - 1; i >= 0; i--)
		{
			int minimal = 10000;
			for(int j = i; j < size; j++)
			{
				if(judge[i][j])
				{
					if(arr[j + 1] + 1 < minimal)
						minimal = arr[j + 1] + 1;		
				}
			}
			arr[i] = minimal;
		}
		ans = arr[0];
		delete arr;
		return ans;
	}

	void JudgePalidrome(const string& s, bool** judge)
	{
		int size = s.size();
		for(int i = size - 1; i >= 0; i--)
		{
			for(int j = i; j < size; j++)
			{
				if(j == i)
					judge[i][j] = true;
				else if(j - i < 2 && s[i] == s[j])
					judge[i][j] = true;
				else if(j - i >= 2 && s[i] == s[j] && judge[i + 1][j - 1] == true)
					judge[i][j] = true;
			}
		}
	}
};

void test()
{
	Solution s;
	string str = "aaaaaa";
	cout << s.minCut(str) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
