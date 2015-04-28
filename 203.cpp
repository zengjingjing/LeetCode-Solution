



/************************************************************
Note:
pathetic...
I forget the situation: delete the head node, and the next node is also == val,
we need to iter delete it ...
************************************************************/






#include <iostream>
#include <vector>
#include <string>
using namespace std;


 typedef struct ListNode
 {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  }ListNode;
 
class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val) 
	{
		if(!head)return NULL;
		while(head && head->val == val)
		{
			ListNode* temp3 = head;
			head = head->next;
			delete temp3;
			
		}
		ListNode * temp = head;
		ListNode * prev = temp;
		while(temp)
		{			
			if(temp->val == val)
			{
				prev->next = temp->next;
				ListNode * temp2 = temp;
				temp = temp->next;
				delete temp2;
				continue;
			}
			prev = temp;
			temp = temp->next;

		}
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

