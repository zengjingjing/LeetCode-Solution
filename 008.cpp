#include <iostream>
#include <string>
using namespace std;
bool IsVaild(char ch)
{
	if(ch == '-' || ch == '+' || (ch >= '0' && ch <= '9') || ch == ' ')
		return true;
	return false;
}

bool IsInteger(char ch)
	{
		if(ch >= '0' && ch <= '9')
			return true;
		return false;
	}
class Solution 
{
public:
	
	int atoi(string str)
	{
		int i;
		int size = str.size();
		if(size == 0)return 0;
		string filter ="";
		if(!IsVaild(str[0]))return 0;
		filter = str;
		size = filter.size();
		if(size == 0)return 0;
		i = 0;
		while(filter[i] == ' ')i++;
		filter = filter.substr(i, size - i);
		bool negtive =false;
		if(filter[0] == '-')
		{
			filter = filter.substr(1, filter.size() - 1);
			negtive = true;
		}
		else if(filter[0] ==  '+') filter = filter.substr(1, filter.size() - 1);

		size = filter.size();
		if(size == 0)return 0;
		i = 0 ;
		while(filter[i] == '0')i++;
		filter = filter.substr(i, filter.size() - i);
		long long  result = 0;
		size = filter.size();
		if(size == 0)return 0;
		int maxLen = 1;
		for(i = 0; i < size; i++)
		{
			if(!IsInteger(filter[i]))
			{
				maxLen = i;
				break;
			}
		}
		if(i == size)maxLen = size;
		if(size > 15)
		{
			if(negtive)
				return -pow((double)2, (double)31);
			else
				return pow((double)2, (double)31) - 1;
		}
		for(i = 0; i < maxLen; i++)
		{
			long long multi = pow(10,  maxLen - i - 1);
			result += (filter[i] - '0') * multi; 
		}
		
		if(negtive)result = -result;
		if(result > pow((double)2, (double)31) - 1)
			return pow((double)2, (double)31) - 1;
		else if(result < -pow((double)2, (double)31))
			return -pow((double)2, (double)31);

		return result;	

	}
};


int main()
{
	//string str = "-0012a42";
	//cout << atoi(str);
	Solution s;
	cout << s.atoi("9223372036854775809");
	
	system("pause");

}