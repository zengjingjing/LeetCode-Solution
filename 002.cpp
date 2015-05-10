#include <iostream>
using namespace std;

struct ListNode
 {
     int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution 
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		int jinwei = 0;
		ListNode * head1 = l1;
		ListNode * head2 = l2;
		ListNode * prev1;
		ListNode * prev2;
		while(l1 !=NULL && l2 !=NULL)
		{
			l1->val += l2->val;
			l1->val += jinwei;
			jinwei = l1->val/10;
			l1->val %= 10;
			l2->val = l1->val;
			prev1 = l1;
			prev2 = l2;
			l1 = l1->next;
			l2 = l2->next;
		}
		if(l1 == NULL && l2 ==NULL)
		{
			if(jinwei  ==1)
			{
				prev1->next = new ListNode(1);

			}
			return head1;
		}
		if(l1 !=NULL && l2 ==NULL)
		{
			while(l1!=NULL)
			{
				l1->val += jinwei;
				jinwei = l1->val/10;
				l1->val %= 10;
				prev1 = l1;
				l1 = l1->next;

			}
			if(jinwei  ==1)
				{
					prev1->next = new ListNode(1);

			}
			
			return head1;
		}
		if(l1 == NULL && l2!=NULL)
		{
			while(l2!=NULL)
			{
				l2->val += jinwei;
				jinwei = l2->val/10;
				l2->val %= 10;
				prev2 = l2;
				l2 = l2->next;
				
			}
			if(jinwei  ==1)
			{
				prev2->next = new ListNode(1);

			}
			return head2;
		}
    }
};


int main()
{
	Solution so;

}