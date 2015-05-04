#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
	int findPeakElement(vector<int>& nums)
	{
		int size = nums.size();
		
		if(size == 0)return -1;
		if(size == 1)return 0;
		for(int i = 0; i < size; i++)
		{
			if(i == 0 && i + 1 < size && nums[i] > nums[i + 1])
			{
				return i;
			}
			else if(i == size - 1 && nums[i] > nums[i - 1])
			{
				return i;
			}
			else if(nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
			{
				return i;
			}

		}
		return -1;
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

