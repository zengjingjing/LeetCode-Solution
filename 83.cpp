/***************************
Note: 1,2思路都一样，统计重复的元素个数，然后分情况删除。
其实1还有一种思路，就是没当遇到重复的元素时，就删除，这样的思路简单粗暴。
**************************/



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


class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head)
	{
        if(head == NULL)return head;
		if(head->next == NULL)return head;
		ListNode *tail = head;
		ListNode  * left, *right;

		left = head;
	//	right = left->next;
		while(left)
		{
			right = left->next;
			int count = 0;
			while(right && right->val == left->val)
			{
				count++;
				right = right->next;
			}
			if(count != 0)
			{
				if(left == head)
				{
					head = left;
					tail = left;
					left = right;
				}
				else
				{
					tail->next = left;
					tail = left;
					left = right;
				}
			}
			else
			{
				if(left != head)
				{
					tail->next = left;
					tail = left;
					left = right;
				}
				else
				{
					left = right;
				}
			}			
		}
		if(tail)
			tail->next = NULL;
		return head;
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
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
//	nums.push_back(2);
//	nums.push_back(2);
//	nums.push_back(3);
	ListNode* head = BuildList(nums);
	cout << "before delete:" << endl;
	Output(head);
	Solution s;
	head = s.deleteDuplicates(head);
	cout << "after delete:" << endl;
	Output(head);
	
}

int main()
{
	test();	
	system("pause");
	return 1;
}
