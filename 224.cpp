/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
	int calculate(string s) 
	{
		stack<long long> s1;
		stack<char> s2;
		int index = 0;
		while(index < s.size())
		{
			if(s[index] >= '0' && s[index] <= '9')
			{
				int temp = index;
				while(s[temp] >= '0' && s[temp] <= '9')
					temp++;
				string str = s.substr(index, temp - index);
				long long val = atol(str.c_str());
				s1.push(val);
				index = temp;
			}
			else if(s[index] == ' ')
			{
				index++;
				continue;
			}
			else if(s[index] == '(')
			{
				s2.push(s[index]);
				index++;
			}
			else if(s[index] == ')')
			{
				char ch = s2.top();
				if(ch == '(')
				{
					s2.pop();
					index++;
				}
				else
				{
					CalculateOnce(s1, ch);
					s2.pop();
				}
			}
			else if(s[index] == '+' || s[index] == '-')
			{
				if(s2.empty())
				{
					s2.push(s[index]);
					index++;
				}
				else
				{
					char ch = s2.top();
					if(ch == '(')
					{
						s2.push(s[index]);
						index++;
					}
					else
					{
						CalculateOnce(s1, ch);	
						s2.pop();
					}
				}	
			}
		}
		while(!s2.empty())
		{
			char ch = s2.top();
			if(ch == '+' || ch == '-')
			{
				CalculateOnce(s1, ch); 
			}
			s2.pop();
		}
		return s1.top();

	}
	
	void CalculateOnce(stack<long long>& s, char ch)
	{
		long  long operator2 = s.top();
		s.pop();
		long  long operator1 = s.top();
		s.pop();
		if(ch == '+')
			s.push( operator1 + operator2);
		else
		{
			s.push( operator1 - operator2);
		}
	}

};
void test()
{
	Solution s;
	string str = " (1+(4+53+2)-32)+(61+8)";
	cout << s.calculate(str) << endl; 
}

int main()
{
	test();
	system("pause");
	return 1;
}
