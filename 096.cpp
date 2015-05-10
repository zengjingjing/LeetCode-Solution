#include <iostream>
#include <vector>
#include <string>
using namespace std;

int *res;
void GetNums(int n)
{
	res[n] = 0;
	for(int i = 0; i < n; i++)
	{
		res[n] += res[i] * res[n - 1 - i];
	}
	

}

class Solution
{
public:
	int numTrees(int n) 
	{
		int *res = new int[n + 1];
		res[0] = 1;
		res[1] = 1;
		if(n == 0)return res[0];
		if(n == 1)return res[1];
		for(int i = 2; i <= n; i++)
		{
			res[i] = 0;
			for(int j = 0; j < i; j++)
			{
				res[i] += res[j] * res[i - 1 - j];
			}
		}
		return res[n];
		
	}
};


void test()
{
	Solution s;
	cout << s.numTrees(4) << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}




