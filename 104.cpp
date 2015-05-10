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
 
class Solution
{
public:
   int maxDepth(TreeNode *root)
	{
		// vector<vector<int>> result;
		 if(!root) return 0;
		 queue<TreeNode*> myQueue;
		 myQueue.push(root);
		 int count = 1;

		 int depth = 0;
		 while(!myQueue.empty())
		 {

			 int nextCount = 0;
			 for(int i = 0; i < count; i++)
			 {
				 TreeNode* top = myQueue.front();

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
			 depth++;
		 }
		 return depth;
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


