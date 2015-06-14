/****************************************************************************************************
Solution 1:
用一个map额外存储每个元素出现的个数，当然这是不符合题目要求的，不过也可以AC。这种题generalize之后，这就是一般化的解法（也就是说如果元素出现的个数不为2，为3为4，或者不等）

Solution 2:
方法1有点小题大做。
这类题可以这样：用位图来做，由于元素都是整形， 可以开辟int arr[32]数组，存放的是所有元素每一位的和。出现2次的元素之和，1个个数肯定是2的倍数，可以用这个结果%2， 剩下的就是
那个单一的元素做的贡献了。

这种思想非常精妙，我以前从未见过！

Solution 3:
相同元素异或 = 0，a1 ^ a2 ^ a3... 可以交换，所以可以把所有元素异或，最后的结果就是单一的元素。

137：同solution 2。

******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums) 
	{

		int size = nums.size();
		if(size == 0)return 0;
		int arr[32];
		memset(arr, 0, sizeof(int) * 32);
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = 0; j < 32; j++)
			{
				arr[31 - j] += (nums[i] >> j) & 1;
			}
		}
		int ans = 0;
		int temp = 1;
		for(int i = 31; i >= 0; i--)
		{
			
			ans += (arr[i] % 2) * temp;
			temp *= 2;
		}
		return ans;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
//	nums.push_back(2);
//	nums.push_back(3);
//	nums.push_back(2);
//	nums.push_back(1);
	cout << s.singleNumber(nums) << endl; 
}
int main()
{
	test();
	system("pause");
	return 1;
}
