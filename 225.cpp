/****************************************************************************************************
��������ջʵ�ֶ���һ���� ����������������ʵ��ջ����������ʵ�ַ�ʽ��

һ�����ö��У�һ����ǰ���С�
Solution 1:making push operation costly
��ǰ�����д洢��������stack���ʵ�Ԫ�أ�������ʱ����push����ô��Ԫ��push������queue�У�Ȼ�󽫵�ǰqueue������Ԫ�ض�dequeue�����ö����С�
��������queue�ʹ洢������stack���ʵ�����Ԫ���ˣ�������ǰqueue�ͱ���queue��ָ�뼴�ɡ�

Solution 1:making pop operation costly
ÿ��pop��ʱ�򶼵�ǰ dequeue  -> ����enqueue,�������һ��Ԫ�ؼ��ɡ�����ÿ��pop����O(n),������˫ջʵ�ֶ���ʱ������ֻ��Ҫĳһ�εĵ�ջO(n)��
�Ϳ�����������ü���queue pop������  
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

