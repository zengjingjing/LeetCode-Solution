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
    ListNode * insertionSortList(ListNode* head)
	{
		ListNode * temp1;
		ListNode * temp2;
		temp2 = temp1 = head;
		if(!temp1)return NULL;
		if(!temp1->next)return head;
		temp2 = temp1->next;
		temp1->next = NULL;
		while(temp2)
		{
			temp1 = head;
			ListNode * prev = head;
			while(temp1)
			{
				if(temp1->val <= temp2->val)
				{
					prev = temp1;
					temp1 = temp1->next;
				}
				else
					break;
			}
			ListNode * temp3 = temp2;
			temp2 = temp2->next;
		    if(temp1 == head)
			{
				temp3->next = head;
				head = temp3;
			}
			else
			{
				prev->next = temp3;
				temp3->next = temp1;
			}
		
		}
		return head;
    }
};

void test()
{
	vector<int> nums;
//	nums.push_back(3);
//	nums.push_back(2);
//	nums.push_back(5);
//	nums.push_back(1);
//	nums.push_back(4);
	cout << " before sort:" << endl;
	ListNode * head = BuildList(nums);
	Output(head);
	Solution s;
		cout << " after sort:" << endl;
	head = s.insertionSortList(head);
	Output(head);

}


int main()
{
	test();	
	system("pause");
	return 1;
}

