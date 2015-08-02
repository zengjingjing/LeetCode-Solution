/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution 
{
public:
    string simplifyPath(string path)
	{
		string ans = "";
		int size = path.size();
		if(size == 0)
			return ans;
		stack<string> myStack;
		if(path[size - 1] != '/')
			path += "/";
		while(!path.empty())
		{
			int index = path.find_first_of('/');
			string temp = path.substr(0, index);
			if(temp == "..")
			{
				if(!myStack.empty())
					myStack.pop();
			}
			else if(temp != "." && temp != "")
				myStack.push(temp);
			path.erase(0, index + 1);
		}
		if(myStack.empty())
			ans = "/";
		while(!myStack.empty())
		{
			string temp = "/" + myStack.top();
			ans = temp + ans;
			myStack.pop();
		}
		return ans;
    }
};


void test()
{
	Solution s;
	string path = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";
	cout << s.simplifyPath(path) << endl;
}


int main()
{
test();
	system("pause");
	return 1;
}
