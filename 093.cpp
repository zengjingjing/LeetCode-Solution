/****************************************************************************************************
Solution:
Note that  the IP start with '0' is invalid. e.g 1.01....
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		vector<string> ans;
		string sub_ans = "";
		int size = s.size();
		if(size < 4 || size > 12)return ans;
		int level = 1;
		GetAllResult(s, 0, ans, sub_ans, level);
		return ans;

	}

	void GetAllResult(const string &s, int start, vector<string>&ans, string& sub_ans, int level)
	{
		if(level == 5 && start >= s.size())
		{
			ans.push_back(sub_ans.substr(0, sub_ans.size() - 1));
			return;
		}
		if(s[start] == '0')
		{

			sub_ans += "0";
			sub_ans += ".";
			GetAllResult(s, start + 1, ans, sub_ans, level + 1);
			sub_ans.pop_back();
			sub_ans.pop_back();
			return; 
		}
		for(int i = start; i < start + 3 && i < s.size(); i++)
		{
			string sub = s.substr(start, i - start + 1);
			int val = atoi(sub.c_str());
			if(val <= 255)
			{
				sub_ans += sub;
				sub_ans += ".";
				GetAllResult(s, i + 1, ans, sub_ans, level + 1);
				sub_ans.pop_back();
				sub_ans.erase(sub_ans.end() - sub.size(), sub_ans.end());		
			}
		}
	}
};
void test()
{
	Solution s;
	string str = "010010";
	vector<string> ans = s.restoreIpAddresses(str);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}

