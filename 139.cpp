#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution
{
public:
    bool wordBreak(string s, unordered_set<string>& wordDict)
	{
        if(s.size() == 0)return true;
		bool flag = false;
		for(int i = 0; i < s.size(); i++)
		{
			string sub_str = s.substr(0, i + 1);
			if(wordDict.find(sub_str)!= wordDict.end())
				flag = flag || wordBreak(s.substr(i + 1, s.size() - i - 1), wordDict);
		}
		return flag;
    }
};
void test()
{
	Solution s;
	unordered_set<string> wordDict ;
	wordDict.insert("leet");
	wordDict.insert("code1");
	if(s.wordBreak("leetcode", wordDict))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
int main()
{
test();
	system("pause");
	return 1;
}


