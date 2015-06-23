/****************************************************************************************************
Solution:
简单题：利用map即可。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		int size = nums.size();
		if(size == 0)return false;
		map<int, int> myMap;
		for(int i = 0; i < size; i++)
		{
			if(myMap.find(nums[i]) != myMap.end())
				myMap[nums[i]]++;
			else
				myMap[nums[i]] = 1;
		}

		for(map<int, int>::const_iterator it = myMap.begin(); it != myMap.end(); it++)
		{
			if(it->second > 1)
				return true;
		}
		return false;
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
