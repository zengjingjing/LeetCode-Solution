/****************************************************************************************************
Solution:

Classical DP problem.
Using the thinking of sub (arr, string etc.)
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int numDistinct(string s, string t)
	{
		int ans = 0;
		int rows = s.size();
		int cols = t.size(); 
		if(rows == 0 || cols == 0 || rows < cols)return ans;
		int** arr = new int*[rows];
		for(int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols];
			memset(arr[i], -1, sizeof(int) * cols);
		}

		return GetNum(s, t, arr, 0, 0) ;
	
	}

	int GetNum(const string& s, const string& t, int** arr, int start1, int start2)
	{
		if(start2 == t.size() && start1 <= s.size())
		{
			arr[start1 - 1][start2 - 1] = 1;
			return 1;
		}
		else if(start1 == s.size())
		{
			arr[start1 - 1][start2 -1] = 0;
			return 0;

		}
		int count = (s.size() - start1) - (t.size() - start2);
		int ans = 0;
		for(int i = start1; i < s.size() && i <= start1 + count; i++)
		{
			if(s[i] == t[start2])
			{
				if(arr[i][start2] == -1)
				{
					ans += GetNum(s, t, arr, i + 1, start2 + 1);
				}
				else 
					ans += arr[i][start2];

			}
		}
		arr[start1][start2] = ans;
		return arr[start1][start2];
	}
	
};

void test()
{
	Solution s;
	string source = "adbdadeecadeadeccaeaabdabdbcdabddddabcaaadbabaaedeeddeaeebcdeabcaaaeeaeeabcddcebddebeebedaecccbdcbcedbdaeaedcdebeecdaaedaacadbdccabddaddacdddc";
	string dest = "bcddceeeebecbc";

	cout << s.numDistinct(source,dest) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
