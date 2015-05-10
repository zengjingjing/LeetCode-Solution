#include <iostream>
#include <stack>
using namespace std;

class MinStack 
{
    private:
    stack<int> normalStack;
	stack<int> minStack;
	int _min;
public:
    void push(int x) 
    {
		int count = normalStack.size();
		normalStack.push(x); 
		if(count == 0)
		{
			minStack.push(x);
			return;
		}
		int min = minStack.top();
		if(x <= min)
		{
			minStack.push(x);

		}

    }

    void pop()
	{
        int t1 = normalStack.top();
		int t2 = minStack.top();
		if(t1 == t2)
			minStack.pop();
		normalStack.pop();
    }

    int top()
	{
		return normalStack.top();    
    }

    int getMin()
	{
		return minStack.top();
    }
};


int main()
{
	MinStack st;
	st.push(2);
	st.push(0);
	st.push(3);
	st.push(0);
	st.pop();
	cout<<st.getMin()<<endl;
	st.pop();
	cout<<st.getMin()<<endl;
	system("pause");
}