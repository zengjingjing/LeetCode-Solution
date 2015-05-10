#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows) 
	{
		vector<vector<int>> result;
		vector<int> sub_result;
		if(numRows <= 0)return result;
		if(numRows >= 1)
		{
			sub_result.push_back(1);
			result.push_back(sub_result);
		}
		int i = 1;

		while(i < numRows)
		{
		//	prev_result = result[i - 1];
			sub_result.clear();
			sub_result.push_back(1);
			for(int j = 0; j < result[i - 1].size() - 1; j++)
			{
				sub_result.push_back(result[i - 1][j] + result[i - 1][j + 1]);

			}
			sub_result.push_back(1);
			result.push_back(sub_result);
			i++;
		}
		return result;
    }
};

void test()
{
	Solution s;
	vector<vector<int>> result = s.generate(5);
	for(int i = 0; i < result.size(); i++)
	{
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
int main()
{
	test();
	system("pause");
	return 1;
}
