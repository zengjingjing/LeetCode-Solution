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
};
 
class Solution {
public:
    void connect(TreeLinkNode *root)
	{
		if(!root)return;
		int count = 1;
		root->next = NULL;
		while(root->left)
		{
			TreeLinkNode* start = root;
			for(int i = 0; i < count && start != NULL; i++)
			{
				start->left->next = start->right;
				if(start->next)
				{
					start->right->next = start->next->left;
				}
				else
					start->right->next = NULL;
				start = start->next;
			}
			count *= 2;
			root = root->left;
		}	
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
