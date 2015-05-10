#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
	{
		int size1 = gas.size();
		int size2 = cost.size();
		if((size1 != size2) || size1 == 0 || size2 == 0)return -1;
		int i = 0;
		int left = 0;
		int start = 0;
		while(i < size1)
		{
			start = i;
			while(i < size1)
			{
				left += gas[i] - cost[i];
				i++;
				if(left < 0)
				{
					left = 0;
					break;
				}

			}
		}
		if(left < 0)return -1;
		left = 0;
		for(int i = start; i < (start + size1); i++)
		{
			left += gas[i%size1] - cost[i%size1];
			if(left < 0)return -1;
		}
		return start;
	}
};


void test()
{
	Solution s;
	vector<int> cost;
	vector<int> gas;
	cost.push_back(3);
	cost.push_back(4);
	gas.push_back(2);
	gas.push_back(4);

	cout << s.canCompleteCircuit(gas, cost) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}



