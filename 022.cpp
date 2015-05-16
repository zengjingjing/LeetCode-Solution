#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct STR
{
	string str;
	int start;
	STR(string s, int st){str = s; start = st;}
	STR(){};
};
STR GenerateLast(int n)
{
	STR ret;
	string ans = "(";
	for(int i = 0; i < n - 1; i++)
		ans += "()";
	ans.push_back(')');
	ret.str = ans;
	ret.start = ans.size() - 2;
	return ret;
	
}
class Solution
{
public:
	vector<string> generateParenthesis(int n) 
	{
		vector<string> ans;
		vector<STR> temp_ans;
		if(n == 0)return ans;
		string str1 = "()";
		string str2 = "()()";
		string str3 = "(())";
		if(n == 1)
		{
			ans.push_back(str1);
			return ans;
		}

		if(n >= 2)
		{
			temp_ans.push_back(STR(str2, 2));
			temp_ans.push_back(STR(str3, 0));
		}
		for(int i = 3; i <= n; i++)
		{
			int size = temp_ans.size();
			for(int j = 0; j < size; j++)
			{
				STR s = temp_ans[j];
				temp_ans[j].start = temp_ans[j].str.size();
				temp_ans[j].str = temp_ans[j].str + "()";
				s.str.insert(s.start,"(");
				s.str.push_back(')');
				//s.start = start;
				temp_ans.push_back(s);
			}
			STR last = GenerateLast(i);
			temp_ans.push_back(last);
		}
		for(int i = 0; i < temp_ans.size(); i++)
			ans.push_back(temp_ans[i].str);
		return ans;
	}
};

void test()
{
	Solution s;
	vector<string> ans = s.generateParenthesis(4);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
