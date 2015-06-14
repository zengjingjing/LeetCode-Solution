/****************************************************************************************************
Solution:
Wrod break I,  II 都是一维DP，II中需要用额外的数据结构set来保存word分割的中间结果，然后遍历一遍得到结果。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
	{
		vector<string> ans;
		int size = s.size();
		if(size == 0)return ans;
		vector<set<int>> sets;
		sets.resize(size + 1);
		sets[size].insert(size);
		for(int i = size - 1; i >= 0; i--)
		{
			for(int j = i; j < size; j++)
			{
				string sub_str = s.substr(i, j - i + 1);
				if(wordDict.find(sub_str) != wordDict.end())
				{
					if(sets[j + 1].size() > 0)
						sets[i].insert(j + 1);
				}
			}

		}
		ans = GetAllPossible(s, sets, 0);
		return ans;
	}

	vector<string> GetAllPossible(const string& s, vector<set<int>>& sets, int start)
	{
		vector<string> ans;
		if(start >= s.size())
			return ans;
		for(set<int>::const_iterator it = sets[start].begin(); it != sets[start].end(); it++)
		{			
			string str = s.substr(start, *it - start);
			vector<string> sub_ans = GetAllPossible(s, sets, *it);
			// 这里需要考虑sub_ans是否为0，如果不做判断统一考虑的话，那当sub_ans = 0时，ans没有push，这样就没有结果。这个地方我犯过好几次错误了。
			if(sub_ans.size() > 0)
			{
				for(int j = 0; j < sub_ans.size(); j++)
				{
					string temp = str;
					if(*it < s.size())
						temp += " ";
					temp += sub_ans[j];

					ans.push_back(temp);
				}
				//	ans.push_back(str);
			}
			else
				ans.push_back(str);
		}
		return ans;


	}
};

void test()
{
	Solution s;
	string str = "aaaaaaa";
	unordered_set<string> word_dict;
	word_dict.insert("aaaa");
	word_dict.insert("aa");
	word_dict.insert("a");
	//	word_dict.insert("aaaa");
	//	word_dict.insert("sand");
	//	word_dict.insert("dog");
	vector<string> ans = s.wordBreak(str, word_dict);
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
}


int main()
{
	test();
	system("pause");
	return 1;
}
