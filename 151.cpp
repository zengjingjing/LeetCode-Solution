#include <iostream>
#include <vector>
#include <string>
using namespace std;


void trim(string& s)
{
	
	while(s.size() > 0 && s[0] == ' ')
		s.erase(0, 1);
}

class Solution
{
public:
	void reverseWords(string &s)
	{
		if(s.size() == 0)return ;
		vector<string> stored;
		trim(s);
		while(s.find(' ')!= string::npos)
		{
			int index= s.find(' ');
			stored.push_back(s.substr(0,index));
			s.erase(0, index + 1);
			trim(s);
		}
		if(!s.empty())
		{
			stored.push_back(s);
			s.erase(0, s.size());
		}
		s = "";
		for(int i = stored.size() - 1; i >= 0; i--)
		{
			s += stored[i];
			if(i > 0)
				s += " "; 

		}
		
	}
};


void test()
{
	Solution s; 
	string str = "1 ";
	s.reverseWords(str);
	cout << str << endl;

}

int main()
{
	test();	
	system("pause");
	return 1;
}

