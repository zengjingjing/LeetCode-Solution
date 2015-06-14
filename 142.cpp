#include <iostream>
#include <string>
#include <vector>

using namespace std;



typedef   struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}ListNode
;

class Solution 
{
public:
    bool hasCycle(ListNode *head)
    {
        if(head == NULL ||  head->next == NULL)return false;
		ListNode* slow;
		ListNode * fast;
		slow = fast = head;
		while(slow && fast)
		{
			if(fast->next)
				fast = fast->next->next;
			else
				return false;
			slow = slow->next;
			if(fast == slow)return true;			
		}
		return false;
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

