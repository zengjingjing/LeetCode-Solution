/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool isAnagram(string s, string t)
	{
		std::sort(s.begin(), s.end());
		std::sort(t.begin(), t.end());
		return s == t;
	}
};

void test()
{
	Solution s;
	string s1 = "";
	string s2= "";
	if(s.isAnagram(s1, s2))
		cout << "true" << endl;
	else
	{
		cout << "false" << endl;
	}
}

int main()
{
	test();
	system("pause");
	return 1;
}

