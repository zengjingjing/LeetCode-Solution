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
		MakeConnection(root->left);
		MakeConnection(root->right);
		TreeLinkNode* tree1 = root->left;
		TreeLinkNode* tree2 = root->right;
		while(tree1 && tree2)
		{
			tree1->next = tree2;
			tree1 = tree1->right;
			tree2 = tree2->left;
		}
		return ;
			
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
