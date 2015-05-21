/****************************************************************************************************
Solution:
My fault: first i just thought out of sorting algorithm, which takes O(nlgn), but i haven't think out 
of the O(n) sorting(garbage sorting), although it could not solve this problem. But i should consider 
all the solution.

Using the thought of garbage sorting: the value A[i] should be placed in the right place( i + 1), if it isn't,
we should swap the value(A[i] and A[A[i] - 1]) iterally. After all the element being placed in their right place,
we can find out which one is not correspond to it's place, which is the first missing positive. 
******************************************************************************************************/




#include <iostream>
#include <string>
#include <vector>

using namespace std;


void Swap(int& a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

class Solution
{
public:
	int firstMissingPositive(vector<int>& nums) 
	{
		int size = nums.size();
		if(size == 0)return 1;
		for(int i = 0; i < size; i++)
		{
			while(nums[i] < size && nums[i] > 0 && nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
			{
				Swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for(int i = 0; i < size; i++)
		{
			if(nums[i] != i + 1)
				return (i + 1);
		}
		return size + 1;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(7);
	nums.push_back(8);
	nums.push_back(9);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(3);
//	nums.push_back(-1);
	cout << s.firstMissingPositive(nums) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
