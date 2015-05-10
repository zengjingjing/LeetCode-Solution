#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct TreeNode 
{
     int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL)
	  {}
}TreeNode;

int TreeDepth(TreeNode* root, int& depth)
{
	if(root == NULL)return true;
	int depth1 = depth + 1;
	int depth2 = depth + 1;
	bool b1 = JudgeBalance(root->left, depth1);
	bool b1 = JudgeBalance(root->right ,depth2);

}

class Solution {
public:
    bool isBalanced(TreeNode *root)
	{
        
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
