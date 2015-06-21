/****************************************************************************************************
Solution:
����map���ɡ�
��Ҫע����ǣ�������ͬ���ַ�����ӳ��Ϊͬһ���ַ����ڶ���ѭ����map2���ز����١�
���磺ab, aa,����ͨ��map1��ͨ������map2
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
	bool isIsomorphic(string s, string t) 
	{
		int size = s.size();
		map<char, char> map1;
		for(int i = 0; i < size; i++)
		{
			char ch = s[i];
			if(map1.find(ch) != map1.end())
			{
				if(map1[ch] == t[i])
					continue;
				else
					return false;
			}
			else
				map1[ch] = t[i];
		}
		map<char, int> map2;
		for(map<char,char>::const_iterator it = map1.begin(); it != map1.end(); it++)
		{
			if(map2.find(it->second) == map2.end())
				map2[it->second] = 1;
			else
				map2[it->second]++;
		}

		for(map<char,int>::const_iterator it = map2.begin(); it != map2.end(); it++)
		{
			if(it->second > 1)
				return false;
		}
		return true;
	}
};

void test()
{
	Solution s;
	string str1 = "ab";
	string str2 = "aa";
	if(s.isIsomorphic(str1, str2))
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
