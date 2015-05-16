#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define MAX_INT 10000000
void Swap(int& a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
class Solution
{
public:
	void nextPermutation(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0 || size == 1)return ;
		for(int i = size - 2; i >= 0; i--)
		{
			int nextIndex = i;
			int nextVal = MAX_INT;
			for(int j = i + 1; j < size; j++)
			{
				if(nums[j] > nums[i] && nums[j] < nextVal)
				{
					nextVal = nums[j];
					nextIndex = j;
				}
			}
			if(nextIndex != i)
			{
				Swap(nums[i], nums[nextIndex]);
				return ;
			}
		}
		for(int i = 0; i < size / 2; i++)
		{
			Swap(nums[i], nums[size - i - 1]);
		}
		return ;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	s.nextPermutation(nums);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;

}
int main()
{
	test();
	system("pause");
	return 1;
}

