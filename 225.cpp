/****************************************************************************************************
跟用两个栈实现队列一样， 可以利用两个队列实现栈。（有两种实现方式）

一个备用队列，一个当前队列。
Solution 1:making push operation costly
当前队列中存储着满足着stack性质的元素，如果这个时候再push，那么将元素push到备用queue中，然后将当前queue中所有元素都dequeue到备用队列中。
这样备用queue就存储着满足stack性质的所有元素了，交换当前queue和备用queue的指针即可。

Solution 1:making pop operation costly
每次pop的时候都当前 dequeue  -> 备用enqueue,弹出最后一个元素即可。这样每次pop都是O(n),不像用双栈实现队列时那样，只需要某一次的弹栈O(n)，
就可以满足后续好几次queue pop操作。  
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Stack
{
public:
	// Push element x onto stack.
	void push(int x) 
	{
		alternative->push(x);
		while(!current->empty())
		{
			int temp = current->front();
			alternative->push(temp);
			current->pop();
		}
		queue<int>* temp = alternative;
		alternative = current;
		current = temp;
	}

	// Removes the element on top of the stack.
	void pop()
	{
		if(!empty())
		{
			current->pop();
		}
	}

	// Get the top element.
	int top()
	{
		if(!empty())
		{
			return current->front();
		}
		else
			return 0;
	}

	// Return whether the stack is empty.
	bool empty()
	{
		return current->empty();
	}

	Stack()
	{
		queue1 = new queue<int>;
		queue2 = new queue<int>;
		current = queue1;
		alternative = queue2;
	}
private:
	queue<int>* queue1;
	queue<int>* queue2;
	queue<int>* current;
	queue<int>* alternative;

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

