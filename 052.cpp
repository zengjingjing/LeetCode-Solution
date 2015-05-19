
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

void GetSolution(int& ans, bool** visited, int n, int cur)
{
	if(cur == n)
	{
		ans++;
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
	int totalNQueens(int n)
	{
		int ans = 0;
		if(n == 0)return 0;
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