#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
    int majorityElement(vector<int>& nums)
	{
		map<int, int > myMap;
		int size = nums.size();
		if(size == 1)return nums[0];
		for(int i = 0; i < size; i++)
		{
			if(myMap.find(nums[i])!= myMap.end())
			{
				myMap[nums[i]]++;
				if(myMap[nums[i]] > size / 2 )return nums[i];
			}
			else
			{
				myMap.insert(make_pair(nums[i], 1));
				
			}
		}

    }
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(3);
//	nums.push_back(1);

	cout << s.majorityElement(nums) << endl;
}


int main()
{
test();
	system("pause");
	return 1;
}

