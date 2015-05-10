#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetMin(const int& a, const int &b)
{
	return a < b ? a : b;
}

class Solution 
{
public:
    int minimumTotal(vector<vector<int> > &triangle)
	{
		int size = triangle.size();
		if(size == 0)return size;
		int *prevMin = new int[size];
		int * curMin = new int[size];
		prevMin[0] = triangle[0][0];
	//	curMin[0] = triangle[0][0];
		for(int i = 1; i < size; i++)
		{
			for(int j = 0; j < triangle[i].size(); j++)
			{
				if(j == 0)
				curMin[j] = prevMin[j] + triangle[i][j];
				else if(j ==  triangle[i].size() - 1)
					curMin[j] = prevMin[j - 1] + triangle[i][j];
				else
					curMin[j] = GetMin(prevMin[j - 1],  prevMin[j]) + triangle[i][j];

			}
			for(int j = 0; j < triangle[i].size(); j++)
				prevMin[j] = curMin[j];
		}
		int result = prevMin[0];
		for(int i = 1; i < size; i++)
		{
			if( prevMin[i] < result)
				result =prevMin[i];

		}

		delete[] prevMin;
		delete[] curMin;
		return result;
    }

};

void test()
{
}
int main()
{
	test();
	system("pause");
	return 1;
}


