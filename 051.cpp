#include <iostream>
#include <string>
#include <vector>

using namespace std;

void GetSubAns(vector<vector<string>>& ans, bool** visited, int n)
{
	vector<string> sub_ans;
	for(int i = 0; i < n; i++)
	{
		string temp = "";
		for(int j = 0; j < n; j++)
		{
			if(visited[i][j] == true)
				temp.push_back('Q');
			else
				temp.push_back('.');
		}
		sub_ans.push_back(temp);
	}
	ans.push_back(sub_ans);
}

bool CanPlace(bool** visited, int n, int row, int col)
{
	for(int i = 0; i < n; i++)
	{
		if(visited[i][col] == true)return false;
	}

	int i = row,j = col;
	while(i < n && i >= 0 && j < n && j >= 0)
	{
		if(visited[i][j])return false;
		i--;
		j--;
	}

	i = row;
	j = col;

	while(i < n && i >= 0 && j < n && j >= 0)
	{
		if(visited[i][j])return false;
		i++;
		j++;
	}
	
	i = row;
	j = col;

	while(i < n && i >= 0 && j < n && j >= 0)
	{
		if(visited[i][j])return false;
		i--;
		j++;
	}

	i = row;
	j = col;

	while(i < n && i >= 0 && j < n && j >= 0)
	{
		if(visited[i][j])return false;
		i++;
		j--;
	}
	
	return true;

}

void GetSolution(vector<vector<string>>& ans, bool** visited, int n, int cur)
{
	if(cur == n)
	{
		GetSubAns(ans, visited, n);
		return ;
	}
	for(int i = 0; i < n; i++)
	{
		if(CanPlace(visited, n, cur, i))
		{
			visited[cur][i] = true;
			GetSolution(ans, visited, n, cur + 1);
			visited[cur][i] = false;
		}
	}
	return ;
}


class Solution 
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> ans;
		if(n == 0)return ans;
		bool ** visited = new bool*[n];
		for(int i = 0; i < n; i++)
		{
			visited[i] = new bool[n];
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				visited[i][j] = false;
		int cur = 0;
		GetSolution(ans, visited, n, cur);
		for(int i = 0; i < n; i++)
			delete visited[i];
		return ans;
	}
};

void test()
{
	Solution s;
	vector<vector<string>> ans = s.solveNQueens(1);
	for(int i = 0; i < ans.size(); i++)
	{
		for(int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << endl;
		}
		cout << endl;
	}

}
int main()
{
	test();
	system("pause");
	return 1;
}
