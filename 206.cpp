/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head)
	{
		ListNode * newHead = new ListNode(1) ;
		ListNode * temp = head;
		while(temp)
		{
			ListNode * next =temp->next;
			temp->next = newHead->next;
			newHead->next = temp;
			temp = next;	
		}
		head = newHead->next;
		delete newHead;
		return head;
		
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

