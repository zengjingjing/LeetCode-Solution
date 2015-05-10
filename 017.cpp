#include <iostream>
#include <string>
#include <vector>
using namespace std;



vector<string> empty;
class Solution {
  
public:
    vector<string> letterCombinations(string digits)
    {
         int i,j;
          vector<string> result;
         if(digits.size() < 1)
         {
             return empty;
         }
         char  ch = digits[0];
         int d = ch - '0';
         string str;
         if(d == 2)
            str = "abc";
        else if(d == 3)
            str = "def";
        else if(d == 4)
            str = "ghi";
        else if(d == 5)
            str = "jkl";
        else if(d == 6)
            str = "mno";
        else if(d == 7)
            str = "pqr";
        else if(d == 8)
            str = "tuv";
        else if(d == 9)
            str = "wxyz";
         int size = str.size();
         string sub = digits.substr(1,digits.size() - 1);
         vector<string> sub_result = letterCombinations(sub);
          int sub_size = sub_result.size();
         for(i = 0; i < size; i++)
         {
            //string temp = str[i];
            if(sub_size == 0)
             {
				string one_char(1, str[i]);
				 result.push_back(one_char);
			}
            else
            {
                 for(j = 0; j < sub_size; j++)
                {
                    string temp(1, str[i]);
                     temp += sub_result[j];
                    result.push_back(temp); 
                              
             } 
            }    
          
            
         }
         return result;
    }
};

int main()
{
	Solution s;
	s.letterCombinations("23");
	vector<string> str = s.letterCombinations("23");
	int i;
	int size = str.size();
	for(i  = 0; i <size; i++)
		cout<<str[i]<<endl;
	system("pause");
	return 1;
}
