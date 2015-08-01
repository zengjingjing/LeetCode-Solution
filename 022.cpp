/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> ans;
		string sub_ans;
		if(n <= 0)
			return ans;
		sub_ans.resize(2 * n);
		GenerateAll(ans, sub_ans, 0, n, 0 , 0);
		return ans;
	}

	void GenerateAll(vector<string>&ans, string& sub_ans, int start, int n, int leftNum, int rightNum)
	{
		if(start == 2 * n)
		{
			ans.push_back(sub_ans);
		}

		if(leftNum < n)
		{
			sub_ans[start] = '(';
			GenerateAll(ans, sub_ans, start + 1, n, leftNum + 1, rightNum);
		}
		if(rightNum < leftNum)
		{
			sub_ans[start] = ')';
			GenerateAll(ans, sub_ans, start + 1, n, leftNum, rightNum + 1);
		}
	}
};

void test()
{
	Solution s;
	int n = 1;
	vector<string> ans = s.generateParenthesis(n);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

}

int main()
{
	test();
	system("pause");
	return 1;
}

