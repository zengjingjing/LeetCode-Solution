#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef struct Node
{
	int val;
	int index;
}Node;

bool cmp(const Node& n1, const Node& n2)
{
	return n1.val < n2.val;
}

class Solution 
{
public:
	vector<int> twoSum(vector<int> &numbers, int target) 
	{
		vector<Node> sortedVec;
		int i, j;
		vector<int> result;
		int size = numbers.size();
		for(i = 0; i < size; i++)
		{
			Node temp;
			temp.val = numbers[i];
			temp.index = i + 1;
			sortedVec.push_back(temp);

		}
		sort(sortedVec.begin(), sortedVec.end(), cmp);
		i = 0;
		j = size -1;
		while(i!=j)
		{
			if(sortedVec[i].val + sortedVec[j].val == target)
			{
				int index1 = sortedVec[i].index;
				int index2 = sortedVec[j].index;
				if(index1 < index2)
				{
					result.push_back(index1);
					result.push_back(index2);
				}
				else 
				{
					result.push_back(index2);
					result.push_back(index1);
				}
				break;
			}
			else if(sortedVec[i].val + sortedVec[j].val > target)
				j--;
			else if(sortedVec[i].val + sortedVec[j].val < target)
				i++;
		}
		return result;
	}
};

void test();
int main()
{
	test();
	system("pause");
	return 1;

}
void test()
{
	vector<int> t;
	vector<int> result;
	t.push_back(2);
	t.push_back(11);
	t.push_back(7);
	t.push_back(15);
	Solution s;
	result = s.twoSum(t, 9);
	cout << "index1 = " << result[0] <<" "<<"index2 = "<< result[1] << endl; 

}


