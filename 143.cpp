/****************************************************************************************************
Solution:
使用额外数组将链表指针保存，然后正向、逆向操作，就可以进行插入工作了。
可以看一下题解，我感觉有可能有不需要额外空间的方法。
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

 
class Solution {
public:
    void reorderList(ListNode* head)
	{
        if(!head)
			return ;
		int count = 0;
		ListNode * temp = head;
		vector<ListNode*> myList;
		while(temp)
		{
			count++;
			myList.push_back(temp);
			temp = temp->next;
		}
		if(count < 3)return ;
		ListNode * tail = head;
		count--;
		ListNode * last = myList[count];
		while(tail != last && tail->next != last)
		{
			last->next = tail->next;
			tail->next = last;
			tail = last->next;
			count--;
			last = myList[count];
		}
		if(tail == last)
			tail->next = NULL;
		else if(tail->next == last)
			last->next = NULL;

    }
};




void test()
{
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
//	nums.push_back(4);
//	nums.push_back(5);
	ListNode * head = BuildList(nums);
//	Output(head);
	s.reorderList(head);
	Output(head);
}
int main()
{
	test();
	system("pause");
	return 1;
}
