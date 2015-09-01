/****************************************************************************************************
Solution:
Doesn't need to use queue.
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;



typedef struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
}TreeLinkNode;

class Solution {
public:
	void connect(TreeLinkNode *root)
	{
		MakeConnection(root);
	}

	void MakeConnection(TreeLinkNode* root)
	{
		if(!root)
			return ;
		TreeLinkNode* p = root->next;
		TreeLinkNode* nextNode = NULL;
		while(p)
		{
			if(p->left)
			{
				nextNode = p->left;
				break;
			}
			else if(p->right)
			{
				nextNode = p->right;
				break;
			}
			else
			{
				p = p->next;
			}
		}
		if(root->right)
		{
			root->right->next = nextNode;
			if(root->left)
				root->left->next = root->right;
		}
		else if(root->left)
			root->left->next = nextNode;
		
		MakeConnection(root->right);
		MakeConnection(root->left);
	
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
