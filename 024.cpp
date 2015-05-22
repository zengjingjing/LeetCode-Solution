/****************************************************************************************************
Solution:
Perfect , using tail pointer, i can simplify most prolems in linklist. 
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


class Solution
{
public:
	ListNode* swapPairs(ListNode* head) 
	{
		ListNode * newHead = NULL, *tail = NULL;
		ListNode * cur = head;
		ListNode * next = NULL;
		ListNode * emptyNode = new ListNode(0);
		newHead = tail = emptyNode;
		while(cur)
		{
			next = cur->next;
			if(next)
			{	
				ListNode * temp = next->next;
				tail->next = next;
				tail = tail->next;
				tail->next = cur;
				tail = cur;
				cur = temp;
			}
			else
			{
				tail->next = cur;
				tail = cur;
				cur = cur->next;
			}

		}
		tail->next = NULL;
		return newHead->next;

	}
};

void Output(ListNode* head)
{
	while(head)
	{
		cout << head->val << endl;
		head = head->next;
	}
	return ;
}


void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(2);
//	nums.push_back(1);
//	nums.push_back(3);
//	nums.push_back(4);
//	nums.push_back(5);
	ListNode* head = BuildList(nums);
	head = s.swapPairs(head);
	Output(head);
}
int main()
{
	test();
	system("pause");
	return 1;
}