/****************************************************************************************************
Solution:
这道题和133：Clone Graph一样的解题思路，用一个map存储新旧链表（图）的映射关系，这样在随机指针的赋值上，就可以找到对应了。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


typedef struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
}RandomListNode;

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		RandomListNode * newHead = NULL;
		if(!head)
			return newHead;
		map<RandomListNode* , RandomListNode*> myMap;

		newHead =new RandomListNode(head->label);
		myMap[head] = newHead;
		RandomListNode * temp = head->next;
		RandomListNode * tail = newHead;
		while(temp)
		{
			tail->next = new RandomListNode(temp->label);
			myMap[temp] = tail->next;
			temp = temp->next;
			tail = tail->next;
		}
		temp = head;
		tail = newHead;
		while(temp)
		{
			if(temp->random)
				tail->random = myMap[temp->random];
			else
				tail->random = NULL;
			temp = temp->next;
			tail = tail->next;
		}
		return newHead;
	}
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
