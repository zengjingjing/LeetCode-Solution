/****************************************************************************************************
Solution:
The thinking in II is same as I.
But i run into the wrong way, i thought that the nums can be generated regularly. Which means the time complexity is O(N), not O(N*N)
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<int> getRow(int rowIndex) 
	{
		vector<int> ans;
		if(rowIndex < 0)return ans;
		ans.push_back(1);
		for(int i = 0; i < rowIndex; i++)
		{
			for(int j = ans.size() - 1; j > 0; j--)
			{
				ans[j] = ans[j - 1] + ans[j];
			}
			ans.push_back(1);
		}
		return ans;
	}
};


void test()
{
	Solution s;
	vector<int> ans = s.getRow(3);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

}
int main()
{
	test();
	system("pause");
	return 1;
}

