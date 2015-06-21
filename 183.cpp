/****************************************************************************************************
Solution:
这道题是map + 位操作
map的用法和max points in a line 一样， 把所有中间结果存在map中，这样就减少了冗余的比较。
位操作是精髓，如果不用位操作，直接存string,那么当size(string) > 10e4, 需要的内存为o(10 * n * n) = 1GB，就会内存溢出
因为只有10个数，可以将这个size = 10的字符串转换成int,总共需要20位。注意要熟练位操作，是很精髓的压缩存储空间的方法。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
	vector<string> findRepeatedDnaSequences(string s)
	{
		map<char, int> map1;
		map1.insert(make_pair('A', 0));
		map1.insert(make_pair('T', 1));
		map1.insert(make_pair('C', 2));
		map1.insert(make_pair('G', 3));

		int size = s.size();
		vector<string> ans;
		if(size < 10)return ans;
		unsigned num = 0;
		map<unsigned int, int> map2;
		for(int i = 0; i < size; i++)
		{
			num = (num << 2) & 0x000FFFFF | map1[s[i]]; 
			if(i < 9)
				continue;
			if(map2.find(num) != map2.end())
				map2[num]++;
			else
				map2[num] = 1;
		}

		for(map<unsigned int, int>::const_iterator it = map2.begin(); it != map2.end(); it++)
		{
			if(it->second > 1)
			{
				string s = IntToATCG(it->first);			
				ans.push_back(s);
			}
		}
		return ans;

	}

	string IntToATCG(unsigned int num)
	{
		string ans = "";
		for(int i = 0; i < 10; i++)
		{
			int temp = num & 0x000C0000;
			if(temp == 0x00000000)
				ans.push_back('A');
			else if(temp == 0x00040000)
				ans.push_back('T');
			else if(temp == 0x00080000)
				ans.push_back('C');
			else
				ans.push_back('G');

			num <<= 2; 
		}
		return ans;
	}
};

void test()
{
	Solution s;
	string str = "AAAAACCC";
	vector<string> ans = s.findRepeatedDnaSequences(str);
	for(vector<string>::const_iterator it = ans.begin(); it != ans.end(); it++)
		cout << *it << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
