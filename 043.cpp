/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	string multiply(string num1, string num2)
	{
		string ans;
		string str = "";
		for(int i = num2.size() - 1; i >= 0; i--)
		{
			string temp = StringMulChar(num1, num2[i]);
			temp = temp + str;
			if(i == num2.size() - 1)
				ans = temp;
			else
				ans = AddTwoString(ans, temp);
			str.push_back('0');
			
		}
		while(ans[0] == '0')
			ans.erase(0, 1);
		if(ans.empty())
			ans = "0";
		return ans;
	}
	
	string StringMulChar(const string& str, const char& ch)
	{
		string ans;
		int size = str.size();
		ans.resize(size + 1);
		int jinwei = 0;
		int val1;
		int val2 = ch - '0';
		for(int i = size - 1; i >=0; i--)
		{
			val1 = str[i] - '0';
			ans[i + 1] = (val1 * val2 + jinwei) % 10 + '0';
			jinwei = (val1 * val2 + jinwei) / 10;
		}
		ans[0] = jinwei + '0';
		if(ans[0] == '0')
			return ans.substr(1, ans.size() - 1);
		else
			return ans;
	}

	string AddTwoString( string str1,  string str2)
	{
		string ans;
		int size1 = str1.size();
		int size2 = str2.size();
		int maxSize = size1 > size2 ? size1 : size2;
		int minSize = size1 < size2 ? size1 : size2; 
		ans.resize(maxSize + 1);
		int jinwei = 0;
		string str;
		for(int i = 0; i < maxSize - minSize; i++)
			str.push_back('0');
		if(size1 < maxSize)
			str1 = str + str1;
		if(size2 < maxSize)
			str2 = str + str2;

		int index = maxSize - 1;
		int index2 = ans.size() - 1;
		while(index >= 0)
		{
			int val1 = str1[index] - '0';
			int val2 = str2[index] - '0';
			ans[index2] = (val1 + val2 + jinwei) % 10 + '0';
			jinwei = (val1 + val2 + jinwei) / 10;
			index--;
			index2--;
		}
		if(jinwei)
			ans[0] = '1';
		else
			ans[0] = '0';
	//	if(ans[0] == '0')
	//		return ans.substr(1, ans.size() - 1);
		return ans;
	}
};

void test()
{
	Solution s;
	string num1 = "123";
	string num2 = "01";
	cout << s.multiply(num1, num2) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
