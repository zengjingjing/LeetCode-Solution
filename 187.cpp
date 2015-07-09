/****************************************************************************************************
Solution:
�������map + λ����
map���÷���max points in a line һ���� �������м�������map�У������ͼ���������ıȽϡ�
λ�����Ǿ��裬�������λ������ֱ�Ӵ�string,��ô��size(string) > 10e4, ��Ҫ���ڴ�Ϊo(10 * n * n) = 1GB���ͻ��ڴ����
��Ϊֻ��10���������Խ����size = 10���ַ���ת����int,�ܹ���Ҫ20λ��ע��Ҫ����λ�������Ǻܾ����ѹ���洢�ռ�ķ�����
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
