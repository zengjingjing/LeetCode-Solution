/******************************************
Note:
����ӳ���Ҿ��ò���1��1ӳ�䣬Ӧ����1�Զ�ӳ�䡣��Ϊ26���Զ�ӦA0��Z����Zֻ�ܶ�Ӧ26��
���ʼһֱ�Ҳ�����������ķ��������˱��˵Ĵ���֮���֪��Ҫ��-1�����С�
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