#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;


bool IsOperation(const string & str)
{
	if(str == "+" || str == "-" || str == "*" || str == "/")return true;
	return false;
}

int  Calculate(int left, int right, string oper)
{
	if(oper == "+")
		return left + right;
	if(oper == "-")
		return left - right;
	if(oper == "*")
		return left * right;
	if(oper == "/")
		return left / right;

}
class Solution 
{
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> myStack;
		if(tokens.size() == 0)return 0;
		for(int i = 0; i < tokens.size(); i++)
		{
			if(!IsOperation(tokens[i]))
				myStack.push(atoi(tokens[i].c_str()));
			else
			{
				int right = myStack.top();
				myStack.pop();
				int left = myStack.top();
				myStack.pop();
				myStack.push(Calculate(left, right, tokens[i]));
			}
		}
		return myStack.top();
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

