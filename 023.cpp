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


};


void test()
{
	Solution s;
	vector<int> nums1;
	vector<int> nums2;
	vector<int> nums3;
	vector<int> nums4;
	vector<int> nums5;


	nums1.push_back(1);
	nums1.push_back(3);
	nums1.push_back(10);

	nums2.push_back(2);
	nums2.push_back(3);
	nums2.push_back(5);
	nums2.push_back(6);

	nums3.push_back(1);
	nums3.push_back(2);
	nums3.push_back(7);

	nums4.push_back(3);
	nums4.push_back(4);
	nums4.push_back(5);

	nums5.push_back(7);
	nums5.push_back(8);
	nums5.push_back(9);


	vector<ListNode*> lists;

	ListNode* list1 = s.BuildList(nums1);
	ListNode* list2 = s.BuildList(nums2);
	ListNode* list3 = s.BuildList(nums3);
	ListNode* list4 = s.BuildList(nums4);
	ListNode* list5 = s.BuildList(nums5);
	lists.push_back(list1);
	lists.push_back(list2);
	lists.push_back(list3);
	lists.push_back(list4);
	lists.push_back(list5);

	ListNode* head = s.mergeKLists(lists);
	s.Output(head);

}

int main()
{
	test();
	system("pause");
	return 1;
}




