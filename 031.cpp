#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0 || size == 1)
			return;
		int i = 0;
		for(i = size - 1; i > 0; i--)
		{
			if(nums[i - 1] < nums[i])
				break;
		}

		if(i == 0)
		{
			std::reverse(nums.begin(), nums.end());
			return;
		}

		int j;
		for(j = size - 1; j >= i; j--)
		{
			if(nums[j] > nums[i - 1])
				break;
		}
		int temp = nums[j];
		nums[j] = nums[i - 1];
		nums[i - 1] = temp;

		sort(nums.begin() + i, nums.end());
		return ;
		
	}
	
};

void PrintVec(vector<int>& nums)
{
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}
void test()
{
	Solution s;
	vector<int> nums;
	srand((unsigned int)time(NULL));
	for(int i = 0; i < 10; i++)
	{
		//int val = rand() % 10;
		nums.push_back(10 - i);
	}
	PrintVec(nums);
	s.nextPermutation(nums);
	PrintVec(nums);

}
int main()
{
	test();
	system("pause");
	return 1;
}

