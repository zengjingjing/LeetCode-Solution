#include <iostream>
#include <string>
using namespace std;

long long GetCombination(int a, int b)
{
    long long mul1 = 1;
	if(b == 0 || b == a)return 1;
    int c = ((a*1.0 / b) > 2)? b:(a - b);
	int count = c;
    while(count)
    {
        mul1 *= a;
        a--;
		count--;
    }
    long long mul2 = 1;

    while(c)
    {
        mul2 *= c;
        c--;
    }
    return mul1 / mul2;
}

class Solution {
public:
    int uniquePaths(int m, int n)
    {
           return GetCombination(m+n-2, n - 1);
    }
};
int main()
{
	//Solution s;
	//cout << s.uniquePaths(19, 13) <<endl;
	string s = "123";
	s.assign(s.rbegin(), s.rend());
	cout << s <<endl;
	
	system("pause");
}