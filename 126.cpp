/****************************************************************************************************
Solution:
BFS构造解路径真的好麻烦 啊。。。。。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>

using namespace std;

typedef struct INFO
{
	int count;
	int index;

}INFO;

typedef struct PATH
{
	string word;
	set<int> prev;
	int level;
}PATH;

class Solution 
{
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
	{
		vector<vector<string>> ans;
		if(start == end)
		{
			vector<string> sub_ans;
			sub_ans.push_back(start);
			sub_ans.push_back(end);
			ans.push_back(sub_ans);
			return ans;
		}
		unordered_map<string, INFO> map1;
		vector<PATH> words;
		dict.insert(start);
		dict.insert(end);
		int i = 0;
		for(unordered_set<string>::const_iterator it = dict.begin(); it!= dict.end(); it++, i++)
		{
			INFO in;
			in.count = 0;
			in.index = i;
			map1.insert(make_pair(*it, in));
			PATH pa;
			pa.word = *it;
			//pa.prev.insert(-1);
			pa.level = 0;
			words.push_back(pa);
		}
		words[map1[start].index].prev.insert(-1);
		queue<string> queue1;
		queue1.push(start);
		map1[start].count = 1;
		int count = 1;
		int level = 1;
		bool flag = false;
		while(!queue1.empty())
		{
			int nextCount = 0;
			for(int i = 0; i < count; i++)
			{
				string topStr = queue1.front();
				int index = map1[topStr].index;
				if(topStr == end)
				{
					flag = true;
				}
				int size = topStr.size();
				string temp = topStr;
				for(int j = 0; j < size; j++)
				{
					for(char ch = 'a'; ch <= 'z'; ch++)
					{
						temp[j] = ch;
						if(map1.find(temp) != map1.end())
						{
							if(map1[temp].count == 0)
							{
								queue1.push(temp);
								nextCount++;
								words[map1[temp].index].prev.insert(index);
								words[map1[temp].index].level = level;
								map1[temp].count = 1;
							}
							if(level == words[map1[temp].index].level)
								words[map1[temp].index].prev.insert(index);
						}
					}
					temp[j] = topStr[j];
				}
				queue1.pop();
			}
			if(flag)
			{
				BuildPath(ans, words, map1[end].index);
				return ans;
			}
			count = nextCount;
			level++;
		}
		return ans;
	}

	void BuildPath(vector<vector<string>>& ans, vector<PATH>& words, int start)
	{
		vector<string> sub_ans;
		BuildRecursive(ans, sub_ans, words, start);
	}

	void BuildRecursive(vector<vector<string>>& ans, vector<string>& sub_ans, vector<PATH>& words, int start)
	{
		if(start == -1)
		{
			vector<string> temp = sub_ans;
			std::reverse(temp.rbegin(), temp.rend());
			ans.push_back(temp);
			return;
		}
		sub_ans.push_back(words[start].word);
		for(set<int>::const_iterator it = words[start].prev.begin(); it != words[start].prev.end(); it++)
		{
			BuildRecursive(ans, sub_ans, words, *it);
		}
		sub_ans.pop_back();

	}

};

void test()
{
	Solution s;
	string start = "a";
	string end = "b";
	unordered_set<string> dict;
	dict.insert("c");
	dict.insert("d");
	dict.insert("e");
//	dict.insert("lot");
//	dict.insert("lat");
//	dict.insert("log");
	//dict.insert("g");
	vector<vector<string>> ans = s.findLadders(start, end, dict);
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	test();
	system("pause");
	return 1;
}

