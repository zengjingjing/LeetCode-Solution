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

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
        int numA = 0;
		int numB = 0;
		ListNode * temp = headA;
		while(temp)
		{
			temp = temp->next;
			numA++;
		}
		temp = headB;
		while(temp)
		{
			temp = temp->next;
			numB++;
		}
		if(numA == 0 || numB == 0)return NULL;
		if(numA > numB)
		{
			int count = numA - numB;
			while(headA && count--)
			{
				headA = headA->next;
			}

		}
		else if(numA < numB)
		{
			int count = numB - numA;
			while(headB && count--)
			{
				headB = headB->next;
			}
		}
		while(headA && headB)
		{
			if(headA == headB)return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
    }
};


void test()
{

}

int main()
{
	test();	
	system("pause");
	return 1;
}

