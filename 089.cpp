/****************************************************************************************************
Solution:
注意:
input: 0
output 0  而不是  空
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<int> grayCode(int n) 
	{
		vector<int> ans;
		if(n == 0)
		{
			ans.push_back(0);
			return ans;
		}

		ans.push_back(0);
		ans.push_back(1);
		int temp = 1;
		for(int i = 2; i <= n; i++)
		{
			int size = ans.size();
			temp *= 2;
			for(int i = size - 1; i >= 0; i--)
			{
				ans.push_back(ans[i] + temp);
			}
		}
		return ans;
	}
};

void test()
{
	Solution s;
	vector<int> ans = s.grayCode(0);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	
}

int main()
{
	test();
	system("pause");
	return 1;
}
