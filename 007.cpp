#include <string>
#include <iostream>
using namespace std;
 int reverse(int x)
    {
        
        
		bool flag = false;
        if(x < 0)
            flag = true;
        string s1 = std::to_string(x);
        string s2(s1.rbegin(), s1.rend());
        long long  result = atof(s2.c_str());
        if(flag) result = -result;
        if(result > pow((double)2, (double)31) - 1 || result < -(pow(double(2), (double)31)))return 0;
        return result;
    }
int main()
{
//	int x =123;
//	string s1 = std::to_string(x);
   //     string s2(s1.rbegin(), s1.rend());
  //     int result = atoi(s2.c_str(), 10);
   //     return result;
	cout << reverse(1534236469);
	system("pause");
}

