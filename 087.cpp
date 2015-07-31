#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution 
{
public:
    bool isScramble(string s1, string s2)
	{
		int size1 = s1.size();
		int size2 = s2.size();
		if(size1 != size2)
			return false;
		if(size1 == 0)
			return true;
		int ***flag = new int**[size1];
		for(int i = 0; i < size1; i++)
		{
			flag[i] = new int*[size1];
			for(int j = 0; j < size1; j++)
			{
				flag[i][j] = new int[size1];
				for(int k = 0; k < size1; k++)
				{
					flag[i][j][k] = 0; // 0 = not visited, 1 = false, 2 = true;
				}
			}
		}
		int ans = JudgeScramble(s1, s2, 0, 0 ,size1, flag);    
		return ans == 2;
    }

	int JudgeScramble(const string& s1, const string& s2, int start1, int start2, int length, int*** flag)
	{
		if(flag[start1][start2][length] != 0)
			return flag[start1][start2][length];
		if(length == 1)
		{
			if(s1[start1] == s2[start2])
				flag[start1][start2][length] = 2;
			else
				flag[start1][start2][length] = 1;
			return flag[start1][start2][length];
		}
		for(int i = start1 + 1; i < start1 + length; i++)
		{
			int b1, b2;
			b1 = JudgeScramble(s1, s2, start1, start2, i - start1, flag);
			b2 = JudgeScramble(s1, s2, i, start2 + (i - start1), length - (i - start1), flag);
			if(b1 == 2 && b2 == 2)
			{
				flag[start1][start2][length] = 2;
				return flag[start1][start2][length];
			}

			b1 = JudgeScramble(s1, s2, start1, start2 + length - (i - start1), i - start1, flag);
			b2 = JudgeScramble(s1, s2, i, start2, length - (i - start1), flag);
			if(b1 == 2 && b2 == 2)
			{
				flag[start1][start2][length] = 2;
				return flag[start1][start2][length];
			}
		}
		flag[start1][start2][length] = 1;
		return flag[start1][start2][length];
	}

};

void test()
{
	Solution s;
	string s1 = "great";
	string s2 = "rgtae";
	if(s.isScramble(s1, s2))
		cout << "true" << endl;
	else
		cout << "false" <<endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}