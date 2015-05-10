#include <iostream>
#include <string>
using namespace std;
typedef enum{NONE, EVEN, ODD}TYPE;
class Solution
{
public:
	string longestPalindrome(string s)
	{

		if(s.size() < 2)return s;

		int maxLen = 0;
		int maxLeftIndex = -1;
		int maxRightIndex = -1;
		int i, j;
		//bool flag = false;
		TYPE flag = NONE;
		int size =s.size();
		for(i = 0; i < size - 1; i++)
		{
			if(s[i] == s[i+1])
			{
				int currentLen = 0;
				//flag = true;
				int rightIndex = i + 1;
				int leftIndex = i;
				while(rightIndex < size && leftIndex >=0  && s[rightIndex] == s[leftIndex])
				{
					rightIndex++;
					leftIndex--;
					currentLen += 2;
				}
				if(currentLen > maxLen)
				{
					maxLeftIndex = leftIndex;
					maxRightIndex = rightIndex; 
					maxLen = currentLen;
					flag = EVEN;
				}
			}
			if(i - 1 >= 0)
			{
				//int currentLen = 0;
				char leftChar = s[i - 1];
				char rightChar = s[i + 1];
				if(leftChar == rightChar)
				{
					//flag = true;
					int currentLen = 1;
					int rightIndex = i + 1;
					int leftIndex = i - 1;
					while(rightIndex < size && leftIndex >=0  && s[rightIndex] == s[leftIndex])
					{
						rightIndex++;
						leftIndex--;
						currentLen += 2;
					}
					if(currentLen > maxLen)
					{
						maxLeftIndex = leftIndex;
						maxRightIndex = rightIndex; 
						maxLen = currentLen;
						flag = ODD;
					}
				}
			}
		}
		string result;
		if(flag)
		{
			result = s.substr(maxLeftIndex + 1, maxLen);
			return result;
		}
		else 
		{
			result = s.substr(0,1);		
			return  result;
		}


	}
};
void test();
int main()
{
	test();
	system("pause");
	return 1;
}

void test()
{
	Solution s;
	cout << s.longestPalindrome("abcabccbad") << endl;

}