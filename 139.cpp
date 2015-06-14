/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) 
	{
		int size = s.size();
		if(size == 0)return false;
		bool ans = false;
		bool* arr = new bool[size + 1];
		for(int i = 0; i < size; i++)
			arr[i] = false;
		arr[size] = true;
		for(int i = size - 1; i >= 0; i--)
		{
			bool temp_ans = false;
			for(int j = i; j < size; j++)
			{
				string sub_str = s.substr(i, j - i + 1);
				if(wordDict.find(sub_str) != wordDict.end())
				{
					temp_ans = temp_ans || arr[j + 1];
					if(temp_ans == true)
						break;
				}
			}
			arr[i] = temp_ans;
		}
		ans = arr[0];
		delete arr;
		return ans;
	 }
};

void test()
{
	Solution s;
	string str = "leetcode";
	unordered_set<string> word_dict;
	word_dict.insert("lee1t");
	word_dict.insert("code");
	if(s.wordBreak(str, word_dict))
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
