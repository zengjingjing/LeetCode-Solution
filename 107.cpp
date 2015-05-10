#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
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
    vector<vector<int> > levelOrderBottom(TreeNode *root)
	{
		
		vector<vector<int>> result;
		 if(!root) return result;
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
			 result.push_back(sub_result);
		 }
		 
		 vector<vector<int>> final_result;
		 for(int i = result.size() - 1; i >= 0 ; i--)
		 {
			 final_result.push_back(result[i]);
		 }
		 return final_result;
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


