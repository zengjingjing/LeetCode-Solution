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

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		ListNode * emptyNode = new ListNode(0);
		ListNode * newHead = emptyNode, *tail = emptyNode;

		ListNode ** pList = new ListNode *[k];
		ListNode * temp = head;
		ListNode * cur = head;
		int count = 0;
		while(temp)
		{
			count++;
			temp = temp->next;
		}
		temp = head;
		for(int i = 0; i < count / k; i++)
		{
			for(int j = 0; j < k; j++)
			{
				pList[j] = cur;
				cur = cur->next;
			}
			
			for(int j = k - 1; j >= 0; j--)
			{
				tail->next = pList[j];
				tail = tail->next;
			}
		}
		tail->next = cur;
		delete []pList;
		return newHead->next;
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
	head = s.reverseKGroup(head, 1);
	Output(head);
}
int main()
{
	test();
	system("pause");
	return 1;
}