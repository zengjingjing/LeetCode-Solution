#include <iostream>
#include <string>
using namespace std;

string NextSay(string prev)
{
	int start = 0;
	string result = "";
	while(start < prev.size())
	{
		char ch = prev[start];
		int count = 1;
		while((start + 1) < prev.size() && prev[start+1] == ch)
		{
			count++;
			start++;
		}
		result += std::to_string(count);
		
		result += ch;
		start++;


	}
	return result;
}

class Solution
{
public:
    string countAndSay(int n)
	{
        int i;
		if(n == 1)return "1";
		string prev = "1";
		string result;
		for(i = 0; i < n - 1; i++)
		{
			result = NextSay(prev);
			prev = result;
		}
		return result;
    }
};
int main()
{
	Solution s;
	cout << s.countAndSay(7) << endl;
	system("pause");
	return 1;

}