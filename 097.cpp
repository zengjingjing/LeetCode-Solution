/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//arr[i][j] == -1 means init,    = 0 means false,  = 1 means true
class Solution
{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		int rows = s1.size();
		int cols = s2.size();
		if(s3.size() != rows + cols)return false;
		if(rows == 0)
			return s2 == s3;
		if(cols == 0)
			return s1 == s3;

		int** arr = new int*[rows];
		for(int i = 0; i < rows; i++)
		{
			arr[i] = new int[cols];
			memset(arr[i], -1, sizeof(int) * cols);
		}
		return Judge(s1, s2, s3, 0, 0, 0, arr);
	}
	bool Judge(const string& s1, const string& s2, const string& s3,int start1, int start2, int start3, int** arr)
	{
		if(start3 >= s3.size())return true;
		bool b1  = false;
		bool b2 = false;
		if(start1 < s1.size() && start2 < s2.size())
		{
			if(arr[start1][start2] == 1)
				return true;
			else if(arr[start1][start2] == 0)
				return false;
			else
			{
				if(s3[start3] == s1[start1])
					b1 = Judge(s1, s2, s3, start1 + 1, start2, start3 + 1, arr);
				if(s3[start3] == s2[start2])
					b2 = Judge(s1, s2, s3, start1, start2 + 1, start3 + 1, arr);
				if(b1 || b2)
					arr[start1][start2] = 1;
				else
					arr[start1][start2] = 0;
				return b1 || b2;
			}
		}
		else if(start1 < s1.size())
		{
			if(arr[start1][start2 - 1] == 1)
				return true;
			else if(arr[start1][start2 - 1] == 0)
				return false;
			else
			{
				if(s3[start3] == s1[start1])
					b1 = Judge(s1, s2, s3, start1 + 1, start2, start3 + 1, arr);
				if(b1)
					arr[start1][start2 - 1] = 1;
				else
					arr[start1][start2 - 1] = 0;
				return b1;
			}
		}
		else if(start2 < s2.size())
		{
			if(arr[start1 - 1][start2] == 1)
				return true;
			else if(arr[start1 - 1][start2] == 0)
				return false;
			else
			{
				if(s3[start3] == s2[start2])
					b2 = Judge(s1, s2, s3, start1, start2 + 1, start3 + 1, arr);
				if(b2)
					arr[start1 - 1][start2] = 1;
				else
					arr[start1 - 1][start2] = 0;
				return b2;
			}
		}


	}
};

void test()
{
	Solution s;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc";
	if(s.isInterleave(s1, s2, s3))
		cout << "true" << endl;
	else cout << "false" << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
