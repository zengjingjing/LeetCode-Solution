/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution 
{
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
	{

		if(beginWord == endWord)
			return 0;
		unordered_map<string, int> map1;
		wordDict.insert(beginWord);
		wordDict.insert(endWord);
		for(unordered_set<string>::const_iterator it = wordDict.begin(); it!= wordDict.end(); it++)
		{
			map1.insert(make_pair(*it, 0));
		}

		map1[beginWord] = 0;
		map1[endWord] = 0;
		queue<string> queue1;
		queue1.push(beginWord);
		map1[beginWord] = 1;
		int count = 1;
		int level = 1;
		bool flag = false;
		while(!queue1.empty())
		{
			int nextCount = 0;
			for(int i = 0; i < count; i++)
			{
				string topStr = queue1.front();
				if(topStr == endWord)
				{
					flag = true;
					return level;
				}
				int size = topStr.size();
				string temp = topStr;
				for(int j = 0; j < size; j++)
				{
					for(char ch = 'a'; ch <= 'z'; ch++)
					{
						temp[j] = ch;
						if(map1.find(temp) != map1.end() && map1[temp] == 0)
						{
							queue1.push(temp);
							nextCount++;
							map1[temp] = 1;
						}
						
					}
					temp[j] = topStr[j];
				}
				queue1.pop();
			}
			count = nextCount;
			level++;
		}
		if(flag)
			return level;
		else
			return 0;


	}

	bool IsSimilar(const string& str1, const string& str2)
	{
		int count = 0;
		int size1 = str1.size();
		int size2 = str2.size();
		int i = 0;
		while(i < size1 && i < size2)
		{
			if(str1[i] != str2[i])
				count++;
			if(count > 1)
				break;
			i++;
		}
		return count == 1;
	}
};

void test()
{
	Solution s;
	string beginWord = "hit";
	string endWord = "dog";
	unordered_set<string> wordDict;
	wordDict.insert("hot");
	wordDict.insert("dog");
//	wordDict.insert("b");
//	wordDict.insert("b");
	//wordDict.insert("b");
	//wordDict.insert("g");
	cout << s.ladderLength(beginWord, endWord, wordDict) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}

