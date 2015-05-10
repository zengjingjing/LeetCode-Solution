/******************************************
Note:
这种映射我觉得不是1对1映射，应该是1对多映射。因为26可以对应A0和Z。而Z只能对应26。
我最开始一直找不到区分歧义的方法，看了别人的代码之后才知道要先-1，才行。
***************************************************/


class Solution {
public:
    string convertToTitle(int n)
    {
        string ans = "";
        if(n == 0)return ans;
        stack<int> myStack;
        while(n > 0)
        {
          n--;
          myStack.push(n % 26);
          n /= 26;
        }
        while(!myStack.empty())
        {
            ans += myStack.top() + 'A' ;   
            myStack.pop();
        }
        return ans;
    }
};