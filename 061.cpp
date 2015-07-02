/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution 
{
public:
	ListNode *rotateRight(ListNode *head, int k) 
	{
		int count= 0;
		ListNode* temp = head;
		ListNode * tail = NULL;
		if(!head)
			return NULL;
		while(temp)
		{
			count++;
			tail = temp;
			temp = temp->next;
		}

		k %= count;
		if( k == 0)return head;
		temp = head;
		ListNode * prev = NULL;
		for(int i = 0; i < count - k; i++)
		{
			prev = temp;
			temp = temp->next;
		}
		tail->next = head;
		prev->next = NULL;
		head = temp;
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
