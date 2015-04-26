#include <iostream>
#include <string>
#include <vector>



using namespace std;

/**********************
Note: There exist ambiguity.
for example :
"1 10 11 12 15".  the root is "11" just as such algorithm, but the root can also be 10.  
***********************/


typedef struct ListNode 
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}ListNode;


typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }TreeNode;

void InorderTraverse(TreeNode * root)
{
	if(root)
	{
		InorderTraverse(root->left);
		cout << root->val << " ";
		InorderTraverse(root->right);		
	}
}


void MakeBST(ListNode* head, int left, int right, TreeNode*& root)
{
	if(left > right) return ;
	int middle = (left + right) / 2;
	ListNode * leftNode, * rightNode;
	leftNode = head;

	for(int i = left; i < middle; i++)
	{
		head = head->next;
	}

	root = new TreeNode(head->val);
	rightNode = head->next;	
	MakeBST(leftNode, left, middle - 1, root->left);
	MakeBST(rightNode, middle + 1, right, root->right);

}


class Solution 
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        int count = 0;
		ListNode * temp = head;
		while(temp) 
		{
			count++;
			temp = temp->next;
		}
		if(count == 0)return NULL;
		TreeNode * root;
		MakeBST(head, 0, count - 1, root);
		return root;
    }
};




void test()
{
	Solution s;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(4);
	num.push_back(5);
	TreeNode * root = s.sortedListToBST(num);
	InorderTraverse(root);

}
int main()
{
	test();
	system("pause");
	return 1;
}
