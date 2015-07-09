/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
	{
		int ans = (D - B) * (C - A) + (H - F) * (G - E);
		if(E >= C || G <= A)
			return ans;
		if(F >= D || H <= B)
			return ans;
		int width = GetLength(A, C, E, G);
		int height = GetLength(B, D, F, H);
		return ans - width * height;
	}

	int GetLength(const int& a, const int& b, const int& c, const int& d)
	{
		vector<int> arr;
		arr.resize(4);
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		arr[3] = d;
		sort(arr.begin(), arr.end());
		return arr[2] - arr[1];
	}
};

void test()
{
	Solution s;
	cout << s.computeArea(-2, -2, 2, 2, -1, -1, 1, 1) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}

