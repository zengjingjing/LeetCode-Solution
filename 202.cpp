#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;


int  Calculate(int n )
{
	int ans = 0;
	int count = 0;
	int temp  = n;
	while(temp > 0)
	{
		temp = temp / 10;
		count++;
	}
	int a = 1;
	for(int i = 0; i < count - 1; i++)
		a *= 10;
	for(int i = 0; i < count; i++)
	{
		ans += (n / a) * (n / a);
		n -= (n / a) * a;
		a /= 10;
	}
	return ans;
}
class Solution
{
public:
	bool isHappy(int n)
	{
		set<int> middleResult;		
		while(Calculate(n)!= 1)
		{
			if(middleResult.find(n) != middleResult.end())return false;			
			middleResult.insert(n);
			n = Calculate(n);
		}
		return true;
	}
};


void test()
{
	Solution s;
	if(s.isHappy(1))cout << "true" << endl;
	else cout << "false" << endl;
}

int main()
{
	test();	
	system("pause");
	return 1;
}

