/****************************************************************************************************
Solution:
Two demensional DP.
the hard part of DP is that you cannot find the optical sub-structure. Actually, i don't konw how to find the sub problem of this question,
so i cannot find the solution.

After you find the optical sub-structure, the next part is easy to do.

******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetMin3(const int& a, const int &b, const int& c)
{
	int max2 = a < b ? a : b;
	return max2 < c ? max2 : c;

}

class Solution
{
public:
	int minDistance(string word1, string word2) 
	{
		int rows = word1.size();
		int cols = word2.size();
		if(rows == 0 && cols == 0)return 0;
		if(rows == 0)return cols;
		if(cols == 0)return rows;
		int ** distance = new int*[rows + 1];
		for(int i = 0; i <= rows; i++)
			distance[i] = new int[cols + 1];

		for(int i = 0; i<= rows; i++)  
			for(int j = 0; j <= cols; j++)
				distance[i][j] = 0;
		for(int i = 0; i <= cols;i++)
			distance[0][i] = i;
		for(int i = 0; i <= rows;i++)
			distance[i][0] = i;

		for(int i = 1; i <= rows; i++)
		{
			for(int j = 1; j <= cols; j++)
			{
				
				if(word1[i - 1] == word2[j - 1])
					distance[i][j] = GetMin3(distance[i - 1][j - 1], distance[i - 1][j] + 1, distance[i][j - 1] + 1);
				else
					distance[i][j] = GetMin3(distance[i - 1][j - 1] + 1, distance[i - 1][j] + 1, distance[i][j - 1] + 1);
			}
		}
		return distance[rows][cols];
	}
};

void test()
{
	Solution s;
	string str1 = "ade";
	string str2 = "a";
	cout << s.minDistance(str1, str2) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}