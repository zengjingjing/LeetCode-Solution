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
		cout << head->val << endl;
		head = head->next;
	}
	return ;
}

class Solution
{
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) 
	{
		ListNode* newHead = new ListNode(1);
		ListNode* tail = newHead;
		ListNode * temp = head;
		for(int i = 0; i < m - 1 && temp; i++)
		{
			tail->next = temp;
			tail = temp;
			temp = temp->next;
		}
		ListNode * start = tail;
		ListNode * cur = temp;
		tail = temp;
		for(int i = m; i <= n && cur; i++)
		{
			ListNode *temp = cur->next;
			cur->next = start->next;
			start->next = cur;
			cur =temp;
		}
		tail->next = cur;
		head = newHead->next;
		delete newHead;
		return head;
	}
};

void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	ListNode * head = BuildList(nums);

	head = s.reverseBetween(head, 1, 3);
	Output(head);
}
int main()
{
	test();
	system("pause");
	return 1;
}
