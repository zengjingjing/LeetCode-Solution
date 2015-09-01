/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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
    ListNode* sortList(ListNode* head)
	{
		int count = 0;
		ListNode* temp = head;
		while(temp)
		{
			count++;
			temp = temp->next;
		}
		if(count == 0)
			return NULL;
		return SortLinkList(head, count);
    }

	ListNode* SortLinkList(ListNode* head, int count)
	{
		if(count == 1)
			return head;
		ListNode* head2 = head;
		for(int i = 0; i < count/2; i++)
			head2 = head2->next;
		ListNode* newHead1 = SortLinkList(head, count/2);
		ListNode* newHead2 = SortLinkList(head2, count - count/2);
		ListNode* newHead = MergeLists(newHead1, newHead2, count/2, count - count/2);
		return newHead;
	}

	ListNode* MergeLists(ListNode* head1, ListNode* head2, int count1, int count2)
	{
		ListNode* newHead = NULL;
		ListNode* tail = NULL;
		int i, j;
		i = j = 0;
		ListNode* p1 = head1;
		ListNode* p2 = head2;
		while(i < count1 && j < count2)
		{
			if(p1->val <= p2->val)
			{
				if(newHead == NULL)
					newHead = tail = p1;
				else
				{
					tail->next = p1;
					tail = tail->next;
					
				}
				p1 = p1->next;
				i++;
			}
			else
			{
				if(newHead == NULL)
					newHead = tail = p2;
				else
				{
					tail->next = p2;
					tail = tail->next;	
				}
				p2 = p2->next;
				j++;
			}
		}
		while(i < count1)
		{
			tail->next = p1;
			tail = tail->next;
			p1 = p1->next;
			i++;
		}
		while(j < count2)
		{
			tail->next = p2;
			tail = tail->next;
			p2 = p2->next;
			j++;
		}
		tail->next = NULL;

		return newHead;
	}

	ListNode * BuildList(vector<int>& nums)
	{
		ListNode * head = NULL;
		int size = nums.size();
		if(size == 0)return head;
		ListNode* tail = NULL;
		for(int i = 0; i < size; i++)
		{
			if(head == NULL)
			{
				head = new ListNode(nums[i]);
				tail = head;
			}
			else
			{
				ListNode * node = new ListNode(nums[i]);
				tail->next = node;
				tail = node;
			}
		}
		tail->next = NULL;	
		return head;
	}

	void Output(ListNode* head)
	{
		while(head)
		{
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
		return ;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	srand((unsigned int)time(NULL));
	for(int i = 0; i < 1; i++)
	{
		int val = rand() % 50;
		nums.push_back(val);
	}
	ListNode* head = s.BuildList(nums);
	ListNode* newHead = s.sortList(head);
	s.Output(newHead);
}

int main()
{
	test();
	system("pause");
	return 1;
}

