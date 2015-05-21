/****************************************************************************************************
Solution:
First i want to use a new linklist(head, tail) to represent the element < x. And plus the left elements.
But during coding, i found that i need to consider many situations, which makes my brain explosion!

Fortunately, i found that we can use a tail point(or sometime + a head) to make things easy. After using tail point( a tail and a head represent current linklist),
we dont need to consider many situations!!!hha

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

 void PrintList(ListNode* head)
 {
	 while(head)
	{
		cout << head->val << " ";
		head = head->next;
	 }
	 cout << endl;
 }

class Solution
{
public:
    ListNode* partition(ListNode* head, int x)
	{
		ListNode* tail1 = NULL;
		ListNode * tail2 = NULL;

		ListNode * temp = head;
		ListNode* head1 = NULL;
		ListNode * head2 = NULL;
		while(temp)
		{
			if(temp->val < x)
			{
				if(head1 == NULL)
					head1 = temp;
				if(tail1 == NULL)
					tail1 = temp;
				else
				{
					tail1->next = temp;
					tail1 = temp;
				}
			}
			else
			{
				if(head2 == NULL)
					head2 = temp;
				if(tail2 == NULL)
					tail2 = temp;
				else
				{
					tail2->next = temp;
					tail2 = temp;
				}
			}
			temp = temp->next;
		}
		if(tail2)
			tail2->next = NULL;
		if(tail1)
			tail1->next = head2;
		if(head1)
			return head1;
		else
			return head2;
    }
};



void test()
{

	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(2);
	ListNode * head = BuildList(nums);
	head = s.partition(head, 3);
	PrintList(head);


}

int main()
{
	test();
	system("pause");
	return 1;
}

