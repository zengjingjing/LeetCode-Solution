/****************************************************************************************************
Solution:
������133��Clone Graphһ���Ľ���˼·����һ��map�洢�¾�����ͼ����ӳ���ϵ�����������ָ��ĸ�ֵ�ϣ��Ϳ����ҵ���Ӧ�ˡ�
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
