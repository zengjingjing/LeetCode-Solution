#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
	{
		int size = s.size();
		if(size == 0)return 0;
		int i;
		int j;
		int count = 1;
		int maxCount = -1;
		string sub = "";
		for(i=0;i<size;i++)
		{
			count  = 1;
			if(i == size - 1)
			{
				return maxCount > 1 ? maxCount : 1;
			}
			for(j = i+1; j <size;j++)
			{
				sub = s.substr(i,j-i);
				char ch = s[j];
				if(sub.find(ch)==string::npos)
					count++;
				else break;
			}			
			if(count > maxCount)maxCount = count; 
		}
		return maxCount;
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
	cout<< s.lengthOfLongestSubstring("au")<<endl;
	cout<<s.lengthOfLongestSubstring("bbb")<<endl;

	
}