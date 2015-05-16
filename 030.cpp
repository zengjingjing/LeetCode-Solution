#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<int> findSubstring(string s, vector<string>& words) 
	{
		vector<int> ans;
		vector<string> concatenation;
		int size = words.size();
		if(size == 0)return ans;
		if(size >= 1)
			concatenation.push_back(words[0]);
		int word_size = words[0].size();
		for(int i = 1; i < size; i++)
		{
			int cur_size = concatenation.size();
			for(int k = 0; k < cur_size; k++)
			{
				int insert_count = concatenation[k].size() / word_size;
				for(int j = 0; j <= insert_count; j++)
				{
					string str = concatenation[k];
					str.insert(j * word_size, words[i]);
					concatenation.push_back(str);
				}
			}
			concatenation.erase(concatenation.begin(), concatenation.begin() + cur_size);
		}
		for(int i = 0; i < concatenation.size(); i++)
		{
			int index = s.find(concatenation[i]);
			if(index != string::npos)
				ans.push_back(index);
		}
		return ans;

	}
};

void test()
{
	Solution s;
	string str = "barbar1foothebar1foobarman";
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("bar1");
	vector<int> ans = s.findSubstring(str, words);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;


}
int main()
{
	test();
	system("pause");
	return 1;
}
