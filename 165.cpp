#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        bool flag1 = false,flag2 = false;
        while(!version1.empty() && !version2.empty() )
      {
          int index1 = version1.find('.');
          int index2 = version2.find('.');
          flag1 = flag2 = false;
          string str1= "";
          string str2 = "";
          if(index1 == string::npos)
          {
              str1 = version1;
              flag1 =true;
          }
          else
            {
                str1 = version1.substr(0, index1);
            }
         if(index2 == string::npos)
            {
                str2 = version2;
                flag2 = true;
            }
          else
          {
              str2 = version2.substr(0, index2);
          }
         int num1 = atoi(str1.c_str());
         int num2 = atoi(str2.c_str());
         if(num1 > num2)return 1;
         else if(num1 < num2)return -1;
         else 
         {
             if(flag1)
                version1.erase(0, version1.size());
            else
                version1.erase(0, index1 + 1);
             if(flag2)
                version2.erase(0, version2.size());
            else
                version2.erase(0, index2 + 1);
            if(!flag1 && !flag2)continue;
            else break;
         }
		}
        if(version1.empty() && version2.empty())return 0;
        while(!version1.empty())
         {
             string str= "";
             int index = version1.find('.');
             if(index == string::npos)
             str = version1;
             else
             str = version1.substr(0, index);
             int num = atoi(str.c_str());
             if(num != 0)return 1;
			 else
			 {
				 if(index == string::npos)
					 version1.erase(0, version1.size());
				 else
					 version1.erase(0, index + 1);
			 }
             
         }
         if(!flag1)return 0;
         
         while(!version2.empty())
         {
             string str= "";
             int index = version2.find('.');
             if(index == string::npos)
             str = version2;
             else
             str = version2.substr(0, index);
             int num = atoi(str.c_str());
             if(num != 0)return -1;
			  else
			 {
				 if(index == string::npos)
					 version2.erase(0, version2.size());
				 else
					 version2.erase(0, index + 1);
			 }
             
         }
         if(!flag2)return 0;
         
	}            

};


void test()
{
	Solution s;
	cout << s.compareVersion("01.0", "02.0.01") << endl;
}
int main()
{
test();
	system("pause");
	return 1;
}

