/************************************************************
Note:
这道题的核心思想是要将string内部排序，不然在匹配的时候会非常麻烦。
**************************************************************/



#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<string> anagrams(vector<string>& strs)
	{
		vector<string> ans;
		if(strs.size() == 0)
			return ans;
		map<string, vector<string>> myMap;
		for(int i = 0; i < strs.size(); i++)
		{
			string s = strs[i];
			sort(s.begin(), s.end());
			myMap[s].push_back(strs[i]);

		}
		for(map<string, vector<string>>::const_iterator it = myMap.begin(); it != myMap.end(); it++)
		{
			if(it->second.size() > 1)
				ans.insert(ans.end(), it->second.begin(), it->second.end());
		}
		return ans;
	}
};

void test()
{
	Solution s;
	vector<string> strs;
	strs.push_back("tea");
	strs.push_back("ate");
	strs.push_back("eta");
	strs.push_back("and");
	strs.push_back("dan");
	vector<string> ans = s.anagrams(strs);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

}
int main()
{
	test();
	system("pause");
	return 1;
}
