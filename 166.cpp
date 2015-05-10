#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
    string fractionToDecimal(int numerator, int denominator) 
	{
		string ans = "";
		if(denominator == 0)return ans;
		if(numerator == 0)return "0";
		if((long long)numerator * denominator < 0)ans += "-";
		long long l_numerator = fabs((double)numerator);
		long long l_denominator = fabs((double)denominator);
		long long  integer = l_numerator / l_denominator;
		ans += std::to_string((long long)integer);
		l_numerator -= integer * l_denominator;
		if(l_numerator == 0)return ans;
		ans += ".";
		map<long long , long long > nums_map;
		vector<int> nums_vec;
		long long left, right;
		int count = 0;
		while(l_numerator)
		{		

			if(nums_map.find(l_numerator) != nums_map.end())
				break;
			nums_map[l_numerator] = count;
			l_numerator *= 10;
			left = l_numerator / l_denominator;
			right = l_numerator % l_denominator;
			nums_vec.push_back(left);
			l_numerator = right;
			count++;
			
		}
		if(l_numerator == 0)
		{
			for(int i = 0; i < nums_vec.size(); i++)
			{
				ans.push_back(nums_vec[i] - 0 + '0');
			}
			return ans;
		}
		else
		{
			for(int i = 0; i < nums_vec.size(); i++)
			{
				if(i == nums_map[l_numerator])
					ans.push_back('(');
				ans.push_back(nums_vec[i] - 0 + '0');

			}
			ans.push_back(')');
			return ans;
		}
    }
};
void test()
{
	Solution s;
	cout << s.fractionToDecimal(-1, -2147483648) << endl;
}
int main()
{
test();
	system("pause");
	return 1;
}
