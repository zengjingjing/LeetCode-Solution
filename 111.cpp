#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;



typedef  struct TreeNode
{
    int val;
    TreeNode *left;
   TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

bool IsLeaf(TreeNode * node)
{
	if(node->left == NULL && node->right == NULL)
		return true;
	return false;
}
 
class Solution
{
public:
    int minDepth(TreeNode *root)
	{
		 int minDepth = 0;
		 if(!root) return minDepth;
		 queue<TreeNode*> myQueue;
		 myQueue.push(root);
		 int count = 1;
		 while(!myQueue.empty())
		 {
			 vector<int> sub_result;
			 int nextCount = 0;
			 for(int i = 0; i < count; i++)
			 {
				 TreeNode* top = myQueue.front();
				 sub_result.push_back(top->val);
				 if(IsLeaf(top))
				 {
					 minDepth++;
					 return minDepth;
				 }
				 if(top->left)
				 {
						 myQueue.push(top->left);
						 nextCount++;
				 }
				 if(top->right)
				{
						 myQueue.push(top->right);
						 nextCount++;
				 }
				 myQueue.pop();
			 }
			 count = nextCount;
			 minDepth++;
		 }
		 return minDepth;
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


