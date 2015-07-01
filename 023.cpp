#include <iostream>
#include <vector>

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
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		int size = lists.size();
		if(size == 0)
			return NULL;
		if(size == 1)
			return lists[0];
		int left = 0;
		int right = size - 1;
		return MergeAll(lists, left, right);
	}

	ListNode* MergeTwoLists(ListNode* list1, ListNode* list2)
	{

		ListNode* tail = new ListNode(0);
		ListNode* head = tail;
		while(list1 && list2)
		{
			if(list1->val > list2->val)
			{
				tail->next = list2;
				list2 = list2->next;
			}
			else
			{
				tail->next = list1;
				list1 = list1->next;
				
			}
			tail = tail->next;
		}
		
		if(list1)
			tail->next = list1;
		else
			tail->next = list2;
		tail = head;
		head = head->next;
		delete tail;
		return head;
	}

	ListNode* MergeAll(vector<ListNode*>& lists, int left, int right)
	{
		if(left == right)
			return lists[left];
		int middle = (left + right) / 2;
		ListNode* head1 = MergeAll(lists, left, middle);
		ListNode* head2 = MergeAll(lists, middle + 1, right);
		return MergeTwoLists(head1, head2);

	}
};


void test()
{

}
int main()
{
	test();
	return 1;
}




