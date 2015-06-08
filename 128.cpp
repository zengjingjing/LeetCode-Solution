/****************************************************************************************************
Solution:

这道题竟然要用set ,我也是醉了。。。这方面我还真的不太会。。。hash表
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int>& nums)
	{
		int size = nums.size();
		int ans = 0;
		set<int> mySet;
		for(int i = 0; i < size; i++)
			mySet.insert(nums[i]);
		while(!mySet.empty())
		{
			int first = *mySet.begin();
			int curLen = 1;
			int conse = first - 1;
			while(mySet.find(conse)!= mySet.end())
			{
				curLen++;
				mySet.erase(conse);
				conse--;
				
			}
			conse = first + 1;
			while(mySet.find(conse)!= mySet.end())
			{
				curLen++;
				mySet.erase(conse);
				conse++;
			}
			if(curLen > ans)
				ans = curLen;
			mySet.erase(first);
		}
		return ans;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(100);
	nums.push_back(4);
	nums.push_back(200);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(2);
	cout << s.longestConsecutive(nums) << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}

