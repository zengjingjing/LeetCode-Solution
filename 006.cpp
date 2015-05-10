#include <iostream>
#include <string>
using namespace std;


class Solution 
{
public:
	string convert(string s, int nRows)
	{
		int i;
		string result = "";
		int size = s.size();
		if( nRows == 1 || nRows >= size)return s;
		for(i = 0; i < nRows; i++)
		{
			int index = i;
			result += s[i];
			int spanDown = 2 * (nRows - i - 1) + 1;
			int spanUp = 2 * i + 1;
			bool turn = false;// 先从上往下，在从上往下
			while(index < size)
			{
				if(turn == false)
				{
					int cur = index + spanDown - 1;
					index = cur;
					if(index < size && spanDown > 1)
						result += s[cur];
					turn = true;
				}
				else
				{

					int cur = index + spanUp - 1;
					index = cur;
					if(index < size && spanUp > 1)
						result += s[cur];

					turn = false;
				}
			}
		}
		return result;
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
	cout << s.convert("AB", 1) << endl;
}