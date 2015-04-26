#include <iostream>
#include <string>
#include <vector>

using namespace std;

/***********************************
Note:
At first i use the return judge " if(!root)..." of the recursion, but i failed in many case;
using return judge "if(isleaf(root))..." is more robust
***********************************/
 struct TreeNode {
      int val;
    TreeNode *left;
      TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 bool IsLeaf(TreeNode* node)
 {
	 return (node->left == NULL && node->right == NULL);
 }

bool HasSum(TreeNode * root, int sum)
{
	int val = root->val;
	if(IsLeaf(root))    // when it is the leaf , judge the sub == 0
	{
		return val == sum;
	}

			bool b1 = false;
			bool b2 = false;
			if(root->left)
			   b1 = HasSum(root->left, sum - val);
			if(root->right) 
			b2 = HasSum(root->right, sum - val);
			return b1 || b2;

}


class Solution 
{
public:
    bool hasPathSum(TreeNode *root, int sum)
	{
		if(!root)return false;
		return HasSum(root, sum);
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
