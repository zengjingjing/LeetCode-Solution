/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long GetCount(bool* visited, int count, int n)
{
	int index = 0;
	for(int i = 0; i < n; i++)
	{
		if(visited[i] == false)
			index++;
		if(index == count)
		{
			visited[i] = true;
			return i + 1;
		}
	}
}

void GetLast(string& ans, bool * visited, int n)
{
	for(int i = n - 1; i >= 0; i--)
	{
		if(visited[i] == false)
		{
			ans += to_string((long long)i + 1);
			visited[i] = true;
		}
	}
}

class Solution
{
public:
	string getPermutation(int n, int k)
	{
		string ans = "";	
		if(k <= 0)return ans;
		if(n == 0)return ans;
		if(n == 1)return "1";
		int *permutationToal = new int[n];
		int a = 2;
		permutationToal[n - 1] = 1;
		permutationToal[n - 2] = 1;
		for(int i = n - 3; i >= 0; i--)
		{
			permutationToal[i] = a * permutationToal[i + 1];
			a++;
		}

		bool * visited = new bool[n];
		for(int i = 0; i < n; i++)
			visited[i] = false;

		for(int i = 0; i < n; i++)
		{
			
			if(k == 0)
			{
				GetLast(ans, visited, n);
				break;
			}
			int count = ceil((double)k / permutationToal[i]);		
			ans += std::to_string(GetCount(visited, count, n));
			k -= (k / permutationToal[i]) * permutationToal[i];
		}
		delete permutationToal;
		delete visited;
		return ans;
	}
};

void test()
{
	Solution s;
	cout << s.getPermutation(4, 6) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}

