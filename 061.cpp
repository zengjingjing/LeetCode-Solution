#include <iostream>
using namespace std;


typedef  struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}ListNode;
 
class Solution 
{
public:
    ListNode *rotateRight(ListNode *head, int k) 
	{
        ListNode * p1,*p2;
		p1 = p2 = head;
		if(head == NULL)return NULL;
		int count = 1;
		while(p2 != NULL)
		{
			p2 = p2->next;
			count++;
			if(count == k)break;
		}
		if(p2 == NULL)return head;
		ListNode * p3 = p1;
		while(p2 ->next != NULL)
		{
			p3 = p1;
			p2 = p2->next;
			p1 = p1->next;
		}
		p3->next =NULL;
		p2->next = head;
		head = p1;
		return head;
    }
};



int main()
{

}

